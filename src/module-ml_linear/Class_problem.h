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
private:
	struct problem _prob;
public:
	Gura_DeclareObjectAccessor(problem)
public:
	Object_problem();
	virtual String ToString(bool exprFlag);
	inline struct problem &GetEntity() { return _prob; }
	bool HasValidEntity() const;
};

Gura_EndModuleScope(ml_linear)

#endif
