//=============================================================================
// DateTime
//=============================================================================
#ifndef __GURA_DATETIME_H__
#define __GURA_DATETIME_H__
#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// TimeDelta
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE TimeDelta {
private:
	long _days;		// -999999999 <= _days <= 999999999
	long _secs;		// 0 <= _secs <= 3600 * 24 - 1
	long _usecs;	// 0 <= _usecs <= 999999
public:
	TimeDelta(long days = 0, long secs = 0, long usecs = 0);
	inline TimeDelta(const TimeDelta &td) :
					_days(td._days), _secs(td._secs), _usecs(td._usecs) {}
	inline long GetDays() const		{ return _days; }
	inline char GetHours() const	{ return static_cast<char>(_secs / 3600); }		// 0-23
	inline char GetMins() const		{ return static_cast<char>((_secs / 60) % 60); }	// 0-59
	inline char GetSecs() const		{ return static_cast<char>(_secs % 60); }			// 0-59
	inline long GetSecsRaw() const	{ return _secs; }
	inline long GetUSecs() const	{ return _usecs; }
	void Plus(const TimeDelta &td);
	void Minus(const TimeDelta &td);
	void Regulate();
	String ToString() const;
	static int Compare(const TimeDelta &td1, const TimeDelta &td2);
};

//-----------------------------------------------------------------------------
// DateTime
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE DateTime {
private:
	short _year;
	char _month;
	char _day;
	long _sec;
	long _usec;
	struct {
		bool validFlag;
		long secsOffset;
	} _tz;
public:
	inline DateTime() : _year(0), _month(0), _day(0), _sec(0), _usec(0) {
		_tz.validFlag = false, _tz.secsOffset = 0;
	}
	inline DateTime(short year, char month, char day, long sec, long usec) :
			_year(year), _month(month), _day(day), _sec(sec), _usec(usec) {
		_tz.validFlag = false, _tz.secsOffset = 0;
	}
	inline DateTime(short year, char month, char day, long sec, long usec, long secsOffset) :
			_year(year), _month(month), _day(day), _sec(sec), _usec(usec) {
		_tz.validFlag = true, _tz.secsOffset = secsOffset;
	}
	inline DateTime(const DateTime &dt) :
			_year(dt._year), _month(dt._month), _day(dt._day),
			_sec(dt._sec), _usec(dt._usec), _tz(dt._tz) {}
	DateTime &operator=(const DateTime &dt) {
		_year = dt._year, _month = dt._month, _day = dt._day;
		_sec = dt._sec, _usec = dt._usec;
		_tz = dt._tz;
		return *this;
	}
	bool Parse(const char *str, const char **next = NULL);
	String ToString(const char *format) const;
	inline void Invalidate()			{ _month = 0; }
	inline bool IsValid() const			{ return _month != 0; }
	inline short GetYear() const		{ return _year; }	// 0-9999
	inline char GetMonth() const		{ return _month; }	// 1-12
	inline char GetDay() const			{ return _day; }	// 1-31
	inline char GetHour() const			{ return static_cast<char>(_sec / 3600); }		// 0-23
	inline char GetMin() const			{ return static_cast<char>((_sec / 60) % 60); }	// 0-59
	inline char GetSec() const			{ return static_cast<char>(_sec % 60); }			// 0-59
	inline long GetSecRaw() const		{ return _sec; }	// 0 - (3600 * 24 - 1)
	inline long GetUSec() const			{ return _usec; }	// 0 - 999999
	inline bool IsLeapYear() const		{ return IsLeapYear(_year); }
	inline long GetMSecOfDay() const	{ return _sec * 1000 + _usec / 1000; }
	inline short GetDaysOfYear() const	{ return GetDaysOfYear(_year); }
	inline short GetDayOfYear() const	{ return GetDayOfYear(_year, _month, _day); }
	inline char GetDayOfWeek() const	{ return GetDayOfWeek(_year, _month, _day); }
	inline void SetYear(short year)		{ _year = year; }
	inline void SetMonth(char month)	{ _month = month; }
	inline void SetDay(char day)		{ _day = day; }
	inline void SetHour(char hour) {
		_sec = static_cast<long>(hour) * 3600 + static_cast<long>(GetMin()) * 60 + GetSec();
	}
	inline void SetMin(char min) {
		_sec = static_cast<long>(GetHour()) * 3600 + static_cast<long>(min) * 60 + GetSec();
	}
	inline void SetSec(char sec) {
		_sec = static_cast<long>(GetHour()) * 3600 + static_cast<long>(GetMin()) * 60 + sec;
	}
	inline void SetUSec(long usec)		{ _usec = usec; }
	inline void ClearTime() { _sec = 0, _usec = 0; }
	inline long GetTZOffset() const { return _tz.secsOffset; }
	inline bool HasTZOffset() const { return _tz.validFlag; }
	inline void SetTZOffset(long secsOffset) {
		_tz.validFlag = true, _tz.secsOffset = secsOffset;
	}
	inline void ClearTZOffset() { _tz.validFlag = false; }
	String GetTZOffsetStr(bool colonFlag) const;
	void Plus(const TimeDelta &td);
	void Minus(const TimeDelta &td);
	void SetUnixTime(ULong time);
	ULong GetUnixTime() const;
	DateTime ToUTC() const;
	TimeDelta Minus(const DateTime &dt) const;
	static inline bool IsLeapYear(short year) {
		return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
	}
	static inline short GetDaysOfYear(short year) {
		return IsLeapYear(year)? 366 : 365;
	}
	static short GetDayOfYear(short year, char month, char day);
	static void GetMonthDay(short year, short dayOfYear, char &month, char &day);
	static char GetDayOfWeek(short year, char month, char day);
	static char GetDaysOfMonth(short year, char month);
	static int Compare(const DateTime &dt1, const DateTime &dt2);
};

}

#endif
