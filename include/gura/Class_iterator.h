//=============================================================================
// Gura class: iterator
//=============================================================================
#ifndef __GURA_CLASS_ITERATOR_H__
#define __GURA_CLASS_ITERATOR_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_iterator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_iterator : public Class {
public:
	Class_iterator(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_iterator
//-----------------------------------------------------------------------------
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
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Object *Clone() const;
	virtual Iterator *CreateIterator(Signal &sig);
	virtual String ToString(bool exprFlag);
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	inline Iterator *GetIterator() const { return _pIterator; }
};

}

#endif
