#ifndef __GURA_OBJECT_ERROR_H__
#define __GURA_OBJECT_ERROR_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_error / Object_error
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_error : public Class {
public:
	Class_error(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

class GURA_DLLDECLARE Object_error : public Object {
public:
	Gura_DeclareObjectAccessor(error)
private:
	ErrorType _errType;
public:
	inline Object_error(Environment &env, ErrorType errType) :
					Object(env.LookupClass(VTYPE_error)), _errType(errType) {}
	inline Object_error(Class *pClass, ErrorType errType) :
					Object(pClass), _errType(errType) {}
	Object_error(const Object_error &obj);
	virtual ~Object_error();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline ErrorType GetErrorType() const { return _errType; }
};

}

#endif
