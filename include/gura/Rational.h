//=============================================================================
// Rational
//=============================================================================
#ifndef __GURA_RATIONAL_H__
#define __GURA_RATIONAL_H__

namespace Gura {

//-----------------------------------------------------------------------------
// Rational
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Rational {
public:
	int numer;
	int denom;
public:
	static const Rational Zero;
public:
	inline Rational() : numer(0), denom(1) {}
	inline Rational(int numer_, int denom_) : numer(numer_), denom(denom_) {}
	inline Rational(const Rational &ratio) : numer(ratio.numer), denom(ratio.denom) {}
	Rational Reduce() const;
	String ToString() const;
	static Rational FromNumber(Number num);
	static void SetError_DenominatorZero(Signal &sig);
};

typedef std::vector<Rational> RationalList;
typedef std::deque<Rational> RationalDeque;

GURA_DLLDECLARE Rational operator+(const Rational &a);
GURA_DLLDECLARE Rational operator-(const Rational &a);
GURA_DLLDECLARE Rational operator+(const Rational &a, const Rational &b);
GURA_DLLDECLARE Rational operator-(const Rational &a, const Rational &b);
GURA_DLLDECLARE Rational operator*(const Rational &a, const Rational &b);
GURA_DLLDECLARE Rational operator/(const Rational &a, const Rational &b);
GURA_DLLDECLARE bool operator==(const Rational &a, const Rational &b);
GURA_DLLDECLARE bool operator!=(const Rational &a, const Rational &b);
GURA_DLLDECLARE bool operator<(const Rational &a, const Rational &b);
GURA_DLLDECLARE bool operator>(const Rational &a, const Rational &b);
GURA_DLLDECLARE bool operator<=(const Rational &a, const Rational &b);
GURA_DLLDECLARE bool operator>=(const Rational &a, const Rational &b);

}

#endif
