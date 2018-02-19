//=============================================================================
// Gura class: gear@tanh
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Tanh
//-----------------------------------------------------------------------------
Gear_Tanh::GearFuncTable Gear_Tanh::gearFuncTable = {{nullptr}};

bool Gear_Tanh::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	GearFuncT gearFunc = gearFuncTable.funcs[pArray->GetElemType()];
	if (gearFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply tanh gear on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*gearFunc)(sig, pArrayRtn, pArray, this);
}

bool Gear_Tanh::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return Gear::DoDirProp(env, symbols);
}

Value Gear_Tanh::DoGetProp(Environment &env, const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Gear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Gear_Tanh::ToString() const
{
	return "tanh";
}

Object *Gear_Tanh::ToObject(Environment &env) const
{
	return new Object_gear_at_tanh(env, Reference());
}

//-----------------------------------------------------------------------------
// NodeGear_Tanh
//-----------------------------------------------------------------------------
bool NodeGear_Tanh::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_Tanh::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool NodeGear_Tanh::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	const Array *pArrayGradSrc = (*ppConnectorDst)->GetArrayGrad();
	// grad_in = grad_out * (1 - out ** 2)
	if (!Array::Mul(env, _pArrayWork1, _pArrayFwd.get(), _pArrayFwd.get())) return false;
	if (!Array::Sub(env, _pArrayWork2, 1, _pArrayWork1.get())) return false;
	if (!Array::Mul(env, GetConnectorSrc()->GetArrayGradAutoPtr(), pArrayGradSrc, _pArrayWork2.get())) return false;
	return true;
}

Trainer::NodeGear *NodeGear_Tanh::CreatorEx::Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const
{
	return new NodeGear_Tanh(Object_gear_at_tanh::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Object_gear_at_tanh
//-----------------------------------------------------------------------------
Value Object_gear_at_tanh::valueConst;

Object_gear_at_tanh::Object_gear_at_tanh(Environment &env, Gear_Tanh *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_tanh), pGear)
{
}

Object *Object_gear_at_tanh::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@tanh() {block?}
Gura_DeclareFunctionAlias(gear_at_tanh, "gear@tanh")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_tanh));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@tanh` instance.\n");
}

Gura_ImplementFunction(gear_at_tanh)
{
	return ReturnValue(env, arg, Object_gear_at_tanh::valueConst);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_tanh::Class_gear_at_tanh(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_tanh)
{
}

void Class_gear_at_tanh::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_tanh);
	// Assignment of value
	Object_gear_at_tanh::valueConst = Value(new Object_gear_at_tanh(env, new Gear_Tanh()));
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_tanh, new NodeGear_Tanh::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_tanh::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
