//=============================================================================
// Common
//=============================================================================
#include "stdafx.h"

extern "C" {
#include "../dSFMT-src-2.2.1/dSFMT.h"
}

namespace Gura {

const char *EXTNAME_Script		= ".gura";
const char *EXTNAME_ScriptWin	= ".guraw";
const char *EXTNAME_Compound	= ".gurc";
const char *EXTNAME_CompoundWin	= ".gurcw";
const char *EXTNAME_BinModule	= ".gurd";

const char *SRCNAME_unknown		= "<unknown>";
const char *SRCNAME_cmdline		= "<cmdline>";
const char *SRCNAME_interactive	= "<interactive>";
const char *SRCNAME_string		= "<string>";
const char *SRCNAME_dumb		= "<dumb>";
const char *SRCNAME_fifo		= "<fifo>";
const char *SRCNAME_memory		= "<memory>";

const int MAX_STACK_LEVEL = 20000;
const size_t InvalidSize = static_cast<size_t>(-1);

const Number Math_PI = 3.14159265358979323846;
const Number Math_E = 2.71828182845904523536;
const Number RoundOffThreshold = 1e-10;

const Complex Complex::Zero;
const Rational Rational::Zero;

bool IsBigEndian()
{
	long num = 0x12345678;
	return *reinterpret_cast<char *>(&num) == 0x12;
}

const char *GetVersion()
{
	return GURA_VERSION;
}

const char *GetOpening()
{
	static char buff[256];
#if defined(_MSC_VER)
	::sprintf(buff, "Gura %s [MSC v.%d, %s] %s",
				GURA_VERSION, _MSC_VER, __DATE__, GURA_COPYRIGHT);
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
	::sprintf(buff, "Gura %s [GNUC v.%d.%d, %s] %s",
				GURA_VERSION, __GNUC__, __GNUC_MINOR__, __DATE__, GURA_COPYRIGHT);
#else
	::sprintf(buff, "Gura %s [%s] %s",
				GURA_VERSION, __DATE__, GURA_COPYRIGHT);
#endif
	return buff;
}

//-----------------------------------------------------------------------------
// Rational
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// RandomGenerator
//-----------------------------------------------------------------------------
void RandomGenerator::Initialize(ULong seed)
{
	::dsfmt_gv_init_gen_rand(seed);	// initialize random generator dSFMT
}

double RandomGenerator::Real2()
{
	return ::dsfmt_gv_genrand_close_open();
}

int RandomGenerator::operator()(int n)
{
	return static_cast<int>(Real2() * n);
}

//-----------------------------------------------------------------------------
// Color
//-----------------------------------------------------------------------------
const Color Color::Zero;

const Color Color::Black(	  0,   0,   0, 255);
const Color Color::Maroon(	128,   0,   0, 255);
const Color Color::Green(	  0, 128,   0, 255);
const Color Color::Olive(	128, 128,   0, 255);
const Color Color::Navy(	  0,   0, 128, 255);
const Color Color::Purple(	128,   0, 128, 255);
const Color Color::Teal(	  0, 128, 128, 255);
const Color Color::Gray(	128, 128, 128, 255);
const Color Color::Silver(	192, 192, 192, 255);
const Color Color::Red(		255,   0,   0, 255);
const Color Color::Lime(	  0, 255,   0, 255);
const Color Color::Yellow(	255, 255,   0, 255);
const Color Color::Blue(	  0,   0, 255, 255);
const Color Color::Fuchsia(	255,   0, 255, 255);
const Color Color::Aqua(	  0, 255, 255, 255);
const Color Color::White(	255, 255, 255, 255);


}
