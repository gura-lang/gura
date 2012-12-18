#ifndef __GURA_OBJECT_SEMAPHORE_H__
#define __GURA_OBJECT_SEMAPHORE_H__

#include "Object.h"
#include "OAL.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_semaphore
//-----------------------------------------------------------------------------
class DLLDECLARE Class_semaphore : public Class {
public:
	Class_semaphore(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_semaphore
//-----------------------------------------------------------------------------
class DLLDECLARE Object_semaphore : public Object {
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
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
