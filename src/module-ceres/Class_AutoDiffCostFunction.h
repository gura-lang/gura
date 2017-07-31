#ifndef __CERES_CLASS_AUTODIFFCOSTFUNCTION_H__
#define __CERES_CLASS_AUTODIFFCOSTFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

class Object_AutoDiffCostFunction;


//-----------------------------------------------------------------------------
// AutoDiffCostFunctorCustom
//-----------------------------------------------------------------------------
struct AutoDiffCostFunctorCustom {
	template<typename T>
	bool operator()(T const *const *parameters, T *residuals) const {
		::printf("operator()\n");
		return false;
	}
};

//-----------------------------------------------------------------------------
// AutoDiffCostFunctionCustom
//-----------------------------------------------------------------------------
class AutoDiffCostFunctionCustom : public ceres::DynamicAutoDiffCostFunction<AutoDiffCostFunctorCustom> {
private:
	AutoPtr<Object_AutoDiffCostFunction> _pObjAssoc;
public:
	AutoDiffCostFunctionCustom(AutoDiffCostFunctorCustom *pCostFunctor);
	inline void SetAssocObj(Object_AutoDiffCostFunction *pObjAssoc) { _pObjAssoc.reset(pObjAssoc); }
};

//-----------------------------------------------------------------------------
// Object_AutoDiffCostFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(AutoDiffCostFunction);

class Object_AutoDiffCostFunction : public Object_CostFunction {
public:
	Gura_DeclareObjectAccessor(AutoDiffCostFunction)
public:
	Object_AutoDiffCostFunction(Class *pClass);
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(ceres)

#endif
