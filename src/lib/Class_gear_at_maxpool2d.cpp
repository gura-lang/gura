//=============================================================================
// Gura class: gear@maxpool2d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_MaxPool2d
//-----------------------------------------------------------------------------
bool Gear_MaxPool2d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePadRow = 0, sizePadCol = 0;
	CalcPadding2d(this, pArray->GetDimensions(), &sizePadRow, &sizePadCol);
	return pArray->CalcMaxPool2d(sig, pArrayRtn, GetSizeRow(), GetSizeCol(), GetStridesRow(), GetStridesCol(),
								 sizePadRow, sizePadCol, GetChannelPos());
}

String Gear_MaxPool2d::ToString() const
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
// Object_gear_at_maxpool2d
//-----------------------------------------------------------------------------
Object_gear_at_maxpool2d::Object_gear_at_maxpool2d(Environment &env, Gear_MaxPool2d *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_maxpool2d), pGear)
{
}

Object *Object_gear_at_maxpool2d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@maxpool2d(size[]:number, strides[]?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(gear_at_maxpool2d, "gear@maxpool2d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_maxpool2d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@maxpool2d` instance.\n");
}

Gura_ImplementFunction(gear_at_maxpool2d)
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
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	if (arg.IsValid(2)) {
		paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	}
	Array::ChannelPos channelPos = Array::CHANNELPOS_Last;
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) return Value::Nil;
	}
	Object_gear_at_maxpool2d *pObj = new Object_gear_at_maxpool2d(
		env, new Gear_MaxPool2d(sizeRow, sizeCol, stridesRow, stridesCol, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// gear@maxpool2d#channel_pos
Gura_DeclareProperty_R(gear_at_maxpool2d, channel_pos)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_maxpool2d, channel_pos)
{
	const Gear_MaxPool2d *pGear = Object_gear_at_maxpool2d::GetObject(valueThis)->GetGear();
	return Value(Array::ChannelPosToSymbol(pGear->GetChannelPos()));
}

// gear@maxpool2d#padding
Gura_DeclareProperty_R(gear_at_maxpool2d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_maxpool2d, padding)
{
	const Gear_MaxPool2d *pGear = Object_gear_at_maxpool2d::GetObject(valueThis)->GetGear();
	return Value(Gear::PaddingTypeToSymbol(pGear->GetPaddingType()));
}

// gear@maxpool2d#size
Gura_DeclareProperty_R(gear_at_maxpool2d, size)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_maxpool2d, size)
{
	const Gear_MaxPool2d *pGear = Object_gear_at_maxpool2d::GetObject(valueThis)->GetGear();
	return Value::CreateList(env, Value(pGear->GetSizeRow()), Value(pGear->GetSizeCol()));
}

// gear@maxpool2d#strides
Gura_DeclareProperty_R(gear_at_maxpool2d, strides)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_maxpool2d, strides)
{
	const Gear_MaxPool2d *pGear = Object_gear_at_maxpool2d::GetObject(valueThis)->GetGear();
	return Value::CreateList(env, Value(pGear->GetStridesRow()), Value(pGear->GetStridesCol()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_maxpool2d::Class_gear_at_maxpool2d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_maxpool2d)
{
}

void Class_gear_at_maxpool2d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_maxpool2d);
	// Assignment of properties
	Gura_AssignProperty(gear_at_maxpool2d, channel_pos);
	Gura_AssignProperty(gear_at_maxpool2d, padding);
	Gura_AssignProperty(gear_at_maxpool2d, size);
	Gura_AssignProperty(gear_at_maxpool2d, strides);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_maxpool2d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
