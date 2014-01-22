//=============================================================================
// Complex
//=============================================================================
#ifndef __GURA_COMPLEX_H__
#define __GURA_COMPLEX_H__

namespace Gura {

//-----------------------------------------------------------------------------
// Complex
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Complex : public std::complex<double> {
public:
	static const Complex Zero;
public:
	inline Complex() : std::complex<double>(0.) {}
	inline Complex(const Complex &comp) : std::complex<double>(comp) {}
	inline Complex(const std::complex<double> &comp) : std::complex<double>(comp) {}
	inline Complex(double real) : std::complex<double>(real) {}
	inline Complex(double real, double imag) : std::complex<double>(real, imag) {}
	inline bool IsZero() const { return real() == 0 && imag() == 0; }
	inline static Complex Polar(double abs, double arg) {
		return Complex(abs * ::cos(arg), abs * ::sin(arg));
	}
};

typedef std::vector<Complex> ComplexList;
typedef std::deque<Complex> ComplexDeque;

}

#endif
