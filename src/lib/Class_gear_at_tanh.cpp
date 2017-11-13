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

String Gear_Tanh::ToString() const
{
	return "tanh";
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
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_tanh::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
