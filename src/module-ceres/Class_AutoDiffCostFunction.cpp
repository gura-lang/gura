#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_NumericDiffCostFunction implementation
//-----------------------------------------------------------------------------
Object_NumericDiffCostFunction::Object_NumericDiffCostFunction(Class *pClass) :
								Object_CostFunction(pClass)
{
}

String Object_NumericDiffCostFunction::ToString(bool exprFlag)
{
	String str = "<ceres.NumericDiffCostFunction";
	if (_pCostFunction == nullptr) str += ":invalid";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.NumericDiffCostFunction(numResiduals:number, parameterBlockSizes+:number) {block?}
Gura_DeclareFunction(NumericDiffCostFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numResiduals", VTYPE_number);
	DeclareArg(env, "parameterBlockSizes", VTYPE_number, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(NumericDiffCostFunction));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(NumericDiffCostFunction)
{
	Object_NumericDiffCostFunction *pObj = Object_NumericDiffCostFunction::GetObjectThis(arg);
	if (pObj == nullptr) {
		env.SetError(ERR_ValueError, "pure class can not be instantiated");
		return Value::Nil;
	}
	ceres::DynamicCostFunction *pCostFunction = pObj->GetCostFunction();
	pCostFunction->SetNumResiduals(arg.GetInt(0));
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		pCostFunction->AddParameterBlock(pValue->GetInt());
	}
	return ReturnValue(env, arg, arg.GetValueThis());
}

//-----------------------------------------------------------------------------
// Implementation of class ceres.NumericDiffCostFunction
//-----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(NumericDiffCostFunction)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(NumericDiffCostFunction);
}

Gura_ImplementDescendantCreator(NumericDiffCostFunction)
{
	Object_NumericDiffCostFunction *pObj = new Object_NumericDiffCostFunction((pClass == nullptr)? this : pClass);
	pObj->SetCostFunction(new NumericDiffCostFunctionCustom(new NumericDiffCostFunctorCustom(pObj->Reference())));
	return pObj;
}

//-----------------------------------------------------------------------------
// NumericDiffCostFunctionCustom
//-----------------------------------------------------------------------------
NumericDiffCostFunctionCustom::NumericDiffCostFunctionCustom(NumericDiffCostFunctorCustom *pCostFunctor) :
	ceres::DynamicNumericDiffCostFunction<NumericDiffCostFunctorCustom>(pCostFunctor)
{
}

Gura_EndModuleScope(ceres)
