#ifndef __CARRAY_H__
#define __CARRAY_H__

Gura_BeginModuleScope(wx)

//-----------------------------------------------------------------------------
// CArray
//-----------------------------------------------------------------------------
template<typename T, typename T_Conv> class CArray {
private:
	int _n;
	T *_buff;
public:
	inline CArray() : _n(0), _buff(NULL) {}
	inline CArray(const ValueList &valList) { Init(valList); }
	~CArray() {
		delete[] _buff;
	}
	void Init(const ValueList &valList) {
		_n = static_cast<int>(valList.size());
		_buff = new T [_n];
		T *buffp = _buff;
		T_Conv conv;
		foreach_const (ValueList, pValue, valList) {
			*buffp++ = conv(*pValue);
		}
	}
	inline T *Data() { return _buff; }
	inline const T *Data() const { return _buff; }
	inline int Count() const { return _n; }
};

class ValueToInt {
public:
	inline int operator()(const Value &value) const {
		return value.GetInt();
	}
};

class ValueToDash {
public:
	inline wxDash operator()(const Value &value) const {
		return static_cast<wxDash>(value.GetInt());
	}
};

class ValueToString {
public:
	inline wxString operator()(const Value &value) const {
		return wxString::FromUTF8(value.GetString());
	}
};

class ValueToPoint {
public:
	inline wxPoint operator()(const Value &value) const {
		return *Object_wx_Point::GetObject(value)->GetEntity();
	}
};

class ValueToAcceleratorEntry {
public:
	inline wxAcceleratorEntry operator()(const Value &value) const {
		return *Object_wx_AcceleratorEntry::GetObject(value)->GetEntity();
	}
};

typedef CArray<int,			ValueToInt>		CArrayOfInt;
typedef CArray<wxDash,		ValueToDash>	CArrayOfDash;
typedef CArray<wxString,	ValueToString>	CArrayOfString;
typedef CArray<wxPoint,		ValueToPoint>	CArrayOfPoint;
typedef CArray<wxAcceleratorEntry, ValueToAcceleratorEntry>	CArrayOfAcceleratorEntry;

Gura_EndModuleScope(wx)

#endif
