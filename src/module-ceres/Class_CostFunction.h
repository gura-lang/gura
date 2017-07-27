#ifndef __CERES_CLASS_COSTFUNCTION_H__
#define __CERES_CLASS_COSTFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// CostFunctionCustom
//-----------------------------------------------------------------------------
class CostFunctionCustom : public ceres::CostFunction {
private:
	
public:
	virtual bool Evaluate(double const *const *parameters,
						  double *residuals, double **jacobians) const;
};

//-----------------------------------------------------------------------------
// Object_CostFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CostFunction);

class Object_CostFunction : public Object {
private:
	CostFunctionCustom *_pCostFunctionCustom; // set to nullptr after released
public:
	Gura_DeclareObjectAccessor(CostFunction)
public:
	Object_CostFunction(Class *pClass);
	virtual String ToString(bool exprFlag);
	inline ceres::CostFunction *GetCostFunction() { return _pCostFunctionCustom; }
	inline ceres::CostFunction *ReleaseCostFunction() {
		ceres::CostFunction *pCostFunction = _pCostFunctionCustom;
		_pCostFunctionCustom = nullptr;
		return pCostFunction;
	}
};

Gura_EndModuleScope(ceres)

#endif
