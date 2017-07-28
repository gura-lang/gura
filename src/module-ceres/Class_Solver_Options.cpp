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
// ceres.Solver$Options#minimizer_progress_to_stdout
Gura_DeclareProperty_RW(Solver_Options, minimizer_progress_to_stdout)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, minimizer_progress_to_stdout)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.minimizer_progress_to_stdout);
}

Gura_ImplementPropertySetter(Solver_Options, minimizer_progress_to_stdout)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.minimizer_progress_to_stdout = value.GetBoolean();
	return Value(options.minimizer_progress_to_stdout);
}

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
// Implementation of class ceres.Solver$Options
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Solver_Options)
{
	// Assignment of properties
	Gura_AssignProperty(Solver_Options, minimizer_progress_to_stdout);
	// Assignment of function
	Gura_AssignFunction(Solver_Options);
}

Gura_EndModuleScope(ceres)
