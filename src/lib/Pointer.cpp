//=============================================================================
// Pointer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Pointer
//-----------------------------------------------------------------------------
Pointer::Pointer(size_t offset) : _cntRef(1), _offset(offset)
{
}

Pointer::~Pointer()
{
}

//-----------------------------------------------------------------------------
// PointerBinary
//-----------------------------------------------------------------------------
PointerBinary::PointerBinary(size_t offset, Object_binary *pObjBinary) :
	Pointer(offset), _pObjBinary(pObjBinary)
{
}

PointerBinary::PointerBinary(const PointerBinary &ptr) :
	Pointer(ptr.GetOffset()), _pObjBinary(dynamic_cast<Object_binary *>(ptr._pObjBinary->Reference()))
{
}

Pointer *PointerBinary::Clone() const
{
	return new PointerBinary(*this);
}

Object *PointerBinary::GetTarget() const
{
	return _pObjBinary.get();
}

bool PointerBinary::IsWritable() const
{
	return _pObjBinary->IsWritable();
}

bool PointerBinary::Pack(Environment &env, bool forwardFlag,
					  const char *format, const ValueList &valListArg)
{
	size_t offset = _offset;
	if (!_pObjBinary->GetBinary().Pack(env, offset, format, valListArg)) return false;
	if (forwardFlag) _offset = offset;
	return true;
}

Value PointerBinary::Unpack(Environment &env, bool forwardFlag,
						 const char *format, const ValueList &valListArg, bool exceedErrorFlag)
{
	size_t offset = _offset;
	Value value = _pObjBinary->GetBinary().Unpack(env, offset,
											format, valListArg, exceedErrorFlag);
	if (forwardFlag) _offset = offset;
	return value;
}

Iterator *PointerBinary::CreateUnpackIterator(const char *format, const ValueList &valList)
{
	Object_binary *pObj = dynamic_cast<Object_binary *>(_pObjBinary->Reference());
	return new Object_binary::IteratorUnpack(pObj, format, valList, GetOffset());
}

bool PointerBinary::UnpackForward(Environment &env, int distance, bool exceedErrorFlag)
{
	Signal &sig = env.GetSignal();
	return _pObjBinary->GetBinary().UnpackForward(sig, _offset, distance, exceedErrorFlag);
}

}
