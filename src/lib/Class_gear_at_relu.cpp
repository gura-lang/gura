//=============================================================================
// Gura class: gear@relu
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Gear_Relu
//-----------------------------------------------------------------------------
Gear_Relu::GearFuncTable Gear_Relu::gearFuncTable = {{nullptr}};

bool Gear_Relu::Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const
{
	GearFuncT gearFunc = gearFuncTable.funcs[pArray->GetElemType()];
	if (gearFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply ReLU gear on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*gearFunc)(sig, pArrayRtn, pArray, this);
}

String Gear_Relu::ToString() const
{
	return "relu";
}

//-----------------------------------------------------------------------------
// Object_gear_at_relu
//-----------------------------------------------------------------------------
Value Object_gear_at_relu::valueConst;

Object_gear_at_relu::Object_gear_at_relu(Environment &env, Gear_Relu *pGear) :
	Object_gear(env.LookupClass(VTYPE_gear_at_relu), pGear)
{
}

Object *Object_gear_at_relu::Clone() const
{
	return nullptr;
}
	
//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gear@relu() {block?}
Gura_DeclareFunctionAlias(gear_at_relu, "gear@relu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_gear_at_relu));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `gear@relu` instance.\n");
}

Gura_ImplementFunction(gear_at_relu)
{
	return ReturnValue(env, arg, Object_gear_at_relu::valueConst);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_gear_at_relu::Class_gear_at_relu(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_gear_at_relu)
{
}

void Class_gear_at_relu::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(gear_at_relu);
	// Assignment of value
	Object_gear_at_relu::valueConst = Value(new Object_gear_at_relu(env, new Gear_Relu()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_relu::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
