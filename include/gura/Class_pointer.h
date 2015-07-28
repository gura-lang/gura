//=============================================================================
// Gura class: pointer
//=============================================================================
#ifndef __GURA_CLASS_POINTER_H__
#define __GURA_CLASS_POINTER_H__

#include "Class_binary.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_pointer / Object_pointer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_pointer : public Class {
public:
	Class_pointer(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal &__to_delete__, Class *pClass);
};

class GURA_DLLDECLARE Object_pointer : public Object {
public:
	Gura_DeclareObjectAccessor(pointer)
private:
	AutoPtr<Object_binary> _pObjBinary;
	size_t _offset;
public:
	inline Object_pointer(Class *pClass, Object_binary *pObjBinary, size_t offset) :
		Object(pClass), _pObjBinary(pObjBinary), _offset(offset) {}
	inline Object_pointer(Environment &env, Object_binary *pObjBinary, size_t offset) :
		Object(env.LookupClass(VTYPE_pointer)), _pObjBinary(pObjBinary), _offset(offset) {}
	inline Object_pointer(const Object_pointer &obj) :
		Object(obj), _pObjBinary(dynamic_cast<Object_binary *>(Object::Reference(obj.GetBinaryObj()))),
		_offset(obj._offset) {}
	virtual ~Object_pointer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Object_binary *GetBinaryObj() { return _pObjBinary.get(); }
	inline const Object_binary *GetBinaryObj() const { return _pObjBinary.get(); }
	inline Binary &GetBinary() { return _pObjBinary->GetBinary(); }
	inline const Binary &GetBinary() const { return _pObjBinary->GetBinary(); }
	inline bool IsWritable() const { return _pObjBinary->IsWritable(); }
	inline size_t GetOffset() const { return _offset; }
	inline void Reset() { _offset = 0; }
	bool Pack(Signal &sig, bool forwardFlag,
					const char *format, const ValueList &valListArg);
	Value Unpack(Signal &sig, bool forwardFlag,
					const char *format, const ValueList &valListArg, bool exeedErrorFlag);
	bool UnpackForward(Signal &sig, int distance, bool exceedErrorFlag);
};

}

#endif
