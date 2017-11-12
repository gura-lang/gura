//=============================================================================
// Gura class: filter@conv2d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_Conv2d
//-----------------------------------------------------------------------------
Filter_Conv2d::FilterFuncTable Filter_Conv2d::filterFuncTable = {{{nullptr}}};

bool Filter_Conv2d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePadRow = 0, sizePadCol = 0;
	CalcPadding2d(this, pArray->GetDimensions(), &sizePadRow, &sizePadCol);
	return pArray->CalcConv2d(sig, pArrayRtn, GetArrayFilter(), GetStridesRow(), GetStridesCol(),
							  sizePadRow, sizePadCol, GetChannelPos());
}

String Filter_Conv2d::ToString() const
{
	char buff[80];
	String str = "conv2d";
	if (HasFilterDim()) {
		::sprintf(buff, ":filter_num=%zu", GetFilterNum());
		str += buff;
	}
	if (HasChannelDim()) {
		::sprintf(buff, ":channel_num=%zu", GetChannelNum());
		str += buff;
	}
	::sprintf(buff, ":size=(%zu,%zu)", GetSizeRow(), GetSizeCol());
	str += buff;
	::sprintf(buff, ":strides=(%zu,%zu)", GetStridesRow(), GetStridesCol());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_pos=%s", Array::ChannelPosToSymbol(GetChannelPos())->GetName());
	str += buff;
	return str;
}

//-----------------------------------------------------------------------------
// Object_filter_at_conv2d
//-----------------------------------------------------------------------------
Object_filter_at_conv2d::Object_filter_at_conv2d(Environment &env, Filter_Conv2d *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_conv2d), pFilter)
{
}

Object *Object_filter_at_conv2d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@conv2d(array:array, strides[]?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(filter_at_conv2d, "filter@conv2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_conv2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@conv2d` instance.\n"
		"\n"
		"The given `array` instance shoud have one of the following shapes:\n"
		"\n"
		"- `[row_size, col_size]`\n"
		"- `[channel_num, row_size, col_size]`\n"
		"- `[filter_num, channel_num, row_size, col_size]`\n"
		"\n"
		"where `row_size` and `col_size` are the size of the filter's kernel,\n"
		"`channel_num` is the number of channels and `filter_num` is the number of filters.\n"
		"\n"
		"The `strides` is a list of strides for a sliding window in row and column. Default is `[1, 1]`.\n"
		"\n"
		"The `padding` is a padding style and takes `` `valid`` or `` `same``. Default is `` `same``.\n"
		"When `valid` is specified, there is no padding. When `same` is specified, zero values are padded so that\n"
		"the result array has the size of the division of the original size by `strides`.\n"
		"\n"
		"The `channel_pos` is a channel position and takes `` `none``, `` `first`` or `` `last``.\n"
		"If not specified, `` `none` for an array without channel dimension\n"
		"and `` `last`` for others are to be set.\n");
}

Gura_ImplementFunction(filter_at_conv2d)
{
	const Array *pArrayFilter = Object_array::GetObject(arg, 0)->GetArray();
	const Array::Dimensions &dims = pArrayFilter->GetDimensions();
	size_t nDims = dims.size();
	if (nDims != 2 && nDims != 3 && nDims != 4) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `filter@conv2d` constructor must have dimensions of 2, 3 or 4.");
		return Value::Nil;
	}
	size_t stridesRow = 1;
	size_t stridesCol = 1;
	if (arg.IsValid(1)) {
		const ValueList &valList = arg.GetList(1);
		if (valList.size() != 2) {
			env.SetError(ERR_ValueError, "strides must have two elements");
			return Value::Nil;
		}
		stridesRow = valList[0].GetSizeT();
		stridesCol = valList[1].GetSizeT();
	}
	Filter::PaddingType paddingType = Filter::PADDINGTYPE_Same;
	if (arg.IsValid(2)) {
		paddingType = Filter::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Filter::PADDINGTYPE_Invalid) return Value::Nil;
	}
	Array::ChannelPos channelPos = Array::CHANNELPOS_Invalid;
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) {
			return Value::Nil;
		} else if (channelPos == Array::CHANNELPOS_None) {
			if (nDims != 2) channelPos = Array::CHANNELPOS_First;
		} else if (channelPos == Array::CHANNELPOS_Last) {
			if (nDims == 2) {
				env.SetError(ERR_ValueError, "channel dimension is expected to exist at last");
				return Value::Nil;
			}
		}
	} else {
		channelPos = (nDims == 2)? Array::CHANNELPOS_None : Array::CHANNELPOS_Last;
	}
	Object_filter_at_conv2d *pObj = new Object_filter_at_conv2d(
		env, new Filter_Conv2d(pArrayFilter->Reference(), stridesRow, stridesCol, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// filter@conv2d#array
Gura_DeclareProperty_R(filter_at_conv2d, array)
{
	SetPropAttr(VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(filter_at_conv2d, array)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	return Value(new Object_array(env, pFilter->GetArrayFilter()->Reference()));
}

// filter@conv2d#channel_num
Gura_DeclareProperty_R(filter_at_conv2d, channel_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv2d, channel_num)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	return pFilter->HasChannelDim()? Value(pFilter->GetChannelNum()) : Value::Nil;
}

// filter@conv2d#channel_pos
Gura_DeclareProperty_R(filter_at_conv2d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv2d, channel_pos)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	return Value(Array::ChannelPosToSymbol(pFilter->GetChannelPos()));
}

// filter@conv1d#filter_num
Gura_DeclareProperty_R(filter_at_conv2d, filter_num)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv2d, filter_num)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	return pFilter->HasFilterDim()? Value(pFilter->GetFilterNum()) : Value::Nil;
}

// filter@conv2d#padding
Gura_DeclareProperty_R(filter_at_conv2d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv2d, padding)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	return Value(Filter::PaddingTypeToSymbol(pFilter->GetPaddingType()));
}

// filter@conv2d#size
Gura_DeclareProperty_R(filter_at_conv2d, size)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv2d, size)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	return Value::CreateList(env, Value(pFilter->GetSizeCol()), Value(pFilter->GetSizeRow()));
}

// filter@conv2d#strides
Gura_DeclareProperty_R(filter_at_conv2d, strides)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_conv2d, strides)
{
	const Filter_Conv2d *pFilter = Object_filter_at_conv2d::GetObject(valueThis)->GetFilter();
	return Value::CreateList(env, Value(pFilter->GetStridesCol()), Value(pFilter->GetStridesRow()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_conv2d::Class_filter_at_conv2d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_conv2d)
{
}

void Class_filter_at_conv2d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(filter_at_conv2d);
	// Assignment of properties
	Gura_AssignProperty(filter_at_conv2d, array);
	Gura_AssignProperty(filter_at_conv2d, channel_num);
	Gura_AssignProperty(filter_at_conv2d, channel_pos);
	Gura_AssignProperty(filter_at_conv2d, filter_num);
	Gura_AssignProperty(filter_at_conv2d, padding);
	Gura_AssignProperty(filter_at_conv2d, size);
	Gura_AssignProperty(filter_at_conv2d, strides);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_conv2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
