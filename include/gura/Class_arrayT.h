//=============================================================================
// Gura class: arrayT
//=============================================================================
#ifndef __GURA_CLASS_ARRAYT_H__
#define __GURA_CLASS_ARRAYT_H__

#include "Class.h"
#include "ArrayT.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Object_arrayT : public Object {
public:
	Gura_DeclareObjectAccessor(arrayT)
private:
	AutoPtr<ArrayT<T_Elem> > _pArrayT;
public:
	inline Object_arrayT(Environment &env, ValueType valType, ArrayT<T_Elem> *pArrayT) :
				Object(env.LookupClass(valType)), _pArrayT(pArrayT) {}
	inline Object_arrayT(Class *pClass, ArrayT<T_Elem> *pArrayT) :
				Object(pClass), _pArrayT(pArrayT) {}
	inline ArrayT<T_Elem> *GetArrayT() { return _pArrayT.get(); }
	inline const ArrayT<T_Elem> *GetArrayT() const { return _pArrayT.get(); }
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
};

//-----------------------------------------------------------------------------
// Class_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Class_arrayT : public Class {
private:
	String _elemName;
public:
	Class_arrayT(Environment *pEnvOuter, ValueType valType, const String &elemName);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl);
};

}

#endif
