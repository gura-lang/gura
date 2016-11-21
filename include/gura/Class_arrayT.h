//=============================================================================
// Gura class: arrayT
//=============================================================================
#ifndef __GURA_CLASS_ARRAYT_H__
#define __GURA_CLASS_ARRAYT_H__

#include "Class.h"
#include "ArrayT.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Class_arrayT : public Class {
private:
	String _elemName;
public:
	Class_arrayT(Environment *pEnvOuter, ValueType valType, const String &elemName);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl);
};

//-----------------------------------------------------------------------------
// Object_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Object_arrayT : public Object_array {
public:
	Gura_DeclareObjectAccessor(arrayT)
public:
	inline Object_arrayT(Environment &env, ValueType valType, Array *pArray) :
		Object_array(env.LookupClass(valType), pArray) {}
	inline Object_arrayT(Class *pClass, Array *pArray) :
		Object_array(pClass, pArray) {}
	inline ArrayT<T_Elem> *GetArrayT() {
		return dynamic_cast<ArrayT<T_Elem> *>(_pArray.get());
	}
	inline const ArrayT<T_Elem> *GetArrayT() const {
		return dynamic_cast<ArrayT<T_Elem> *>(_pArray.get());
	}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
};

}

#endif
