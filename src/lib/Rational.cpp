//=============================================================================
// Rational
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Rational
//-----------------------------------------------------------------------------
const Rational Rational::Zero;

Rational Rational::Reduce() const
{
	if (numer == 0 || denom == 0) return *this;
	int gcd = CalcGCD(numer, denom);
	int numerReduced = numer / gcd;
	int denomReduced = denom / gcd;
	if (denomReduced < 0) {
		numerReduced = -numerReduced;
		denomReduced = -denomReduced;
	}
	return Rational(numerReduced, denomReduced);
}

String Rational::ToString() const
{
	String str;
	str += NumberToString(numer);
	if (denom != 1) {
		str += "/";
		str += NumberToString(denom);
	}
	str += "r";
	return str;
}

Rational Rational::FromNumber(Number num)
{
	int numInt = int(num);
	if (num == numInt) return Rational(numInt, 1);
	//char buff[64];
	//::sprintf(buff, "%f", num);
	return Rational(0, 1);
}

void Rational::SetError_DenominatorZero(Signal &sig)
{
	sig.SetError(ERR_ZeroDivisionError, "denominator can't be zero");
}

Rational operator+(const Rational &a)
{
	if (a.denom < 0) return Rational(-a.numer, -a.denom);
	return a;
}

Rational operator-(const Rational &a)
{
	if (a.denom < 0) return Rational(a.numer, -a.denom);
	return Rational(-a.numer, a.denom);
}

Rational operator+(const Rational &a, const Rational &b)
{
	if (a.denom == 0 || b.denom == 0) return Rational::Zero;
	Rational rtn;
	if (a.denom == b.denom) {
		rtn.numer = a.numer + b.numer;
		rtn.denom = a.denom;
	} else {
		rtn.numer = a.numer * b.denom + b.numer * a.denom;
		rtn.denom = a.denom * b.denom;
	}
	return rtn.Reduce();
}

Rational operator-(const Rational &a, const Rational &b)
{
	if (a.denom == 0 || b.denom == 0) return Rational::Zero;
	Rational rtn;
	if (a.denom == b.denom) {
		rtn.numer = a.numer - b.numer;
		rtn.denom = a.denom;
	} else {
		rtn.numer = a.numer * b.denom - b.numer * a.denom;
		rtn.denom = a.denom * b.denom;
	}
	return rtn.Reduce();
}

Rational operator*(const Rational &a, const Rational &b)
{
	if (a.denom == 0 || b.denom == 0) return Rational::Zero;
	return Rational(a.numer * b.numer, a.denom * b.denom).Reduce();
}

Rational operator/(const Rational &a, const Rational &b)
{
	if (a.denom == 0 || b.numer == 0) return Rational::Zero;
	return Rational(a.numer * b.denom, a.denom * b.numer).Reduce();
}

bool operator==(const Rational &a, const Rational &b)
{
	int ax = a.numer * b.denom, bx = b.numer * a.denom;
	return ax == bx;
}

bool operator!=(const Rational &a, const Rational &b)
{
	int ax = a.numer * b.denom, bx = b.numer * a.denom;
	return ax != bx;
}

bool operator<(const Rational &a, const Rational &b)
{
	int ax = a.numer * b.denom, bx = b.numer * a.denom;
	return ax < bx;
}

bool operator>(const Rational &a, const Rational &b)
{
	int ax = a.numer * b.denom, bx = b.numer * a.denom;
	return ax > bx;
}

bool operator<=(const Rational &a, const Rational &b)
{
	int ax = a.numer * b.denom, bx = b.numer * a.denom;
	return ax <= bx;
}

bool operator>=(const Rational &a, const Rational &b)
{
	int ax = a.numer * b.denom, bx = b.numer * a.denom;
	return ax >=  bx;
}

}
