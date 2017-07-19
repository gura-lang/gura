#ifndef __CERES_CLASS_COSTFUNCTION_H__
#define __CERES_CLASS_COSTFUNCTION_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_CostFunction declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CostFunction);

class Object_CostFunction : public Object {
public:
	Gura_DeclareObjectAccessor(CostFunction)
public:
	Object_CostFunction();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(ceres)

#endif
