//=============================================================================
// Pointer
//=============================================================================
#ifndef __GURA_POINTER_H__
#define __GURA_POINTER_H__

#include "Environment.h"
#include "Signal.h"
#include "Value.h"

#include "Class_binary.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Pointer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Pointer {
protected:
	int _cntRef;
	size_t _offset;
public:
	Gura_DeclareReferenceAccessor(Pointer)
public:
	Pointer(size_t offset);
	virtual ~Pointer();
	inline size_t GetOffset() const { return _offset; }
	inline void Reset() { _offset = 0; }
public:
	virtual bool IsWritable() const = 0;
	virtual bool Pack(Environment &env, bool forwardFlag,
					  const char *format, const ValueList &valListArg) = 0;
	virtual Value Unpack(Environment &env, bool forwardFlag,
						 const char *format, const ValueList &valListArg, bool exeedErrorFlag) = 0;
	virtual bool UnpackForward(Environment &env, int distance, bool exceedErrorFlag) = 0;
};

//-----------------------------------------------------------------------------
// PointerBinary
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PointerBinary : public Pointer {
protected:
	AutoPtr<Object_binary> _pObjBinary;
public:
	inline PointerBinary(size_t offset, Object_binary *pObjBinary) :
						Pointer(offset), _pObjBinary(pObjBinary) {}
	inline Object_binary *GetBinaryObj() { return _pObjBinary.get(); }
	inline const Object_binary *GetBinaryObj() const { return _pObjBinary.get(); }
	inline Binary &GetBinary() { return _pObjBinary->GetBinary(); }
	inline const Binary &GetBinary() const { return _pObjBinary->GetBinary(); }
public:
	virtual bool IsWritable() const;
	virtual bool Pack(Environment &env, bool forwardFlag,
					  const char *format, const ValueList &valListArg);
	virtual Value Unpack(Environment &env, bool forwardFlag,
						 const char *format, const ValueList &valListArg, bool exeedErrorFlag);
	virtual bool UnpackForward(Environment &env, int distance, bool exceedErrorFlag);
};

}

#endif
