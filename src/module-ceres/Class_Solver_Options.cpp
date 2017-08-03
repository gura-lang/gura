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
number      minimizer_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      line_search_direction_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      line_search_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      nonlinear_conjugate_gradient_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_lbfgs_rank
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      use_approximate_eigenvalue_bfgs_scaling
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      line_search_interpolation_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      min_line_search_step_size
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      line_search_sufficient_function_decrease
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_line_search_step_contraction
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      min_line_search_step_contraction
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_num_line_search_step_size_iterations
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_num_line_search_direction_restarts
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      line_search_sufficient_curvature_decrease
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_line_search_step_expansion
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      trust_region_strategy_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      dogleg_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      use_nonmonotonic_steps
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_consecutive_nonmonotonic_steps
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_num_iterations
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_solver_time_in_seconds
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      num_threads
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      initial_trust_region_radius
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_trust_region_radius
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      min_trust_region_radius
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      min_relative_decrease
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      min_lm_diagonal
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_lm_diagonal
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_num_consecutive_invalid_steps
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      function_tolerance
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      gradient_tolerance
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      parameter_tolerance
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      linear_solver_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      preconditioner_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      visibility_clustering_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      dense_linear_algebra_library_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      sparse_linear_algebra_library_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      num_linear_solver_threads
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      use_explicit_schur_complement
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      use_postordering
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      dynamic_sparsity
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      min_linear_solver_iterations
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      max_linear_solver_iterations
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      eta
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      jacobi_scaling
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      use_inner_iterations
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      inner_iteration_tolerance
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      logging_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      minimizer_progress_to_stdout
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
string      trust_region_problem_dump_directory
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      trust_region_problem_dump_format_type
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      check_gradients
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      gradient_check_relative_precision
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
number      gradient_check_numeric_derivative_relative_step_size
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
boolean      update_state_every_iteration
// ceres.Solver$Options#
Gura_DeclareProperty_RW(Solver_Options, )
{
	SetPropAttr(VTYPE_);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Options, )
{
	const ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	return Value(options.);
}

Gura_ImplementPropertySetter(Solver_Options, )
{
	ceres::Solver::Options &options = Object_Solver_Options::GetObject(valueThis)->GetOptions();
	options. = value.Get();
	return Value(options.);
}
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
/*
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
*/
	Gura_AssignProperty(Solver_Options, minimizer_progress_to_stdout);
	// Assignment of function
	Gura_AssignFunction(Solver_Options);
}

Gura_EndModuleScope(ceres)
