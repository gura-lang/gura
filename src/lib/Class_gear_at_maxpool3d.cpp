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
	size_t sizePadPlane = 0, sizePadRow = 0, sizePadCol = 0;
	CalcPadding3d(this, pArray->GetDims(), &sizePadPlane, &sizePadRow, &sizePadCol);
	return pArray->CalcMaxPool3d(sig, pArrayRtn, GetSizePlane(), GetSizeRow(), GetSizeCol(),
								 GetStridesPlane(), GetStridesRow(), GetStridesCol(),
								 sizePadPlane, sizePadRow, sizePadCol, GetChannelPos());
}

bool Gear_MaxPool3d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return Gear::DoDirProp(env, symbols);
}

Value Gear_MaxPool3d::DoGetProp(Environment &env, const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Gear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
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

Object *Gear_MaxPool3d::ToObject(Environment &env) const
{
	return new Object_gear_at_maxpool3d(env, Reference());
}

//-----------------------------------------------------------------------------
// NodeGear_MaxPool3d
//-----------------------------------------------------------------------------
bool NodeGear_MaxPool3d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_MaxPool3d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool NodeGear_MaxPool3d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *NodeGear_MaxPool3d::CreatorEx::Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const
{
	return new NodeGear_MaxPool3d(Object_gear_at_maxpool3d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
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
	size_t stridesPlane = 1;
	size_t stridesRow = 1;
	size_t stridesCol = 1;
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	Array::ChannelPos channelPos = Array::CHANNELPOS_Last;
	Value value1, value2, value3;
	if (arg.GetListValues(0, &value1, &value2, &value3)) {
		sizePlane = value1.GetSizeT();
		sizeRow = value2.GetSizeT();
		sizeCol = value3.GetSizeT();
	} else {
		env.SetError(ERR_ValueError, "size must have three elements");
		return Value::Nil;
	}
	if (arg.IsInvalid(1)) {
		// nothing to do
	} else if (arg.GetListValues(1, &value1, &value2, &value3)) {
		stridesPlane = value1.GetSizeT();
		stridesRow = value2.GetSizeT();
		stridesCol = value3.GetSizeT();
	} else {
		env.SetError(ERR_ValueError, "strides must have three elements");
		return Value::Nil;
	}
	if (arg.IsValid(2)) {
		paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	}
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
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_maxpool3d, new NodeGear_MaxPool3d::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_maxpool3d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
