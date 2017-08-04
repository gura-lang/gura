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
		if (!rtn.Is_array()) {
			env.SetError(ERR_ValueError, "Evaluate() method is expected to return an array");
			return false;
		}
		do {
			const Array *pArray_residuals = Object_array::GetObject(rtn)->GetArray();
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

Gura_EndModuleScope(ceres)

#endif
