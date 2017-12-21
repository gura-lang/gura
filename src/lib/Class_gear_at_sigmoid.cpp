//=============================================================================
// Gura class: gear@sigmoid
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Sigmoid
//-----------------------------------------------------------------------------
Gear_Sigmoid::GearFuncTable Gear_Sigmoid::gearFuncTable = {{nullptr}};

bool Gear_Sigmoid::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	GearFuncT gearFunc = gearFuncTable.funcs[pArray->GetElemType()];
	if (gearFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply sigmoid gear on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*gearFunc)(sig, pArrayRtn, pArray, this);
}

String Gear_Sigmoid::ToString() const
{
	return "sigmoid";
}

//-----------------------------------------------------------------------------
// NodeGear_Sigmoid
//-----------------------------------------------------------------------------
bool NodeGear_Sigmoid::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_Sigmoid::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool NodeGear_Sigmoid::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	if (_connectorSrc.GetNodeSrc()->IsVulnerable()) {
		// 1 - y
		if (!Array::Sub(env, _pArrayTmp, 1, _pArrayFwd.get())) return false;
		// (1 - y) * y
		if (!Array::Mul(env, _pArrayTmp, _pArrayTmp.get(), _pArrayFwd.get())) return false;
		if (env.IsSignalled()) return false;
		// (1 - y) * y * bwd_in
		if (!Array::Mul(env, _connectorSrc.GetArrayBwdAutoPtr(),
						_pArrayTmp.get(), (*ppConnectorDst)->GetArrayBwd())) return false;
	}
	return true;
}

bool NodeGear_Sigmoid::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return NodeGear::DoDirProp(env, symbols);
}

Value NodeGear_Sigmoid::DoGetProp(Environment &env, const Symbol *pSymbol,
										   const SymbolSet &attrs, bool &evaluatedFlag)
{
	return NodeGear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

Trainer::NodeGear *NodeGear_Sigmoid::CreatorEx::Create(const Value &value, Connector *pConnectorDst) const
{
	return new NodeGear_Sigmoid(Object_gear_at_sigmoid::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Object_gear_at_sigmoid
//-----------------------------------------------------------------------------
Value Object_gear_at_sigmoid::valueConst;

Object_gear_at_sigmoid::Object_gear_at_sigmoid(Environment &env, Gear_Sigmoid *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_sigmoid), pGear)
{
}

Object *Object_gear_at_sigmoid::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@sigmoid() {block?}
Gura_DeclareFunctionAlias(gear_at_sigmoid, "gear@sigmoid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_sigmoid));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@sigmoid` instance.\n");
}

Gura_ImplementFunction(gear_at_sigmoid)
{
	return ReturnValue(env, arg, Object_gear_at_sigmoid::valueConst);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_sigmoid::Class_gear_at_sigmoid(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_sigmoid)
{
}

void Class_gear_at_sigmoid::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_sigmoid);
	// Assignment of value
	Object_gear_at_sigmoid::valueConst = Value(new Object_gear_at_sigmoid(env, new Gear_Sigmoid()));
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_sigmoid, new NodeGear_Sigmoid::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_sigmoid::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
