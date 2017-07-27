#ifndef __CERES_CLASS_LOSSFUNCTION_H__
#define __CERES_CLASS_LOSSFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_LossFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(LossFunction);

class Object_LossFunction : public Object {
public:
	Gura_DeclareObjectAccessor(LossFunction)
public:
	Object_LossFunction();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(ceres)

#endif
