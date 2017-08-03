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
// ceres.Solver$Summary#minimizer_type
Gura_DeclareProperty_RW(Solver_Summary, minimizer_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, minimizer_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.minimizer_type);
}

Gura_ImplementPropertySetter(Solver_Summary, minimizer_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.minimizer_type = static_cast<ceres::MinimizerType>(value.GetInt());
	return Value(summary.minimizer_type);
}

// ceres.Solver$Summary#termination_type
Gura_DeclareProperty_RW(Solver_Summary, termination_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, termination_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.termination_type);
}

Gura_ImplementPropertySetter(Solver_Summary, termination_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.termination_type = static_cast<ceres::TerminationType>(value.GetInt());
	return Value(summary.termination_type);
}

// ceres.Solver$Summary#message
Gura_DeclareProperty_RW(Solver_Summary, message)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, message)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.message.c_str());
}

Gura_ImplementPropertySetter(Solver_Summary, message)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.message = value.GetString();
	return Value(summary.message.c_str());
}

// ceres.Solver$Summary#initial_cost
Gura_DeclareProperty_RW(Solver_Summary, initial_cost)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, initial_cost)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.initial_cost);
}

Gura_ImplementPropertySetter(Solver_Summary, initial_cost)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.initial_cost = value.GetDouble();
	return Value(summary.initial_cost);
}

// ceres.Solver$Summary#final_cost
Gura_DeclareProperty_RW(Solver_Summary, final_cost)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, final_cost)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.final_cost);
}

Gura_ImplementPropertySetter(Solver_Summary, final_cost)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.final_cost = value.GetDouble();
	return Value(summary.final_cost);
}

// ceres.Solver$Summary#fixed_cost
Gura_DeclareProperty_RW(Solver_Summary, fixed_cost)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, fixed_cost)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.fixed_cost);
}

Gura_ImplementPropertySetter(Solver_Summary, fixed_cost)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.fixed_cost = value.GetDouble();
	return Value(summary.fixed_cost);
}

// ceres.Solver$Summary#num_successful_steps
Gura_DeclareProperty_RW(Solver_Summary, num_successful_steps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_successful_steps)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_successful_steps);
}

Gura_ImplementPropertySetter(Solver_Summary, num_successful_steps)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_successful_steps = value.GetInt();
	return Value(summary.num_successful_steps);
}

// ceres.Solver$Summary#num_unsuccessful_steps
Gura_DeclareProperty_RW(Solver_Summary, num_unsuccessful_steps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_unsuccessful_steps)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_unsuccessful_steps);
}

Gura_ImplementPropertySetter(Solver_Summary, num_unsuccessful_steps)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_unsuccessful_steps = value.GetInt();
	return Value(summary.num_unsuccessful_steps);
}

// ceres.Solver$Summary#num_inner_iteration_steps
Gura_DeclareProperty_RW(Solver_Summary, num_inner_iteration_steps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_inner_iteration_steps)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_inner_iteration_steps);
}

Gura_ImplementPropertySetter(Solver_Summary, num_inner_iteration_steps)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_inner_iteration_steps = value.GetInt();
	return Value(summary.num_inner_iteration_steps);
}

// ceres.Solver$Summary#num_line_search_steps
Gura_DeclareProperty_RW(Solver_Summary, num_line_search_steps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_line_search_steps)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_line_search_steps);
}

Gura_ImplementPropertySetter(Solver_Summary, num_line_search_steps)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_line_search_steps = value.GetInt();
	return Value(summary.num_line_search_steps);
}

// ceres.Solver$Summary#preprocessor_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, preprocessor_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, preprocessor_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.preprocessor_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, preprocessor_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.preprocessor_time_in_seconds = value.GetDouble();
	return Value(summary.preprocessor_time_in_seconds);
}

// ceres.Solver$Summary#minimizer_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, minimizer_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, minimizer_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.minimizer_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, minimizer_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.minimizer_time_in_seconds = value.GetDouble();
	return Value(summary.minimizer_time_in_seconds);
}

// ceres.Solver$Summary#postprocessor_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, postprocessor_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, postprocessor_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.postprocessor_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, postprocessor_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.postprocessor_time_in_seconds = value.GetDouble();
	return Value(summary.postprocessor_time_in_seconds);
}

// ceres.Solver$Summary#total_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, total_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, total_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.total_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, total_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.total_time_in_seconds = value.GetDouble();
	return Value(summary.total_time_in_seconds);
}

// ceres.Solver$Summary#linear_solver_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, linear_solver_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, linear_solver_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.linear_solver_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, linear_solver_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.linear_solver_time_in_seconds = value.GetDouble();
	return Value(summary.linear_solver_time_in_seconds);
}

// ceres.Solver$Summary#residual_evaluation_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, residual_evaluation_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, residual_evaluation_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.residual_evaluation_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, residual_evaluation_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.residual_evaluation_time_in_seconds = value.GetDouble();
	return Value(summary.residual_evaluation_time_in_seconds);
}

// ceres.Solver$Summary#jacobian_evaluation_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, jacobian_evaluation_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, jacobian_evaluation_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.jacobian_evaluation_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, jacobian_evaluation_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.jacobian_evaluation_time_in_seconds = value.GetDouble();
	return Value(summary.jacobian_evaluation_time_in_seconds);
}

// ceres.Solver$Summary#inner_iteration_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, inner_iteration_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, inner_iteration_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.inner_iteration_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, inner_iteration_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.inner_iteration_time_in_seconds = value.GetDouble();
	return Value(summary.inner_iteration_time_in_seconds);
}

// ceres.Solver$Summary#line_search_cost_evaluation_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, line_search_cost_evaluation_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, line_search_cost_evaluation_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.line_search_cost_evaluation_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, line_search_cost_evaluation_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.line_search_cost_evaluation_time_in_seconds = value.GetDouble();
	return Value(summary.line_search_cost_evaluation_time_in_seconds);
}

// ceres.Solver$Summary#line_search_gradient_evaluation_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, line_search_gradient_evaluation_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, line_search_gradient_evaluation_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.line_search_gradient_evaluation_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, line_search_gradient_evaluation_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.line_search_gradient_evaluation_time_in_seconds = value.GetDouble();
	return Value(summary.line_search_gradient_evaluation_time_in_seconds);
}

// ceres.Solver$Summary#line_search_polynomial_minimization_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, line_search_polynomial_minimization_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, line_search_polynomial_minimization_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.line_search_polynomial_minimization_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, line_search_polynomial_minimization_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.line_search_polynomial_minimization_time_in_seconds = value.GetDouble();
	return Value(summary.line_search_polynomial_minimization_time_in_seconds);
}

// ceres.Solver$Summary#line_search_total_time_in_seconds
Gura_DeclareProperty_RW(Solver_Summary, line_search_total_time_in_seconds)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, line_search_total_time_in_seconds)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.line_search_total_time_in_seconds);
}

Gura_ImplementPropertySetter(Solver_Summary, line_search_total_time_in_seconds)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.line_search_total_time_in_seconds = value.GetDouble();
	return Value(summary.line_search_total_time_in_seconds);
}

// ceres.Solver$Summary#num_parameter_blocks
Gura_DeclareProperty_RW(Solver_Summary, num_parameter_blocks)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_parameter_blocks)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_parameter_blocks);
}

Gura_ImplementPropertySetter(Solver_Summary, num_parameter_blocks)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_parameter_blocks = value.GetInt();
	return Value(summary.num_parameter_blocks);
}

// ceres.Solver$Summary#num_parameters
Gura_DeclareProperty_RW(Solver_Summary, num_parameters)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_parameters)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_parameters);
}

Gura_ImplementPropertySetter(Solver_Summary, num_parameters)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_parameters = value.GetInt();
	return Value(summary.num_parameters);
}

// ceres.Solver$Summary#num_effective_parameters
Gura_DeclareProperty_RW(Solver_Summary, num_effective_parameters)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_effective_parameters)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_effective_parameters);
}

Gura_ImplementPropertySetter(Solver_Summary, num_effective_parameters)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_effective_parameters = value.GetInt();
	return Value(summary.num_effective_parameters);
}

// ceres.Solver$Summary#num_residual_blocks
Gura_DeclareProperty_RW(Solver_Summary, num_residual_blocks)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_residual_blocks)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_residual_blocks);
}

Gura_ImplementPropertySetter(Solver_Summary, num_residual_blocks)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_residual_blocks = value.GetInt();
	return Value(summary.num_residual_blocks);
}

// ceres.Solver$Summary#num_residuals
Gura_DeclareProperty_RW(Solver_Summary, num_residuals)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_residuals)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_residuals);
}

Gura_ImplementPropertySetter(Solver_Summary, num_residuals)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_residuals = value.GetInt();
	return Value(summary.num_residuals);
}

// ceres.Solver$Summary#num_parameter_blocks_reduced
Gura_DeclareProperty_RW(Solver_Summary, num_parameter_blocks_reduced)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_parameter_blocks_reduced)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_parameter_blocks_reduced);
}

Gura_ImplementPropertySetter(Solver_Summary, num_parameter_blocks_reduced)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_parameter_blocks_reduced = value.GetInt();
	return Value(summary.num_parameter_blocks_reduced);
}

// ceres.Solver$Summary#num_parameters_reduced
Gura_DeclareProperty_RW(Solver_Summary, num_parameters_reduced)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_parameters_reduced)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_parameters_reduced);
}

Gura_ImplementPropertySetter(Solver_Summary, num_parameters_reduced)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_parameters_reduced = value.GetInt();
	return Value(summary.num_parameters_reduced);
}

// ceres.Solver$Summary#num_effective_parameters_reduced
Gura_DeclareProperty_RW(Solver_Summary, num_effective_parameters_reduced)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_effective_parameters_reduced)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_effective_parameters_reduced);
}

Gura_ImplementPropertySetter(Solver_Summary, num_effective_parameters_reduced)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_effective_parameters_reduced = value.GetInt();
	return Value(summary.num_effective_parameters_reduced);
}

// ceres.Solver$Summary#num_residual_blocks_reduced
Gura_DeclareProperty_RW(Solver_Summary, num_residual_blocks_reduced)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_residual_blocks_reduced)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_residual_blocks_reduced);
}

Gura_ImplementPropertySetter(Solver_Summary, num_residual_blocks_reduced)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_residual_blocks_reduced = value.GetInt();
	return Value(summary.num_residual_blocks_reduced);
}

// ceres.Solver$Summary#num_residuals_reduced
Gura_DeclareProperty_RW(Solver_Summary, num_residuals_reduced)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_residuals_reduced)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_residuals_reduced);
}

Gura_ImplementPropertySetter(Solver_Summary, num_residuals_reduced)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_residuals_reduced = value.GetInt();
	return Value(summary.num_residuals_reduced);
}

// ceres.Solver$Summary#is_constrained
Gura_DeclareProperty_RW(Solver_Summary, is_constrained)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, is_constrained)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.is_constrained);
}

Gura_ImplementPropertySetter(Solver_Summary, is_constrained)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.is_constrained = value.GetBoolean();
	return Value(summary.is_constrained);
}

// ceres.Solver$Summary#num_threads_given
Gura_DeclareProperty_RW(Solver_Summary, num_threads_given)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_threads_given)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_threads_given);
}

Gura_ImplementPropertySetter(Solver_Summary, num_threads_given)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_threads_given = value.GetInt();
	return Value(summary.num_threads_given);
}

// ceres.Solver$Summary#num_threads_used
Gura_DeclareProperty_RW(Solver_Summary, num_threads_used)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_threads_used)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_threads_used);
}

Gura_ImplementPropertySetter(Solver_Summary, num_threads_used)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_threads_used = value.GetInt();
	return Value(summary.num_threads_used);
}

// ceres.Solver$Summary#num_linear_solver_threads_given
Gura_DeclareProperty_RW(Solver_Summary, num_linear_solver_threads_given)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_linear_solver_threads_given)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_linear_solver_threads_given);
}

Gura_ImplementPropertySetter(Solver_Summary, num_linear_solver_threads_given)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_linear_solver_threads_given = value.GetInt();
	return Value(summary.num_linear_solver_threads_given);
}

// ceres.Solver$Summary#num_linear_solver_threads_used
Gura_DeclareProperty_RW(Solver_Summary, num_linear_solver_threads_used)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, num_linear_solver_threads_used)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.num_linear_solver_threads_used);
}

Gura_ImplementPropertySetter(Solver_Summary, num_linear_solver_threads_used)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.num_linear_solver_threads_used = value.GetInt();
	return Value(summary.num_linear_solver_threads_used);
}

// ceres.Solver$Summary#linear_solver_type_given
Gura_DeclareProperty_RW(Solver_Summary, linear_solver_type_given)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, linear_solver_type_given)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.linear_solver_type_given);
}

Gura_ImplementPropertySetter(Solver_Summary, linear_solver_type_given)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.linear_solver_type_given = static_cast<ceres::LinearSolverType>(value.GetInt());
	return Value(summary.linear_solver_type_given);
}

// ceres.Solver$Summary#linear_solver_type_used
Gura_DeclareProperty_RW(Solver_Summary, linear_solver_type_used)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, linear_solver_type_used)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.linear_solver_type_used);
}

Gura_ImplementPropertySetter(Solver_Summary, linear_solver_type_used)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.linear_solver_type_used = static_cast<ceres::LinearSolverType>(value.GetInt());
	return Value(summary.linear_solver_type_used);
}

// ceres.Solver$Summary#inner_iterations_given
Gura_DeclareProperty_RW(Solver_Summary, inner_iterations_given)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, inner_iterations_given)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.inner_iterations_given);
}

Gura_ImplementPropertySetter(Solver_Summary, inner_iterations_given)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.inner_iterations_given = value.GetBoolean();
	return Value(summary.inner_iterations_given);
}

// ceres.Solver$Summary#inner_iterations_used
Gura_DeclareProperty_RW(Solver_Summary, inner_iterations_used)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, inner_iterations_used)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.inner_iterations_used);
}

Gura_ImplementPropertySetter(Solver_Summary, inner_iterations_used)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.inner_iterations_used = value.GetBoolean();
	return Value(summary.inner_iterations_used);
}

// ceres.Solver$Summary#preconditioner_type_given
Gura_DeclareProperty_RW(Solver_Summary, preconditioner_type_given)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, preconditioner_type_given)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.preconditioner_type_given);
}

Gura_ImplementPropertySetter(Solver_Summary, preconditioner_type_given)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.preconditioner_type_given = static_cast<ceres::PreconditionerType>(value.GetInt());
	return Value(summary.preconditioner_type_given);
}

// ceres.Solver$Summary#preconditioner_type_used
Gura_DeclareProperty_RW(Solver_Summary, preconditioner_type_used)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, preconditioner_type_used)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.preconditioner_type_used);
}

Gura_ImplementPropertySetter(Solver_Summary, preconditioner_type_used)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.preconditioner_type_used = static_cast<ceres::PreconditionerType>(value.GetInt());
	return Value(summary.preconditioner_type_used);
}

// ceres.Solver$Summary#visibility_clustering_type
Gura_DeclareProperty_RW(Solver_Summary, visibility_clustering_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, visibility_clustering_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.visibility_clustering_type);
}

Gura_ImplementPropertySetter(Solver_Summary, visibility_clustering_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.visibility_clustering_type = static_cast<ceres::VisibilityClusteringType>(value.GetInt());
	return Value(summary.visibility_clustering_type);
}

// ceres.Solver$Summary#trust_region_strategy_type
Gura_DeclareProperty_RW(Solver_Summary, trust_region_strategy_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, trust_region_strategy_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.trust_region_strategy_type);
}

Gura_ImplementPropertySetter(Solver_Summary, trust_region_strategy_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.trust_region_strategy_type = static_cast<ceres::TrustRegionStrategyType>(value.GetInt());
	return Value(summary.trust_region_strategy_type);
}

// ceres.Solver$Summary#dogleg_type
Gura_DeclareProperty_RW(Solver_Summary, dogleg_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, dogleg_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.dogleg_type);
}

Gura_ImplementPropertySetter(Solver_Summary, dogleg_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.dogleg_type = static_cast<ceres::DoglegType>(value.GetInt());
	return Value(summary.dogleg_type);
}

// ceres.Solver$Summary#dense_linear_algebra_library_type
Gura_DeclareProperty_RW(Solver_Summary, dense_linear_algebra_library_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, dense_linear_algebra_library_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.dense_linear_algebra_library_type);
}

Gura_ImplementPropertySetter(Solver_Summary, dense_linear_algebra_library_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.dense_linear_algebra_library_type = static_cast<ceres::DenseLinearAlgebraLibraryType>(value.GetInt());
	return Value(summary.dense_linear_algebra_library_type);
}

// ceres.Solver$Summary#sparse_linear_algebra_library_type
Gura_DeclareProperty_RW(Solver_Summary, sparse_linear_algebra_library_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, sparse_linear_algebra_library_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.sparse_linear_algebra_library_type);
}

Gura_ImplementPropertySetter(Solver_Summary, sparse_linear_algebra_library_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.sparse_linear_algebra_library_type = static_cast<ceres::SparseLinearAlgebraLibraryType>(value.GetInt());
	return Value(summary.sparse_linear_algebra_library_type);
}

// ceres.Solver$Summary#line_search_direction_type
Gura_DeclareProperty_RW(Solver_Summary, line_search_direction_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, line_search_direction_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.line_search_direction_type);
}

Gura_ImplementPropertySetter(Solver_Summary, line_search_direction_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.line_search_direction_type = static_cast<ceres::LineSearchDirectionType>(value.GetInt());
	return Value(summary.line_search_direction_type);
}

// ceres.Solver$Summary#line_search_type
Gura_DeclareProperty_RW(Solver_Summary, line_search_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, line_search_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.line_search_type);
}

Gura_ImplementPropertySetter(Solver_Summary, line_search_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.line_search_type = static_cast<ceres::LineSearchType>(value.GetInt());
	return Value(summary.line_search_type);
}

// ceres.Solver$Summary#line_search_interpolation_type
Gura_DeclareProperty_RW(Solver_Summary, line_search_interpolation_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, line_search_interpolation_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.line_search_interpolation_type);
}

Gura_ImplementPropertySetter(Solver_Summary, line_search_interpolation_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.line_search_interpolation_type = static_cast<ceres::LineSearchInterpolationType>(value.GetInt());
	return Value(summary.line_search_interpolation_type);
}

// ceres.Solver$Summary#nonlinear_conjugate_gradient_type
Gura_DeclareProperty_RW(Solver_Summary, nonlinear_conjugate_gradient_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, nonlinear_conjugate_gradient_type)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.nonlinear_conjugate_gradient_type);
}

Gura_ImplementPropertySetter(Solver_Summary, nonlinear_conjugate_gradient_type)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.nonlinear_conjugate_gradient_type = static_cast<ceres::NonlinearConjugateGradientType>(value.GetInt());
	return Value(summary.nonlinear_conjugate_gradient_type);
}

// ceres.Solver$Summary#max_lbfgs_rank
Gura_DeclareProperty_RW(Solver_Summary, max_lbfgs_rank)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Solver_Summary, max_lbfgs_rank)
{
	const ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	return Value(summary.max_lbfgs_rank);
}

Gura_ImplementPropertySetter(Solver_Summary, max_lbfgs_rank)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObject(valueThis)->GetSummary();
	summary.max_lbfgs_rank = value.GetInt();
	return Value(summary.max_lbfgs_rank);
}

/*
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
	Gura_AssignProperty(Solver_Summary, termination_type);
	Gura_AssignProperty(Solver_Summary, message);
	Gura_AssignProperty(Solver_Summary, initial_cost);
	Gura_AssignProperty(Solver_Summary, final_cost);
	Gura_AssignProperty(Solver_Summary, fixed_cost);
	Gura_AssignProperty(Solver_Summary, num_successful_steps);
	Gura_AssignProperty(Solver_Summary, num_unsuccessful_steps);
	Gura_AssignProperty(Solver_Summary, num_inner_iteration_steps);
	Gura_AssignProperty(Solver_Summary, num_line_search_steps);
	Gura_AssignProperty(Solver_Summary, preprocessor_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, minimizer_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, postprocessor_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, total_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, linear_solver_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, residual_evaluation_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, jacobian_evaluation_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, inner_iteration_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, line_search_cost_evaluation_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, line_search_gradient_evaluation_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, line_search_polynomial_minimization_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, line_search_total_time_in_seconds);
	Gura_AssignProperty(Solver_Summary, num_parameter_blocks);
	Gura_AssignProperty(Solver_Summary, num_parameters);
	Gura_AssignProperty(Solver_Summary, num_effective_parameters);
	Gura_AssignProperty(Solver_Summary, num_residual_blocks);
	Gura_AssignProperty(Solver_Summary, num_residuals);
	Gura_AssignProperty(Solver_Summary, num_parameter_blocks_reduced);
	Gura_AssignProperty(Solver_Summary, num_parameters_reduced);
	Gura_AssignProperty(Solver_Summary, num_effective_parameters_reduced);
	Gura_AssignProperty(Solver_Summary, num_residual_blocks_reduced);
	Gura_AssignProperty(Solver_Summary, num_residuals_reduced);
	Gura_AssignProperty(Solver_Summary, is_constrained);
	Gura_AssignProperty(Solver_Summary, num_threads_given);
	Gura_AssignProperty(Solver_Summary, num_threads_used);
	Gura_AssignProperty(Solver_Summary, num_linear_solver_threads_given);
	Gura_AssignProperty(Solver_Summary, num_linear_solver_threads_used);
	Gura_AssignProperty(Solver_Summary, linear_solver_type_given);
	Gura_AssignProperty(Solver_Summary, linear_solver_type_used);
	Gura_AssignProperty(Solver_Summary, inner_iterations_given);
	Gura_AssignProperty(Solver_Summary, inner_iterations_used);
	Gura_AssignProperty(Solver_Summary, preconditioner_type_given);
	Gura_AssignProperty(Solver_Summary, preconditioner_type_used);
	Gura_AssignProperty(Solver_Summary, visibility_clustering_type);
	Gura_AssignProperty(Solver_Summary, trust_region_strategy_type);
	Gura_AssignProperty(Solver_Summary, dogleg_type);
	Gura_AssignProperty(Solver_Summary, dense_linear_algebra_library_type);
	Gura_AssignProperty(Solver_Summary, sparse_linear_algebra_library_type);
	Gura_AssignProperty(Solver_Summary, line_search_direction_type);
	Gura_AssignProperty(Solver_Summary, line_search_type);
	Gura_AssignProperty(Solver_Summary, line_search_interpolation_type);
	Gura_AssignProperty(Solver_Summary, nonlinear_conjugate_gradient_type);
	Gura_AssignProperty(Solver_Summary, max_lbfgs_rank);
	// Assignment of function
	Gura_AssignFunction(Solver_Summary);
	// Assignment of method
	Gura_AssignMethod(Solver_Summary, BriefReport);
	Gura_AssignMethod(Solver_Summary, FullReport);
}

Gura_EndModuleScope(ceres)
