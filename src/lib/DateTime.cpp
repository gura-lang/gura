#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// TimeDelta
//-----------------------------------------------------------------------------
TimeDelta::TimeDelta(long days, long secs, long usecs) :
								_days(days), _secs(secs), _usecs(usecs)
{
	_secs += _usecs / 1000000;
	_usecs %= 1000000;
	_days += _secs / (3600 * 24);
	_secs %= 3600 * 24;
	if (_usecs < 0) {
		_usecs += 1000000;
		_secs--;
	}
	if (_secs < 0) {
		_secs += 3600 * 24;
		_days--;
	}
}

String TimeDelta::ToString() const
{
	char buff[80];
	::sprintf(buff, "%lddays,%ldsecs(%02d:%02d:%02d),%ldusecs",
		GetDays(), GetSecsRaw(), GetHours(), GetMins(), GetSecs(), GetUSecs());
	return String(buff);
}

int TimeDelta::Compare(const TimeDelta &td1, const TimeDelta &td2)
{
	long result = 0;
	if ((result = td1._days - td2._days) != 0) {
	} else if ((result = td1._secs - td2._secs) != 0) {
	} else if ((result = td1._usecs - td2._usecs) != 0) {
	}
	return (result < 0)? -1 : (result > 0)? +1 : 0;
}

//-----------------------------------------------------------------------------
// DateTime
//-----------------------------------------------------------------------------
String DateTime::GetTZOffsetStr(bool colonFlag) const
{
	if (!HasTZOffset()) return String("");
	long secsOffset = GetTZOffset();
	if (secsOffset == 0) return String("Z");
	char str[32];
	if (secsOffset < 0) {
		secsOffset = -secsOffset;
		str[0] = '-';
	} else {
		str[0] = '+';
	}
	::sprintf(str + 1, colonFlag? "%02d:%02d" : "%02d%02d",
			  static_cast<int>(secsOffset / 3600),
			  static_cast<int>((secsOffset % 3600) / 60));
	return String(str);
}

void DateTime::Plus(const TimeDelta &td)
{
	long dayOfYear = GetDayOfYear();
	_usec += td.GetUSecs();
	if (_usec >= 1000000) {
		_usec -= 1000000;
		_sec++;
	}
	_sec += td.GetSecsRaw();
	if (_sec >= 3600 * 24) {
		_sec -= 3600 * 24;
		dayOfYear++;
	}
	dayOfYear += td.GetDays();
	if (dayOfYear >= 0) {
		while (dayOfYear >= GetDaysOfYear(_year)) {
			dayOfYear -= GetDaysOfYear(_year);
			_year++;
		}
	} else {
		while (dayOfYear < 0) {
			_year--;
			dayOfYear += GetDaysOfYear(_year);
		}
	}
	GetMonthDay(_year, static_cast<short>(dayOfYear), _month, _day);
}

void DateTime::Minus(const TimeDelta &td)
{
	Plus(TimeDelta(-td.GetDays(), -td.GetSecsRaw(), -td.GetUSecs()));
}

TimeDelta DateTime::Minus(const DateTime &dt) const
{
	DateTime dt1, dt2;
	if (HasTZOffset() && dt.HasTZOffset()) {
		dt1 = ToUTC();
		dt2 = dt.ToUTC();
	} else {
		dt1 = *this;
		dt2 = dt;
	}
	long daysDiff = dt1.GetDayOfYear() - dt2.GetDayOfYear();
	if (dt1.GetYear() < dt2.GetYear()) {
		for (short year = dt1.GetYear(); year < dt2.GetYear(); year++) {
			daysDiff -= GetDaysOfYear(year);
		}
	} else if (dt1.GetYear() > dt2.GetYear()) {
		for (short year = dt1.GetYear() - 1; year >= dt2.GetYear(); year--) {
			daysDiff += GetDaysOfYear(year);
		}
	}
	long secsDiff = dt1.GetSecRaw() - dt2.GetSecRaw();
	long usecsDiff = dt1.GetUSec() - dt2.GetUSec();
	return TimeDelta(daysDiff, secsDiff, usecsDiff);
}

void DateTime::SetUnixTime(ULong time)
{
	*this = DateTime(1970, 1, 1, 0, 0, 0);
	const int secsPerDay = 3600 * 24;
	Plus(TimeDelta(static_cast<long>(time / secsPerDay),
								static_cast<long>(time % secsPerDay), 0));
}

ULong DateTime::GetUnixTime() const
{
	DateTime dtOrg(1970, 1, 1, 0, 0, 0);
	TimeDelta td = Minus(dtOrg);
	return td.GetSecsRaw() + td.GetDays() * 3600 * 24;
}

DateTime DateTime::ToUTC() const
{
	long secs = HasTZOffset()? GetTZOffset() : 0;
	DateTime dateTime = *this;
	dateTime.Minus(TimeDelta(0, secs, 0));
	dateTime.SetTZOffset(0);
	return dateTime;
}

// capable of parsing the following formats
// RFC1123   Sat, 06 Nov 2010 08:49:37 GMT
// RFC1036   Saturday, 06-Nov-10 08:49:37 GMT
// asctime() Sat Nov  6 08:49:37 2010
//           Sat Nov  6 08:49:37 +0000 2010
// W3C       2010-11-06T08:49:37Z
bool DateTime::Parse(const char *str, const char **next)
{
	enum {
		STAT_Start, STAT_End,
		STAT_Weekday, STAT_Date,
		STAT_DateAscTime_Month, STAT_DateAscTime_Day,
		STAT_DateAscTime_YearPre, STAT_DateAscTime_Year,
		STAT_DateRFC_Year, STAT_DateRFC_Month, STAT_DateRFC_Day,
		STAT_W3C_Year, STAT_W3C_Month, STAT_W3C_Day,
		STAT_Time, STAT_Time_Hour, STAT_Time_Min, STAT_Time_Sec,
		STAT_TimeZone, STAT_TimeZoneName, STAT_TimeZoneDigit,
		STAT_SkipWhite,
	} stat = STAT_Start, statNext = STAT_Start;
	const char *monthNames[] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	int nCols = 0;
	String token;
	int year = 0, month = 0, day = 0;
	int hour = 0, min = 0, sec = 0;
	String timeZone;
	const char *p = str;
	for (;;) {
		char ch = *p;
		bool continueFlag = false;
		switch (stat) {
		case STAT_Start: {
			if (IsAlpha(ch)) {
				continueFlag = true;
				stat = STAT_Weekday;
			} else if (IsDigit(ch)) {
				continueFlag = true;
				stat = STAT_W3C_Year;
			} else {
				return false;
			}
			break;
		}
		case STAT_Weekday: {
			if (IsAlpha(ch)) {
				token += ch;
			} else if (IsWhite(ch) || ch == ',') {
				if (token.size() < 3) return false;
				token.clear();
				statNext = STAT_Date;
				stat = STAT_SkipWhite;
			} else {
				return false;
			}
			break;
		}
		case STAT_Date: {
			if (IsAlpha(ch)) {
				continueFlag = true;
				stat = STAT_DateAscTime_Month;
			} else if (IsDigit(ch)) {
				continueFlag = true;
				stat = STAT_DateRFC_Day;
			} else {
				return false;
			}
			break;
		}
		case STAT_W3C_Year: {
			if (IsDigit(ch)) {
				nCols++;
				year = year * 10 + (ch - '0');
				if (year > 9999 || nCols > 4) return false;
			} else if (ch == '-') {
				if (nCols != 4) return false;
				nCols = 0;
				stat = STAT_W3C_Month;
			} else {
				return false;
			}
			break;
		}
		case STAT_W3C_Month: {
			if (IsDigit(ch)) {
				nCols++;
				month = month * 10 + (ch - '0');
				if (month > 12 || nCols > 2) return false;
			} else if (ch == '-') {
				if (nCols != 2) return false;
				nCols = 0;
				stat = STAT_W3C_Day;
			} else {
				return false;
			}
			break;
		}
		case STAT_W3C_Day: {
			if (IsDigit(ch)) {
				nCols++;
				day = day * 10 + (ch - '0');
				if (day > 31 || nCols > 2) return false;
			} else if (ch == 'T') {
				if (nCols != 2) return false;
				nCols = 0;
				statNext = STAT_TimeZone;
				stat = STAT_Time;
			} else {
				return false;
			}
			break;
		}
		case STAT_DateAscTime_Month: {
			if (IsAlpha(ch)) {
				token += ch;
			} else if (IsWhite(ch)) {
				int i = 0;
				for (i = 0; i < ArraySizeOf(monthNames); i++) {
					if (::strcasecmp(token.c_str(), monthNames[i]) == 0) break;
				}
				if (i == ArraySizeOf(monthNames)) return false;
				month = i + 1;
				token.clear();
				statNext = STAT_DateAscTime_Day;
				stat = STAT_SkipWhite;
			} else {
				return false;
			}
			break;
		}
		case STAT_DateAscTime_Day: {
			if (IsDigit(ch)) {
				nCols++;
				day = day * 10 + (ch - '0');
				if (day > 31 || nCols > 2) return false;
			} else if (IsWhite(ch)) {
				nCols = 0;
				statNext = STAT_DateAscTime_YearPre;
				stat = STAT_Time;
			} else {
				return false;
			}
			break;
		}
		case STAT_DateAscTime_YearPre: {
			if (IsDigit(ch)) {
				continueFlag = true;
				stat = STAT_DateAscTime_Year;
			} else if (IsAlpha(ch) || ch == '+' || ch == '-') {
				continueFlag = true;
				statNext = STAT_DateAscTime_YearPre;
				stat = STAT_TimeZone;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				return false;
			}
			break;
		}
		case STAT_DateAscTime_Year: {
			if (IsDigit(ch)) {
				nCols++;
				year = year * 10 + (ch - '0');
				if (year > 9999 || nCols > 4) return false;
			} else {
				ch = '\0';
			}
			break;
		}
		case STAT_DateRFC_Day: {
			if (IsDigit(ch)) {
				nCols++;
				day = day * 10 + (ch - '0');
				if (day > 31 || nCols > 2) return false;
			} else if (IsWhite(ch) || ch == '-') {
				nCols = 0;
				statNext = STAT_DateRFC_Month;
				stat = STAT_SkipWhite;
			} else {
				return false;
			}
			break;
		}
		case STAT_DateRFC_Month: {
			if (IsAlpha(ch)) {
				token += ch;
			} else if (IsWhite(ch) || ch == '-') {
				int i = 0;
				for (i = 0; i < ArraySizeOf(monthNames); i++) {
					if (::strcasecmp(token.c_str(), monthNames[i]) == 0) break;
				}
				if (i == ArraySizeOf(monthNames)) return false;
				month = i + 1;
				token.clear();
				statNext = STAT_DateRFC_Year;
				stat = STAT_SkipWhite;
			} else {
				return false;
			}
			break;
		}
		case STAT_DateRFC_Year: {
			if (IsDigit(ch)) {
				nCols++;
				year = year * 10 + (ch - '0');
				if (year > 9999 || nCols > 4) return false;
			} else if (IsWhite(ch)) {
				if (nCols == 2) {
					year += (year < 70)? 2000 : 1900;
				} else if (nCols != 4) {
					return false;
				}
				nCols = 0;
				statNext = STAT_TimeZone;
				stat = STAT_Time;
			} else {
				return false;
			}
			break;
		}
		case STAT_Time: {
			if (IsWhite(ch)) {
				// nothing to do
			} else if (IsDigit(ch)) {
				continueFlag = true;
				stat = STAT_Time_Hour;
			} else {
				return false;
			}
			break;
		}
		case STAT_Time_Hour: {
			if (IsDigit(ch)) {
				nCols++;
				hour = hour * 10 + (ch - '0');
				if (hour > 23 || nCols > 2) return false;
			} else if (ch == ':') {
				if (nCols != 2) return false;
				nCols = 0;
				stat = STAT_Time_Min;
			} else {
				return false;
			}
			break;
		}
		case STAT_Time_Min: {
			if (IsDigit(ch)) {
				nCols++;
				min = min * 10 + (ch - '0');
				if (min > 59 || nCols > 2) return false;
			} else if (ch == ':') {
				if (nCols != 2) return false;
				nCols = 0;
				stat = STAT_Time_Sec;
			} else {
				return false;
			}
			break;
		}
		case STAT_Time_Sec: {
			if (IsDigit(ch)) {
				nCols++;
				sec = sec * 10 + (ch - '0');
				if (sec > 59 || nCols > 2) return false;
			} else {
				if (nCols != 2) return false;
				nCols = 0;
				continueFlag = true;
				stat = statNext;
				statNext = STAT_End;
			}
			break;
		}
		case STAT_TimeZone: {
			if (IsAlpha(ch)) {
				continueFlag = true;
				stat = STAT_TimeZoneName;
			} else if (ch == '+' || ch == '-') {
				timeZone = ch;
				stat = STAT_TimeZoneDigit;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				return false;
			}
			break;
		}
		case STAT_TimeZoneName: {
			if (IsAlpha(ch)) {
				timeZone += ch;
			} else {
				continueFlag = true;
				stat = statNext;
				statNext = STAT_End;
			}
			break;
		}
		case STAT_TimeZoneDigit: {
			if (IsDigit(ch)) {
				timeZone += ch;
				if (timeZone.size() > 5) return false;
			} else if (ch == ':' && timeZone.size() == 3) {
				// accept ':' character between hour and minute fields
			} else {
				if (timeZone.size() != 5) return false;
				continueFlag = true;
				stat = statNext;
				statNext = STAT_End;
			}
			break;
		}
		case STAT_SkipWhite: {
			if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				stat = statNext;
				statNext = STAT_End;
			}
			break;
		}
		case STAT_End: {
			ch = '\0';
			break;
		}
		}
		if (continueFlag) {
			// nothing to do
		} else if (ch == '\0') {
			break;
		} else {
			p++;
		}
	}
	if (next != NULL) *next = p;
	_year = static_cast<short>(year);
	_month = static_cast<char>(month);
	_day = static_cast<char>(day);
	_sec = static_cast<long>(hour * 3600 + min * 60 + sec);
	_usec = 0;
	if (timeZone.empty()) {
		// nothing to do
	} else if (IsAlpha(timeZone[0])) {
		// the list contains timezone names that are described in RFC 822 and JST.
		static const struct {
			const char *name;
			long minsOffset;
		} tbl[] = {
			{ "GMT",	  0 * 60	},
			{ "UT",		  0 * 60	},
			{ "Z",		  0 * 60	},
			{ "A",		 -1 * 60	},
			{ "M",		-12 * 60	},
			{ "N",		  1 * 60	},
			{ "Y",		 12 * 60	},
			{ "JST",	  9 * 60	},
		};
		for (int i = 0; i < ArraySizeOf(tbl); i++) {
			if (::strcasecmp(timeZone.c_str(), tbl[i].name) == 0) {
				_tz.validFlag = true;
				_tz.secsOffset = tbl[i].minsOffset * 60;
				break;
			}
		}
	} else if (timeZone[0] == '+' || timeZone[0] == '-') {
		int signNum = (timeZone[0] == '-')? -1 : +1;
		int hours = (timeZone[1] - '0') * 10 + (timeZone[2] - '0');
		int mins = (timeZone[3] - '0') * 10 + (timeZone[4] - '0');
		_tz.validFlag = true;
		_tz.secsOffset = signNum * (hours * 3600 + mins * 60);
	}
	return true;
}

String DateTime::ToString(const char *format) const
{
	String rtn;
	for (const char *p = format; *p != '\0'; p++) {
		if (*p != '%') {
			rtn.push_back(*p);
			continue;
		}
		char buff[32];
		p++;
		char ch = *p;
		if (ch == 'a') {			// locale
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'A') {		// locale
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'b') {		// locale
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'B') {		// locale
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'c') {		// locale
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'd') {
			::sprintf(buff, "%02d", GetDay());
			rtn += buff;
		} else if (ch == 'H') {
			::sprintf(buff, "%02d", GetHour());
			rtn += buff;
		} else if (ch == 'I') {
			char hour = GetHour();
			::sprintf(buff, "%02d", (hour == 0)? 12 : (hour > 12)? hour - 12 : hour);
			rtn += buff;
		} else if (ch == 'j') {
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'm') {
			::sprintf(buff, "%02d", GetMonth());
			rtn += buff;
		} else if (ch == 'M') {
			::sprintf(buff, "%02d", GetMin());
			rtn += buff;
		} else if (ch == 'p') {		// locale
			
		} else if (ch == 'S') {
			::sprintf(buff, "%02d", GetSec());
			rtn += buff;
		} else if (ch == 'U') {
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'w') {
			::sprintf(buff, "%d", GetDayOfWeek());
			rtn += buff;
		} else if (ch == 'W') {
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'x') {		// locale
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'X') {		// locale
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == 'y') {
			::sprintf(buff, "%02d", GetYear() % 100);
			rtn += buff;
		} else if (ch == 'Y') {
			::sprintf(buff, "%04d", GetYear());
			rtn += buff;
		} else if (ch == 'Z') {
			::sprintf(buff, "****");
			rtn += buff;
		} else if (ch == '%') {
			rtn.push_back(ch);
		} else {
			rtn.push_back(ch);
		}
	}
	return rtn;
}

char DateTime::GetDaysOfMonth(short year, char month)
{
	static const char daysTbl_Normal[] = {
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	};
	static const char daysTbl_Leap[] = {
		0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	};
	if (month < 1 || month > 12) return -1;
	return (IsLeapYear(year)? daysTbl_Leap : daysTbl_Normal)[month];
}

short DateTime::GetDayOfYear(short year, char month, char day)
{
	static const short offsetTbl_Normal[] = {
		0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334,
	};
	static const short offsetTbl_Leap[] = {
		0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335,
	};
	if (day < 1 || month < 1 || month > 12) return -1;
	return (IsLeapYear(year)? offsetTbl_Leap : offsetTbl_Normal)[month] + day - 1;
}

void DateTime::GetMonthDay(short year, short dayOfYear, char &month, char &day)
{
	static const short offsetTbl_Normal[] = {
		0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334,
	};
	static const short offsetTbl_Leap[] = {
		0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335,
	};
	const short *offsetTbl = IsLeapYear(year)? offsetTbl_Leap : offsetTbl_Normal;
	int i = 0;
	for ( ; i < 12 && dayOfYear >= offsetTbl[i]; i++) ;
	i--;
	month = static_cast<char>(i + 1);
	day = static_cast<char>(dayOfYear - offsetTbl[i] + 1);
}

// Zeller's congruence. treat 0 as Sunday
char DateTime::GetDayOfWeek(short year, char month, char day)
{
	if (day < 1 || month < 1 || month > 12) return -1;
	if (month <= 2) {
		month += 12, year -= 1;
	}
	short yearH = year / 100, yearL = year % 100;
	int rtn = yearL + yearL / 4 + yearH / 4 - 2 * yearH +
							13 * (static_cast<int>(month) + 1) / 5 + day;
	rtn %= 7;
	if (rtn < 0) rtn += 7;
	return (rtn + 6) % 7;
}

int DateTime::Compare(const DateTime &dt1, const DateTime &dt2)
{
	long result = 0;
	DateTime dt1utc = dt1.ToUTC();
	DateTime dt2utc = dt2.ToUTC();
	if ((result = dt1utc._year - dt2utc._year) != 0) {
	} else if ((result = dt1utc._month - dt2utc._month) != 0) {
	} else if ((result = dt1utc._day - dt2utc._day) != 0) {
	} else if ((result = dt1utc._sec - dt2utc._sec) != 0) {
	} else if ((result = dt1utc._usec - dt2utc._usec) != 0) {
	}
	return (result < 0)? -1 : (result > 0)? +1 : 0;
}

}
