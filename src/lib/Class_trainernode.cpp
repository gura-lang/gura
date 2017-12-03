//=============================================================================
// Gura class: trainernode
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_trainernode
//-----------------------------------------------------------------------------
Object_trainernode::Object_trainernode(const Object_trainernode &obj) :
								Object(obj), _pNode(obj._pNode->Reference())
{
}

Object_trainernode::~Object_trainernode()
{
}

Object *Object_trainernode::Clone() const
{
	return new Object_trainernode(*this);
}

String Object_trainernode::ToString(bool exprFlag)
{
	String str;
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_trainernode::Class_trainernode(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_trainernode)
{
}

void Class_trainernode::DoPrepare(Environment &env)
{
	// Assignment of function
	// Assignment of properties
	// Assignment of methods
	// Assignment of values
	Gura_AssignValue(trainernode, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_trainernode::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
