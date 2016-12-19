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
class GURA_DLLDECLARE Object_array : public Object {
public:
	Gura_DeclareObjectAccessor(array)
protected:
	AutoPtr<Array> _pArray;
public:
	inline Object_array(Environment &env, Array *pArray) :
		Object(env.LookupClass(VTYPE_array)), _pArray(pArray) {}
	inline Object_array(Class *pClass, Array *pArray) :
		Object(pClass), _pArray(pArray) {}
	inline Array *GetArray() { return _pArray.get(); }
	inline const Array *GetArray() const { return _pArray.get(); }
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
};

//-----------------------------------------------------------------------------
// Class_array
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_array : public Class {
public:
	Class_array(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl);
};

}

#endif
