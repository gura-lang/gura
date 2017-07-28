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
// ceres.CostFunction(numResiduals:number, parameterBlockSizes+:number) {block?}
Gura_DeclareFunction(CostFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numResiduals", VTYPE_number);
	DeclareArg(env, "parameterBlockSizes", VTYPE_number, OCCUR_OnceOrMore);
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
	CostFunctionCustom *pCostFunctionCustom = pObj->GetCostFunctionCustom();
	pCostFunctionCustom->Prepare(arg.GetValue(0), arg.GetList(1));
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
CostFunctionCustom::CostFunctionCustom()
{
}

void CostFunctionCustom::Prepare(const Value &value_numResiduals, const ValueList &valList_parameterBlockSizes)
{
	set_num_residuals(value_numResiduals.GetInt());
	foreach_const (ValueList, pValue, valList_parameterBlockSizes) {
		mutable_parameter_block_sizes()->push_back(pValue->GetInt());
	}
}

bool CostFunctionCustom::Evaluate(double const *const *parameters,
								  double *residuals, double **jacobians) const
{
	Environment &env = *_pObjAssoc;
	const Function *pFunc = _pObjAssoc->LookupFunction(Gura_UserSymbol(Evaluate), ENVREF_Escalate);
	if (pFunc == nullptr) {
		env.SetError(ERR_KeyError, "can't find a method named Evaluate");
		return false;
	}
	ValueList valListArg;
	size_t i = 0;
	foreach_const (std::vector<ceres::int32>, pSize, parameter_block_sizes()) {
		ceres::int32 size = *pSize;
		double const *parameter = parameters[i++];
		valListArg.push_back(Value(new Object_array(env, new ArrayT<Double>(parameter, size))));
	}
	Value rtn = _pObjAssoc->EvalMethod(*_pObjAssoc, pFunc, valListArg);
	if (rtn.Is_list()) {
		
	} else if (rtn.Is_array()) {
		const Array *pArray = Object_array::GetObject(rtn)->GetArray();
		if (pArray->GetElemType() != Array::ETYPE_Double) {
			env.SetError(ERR_ValueError, "type of elements in the returned array must be double");
			return false;
		}
		const ArrayT<Double> *pArrayT = dynamic_cast<const ArrayT<Double> *>(pArray);
		if (static_cast<size_t>(num_residuals()) != pArrayT->GetElemNum()) {
			env.SetError(ERR_ValueError, "number of residuals doesn't match");
			return false;
		}
		::memcpy(residuals, pArrayT->GetPointer(), sizeof(Double) * pArrayT->GetElemNum());
	} else {
		env.SetError(ERR_ValueError, "returned value must be a single array or a pair of arrays");
		return false;
	}
	return true;
}

Gura_EndModuleScope(ceres)
