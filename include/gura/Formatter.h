#ifndef __GURA_FORMATTER_H__
#define __GURA_FORMATTER_H__

#include "Common.h"

namespace Gura {

class IteratorOwner;
class Environment;
class Value;

//-----------------------------------------------------------------------------
// FormatterBase
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE FormatterBase {
private:
	bool _nilVisibleFlag;
	const char *_lineSep;
	enum PlusMode { PLUSMODE_None, PLUSMODE_Space, PLUSMODE_Plus, };
	struct Flags {
		bool leftAlignFlag;
		bool sharpFlag;
		int fieldMinWidth;
		int precision;
		PlusMode plusMode;
		char charPadding;
	};
public:
	inline FormatterBase(bool nilVisibleFlag = true) :
					_nilVisibleFlag(nilVisibleFlag), _lineSep("\n") {}
	bool DoFormat(Signal sig, const char *format, const ValueList &valList);
	void PutString(const Flags &flags, const char *p, int cntMax = -1);
	void PutInvalid(const Flags &flags);
	virtual void PutChar(char ch) = 0;
private:
	inline static void SetError_WrongFormat(Signal &sig) {
		sig.SetError(ERR_ValueError, "wrong format for formatter");
	}
	inline static void SetError_NotEnoughArguments(Signal &sig) {
		sig.SetError(ERR_TypeError, "not enough arguments for formatter");
	}
	inline static void SetError_NumberIsExpected(Signal &sig, const char ch) {
		sig.SetError(ERR_ValueError, "number is expected for %%%c qualifier", ch);
	}
	inline static void SetError_NumberOrComplexIsExpected(Signal &sig, const char ch) {
		sig.SetError(ERR_ValueError, "number or complex is expected for %%%c qualifier", ch);
	}
	inline static void SetError_NumberIsExpected(Signal &sig, const char *qualifier) {
		sig.SetError(ERR_ValueError, "number is expected for %s", qualifier);
	}
	static const char *Conv_d(const Flags &flags, int value,
							char *buff, size_t size);
	static const char *Conv_u(const Flags &flags, UInt value,
							char *buff, size_t size);
	static const char *Conv_b(const Flags &flags, UInt value,
							char *buff, size_t size);
	static const char *Conv_o(const Flags &flags, UInt value,
							char *buff, size_t size);
	static const char *Conv_x(const Flags &flags, UInt value,
							char *buff, size_t size, bool upperFlag);
	static const char *Conv_e(const Flags &flags, double value,
							char *buff, size_t size, bool upperFlag);
	static const char *Conv_f(const Flags &flags, double value,
							char *buff, size_t size, bool upperFlag);
	static const char *Conv_g(const Flags &flags, double value,
							char *buff, size_t size, bool upperFlag);
	static char *FillZeroDigit(char *dstp, char *dstpEnd, int cnt);
	static char *CopyDigits(char *dstp, char *dstpEnd, const char *srcp);
	static char *CopyDigits(char *dstp, char *dstpEnd, const char *srcp, int cnt);
};

//-----------------------------------------------------------------------------
// Formatter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Formatter : public FormatterBase {
private:
	String _str;
public:
	static String Format(Signal sig,
							const char *format, const ValueList &valList);
	static Value Format(Environment &env, Signal sig,
							const char *format, IteratorOwner &iterOwner);
	virtual void PutChar(char ch);
};

}

#endif
