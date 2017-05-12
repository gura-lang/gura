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
	class GURA_DLLDECLARE PointerEx : public Pointer {
	protected:
		AutoPtr<Object_array> _pObjArray;
	public:
		PointerEx(size_t offset, Object_array *pObjArray);
		PointerEx(const PointerEx &ptr);
		inline Object_array *GetObjArray() { return _pObjArray.get(); }
		inline const Object_array *GetObjArray() const { return _pObjArray.get(); }
		inline Memory &GetMemory() { return _pObjArray->GetArray()->GetMemory(); }
		inline Memory &GetMemory() const { return _pObjArray->GetArray()->GetMemory(); }
	public:
		// virtual functions for Packer
		virtual bool StorePrepare(Signal &sig, size_t bytes);
		virtual void StoreBuffer(const void *buff, size_t bytes);
		virtual const UChar *ExtractPrepare(Signal &sig, size_t bytes, bool exceedErrorFlag);
	public:
		// virtual functions for Pointer
		virtual Pointer *Clone() const;
		virtual Object *GetTarget() const;
		virtual const UChar *GetPointerC() const;
		virtual UChar *GetWritablePointerC() const;
		virtual size_t GetEntireSize() const;
		virtual bool IsWritable() const;
	};
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
	virtual Value EvalIndexGet(Environment &env, const ValueList &valListIdx);
	virtual void EvalIndexSet(Environment &env, const ValueList &valListIdx, const Value &value);
	virtual Iterator *CreateIterator(Signal &sig);
};

//-----------------------------------------------------------------------------
// Class_array
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_array : public ClassFundamental {
public:
	Class_array(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl);
};

}

#endif
