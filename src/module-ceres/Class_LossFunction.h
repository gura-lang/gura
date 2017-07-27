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
	ceres::LossFunction *_pLossFunction; // set to nullptr after released
public:
	Gura_DeclareObjectAccessor(LossFunction)
public:
	Object_LossFunction();
	virtual String ToString(bool exprFlag);
	inline ceres::LossFunction *GetLossFunction() { return _pLossFunction; }
	inline ceres::LossFunction *ReleaseLossFunction() {
		ceres::LossFunction *pLossFunction = _pLossFunction;
		_pLossFunction = nullptr;
		return pLossFunction;
	}
};

Gura_EndModuleScope(ceres)

#endif
