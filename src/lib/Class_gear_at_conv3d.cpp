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
	GearFuncT gearFunc = gearFuncTable.funcs[pArray->GetElemType()][Array::ETYPE_None];
	if (gearFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply 3-dimension convolution gear on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*gearFunc)(sig, pArrayRtn, pArray, this);
}

String Gear_Conv3d::ToString() const
{
	return "conv3d";
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
	Object_gear_at_conv3d *pObj = new Object_gear_at_conv3d(env, new Gear_Conv3d());
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
