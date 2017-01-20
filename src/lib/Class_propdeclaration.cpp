//=============================================================================
// Gura class: propdeclaration
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_propdeclaration
//-----------------------------------------------------------------------------
Object_propdeclaration::Object_propdeclaration(const Object_propdeclaration &obj) :
	Object(obj), _pPropDeclaration(obj._pPropDeclaration->Reference())
{
}

Object *Object_propdeclaration::Clone() const
{
	return new Object_propdeclaration(*this);
}

String Object_propdeclaration::ToString(bool exprFlag)
{
	return "<propdeclaration>";
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_propdeclaration::Class_propdeclaration(Environment *pEnvOuter) :
	Class(pEnvOuter, VTYPE_propdeclaration)
{
}

void Class_propdeclaration::DoPrepare(Environment &env)
{
	// Assignment of value
	Gura_AssignValue(propdeclaration, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_propdeclaration::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
