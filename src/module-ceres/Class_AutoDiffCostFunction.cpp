#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_AutoDiffCostFunction implementation
//-----------------------------------------------------------------------------
Object_AutoDiffCostFunction::Object_AutoDiffCostFunction(Class *pClass) :
								Object_CostFunction(pClass)
{
}

String Object_AutoDiffCostFunction::ToString(bool exprFlag)
{
	String str = "<ceres.AutoDiffCostFunction";
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
// ceres.AutoDiffCostFunction(numResiduals:number, parameterBlockSizes+:number) {block?}
Gura_DeclareFunction(AutoDiffCostFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numResiduals", VTYPE_number);
	DeclareArg(env, "parameterBlockSizes", VTYPE_number, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(AutoDiffCostFunction));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(AutoDiffCostFunction)
{
	Object_AutoDiffCostFunction *pObj = Object_AutoDiffCostFunction::GetObjectThis(arg);
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
// Implementation of class ceres.AutoDiffCostFunction
//-----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(AutoDiffCostFunction)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(AutoDiffCostFunction);
}

Gura_ImplementDescendantCreator(AutoDiffCostFunction)
{
	Object_AutoDiffCostFunction *pObj = new Object_AutoDiffCostFunction((pClass == nullptr)? this : pClass);
	pObj->SetCostFunction(new AutoDiffCostFunctionCustom(new AutoDiffCostFunctorCustom(pObj->Reference())));
	return pObj;
}

//-----------------------------------------------------------------------------
// AutoDiffCostFunctionCustom
//-----------------------------------------------------------------------------
AutoDiffCostFunctionCustom::AutoDiffCostFunctionCustom(AutoDiffCostFunctorCustom *pCostFunctor) :
	ceres::DynamicAutoDiffCostFunction<AutoDiffCostFunctorCustom>(pCostFunctor)
{
}

Gura_EndModuleScope(ceres)
