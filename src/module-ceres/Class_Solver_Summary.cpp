#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Solver_Summary implementation
//-----------------------------------------------------------------------------
Object_Solver_Summary::Object_Solver_Summary() : Object(Gura_UserClass(Solver_Summary))
{
}

String Object_Solver_Summary::ToString(bool exprFlag)
{
	return String("<ceres.Solver$Summary>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
/*
MinimizerType minimizer_type;
// ceres.Solver$Summary#
Gura_DeclareProperty_RW(Solver_Summary, )
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, )
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.);
}

Gura_ImplementPropertySetter(Solver_Summary, )
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary. = value.Get();
	return Value(summary.);
}

TerminationType termination_type;
std::string message;
double initial_cost;
double final_cost;
double fixed_cost;
int num_successful_steps;
int num_unsuccessful_steps;
int num_inner_iteration_steps;
int num_line_search_steps;
double preprocessor_time_in_seconds;
double minimizer_time_in_seconds;
double postprocessor_time_in_seconds;
double total_time_in_seconds;
double linear_solver_time_in_seconds;
double residual_evaluation_time_in_seconds;
double jacobian_evaluation_time_in_seconds;
double inner_iteration_time_in_seconds;
double line_search_cost_evaluation_time_in_seconds;
double line_search_gradient_evaluation_time_in_seconds;
double line_search_polynomial_minimization_time_in_seconds;
double line_search_total_time_in_seconds;
int num_parameter_blocks;
int num_parameters;
int num_effective_parameters;
int num_residual_blocks;
int num_residuals;
int num_parameter_blocks_reduced;
int num_parameters_reduced;
int num_effective_parameters_reduced;
int num_residual_blocks_reduced;
int num_residuals_reduced;
bool is_constrained;
int num_threads_given;
int num_threads_used;
int num_linear_solver_threads_given;
int num_linear_solver_threads_used;
LinearSolverType linear_solver_type_given;
LinearSolverType linear_solver_type_used;
bool inner_iterations_given;
bool inner_iterations_used;
PreconditionerType preconditioner_type_given;
PreconditionerType preconditioner_type_used;
VisibilityClusteringType visibility_clustering_type;
TrustRegionStrategyType trust_region_strategy_type;
DoglegType dogleg_type;
DenseLinearAlgebraLibraryType dense_linear_algebra_library_type;
SparseLinearAlgebraLibraryType sparse_linear_algebra_library_type;
LineSearchDirectionType line_search_direction_type;
LineSearchType line_search_type;
LineSearchInterpolationType line_search_interpolation_type;
NonlinearConjugateGradientType nonlinear_conjugate_gradient_type;
int max_lbfgs_rank;

std::vector<IterationSummary> iterations;
std::vector<int> linear_solver_ordering_given;
std::vector<int> linear_solver_ordering_used;
std::vector<int> inner_iteration_ordering_given;
std::vector<int> inner_iteration_ordering_used;
*/
	
//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.Solver$Summary() {block?}
Gura_DeclareFunctionAlias(Solver_Summary, "Solver$Summary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(Solver_Summary));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(Solver_Summary)
{
	Object_Solver_Summary *pObj = new Object_Solver_Summary();
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
Gura_DeclareMethod(Solver_Summary, BriefReport)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(Solver_Summary, BriefReport)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObjectThis(arg)->GetSummary();
	return Value(summary.BriefReport().c_str());
}

Gura_DeclareMethod(Solver_Summary, FullReport)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(Solver_Summary, FullReport)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObjectThis(arg)->GetSummary();
	return Value(summary.FullReport().c_str());
}

//-----------------------------------------------------------------------------
// Implementation of class ceres.Solver$Summary
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Solver_Summary)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(Solver_Summary);
	// Assignment of method
	Gura_AssignMethod(Solver_Summary, BriefReport);
	Gura_AssignMethod(Solver_Summary, FullReport);
}

Gura_EndModuleScope(ceres)
