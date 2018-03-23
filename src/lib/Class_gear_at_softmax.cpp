//=============================================================================
// Gura class: gear@softmax
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Softmax
//-----------------------------------------------------------------------------
Gear_Softmax::GearFuncTable Gear_Softmax::gearFuncTable = {{nullptr}};

bool Gear_Softmax::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	GearFuncT gearFunc = gearFuncTable.funcs[pArray->GetElemType()];
	if (gearFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply softmax gear on array@%s",
					 pArray->GetElemTypeName());
		return false;
	}
	return (*gearFunc)(sig, pArrayRtn, pArray, this);
}

bool Gear_Softmax::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return Gear::DoDirProp(env, symbols);
}

Value Gear_Softmax::DoGetProp(Environment &env, const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Gear::DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Gear_Softmax::ToString() const
{
	return "softmax";
}

Object *Gear_Softmax::ToObject(Environment &env) const
{
	return new Object_gear_at_softmax(env, Reference());
}

//-----------------------------------------------------------------------------
// NodeGear_Softmax
//-----------------------------------------------------------------------------
bool NodeGear_Softmax::IsVulnerable() const
{
	return _connectorSrc.GetNodeSrc()->IsVulnerable();
}

bool NodeGear_Softmax::EvalForward(Environment &env)
{
	return _pGear->Apply(env, _pArrayFwd, GetConnectorSrc()->GetArrayFwd());
}

bool NodeGear_Softmax::EvalBackward(Environment &env)
{
	ConnectorList::iterator ppConnectorDst = _connectorsDst.begin();
	if (ppConnectorDst == _connectorsDst.end()) return true;
	_connectorSrc.SetArrayGrad((*ppConnectorDst)->GetArrayGrad()->Reference());
	return true;
}

Trainer::NodeGear *NodeGear_Softmax::CreatorEx::Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const
{
	return new NodeGear_Softmax(Object_gear_at_softmax::GetObject(value)->GetGear()->Reference(), pConnectorDst);
}

//-----------------------------------------------------------------------------
// Object_gear_at_softmax
//-----------------------------------------------------------------------------
Object_gear_at_softmax::Object_gear_at_softmax(Environment &env, Gear_Softmax *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_softmax), pGear)
{
}

Object *Object_gear_at_softmax::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@softmax(axis?:number):map {block?}
Gura_DeclareFunctionAlias(gear_at_softmax, "gear@softmax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_softmax));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@softmax` instance.\n");
}

Gura_ImplementFunction(gear_at_softmax)
{
	size_t axis = arg.IsValid(0)? arg.GetSizeT(0) : static_cast<size_t>(-1);
	Object_gear_at_softmax *pObj = new Object_gear_at_softmax(env, new Gear_Softmax(axis));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// gear@softmax#axis
Gura_DeclareProperty_R(gear_at_softmax, axis)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(gear_at_softmax, axis)
{
	const Gear_Softmax *pGear = Object_gear_at_softmax::GetObject(valueThis)->GetGear();
	size_t axis = pGear->GetAxis();
	return (axis == static_cast<size_t>(-1))? Value::Nil : Value(axis);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_softmax::Class_gear_at_softmax(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_softmax)
{
}

void Class_gear_at_softmax::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_softmax);
	// Assignment of properties
	Gura_AssignProperty(gear_at_softmax, axis);
	// Assignment of value
	// Assignment of NodeGear creator for Trainer
	Trainer::RegisterNodeGearCreator(VTYPE_gear_at_softmax, new NodeGear_Softmax::CreatorEx());
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_softmax::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
