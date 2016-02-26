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
bool PointerBinary::IsWritable() const
{
	return _pObjBinary->IsWritable();
}

bool PointerBinary::Pack(Environment &env, bool forwardFlag,
					  const char *format, const ValueList &valListArg)
{
	return false;
}

Value PointerBinary::Unpack(Environment &env, bool forwardFlag,
						 const char *format, const ValueList &valListArg, bool exeedErrorFlag)
{
	return Value::Nil;
}

bool PointerBinary::UnpackForward(Environment &env, int distance, bool exceedErrorFlag)
{
	return false;
}

}
