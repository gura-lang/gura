#ifndef __CERES_CLASS_COSTFUNCTION_H__
#define __CERES_CLASS_COSTFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

class Object_CostFunction;

//-----------------------------------------------------------------------------
// CostFunctionCustom
//-----------------------------------------------------------------------------
class CostFunctionCustom : public ceres::DynamicCostFunction {
private:
	AutoPtr<Object> _pObjAssoc;
public:
	CostFunctionCustom(Object *pObjAssoc);
	virtual bool Evaluate(double const *const *parameters,
						  double *residuals, double **jacobians) const;
};

//-----------------------------------------------------------------------------
// Object_CostFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CostFunction);

class Object_CostFunction : public Object {
protected:
	ceres::DynamicCostFunction *_pCostFunction; // set to nullptr after released
public:
	Gura_DeclareObjectAccessor(CostFunction)
public:
	Object_CostFunction(Class *pClass);
	virtual String ToString(bool exprFlag);
	inline void SetCostFunction(ceres::DynamicCostFunction *pCostFunction) {
		_pCostFunction = pCostFunction;
	}
	inline ceres::DynamicCostFunction *GetCostFunction() { return _pCostFunction; }
	inline ceres::DynamicCostFunction *ReleaseCostFunction() {
		ceres::DynamicCostFunction *pCostFunction = _pCostFunction;
		_pCostFunction = nullptr;
		return pCostFunction;
	}
};

Gura_EndModuleScope(ceres)

#endif
