//=============================================================================
// Gura class: semaphore
//=============================================================================
#ifndef __GURA_CLASS_SEMAPHORE_H__
#define __GURA_CLASS_SEMAPHORE_H__

#include "Class.h"
#include "OAL.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_semaphore
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_semaphore : public Class {
public:
	Class_semaphore(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
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
	Object_semaphore(Environment &env);
	Object_semaphore(Class *pClass);
	inline OAL::Semaphore &GetSemaphore() { return _semaphore; }
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
};

}

#endif
