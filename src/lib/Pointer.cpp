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

bool Pointer::Advance(Environment &env, int distance, bool exceedErrorFlag)
{
	if (distance < 0) {
		if (_offset >= static_cast<size_t>(-distance)) {
			_offset += distance;
			return true;
		}
	} else {
		if (_offset + distance <= GetSize()) {
			_offset += distance;
			return true;
		}
	}
	if (exceedErrorFlag) {
		env.SetError(ERR_IndexError, "pointer exceeds the range of binary");
	}
	return false;
}

}
