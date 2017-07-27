#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_CostFunction implementation
//-----------------------------------------------------------------------------
Object_CostFunction::Object_CostFunction(Class *pClass) :
					Object(pClass), _pCostFunctionCustom(new CostFunctionCustom())
{
	_pCostFunctionCustom->SetAssocObj(Reference());
}

String Object_CostFunction::ToString(bool exprFlag)
{
	String str = "<ceres.CostFunction";
	if (_pCostFunctionCustom == nullptr) str += ":invalid";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.CostFunction() {block?}
Gura_DeclareFunction(CostFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(CostFunction));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(CostFunction)
{
	Object_CostFunction *pObj = Object_CostFunction::GetObjectThis(arg);
	if (pObj == nullptr) {
		env.SetError(ERR_ValueError, "pure class can not be instantiated");
		return Value::Nil;
	}
	return ReturnValue(env, arg, arg.GetValueThis());
}

//-----------------------------------------------------------------------------
// Implementation of class ceres.CostFunction
//-----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(CostFunction)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(CostFunction);
}

Gura_ImplementDescendantCreator(CostFunction)
{
	return new Object_CostFunction((pClass == nullptr)? this : pClass);
}

//-----------------------------------------------------------------------------
// CostFunctionCustom
//-----------------------------------------------------------------------------
bool CostFunctionCustom::Evaluate(double const *const *parameters,
								  double *residuals, double **jacobians) const
{
	const Function *pFunc = _pObjAssoc->LookupFunction(Gura_UserSymbol(Evaluate), ENVREF_Escalate);
	if (pFunc == nullptr) {
		return false;
	}
	Value rtn = _pObjAssoc->EvalMethod(*_pObjAssoc, pFunc, ValueList::Empty);
	return false;
}

Gura_EndModuleScope(ceres)
