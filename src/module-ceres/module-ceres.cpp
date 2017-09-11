//=============================================================================
// Gura module: ceres
//=============================================================================
#include "stdafx.h"
#include "ceres/ceres.h"
#include "glog/logging.h"
#include "ArrayChain.h"

namespace helloworld { int main(); }
namespace helloworld_analytic_diff { int main(); }
namespace curve_fitting { int main(); }
namespace robust_curve_fitting { int main(); }
namespace ellipse_approximation { int main(); }

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

// ceres.test(expr:expr)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "expr", VTYPE_expr);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(test)
{
	ArrayChainOwner arrayChainOwner;
	arrayChainOwner.CreateFromExpr(env, Object_expr::GetObject(arg, 0)->GetExpr());
	arrayChainOwner.front()->Print(0);
	if (!arrayChainOwner.InitForward(env)) return Value::Nil;
	arrayChainOwner.front()->Print(0);
	if (!arrayChainOwner.InitBackward(env)) return Value::Nil;
	arrayChainOwner.front()->Print(0);
	if (!arrayChainOwner.EvalForward(env)) return Value::Nil;
	if (!arrayChainOwner.EvalBackward(env)) return Value::Nil;
	return Value::Nil;
}

// ceres.example@helloworld():void
Gura_DeclareFunctionAlias(example_at_helloworld, "example@helloworld")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(example_at_helloworld)
{
	helloworld::main();
	return Value::Nil;
}

// ceres.example@helloworld_analytic_diff():void
Gura_DeclareFunctionAlias(example_at_helloworld_analytic_diff, "example@helloworld_analytic_diff")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(example_at_helloworld_analytic_diff)
{
	helloworld_analytic_diff::main();
	return Value::Nil;
}

// ceres.example@curve_fitting():void
Gura_DeclareFunctionAlias(example_at_curve_fitting, "example@curve_fitting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(example_at_curve_fitting)
{
	curve_fitting::main();
	return Value::Nil;
}

// ceres.example@robust_curve_fitting():void
Gura_DeclareFunctionAlias(example_at_robust_curve_fitting, "example@robust_curve_fitting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(example_at_robust_curve_fitting)
{
	robust_curve_fitting::main();
	return Value::Nil;
}

// ceres.example@ellipse_approximation():void
Gura_DeclareFunctionAlias(example_at_ellipse_approximation, "example@ellipse_approximation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(example_at_ellipse_approximation)
{
	ellipse_approximation::main();
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
	Gura_AssignFunction(test);
	Gura_AssignFunction(example_at_helloworld);
	Gura_AssignFunction(example_at_helloworld_analytic_diff);
	Gura_AssignFunction(example_at_curve_fitting);
	Gura_AssignFunction(example_at_robust_curve_fitting);
	Gura_AssignFunction(example_at_ellipse_approximation);
	// Assignment of value
	// Ownership
	Gura_AssignValueEx("DO_NOT_TAKE_OWNERSHIP", ceres::DO_NOT_TAKE_OWNERSHIP);
	Gura_AssignValueEx("TAKE_OWNERSHIP", ceres::TAKE_OWNERSHIP);
	// LinearSolverType
	Gura_AssignValueEx("DENSE_NORMAL_CHOLESKY", ceres::DENSE_NORMAL_CHOLESKY);
	Gura_AssignValueEx("DENSE_QR", ceres::DENSE_QR);
	Gura_AssignValueEx("SPARSE_NORMAL_CHOLESKY", ceres::SPARSE_NORMAL_CHOLESKY);
	Gura_AssignValueEx("DENSE_SCHUR", ceres::DENSE_SCHUR);
	Gura_AssignValueEx("SPARSE_SCHUR", ceres::SPARSE_SCHUR);
	Gura_AssignValueEx("ITERATIVE_SCHUR", ceres::ITERATIVE_SCHUR);
	Gura_AssignValueEx("CGNR", ceres::CGNR);
	// PreconditionerType
	Gura_AssignValueEx("IDENTITY", ceres::IDENTITY);
	Gura_AssignValueEx("JACOBI", ceres::JACOBI);
	Gura_AssignValueEx("SCHUR_JACOBI", ceres::SCHUR_JACOBI);
	Gura_AssignValueEx("CLUSTER_JACOBI", ceres::CLUSTER_JACOBI);
	Gura_AssignValueEx("CLUSTER_TRIDIAGONAL", ceres::CLUSTER_TRIDIAGONAL);
	// VisibilityClusteringType
	Gura_AssignValueEx("CANONICAL_VIEWS", ceres::CANONICAL_VIEWS);
	Gura_AssignValueEx("SINGLE_LINKAGE", ceres::SINGLE_LINKAGE);
	// SparseLinearAlgebraLibraryType
	Gura_AssignValueEx("SUITE_SPARSE", ceres::SUITE_SPARSE);
	Gura_AssignValueEx("CX_SPARSE", ceres::CX_SPARSE);
	Gura_AssignValueEx("EIGEN_SPARSE", ceres::EIGEN_SPARSE);
	Gura_AssignValueEx("NO_SPARSE", ceres::NO_SPARSE);
	// DenseLinearAlgebraLibraryType
	Gura_AssignValueEx("EIGEN", ceres::EIGEN);
	Gura_AssignValueEx("LAPACK", ceres::LAPACK);
	// LoggingType
	Gura_AssignValueEx("SILENT", ceres::SILENT);
	Gura_AssignValueEx("PER_MINIMIZER_ITERATION", ceres::PER_MINIMIZER_ITERATION);
	// MinimizerType
	Gura_AssignValueEx("LINE_SEARCH", ceres::LINE_SEARCH);
	Gura_AssignValueEx("TRUST_REGION", ceres::TRUST_REGION);
	// LineSearchDirectionType
	Gura_AssignValueEx("STEEPEST_DESCENT", ceres::STEEPEST_DESCENT);
	Gura_AssignValueEx("NONLINEAR_CONJUGATE_GRADIENT", ceres::NONLINEAR_CONJUGATE_GRADIENT);
	Gura_AssignValueEx("LBFGS", ceres::LBFGS);
	Gura_AssignValueEx("BFGS", ceres::BFGS);
	// NonlinearConjugateGradientType
	Gura_AssignValueEx("FLETCHER_REEVES", ceres::FLETCHER_REEVES);
	Gura_AssignValueEx("POLAK_RIBIERE", ceres::POLAK_RIBIERE);
	Gura_AssignValueEx("HESTENES_STIEFEL", ceres::HESTENES_STIEFEL);
	// LineSearchType
	Gura_AssignValueEx("ARMIJO", ceres::ARMIJO);
	Gura_AssignValueEx("WOLFE", ceres::WOLFE);
	// TrustRegionStrategyType
	Gura_AssignValueEx("LEVENBERG_MARQUARDT", ceres::LEVENBERG_MARQUARDT);
	Gura_AssignValueEx("DOGLEG", ceres::DOGLEG);
	// DoglegType
	Gura_AssignValueEx("TRADITIONAL_DOGLEG", ceres::TRADITIONAL_DOGLEG);
	Gura_AssignValueEx("SUBSPACE_DOGLEG", ceres::SUBSPACE_DOGLEG);
	// TerminationType
	Gura_AssignValueEx("CONVERGENCE", ceres::CONVERGENCE);
	Gura_AssignValueEx("NO_CONVERGENCE", ceres::NO_CONVERGENCE);
	Gura_AssignValueEx("FAILURE", ceres::FAILURE);
	Gura_AssignValueEx("USER_SUCCESS", ceres::USER_SUCCESS);
	Gura_AssignValueEx("USER_FAILURE", ceres::USER_FAILURE);
	// CallbackReturnType
	Gura_AssignValueEx("SOLVER_CONTINUE", ceres::SOLVER_CONTINUE);
	Gura_AssignValueEx("SOLVER_ABORT", ceres::SOLVER_ABORT);
	Gura_AssignValueEx("SOLVER_TERMINATE_SUCCESSFULLY", ceres::SOLVER_TERMINATE_SUCCESSFULLY);
	// DumpFormatType
	Gura_AssignValueEx("CONSOLE", ceres::CONSOLE);
	Gura_AssignValueEx("TEXTFILE", ceres::TEXTFILE);
	// DimensionType
	Gura_AssignValueEx("DYNAMIC", ceres::DYNAMIC);
	// NumericDiffMethodType
	Gura_AssignValueEx("CENTRAL", ceres::CENTRAL);
	Gura_AssignValueEx("FORWARD", ceres::FORWARD);
	Gura_AssignValueEx("RIDDERS", ceres::RIDDERS);
	// LineSearchInterpolationType
	Gura_AssignValueEx("BISECTION", ceres::BISECTION);
	Gura_AssignValueEx("QUADRATIC", ceres::QUADRATIC);
	Gura_AssignValueEx("CUBIC", ceres::CUBIC);
	// CovarianceAlgorithmType
	Gura_AssignValueEx("DENSE_SVD", ceres::DENSE_SVD);
	Gura_AssignValueEx("SUITE_SPARSE_QR", ceres::SUITE_SPARSE_QR);
	Gura_AssignValueEx("EIGEN_SPARSE_QR", ceres::EIGEN_SPARSE_QR);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ceres, ceres)

Gura_RegisterModule(ceres)
