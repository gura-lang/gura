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

std::string message;
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

double initial_cost;
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

double final_cost;
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

double fixed_cost;
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

int num_successful_steps;
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

int num_unsuccessful_steps;
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

int num_inner_iteration_steps;
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

int num_line_search_steps;
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

double preprocessor_time_in_seconds;
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

double minimizer_time_in_seconds;
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

double postprocessor_time_in_seconds;
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

double total_time_in_seconds;
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

double linear_solver_time_in_seconds;
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

double residual_evaluation_time_in_seconds;
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

double jacobian_evaluation_time_in_seconds;
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

double inner_iteration_time_in_seconds;
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

double line_search_cost_evaluation_time_in_seconds;
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

double line_search_gradient_evaluation_time_in_seconds;
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

double line_search_polynomial_minimization_time_in_seconds;
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

double line_search_total_time_in_seconds;
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

int num_parameter_blocks;
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

int num_parameters;
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

int num_effective_parameters;
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

int num_residual_blocks;
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

int num_residuals;
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

int num_parameter_blocks_reduced;
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

int num_parameters_reduced;
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

int num_effective_parameters_reduced;
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

int num_residual_blocks_reduced;
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

int num_residuals_reduced;
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

bool is_constrained;
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

int num_threads_given;
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

int num_threads_used;
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

int num_linear_solver_threads_given;
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

int num_linear_solver_threads_used;
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

LinearSolverType linear_solver_type_given;
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

LinearSolverType linear_solver_type_used;
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

bool inner_iterations_given;
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

bool inner_iterations_used;
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

PreconditionerType preconditioner_type_given;
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

PreconditionerType preconditioner_type_used;
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

VisibilityClusteringType visibility_clustering_type;
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

TrustRegionStrategyType trust_region_strategy_type;
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

DoglegType dogleg_type;
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

DenseLinearAlgebraLibraryType dense_linear_algebra_library_type;
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

SparseLinearAlgebraLibraryType sparse_linear_algebra_library_type;
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

LineSearchDirectionType line_search_direction_type;
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

LineSearchType line_search_type;
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

LineSearchInterpolationType line_search_interpolation_type;
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

NonlinearConjugateGradientType nonlinear_conjugate_gradient_type;
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

int max_lbfgs_rank;
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
