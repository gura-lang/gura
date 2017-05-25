//=============================================================================
// Half
// Implementation of IEEE754 format
// This implementation owes much to the project:
//   https://sourceforge.net/projects/csharp-half/
//=============================================================================
#include "stdafx.h"
#include "gura/Half.h"


namespace Gura {

UInt32 Half::_mantissaTable[2048];
UInt32 Half::_exponentTable[64];
UInt16 Half::_offsetTable[64];
UInt16 Half::_baseTable[512];
Int8 Half::_shiftTable[512];

Float Half::HalfToFloat(UInt16 num)
{
	UInt32 result = _mantissaTable[_offsetTable[num >> 10] + (num & 0x3ff)] +
		_exponentTable[num >> 10];
	return *reinterpret_cast<Float *>(&result);
}

UInt16 Half::FloatToHalf(Float num)
{
	UInt32 t = *reinterpret_cast<UInt32 *>(&num);
	return (UInt16)(_baseTable[(t >> 23) & 0x1ff] + ((t & 0x007fffff) >> _shiftTable[t >> 23]));
}

void Half::Bootup()
{
	GenerateMantissaTable();
	GenerateExponentTable();
	GenerateOffsetTable();
	GenerateBaseTable();
	GenerateShiftTable();
}

UInt32 Half::ConvertMantissa(int i)
{
	UInt32 m = static_cast<UInt32>(i << 13); // Zero pad mantissa bits
	UInt32 e = 0; // Zero exponent
	
	// While not normalized
	while ((m & 0x00800000) == 0) {
		e -= 0x00800000; // Decrement exponent (1<<23)
		m <<= 1; // Shift mantissa                
	}
	m &= static_cast<UInt32>(~0x00800000); // Clear leading 1 bit
	e += 0x38800000; // Adjust bias ((127-14)<<23)
	return m | e; // Return combined number
}

void Half::GenerateMantissaTable()
{
	_mantissaTable[0] = 0;
	for (int i = 1; i < 1024; i++) {
		_mantissaTable[i] = ConvertMantissa(i);
	}
	for (int i = 1024; i < 2048; i++) {
		_mantissaTable[i] = static_cast<UInt32>(0x38000000 + ((i - 1024) << 13));
	}
}

void Half::GenerateExponentTable()
{
	_exponentTable[0] = 0;
	for (int i = 1; i < 31; i++) {
		_exponentTable[i] = static_cast<UInt32>(i << 23);
	}
	_exponentTable[31] = 0x47800000;
	_exponentTable[32] = 0x80000000;
	for (int i = 33; i < 63; i++) {
		_exponentTable[i] = static_cast<UInt32>(0x80000000 + ((i - 32) << 23));
	}
	_exponentTable[63] = 0xc7800000;
}

void Half::GenerateOffsetTable()
{
	_offsetTable[0] = 0;
	for (int i = 1; i < 32; i++) {
		_offsetTable[i] = 1024;
	}
	_offsetTable[32] = 0;
	for (int i = 33; i < 64; i++) {
		_offsetTable[i] = 1024;
	}
}

void Half::GenerateBaseTable()
{
	for (int i = 0; i < 256; i++) {
		Int8 e = static_cast<Int8>(127 - i);
		if (e > 24) {
			// Very small numbers map to zero
			_baseTable[i | 0x000] = 0x0000;
			_baseTable[i | 0x100] = 0x8000;
		} else if (e > 14) {
			// Small numbers map to denorms
			_baseTable[i | 0x000] = static_cast<UInt16>(0x0400 >> (18 + e));
			_baseTable[i | 0x100] = static_cast<UInt16>((0x0400 >> (18 + e)) | 0x8000);
		} else if (e >= -15) {
			// Normal numbers just lose precision
			_baseTable[i | 0x000] = static_cast<UInt16>((15 - e) << 10);
			_baseTable[i | 0x100] = static_cast<UInt16>(((15 - e) << 10) | 0x8000);
		} else if (e > -128) {
			// Large numbers map to Infinity
			_baseTable[i | 0x000] = 0x7c00;
			_baseTable[i | 0x100] = 0xfc00;
		} else {
			// Infinity and NaN's stay Infinity and NaN's
			_baseTable[i | 0x000] = 0x7c00;
			_baseTable[i | 0x100] = 0xfc00;
		}
	}
}

void Half::GenerateShiftTable()
{
	for (int i = 0; i < 256; i++) {
		Int8 e = static_cast<Int8>(127 - i);
		if (e > 24) {
			// Very small numbers map to zero
			_shiftTable[i | 0x000] = 24;
			_shiftTable[i | 0x100] = 24;
		} else if (e > 14) {
			// Small numbers map to denorms
			_shiftTable[i | 0x000] = static_cast<Int8>(e - 1);
			_shiftTable[i | 0x100] = static_cast<Int8>(e - 1);
		} else if (e >= -15) {
			// Normal numbers just lose precision
			_shiftTable[i | 0x000] = 13;
			_shiftTable[i | 0x100] = 13;
		} else if (e > -128) {
			// Large numbers map to Infinity
			_shiftTable[i | 0x000] = 24;
			_shiftTable[i | 0x100] = 24;
		} else {
			// Infinity and NaN's stay Infinity and NaN's
			_shiftTable[i | 0x000] = 13;
			_shiftTable[i | 0x100] = 13;
		}
	}
}

}
