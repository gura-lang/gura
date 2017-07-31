#ifndef __CERES_CLASS_AUTODIFFCOSTFUNCTION_H__
#define __CERES_CLASS_AUTODIFFCOSTFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

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

//-----------------------------------------------------------------------------
// AutoDiffCostFunctorCustom
//-----------------------------------------------------------------------------
class AutoDiffCostFunctorCustom {
private:
	AutoPtr<Object_AutoDiffCostFunction> _pObjAssoc;
public:
	inline AutoDiffCostFunctorCustom(Object_AutoDiffCostFunction *pObjAssoc) : _pObjAssoc(pObjAssoc) {}
	template<typename T> bool operator()(T const *const *parameters, T *residuals) const{
		::printf("operator()\n");
		return false;
	}		
};

//-----------------------------------------------------------------------------
// AutoDiffCostFunctionCustom
//-----------------------------------------------------------------------------
class AutoDiffCostFunctionCustom : public ceres::DynamicAutoDiffCostFunction<AutoDiffCostFunctorCustom> {
public:
	AutoDiffCostFunctionCustom(AutoDiffCostFunctorCustom *pCostFunctor);
};

Gura_EndModuleScope(ceres)

#endif
