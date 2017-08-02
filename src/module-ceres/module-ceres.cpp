//=============================================================================
// Gura module: ceres
//=============================================================================
#include "stdafx.h"
#include "ceres/ceres.h"
#include "glog/logging.h"

int helloworld();
int helloworld_analytic_diff();
int curve_fitting();
int ellipse_approximation();

Gura_BeginModuleBody(ceres)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// ceres.Solve(options:ceres.Solver$Options, problem:ceres.Problem, summary:ceres.Solver$Summary):void
Gura_DeclareFunction(Solve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "options", VTYPE_Solver_Options);
	DeclareArg(env, "problem", VTYPE_Problem);
	DeclareArg(env, "summary", VTYPE_Solver_Summary);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(Solve)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(arg, 0)->GetOptions();
	ceres::Problem &problem = Object_Problem::GetObject(arg, 1)->GetProblem();
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(arg, 2)->GetSummary();
	ceres::Solve(options, &problem, &summary);
	return Value::Nil;
}

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

// ceres.sample@ellipse_approximation():void
Gura_DeclareFunctionAlias(sample_at_ellipse_approximation, "sample@ellipse_approximation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(sample_at_ellipse_approximation)
{
	ellipse_approximation();
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
	// symbol realization
	Gura_RealizeUserSymbol(Evaluate);
	// Realization of class
	Gura_RealizeUserClass(CostFunction, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(NumericDiffCostFunction, Gura_UserClass(CostFunction));
	Gura_RealizeUserClass(LossFunction, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Problem, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(Solver_Options, "Solver$Options", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(Solver_Summary, "Solver$Summary", env.LookupClass(VTYPE_object));
	// Preparation of class
	Gura_PrepareUserClass(CostFunction);
	Gura_PrepareUserClass(NumericDiffCostFunction);
	Gura_PrepareUserClass(LossFunction);
	Gura_PrepareUserClass(Problem);
	Gura_PrepareUserClass(Solver_Options);
	Gura_PrepareUserClass(Solver_Summary);
	// Assignment of function
	Gura_AssignFunction(Solve);
	Gura_AssignFunction(sample_at_helloworld);
	Gura_AssignFunction(sample_at_helloworld_analytic_diff);
	Gura_AssignFunction(sample_at_curve_fitting);
	Gura_AssignFunction(sample_at_ellipse_approximation);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ceres, ceres)

Gura_RegisterModule(ceres)
