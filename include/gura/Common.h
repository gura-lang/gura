//=============================================================================
// Common
//=============================================================================
#ifndef __GURA_COMMON_H__
#define __GURA_COMMON_H__

#include "Macro.h"
#include "Version.h"
#include "PackedNumber.h"
#include "MemoryPool.h"

Gura_BeginNameSpace()

#if defined(GURA_ON_MSWIN)
typedef __int64 int64;
typedef unsigned __int64 uint64;
#else
typedef long long int64;
typedef unsigned long long uint64;
typedef void *HBITMAP;
#endif

template<typename T>
inline T ChooseMin(T a, T b) { return (a < b)? a : b; }
template<typename T>
inline T ChooseMax(T a, T b) { return (a > b)? a : b; }

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
// Flag
//-----------------------------------------------------------------------------
enum {
	FLAG_None			= 0,
	FLAG_CutExtraArgs	= (1 << 0),		// :cut_extra_args
	FLAG_DynamicScope	= (1 << 1),		// :dynamic_scope
	FLAG_EndMarker		= (1 << 2),		// :end_marker
	FLAG_Finalizer		= (1 << 3),		// :finalizer
	FLAG_Flat			= (1 << 4),		// :flat
	FLAG_Fork			= (1 << 5),		// :fork
	FLAG_Leader			= (1 << 6),		// :leader
	FLAG_ListVar		= (1 << 7),		// :listvar
	FLAG_Map			= (1 << 8),		// :map
	FLAG_Nil			= (1 << 9),		// :nil
	FLAG_NoCast			= (1 << 10),	// :nocast
	FLAG_NoMap			= (1 << 11),	// :nomap
	FLAG_NoNamed		= (1 << 12),	// :nonamed
	FLAG_Private		= (1 << 13),	// :private
	FLAG_Privileged		= (1 << 14),	// :privileged
	FLAG_Public			= (1 << 15),	// :public
	FLAG_Read			= (1 << 16),	// :r
	FLAG_SymbolFunc		= (1 << 17),	// :symbol_func
	FLAG_Trailer		= (1 << 18),	// :trailer
	FLAG_Write			= (1 << 19),	// :w
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
	inline void reset(T *p) { T::Delete(_p); _p = p; }
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

typedef std::basic_string<char, my_char_traits> String;
typedef std::deque<String> StringDeque;

class GURA_DLLDECLARE StringShared {
private:
	int _cntRef;
	String _str;
public:
	Gura_DeclareReferenceAccessor(StringShared)
public:
	inline StringShared() : _cntRef(1) {}
	inline StringShared(const String &str) : _cntRef(1), _str(str) {}
private:
	inline ~StringShared() {}
public:
	inline const char *GetString() const { return _str.c_str(); }
	inline const String &GetStringSTL() const { return _str; }
};

Gura_EndNameSpace()

#endif
