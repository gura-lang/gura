#include "stdafx.h"

namespace Gura {

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
	static unsigned long *tbl = NULL;
	if (tbl == NULL) {
		const unsigned long CRC32_POLY = 0xedb88320; // CRC-32-IEEE 802.3
		tbl = new unsigned long [256];
		for (unsigned long i = 0; i < 256; i++){
			unsigned long x = i;
			for (int j = 0; j < 8; j++) {
				x = (x & 1)? ((x >> 1) ^ CRC32_POLY) : (x >> 1);
				tbl[i] = x;
			}
		}
	}
	const unsigned char *buffp = reinterpret_cast<const unsigned char *>(buff);
	for (size_t i = 0; i < bytes; i++, buffp++) {
		_crc32 = ((_crc32 >> 8) & 0x00ffffff) ^ tbl[(_crc32 ^ *buffp) & 0xff];
	}
	_bytes += bytes;
}

//-----------------------------------------------------------------------------
// FFT
//-----------------------------------------------------------------------------
void CalcFFT(ComplexList &vec)
{
	
}

//-----------------------------------------------------------------------------
// Invert matrix
//-----------------------------------------------------------------------------
static const Number Epsilon = 1.0e-6;

bool InvertMatrix(NumberList &mat, size_t nFold, Number &det)
{
	size_t nFold2 = nFold * 2;
	typedef std::vector<NumberList::iterator> Rows;
	Rows rows;
	size_t offset = 0;
	det = 1.;
	for (size_t iRow = 0; iRow < nFold; iRow++, offset += nFold2) {
		rows.push_back(mat.begin() + offset);
	}
	for (size_t iPivot = 0; iPivot < nFold; iPivot++) {
		size_t iRowMax = iPivot;
		Number nMax = ::fabs(*(rows[iRowMax] + iPivot));
		for (size_t iRow = iRowMax + 1; iRow < nFold; iRow++) {
			Number n = ::fabs(*(rows[iRow] + iPivot));
			if (nMax < n) {
				iRowMax = iRow;
				nMax = n;
			}
		}
		if (nMax < Epsilon) return false;
		if (iPivot != iRowMax) {
			NumberList::iterator p1 = rows[iPivot];
			NumberList::iterator p2 = rows[iRowMax];
			for (size_t cnt = nFold2; cnt > 0; cnt--, p1++, p2++) {
				std::swap(*p1, *p2);
			}
			det = -det;
		}
		NumberList::iterator p_i = rows[iPivot];
		Number n = *(p_i + iPivot);
		det *= n;
		for (size_t cnt = nFold2; cnt > 0; cnt--, p_i++) {
			*p_i /= n;
		}
		for (size_t j = 0; j < nFold; j++) {
			if (iPivot == j) continue;
			NumberList::iterator p_i = rows[iPivot], p_j = rows[j];
			Number factor = *(p_j + iPivot);
			for (size_t cnt = nFold2; cnt > 0; cnt--, p_i++, p_j++) {
				*p_j -= *p_i * factor;
			}
		}
	}
	return true;
}

bool InvertMatrix(ComplexList &mat, size_t nFold, Complex &det)
{
	size_t nFold2 = nFold * 2;
	typedef std::vector<ComplexList::iterator> Rows;
	Rows rows;
	size_t offset = 0;
	for (size_t iRow = 0; iRow < nFold; iRow++, offset += nFold2) {
		rows.push_back(mat.begin() + offset);
	}
	det = 1.;
	for (size_t iPivot = 0; iPivot < nFold; iPivot++) {
		size_t iRowMax = iPivot;
		Number nMax = std::abs(*(rows[iRowMax] + iPivot));
		for (size_t iRow = iRowMax + 1; iRow < nFold; iRow++) {
			Number n = std::abs(*(rows[iRow] + iPivot));
			if (nMax < n) {
				iRowMax = iRow;
				nMax = n;
			}
		}
		if (nMax < Epsilon) return false;
		if (iPivot != iRowMax) {
			ComplexList::iterator p1 = rows[iPivot];
			ComplexList::iterator p2 = rows[iRowMax];
			for (size_t cnt = nFold2; cnt > 0; cnt--, p1++, p2++) {
				std::swap(*p1, *p2);
			}
			det = -det;
		}
		ComplexList::iterator p_i = rows[iPivot];
		Complex n = *(p_i + iPivot);
		det *= n;
		for (size_t cnt = nFold2; cnt > 0; cnt--, p_i++) {
			*p_i /= n;
		}
		for (size_t j = 0; j < nFold; j++) {
			if (iPivot == j) continue;
			ComplexList::iterator p_i = rows[iPivot], p_j = rows[j];
			Complex factor = *(p_j + iPivot);
			for (size_t cnt = nFold2; cnt > 0; cnt--, p_i++, p_j++) {
				*p_j -= *p_i * factor;
			}
		}
	}
	return true;
}

}
