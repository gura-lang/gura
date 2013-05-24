#ifndef __GURA_OBJECT_ITERATOR_H__
#define __GURA_OBJECT_ITERATOR_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_iterator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_iterator : public Class {
public:
	Class_iterator(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

class GURA_DLLDECLARE Object_iterator : public Object {
public:
	Gura_DeclareObjectAccessor(iterator)
private:
	Iterator *_pIterator;
public:
	inline Object_iterator(Environment &env, Iterator *pIterator) :
				Object(env.LookupClass(VTYPE_iterator)), _pIterator(pIterator) {}
	inline Object_iterator(Class *pClass, Iterator *pIterator) :
				Object(pClass), _pIterator(pIterator) {}
	Object_iterator(const Object_iterator &obj);
	virtual ~Object_iterator();
	virtual Object *Clone() const;
	virtual Iterator *CreateIterator(Signal sig);
	virtual String ToString(Signal sig, bool exprFlag);
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	inline Iterator *GetIterator() const { return _pIterator; }
};

}

#endif
