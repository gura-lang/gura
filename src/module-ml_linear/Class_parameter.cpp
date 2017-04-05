#include "stdafx.h"
#include "Class_parameter.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_parameter implementation
//-----------------------------------------------------------------------------
Object_parameter::Object_parameter() : Object(Gura_UserClass(parameter))
{
}

String Object_parameter::ToString(bool exprFlag)
{
	return String("<ml.linear.parameter>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// ml.linear.parameter() {block?}
Gura_DeclareFunction(parameter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(parameter));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of ml.linear.parameter.\n");
}

Gura_ImplementFunction(parameter)
{
	return ReturnValue(env, arg, Value(new Object_parameter()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(parameter)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(parameter);
	// Assignment of value
	Gura_AssignValue(parameter, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
