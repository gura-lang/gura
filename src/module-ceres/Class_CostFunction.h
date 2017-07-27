#ifndef __CERES_CLASS_COSTFUNCTION_H__
#define __CERES_CLASS_COSTFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_CostFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CostFunction);

class Object_CostFunction : public Object {
private:
	ceres::CostFunction *_pCostFunction; // set to nullptr after released
public:
	Gura_DeclareObjectAccessor(CostFunction)
public:
	Object_CostFunction();
	virtual String ToString(bool exprFlag);
	inline ceres::CostFunction *GetCostFunction() { return _pCostFunction; }
	inline ceres::CostFunction *ReleaseCostFunction() {
		ceres::CostFunction *pCostFunction = _pCostFunction;
		_pCostFunction = nullptr;
		return pCostFunction;
	}
};

Gura_EndModuleScope(ceres)

#endif
