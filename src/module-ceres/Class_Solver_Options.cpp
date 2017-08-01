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
/*
number      minimizer_type = TRUST_REGION;
number      line_search_direction_type = LBFGS;
number      line_search_type = WOLFE;
number      nonlinear_conjugate_gradient_type = FLETCHER_REEVES;
number      max_lbfgs_rank = 20;
boolean      use_approximate_eigenvalue_bfgs_scaling = false;
number      line_search_interpolation_type = CUBIC;
number      min_line_search_step_size = 1e-9;
number      line_search_sufficient_function_decrease = 1e-4;
number      max_line_search_step_contraction = 1e-3;
number      min_line_search_step_contraction = 0.6;
number      max_num_line_search_step_size_iterations = 20;
number      max_num_line_search_direction_restarts = 5;
number      line_search_sufficient_curvature_decrease = 0.9;
number      max_line_search_step_expansion = 10.0;
number      trust_region_strategy_type = LEVENBERG_MARQUARDT;
number      dogleg_type = TRADITIONAL_DOGLEG;
boolean      use_nonmonotonic_steps = false;
number      max_consecutive_nonmonotonic_steps = 5;
number      max_num_iterations = 50;
number      max_solver_time_in_seconds = 1e9;
number      num_threads = 1;
number      initial_trust_region_radius = 1e4;
number      max_trust_region_radius = 1e16;
number      min_trust_region_radius = 1e-32;
number      min_relative_decrease = 1e-3;
number      min_lm_diagonal = 1e-6;
number      max_lm_diagonal = 1e32;
number      max_num_consecutive_invalid_steps = 5;
number      function_tolerance = 1e-6;
number      gradient_tolerance = 1e-10;
number      parameter_tolerance = 1e-8;
number      linear_solver_type = DENSE_QR;
number      preconditioner_type = JACOBI;
number      visibility_clustering_type = CANONICAL_VIEWS;
number      dense_linear_algebra_library_type = EIGEN;
number      sparse_linear_algebra_library_type = NO_SPARSE;
number      num_linear_solver_threads = 1;
boolean      use_explicit_schur_complement = false;
boolean      use_postordering = false;
boolean      dynamic_sparsity = false;
number      min_linear_solver_iterations = 0;
number      max_linear_solver_iterations = 500;
number      eta = 1e-1;
boolean      jacobi_scaling = true;
boolean      use_inner_iterations = false;
number      inner_iteration_tolerance = 1e-3;
number      logging_type = PER_MINIMIZER_ITERATION;
boolean      minimizer_progress_to_stdout = false;
string      trust_region_problem_dump_directory = "/tmp";
number      trust_region_problem_dump_format_type = TEXTFILE;
boolean      check_gradients = false;
number      gradient_check_relative_precision = 1e-8;
number      gradient_check_numeric_derivative_relative_step_size = 1e-6;
boolean      update_state_every_iteration = false;
*/


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
