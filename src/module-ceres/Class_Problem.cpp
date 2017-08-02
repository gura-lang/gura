#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Problem implementation
//-----------------------------------------------------------------------------
Object_Problem::Object_Problem() : Object(Gura_UserClass(Problem)), _pArrayOwner(new ArrayOwner())
{
}

String Object_Problem::ToString(bool exprFlag)
{
	return String("<ceres.Problem>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.Problem() {block?}
Gura_DeclareFunction(Problem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(Problem));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(Problem)
{
	Object_Problem *pObj = new Object_Problem();
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// ceres.Problem#AddResidualBlock(cost_function:ceres.CostFunction, loss_function:ceres.LossFunction, params+:array@double)
Gura_DeclareMethod(Problem, AddResidualBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cost_function", VTYPE_CostFunction, OCCUR_Once);
	DeclareArg(env, "loss_function", VTYPE_LossFunction, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "params", VTYPE_array_at_double, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(Problem, AddResidualBlock)
{
	Object_Problem *pThis = Object_Problem::GetObjectThis(arg);
	ceres::Problem &problem = pThis->GetProblem();
	ceres::CostFunction *cost_function = Object_CostFunction::GetObject(arg, 0)->GetCostFunction();
	ceres::LossFunction *loss_function = arg.IsValid(1)?
		Object_LossFunction::GetObject(arg, 1)->GetLossFunction() : nullptr;
	if (cost_function == nullptr) {
		env.SetError(ERR_ValueError, "cost_function is invalid");
		return Value::Nil;
	}
	std::vector<double *> parameter_blocks;
	foreach_const (ValueList, pValue, arg.GetList(2)) {
		ArrayT<Double> *pArrayT = dynamic_cast<ArrayT<Double> *>(Object_array::GetObject(*pValue)->GetArray());
		pThis->GetArrayOwner().push_back(pArrayT->Reference());
		parameter_blocks.push_back(pArrayT->GetPointer());
	}
	ceres::ResidualBlockId rtn = problem.AddResidualBlock(cost_function, loss_function, parameter_blocks);
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// Implementation of class ceres.Problem
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Problem)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(Problem);
	// Assignment of method
	Gura_AssignMethod(Problem, AddResidualBlock);
}

Gura_EndModuleScope(ceres)
