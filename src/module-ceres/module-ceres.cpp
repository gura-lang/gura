//=============================================================================
// Gura module: ceres
//=============================================================================
#include "stdafx.h"
#include "ceres/ceres.h"
#include "glog/logging.h"

int helloworld();
int helloworld_analytic_diff();
int curve_fitting();

Gura_BeginModuleBody(ceres)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// ceres.sample@helloworld():void
Gura_DeclareFunctionAlias(sample_at_helloworld, "sample@helloworld")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(sample_at_helloworld)
{
	helloworld();
	return Value::Nil;
}

// ceres.sample@helloworld_analytic_diff():void
Gura_DeclareFunctionAlias(sample_at_helloworld_analytic_diff, "sample@helloworld_analytic_diff")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(sample_at_helloworld_analytic_diff)
{
	helloworld_analytic_diff();
	return Value::Nil;
}

// ceres.sample@curve_fitting():void
Gura_DeclareFunctionAlias(sample_at_curve_fitting, "sample@curve_fitting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(sample_at_curve_fitting)
{
	curve_fitting();
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
	Gura_AssignFunction(sample_at_helloworld);
	Gura_AssignFunction(sample_at_helloworld_analytic_diff);
	Gura_AssignFunction(sample_at_curve_fitting);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ceres, ceres)

Gura_RegisterModule(ceres)