//=============================================================================
// Gura class: array
//=============================================================================
#ifndef __GURA_CLASS_ARRAY_H__
#define __GURA_CLASS_ARRAY_H__

#include "Class.h"
#include "ArrayT.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_array
//-----------------------------------------------------------------------------
class Object_array : public Object {
public:
	Gura_DeclareObjectAccessor(array)
private:
	AutoPtr<Array> _pArray;
public:
	inline Object_array(Environment &env, Array *pArray) :
		Object(env.LookupClass(VTYPE_array)), _pArray(pArray) {}
	inline Object_array(Class *pClass, Array *pArray) :
		Object(pClass), _pArray(pArray) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
};

//-----------------------------------------------------------------------------
// Class_array
//-----------------------------------------------------------------------------
class Class_array : public Class {
public:
	Class_array(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
};

}

#endif
