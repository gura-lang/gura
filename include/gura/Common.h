#ifndef __GURA_COMMON_H__
#define __GURA_COMMON_H__

#include "Version.h"
#include "PackedNumber.h"

#define ArraySizeOf(array)				(sizeof(array) / sizeof(array[0]))

#define foreach(T, i, c)				for (T::iterator i = (c).begin(); i != (c).end(); i++)
#define foreach_const(T, i, c)			for (T::const_iterator i = (c).begin(); i != (c).end(); i++)
#define foreach_reverse(T, i, c)		for (T::reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)
#define foreach_const_reverse(T, i, c)	for (T::const_reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)

namespace Gura {

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

#define Gura_DeclareReferenceAccessor(T) \
inline static T *Reference(const T *p) { \
	if (p == NULL) return NULL; \
	T *pCasted = const_cast<T *>(p); \
	pCasted->_cntRef++; \
	return pCasted; \
} \
inline T *Reference() const { return Reference(this); } \
inline static void Delete(T *p) { \
	if (p == NULL) return; \
	p->_cntRef--; \
	if (p->_cntRef <= 0) delete p; \
}

class Signal;

//-----------------------------------------------------------------------------
// Simple type declarations
//-----------------------------------------------------------------------------
typedef double Number;

GURA_DLLDECLARE extern const char *EXTNAME_Script;
GURA_DLLDECLARE extern const char *EXTNAME_ScriptWin;
GURA_DLLDECLARE extern const char *EXTNAME_Compound;
GURA_DLLDECLARE extern const char *EXTNAME_CompoundWin;
GURA_DLLDECLARE extern const char *EXTNAME_BinModule;

GURA_DLLDECLARE extern const char *SRCNAME_unknown;
GURA_DLLDECLARE extern const char *SRCNAME_cmdline;
GURA_DLLDECLARE extern const char *SRCNAME_interactive;
GURA_DLLDECLARE extern const char *SRCNAME_string;
GURA_DLLDECLARE extern const char *SRCNAME_dumb;
GURA_DLLDECLARE extern const char *SRCNAME_fifo;
GURA_DLLDECLARE extern const char *SRCNAME_memory;

GURA_DLLDECLARE extern const double Math_PI;
GURA_DLLDECLARE extern const double Math_E;
GURA_DLLDECLARE extern const double RoundOffThreshold;

typedef int					Int;		// signed native bits
typedef char				Char;		// signed 8bit
typedef short				Short;		// signed 16bit
typedef long				Long;		// signed 32bit
typedef int64				Int64;		// signed 64bit
typedef unsigned int		UInt;		// unsigned native bits
typedef unsigned char		UChar;		// unsigned 8bit
typedef unsigned short		UShort;		// unsigned 16bit
typedef unsigned long		ULong;		// unsigned 32bit
typedef uint64				UInt64;		// unsigned 64bit

typedef std::vector<char>	CharList;
typedef std::vector<short>	ShortList;
typedef std::vector<int>	IntList;
typedef std::vector<long>	LongList;
typedef std::vector<float>	FloatList;
typedef std::vector<double>	DoubleList;
typedef std::vector<UChar>	UCharList;
typedef std::vector<UShort>	UShortList;
typedef std::vector<UInt>	UIntList;
typedef std::vector<ULong>	ULongList;
typedef std::vector<Number>	NumberList;

typedef std::deque<char>	CharDeque;
typedef std::deque<short>	ShortDeque;
typedef std::deque<int>		IntDeque;
typedef std::deque<long>	LongDeque;
typedef std::deque<float>	FloatDeque;
typedef std::deque<double>	DoubleDeque;
typedef std::deque<UChar>	UCharDeque;
typedef std::deque<UShort>	UShortDeque;
typedef std::deque<UInt>	UIntDeque;
typedef std::deque<ULong>	ULongDeque;
typedef std::deque<Number>	NumberDeque;

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
	FLAG_Finalizer		= (1 << 13),	// :finalizer
	FLAG_EndMarker		= (1 << 14),	// :end_marker
	FLAG_Public			= (1 << 15),	// :public
	FLAG_Private		= (1 << 16),	// :private
	FLAG_Privileged		= (1 << 17),	// :privileged
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

class GURA_DLLDECLARE StringRef {
private:
	int _cntRef;
	String _str;
public:
	Gura_DeclareReferenceAccessor(StringRef)
public:
	inline StringRef() : _cntRef(1) {}
	inline StringRef(const String &str) : _cntRef(1), _str(str) {}
private:
	inline ~StringRef() {}
public:
	inline const char *GetString() const { return _str.c_str(); }
	inline const String &GetStringSTL() const { return _str; }
};

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

//-----------------------------------------------------------------------------
// Fraction
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Fraction {
public:
	int numer;
	int denom;
public:
	static const Fraction Zero;
public:
	inline Fraction() : numer(0), denom(1) {}
	inline Fraction(int numer_, int denom_) : numer(numer_), denom(denom_) {}
	inline Fraction(const Fraction &frac) : numer(frac.numer), denom(frac.denom) {}
	Fraction Reduce() const;
	static Fraction FromNumber(Number num);
	static void SetError_DenominatorZero(Signal &sig);
};

typedef std::vector<Fraction> FractionList;
typedef std::deque<Fraction> FractionDeque;

GURA_DLLDECLARE Fraction operator+(const Fraction &a);
GURA_DLLDECLARE Fraction operator-(const Fraction &a);
GURA_DLLDECLARE Fraction operator+(const Fraction &a, const Fraction &b);
GURA_DLLDECLARE Fraction operator-(const Fraction &a, const Fraction &b);
GURA_DLLDECLARE Fraction operator*(const Fraction &a, const Fraction &b);
GURA_DLLDECLARE Fraction operator/(const Fraction &a, const Fraction &b);

//-----------------------------------------------------------------------------
// RandomGenerator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE RandomGenerator {
public:
	static void Initialize(ULong seed);
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
	UChar _red, _green, _blue, _alpha;
public:
	static const Color Zero;
	static const Color Black;
	static const Color Maroon;
	static const Color Green;
	static const Color Olive;
	static const Color Navy;
	static const Color Purple;
	static const Color Teal;
	static const Color Gray;
	static const Color Silver;
	static const Color Red;
	static const Color Lime;
	static const Color Yellow;
	static const Color Blue;
	static const Color Fuchsia;
	static const Color Aqua;
	static const Color White;
public:
	inline Color() : _red(0), _green(0), _blue(0), _alpha(0) {}
	inline Color(const Color &color) : _red(color._red), _green(color._green),
					_blue(color._blue), _alpha(color._alpha) {}
	inline Color(UChar red, UChar green, UChar blue) :
					_red(red), _green(green), _blue(blue), _alpha(0) {}
	inline Color(UChar red, UChar green, UChar blue, UChar alpha) :
					_red(red), _green(green), _blue(blue), _alpha(alpha) {}
	inline UChar GetRed() const { return _red; }
	inline UChar GetGreen() const { return _green; }
	inline UChar GetBlue() const { return _blue; }
	inline UChar GetAlpha() const { return _alpha; }
	inline void SetRed(UChar red) { _red = red; }
	inline void SetGreen(UChar green) { _green = green; }
	inline void SetBlue(UChar blue) { _blue = blue; }
	inline void SetAlpha(UChar alpha) { _alpha = alpha; }
	inline UChar GetGray() const {
		return CalcGray(GetRed(), GetGreen(), GetBlue());
	}
	inline ULong GetARGB() const {
		return
			(static_cast<ULong>(GetAlpha()) << 24) +
			(static_cast<ULong>(GetRed()) << 16) +
			(static_cast<ULong>(GetGreen()) << 8) +
			(static_cast<ULong>(GetBlue()) << 0);
	}
	inline ULong GetABGR() const {
		return
			(static_cast<ULong>(GetAlpha()) << 24) +
			(static_cast<ULong>(GetBlue()) << 16) +
			(static_cast<ULong>(GetGreen()) << 8) +
			(static_cast<ULong>(GetRed()) << 0);
	}
	inline ULong GetRGB() const {
		return
			(static_cast<ULong>(GetRed()) << 16) +
			(static_cast<ULong>(GetGreen()) << 8) +
			(static_cast<ULong>(GetBlue()) << 0);
	}
	inline ULong GetBGR() const {
		return
			(static_cast<ULong>(GetBlue()) << 16) +
			(static_cast<ULong>(GetGreen()) << 8) +
			(static_cast<ULong>(GetRed()) << 0);
	}
	inline bool operator<(const Color &c) const { return GetRGB() < c.GetRGB(); }
	inline size_t CalcDistSqu(UChar red, UChar green, UChar blue) const {
		return CalcDistSqu(GetRed(), GetGreen(), GetBlue(), red, green, blue);
	}
	inline size_t CalcDistSqu(const Color &c) const {
		return CalcDistSqu(GetRed(), GetGreen(), GetBlue(), c.GetRed(), c.GetGreen(), c.GetBlue());
	}
	inline String GetHTML() const {
		char buff[32];
		::sprintf(buff, "#%06lx", GetRGB());
		return String(buff);
	}
	static inline size_t CalcDistSqu(
				UChar red1, UChar green1, UChar blue1,
				UChar red2, UChar green2, UChar blue2) {
		Long distR = static_cast<Long>(red1) - static_cast<Long>(red2);
		Long distG = static_cast<Long>(green1) - static_cast<Long>(green2);
		Long distB = static_cast<Long>(blue1) - static_cast<Long>(blue2);
		return distR * distR + distG * distG + distB * distB;
	}
	// revise this equation to convert a color into gray scale.
	static inline UChar CalcGray(UChar red, UChar green, UChar blue) {
		return static_cast<UChar>(
			(static_cast<ULong>(red) * 299 +
			 static_cast<ULong>(green) * 587 +
			 static_cast<ULong>(blue) * 114) / 1000);
	}
};

typedef std::vector<Color> ColorList;
typedef std::deque<Color> ColorDeque;
typedef std::set<Color> ColorSet;

}
#endif
