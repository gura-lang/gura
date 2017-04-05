#ifndef __ML_LINEAR_CLASS_PROBLEM_H__
#define __ML_LINEAR_CLASS_PROBLEM_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

class Object_ifd;

//-----------------------------------------------------------------------------
// Object_problem declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(problem);

class Object_problem : public Object {
public:
	Gura_DeclareObjectAccessor(problem)
public:
	Object_problem();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(ml_linear)

#endif
