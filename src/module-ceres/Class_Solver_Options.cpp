#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Solver_Options implementation
//-----------------------------------------------------------------------------
Object_Solver_Options::Object_Solver_Options() : Object(Gura_UserClass(Solver_Options))
{
}

String Object_Solver_Options::ToString(bool exprFlag)
{
	return String("<ceres.Solver$Options>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.Solver$Options() {block?}
Gura_DeclareFunctionAlias(Solver_Options, "Solver$Options")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(Solver_Options));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(Solver_Options)
{
	Object_Solver_Options *pObj = new Object_Solver_Options();
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for ceres.Solver_Options
//-----------------------------------------------------------------------------
// implementation of class ceres.Solver_Options
Gura_ImplementUserClass(Solver_Options)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(Solver_Options);
}

Gura_EndModuleScope(ceres)
