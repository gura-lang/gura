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

template<typename T_Elem> inline Double _CalcInvError(const T_Elem &num)
{
	return std::abs(static_cast<Double>(num));
}

template<> inline Double _CalcInvError<Complex>(const Complex &num)
{
	return std::norm(num);
}

template<typename T_Elem> inline Double _CalcInvErrorThreshold(Double epsilon)
{
	return epsilon;
}

template<> inline Double _CalcInvErrorThreshold<Complex>(Double epsilon)
{
	return epsilon * epsilon;
}

template<typename T_Elem>
bool InvertFuncTmpl_Sub(T_Elem *pElemResult, const T_Elem *pElemOrg, size_t nRows,
						T_Elem &det, T_Elem *pElemWork, T_Elem *rows[], Double epsilon)
{
	static const Double invErrThreshold = _CalcInvErrorThreshold<T_Elem>(epsilon);
	size_t nCols = nRows;
	size_t nCols2 = nCols * 2;
	size_t bytesPerRow = nCols * sizeof(T_Elem);
	det = 1;
	do {
		const T_Elem *pElemSrc = pElemOrg;
		T_Elem *pElemDst = pElemWork;
		::memset(pElemWork, 0x00, nRows * nCols2 * sizeof(T_Elem));
		for (size_t iRow = 0; iRow < nRows; iRow++, pElemDst += nCols2, pElemSrc += nCols) {
			::memcpy(pElemDst, pElemSrc, bytesPerRow);
			*(pElemDst + nCols + iRow) = 1;
			rows[iRow] = pElemDst;
		}
	} while (0);
	for (size_t iRowPivot = 0; iRowPivot < nRows; iRowPivot++) {
		size_t iRowMax = iRowPivot;
		Double invErrMax = _CalcInvError<T_Elem>(rows[iRowMax][iRowPivot]);
		for (size_t iRow = iRowMax + 1; iRow < nRows; iRow++) {
			Double invErr = _CalcInvError<T_Elem>(rows[iRow][iRowPivot]);
			if (invErrMax < invErr) {
				iRowMax = iRow;
				invErrMax = invErr;
			}
		}
		if (invErrMax < invErrThreshold) {
			det = 0;
			return false;
		}
		if (iRowPivot != iRowMax) {
			std::swap(rows[iRowPivot], rows[iRowMax]);
			det = -det;
		}
		do {
			T_Elem *pElemPivot = rows[iRowPivot];
			T_Elem factor = *(pElemPivot + iRowPivot);
			det *= factor;
			for (size_t cnt = nCols2; cnt > 0; cnt--, pElemPivot++) {
				*pElemPivot /= factor;
			}
		} while (0);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			if (iRowPivot == iRow) continue;
			T_Elem *pElemPivot = rows[iRowPivot];
			T_Elem *pElemEach = rows[iRow];
			T_Elem factor = *(pElemEach + iRowPivot);
			for (size_t cnt = nCols2; cnt > 0; cnt--, pElemPivot++, pElemEach++) {
				*pElemEach -= *pElemPivot * factor;
			}
		}
	}
	if (pElemResult != nullptr) {
		T_Elem *pElemDst = pElemResult;
		for (size_t iRow = 0; iRow < nRows; iRow++, pElemDst += nCols) {
			::memcpy(pElemDst, rows[iRow] + nCols, bytesPerRow);
		}
	}
	return true;
}

}

#endif
