//=============================================================================
// Algorithm
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// GCD/LCM
//-----------------------------------------------------------------------------
int CalcGCD(int a, int b)
{
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a == b) return a;
	int left = a, right = b;
	if (a < b) {
		left = b, right = a;
	}
	int gcd = right;
	for (;;) {
		int div = left / right;
		int rest = left - div * right;
		if (rest == 0) break;
		gcd = rest;
		left = right, right = rest;
	}
	return gcd;
}

int CalcLCM(int a, int b)
{
	return a * b / CalcGCD(a, b);
}

//-----------------------------------------------------------------------------
// CRC32
//-----------------------------------------------------------------------------
void CRC32::Update(const void *buff, size_t bytes)
{
	static ULong *tbl = nullptr;
	if (tbl == nullptr) {
		const ULong CRC32_POLY = 0xedb88320; // CRC-32-IEEE 802.3
		tbl = new ULong [256];
		for (ULong i = 0; i < 256; i++){
			ULong x = i;
			for (int j = 0; j < 8; j++) {
				x = (x & 1)? ((x >> 1) ^ CRC32_POLY) : (x >> 1);
				tbl[i] = x;
			}
		}
	}
	const UChar *buffp = reinterpret_cast<const UChar *>(buff);
	for (size_t i = 0; i < bytes; i++, buffp++) {
		_crc32 = ((_crc32 >> 8) & 0x00ffffff) ^ tbl[(_crc32 ^ *buffp) & 0xff];
	}
	_bytes += bytes;
}

}
