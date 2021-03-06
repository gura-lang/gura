//=============================================================================
// Common
//=============================================================================
#ifndef __GURA_COMMON_H__
#define __GURA_COMMON_H__

#define NEW_INDEXING 0

#include "Macro.h"
#include "Version.h"
#include "PackedNumber.h"
#include "MemoryPool.h"

Gura_BeginNameSpace()

#if defined(GURA_ON_MSWIN)
#else
typedef void *HBITMAP;
#endif

#if defined(GURA_ON_LINUX)
// Linux doesn't provide a function to change mode of a symbolic link.
inline int lchmod(const char *path, mode_t mode) { return 0; }
#endif

GURA_DLLDECLARE extern const int MAX_STACK_LEVEL;
GURA_DLLDECLARE extern const size_t InvalidSize;

GURA_DLLDECLARE bool IsBigEndian();

class Signal;

//-----------------------------------------------------------------------------
// Simple type declarations
//-----------------------------------------------------------------------------

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
typedef long				Long;		// long
typedef int8_t				Char;		// signed 8bit
typedef int16_t				Short;		// signed 16bit
typedef bool				Boolean;	// signed 8bit
typedef int8_t				Int8;		// signed 8bit
typedef int16_t				Int16;		// signed 16bit
typedef int32_t				Int32;		// signed 32bit
typedef int64_t				Int64;		// signed 64bit
typedef unsigned int		UInt;		// unsigned native bits
typedef unsigned long		ULong;		// unsigned long
typedef uint8_t				UChar;		// unsigned 8bit
typedef uint16_t			UShort;		// unsigned 16bit
typedef uint8_t				UInt8;		// unsigned 8bit
typedef uint16_t			UInt16;		// unsigned 16bit
typedef uint32_t			UInt32;		// unsigned 32bit
typedef uint64_t			UInt64;		// unsigned 64bit
typedef float				Float;
typedef double				Double;
typedef double				Number;

typedef std::vector<Int,	Allocator<Int> >	IntList;
typedef std::vector<Long,	Allocator<Long> >	LongList;
typedef std::vector<Char,	Allocator<Char> >	CharList;
typedef std::vector<Short,	Allocator<Short> >	ShortList;
typedef std::vector<Boolean,Allocator<Boolean> >BooleanList;
typedef std::vector<Int8,	Allocator<Int8> >	Int8List;
typedef std::vector<Int16,	Allocator<Int16> >	Int16List;
typedef std::vector<Int32,	Allocator<Int32> >	Int32List;
typedef std::vector<Int64,	Allocator<Int64> >	Int64List;
typedef std::vector<UInt,	Allocator<UInt> >	UIntList;
typedef std::vector<ULong,	Allocator<ULong> >	ULongList;
typedef std::vector<UChar,	Allocator<UChar> >	UCharList;
typedef std::vector<UShort,	Allocator<UShort> >	UShortList;
typedef std::vector<UInt8,	Allocator<UInt8> >	UInt8List;
typedef std::vector<UInt16,	Allocator<UInt16> >	UInt16List;
typedef std::vector<UInt32,	Allocator<UInt32> >	UInt32List;
typedef std::vector<UInt64,	Allocator<UInt64> >	UInt64List;
typedef std::vector<Float,	Allocator<Float> >	FloatList;
typedef std::vector<Double,	Allocator<Double> >	DoubleList;
typedef std::vector<Number,	Allocator<Number> >	NumberList;
typedef std::vector<size_t,	Allocator<size_t> >	SizeTList;

typedef std::deque<Int,		Allocator<Int> >	IntDeque;
typedef std::deque<Long,	Allocator<Long> >	LongDeque;
typedef std::deque<Char,	Allocator<Char> >	CharDeque;
typedef std::deque<Short,	Allocator<Short> >	ShortDeque;
typedef std::deque<Boolean,	Allocator<Boolean> >BooleanDeque;
typedef std::deque<Int8,	Allocator<Int8> >	Int8Deque;
typedef std::deque<Int16,	Allocator<Int16> >	Int16Deque;
typedef std::deque<Int32,	Allocator<Int32> >	Int32Deque;
typedef std::deque<Int64,	Allocator<Int64> >	Int64Deque;
typedef std::deque<UInt,	Allocator<UInt> >	UIntDeque;
typedef std::deque<ULong,	Allocator<ULong> >	ULongDeque;
typedef std::deque<UChar,	Allocator<UChar> >	UCharDeque;
typedef std::deque<UShort,	Allocator<UShort> >	UShortDeque;
typedef std::deque<UInt8,	Allocator<UInt8> >	UInt8Deque;
typedef std::deque<UInt16,	Allocator<UInt16> >	UInt16Deque;
typedef std::deque<UInt32,	Allocator<UInt32> >	UInt32Deque;
typedef std::deque<UInt64,	Allocator<UInt64> >	UInt64Deque;
typedef std::deque<Float,	Allocator<Float> >	FloatDeque;
typedef std::deque<Double,	Allocator<Double> >	DoubleDeque;
typedef std::deque<Number,	Allocator<Number> >	NumberDeque;
typedef std::deque<size_t,	Allocator<size_t> >	SizeTDeque;

//-----------------------------------------------------------------------------
// Flag
//-----------------------------------------------------------------------------
enum {
	FLAG_None			= 0,
	FLAG_Closure		= (1 << 0),		// :closure
	FLAG_CutExtraArgs	= (1 << 1),		// :cut_extra_args
	FLAG_Deg			= (1 << 2),		// :deg
	FLAG_DynamicScope	= (1 << 3),		// :dynamic_scope
	FLAG_EndMarker		= (1 << 4),		// :end_marker
	FLAG_Finalizer		= (1 << 5),		// :finalizer
	FLAG_Flat			= (1 << 6),		// :flat
	FLAG_Fork			= (1 << 7),		// :fork
	FLAG_Leader			= (1 << 8),		// :leader
	FLAG_ListVar		= (1 << 9),		// :listvar
	FLAG_Map			= (1 << 10),	// :map
	FLAG_Nil			= (1 << 11),	// :nil
	FLAG_NoCast			= (1 << 12),	// :nocast
	FLAG_NoMap			= (1 << 13),	// :nomap
	FLAG_NoNamed		= (1 << 14),	// :nonamed
	FLAG_Private		= (1 << 15),	// :private
	FLAG_Privileged		= (1 << 16),	// :privileged
	FLAG_Public			= (1 << 17),	// :public
	FLAG_Read			= (1 << 18),	// :r
	FLAG_SymbolFunc		= (1 << 19),	// :symbol_func
	FLAG_Trailer		= (1 << 20),	// :trailer
	FLAG_Write			= (1 << 21),	// :w
};

//-----------------------------------------------------------------------------
// OccurPattern
//-----------------------------------------------------------------------------
enum OccurPattern {
	OCCUR_Invalid,
	OCCUR_Zero,							// (none)
	OCCUR_Once,							// 1
	OCCUR_ZeroOrOnce,					// ?
	OCCUR_ZeroOrMore,					// *
	OCCUR_OnceOrMore,					// +
};

//-----------------------------------------------------------------------------
// ResultMode
//-----------------------------------------------------------------------------
enum ResultMode {
	RSLTMODE_Normal,
	RSLTMODE_Iterator,					// :iter
	RSLTMODE_List,						// :list
	RSLTMODE_Reduce,					// :reduce
	RSLTMODE_Set,						// :set
	RSLTMODE_Void,						// :void
	RSLTMODE_XIterator,					// :xiter
	RSLTMODE_XList,						// :xlist
	RSLTMODE_XReduce,					// :xreduce
	RSLTMODE_XSet,						// :xset
};

//-----------------------------------------------------------------------------
// Extra
//-----------------------------------------------------------------------------
enum {
	EXTRA_None			= 0,
	EXTRA_Public		= (1 << 0),
	EXTRA_Argument		= (1 << 1),
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
	inline AutoPtr(T *p = nullptr) : _p(p) {}
	inline ~AutoPtr() { T::Delete(_p); }
	inline T &operator*() { return *_p; }
	inline T &operator*() const { return *_p; }
	inline T *operator->() { return _p; }
	inline T *operator->() const { return _p; }
	inline void reset(T *p = nullptr) { T::Delete(_p); _p = p; }
	inline T *get() { return _p; }
	inline T *get() const { return _p; }
	inline T *release() { T *p = _p; _p = nullptr; return p; }
	inline bool IsNull() const { return _p == nullptr; }
	inline T *Reference() const { return T::Reference(_p); }
private:
	inline void operator=(const T *p) {}
};

//-----------------------------------------------------------------------------
// String
//-----------------------------------------------------------------------------
struct my_char_traits : public std::char_traits<char> {};

typedef std::basic_string<char, my_char_traits, Allocator<char> > String;
typedef std::deque<String, Allocator<String> > StringDeque;

class GURA_DLLDECLARE StringShared {
private:
	int _cntRef;
	String _str;
public:
	Gura_DeclareReferenceAccessor(StringShared)
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "StringShared");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	inline StringShared() : _cntRef(1) {}
	inline StringShared(const String &str) : _cntRef(1), _str(str) {}
private:
	inline ~StringShared() {}
public:
	inline const char *GetString() const { return _str.c_str(); }
	inline const String &GetStringSTL() const { return _str; }
};

//-----------------------------------------------------------------------------
// Comparator functions
//-----------------------------------------------------------------------------
template<typename T>
inline T ChooseMin(T a, T b) { return (a < b)? a : b; }

template<typename T>
inline T ChooseMax(T a, T b) { return (a > b)? a : b; }

template<typename T>
inline bool CompareEq(T a, T b) { return a == b; }

template<typename T>
inline bool CompareNe(T a, T b) { return a != b; }

template<typename T>
inline bool CompareGt(T a, T b) { return a > b; }

template<typename T>
inline bool CompareLt(T a, T b) { return a < b; }

template<typename T>
inline bool CompareGe(T a, T b) { return a >= b; }

template<typename T>
inline bool CompareLe(T a, T b) { return a <= b; }

Gura_EndNameSpace()

#endif
