#ifndef __ML_LINEAR_CLASS_PARAMETER_H__
#define __ML_LINEAR_CLASS_PARAMETER_H__
#include <gura.h>

Gura_BeginModuleScope(ml_linear)

class Object_ifd;

//-----------------------------------------------------------------------------
// Object_parameter declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(parameter);

class Object_parameter : public Object {
private:
	struct parameter _param;
public:
	Gura_DeclareObjectAccessor(parameter)
public:
	Object_parameter();
	virtual String ToString(bool exprFlag);
	inline struct parameter &GetEntity() { return _param; }
	bool HasValidEntity() const;
};

Gura_EndModuleScope(ml_linear)

#endif
