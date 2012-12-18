#ifndef __GURA_ALGORITHM_H__
#define __GURA_ALGORITHM_H__

#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CRC32
//-----------------------------------------------------------------------------
class DLLDECLARE CRC32 {
private:
	unsigned long _crc32;
	size_t _bytes;
public:
	inline CRC32() : _crc32(0xffffffff), _bytes(0) {}
	inline void Initialize() { _crc32 = 0xffffffff, _bytes = 0; }
	void Update(const void *buff, size_t bytes);
	inline unsigned long GetResult() const { return ~_crc32; }
	inline size_t GetBytes() const { return _bytes; }
};

//DLLDECLARE unsigned long UpdateCRC32(unsigned long crc32, const void *buff, size_t bytes);

//-----------------------------------------------------------------------------
// FFT
//-----------------------------------------------------------------------------
DLLDECLARE void CalcFFT(ComplexList &vec);

//-----------------------------------------------------------------------------
// Inverse matrix
//-----------------------------------------------------------------------------
DLLDECLARE bool InverseMatrix(NumberList &mat, size_t nFold, Number &det);
DLLDECLARE bool InverseMatrix(ComplexList &mat, size_t nFold, Complex &det);

}

#endif
