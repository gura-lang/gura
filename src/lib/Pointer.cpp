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

bool Pointer::PutCharStay(Environment &env, Char num)
{
	size_t offset = _offset;
	if (!PutChar(env, num)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutUCharStay(Environment &env, UChar num)
{
	size_t offset = _offset;
	if (!PutUChar(env, num)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutShortStay(Environment &env, Short num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutShort(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutUShortStay(Environment &env, UShort num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutUShort(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutInt32Stay(Environment &env, Int32 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutInt32(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutUInt32Stay(Environment &env, UInt32 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutUInt32(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutInt64Stay(Environment &env, Int64 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutInt64(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutUInt64Stay(Environment &env, UInt64 num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutUInt64(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutFloatStay(Environment &env, float num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutFloat(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::PutDoubleStay(Environment &env, double num, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!PutDouble(env, num, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetCharStay(Environment &env, Char *pNum)
{
	size_t offset = _offset;
	if (!GetChar(env, pNum)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetUCharStay(Environment &env, UChar *pNum)
{
	size_t offset = _offset;
	if (!GetUChar(env, pNum)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetShortStay(Environment &env, Short *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetShort(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetUShortStay(Environment &env, UShort *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetUShort(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetInt32Stay(Environment &env, Int32 *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetInt32(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetUInt32Stay(Environment &env, UInt32 *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetUInt32(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetInt64Stay(Environment &env, Int64 *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetInt64(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetUInt64Stay(Environment &env, UInt64 *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetUInt64(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetFloatStay(Environment &env, float *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetFloat(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

bool Pointer::GetDoubleStay(Environment &env, double *pNum, bool bigEndianFlag)
{
	size_t offset = _offset;
	if (!GetDouble(env, pNum, bigEndianFlag)) return false;
	_offset = offset;
	return true;
}

//-----------------------------------------------------------------------------
// Pointer::IteratorUnpack
//-----------------------------------------------------------------------------
Pointer::IteratorUnpack::IteratorUnpack(Pointer *pPointer,
				const char *format, const ValueList &valListArg) :
		Iterator(false), _pPointer(pPointer), _format(format), _valListArg(valListArg)
{
}

Iterator *Pointer::IteratorUnpack::GetSource()
{
	return nullptr;
}

bool Pointer::IteratorUnpack::DoNext(Environment &env, Value &value)
{
	value = _pPointer->Unpack(env, _format.c_str(), _valListArg, false);
	return value.IsValid();
}

String Pointer::IteratorUnpack::ToString() const
{
	return String("pointer.unpacks");
}

void Pointer::IteratorUnpack::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
