//=============================================================================
// Gura class: gear@maxpool3d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_MaxPool3d
//-----------------------------------------------------------------------------
bool Gear_MaxPool3d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizeOutPlane = 0, sizePadPlane = 0;
	size_t sizeOutRow = 0, sizePadRow = 0;
	size_t sizeOutCol = 0, sizePadCol = 0;
	bool chLastFlag = (GetChannelPos() == Array::CHANNELPOS_Last);
	const Array::Dimensions &dims = pArray->GetDimensions();
	Gear::CalcPadding(dims.GetBack(chLastFlag? 3 : 2).GetSize(),
						GetSizePlane(), GetStridesPlane(), GetPaddingType(),
						&sizeOutPlane, &sizePadPlane);
	Gear::CalcPadding(dims.GetBack(chLastFlag? 2 : 1).GetSize(),
						GetSizeRow(), GetStridesRow(), GetPaddingType(),
						&sizeOutRow, &sizePadRow);
	Gear::CalcPadding(dims.GetBack(chLastFlag? 1 : 0).GetSize(),
						GetSizeCol(), GetStridesCol(), GetPaddingType(),
						&sizeOutCol, &sizePadCol);
	pArray->CalcMaxPool3d(pArrayRtn, GetSizePlane(), GetSizeRow(), GetSizeCol(),
						  GetStridesPlane(), GetStridesRow(), GetStridesCol(),
						  sizePadPlane, sizePadRow, sizePadCol, GetChannelPos());
	return true;
}

String Gear_MaxPool3d::ToString() const
{
	String str;
	char buff[80];
	str += "maxpool2d";
	::sprintf(buff, ":size=(%zu,%zu,%zu)", GetSizePlane(), GetSizeRow(), GetSizeCol());
	str += buff;
	::sprintf(buff, ":strides=(%zu,%zu,%zu)", GetStridesPlane(), GetStridesRow(), GetStridesCol());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_pos=%s", Array::ChannelPosToSymbol(GetChannelPos())->GetName());
	str += buff;
	return str;
}

//-----------------------------------------------------------------------------
// Object_gear_at_maxpool3d
//-----------------------------------------------------------------------------
Object_gear_at_maxpool3d::Object_gear_at_maxpool3d(Environment &env, Gear_MaxPool3d *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_maxpool3d), pGear)
{
}

Object *Object_gear_at_maxpool3d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@maxpool3d(size[]:number, strides[]?:number, padding?:symbol, format?:symbol):map {block?}
Gura_DeclareFunctionAlias(gear_at_maxpool3d, "gear@maxpool3d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_maxpool3d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@maxpool3d` instance.\n");
}

Gura_ImplementFunction(gear_at_maxpool3d)
{
	size_t sizePlane = 0;
	size_t sizeRow = 0;
	size_t sizeCol = 0;
	do {
		const ValueList &valList = arg.GetList(0);
		if (valList.size() != 3) {
			env.SetError(ERR_ValueError, "size must have three elements");
			return Value::Nil;
		}
		sizePlane = valList[0].GetSizeT();
		sizeRow = valList[1].GetSizeT();
		sizeCol = valList[2].GetSizeT();
	} while (0);
	size_t stridesPlane = 1;
	size_t stridesRow = 1;
	size_t stridesCol = 1;
	if (arg.IsValid(1)) {
		const ValueList &valList = arg.GetList(1);
		if (valList.size() != 3) {
			env.SetError(ERR_ValueError, "strides must have three elements");
			return Value::Nil;
		}
		stridesPlane = valList[0].GetSizeT();
		stridesRow = valList[1].GetSizeT();
		stridesCol = valList[2].GetSizeT();
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
	Object_gear_at_maxpool3d *pObj = new Object_gear_at_maxpool3d(
		env, new Gear_MaxPool3d(sizePlane, sizeRow, sizeCol,
								  stridesPlane, stridesRow, stridesCol, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_maxpool3d::Class_gear_at_maxpool3d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_maxpool3d)
{
}

void Class_gear_at_maxpool3d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_maxpool3d);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_maxpool3d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
