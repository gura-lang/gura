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
	size_t sizeOut = 0, sizePad = 0;
	bool chLastFlag = (GetChannelAt() == Array::CHANNELAT_Last);
	const Array::Dimensions &dims = pArray->GetDimensions();
	Filter::CalcPadding(dims.GetBack(chLastFlag? 1 : 0).GetSize(),
						GetSize(), GetStrides(), GetPaddingType(),
						&sizeOut, &sizePad);
	pArray->CalcConv1d(pArrayRtn, GetArrayFilter(), GetStrides(), sizePad, GetChannelAt());
	return true;
}

String Filter_Conv1d::ToString() const
{
	char buff[80];
	String str = "conv1d";
	if (HasFilterDim()) {
		::sprintf(buff, ":FN=%zu", GetFilterNum());
		str += buff;
	}
	if (HasChannelDim()) {
		::sprintf(buff, ":C=%zu", GetChannelNum());
		str += buff;
	}
	::sprintf(buff, ":size=%zu", GetSize());
	str += buff;
	::sprintf(buff, ":strides=%zu", GetStrides());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_at=%s", Array::ChannelAtToSymbol(GetChannelAt())->GetName());
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
// filter@conv1d(array:array, strides?:number, padding?:symbol, channel_at?:symbol):map {block?}
Gura_DeclareFunctionAlias(filter_at_conv1d, "filter@conv1d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_at", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_conv1d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@conv1d` instance.\n"
		"\n"
		"The given `array` instance shoud have one of the following shapes:\n"
		"\n"
		"- `[FW]`\n"
		"- `[C, FW]`\n"
		"- `[FN, C, FW]`\n"
		"\n"
		"where `FW` is the size of the filter's kernel,\n"
		"`C` is the number of channels and `FN` is the number of filters.\n"
		);
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
		if (paddingType == Filter::PADDINGTYPE_None) return Value::Nil;
	}
	Array::ChannelAt channelAt = Array::CHANNELAT_Last;
	if (arg.IsValid(3)) {
		channelAt = Array::SymbolToChannelAt(env, arg.GetSymbol(3));
		if (channelAt == Array::CHANNELAT_None) return Value::Nil;
	}
	Object_filter_at_conv1d *pObj = new Object_filter_at_conv1d(
		env, new Filter_Conv1d(pArrayFilter->Reference(), strides, paddingType, channelAt));
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
	Object_array *pObj = new Object_array(env, pFilter->GetArrayFilter()->Reference());
	return Value(pObj);
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
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_conv1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
