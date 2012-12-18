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
DLLDECLARE char GetEscaped(char ch);
DLLDECLARE String ZenToHan(const char *str);
DLLDECLARE char ZenToHanChar(const char *str, const char **next);
DLLDECLARE const char *FindString(const char *str, const char *sub, bool ignoreCaseFlag);
DLLDECLARE String::const_iterator FindString(String::const_iterator str,
		String::const_iterator strEnd, const String &sub, bool ignoreCaseFlag);

DLLDECLARE String PickChar(const String &str, size_t idx);
DLLDECLARE String::const_iterator NextChar(const String &str, String::const_iterator p);
DLLDECLARE String::const_iterator NextUTF8(const String &str, String::const_iterator p, uint64 &codeUTF8);
DLLDECLARE String::const_iterator NextUTF32(const String &str, String::const_iterator p, unsigned long &codeUTF32);

DLLDECLARE String MakeQuotedString(const char *str);

DLLDECLARE void EscapeURI(String &strDst, const char *str);
DLLDECLARE String EscapeURI(const char *str);
DLLDECLARE void EscapeURI(String &strDst, const char *str, size_t len);
DLLDECLARE String EscapeURI(const char *str, size_t len);
DLLDECLARE void UnescapeURI(String &strDst, const char *str);
DLLDECLARE String UnescapeURI(const char *str);
DLLDECLARE void EscapeHtml(String &strDst, const char *str, bool quoteFlag);
DLLDECLARE String EscapeHtml(const char *str, bool quoteFlag);
DLLDECLARE void UnescapeHtml(String &strDst, const char *str);
DLLDECLARE String UnescapeHtml(const char *str);
DLLDECLARE String NumberToString(Number num);
DLLDECLARE const char *StartsWith(const char *str, const char *prefix, size_t pos, bool ignoreCaseFlag);
DLLDECLARE const char *EndsWith(const char *str, const char *suffix, bool ignoreCaseFlag);
DLLDECLARE const char *EndsWith(const char *str, const char *suffix, size_t posEnd, bool ignoreCaseFlag);
DLLDECLARE String Capitalize(const char *str);
DLLDECLARE String Lower(const char *str);
DLLDECLARE String Upper(const char *str);
DLLDECLARE String Strip(const char *str, bool stripLeftFlag = true, bool stripRightFlag = true);
DLLDECLARE String Strip(const char *str, const SymbolSet &attrs);
DLLDECLARE String Chop(const char *str, bool eolOnlyFlag);
DLLDECLARE size_t Length(const char *str);
DLLDECLARE size_t CalcCharPos(const char *str, size_t idx);
DLLDECLARE const char *Forward(const char *str, size_t len);
DLLDECLARE String::const_iterator Forward(String::const_iterator str, String::const_iterator strEnd, size_t len);
DLLDECLARE String Center(const char *str, size_t len, const char *padding);
DLLDECLARE String LJust(const char *str, size_t len, const char *padding);
DLLDECLARE String RJust(const char *str, size_t len, const char *padding);
DLLDECLARE String Left(const char *str, size_t len);
DLLDECLARE String Right(const char *str, size_t len);
DLLDECLARE String Middle(const char *str, int start, int len);
DLLDECLARE String Join(const ValueList &valList, const char *str);
DLLDECLARE String Replace(const char *str, const char *sub, const char *replace,
									int nMaxReplace, const SymbolSet &attrs);
DLLDECLARE void SplitPathList(const char *str, StringList &strList);
DLLDECLARE Value FindString(Environment &env, Signal sig,
		const char *str, const char *sub, int start, const SymbolSet &attrs);

DLLDECLARE unsigned short GetCType(char ch);

inline size_t CalcCharOffset(const char *str, size_t pos) {
	return Forward(str, pos) - str;
}


#define CTYPE_Alpha (1 << 0)
inline bool IsAlpha(char ch) { return (GetCType(ch) & CTYPE_Alpha) != 0; }

#define CTYPE_Digit (1 << 1)
inline bool IsDigit(char ch) { return (GetCType(ch) & CTYPE_Digit) != 0; }

#define CTYPE_HexDigit (1 << 2)
inline bool IsHexDigit(char ch) { return (GetCType(ch) & CTYPE_HexDigit) != 0; }

#define CTYPE_OctDigit (1 << 3)
inline bool IsOctDigit(char ch) { return (GetCType(ch) & CTYPE_OctDigit) != 0; }

#define CTYPE_White (1 << 4)
inline bool IsWhite(char ch) { return (GetCType(ch) & CTYPE_White) != 0; }

#define CTYPE_Space (1 << 5)
inline bool IsSpace(char ch) { return (GetCType(ch) & CTYPE_Space) != 0; }

#define CTYPE_SJISFirst (1 << 6)
inline bool IsSJISFirst(char ch) { return (GetCType(ch) & CTYPE_SJISFirst) != 0; }

#define CTYPE_SJISSecond (1 << 7)
inline bool IsSJISSecond(char ch) { return (GetCType(ch) & CTYPE_SJISSecond) != 0; }

#define CTYPE_UTF8First (1 << 8)
inline bool IsUTF8First(char ch) { return (GetCType(ch) & CTYPE_UTF8First) != 0; }

#define CTYPE_UTF8Follower (1 << 9)
inline bool IsUTF8Follower(char ch) { return (GetCType(ch) & CTYPE_UTF8Follower) != 0; }

#define CTYPE_SymbolExtra (1 << 10)
inline bool IsSymbolExtra(char ch) { return (GetCType(ch) & CTYPE_SymbolExtra) != 0; }

#define CTYPE_Lower (1 << 11)
inline bool IsLower(char ch) { return (GetCType(ch) & CTYPE_Lower) != 0; }

#define CTYPE_Upper (1 << 12)
inline bool IsUpper(char ch) { return (GetCType(ch) & CTYPE_Upper) != 0; }

#define CTYPE_URIC (1 << 13)
inline bool IsURIC(char ch) { return (GetCType(ch) & CTYPE_URIC) != 0; }

#define CTYPE_SymbolFirstChar (CTYPE_Alpha | CTYPE_SymbolExtra | CTYPE_UTF8First)
inline bool IsSymbolFirstChar(char ch) { return (GetCType(ch) & CTYPE_SymbolFirstChar) != 0; }

#define CTYPE_SymbolChar (CTYPE_SymbolFirstChar | CTYPE_Digit | CTYPE_UTF8Follower)
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
class DLLDECLARE StringList : public std::vector<String> {
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
