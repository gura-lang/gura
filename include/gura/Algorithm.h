#ifndef __GURA_ALGORITHM_H__
#define __GURA_ALGORITHM_H__

#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CRC32
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CRC32 {
private:
	unsigned long _crc32;
	size_t _bytes;
public:
	inline CRC32() : _crc32(0xffffffff), _bytes(0) {}
	inline void Initialize() { _crc32 = 0xffffffff, _bytes = 0; }
	void Update(const void *buff, size_t bytes);
	inline unsigned long GetResult() const { return ~_crc32 & 0xffffffff; }
	inline size_t GetBytes() const { return _bytes; }
};

//GURA_DLLDECLARE unsigned long UpdateCRC32(unsigned long crc32, const void *buff, size_t bytes);

//-----------------------------------------------------------------------------
// FFT
//-----------------------------------------------------------------------------
GURA_DLLDECLARE void CalcFFT(ComplexList &vec);

//-----------------------------------------------------------------------------
// Invert matrix
//-----------------------------------------------------------------------------
GURA_DLLDECLARE bool InvertMatrix(NumberList &mat, size_t nFold, Number &det);
GURA_DLLDECLARE bool InvertMatrix(ComplexList &mat, size_t nFold, Complex &det);

}

#endif
