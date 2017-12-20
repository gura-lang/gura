//=============================================================================
// Gura class: gear@conv3d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Conv3d
//-----------------------------------------------------------------------------
Gear_Conv3d::GearFuncTable Gear_Conv3d::gearFuncTable = {{{nullptr}}};

bool Gear_Conv3d::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	size_t sizePadPlane = 0, sizePadRow = 0, sizePadCol = 0;
	CalcPadding3d(this, pArray->GetDimensions(), &sizePadPlane, &sizePadRow, &sizePadCol);
	return pArray->CalcConv3d(sig, pArrayRtn, GetArrayGear(), GetStridesPlane(), GetStridesRow(), GetStridesCol(),
							  sizePadPlane, sizePadRow, sizePadCol, GetChannelPos());
}

String Gear_Conv3d::ToString() const
{
	char buff[80];
	String str = "conv3d";
	str += ":filter_num=";
	if (HasFilterDim()) {
		::sprintf(buff, "%zu", GetFilterNum());
		str += buff;
	} else {
		str += "none";
	}
	str += ":channel_num=";
	if (HasChannelDim()) {
		::sprintf(buff, "%zu", GetChannelNum());
		str += buff;
	} else {
		str += "none";
	}
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
// NodeGear_Conv3d
//-----------------------------------------------------------------------------
bool NodeGear_Conv3d::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_Conv3d::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value NodeGear_Conv3d::DoGetProp(Environment &env, const Symbol *pSymbol,
								   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

bool NodeGear_Conv3d::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool NodeGear_Conv3d::EvalBackward(Environment &env)
{
	return false;
}

Trainer::NodeGear *NodeGear_Conv3d::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Conv3d(Object_gear_at_conv3d::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Object_gear_at_conv3d
//-----------------------------------------------------------------------------
Object_gear_at_conv3d::Object_gear_at_conv3d(Environment &env, Gear_Conv3d *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_conv3d), pGear)
{
}

Object *Object_gear_at_conv3d::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@conv3d(array:array, strides[]?:number, padding?:symbol, channel_pos?:symbol):map {block?}
Gura_DeclareFunctionAlias(gear_at_conv3d, "gear@conv3d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "array", VTYPE_array);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_conv3d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@conv3d` instance.\n");
}

Gura_ImplementFunction(gear_at_conv3d)
{
	const Array *pArrayGear = Object_array::GetObject(arg, 0)->GetArray();
	const Array::Dimensions &dims = pArrayGear->GetDimensions();
	size_t nDims = dims.size();
	if (nDims != 3 && nDims != 4 && nDims != 5) {
		env.SetError(ERR_ValueError,
					 "the `array` instance given to `gear@conv3d` constructor must have dimensions of 3, 4 or 5.");
		return Value::Nil;
	}
	size_t stridesPlane = 1;
	size_t stridesRow = 1;
	size_t stridesCol = 1;
	Gear::PaddingType paddingType = Gear::PADDINGTYPE_Same;
	Array::ChannelPos channelPos = Array::CHANNELPOS_Invalid;
	Value value1, value2, value3;
	if (arg.IsInvalid(1)) {
		// nothing to do
	} else if (arg.GetListValues(1, &value1, &value2, &value3)) {
		stridesPlane = value1.GetSizeT();
		stridesRow = value2.GetSizeT();
		stridesCol = value3.GetSizeT();
	} else {
		env.SetError(ERR_ValueError, "strides must have two elements");
		return Value::Nil;
	}
	if (arg.IsValid(2)) {
		paddingType = Gear::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Gear::PADDINGTYPE_Invalid) return Value::Nil;
	}
	if (arg.IsValid(3)) {
		channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3));
		if (channelPos == Array::CHANNELPOS_Invalid) return Value::Nil;
	} else {
		channelPos = (nDims == 2)? Array::CHANNELPOS_None : Array::CHANNELPOS_Last;
	}
	if (!dims.HasEnoughDims(env, 2, channelPos)) return Value::Nil;
	Object_gear_at_conv3d *pObj = new Object_gear_at_conv3d(
		env, new Gear_Conv3d(pArrayGear->Reference(), stridesPlane, stridesRow, stridesCol, paddingType, channelPos));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_conv3d::Class_gear_at_conv3d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_conv3d)
{
}

void Class_gear_at_conv3d::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_conv3d);
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_conv3d, new NodeGear_Conv3d::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_conv3d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
