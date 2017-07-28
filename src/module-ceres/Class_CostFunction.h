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
	AutoPtr<Object_CostFunction> _pObjAssoc;
public:
	CostFunctionCustom();
	void Prepare(const Value &value_numResiduals, const ValueList &valList_parameterBlockSizes);
	virtual bool Evaluate(double const *const *parameters,
						  double *residuals, double **jacobians) const;
	inline void SetAssocObj(Object_CostFunction *pObjAssoc) { _pObjAssoc.reset(pObjAssoc); }
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
	inline CostFunctionCustom *GetCostFunctionCustom() { return _pCostFunctionCustom; }
	inline CostFunctionCustom *ReleaseCostFunctionCustom() {
		CostFunctionCustom *pCostFunctionCustom = _pCostFunctionCustom;
		_pCostFunctionCustom = nullptr;
		return pCostFunctionCustom;
	}
};

Gura_EndModuleScope(ceres)

#endif
