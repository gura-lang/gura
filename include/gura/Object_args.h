#ifndef __GURA_OBJECT_ARGS_H__
#define __GURA_OBJECT_ARGS_H__

#include "Object.h"
#include "OAL.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_args : public Class {
public:
	Class_args(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_args : public Object {
private:
	AutoPtr<Args> _pArgs;
public:
	Gura_DeclareObjectAccessor(args)
public:
	inline Object_args(Environment &env, Args *pArgs) :
					Object(env.LookupClass(VTYPE_args)), _pArgs(pArgs) {}
	inline Object_args(Class *pClass, Args *pArgs) :
					Object(pClass), _pArgs(pArgs) {}
	virtual ~Object_args();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline Args *GetArgs() { return _pArgs.get(); }
};

}

#endif
