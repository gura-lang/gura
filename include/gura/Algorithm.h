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
GURA_DLLDECLARE Int64 CalcGCD(Int64 a, Int64 b);
GURA_DLLDECLARE Int64 CalcLCM(Int64 a, Int64 b);

//-----------------------------------------------------------------------------
// CRC32
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CRC32 {
private:
	UInt32 _crc32;
	size_t _bytes;
public:
	inline CRC32() : _crc32(0xffffffff), _bytes(0) {}
	inline void Initialize() { _crc32 = 0xffffffff, _bytes = 0; }
	void Update(const void *buff, size_t bytes);
	inline UInt32 GetResult() const { return ~_crc32 & 0xffffffff; }
	inline size_t GetBytes() const { return _bytes; }
};

}

#endif
