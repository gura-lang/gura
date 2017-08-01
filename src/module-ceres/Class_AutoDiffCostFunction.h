#ifndef __CERES_CLASS_AUTODIFFCOSTFUNCTION_H__
#define __CERES_CLASS_AUTODIFFCOSTFUNCTION_H__
#include <gura.h>
#include "Symbol.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_NumericDiffCostFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(NumericDiffCostFunction);

class Object_NumericDiffCostFunction : public Object_CostFunction {
public:
	Gura_DeclareObjectAccessor(NumericDiffCostFunction)
public:
	Object_NumericDiffCostFunction(Class *pClass);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// NumericDiffCostFunctorCustom
//-----------------------------------------------------------------------------
class NumericDiffCostFunctorCustom {
private:
	AutoPtr<Object_NumericDiffCostFunction> _pObjAssoc;
public:
	inline NumericDiffCostFunctorCustom(Object_NumericDiffCostFunction *pObjAssoc) : _pObjAssoc(pObjAssoc) {}
	bool operator()(double const *const *parameters, double *residuals) const{
		::printf("operator()\n");
		Environment &env = *_pObjAssoc;
		ceres::DynamicCostFunction *pCostFunction = _pObjAssoc->GetCostFunction();
		const Function *pFunc = _pObjAssoc->LookupFunction(Gura_UserSymbol(Evaluate), ENVREF_Escalate);
		if (pFunc == nullptr) {
			env.SetError(ERR_KeyError, "can't find a method Evaluate");
			return false;
		}
		ValueList valListArg;
		size_t i = 0;
		foreach_const (std::vector<ceres::int32>, pSize, pCostFunction->parameter_block_sizes()) {
			ceres::int32 size = *pSize;
			double const *parameter = parameters[i++];
			valListArg.push_back(Value(new Object_array(env, new ArrayT<Double>(parameter, size))));
		}
		Value rtn = _pObjAssoc->EvalMethod(*_pObjAssoc, pFunc, valListArg);
		if (!rtn.Is_list()) {
			env.SetError(ERR_ValueError, "returned value must be a pair of arrays");
			return false;
		}
		const ValueList &valList = rtn.GetList();
		if (valList.size() != 2 || !valList[0].Is_array() || !valList[1].Is_array()) {
			env.SetError(ERR_ValueError, "the list must contain a pair of arrays");
			return false;
		}
		do {
			const Array *pArray_residuals = Object_array::GetObject(valList[0])->GetArray();
			if (pArray_residuals->GetElemType() != Array::ETYPE_Double) {
				env.SetError(ERR_ValueError, "type of elements in the returned array must be double");
				return false;
			}
			const ArrayT<Double> *pArrayT_residuals = dynamic_cast<const ArrayT<Double> *>(pArray_residuals);
			if (static_cast<size_t>(pCostFunction->num_residuals()) != pArrayT_residuals->GetElemNum()) {
				env.SetError(ERR_ValueError, "number of residuals doesn't match");
				return false;
			}
			::memcpy(residuals, pArrayT_residuals->GetPointer(), sizeof(Double) * pArrayT_residuals->GetElemNum());
		} while (0);
		return true;
	}		
};

//-----------------------------------------------------------------------------
// NumericDiffCostFunctionCustom
//-----------------------------------------------------------------------------
class NumericDiffCostFunctionCustom : public ceres::DynamicNumericDiffCostFunction<NumericDiffCostFunctorCustom> {
public:
	NumericDiffCostFunctionCustom(NumericDiffCostFunctorCustom *pCostFunctor);
};

Gura_EndModuleScope(ceres)

#endif
