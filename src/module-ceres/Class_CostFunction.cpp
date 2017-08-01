#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_CostFunction implementation
//-----------------------------------------------------------------------------
Object_CostFunction::Object_CostFunction(Class *pClass) :
								Object(pClass), _pCostFunction(nullptr)
{
}

String Object_CostFunction::ToString(bool exprFlag)
{
	String str = "<ceres.CostFunction";
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
	ceres::DynamicCostFunction *pCostFunction = pObj->GetCostFunction();
	pCostFunction->SetNumResiduals(arg.GetInt(0));
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		pCostFunction->AddParameterBlock(pValue->GetInt());
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
	Object_CostFunction *pObj = new Object_CostFunction((pClass == nullptr)? this : pClass);
	pObj->SetCostFunction(new CostFunctionCustom(pObj->Reference()));
	return pObj;
}

//-----------------------------------------------------------------------------
// CostFunctionCustom
//-----------------------------------------------------------------------------
CostFunctionCustom::CostFunctionCustom(Object *pObjAssoc) : _pObjAssoc(pObjAssoc)
{
}

bool CostFunctionCustom::Evaluate(double const *const *parameters,
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
	if (!rtn.Is_list()) {
		env.SetError(ERR_ValueError, "Evaluate() method is expected to return a pair of arrays");
		return false;
	}
	const ValueList &valList = rtn.GetList();
	if (valList.size() != 2 || !valList[0].Is_array() || !valList[1].Is_array()) {
		env.SetError(ERR_ValueError, "Evaluate() method is expected to return a pair of arrays");
		return false;
	}
	do {
		const Array *pArray_residuals = Object_array::GetObject(valList[0])->GetArray();
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
	if (jacobians != nullptr) {
		const Array *pArray_jacobians = Object_array::GetObject(valList[1])->GetArray();
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

Gura_EndModuleScope(ceres)
