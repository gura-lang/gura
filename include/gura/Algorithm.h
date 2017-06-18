//=============================================================================
// Algorithm
//=============================================================================
#ifndef __GURA_ALGORITHM_H__
#define __GURA_ALGORITHM_H__

#include "Common.h"
#include "Complex.h"

namespace Gura {

//-----------------------------------------------------------------------------
// simple functions
//-----------------------------------------------------------------------------
inline double RadToDeg(double n) { return 180 * n / Math_PI; }
inline double DegToRad(double n) { return Math_PI * n / 180; }

//-----------------------------------------------------------------------------
// GCD/LCM
//-----------------------------------------------------------------------------
GURA_DLLDECLARE int CalcGCD(int a, int b);
GURA_DLLDECLARE int CalcLCM(int a, int b);

//-----------------------------------------------------------------------------
// CRC32
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CRC32 {
private:
	ULong _crc32;
	size_t _bytes;
public:
	inline CRC32() : _crc32(0xffffffff), _bytes(0) {}
	inline void Initialize() { _crc32 = 0xffffffff, _bytes = 0; }
	void Update(const void *buff, size_t bytes);
	inline ULong GetResult() const { return ~_crc32 & 0xffffffff; }
	inline size_t GetBytes() const { return _bytes; }
};

//-----------------------------------------------------------------------------
// Invert matrix
//-----------------------------------------------------------------------------
GURA_DLLDECLARE bool InvertMatrix(NumberList &mat, size_t nFold, Number &det);
GURA_DLLDECLARE bool InvertMatrix(ComplexList &mat, size_t nFold, Complex &det);

}

#endif
