#ifndef __CERES_CLASS_SOLVER_SUMMARY_H__
#define __CERES_CLASS_SOLVER_SUMMARY_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Solver_Summary declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Solver_Summary);

class Object_Solver_Summary : public Object {
public:
	Gura_DeclareObjectAccessor(Solver_Summary)
public:
	Object_Solver_Summary();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(ceres)

#endif
