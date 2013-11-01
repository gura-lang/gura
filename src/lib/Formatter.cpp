#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// FormatterBase
//-----------------------------------------------------------------------------
bool FormatterBase::DoFormat(Signal sig, const char *format, const ValueList &valList)
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
	char buff[128];
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
				if (!pValue->IsNumber()) {
					SetError_NumberIsExpected(sig,
									"*, specifier of variable field length");
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
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_d(flags,
						static_cast<int>(pValue->GetNumber()), buff, sizeof(buff)));
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsBoolean()) {
					PutString(flags, Conv_d(flags,
						static_cast<int>(pValue->GetBoolean()), buff, sizeof(buff)));
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberIsExpected(sig, ch);
					break;
				}
			} else if (ch == 'u') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_u(flags,
						static_cast<UInt>(pValue->GetNumber()), buff, sizeof(buff)));
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberIsExpected(sig, ch);
					break;
				}
			} else if (ch == 'b') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_b(flags,
						static_cast<UInt>(pValue->GetNumber()), buff, sizeof(buff)));
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberIsExpected(sig, ch);
					break;
				}
			} else if (ch == 'o') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_o(flags,
						static_cast<UInt>(pValue->GetNumber()), buff, sizeof(buff)));
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberIsExpected(sig, ch);
					break;
				}
			} else if (ch == 'x' || ch == 'X') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_x(flags,
						static_cast<UInt>(pValue->GetNumber()), buff, sizeof(buff),
						ch == 'X'));
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberIsExpected(sig, ch);
					break;
				}
			} else if (ch == 'e' || ch == 'E') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_e(flags,
						pValue->GetNumber(), buff, sizeof(buff), ch == 'E'));
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsComplex()) {
					PutString(flags, Conv_e(flags,
						pValue->GetComplex().real(), buff, sizeof(buff), ch == 'E'));
					PlusMode plusMode = flags.plusMode;
					flags.plusMode = PLUSMODE_Plus;
					PutString(flags, Conv_e(flags,
						pValue->GetComplex().imag(), buff, sizeof(buff), ch == 'E'));
					flags.plusMode = plusMode;
					PutChar('j');
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberOrComplexIsExpected(sig, ch);
					break;
				}
			} else if (ch == 'f' || ch == 'F') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_f(flags,
						pValue->GetNumber(), buff, sizeof(buff), ch == 'F'));
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsComplex()) {
					PutString(flags, Conv_f(flags,
						pValue->GetComplex().real(), buff, sizeof(buff), ch == 'F'));
					PlusMode plusMode = flags.plusMode;
					flags.plusMode = PLUSMODE_Plus;
					PutString(flags, Conv_f(flags,
						pValue->GetComplex().imag(), buff, sizeof(buff), ch == 'F'));
					flags.plusMode = plusMode;
					PutChar('j');
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberOrComplexIsExpected(sig, ch);
					break;
				}
			} else if (ch == 'g' || ch == 'G') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsNumber()) {
					PutString(flags, Conv_g(flags,
						pValue->GetNumber(), buff, sizeof(buff), ch == 'G'));
					pValue++;
					stat = STAT_Start;
				} else if (pValue->IsComplex()) {
					PutString(flags, Conv_g(flags,
						pValue->GetComplex().real(), buff, sizeof(buff), ch == 'G'));
					PlusMode plusMode = flags.plusMode;
					flags.plusMode = PLUSMODE_Plus;
					PutString(flags, Conv_g(flags,
						pValue->GetComplex().imag(), buff, sizeof(buff), ch == 'G'));
					flags.plusMode = plusMode;
					PutChar('j');
					pValue++;
					stat = STAT_Start;
				} else {
					SetError_NumberOrComplexIsExpected(sig, ch);
					break;
				}
			} else if (ch == 's') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else {
					PutString(flags, pValue->ToString(false).c_str(), flags.precision);
					pValue++;
					stat = STAT_Start;
				}
			} else if (ch == 'c') {
				if (pValue->IsInvalid()) {
					PutInvalid(flags);
					pValue++;
					stat = STAT_Start;
				} else {
					PutChar(static_cast<char>(pValue->GetNumber()));
					pValue++;
					stat = STAT_Start;
				}
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
				if (!pValue->IsNumber()) {
					SetError_NumberIsExpected(sig,
									"*, specifier of variable precision");
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

void FormatterBase::PutString(const Flags &flags, const char *p, int cntMax)
{
	int cnt = static_cast<int>(::strlen(p));
	if (cntMax >= 0 && cnt > cntMax) cnt = cntMax;
	int cntPadding = flags.fieldMinWidth - static_cast<int>(::strlen(p));
	if (flags.leftAlignFlag) {
		for ( ; cnt > 0; p++, cnt--) PutChar(*p);
		while (cntPadding-- > 0) PutChar(flags.charPadding);
	} else {
		while (cntPadding-- > 0) PutChar(flags.charPadding);
		for ( ; cnt > 0; p++, cnt--) PutChar(*p);
	}
}

void FormatterBase::PutInvalid(const Flags &flags)
{
	if (!_nilVisibleFlag) return;
	std::string str;
	//str += '(';
	str += Gura_Symbol(nil)->GetName();
	//str += ')';
	PutString(flags, str.c_str());
}

const char *FormatterBase::Conv_d(const Flags &flags, int value,
												char *buff, size_t size)
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

const char *FormatterBase::Conv_u(const Flags &flags, UInt value,
												char *buff, size_t size)
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

const char *FormatterBase::Conv_b(const Flags &flags, UInt value,
												char *buff, size_t size)
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

const char *FormatterBase::Conv_o(const Flags &flags, UInt value,
												char *buff, size_t size)
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

const char *FormatterBase::Conv_x(const Flags &flags, UInt value,
									char *buff, size_t size, bool upperFlag)
{
	char *p = buff + size - 1;
	*p = '\0';
	const char *convTbl = upperFlag?
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
			*p = upperFlag? 'X' : 'x';
			p--;
			*p = '0';
		}
	}
	return p;
}

const char *FormatterBase::Conv_e(const Flags &flags, double value,
							char *buff, size_t size, bool upperFlag)
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
		*dstp++ = upperFlag? 'E' : 'e';
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

const char *FormatterBase::Conv_f(const Flags &flags, double value,
							char *buff, size_t size, bool upperFlag)
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

const char *FormatterBase::Conv_g(const Flags &flags, double value,
							char *buff, size_t size, bool upperFlag)
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
			*dstp = upperFlag? 'E' : 'e';
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

char *FormatterBase::FillZeroDigit(char *dstp, char *dstpEnd, int cnt)
{
	for ( ; cnt > 0 && dstp < dstpEnd - 1; cnt--, dstp++) {
		*dstp = '0';
	}
	*dstp = '\0';
	return dstp;
}

char *FormatterBase::CopyDigits(char *dstp, char *dstpEnd, const char *srcp)
{
	for ( ; *srcp != '\0' && dstp < dstpEnd - 1; srcp++, dstp++) {
		*dstp = static_cast<char>(*srcp);
	}
	*dstp = '\0';
	return dstp;
}

char *FormatterBase::CopyDigits(char *dstp, char *dstpEnd, const char *srcp, int cnt)
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

//-----------------------------------------------------------------------------
// Formatter
//-----------------------------------------------------------------------------
String Formatter::Format(Signal sig,
						const char *format, const ValueList &valList)
{
	Formatter formatter;
	formatter.DoFormat(sig, format, valList);
	return formatter._str;
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
		valListResult.push_back(Value(env, str.c_str()));
	}
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

void Formatter::PutChar(char ch)
{
	_str += ch;
}

}
