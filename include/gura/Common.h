#ifndef __GURA_COMMON_H__
#define __GURA_COMMON_H__

#define GURA_VERSION "0.3.1"

#if defined(__BORLANDC__)
#define HAVE_WINDOWS_H
#endif

#if defined(_MSC_VER)
#define HAVE_WINDOWS_H
#pragma warning(disable:4251)
#pragma warning(disable:4275)
#pragma warning(disable:4355)
#pragma warning(disable:4996)
#endif

#if defined(HAVE_WINDOWS_H)
#define DLLIMPORT __declspec(dllimport)
#define DLLEXPORT __declspec(dllexport)
#if defined(gura_EXPORTS)
#define DLLDECLARE __declspec(dllexport)
#else
#define DLLDECLARE __declspec(dllimport)
#endif
typedef __int64 int64;
typedef unsigned __int64 uint64;
#define strcasecmp stricmp
#define USE_WINDOWS_DIB 1
#else
#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif
#define DLLIMPORT
#define DLLEXPORT
#define DLLDECLARE
typedef long long int64;
typedef unsigned long long uint64;
typedef void *HBITMAP;
#define USE_WINDOWS_DIB 0
#endif

#define NUMBEROF(x) (sizeof(x) / sizeof(x[0]))

#define ChooseMin(a, b) (((a) < (b))? (a) : (b))
#define ChooseMax(a, b) (((a) > (b))? (a) : (b))

#define foreach(T, i, c) for (T::iterator i = (c).begin(); i != (c).end(); i++)
#define foreach_const(T, i, c) for (T::const_iterator i = (c).begin(); i != (c).end(); i++)
#define foreach_reverse(T, i, c) for (T::reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)
#define foreach_const_reverse(T, i, c) for (T::const_reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)

#ifdef DEBUG_GURA
#define DBG(x) x
#define DBGPARSER(x) x
#define ASSUME(env, x) if (!(x)) { env.Error(__FILE__, __LINE__, #x); }
#else
#define DBG(x)
#define DBGPARSER(x)
#define ASSUME(env, x) if (!(x)) { env.Error(__FILE__, __LINE__, #x); }
#endif

#define ERROREND(env, str) (env).Error(__FILE__, __LINE__, (str));

#include "PackedNumber.h"

namespace Gura {

DLLDECLARE extern const int MAX_STACK_LEVEL;
DLLDECLARE extern const size_t InvalidSize;

DLLDECLARE bool IsBigEndian();
DLLDECLARE const char *GetVersion();
DLLDECLARE const char *GetOpening();

//-----------------------------------------------------------------------------
// Simple type declarations
//-----------------------------------------------------------------------------
typedef double Number;
typedef std::complex<Number> Complex;

DLLDECLARE extern const Number RoundOffThreshold;

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
typedef std::vector<Complex> ComplexList;

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
typedef std::deque<Complex> ComplexDeque;

typedef std::basic_string<char> String;
typedef std::deque<String> StringDeque;

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
// RandomGenerator
//-----------------------------------------------------------------------------
class RandomGenerator {
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
	XPackedUShort_LE(bfType);
	XPackedULong_LE(bfSize);
	XPackedUShort_LE(bfReserved1);
	XPackedUShort_LE(bfReserved2);
	XPackedULong_LE(bfOffBits);
};

struct BitmapInfoHeader {
	enum { Size = 40 };
	XPackedULong_LE(biSize);
	XPackedLong_LE(biWidth);
	XPackedLong_LE(biHeight);
	XPackedUShort_LE(biPlanes);
	XPackedUShort_LE(biBitCount);
	XPackedULong_LE(biCompression);
	XPackedULong_LE(biSizeImage);
	XPackedLong_LE(biXPelsPerMeter);
	XPackedLong_LE(biYPelsPerMeter);
	XPackedULong_LE(biClrUsed);
	XPackedULong_LE(biClrImportant);
};

}
#endif
