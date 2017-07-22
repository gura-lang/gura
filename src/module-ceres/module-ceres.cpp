//=============================================================================
// Gura module: ceres
//=============================================================================
#include "stdafx.h"
#include "ceres/ceres.h"
#include "glog/logging.h"

int helloworld();
int curve_fitting();

Gura_BeginModuleBody(ceres)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// ceres.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(test)
{
	curve_fitting();
	//helloworld();
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// Realization of class
	Gura_RealizeUserClass(CostFunction, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Problem, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(Solver_Options, "Solver$Options", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(Solver_Summary, "Solver$Summary", env.LookupClass(VTYPE_object));
	// Preparation of class
	Gura_PrepareUserClass(CostFunction);
	Gura_PrepareUserClass(Problem);
	Gura_PrepareUserClass(Solver_Options);
	Gura_PrepareUserClass(Solver_Summary);
	// Assignment of function
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ceres, ceres)

Gura_RegisterModule(ceres)
