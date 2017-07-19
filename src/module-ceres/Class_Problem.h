#ifndef __CERES_CLASS_PROBLEM_H__
#define __CERES_CLASS_PROBLEM_H__
#include <gura.h>

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Problem declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Problem);

class Object_Problem : public Object {
private:
	ceres::Problem _problem;
public:
	Gura_DeclareObjectAccessor(Problem)
public:
	Object_Problem();
	virtual String ToString(bool exprFlag);
	inline ceres::Problem &GetProblem() { return _problem; }
};

Gura_EndModuleScope(ceres)

#endif
