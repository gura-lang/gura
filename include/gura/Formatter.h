//=============================================================================
// Formatter
//=============================================================================
#ifndef __GURA_FORMATTER_H__
#define __GURA_FORMATTER_H__

#include "Common.h"

namespace Gura {

class IteratorOwner;
class Environment;
class Value;

//-----------------------------------------------------------------------------
// Formatter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Formatter {
public:
	enum PlusMode {
		PLUSMODE_None, PLUSMODE_Space, PLUSMODE_Plus,
	};
	struct Flags {
		bool upperCaseFlag;
		bool leftAlignFlag;
		bool sharpFlag;
		int fieldMinWidth;
		int precision;
		PlusMode plusMode;
		char charPadding;
	};
public:
	class Source {
	public:
		virtual bool IsEnd() = 0;
		virtual Value GetInt() = 0;
		virtual Value GetDouble() = 0;
		virtual Value GetString() = 0;
	};
	class Source_ValueList : public Source {
	private:
		const ValueList &_valList;
		ValueList::const_iterator _pValue;
	public:
		inline Source_ValueList(const ValueList &valList) : _valList(valList) {
			_pValue = _valList.begin();
		}
		virtual bool IsEnd();
		virtual Value GetInt();
		virtual Value GetDouble();
		virtual Value GetString();
	};
	class Source_va_list : public Source {
	private:
		va_list _ap;
	public:
		inline Source_va_list(va_list ap) : _ap(ap) {}
		virtual bool IsEnd();
		virtual Value GetInt();
		virtual Value GetDouble();
		virtual Value GetString();
	};
private:
	bool _nilVisibleFlag;
	const char *_lineSep;
public:
	inline Formatter(bool nilVisibleFlag = true) :
					_nilVisibleFlag(nilVisibleFlag), _lineSep("\n") {}
	bool DoFormat(Signal sig, const char *format, const ValueList &valList);
	bool DoFormat(Signal sig, const char *format, va_list ap);
	bool DoFormat(Signal sig, const char *format, Source &source);
	bool PutString(Signal sig, const char *p);
	bool PutAlignedString(Signal sig, const Flags &flags, const char *p, int cntMax = -1);
	bool PutInvalid(Signal sig, const Flags &flags);
	virtual bool PutChar(Signal sig, char ch) = 0;
	static String Format(Signal sig, const char *format, const ValueList &valList);
	static String Format(Signal sig, const char *format, va_list ap);
	static Value Format(Environment &env, Signal sig,
							const char *format, IteratorOwner &iterOwner);
	static const char *Format_d(const Flags &flags, int value, char *buff, size_t size);
	static const char *Format_u(const Flags &flags, UInt value, char *buff, size_t size);
	static const char *Format_b(const Flags &flags, UInt value, char *buff, size_t size);
	static const char *Format_o(const Flags &flags, UInt value, char *buff, size_t size);
	static const char *Format_x(const Flags &flags, UInt value, char *buff, size_t size);
	static const char *Format_e(const Flags &flags, double value, char *buff, size_t size);
	static const char *Format_f(const Flags &flags, double value, char *buff, size_t size);
	static const char *Format_g(const Flags &flags, double value, char *buff, size_t size);
private:
	static void SetError_WrongFormat(Signal &sig);
	static void SetError_NotEnoughArguments(Signal &sig);
	static char *FillZeroDigit(char *dstp, char *dstpEnd, int cnt);
	static char *CopyDigits(char *dstp, char *dstpEnd, const char *srcp);
	static char *CopyDigits(char *dstp, char *dstpEnd, const char *srcp, int cnt);
};

//-----------------------------------------------------------------------------
// FormatterString
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE FormatterString : public Formatter {
private:
	String _str;
public:
	virtual bool PutChar(Signal sig, char ch);
	inline const String &GetStringSTL() const { return _str; }
};

}

#endif
