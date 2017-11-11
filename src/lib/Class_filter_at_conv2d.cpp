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
							  sizePadRow, sizePadCol, GetChannelAt());
}

String Filter_Conv2d::ToString() const
{
	char buff[80];
	String str = "conv2d";
	if (HasFilterDim()) {
		::sprintf(buff, ":FN=%zu", GetFilterNum());
		str += buff;
	}
	if (HasChannelDim()) {
		::sprintf(buff, ":C=%zu", GetChannelNum());
		str += buff;
	}
	::sprintf(buff, ":size=(%zu,%zu)", GetSizeRow(), GetSizeCol());
	str += buff;
	::sprintf(buff, ":strides=(%zu,%zu)", GetStridesRow(), GetStridesCol());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_at=%s", Array::ChannelAtToSymbol(GetChannelAt())->GetName());
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
// filter@conv2d(array:array, strides[]?:number, padding?:symbol, channel_at?:symbol):map {block?}
Gura_DeclareFunctionAlias(filter_at_conv2d, "filter@conv2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_at", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_conv2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@conv2d` instance.\n"
		"\n"
		"The given `array` instance shoud have one of the following shapes:\n"
		"\n"
		"- `[FH, FW]`\n"
		"- `[C, FH, FW]`\n"
		"- `[FN, C, FH, FW]`\n"
		"\n"
		"where `FH` and `FW` are the size of the filter's kernel,\n"
		"`C` is the number of channels and `FN` is the number of filters.\n"
		);
}

Gura_ImplementFunction(filter_at_conv2d)
{
	const Array *pArrayFilter = Object_array::GetObject(arg, 0)->GetArray();
	const Array::Dimensions &dims = pArrayFilter->GetDimensions();
	size_t nDims = dims.size();
	if (nDims != 2 && nDims != 3 && nDims != 4) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `filter@conv2d` constructor must have 2, 3 or 4 dimensions.");
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
		if (paddingType == Filter::PADDINGTYPE_None) return Value::Nil;
	}
	Array::ChannelAt channelAt = Array::CHANNELAT_First;
	if (arg.IsValid(3)) {
		channelAt = Array::SymbolToChannelAt(env, arg.GetSymbol(3));
		if (channelAt == Array::CHANNELAT_None) return Value::Nil;
	}
	if (channelAt == Array::CHANNELAT_Last && nDims < 3) {
		env.SetError(ERR_ValueError, "channel dimension is expected to exist at last");
		return Value::Nil;
	}
	Object_filter_at_conv2d *pObj = new Object_filter_at_conv2d(
		env, new Filter_Conv2d(pArrayFilter->Reference(), stridesRow, stridesCol, paddingType, channelAt));
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
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_conv2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
