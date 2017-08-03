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
// ceres.Solver$Options#minimizer_type
Gura_DeclareProperty_RW(Solver_Options, minimizer_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, minimizer_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.minimizer_type);
}

Gura_ImplementPropertySetter(Solver_Options, minimizer_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.minimizer_type = static_cast<ceres::MinimizerType>(value.GetInt());
	return Value(options.minimizer_type);
}

// ceres.Solver$Options#line_search_direction_type
Gura_DeclareProperty_RW(Solver_Options, line_search_direction_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, line_search_direction_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.line_search_direction_type);
}

Gura_ImplementPropertySetter(Solver_Options, line_search_direction_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.line_search_direction_type = static_cast<ceres::LineSearchDirectionType>(value.GetInt());
	return Value(options.line_search_direction_type);
}

// ceres.Solver$Options#line_search_type
Gura_DeclareProperty_RW(Solver_Options, line_search_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, line_search_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.line_search_type);
}

Gura_ImplementPropertySetter(Solver_Options, line_search_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.line_search_type = static_cast<ceres::LineSearchType>(value.GetInt());
	return Value(options.line_search_type);
}

// ceres.Solver$Options#nonlinear_conjugate_gradient_type
Gura_DeclareProperty_RW(Solver_Options, nonlinear_conjugate_gradient_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, nonlinear_conjugate_gradient_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.nonlinear_conjugate_gradient_type);
}

Gura_ImplementPropertySetter(Solver_Options, nonlinear_conjugate_gradient_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.nonlinear_conjugate_gradient_type = static_cast<ceres::NonlinearConjugateGradientType>(value.GetInt());
	return Value(options.nonlinear_conjugate_gradient_type);
}

// ceres.Solver$Options#max_lbfgs_rank
Gura_DeclareProperty_RW(Solver_Options, max_lbfgs_rank)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_lbfgs_rank)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_lbfgs_rank);
}

Gura_ImplementPropertySetter(Solver_Options, max_lbfgs_rank)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_lbfgs_rank = value.GetInt();
	return Value(options.max_lbfgs_rank);
}

// ceres.Solver$Options#use_approximate_eigenvalue_bfgs_scaling
Gura_DeclareProperty_RW(Solver_Options, use_approximate_eigenvalue_bfgs_scaling)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, use_approximate_eigenvalue_bfgs_scaling)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.use_approximate_eigenvalue_bfgs_scaling);
}

Gura_ImplementPropertySetter(Solver_Options, use_approximate_eigenvalue_bfgs_scaling)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.use_approximate_eigenvalue_bfgs_scaling = value.GetBoolean();
	return Value(options.use_approximate_eigenvalue_bfgs_scaling);
}

// ceres.Solver$Options#line_search_interpolation_type
Gura_DeclareProperty_RW(Solver_Options, line_search_interpolation_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, line_search_interpolation_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.line_search_interpolation_type);
}

Gura_ImplementPropertySetter(Solver_Options, line_search_interpolation_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.line_search_interpolation_type = static_cast<ceres::LineSearchInterpolationType>(value.GetInt());
	return Value(options.line_search_interpolation_type);
}

// ceres.Solver$Options#min_line_search_step_size
Gura_DeclareProperty_RW(Solver_Options, min_line_search_step_size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, min_line_search_step_size)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.min_line_search_step_size);
}

Gura_ImplementPropertySetter(Solver_Options, min_line_search_step_size)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.min_line_search_step_size = value.GetDouble();
	return Value(options.min_line_search_step_size);
}

// ceres.Solver$Options#line_search_sufficient_function_decrease
Gura_DeclareProperty_RW(Solver_Options, line_search_sufficient_function_decrease)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, line_search_sufficient_function_decrease)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.line_search_sufficient_function_decrease);
}

Gura_ImplementPropertySetter(Solver_Options, line_search_sufficient_function_decrease)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.line_search_sufficient_function_decrease = value.GetDouble();
	return Value(options.line_search_sufficient_function_decrease);
}

// ceres.Solver$Options#max_line_search_step_contraction
Gura_DeclareProperty_RW(Solver_Options, max_line_search_step_contraction)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_line_search_step_contraction)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_line_search_step_contraction);
}

Gura_ImplementPropertySetter(Solver_Options, max_line_search_step_contraction)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_line_search_step_contraction = value.GetDouble();
	return Value(options.max_line_search_step_contraction);
}

// ceres.Solver$Options#min_line_search_step_contraction
Gura_DeclareProperty_RW(Solver_Options, min_line_search_step_contraction)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, min_line_search_step_contraction)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.min_line_search_step_contraction);
}

Gura_ImplementPropertySetter(Solver_Options, min_line_search_step_contraction)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.min_line_search_step_contraction = value.GetDouble();
	return Value(options.min_line_search_step_contraction);
}

// ceres.Solver$Options#max_num_line_search_step_size_iterations
Gura_DeclareProperty_RW(Solver_Options, max_num_line_search_step_size_iterations)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_num_line_search_step_size_iterations)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_num_line_search_step_size_iterations);
}

Gura_ImplementPropertySetter(Solver_Options, max_num_line_search_step_size_iterations)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_num_line_search_step_size_iterations = value.GetInt();
	return Value(options.max_num_line_search_step_size_iterations);
}

// ceres.Solver$Options#max_num_line_search_direction_restarts
Gura_DeclareProperty_RW(Solver_Options, max_num_line_search_direction_restarts)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_num_line_search_direction_restarts)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_num_line_search_direction_restarts);
}

Gura_ImplementPropertySetter(Solver_Options, max_num_line_search_direction_restarts)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_num_line_search_direction_restarts = value.GetInt();
	return Value(options.max_num_line_search_direction_restarts);
}

// ceres.Solver$Options#line_search_sufficient_curvature_decrease
Gura_DeclareProperty_RW(Solver_Options, line_search_sufficient_curvature_decrease)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, line_search_sufficient_curvature_decrease)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.line_search_sufficient_curvature_decrease);
}

Gura_ImplementPropertySetter(Solver_Options, line_search_sufficient_curvature_decrease)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.line_search_sufficient_curvature_decrease = value.GetDouble();
	return Value(options.line_search_sufficient_curvature_decrease);
}

// ceres.Solver$Options#max_line_search_step_expansion
Gura_DeclareProperty_RW(Solver_Options, max_line_search_step_expansion)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_line_search_step_expansion)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_line_search_step_expansion);
}

Gura_ImplementPropertySetter(Solver_Options, max_line_search_step_expansion)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_line_search_step_expansion = value.GetDouble();
	return Value(options.max_line_search_step_expansion);
}

// ceres.Solver$Options#trust_region_strategy_type
Gura_DeclareProperty_RW(Solver_Options, trust_region_strategy_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, trust_region_strategy_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.trust_region_strategy_type);
}

Gura_ImplementPropertySetter(Solver_Options, trust_region_strategy_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.trust_region_strategy_type = static_cast<ceres::TrustRegionStrategyType>(value.GetInt());
	return Value(options.trust_region_strategy_type);
}

// ceres.Solver$Options#dogleg_type
Gura_DeclareProperty_RW(Solver_Options, dogleg_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, dogleg_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.dogleg_type);
}

Gura_ImplementPropertySetter(Solver_Options, dogleg_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.dogleg_type = static_cast<ceres::DoglegType>(value.GetInt());
	return Value(options.dogleg_type);
}

// ceres.Solver$Options#use_nonmonotonic_steps
Gura_DeclareProperty_RW(Solver_Options, use_nonmonotonic_steps)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, use_nonmonotonic_steps)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.use_nonmonotonic_steps);
}

Gura_ImplementPropertySetter(Solver_Options, use_nonmonotonic_steps)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.use_nonmonotonic_steps = value.GetBoolean();
	return Value(options.use_nonmonotonic_steps);
}

// ceres.Solver$Options#max_consecutive_nonmonotonic_steps
Gura_DeclareProperty_RW(Solver_Options, max_consecutive_nonmonotonic_steps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_consecutive_nonmonotonic_steps)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_consecutive_nonmonotonic_steps);
}

Gura_ImplementPropertySetter(Solver_Options, max_consecutive_nonmonotonic_steps)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_consecutive_nonmonotonic_steps = value.GetInt();
	return Value(options.max_consecutive_nonmonotonic_steps);
}

// ceres.Solver$Options#max_num_iterations
Gura_DeclareProperty_RW(Solver_Options, max_num_iterations)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_num_iterations)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_num_iterations);
}

Gura_ImplementPropertySetter(Solver_Options, max_num_iterations)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_num_iterations = value.GetInt();
	return Value(options.max_num_iterations);
}

// ceres.Solver$Options#max_solver_time_in_seconds
Gura_DeclareProperty_RW(Solver_Options, max_solver_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_solver_time_in_seconds)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_solver_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Options, max_solver_time_in_seconds)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_solver_time_in_seconds = value.GetDouble();
	return Value(options.max_solver_time_in_seconds);
}

// ceres.Solver$Options#num_threads
Gura_DeclareProperty_RW(Solver_Options, num_threads)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, num_threads)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.num_threads);
}

Gura_ImplementPropertySetter(Solver_Options, num_threads)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.num_threads = value.GetInt();
	return Value(options.num_threads);
}

// ceres.Solver$Options#initial_trust_region_radius
Gura_DeclareProperty_RW(Solver_Options, initial_trust_region_radius)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, initial_trust_region_radius)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.initial_trust_region_radius);
}

Gura_ImplementPropertySetter(Solver_Options, initial_trust_region_radius)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.initial_trust_region_radius = value.GetDouble();
	return Value(options.initial_trust_region_radius);
}

// ceres.Solver$Options#max_trust_region_radius
Gura_DeclareProperty_RW(Solver_Options, max_trust_region_radius)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_trust_region_radius)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_trust_region_radius);
}

Gura_ImplementPropertySetter(Solver_Options, max_trust_region_radius)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_trust_region_radius = value.GetDouble();
	return Value(options.max_trust_region_radius);
}

// ceres.Solver$Options#min_trust_region_radius
Gura_DeclareProperty_RW(Solver_Options, min_trust_region_radius)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, min_trust_region_radius)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.min_trust_region_radius);
}

Gura_ImplementPropertySetter(Solver_Options, min_trust_region_radius)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.min_trust_region_radius = value.GetDouble();
	return Value(options.min_trust_region_radius);
}

// ceres.Solver$Options#min_relative_decrease
Gura_DeclareProperty_RW(Solver_Options, min_relative_decrease)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, min_relative_decrease)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.min_relative_decrease);
}

Gura_ImplementPropertySetter(Solver_Options, min_relative_decrease)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.min_relative_decrease = value.GetDouble();
	return Value(options.min_relative_decrease);
}

// ceres.Solver$Options#min_lm_diagonal
Gura_DeclareProperty_RW(Solver_Options, min_lm_diagonal)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, min_lm_diagonal)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.min_lm_diagonal);
}

Gura_ImplementPropertySetter(Solver_Options, min_lm_diagonal)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.min_lm_diagonal = value.GetDouble();
	return Value(options.min_lm_diagonal);
}

// ceres.Solver$Options#max_lm_diagonal
Gura_DeclareProperty_RW(Solver_Options, max_lm_diagonal)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_lm_diagonal)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_lm_diagonal);
}

Gura_ImplementPropertySetter(Solver_Options, max_lm_diagonal)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_lm_diagonal = value.GetDouble();
	return Value(options.max_lm_diagonal);
}

// ceres.Solver$Options#max_num_consecutive_invalid_steps
Gura_DeclareProperty_RW(Solver_Options, max_num_consecutive_invalid_steps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_num_consecutive_invalid_steps)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_num_consecutive_invalid_steps);
}

Gura_ImplementPropertySetter(Solver_Options, max_num_consecutive_invalid_steps)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_num_consecutive_invalid_steps = value.GetInt();
	return Value(options.max_num_consecutive_invalid_steps);
}

// ceres.Solver$Options#function_tolerance
Gura_DeclareProperty_RW(Solver_Options, function_tolerance)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, function_tolerance)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.function_tolerance);
}

Gura_ImplementPropertySetter(Solver_Options, function_tolerance)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.function_tolerance = value.GetDouble();
	return Value(options.function_tolerance);
}

// ceres.Solver$Options#gradient_tolerance
Gura_DeclareProperty_RW(Solver_Options, gradient_tolerance)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, gradient_tolerance)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.gradient_tolerance);
}

Gura_ImplementPropertySetter(Solver_Options, gradient_tolerance)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.gradient_tolerance = value.GetDouble();
	return Value(options.gradient_tolerance);
}

// ceres.Solver$Options#parameter_tolerance
Gura_DeclareProperty_RW(Solver_Options, parameter_tolerance)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, parameter_tolerance)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.parameter_tolerance);
}

Gura_ImplementPropertySetter(Solver_Options, parameter_tolerance)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.parameter_tolerance = value.GetDouble();
	return Value(options.parameter_tolerance);
}

// ceres.Solver$Options#linear_solver_type
Gura_DeclareProperty_RW(Solver_Options, linear_solver_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, linear_solver_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.linear_solver_type);
}

Gura_ImplementPropertySetter(Solver_Options, linear_solver_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.linear_solver_type = static_cast<ceres::LinearSolverType>(value.GetInt());
	return Value(options.linear_solver_type);
}

// ceres.Solver$Options#preconditioner_type
Gura_DeclareProperty_RW(Solver_Options, preconditioner_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, preconditioner_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.preconditioner_type);
}

Gura_ImplementPropertySetter(Solver_Options, preconditioner_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.preconditioner_type = static_cast<ceres::PreconditionerType>(value.GetInt());
	return Value(options.preconditioner_type);
}

// ceres.Solver$Options#visibility_clustering_type
Gura_DeclareProperty_RW(Solver_Options, visibility_clustering_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, visibility_clustering_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.visibility_clustering_type);
}

Gura_ImplementPropertySetter(Solver_Options, visibility_clustering_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.visibility_clustering_type = static_cast<ceres::VisibilityClusteringType>(value.GetInt());
	return Value(options.visibility_clustering_type);
}

// ceres.Solver$Options#dense_linear_algebra_library_type
Gura_DeclareProperty_RW(Solver_Options, dense_linear_algebra_library_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, dense_linear_algebra_library_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.dense_linear_algebra_library_type);
}

Gura_ImplementPropertySetter(Solver_Options, dense_linear_algebra_library_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.dense_linear_algebra_library_type = static_cast<ceres::DenseLinearAlgebraLibraryType>(value.GetInt());
	return Value(options.dense_linear_algebra_library_type);
}

// ceres.Solver$Options#sparse_linear_algebra_library_type
Gura_DeclareProperty_RW(Solver_Options, sparse_linear_algebra_library_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, sparse_linear_algebra_library_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.sparse_linear_algebra_library_type);
}

Gura_ImplementPropertySetter(Solver_Options, sparse_linear_algebra_library_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.sparse_linear_algebra_library_type = static_cast<ceres::SparseLinearAlgebraLibraryType>(value.GetInt());
	return Value(options.sparse_linear_algebra_library_type);
}

// ceres.Solver$Options#num_linear_solver_threads
Gura_DeclareProperty_RW(Solver_Options, num_linear_solver_threads)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, num_linear_solver_threads)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.num_linear_solver_threads);
}

Gura_ImplementPropertySetter(Solver_Options, num_linear_solver_threads)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.num_linear_solver_threads = value.GetInt();
	return Value(options.num_linear_solver_threads);
}

// ceres.Solver$Options#use_explicit_schur_complement
Gura_DeclareProperty_RW(Solver_Options, use_explicit_schur_complement)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, use_explicit_schur_complement)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.use_explicit_schur_complement);
}

Gura_ImplementPropertySetter(Solver_Options, use_explicit_schur_complement)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.use_explicit_schur_complement = value.GetBoolean();
	return Value(options.use_explicit_schur_complement);
}

// ceres.Solver$Options#use_postordering
Gura_DeclareProperty_RW(Solver_Options, use_postordering)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, use_postordering)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.use_postordering);
}

Gura_ImplementPropertySetter(Solver_Options, use_postordering)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.use_postordering = value.GetBoolean();
	return Value(options.use_postordering);
}

// ceres.Solver$Options#dynamic_sparsity
Gura_DeclareProperty_RW(Solver_Options, dynamic_sparsity)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, dynamic_sparsity)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.dynamic_sparsity);
}

Gura_ImplementPropertySetter(Solver_Options, dynamic_sparsity)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.dynamic_sparsity = value.GetBoolean();
	return Value(options.dynamic_sparsity);
}

// ceres.Solver$Options#min_linear_solver_iterations
Gura_DeclareProperty_RW(Solver_Options, min_linear_solver_iterations)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, min_linear_solver_iterations)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.min_linear_solver_iterations);
}

Gura_ImplementPropertySetter(Solver_Options, min_linear_solver_iterations)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.min_linear_solver_iterations = value.GetInt();
	return Value(options.min_linear_solver_iterations);
}

// ceres.Solver$Options#max_linear_solver_iterations
Gura_DeclareProperty_RW(Solver_Options, max_linear_solver_iterations)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, max_linear_solver_iterations)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.max_linear_solver_iterations);
}

Gura_ImplementPropertySetter(Solver_Options, max_linear_solver_iterations)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.max_linear_solver_iterations = value.GetInt();
	return Value(options.max_linear_solver_iterations);
}

// ceres.Solver$Options#eta
Gura_DeclareProperty_RW(Solver_Options, eta)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, eta)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.eta);
}

Gura_ImplementPropertySetter(Solver_Options, eta)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.eta = value.GetDouble();
	return Value(options.eta);
}

// ceres.Solver$Options#jacobi_scaling
Gura_DeclareProperty_RW(Solver_Options, jacobi_scaling)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, jacobi_scaling)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.jacobi_scaling);
}

Gura_ImplementPropertySetter(Solver_Options, jacobi_scaling)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.jacobi_scaling = value.GetBoolean();
	return Value(options.jacobi_scaling);
}

// ceres.Solver$Options#use_inner_iterations
Gura_DeclareProperty_RW(Solver_Options, use_inner_iterations)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, use_inner_iterations)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.use_inner_iterations);
}

Gura_ImplementPropertySetter(Solver_Options, use_inner_iterations)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.use_inner_iterations = value.GetBoolean();
	return Value(options.use_inner_iterations);
}

// ceres.Solver$Options#inner_iteration_tolerance
Gura_DeclareProperty_RW(Solver_Options, inner_iteration_tolerance)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, inner_iteration_tolerance)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.inner_iteration_tolerance);
}

Gura_ImplementPropertySetter(Solver_Options, inner_iteration_tolerance)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.inner_iteration_tolerance = value.GetDouble();
	return Value(options.inner_iteration_tolerance);
}

// ceres.Solver$Options#logging_type
Gura_DeclareProperty_RW(Solver_Options, logging_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, logging_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.logging_type);
}

Gura_ImplementPropertySetter(Solver_Options, logging_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.logging_type = static_cast<ceres::LoggingType>(value.GetInt());
	return Value(options.logging_type);
}

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

// ceres.Solver$Options#trust_region_problem_dump_directory
Gura_DeclareProperty_RW(Solver_Options, trust_region_problem_dump_directory)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, trust_region_problem_dump_directory)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.trust_region_problem_dump_directory.c_str());
}

Gura_ImplementPropertySetter(Solver_Options, trust_region_problem_dump_directory)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.trust_region_problem_dump_directory = value.GetString();
	return Value(options.trust_region_problem_dump_directory.c_str());
}

// ceres.Solver$Options#trust_region_problem_dump_format_type
Gura_DeclareProperty_RW(Solver_Options, trust_region_problem_dump_format_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, trust_region_problem_dump_format_type)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.trust_region_problem_dump_format_type);
}

Gura_ImplementPropertySetter(Solver_Options, trust_region_problem_dump_format_type)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.trust_region_problem_dump_format_type = static_cast<ceres::DumpFormatType>(value.GetInt());
	return Value(options.trust_region_problem_dump_format_type);
}

// ceres.Solver$Options#check_gradients
Gura_DeclareProperty_RW(Solver_Options, check_gradients)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, check_gradients)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.check_gradients);
}

Gura_ImplementPropertySetter(Solver_Options, check_gradients)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.check_gradients = value.GetBoolean();
	return Value(options.check_gradients);
}

// ceres.Solver$Options#gradient_check_relative_precision
Gura_DeclareProperty_RW(Solver_Options, gradient_check_relative_precision)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, gradient_check_relative_precision)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.gradient_check_relative_precision);
}

Gura_ImplementPropertySetter(Solver_Options, gradient_check_relative_precision)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.gradient_check_relative_precision = value.GetDouble();
	return Value(options.gradient_check_relative_precision);
}

// ceres.Solver$Options#gradient_check_numeric_derivative_relative_step_size
Gura_DeclareProperty_RW(Solver_Options, gradient_check_numeric_derivative_relative_step_size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, gradient_check_numeric_derivative_relative_step_size)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.gradient_check_numeric_derivative_relative_step_size);
}

Gura_ImplementPropertySetter(Solver_Options, gradient_check_numeric_derivative_relative_step_size)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.gradient_check_numeric_derivative_relative_step_size = value.GetDouble();
	return Value(options.gradient_check_numeric_derivative_relative_step_size);
}

// ceres.Solver$Options#update_state_every_iteration
Gura_DeclareProperty_RW(Solver_Options, update_state_every_iteration)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, update_state_every_iteration)
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.update_state_every_iteration);
}

Gura_ImplementPropertySetter(Solver_Options, update_state_every_iteration)
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options.update_state_every_iteration = value.GetBoolean();
	return Value(options.update_state_every_iteration);
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
	Gura_AssignProperty(Solver_Options, minimizer_type);
	Gura_AssignProperty(Solver_Options, line_search_direction_type);
	Gura_AssignProperty(Solver_Options, line_search_type);
	Gura_AssignProperty(Solver_Options, nonlinear_conjugate_gradient_type);
	Gura_AssignProperty(Solver_Options, max_lbfgs_rank);
	Gura_AssignProperty(Solver_Options, use_approximate_eigenvalue_bfgs_scaling);
	Gura_AssignProperty(Solver_Options, line_search_interpolation_type);
	Gura_AssignProperty(Solver_Options, min_line_search_step_size);
	Gura_AssignProperty(Solver_Options, line_search_sufficient_function_decrease);
	Gura_AssignProperty(Solver_Options, max_line_search_step_contraction);
	Gura_AssignProperty(Solver_Options, min_line_search_step_contraction);
	Gura_AssignProperty(Solver_Options, max_num_line_search_step_size_iterations);
	Gura_AssignProperty(Solver_Options, max_num_line_search_direction_restarts);
	Gura_AssignProperty(Solver_Options, line_search_sufficient_curvature_decrease);
	Gura_AssignProperty(Solver_Options, max_line_search_step_expansion);
	Gura_AssignProperty(Solver_Options, trust_region_strategy_type);
	Gura_AssignProperty(Solver_Options, dogleg_type);
	Gura_AssignProperty(Solver_Options, use_nonmonotonic_steps);
	Gura_AssignProperty(Solver_Options, max_consecutive_nonmonotonic_steps);
	Gura_AssignProperty(Solver_Options, max_num_iterations);
	Gura_AssignProperty(Solver_Options, max_solver_time_in_seconds);
	Gura_AssignProperty(Solver_Options, num_threads);
	Gura_AssignProperty(Solver_Options, initial_trust_region_radius);
	Gura_AssignProperty(Solver_Options, max_trust_region_radius);
	Gura_AssignProperty(Solver_Options, min_trust_region_radius);
	Gura_AssignProperty(Solver_Options, min_relative_decrease);
	Gura_AssignProperty(Solver_Options, min_lm_diagonal);
	Gura_AssignProperty(Solver_Options, max_lm_diagonal);
	Gura_AssignProperty(Solver_Options, max_num_consecutive_invalid_steps);
	Gura_AssignProperty(Solver_Options, function_tolerance);
	Gura_AssignProperty(Solver_Options, gradient_tolerance);
	Gura_AssignProperty(Solver_Options, parameter_tolerance);
	Gura_AssignProperty(Solver_Options, linear_solver_type);
	Gura_AssignProperty(Solver_Options, preconditioner_type);
	Gura_AssignProperty(Solver_Options, visibility_clustering_type);
	Gura_AssignProperty(Solver_Options, dense_linear_algebra_library_type);
	Gura_AssignProperty(Solver_Options, sparse_linear_algebra_library_type);
	Gura_AssignProperty(Solver_Options, num_linear_solver_threads);
	Gura_AssignProperty(Solver_Options, use_explicit_schur_complement);
	Gura_AssignProperty(Solver_Options, use_postordering);
	Gura_AssignProperty(Solver_Options, dynamic_sparsity);
	Gura_AssignProperty(Solver_Options, min_linear_solver_iterations);
	Gura_AssignProperty(Solver_Options, max_linear_solver_iterations);
	Gura_AssignProperty(Solver_Options, eta);
	Gura_AssignProperty(Solver_Options, jacobi_scaling);
	Gura_AssignProperty(Solver_Options, use_inner_iterations);
	Gura_AssignProperty(Solver_Options, inner_iteration_tolerance);
	Gura_AssignProperty(Solver_Options, logging_type);
	Gura_AssignProperty(Solver_Options, minimizer_progress_to_stdout);
	Gura_AssignProperty(Solver_Options, trust_region_problem_dump_directory);
	Gura_AssignProperty(Solver_Options, trust_region_problem_dump_format_type);
	Gura_AssignProperty(Solver_Options, check_gradients);
	Gura_AssignProperty(Solver_Options, gradient_check_relative_precision);
	Gura_AssignProperty(Solver_Options, gradient_check_numeric_derivative_relative_step_size);
	Gura_AssignProperty(Solver_Options, update_state_every_iteration);
	// Assignment of function
	Gura_AssignFunction(Solver_Options);
}

Gura_EndModuleScope(ceres)
