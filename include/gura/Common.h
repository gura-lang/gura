#ifndef __GURA_COMMON_H__
#define __GURA_COMMON_H__

#include "PackedNumber.h"

#define ArraySizeOf(array)				(sizeof(array) / sizeof(array[0]))

#define foreach(T, i, c)				for (T::iterator i = (c).begin(); i != (c).end(); i++)
#define foreach_const(T, i, c)			for (T::const_iterator i = (c).begin(); i != (c).end(); i++)
#define foreach_reverse(T, i, c)		for (T::reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)
#define foreach_const_reverse(T, i, c)	for (T::const_reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)

namespace Gura {

#define GURA_VERSION "0.4.0"

#if defined(_MSC_VER)
#define GURA_ON_MSWIN
#undef SetProp
#undef GetProp
#undef GetObject
#pragma warning(disable:4251)
#pragma warning(disable:4275)
#pragma warning(disable:4355)
#pragma warning(disable:4996)
#else
#define GURA_ON_LINUX
#endif

#if defined(GURA_ON_MSWIN)
#define GURA_DLLIMPORT __declspec(dllimport)
#define GURA_DLLEXPORT __declspec(dllexport)
#if defined(gura_EXPORTS)
#define GURA_DLLDECLARE __declspec(dllexport)
#else
#define GURA_DLLDECLARE __declspec(dllimport)
#endif
typedef __int64 int64;
typedef unsigned __int64 uint64;
#define strcasecmp stricmp
#define GURA_USE_MSWIN_DIB 1
#else
#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif
#define GURA_DLLIMPORT
#define GURA_DLLEXPORT
#define GURA_DLLDECLARE
typedef long long int64;
typedef unsigned long long uint64;
typedef void *HBITMAP;
#define GURA_USE_MSWIN_DIB 0
#endif

#define GURA_ASSUME(env, x) if (!(x)) { env.Error(__FILE__, __LINE__, #x); }
#define GURA_ERROREND(env, str) (env).Error(__FILE__, __LINE__, (str))

template<typename T>
inline T ChooseMin(T a, T b) { return (a < b)? a : b; }
template<typename T>
inline T ChooseMax(T a, T b) { return (a > b)? a : b; }

GURA_DLLDECLARE extern const int MAX_STACK_LEVEL;
GURA_DLLDECLARE extern const size_t InvalidSize;

GURA_DLLDECLARE bool IsBigEndian();
GURA_DLLDECLARE const char *GetVersion();
GURA_DLLDECLARE const char *GetOpening();

//-----------------------------------------------------------------------------
// Simple type declarations
//-----------------------------------------------------------------------------
typedef double Number;

GURA_DLLDECLARE extern const Number RoundOffThreshold;

typedef std::vector<char> CharList;
typedef std::vector<short> ShortList;
typedef std::vector<int> IntList;
typedef std::vector<long> LongList;
typedef std::vector<float> FloatList;
typedef std::vector<double> DoubleList;
typedef std::vector<unsigned char> UCharList;
typedef std::vector<unsigned short> UShortList;
typedef std::vector<unsigned int> UIntList;
typedef std::vector<unsigned long> ULongList;
typedef std::vector<Number> NumberList;

typedef std::deque<char> CharDeque;
typedef std::deque<short> ShortDeque;
typedef std::deque<int> IntDeque;
typedef std::deque<long> LongDeque;
typedef std::deque<float> FloatDeque;
typedef std::deque<double> DoubleDeque;
typedef std::deque<unsigned char> UCharDeque;
typedef std::deque<unsigned short> UShortDeque;
typedef std::deque<unsigned int> UIntDeque;
typedef std::deque<unsigned long> ULongDeque;
typedef std::deque<Number> NumberDeque;

//-----------------------------------------------------------------------------
// OccurPattern
//-----------------------------------------------------------------------------
enum OccurPattern {
	OCCUR_Invalid,
	OCCUR_Zero,			// (none)
	OCCUR_Once,			// 1
	OCCUR_ZeroOrOnce,	// ?
	OCCUR_ZeroOrMore,	// *
	OCCUR_OnceOrMore,	// +
};

//-----------------------------------------------------------------------------
// ResultMode
//-----------------------------------------------------------------------------
enum ResultMode {
	RSLTMODE_Normal,
	RSLTMODE_List,			// :list
	RSLTMODE_XList,			// :xlist
	RSLTMODE_Set,			// :set
	RSLTMODE_XSet,			// :xset
	RSLTMODE_Iterator,		// :iter
	RSLTMODE_XIterator,		// :xiter
	RSLTMODE_Void,			// :void
	RSLTMODE_Reduce,		// :reduce
	RSLTMODE_XReduce,		// :xreduce
};

//-----------------------------------------------------------------------------
// Flag
//-----------------------------------------------------------------------------
enum {
	FLAG_None			= 0,
	FLAG_Map			= (1 << 0),		// :map
	FLAG_Flat			= (1 << 1),		// :flat
	FLAG_Fork			= (1 << 2),		// :fork
	FLAG_DynamicScope	= (1 << 3),		// :dynamic_scope
	FLAG_SymbolFunc		= (1 << 4),		// :symbol_func
	FLAG_NoMap			= (1 << 5),		// :nomap
	FLAG_List			= (1 << 6),		// :list
	FLAG_Nil			= (1 << 7),		// :nil
	FLAG_Read			= (1 << 8),		// :r
	FLAG_Write			= (1 << 9),		// :w
	FLAG_NoCast			= (1 << 10),	// :nocast
	FLAG_Leader			= (1 << 11),	// :leader
	FLAG_Trailer		= (1 << 12),	// :trailer
	FLAG_EndMarker		= (1 << 13),	// :end_marker
	FLAG_Public			= (1 << 14),	// :public
	FLAG_Private		= (1 << 15),	// :private
	FLAG_Privileged		= (1 << 16),	// :privileged
};

//-----------------------------------------------------------------------------
// Extra
//-----------------------------------------------------------------------------
enum {
	EXTRA_None			= 0,
	EXTRA_Public		= (1 << 0),
};

//-----------------------------------------------------------------------------
// AutoPtr
// The destroyer executes "T::Delete(p)" instead of "delete p".
// Class T must have a static function named Delete() that deletes the pointed
// object in the argument.
//-----------------------------------------------------------------------------
template<typename T> class AutoPtr {
private:
	T *_p;
public:
	inline AutoPtr(T *p = NULL) : _p(p) {}
	inline ~AutoPtr() { T::Delete(_p); }
	inline T &operator*() { return *_p; }
	inline T &operator*() const { return *_p; }
	inline T *operator->() { return _p; }
	inline T *operator->() const { return _p; }
	inline void reset(T *p) { T::Delete(_p); _p = p; }
	inline T *get() { return _p; }
	inline T *get() const { return _p; }
	inline T *release() { T *p = _p; _p = NULL; return p; }
	inline bool IsNull() const { return _p == NULL; }
	inline T *Reference() const { return T::Reference(_p); }
private:
	inline void operator=(const T *p) {}
};

//-----------------------------------------------------------------------------
// String
//-----------------------------------------------------------------------------
typedef std::basic_string<char> String;
typedef std::deque<String> StringDeque;

//-----------------------------------------------------------------------------
// Complex
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Complex : public std::complex<Number> {
public:
	static const Complex Zero;
public:
	inline Complex() : std::complex<Number>(0.) {}
	inline Complex(const Complex &comp) : std::complex<Number>(comp) {}
	inline Complex(const std::complex<Number> &comp) : std::complex<Number>(comp) {}
	inline Complex(Number real) : std::complex<Number>(real) {}
	inline Complex(Number real, Number imag) : std::complex<Number>(real, imag) {}
};

typedef std::vector<Complex> ComplexList;
typedef std::deque<Complex> ComplexDeque;

//-----------------------------------------------------------------------------
// Fraction
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Fraction {
public:
	Number numerator;
	Number denominator;
public:
	static const Fraction Zero;
public:
	inline Fraction() : numerator(0), denominator(1) {}
	inline Fraction(Number numerator_, Number denominator_) :
			numerator(numerator_), denominator(denominator_) {}
	inline Fraction(const Fraction &frac) :
			numerator(frac.numerator), denominator(frac.denominator) {}
};

typedef std::vector<Fraction> FractionList;
typedef std::deque<Fraction> FractionDeque;

//-----------------------------------------------------------------------------
// RandomGenerator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE RandomGenerator {
public:
	static void Initialize(unsigned long seed);
	static double Real2();
	int operator()(int n);
};

//-----------------------------------------------------------------------------
// Data structure for Windows BMP format
//-----------------------------------------------------------------------------
struct BitmapFileHeader {
	enum { Size = 14 };
	Gura_PackedUShort_LE(bfType);
	Gura_PackedULong_LE(bfSize);
	Gura_PackedUShort_LE(bfReserved1);
	Gura_PackedUShort_LE(bfReserved2);
	Gura_PackedULong_LE(bfOffBits);
};

struct BitmapInfoHeader {
	enum { Size = 40 };
	Gura_PackedULong_LE(biSize);
	Gura_PackedLong_LE(biWidth);
	Gura_PackedLong_LE(biHeight);
	Gura_PackedUShort_LE(biPlanes);
	Gura_PackedUShort_LE(biBitCount);
	Gura_PackedULong_LE(biCompression);
	Gura_PackedULong_LE(biSizeImage);
	Gura_PackedLong_LE(biXPelsPerMeter);
	Gura_PackedLong_LE(biYPelsPerMeter);
	Gura_PackedULong_LE(biClrUsed);
	Gura_PackedULong_LE(biClrImportant);
};

//-----------------------------------------------------------------------------
// Color
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Color {
private:
	unsigned char _red, _green, _blue, _alpha;
public:
	static const Color Zero;
public:
	inline Color() : _red(0), _green(0), _blue(0), _alpha(0) {}
	inline Color(const Color &color) : _red(color._red), _green(color._green),
					_blue(color._blue), _alpha(color._alpha) {}
	inline Color(unsigned char red, unsigned char green, unsigned char blue) :
					_red(red), _green(green), _blue(blue), _alpha(0) {}
	inline Color(unsigned char red, unsigned char green, unsigned char blue, unsigned alpha) :
					_red(red), _green(green), _blue(blue), _alpha(alpha) {}
	inline unsigned char GetRed() const { return _red; }
	inline unsigned char GetGreen() const { return _green; }
	inline unsigned char GetBlue() const { return _blue; }
	inline unsigned char GetAlpha() const { return _alpha; }
	inline void SetRed(unsigned char red) { _red = red; }
	inline void SetGreen(unsigned char green) { _green = green; }
	inline void SetBlue(unsigned char blue) { _blue = blue; }
	inline void SetAlpha(unsigned char alpha) { _alpha = alpha; }
	inline unsigned char GetGray() const {
		return CalcGray(GetRed(), GetGreen(), GetBlue());
	}
	inline unsigned long GetARGB() const {
		return
			(static_cast<unsigned long>(GetAlpha()) << 24) +
			(static_cast<unsigned long>(GetRed()) << 16) +
			(static_cast<unsigned long>(GetGreen()) << 8) +
			(static_cast<unsigned long>(GetBlue()) << 0);
	}
	inline unsigned long GetABGR() const {
		return
			(static_cast<unsigned long>(GetAlpha()) << 24) +
			(static_cast<unsigned long>(GetBlue()) << 16) +
			(static_cast<unsigned long>(GetGreen()) << 8) +
			(static_cast<unsigned long>(GetRed()) << 0);
	}
	inline unsigned long GetRGB() const {
		return
			(static_cast<unsigned long>(GetRed()) << 16) +
			(static_cast<unsigned long>(GetGreen()) << 8) +
			(static_cast<unsigned long>(GetBlue()) << 0);
	}
	inline unsigned long GetBGR() const {
		return
			(static_cast<unsigned long>(GetBlue()) << 16) +
			(static_cast<unsigned long>(GetGreen()) << 8) +
			(static_cast<unsigned long>(GetRed()) << 0);
	}
	inline bool operator<(const Color &c) const { return GetRGB() < c.GetRGB(); }
	inline size_t CalcDist(unsigned char red, unsigned char green, unsigned char blue) const {
		return CalcDist(GetRed(), GetGreen(), GetBlue(), red, green, blue);
	}
	inline size_t CalcDist(const Color &c) const {
		return CalcDist(GetRed(), GetGreen(), GetBlue(), c.GetRed(), c.GetGreen(), c.GetBlue());
	}
	inline String GetHTML() const {
		char buff[32];
		::sprintf(buff, "#%06lx", GetRGB());
		return String(buff);
	}
	static inline size_t CalcDist(
				unsigned char red1, unsigned char green1, unsigned char blue1,
				unsigned char red2, unsigned char green2, unsigned char blue2) {
		long distR = static_cast<long>(red1) - static_cast<long>(red2);
		long distG = static_cast<long>(green1) - static_cast<long>(green2);
		long distB = static_cast<long>(blue1) - static_cast<long>(blue2);
		return distR * distR + distG * distG + distB * distB;
	}
	// revise this equation to convert a color into gray scale.
	static inline unsigned char CalcGray(unsigned char red, unsigned char green, unsigned char blue) {
		return static_cast<unsigned char>(
			(static_cast<unsigned long>(red) * 299 +
			 static_cast<unsigned long>(green) * 587 +
			 static_cast<unsigned long>(blue) * 114) / 1000);
	}
};

typedef std::vector<Color> ColorList;
typedef std::deque<Color> ColorDeque;
typedef std::set<Color> ColorSet;

}
#endif
