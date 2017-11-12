//=============================================================================
// Gura class: filter@maxpool2d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_MaxPool2d
//-----------------------------------------------------------------------------
bool Filter_MaxPool2d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizeOutRow = 0, sizePadRow = 0;
	size_t sizeOutCol = 0, sizePadCol = 0;
	bool chLastFlag = (GetChannelPos() == Array::CHANNELPOS_Last);
	const Array::Dimensions &dims = pArray->GetDimensions();
	Filter::CalcPadding(dims.GetBack(chLastFlag? 2 : 1).GetSize(),
						GetSizeRow(), GetStridesRow(), GetPaddingType(),
						&sizeOutRow, &sizePadRow);
	Filter::CalcPadding(dims.GetBack(chLastFlag? 1 : 0).GetSize(),
						GetSizeCol(), GetStridesCol(), GetPaddingType(),
						&sizeOutCol, &sizePadCol);
	pArray->CalcMaxPool2d(pArrayRtn, GetSizeRow(), GetSizeCol(), GetStridesRow(), GetStridesCol(),
						  sizePadRow, sizePadCol, GetChannelPos());
	return true;
}

String Filter_MaxPool2d::ToString() const
{
	String str;
	char buff[80];
	str += "maxpool2d";
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
// Object_filter_at_maxpool2d
//-----------------------------------------------------------------------------
Object_filter_at_maxpool2d::Object_filter_at_maxpool2d(Environment &env, Filter_MaxPool2d *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_maxpool2d), pFilter)
{
}

Object *Object_filter_at_maxpool2d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@maxpool2d(size[]:number, strides[]?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(filter_at_maxpool2d, "filter@maxpool2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_maxpool2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@maxpool2d` instance.\n");
}

Gura_ImplementFunction(filter_at_maxpool2d)
{
	size_t sizeRow = 0;
	size_t sizeCol = 0;
	do {
		const ValueList &valList = arg.GetList(0);
		if (valList.size() != 2) {
			env.SetError(ERR_ValueError, "size must have two elements");
			return Value::Nil;
		}
		sizeRow = valList[0].GetSizeT();
		sizeCol = valList[1].GetSizeT();
	} while (0);
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
	Array::ChannelPos channelPos = Array::CHANNELPOS_Last;
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) return Value::Nil;
	}
	Object_filter_at_maxpool2d *pObj = new Object_filter_at_maxpool2d(
		env, new Filter_MaxPool2d(sizeRow, sizeCol, stridesRow, stridesCol, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// filter@maxpool2d#size
Gura_DeclareProperty_R(filter_at_maxpool2d, size)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool2d, size)
{
	const Filter_MaxPool2d *pFilter = Object_filter_at_maxpool2d::GetObject(valueThis)->GetFilter();
	return Value::CreateList(env, Value(pFilter->GetSizeCol()), Value(pFilter->GetSizeRow()));
}

// filter@maxpool2d#strides
Gura_DeclareProperty_R(filter_at_maxpool2d, strides)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool2d, strides)
{
	const Filter_MaxPool2d *pFilter = Object_filter_at_maxpool2d::GetObject(valueThis)->GetFilter();
	return Value::CreateList(env, Value(pFilter->GetStridesCol()), Value(pFilter->GetStridesRow()));
}

// filter@maxpool2d#padding
Gura_DeclareProperty_R(filter_at_maxpool2d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool2d, padding)
{
	const Filter_MaxPool2d *pFilter = Object_filter_at_maxpool2d::GetObject(valueThis)->GetFilter();
	return Value(Filter::PaddingTypeToSymbol(pFilter->GetPaddingType()));
}

// filter@maxpool2d#channel_pos
Gura_DeclareProperty_R(filter_at_maxpool2d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool2d, channel_pos)
{
	const Filter_MaxPool2d *pFilter = Object_filter_at_maxpool2d::GetObject(valueThis)->GetFilter();
	return Value(Array::ChannelPosToSymbol(pFilter->GetChannelPos()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_maxpool2d::Class_filter_at_maxpool2d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_maxpool2d)
{
}

void Class_filter_at_maxpool2d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(filter_at_maxpool2d);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_maxpool2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
