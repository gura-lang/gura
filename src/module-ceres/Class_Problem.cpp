#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Problem implementation
//-----------------------------------------------------------------------------
Object_Problem::Object_Problem() : Object(Gura_UserClass(Problem))
{
}

String Object_Problem::ToString(bool exprFlag)
{
	return String("<ceres.Problem>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.Problem() {block?}
Gura_DeclareFunction(Problem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(Problem));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(Problem)
{
	Object_Problem *pObj = new Object_Problem();
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for ceres.Problem
//-----------------------------------------------------------------------------
// implementation of class ceres.Problem
Gura_ImplementUserClass(Problem)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(Problem);
}

Gura_EndModuleScope(ceres)
