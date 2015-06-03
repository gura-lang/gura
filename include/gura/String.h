//=============================================================================
// String
//=============================================================================
#ifndef __GURA_STRING_H__
#define __GURA_STRING_H__

#include "Common.h"
#include "Signal.h"
#include "Codec.h"

namespace Gura {

class Symbol;
class SymbolSet;
class Value;
class ValueList;
class Environment;
class StringList;

//-----------------------------------------------------------------------------
// String operations
//-----------------------------------------------------------------------------
GURA_DLLDECLARE char GetEscaped(char ch);
GURA_DLLDECLARE String ZenToHan(const char *str);
GURA_DLLDECLARE char ZenToHanChar(const char *str, const char **next);
GURA_DLLDECLARE const char *FindString(const char *str, const char *sub, bool ignoreCaseFlag);
GURA_DLLDECLARE String::const_iterator FindString(String::const_iterator str,
		String::const_iterator strEnd, const String &sub, bool ignoreCaseFlag);

GURA_DLLDECLARE String PickChar(const String &str, size_t idx);
GURA_DLLDECLARE String::const_iterator NextChar(const String &str, String::const_iterator p);
GURA_DLLDECLARE String::const_iterator NextUTF8(const String &str, String::const_iterator p, uint64 &codeUTF8);
GURA_DLLDECLARE const char *NextUTF8(const char *p, UInt64 &codeUTF8);
GURA_DLLDECLARE String::const_iterator NextUTF32(const String &str, String::const_iterator p, ULong &codeUTF32);
GURA_DLLDECLARE const char *NextUTF32(const char *p, ULong &codeUTF32);
GURA_DLLDECLARE void AppendUTF8(String &str, UInt64 codeUTF8);
GURA_DLLDECLARE void AppendUTF32(String &str, ULong codeUTF32);

GURA_DLLDECLARE String MakeQuotedString(const char *str);

GURA_DLLDECLARE void EncodeURI(String &strDst, const char *str);
GURA_DLLDECLARE String EncodeURI(const char *str);
GURA_DLLDECLARE void EncodeURI(String &strDst, const char *str, size_t len);
GURA_DLLDECLARE String EncodeURI(const char *str, size_t len);
GURA_DLLDECLARE void DecodeURI(String &strDst, const char *str);
GURA_DLLDECLARE String DecodeURI(const char *str);
GURA_DLLDECLARE void EscapeHtml(String &strDst, const char *str, bool quoteFlag);
GURA_DLLDECLARE String EscapeHtml(const char *str, bool quoteFlag);
GURA_DLLDECLARE void UnescapeHtml(String &strDst, const char *str);
GURA_DLLDECLARE String UnescapeHtml(const char *str);
GURA_DLLDECLARE String NumberToString(Number num);
GURA_DLLDECLARE const char *StartsWith(const char *str, const char *prefix, size_t pos, bool ignoreCaseFlag);
GURA_DLLDECLARE const char *EndsWith(const char *str, const char *suffix, bool ignoreCaseFlag);
GURA_DLLDECLARE const char *EndsWith(const char *str, const char *suffix, size_t posEnd, bool ignoreCaseFlag);
GURA_DLLDECLARE String Capitalize(const char *str);
GURA_DLLDECLARE String Lower(const char *str);
GURA_DLLDECLARE String Upper(const char *str);
GURA_DLLDECLARE String Strip(const char *str, bool stripLeftFlag = true, bool stripRightFlag = true);
GURA_DLLDECLARE String Strip(const char *str, const SymbolSet &attrs);
GURA_DLLDECLARE String Chop(const char *str, bool eolOnlyFlag);
GURA_DLLDECLARE size_t Length(const char *str);
GURA_DLLDECLARE size_t Width(const char *str);
GURA_DLLDECLARE bool CheckCType(const char *str, UShort type);
GURA_DLLDECLARE size_t CalcCharPos(const char *str, size_t idx);
GURA_DLLDECLARE const char *Forward(const char *str, size_t len, size_t *pLenForward = NULL);
GURA_DLLDECLARE String::const_iterator Forward(String::const_iterator str, String::const_iterator strEnd, size_t len, size_t *pLenForward = NULL);
GURA_DLLDECLARE String Center(const char *str, size_t width, const char *padding);
GURA_DLLDECLARE String LJust(const char *str, size_t width, const char *padding);
GURA_DLLDECLARE String RJust(const char *str, size_t width, const char *padding);
GURA_DLLDECLARE String Left(const char *str, size_t len);
GURA_DLLDECLARE String Right(const char *str, size_t len);
GURA_DLLDECLARE String Middle(const char *str, int start, int len);
GURA_DLLDECLARE String Replace(const char *str, const char *sub, const char *replace,
									int nMaxReplace, const SymbolSet &attrs);
GURA_DLLDECLARE String Replaces(const char *str, const ValueList &valList,
									int nMaxReplace, const SymbolSet &attrs);
GURA_DLLDECLARE void SplitPathList(const char *str, StringList &strList);
GURA_DLLDECLARE Value FindString(Environment &env, Signal sig,
		const char *str, const char *sub, int start, const SymbolSet &attrs);

GURA_DLLDECLARE UShort GetCType(char ch);
GURA_DLLDECLARE Number ToNumber(const char *str, bool *pSuccessFlag = NULL);

inline size_t CalcCharOffset(const char *str, size_t pos) {
	return Forward(str, pos) - str;
}

enum {
	CTYPE_Alpha				= (1 << 0),
	CTYPE_Digit				= (1 << 1),
	CTYPE_HexDigit			= (1 << 2),
	CTYPE_OctDigit			= (1 << 3),
	CTYPE_BinDigit			= (1 << 4),
	CTYPE_White				= (1 << 5),
	CTYPE_Space				= (1 << 6),
	CTYPE_SJISFirst			= (1 << 7),
	CTYPE_SJISSecond		= (1 << 8),
	CTYPE_UTF8First			= (1 << 9),
	CTYPE_UTF8Follower		= (1 << 10),
	CTYPE_SymbolExtra		= (1 << 11),
	CTYPE_Lower				= (1 << 12),
	CTYPE_Upper				= (1 << 13),
	CTYPE_URIC				= (1 << 14),
	CTYPE_SymbolFirstChar	= (CTYPE_Alpha | CTYPE_SymbolExtra | CTYPE_UTF8First),
	CTYPE_SymbolChar		= (CTYPE_SymbolFirstChar | CTYPE_Digit | CTYPE_UTF8Follower),
};

inline bool IsAlpha(char ch) { return (GetCType(ch) & CTYPE_Alpha) != 0; }
inline bool IsDigit(char ch) { return (GetCType(ch) & CTYPE_Digit) != 0; }
inline bool IsHexDigit(char ch) { return (GetCType(ch) & CTYPE_HexDigit) != 0; }
inline bool IsOctDigit(char ch) { return (GetCType(ch) & CTYPE_OctDigit) != 0; }
inline bool IsBinDigit(char ch) { return (GetCType(ch) & CTYPE_BinDigit) != 0; }
inline bool IsWhite(char ch) { return (GetCType(ch) & CTYPE_White) != 0; }
inline bool IsSpace(char ch) { return (GetCType(ch) & CTYPE_Space) != 0; }
inline bool IsSJISFirst(char ch) { return (GetCType(ch) & CTYPE_SJISFirst) != 0; }
inline bool IsSJISSecond(char ch) { return (GetCType(ch) & CTYPE_SJISSecond) != 0; }
inline bool IsUTF8First(char ch) { return (GetCType(ch) & CTYPE_UTF8First) != 0; }
inline bool IsUTF8Follower(char ch) { return (GetCType(ch) & CTYPE_UTF8Follower) != 0; }
inline bool IsSymbolExtra(char ch) { return (GetCType(ch) & CTYPE_SymbolExtra) != 0; }
inline bool IsLower(char ch) { return (GetCType(ch) & CTYPE_Lower) != 0; }
inline bool IsUpper(char ch) { return (GetCType(ch) & CTYPE_Upper) != 0; }
inline bool IsURIC(char ch) { return (GetCType(ch) & CTYPE_URIC) != 0; }
inline bool IsSymbolFirstChar(char ch) { return (GetCType(ch) & CTYPE_SymbolFirstChar) != 0; }
inline bool IsSymbolChar(char ch) { return (GetCType(ch) & CTYPE_SymbolChar) != 0; }

inline char ConvHexDigit(char ch) {
	return
		('0' <= ch && ch <= '9')? ch - '0' :
		('A' <= ch && ch <= 'F')? ch - 'A' + 10 :
		('a' <= ch && ch <= 'f')? ch - 'a' + 10 : 0;
}

inline char ConvOctDigit(char ch) {
	return ('0' <= ch && ch <= '7')? ch - '0' : 0;
}

inline char ConvBinDigit(char ch) {
	return ('0' <= ch && ch <= '1')? ch - '0' : 0;
}

inline char ToUpper(char ch) {
	return ('a' <= ch && ch <= 'z')? ch - 'a' + 'A' : ch;
}

inline char ToLower(char ch) {
	return ('A' <= ch && ch <= 'Z')? ch - 'A' + 'a' : ch;
}

inline int CompareChar(char ch1, char ch2, bool ignoreCaseFlag) {
	return ignoreCaseFlag?
		static_cast<int>(ToUpper(ch1)) - static_cast<int>(ToUpper(ch2)) :
		static_cast<int>(ch1) - static_cast<int>(ch2);
}

inline bool IsFileSeparator(char ch) {
	return ch == '\\' || ch == '/';
}

//-----------------------------------------------------------------------------
// StringList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StringList : public std::vector<String> {
public:
	static const StringList Null;
	inline StringList() {}
	StringList(const StringList &stringList);
	void operator=(const StringList &stringList);
};

//-----------------------------------------------------------------------------
// CharConverter
//-----------------------------------------------------------------------------
class CharConverter {
private:
	char _buff[16];
	char _chSuspend;
	bool _enableFlag;
	bool _readyFlag;
	size_t _idxPut, _idxGet;
public:
	CharConverter();
	inline void Enable(bool enableFlag) { _enableFlag = enableFlag; }
	void Put(char ch);
	bool Get(char *pch);
};

}

#endif
