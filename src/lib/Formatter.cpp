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
	bool eatNextFlag;
	const char *formatp = format;
	Flags flags;
	ValueList::const_iterator pValue = valList.begin();
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
					PutChar(*p);
				}
			} else {
				PutChar(ch);
			}
		} else if (stat == STAT_FlagsPre) {
			if (ch == '%') {
				PutChar(ch);
				stat = STAT_Start;
			} else {
				if (pValue == valList.end()) {
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
				if (!pValue->Is_number()) {
					sig.SetError(ERR_ValueError, "number is expected for * specifier");
					break;
				}
				flags.fieldMinWidth = static_cast<int>(pValue->GetNumber());
				if (flags.fieldMinWidth < 0) {
					flags.leftAlignFlag = true;
					flags.fieldMinWidth = -flags.fieldMinWidth;
				}
				pValue++;
				if (pValue == valList.end()) {
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
				if (!pValue->GetClass()->Format_d(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'u') {
				if (!pValue->GetClass()->Format_u(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'b') {
				if (!pValue->GetClass()->Format_b(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'o') {
				if (!pValue->GetClass()->Format_o(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'x' || ch == 'X') {
				flags.upperCaseFlag = (ch == 'X');
				if (!pValue->GetClass()->Format_x(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'e' || ch == 'E') {
				flags.upperCaseFlag = (ch == 'E');
				if (!pValue->GetClass()->Format_e(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'f' || ch == 'F') {
				flags.upperCaseFlag = (ch == 'F');
				if (!pValue->GetClass()->Format_f(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'g' || ch == 'G') {
				flags.upperCaseFlag = (ch == 'G');
				if (!pValue->GetClass()->Format_g(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 's') {
				if (!pValue->GetClass()->Format_s(sig, this, flags, *pValue)) break;
				pValue++;
				stat = STAT_Start;
			} else if (ch == 'c') {
				if (!pValue->GetClass()->Format_c(sig, this, flags, *pValue)) break;
				pValue++;
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
				if (!pValue->Is_number()) {
					sig.SetError(ERR_ValueError, "number is expected for * specifier");
					break;
				}
				flags.precision = static_cast<int>(pValue->GetNumber());
				if (flags.precision < 0) flags.precision = 0;
				pValue++;
				if (pValue == valList.end()) {
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

void Formatter::PutAlignedString(const Flags &flags, const char *p, int cntMax)
{
	int cnt = static_cast<int>(::strlen(p));
	if (cntMax >= 0 && cnt > cntMax) cnt = cntMax;
	int cntPadding = flags.fieldMinWidth - static_cast<int>(Width(p));
	if (flags.leftAlignFlag) {
		for ( ; cnt > 0; p++, cnt--) PutChar(*p);
		while (cntPadding-- > 0) PutChar(flags.charPadding);
	} else {
		while (cntPadding-- > 0) PutChar(flags.charPadding);
		for ( ; cnt > 0; p++, cnt--) PutChar(*p);
	}
}

void Formatter::PutInvalid(const Flags &flags)
{
	if (!_nilVisibleFlag) return;
	std::string str;
	str += Gura_Symbol(nil)->GetName();
	PutAlignedString(flags, str.c_str());
}

String Formatter::Format(Signal sig,
						const char *format, const ValueList &valList)
{
	FormatterString formatter;
	formatter.DoFormat(sig, format, valList);
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
	int count = (flags.precision < 0)? 6 : flags.precision;
	int dec, sign;
	char *srcp = ::ecvt(value, count, &dec, &sign);
	dec -= 1;
	char *dstp = buff;
	if (sign) {
		*dstp++ = '-';
	} else if (flags.plusMode == PLUSMODE_Space) {
		*dstp++ = ' ';
	} else if (flags.plusMode == PLUSMODE_Plus) {
		*dstp++ = '+';
	}
	*dstp++ = static_cast<char>(*srcp++);
	if (*srcp != '\0') {
		*dstp++ = '.';
		dstp = CopyDigits(dstp, buff + size, srcp);
	}
	if (dstp < buff + size - 5) {
		*dstp++ = flags.upperCaseFlag? 'E' : 'e';
		if (dec >= 0) {
			*dstp++ = '+';
		} else {
			*dstp++ = '-';
			dec = -dec;
		}
		*dstp++ = '0' + (dec / 10) % 10;
		*dstp++ = '0' + (dec % 10);
		*dstp++ = '\0';
	}
	return buff;
}

const char *Formatter::Format_f(const Flags &flags, double value, char *buff, size_t size)
{
	int count = (flags.precision < 0)? 6 : flags.precision;
	int dec, sign;
	char *srcp = ::fcvt(value, count, &dec, &sign);
	char *dstp = buff;
	if (sign) {
		*dstp++ = '-';
	} else if (flags.plusMode == PLUSMODE_Space) {
		*dstp++ = ' ';
	} else if (flags.plusMode == PLUSMODE_Plus) {
		*dstp++ = '+';
	}
	if (dec <= 0) {
		*dstp++ = '0';
		*dstp++ = '.';
		dstp = FillZeroDigit(dstp, buff + size, -dec);
		CopyDigits(dstp, buff + size, srcp);
	} else {
		dstp = CopyDigits(dstp, buff + size, srcp, dec);
		if (::strlen(srcp) > static_cast<size_t>(dec)) {
			*dstp++ = '.';
			CopyDigits(dstp, buff + size, srcp + dec);
		}
	}
	return buff;
}

const char *Formatter::Format_g(const Flags &flags, double value, char *buff, size_t size)
{
	char *buffRaw = new char[size];
	int digits = (flags.precision < 0)? 6 : flags.precision;
	char *srcp = ::gcvt(value, digits, buffRaw);
	char *dstp = buff;
	if (*srcp == '-') {
		// nothing to do
	} else if (flags.plusMode == PLUSMODE_Space) {
		*dstp++ = ' ';
	} else if (flags.plusMode == PLUSMODE_Plus) {
		*dstp++ = '+';
	}
	const char *dstpEnd = buff + size - 1;
	char chPrev = '\0';
	for ( ; *srcp != '\0' && dstp < dstpEnd; srcp++, dstp++) {
		char ch = *srcp;
		if (ch == 'e' || ch == 'E') {
			if (chPrev == '.') dstp--;
			*dstp = flags.upperCaseFlag? 'E' : 'e';
		} else {
			*dstp = ch;
		}
		chPrev = ch;
	}
	if (chPrev == '.') dstp--;
	*dstp = '\0';
	delete[] buffRaw;
	return buff;
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
// FormatterString
//-----------------------------------------------------------------------------
void FormatterString::PutChar(char ch)
{
	_str += ch;
}

}
