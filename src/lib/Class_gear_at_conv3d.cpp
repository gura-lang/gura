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
// gear@conv3d():map {block?}
Gura_DeclareFunctionAlias(gear_at_conv3d, "gear@conv3d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_gear_at_conv3d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
