#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_AutoDiffCostFunction implementation
//-----------------------------------------------------------------------------
Object_AutoDiffCostFunction::Object_AutoDiffCostFunction(Class *pClass) :
	Object_CostFunction(pClass)
{
	//_pCostFunctionCustom->SetAssocObj(Reference());
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
#if 0
	Object_AutoDiffCostFunction *pObj = Object_AutoDiffCostFunction::GetObjectThis(arg);
	if (pObj == nullptr) {
		env.SetError(ERR_ValueError, "pure class can not be instantiated");
		return Value::Nil;
	}
	CostFunctionCustom *pCostFunctionCustom = pObj->GetCostFunctionCustom();
	pCostFunctionCustom->SetNumResiduals(arg.GetInt(0));
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		pCostFunctionCustom->AddParameterBlock(pValue->GetInt());
	}
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	return Value::Nil;
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
	return new Object_AutoDiffCostFunction((pClass == nullptr)? this : pClass);
}

//-----------------------------------------------------------------------------
// AutoDiffCostFunctionCustom
//-----------------------------------------------------------------------------
AutoDiffCostFunctionCustom::AutoDiffCostFunctionCustom(AutoDiffCostFunctorCustom *pCostFunctor) :
	ceres::DynamicAutoDiffCostFunction<AutoDiffCostFunctorCustom>(pCostFunctor)
{
}

#if 0
bool AutoDiffCostFunctionCustom::Evaluate(double const *const *parameters,
								  double *residuals, double **jacobians) const
{
	Environment &env = *_pObjAssoc;
	const Function *pFunc = _pObjAssoc->LookupFunction(Gura_UserSymbol(Evaluate), ENVREF_Escalate);
	if (pFunc == nullptr) {
		env.SetError(ERR_KeyError, "can't find a method Evaluate");
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
	const Array *pArray_residuals = nullptr;
	const Array *pArray_jacobians = nullptr;
	if (rtn.Is_array()) {
		pArray_residuals = Object_array::GetObject(rtn)->GetArray();
	} else if (rtn.Is_list()) {
		const ValueList &valList = rtn.GetList();
		if (valList.size() != 2 || !valList[0].Is_array() || !valList[1].Is_array()) {
			env.SetError(ERR_ValueError, "the list must contain a pair of arrays");
			return false;
		}
		pArray_residuals = Object_array::GetObject(valList[0])->GetArray();
		pArray_jacobians = Object_array::GetObject(valList[1])->GetArray();
	} else {
		env.SetError(ERR_ValueError, "returned value must be a single array or a pair of arrays");
		return false;
	}
	do {
		if (pArray_residuals->GetElemType() != Array::ETYPE_Double) {
			env.SetError(ERR_ValueError, "type of elements in the returned array must be double");
			return false;
		}
		const ArrayT<Double> *pArrayT_residuals = dynamic_cast<const ArrayT<Double> *>(pArray_residuals);
		if (static_cast<size_t>(num_residuals()) != pArrayT_residuals->GetElemNum()) {
			env.SetError(ERR_ValueError, "number of residuals doesn't match");
			return false;
		}
		::memcpy(residuals, pArrayT_residuals->GetPointer(), sizeof(Double) * pArrayT_residuals->GetElemNum());
	} while (0);
	if (jacobians == nullptr) {
		// nothing to do
	} else if (pArray_jacobians == nullptr) {
		
	} else {
		if (pArray_jacobians->GetElemType() != Array::ETYPE_Double) {
			env.SetError(ERR_ValueError, "type of elements in the returned array must be double");
			return false;
		}
		const ArrayT<Double> *pArrayT_jacobians = dynamic_cast<const ArrayT<Double> *>(pArray_jacobians);
		const Array::Dimensions &dims = pArrayT_jacobians->GetDimensions();
		if (dims.size() != 2) {
			env.SetError(ERR_ValueError, "returned array must be two-dimension");
			return false;
		}
		size_t i = 0;
		const double *pElem = pArrayT_jacobians->GetPointer();
		foreach_const (std::vector<ceres::int32>, pSize, parameter_block_sizes()) {
			if (i >= dims[0].GetSize()) break;
			ceres::int32 size = *pSize;
			double *jacobian = jacobians[i++];
			size_t sizeMin = ChooseMin(dims[1].GetSize(), static_cast<size_t>(size));
			::memcpy(jacobian, pElem, sizeMin * sizeof(double));
			pElem += dims[0].GetStride();
		}
	}
	return true;
}
#endif

Gura_EndModuleScope(ceres)
