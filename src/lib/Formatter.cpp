//=============================================================================
// Formatter
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Formatter
//-----------------------------------------------------------------------------
bool Formatter::DoFormat(Signal sig, const char *format, const ValueList &valList)
{
	Source_ValueList source(valList);
	return DoFormat(sig, format, source);
}

bool Formatter::DoFormat(Signal sig, const char *format, va_list ap)
{
	Source_va_list source(ap);
	return DoFormat(sig, format, source);
}

bool Formatter::DoFormat(Signal sig, const char *format, Source &source)
{
	bool eatNextFlag;
	const char *formatp = format;
	Flags flags;
	enum {
		STAT_Start,
		STAT_FlagsPre, STAT_Flags, STAT_FlagsAfterWhite,
		STAT_PrecisionPre, STAT_Precision,
		STAT_Padding,
	} stat = STAT_Start;
	for (;;) {
		char ch = *formatp;
		eatNextFlag = true;
		if (ch == '\0') {
			break;
		} else if (stat == STAT_Start) {
			if (ch == '%') {
				stat = STAT_FlagsPre;
			} else if (ch == '\n') {
				for (const char *p = _lineSep; *p != '\0'; p++) {
					if (!PutChar(sig, *p)) return false;
				}
			} else {
				if (!PutChar(sig, ch)) return false;
			}
		} else if (stat == STAT_FlagsPre) {
			if (ch == '%') {
				if (!PutChar(sig, ch)) return false;
				stat = STAT_Start;
			} else {
				if (source.IsEnd()) {
					SetError_NotEnoughArguments(sig);
					break;
				}
				// initialize flags
				flags.upperCaseFlag = false;
				flags.leftAlignFlag = false;
				flags.sharpFlag = false;
				flags.fieldMinWidth = 0;
				flags.precision = -1;	// minus value means unspecified state
				flags.plusMode = PLUSMODE_None;
				flags.charPadding = ' ';
				eatNextFlag = false;
				stat = STAT_Flags;
			}
		} else if (stat == STAT_Flags) {
			if (ch == '#') {
				flags.sharpFlag = true;
			} else if (ch == '0') {
				if (!flags.leftAlignFlag) {
					flags.charPadding = '0';
				}
			} else if (ch == '-') {
				flags.leftAlignFlag = true;
				flags.charPadding = ' ';
			} else if (ch == ' ') {
				if (flags.plusMode == PLUSMODE_None) {
					flags.plusMode = PLUSMODE_Space;
				}
				stat = STAT_FlagsAfterWhite;
			} else if (ch == '+') {
				flags.plusMode = PLUSMODE_Plus;
			} else if (ch == '*') {
				Value value = source.GetInt();
				if (!value.Is_number()) {
					sig.SetError(ERR_ValueError, "number is expected for * specifier");
					break;
				}
				flags.fieldMinWidth = static_cast<int>(value.GetNumber());
				if (flags.fieldMinWidth < 0) {
					flags.leftAlignFlag = true;
					flags.fieldMinWidth = -flags.fieldMinWidth;
				}
				if (source.IsEnd()) {
					SetError_NotEnoughArguments(sig);
					break;
				}
			} else if ('0' < ch && ch <= '9') {
				eatNextFlag = false;
				stat = STAT_Padding;
			} else if (ch == '.') {
				flags.precision = 0;
				stat = STAT_PrecisionPre;
			} else if (ch == 'l') {
				// just ignore it
			} else if (ch == 'd' || ch == 'i') {
				Value value = source.GetInt();
				if (!value.GetClass()->Format_d(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'u') {
				Value value = source.GetInt();
				if (!value.GetClass()->Format_u(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'b') {
				Value value = source.GetInt();
				if (!value.GetClass()->Format_b(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'o') {
				Value value = source.GetInt();
				if (!value.GetClass()->Format_o(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'x' || ch == 'X') {
				Value value = source.GetInt();
				flags.upperCaseFlag = (ch == 'X');
				if (!value.GetClass()->Format_x(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'e' || ch == 'E') {
				Value value = source.GetDouble();
				flags.upperCaseFlag = (ch == 'E');
				if (!value.GetClass()->Format_e(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'f' || ch == 'F') {
				Value value = source.GetDouble();
				if (!value.GetClass()->Format_f(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'g' || ch == 'G') {
				Value value = source.GetDouble();
				flags.upperCaseFlag = (ch == 'G');
				if (!value.GetClass()->Format_g(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 's') {
				Value value = source.GetString();
				if (!value.GetClass()->Format_s(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else if (ch == 'c') {
				Value value = source.GetInt();
				if (!value.GetClass()->Format_c(sig, this, flags, value)) break;
				stat = STAT_Start;
			} else {
				SetError_WrongFormat(sig);
				break;
			}
		} else if (stat == STAT_FlagsAfterWhite) {
			if (ch == ' ') {
				SetError_WrongFormat(sig);
				break;
			} else {
				eatNextFlag = false;
				stat = STAT_Flags;
			}
		} else if (stat == STAT_Padding) {
			if ('0' <= ch && ch <= '9') {
				flags.fieldMinWidth = flags.fieldMinWidth * 10 + (ch - '0');
			} else {
				eatNextFlag = false;
				stat = STAT_Flags;
			}
		} else if (stat == STAT_PrecisionPre) {
			if (ch == '*') {
				Value value = source.GetInt();
				if (!value.Is_number()) {
					sig.SetError(ERR_ValueError, "number is expected for * specifier");
					break;
				}
				flags.precision = static_cast<int>(value.GetNumber());
				if (flags.precision < 0) flags.precision = 0;
				if (source.IsEnd()) {
					SetError_NotEnoughArguments(sig);
					break;
				}
				stat = STAT_Flags;
			} else if ('0' < ch && ch <= '9') {
				eatNextFlag = false;
				stat = STAT_Precision;
			} else {
				stat = STAT_Flags;
			}
		} else if (stat == STAT_Precision) {
			if ('0' <= ch && ch <= '9') {
				flags.precision = flags.precision * 10 + (ch - '0');
			} else {
				eatNextFlag = false;
				stat = STAT_Flags;
			}
		}
		if (eatNextFlag) formatp++;
	}
	return !sig.IsSignalled();
}

bool Formatter::PutString(Signal sig, const char *p)
{
	for ( ; *p != '\0'; p++) if (!PutChar(sig, *p)) return false;
	return true;
}

bool Formatter::PutAlignedString(Signal sig, const Flags &flags, const char *p, int cntMax)
{
	int cnt = static_cast<int>(::strlen(p));
	if (cntMax >= 0 && cnt > cntMax) cnt = cntMax;
	int cntPadding = flags.fieldMinWidth - static_cast<int>(Width(p));
	if (flags.leftAlignFlag) {
		for ( ; cnt > 0; p++, cnt--) if (!PutChar(sig, *p)) return false;
		while (cntPadding-- > 0) if (!PutChar(sig, flags.charPadding)) return false;
	} else {
		while (cntPadding-- > 0) if (!PutChar(sig, flags.charPadding)) return false;
		for ( ; cnt > 0; p++, cnt--) if (!PutChar(sig, *p)) return false;
	}
	return true;
}

bool Formatter::PutInvalid(Signal sig, const Flags &flags)
{
	if (!_nilVisibleFlag) return true;
	std::string str;
	str += Gura_Symbol(nil)->GetName();
	return PutAlignedString(sig, flags, str.c_str());
}

String Formatter::Format(Signal sig,
						const char *format, const ValueList &valList)
{
	FormatterString formatter;
	formatter.DoFormat(sig, format, valList);
	return formatter.GetStringSTL();
}

String Formatter::Format(Signal sig, const char *format, va_list ap)
{
	FormatterString formatter;
	formatter.DoFormat(sig, format, ap);
	return formatter.GetStringSTL();
}

Value Formatter::Format(Environment &env, Signal sig,
						const char *format, IteratorOwner &iterOwner)
{
	Value result;
	ValueList &valListResult = result.InitAsList(env);
	ValueList valList;
	while (iterOwner.Next(env, sig, valList)) {
		String str = Format(sig, format, valList);
		if (sig.IsSignalled()) return Value::Null;
		valListResult.push_back(Value(str));
	}
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

const char *Formatter::Format_d(const Flags &flags, int value, char *buff, size_t size)
{
	char *p = buff + size - 1;
	*p = '\0';
	if (value == 0) {
		if (flags.precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else if (value > 0) {
		int nCols = 0;
		for ( ; value != 0; value /= 10, nCols++) {
			p--;
			*p = (value % 10) + '0';
		}
		if (nCols < flags.precision) {
			int precision = ChooseMin(flags.precision, static_cast<int>(size) - 2);
			int cnt = precision - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		if (flags.plusMode == PLUSMODE_Space) {
			p--;
			*p = ' ';
		} else if (flags.plusMode == PLUSMODE_Plus) {
			p--;
			*p = '+';
		}
	} else {
		int nCols = 0;
		UInt valueNeg = -value;
		for ( ; valueNeg != 0; valueNeg /= 10, nCols++) {
			p--;
			*p = (valueNeg % 10) + '0';
		}
		if (nCols < flags.precision) {
			int precision = ChooseMin(flags.precision, static_cast<int>(size) - 2);
			int cnt = precision - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		p--;
		*p = '-';
	}
	return p;
}

const char *Formatter::Format_u(const Flags &flags, UInt value, char *buff, size_t size)
{
	char *p = buff + size - 1;
	*p = '\0';
	if (value == 0) {
		if (flags.precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; value != 0; value /= 10, nCols++) {
			p--;
			*p = (value % 10) + '0';
		}
		if (nCols < flags.precision) {
			int precision = ChooseMin(flags.precision, static_cast<int>(size) - 1);
			int cnt = precision - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
	}
	return p;
}

const char *Formatter::Format_b(const Flags &flags, UInt value, char *buff, size_t size)
{
	char *p = buff + size - 1;
	*p = '\0';
	if (value == 0) {
		if (flags.precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; value != 0; value >>= 1, nCols++) {
			p--;
			*p = '0' + (value & 0x1);
		}
		if (nCols < flags.precision) {
			int precision = ChooseMin(flags.precision, static_cast<int>(size) - 1);
			int cnt = precision - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		} else if (flags.sharpFlag) {
			p--;
			*p = 'b';
			p--;
			*p = '0';
		}
	}
	return p;
}

const char *Formatter::Format_o(const Flags &flags, UInt value, char *buff, size_t size)
{
	char *p = buff + size - 1;
	*p = '\0';
	if (value == 0) {
		if (flags.precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; value != 0; value >>= 3, nCols++) {
			p--;
			*p = '0' + (value & 0x7);
		}
		if (nCols < flags.precision) {
			int precision = ChooseMin(flags.precision, static_cast<int>(size) - 1);
			int cnt = precision - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		} else if (flags.sharpFlag) {
			p--;
			*p = '0';
		}
	}
	return p;
}

const char *Formatter::Format_x(const Flags &flags, UInt value, char *buff, size_t size)
{
	char *p = buff + size - 1;
	*p = '\0';
	const char *convTbl = flags.upperCaseFlag?
						"0123456789ABCDEF" : "0123456789abcdef";
	if (value == 0) {
		if (flags.precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; value != 0; value >>= 4, nCols++) {
			p--;
			*p = convTbl[value & 0xf];
		}
		if (nCols < flags.precision) {
			int precision = ChooseMin(flags.precision, static_cast<int>(size) - 3);
			int cnt = precision - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		if (flags.sharpFlag) {
			p--;
			*p = flags.upperCaseFlag? 'X' : 'x';
			p--;
			*p = '0';
		}
	}
	return p;
}

const char *Formatter::Format_e(const Flags &flags, double value, char *buff, size_t size)
{
	::snprintf(buff, size, ComposeFlags(flags, flags.upperCaseFlag? "E" : "e").c_str(), value);
	return buff;
}

const char *Formatter::Format_f(const Flags &flags, double value, char *buff, size_t size)
{
	::snprintf(buff, size, ComposeFlags(flags, "f").c_str(), value);
	return buff;
}

const char *Formatter::Format_g(const Flags &flags, double value, char *buff, size_t size)
{
	::snprintf(buff, size, ComposeFlags(flags, flags.upperCaseFlag? "G" : "g").c_str(), value);
	return buff;
}

String Formatter::ComposeFlags(const Formatter::Flags &flags, const char *qualifier)
{
	String fmt = "%";
	if (flags.leftAlignFlag) fmt += "-";
	if (flags.sharpFlag) fmt += "#";
	if (flags.charPadding == '0') fmt += '0';
	if (flags.plusMode == Formatter::PLUSMODE_Space) {
		fmt += " ";
	} else if (flags.plusMode == Formatter::PLUSMODE_Plus) {
		fmt += "+";
	}
	if (flags.fieldMinWidth > 0) {
		char buff[64];
		::sprintf(buff, "%d", flags.fieldMinWidth);
		fmt += buff;
	}
	if (flags.precision >= 0) {
		char buff[64];
		::sprintf(buff, ".%d", flags.precision);
		fmt += buff;
	}
	fmt += qualifier;
	return fmt;
}

char *Formatter::FillZeroDigit(char *dstp, char *dstpEnd, int cnt)
{
	for ( ; cnt > 0 && dstp < dstpEnd - 1; cnt--, dstp++) {
		*dstp = '0';
	}
	*dstp = '\0';
	return dstp;
}

char *Formatter::CopyDigits(char *dstp, char *dstpEnd, const char *srcp)
{
	for ( ; *srcp != '\0' && dstp < dstpEnd - 1; srcp++, dstp++) {
		*dstp = static_cast<char>(*srcp);
	}
	*dstp = '\0';
	return dstp;
}

char *Formatter::CopyDigits(char *dstp, char *dstpEnd, const char *srcp, int cnt)
{
	for ( ; *srcp != '\0' && dstp < dstpEnd - 1 && cnt > 0; srcp++, dstp++, cnt--) {
		*dstp = static_cast<char>(*srcp);
	}
	for ( ; dstp < dstpEnd - 1 && cnt > 0; dstp++, cnt--) {
		*dstp = '0';
	}
	*dstp = '\0';
	return dstp;
}

void Formatter::SetError_WrongFormat(Signal &sig)
{
	sig.SetError(ERR_ValueError, "wrong format for formatter");
}

void Formatter::SetError_NotEnoughArguments(Signal &sig)
{
	sig.SetError(ERR_TypeError, "not enough arguments for formatter");
}

//-----------------------------------------------------------------------------
// Formatter::Source_ValueList
//-----------------------------------------------------------------------------
bool Formatter::Source_ValueList::IsEnd()
{
	return _pValue == _valList.end();
}

Value Formatter::Source_ValueList::GetInt()
{
	return *_pValue++;
}

Value Formatter::Source_ValueList::GetDouble()
{
	return *_pValue++;
}

Value Formatter::Source_ValueList::GetString()
{
	return *_pValue++;
}

//-----------------------------------------------------------------------------
// Formatter::Source_va_list
//-----------------------------------------------------------------------------
bool Formatter::Source_va_list::IsEnd()
{
	return false;
}

Value Formatter::Source_va_list::GetInt()
{
	int value = va_arg(_ap, int);
	return Value(value);
}

Value Formatter::Source_va_list::GetDouble()
{
	double value = va_arg(_ap, double);
	return Value(value);
}

Value Formatter::Source_va_list::GetString()
{
	char *value = va_arg(_ap, char *);
	return Value(value);
}

//-----------------------------------------------------------------------------
// FormatterString
//-----------------------------------------------------------------------------
bool FormatterString::PutChar(Signal slg, char ch)
{
	_str += ch;
	return true;
}

}
