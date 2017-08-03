#ifndef __CERES_CLASS_LOSSFUNCTION_H__
#define __CERES_CLASS_LOSSFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_LossFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(LossFunction);

class Object_LossFunction : public Object {
private:
	ceres::LossFunction *_pLossFunction;
	String _name;
public:
	Gura_DeclareObjectAccessor(LossFunction)
public:
	Object_LossFunction(ceres::LossFunction *pLossFunction, const char *name);
	virtual String ToString(bool exprFlag);
	inline void SetLossFunction(ceres::LossFunction *pLossFunction) {
		_pLossFunction = pLossFunction;
	}
	inline ceres::LossFunction *GetLossFunction() { return _pLossFunction; }
};

Gura_EndModuleScope(ceres)

#endif
