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
	Int32 _days;		// -999999999 <= _days <= 999999999
	Int32 _secs;		// 0 <= _secs <= 3600 * 24 - 1
	Int32 _usecs;	// 0 <= _usecs <= 999999
public:
	TimeDelta(Int32 days = 0, Int32 secs = 0, Int32 usecs = 0);
	inline TimeDelta(const TimeDelta &td) :
					_days(td._days), _secs(td._secs), _usecs(td._usecs) {}
	inline Int32 GetDays() const	{ return _days; }
	inline Int8 GetHours() const	{ return static_cast<Int8>(_secs / 3600); }		// 0-23
	inline Int8 GetMins() const		{ return static_cast<Int8>((_secs / 60) % 60); }	// 0-59
	inline Int8 GetSecs() const		{ return static_cast<Int8>(_secs % 60); }			// 0-59
	inline Int32 GetSecsRaw() const	{ return _secs; }
	inline Int32 GetUSecs() const	{ return _usecs; }
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
	Int16 _year;
	Int8 _month;
	Int8 _day;
	Int32 _sec;
	Int32 _usec;
	struct {
		bool validFlag;
		Int32 secsOffset;
	} _tz;
public:
	inline DateTime() : _year(0), _month(0), _day(0), _sec(0), _usec(0) {
		_tz.validFlag = false, _tz.secsOffset = 0;
	}
	inline DateTime(Int16 year, Int8 month, Int8 day, Int32 sec, Int32 usec) :
			_year(year), _month(month), _day(day), _sec(sec), _usec(usec) {
		_tz.validFlag = false, _tz.secsOffset = 0;
	}
	inline DateTime(Int16 year, Int8 month, Int8 day, Int32 sec, Int32 usec, Int32 secsOffset) :
			_year(year), _month(month), _day(day), _sec(sec), _usec(usec) {
		_tz.validFlag = true, _tz.secsOffset = secsOffset;
	}
	inline DateTime(const DateTime &dt) :
			_year(dt._year), _month(dt._month), _day(dt._day),
			_sec(dt._sec), _usec(dt._usec), _tz(dt._tz) {}
	DateTime(const time_t *timep);
	DateTime &operator=(const DateTime &dt) {
		_year = dt._year, _month = dt._month, _day = dt._day;
		_sec = dt._sec, _usec = dt._usec;
		_tz = dt._tz;
		return *this;
	}
	bool Parse(const char *str, const char **next = nullptr);
	String ToString(const char *format) const;
	inline void Invalidate()			{ _month = 0; }
	inline bool IsValid() const			{ return _month != 0; }
	inline Int16 GetYear() const		{ return _year; }	// 0-9999
	inline Int8 GetMonth() const		{ return _month; }	// 1-12
	inline Int8 GetDay() const			{ return _day; }	// 1-31
	inline Int8 GetHour() const			{ return static_cast<Int8>(_sec / 3600); }		// 0-23
	inline Int8 GetMin() const			{ return static_cast<Int8>((_sec / 60) % 60); }	// 0-59
	inline Int8 GetSec() const			{ return static_cast<Int8>(_sec % 60); }			// 0-59
	inline Int32 GetSecRaw() const		{ return _sec; }	// 0 - (3600 * 24 - 1)
	inline Int32 GetUSec() const		{ return _usec; }	// 0 - 999999
	inline bool IsLeapYear() const		{ return IsLeapYear(_year); }
	inline Int32 GetMSecOfDay() const	{ return _sec * 1000 + _usec / 1000; }
	inline Int16 GetDaysOfYear() const	{ return GetDaysOfYear(_year); }
	inline Int16 GetDayOfYear() const	{ return GetDayOfYear(_year, _month, _day); }
	inline Int8 GetDayOfWeek() const	{ return GetDayOfWeek(_year, _month, _day); }
	inline void SetYear(Int16 year)		{ _year = year; }
	inline void SetMonth(Int8 month)	{ _month = month; }
	inline void SetDay(Int8 day)		{ _day = day; }
	inline void SetHour(Int8 hour) {
		_sec = static_cast<Int32>(hour) * 3600 + static_cast<Int32>(GetMin()) * 60 + GetSec();
	}
	inline void SetMin(Int8 min) {
		_sec = static_cast<Int32>(GetHour()) * 3600 + static_cast<Int32>(min) * 60 + GetSec();
	}
	inline void SetSec(Int8 sec) {
		_sec = static_cast<Int32>(GetHour()) * 3600 + static_cast<Int32>(GetMin()) * 60 + sec;
	}
	inline void SetUSec(Int32 usec)		{ _usec = usec; }
	inline void ClearTime() { _sec = 0, _usec = 0; }
	inline Int32 GetTZOffset() const { return _tz.secsOffset; }
	inline bool HasTZOffset() const { return _tz.validFlag; }
	inline void SetTZOffset(Int32 secsOffset) {
		_tz.validFlag = true, _tz.secsOffset = secsOffset;
	}
	inline void ClearTZOffset() { _tz.validFlag = false; }
	String GetTZOffsetStr(bool colonFlag) const;
	void Plus(const TimeDelta &td);
	void Minus(const TimeDelta &td);
	bool HasValidUnixTime() const;
	time_t GetUnixTime() const;
	DateTime ToUTC() const;
	TimeDelta Minus(const DateTime &dt) const;
	static inline bool IsLeapYear(Int16 year) {
		return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
	}
	static inline Int16 GetDaysOfYear(Int16 year) {
		return IsLeapYear(year)? 366 : 365;
	}
	static Int16 GetDayOfYear(Int16 year, Int8 month, Int8 day);
	static void GetMonthDay(Int16 year, Int16 dayOfYear, Int8 &month, Int8 &day);
	static Int8 GetDayOfWeek(Int16 year, Int8 month, Int8 day);
	static Int8 GetDaysOfMonth(Int16 year, Int8 month);
	static void Add(DateTime &dtRtn, const DateTime &dt, const TimeDelta &td);
	static void Add(DateTime &dtRtn, const TimeDelta &td, const DateTime &dt);
	static void Sub(DateTime &dtRtn, const DateTime &dt, const TimeDelta &td);
	static bool Sub(Signal &sig, TimeDelta &tdRtn, const DateTime &dt1, const DateTime &dt2);
	static int Compare(const DateTime &dt1, const DateTime &dt2);
};

}

#endif
