#ifndef __GURA_OBJECT_SEMAPHORE_H__
#define __GURA_OBJECT_SEMAPHORE_H__

#include "Object.h"
#include "OAL.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_semaphore
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_semaphore : public Class {
public:
	Class_semaphore(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_semaphore
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_semaphore : public Object {
public:
	Gura_DeclareObjectAccessor(semaphore)
private:
	OAL::Semaphore _semaphore;
public:
	inline Object_semaphore(Environment &env) : Object(env.LookupClass(VTYPE_semaphore)) {}
	inline Object_semaphore(Class *pClass) : Object(pClass) {}
	inline OAL::Semaphore &GetSemaphore() { return _semaphore; }
	virtual ~Object_semaphore();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
};

}

#endif
