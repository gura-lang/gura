//=============================================================================
// Pointer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Pointer
//-----------------------------------------------------------------------------
Pointer::Pointer(size_t offset) : _offset(offset)
{
}

Pointer::~Pointer()
{
}

bool Pointer::Advance(Environment &env, int distance)
{
	if (distance >= 0) {
		_offset += distance;
		return true;
	}
	if (_offset >= static_cast<size_t>(-distance)) {
		_offset += distance;
		return true;
	}
	env.SetError(ERR_IndexError, "pointer offset becomes negative");
	return false;
}

bool Pointer::PackStay(Environment &env, const char *format, const ValueList &valListArg)
{
	size_t offset = _offset;
	if (!Pack(env, format, valListArg)) return false;
	_offset = offset;
	return true;
}

Value Pointer::UnpackStay(Environment &env, const char *format,
						  const ValueList &valListArg, bool exceedErrorFlag)
{
	size_t offset = _offset;
	Value value = Unpack(env, format, valListArg, exceedErrorFlag);
	_offset = offset;
	return value;
}

#if 0
bool Pointer::PutCharStay(Environment &env, Char num)
{
	size_t offset = _offset;
	bool rtn = PutChar(env, num);
	_offset = offset;
	return rtn;
}

bool Pointer::PutUCharStay(Environment &env, UChar num)
{
	size_t offset = _offset;
	bool rtn = PutUChar(env, num);
	_offset = offset;
	return rtn;
}

bool Pointer::PutShortStay(Environment &env, Short num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutShort(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::PutUShortStay(Environment &env, UShort num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutUShort(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::PutInt32Stay(Environment &env, Int32 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutInt32(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::PutUInt32Stay(Environment &env, UInt32 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutUInt32(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::PutInt64Stay(Environment &env, Int64 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutInt64(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::PutUInt64Stay(Environment &env, UInt64 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutUInt64(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::PutFloatStay(Environment &env, float num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutFloat(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::PutDoubleStay(Environment &env, double num, bool bigEndianFlag)
{
	size_t offset = _offset;
	bool rtn = PutDouble(env, num, bigEndianFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetCharStay(Environment &env, Char *pNum, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetChar(env, pNum, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetUCharStay(Environment &env, UChar *pNum, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetUChar(env, pNum, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetShortStay(Environment &env, Short *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetShort(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetUShortStay(Environment &env, UShort *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetUShort(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetInt32Stay(Environment &env, Int32 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetInt32(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetUInt32Stay(Environment &env, UInt32 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetUInt32(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetInt64Stay(Environment &env, Int64 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetInt64(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetUInt64Stay(Environment &env, UInt64 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetUInt64(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetFloatStay(Environment &env, float *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetFloat(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}

bool Pointer::GetDoubleStay(Environment &env, double *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	size_t offset = _offset;
	bool rtn = GetDouble(env, pNum, bigEndianFlag, exceedErrorFlag);
	_offset = offset;
	return rtn;
}
#endif

}
