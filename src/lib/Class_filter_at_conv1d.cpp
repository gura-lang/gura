//=============================================================================
// Gura class: filter@conv1d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_Conv1d
//-----------------------------------------------------------------------------
Filter_Conv1d::FilterFuncTable Filter_Conv1d::filterFuncTable = {{{nullptr}}};

bool Filter_Conv1d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePad = 0;
	CalcPadding1d(this, pArray->GetDimensions(), &sizePad);
	return pArray->CalcConv1d(sig, pArrayRtn, GetArrayFilter(), GetStrides(), sizePad, GetChannelPos());
}

String Filter_Conv1d::ToString() const
{
	char buff[80];
	String str = "conv1d";
	if (HasFilterDim()) {
		::sprintf(buff, ":filter_num=%zu", GetFilterNum());
		str += buff;
	}
	if (HasChannelDim()) {
		::sprintf(buff, ":channel_num=%zu", GetChannelNum());
		str += buff;
	}
	::sprintf(buff, ":size=%zu", GetSize());
	str += buff;
	::sprintf(buff, ":strides=%zu", GetStrides());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_pos=%s", Array::ChannelPosToSymbol(GetChannelPos())->GetName());
	str += buff;
	return str;
}

//-----------------------------------------------------------------------------
// Object_filter_at_conv1d
//-----------------------------------------------------------------------------
Object_filter_at_conv1d::Object_filter_at_conv1d(Environment &env, Filter_Conv1d *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_conv1d), pFilter)
{
}

Object *Object_filter_at_conv1d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@conv1d(array:array, strides?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(filter_at_conv1d, "filter@conv1d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_conv1d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@conv1d` instance.\n"
		"\n"
		"The `array` is an `array` instance that has one of the following shapes:\n"
		"\n"
		"- `[size]`\n"
		"- `[channel_num, size]`\n"
		"- `[filter_num, channel_num, size]`\n"
		"\n"
		"where `size` is the size of the filter's kernel,\n"
		"`channel_num` is the number of channels and `filter_num` is the number of filters.\n"
		"\n"
		"The `strides` is a strides for a sliding window. Default is one.\n"
		"\n"
		"The `padding` is a padding style and takes `` `valid`` or `` `same``. Default is `` `same``.\n"
		"When `valid` is specified, there is no padding. When `same` is specified, zero values are padded so that\n"
		"the result array has the size of the division of the original size by `strides`.\n"
		"\n"
		"The `channel_pos` is a channel position and takes `` `first`` or `` `last``. Default is `` `last``. \n");
}

Gura_ImplementFunction(filter_at_conv1d)
{
	const Array *pArrayFilter = Object_array::GetObject(arg, 0)->GetArray();
	const Array::Dimensions &dims = pArrayFilter->GetDimensions();
	size_t nDims = dims.size();
	if (nDims != 1 && nDims != 2 && nDims != 3) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `filter@conv1d` constructor must have 1, 2 or 3 dimensions.");
		return Value::Nil;
	}
	size_t strides = arg.IsValid(1)? arg.GetSizeT(1) : 1;
	Filter::PaddingType paddingType = Filter::PADDINGTYPE_Same;
	if (arg.IsValid(2)) {
		paddingType = Filter::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Filter::PADDINGTYPE_Invalid) return Value::Nil;
	}
	Array::ChannelPos channelPos = Array::CHANNELPOS_First;
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) return Value::Nil;
	}
	if (channelPos == Array::CHANNELPOS_Last && nDims < 2) {
		env.SetError(ERR_ValueError, "channel dimension is expected to exist at last");
		return Value::Nil;
	}
	Object_filter_at_conv1d *pObj = new Object_filter_at_conv1d(
		env, new Filter_Conv1d(pArrayFilter->Reference(), strides, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// filter@conv1d#array
Gura_DeclareProperty_R(filter_at_conv1d, array)
{
	SetPropAttr(VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(filter_at_conv1d, array)
{
	const Filter_Conv1d *pFilter = Object_filter_at_conv1d::GetObject(valueThis)->GetFilter();
	return Value(new Object_array(env, pFilter->GetArrayFilter()->Reference()));
}

// filter@conv1d#channel_num
Gura_DeclareProperty_R(filter_at_conv1d, channel_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv1d, channel_num)
{
	const Filter_Conv1d *pFilter = Object_filter_at_conv1d::GetObject(valueThis)->GetFilter();
	return pFilter->HasChannelDim()? Value(pFilter->GetChannelNum()) : Value::Nil;
}

// filter@conv1d#channel_pos
Gura_DeclareProperty_R(filter_at_conv1d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv1d, channel_pos)
{
	const Filter_Conv1d *pFilter = Object_filter_at_conv1d::GetObject(valueThis)->GetFilter();
	return Value(Array::ChannelPosToSymbol(pFilter->GetChannelPos()));
}

// filter@conv1d#filter_num
Gura_DeclareProperty_R(filter_at_conv1d, filter_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv1d, filter_num)
{
	const Filter_Conv1d *pFilter = Object_filter_at_conv1d::GetObject(valueThis)->GetFilter();
	return pFilter->HasFilterDim()? Value(pFilter->GetFilterNum()) : Value::Nil;
}

// filter@conv1d#padding
Gura_DeclareProperty_R(filter_at_conv1d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv1d, padding)
{
	const Filter_Conv1d *pFilter = Object_filter_at_conv1d::GetObject(valueThis)->GetFilter();
	return Value(Filter::PaddingTypeToSymbol(pFilter->GetPaddingType()));
}

// filter@conv1d#size
Gura_DeclareProperty_R(filter_at_conv1d, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv1d, size)
{
	const Filter_Conv1d *pFilter = Object_filter_at_conv1d::GetObject(valueThis)->GetFilter();
	return Value(pFilter->GetSize());
}

// filter@conv1d#strides
Gura_DeclareProperty_R(filter_at_conv1d, strides)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv1d, strides)
{
	const Filter_Conv1d *pFilter = Object_filter_at_conv1d::GetObject(valueThis)->GetFilter();
	return Value(pFilter->GetStrides());
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_conv1d::Class_filter_at_conv1d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_conv1d)
{
}

void Class_filter_at_conv1d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(filter_at_conv1d);
	// Assignment of properties
	Gura_AssignProperty(filter_at_conv1d, array);
	Gura_AssignProperty(filter_at_conv1d, channel_num);
	Gura_AssignProperty(filter_at_conv1d, channel_pos);
	Gura_AssignProperty(filter_at_conv1d, filter_num);
	Gura_AssignProperty(filter_at_conv1d, padding);
	Gura_AssignProperty(filter_at_conv1d, size);
	Gura_AssignProperty(filter_at_conv1d, strides);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_conv1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
