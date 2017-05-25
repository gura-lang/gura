//=============================================================================
// Half
//=============================================================================
#ifndef __GURA_HALF_H__
#define __GURA_HALF_H__

namespace Gura {

class GURA_DLLDECLARE Half {
private:
	UInt16 _num;
private:
	static UInt32 _mantissaTable[];
	static UInt32 _exponentTable[];
	static UInt16 _offsetTable[];
	static UInt16 _baseTable[];
	static Int8 _shiftTable[];
public:
	inline Half() : _num(0) {}
	inline Half(const Half &half) : _num(half._num) {}
	inline Half(Float num) : _num(FloatToHalf(num)) {}
public:
	inline Half &operator=(const Half &half) { _num = half._num; return *this; }
public:
	inline Float ToFloat() const { return HalfToFloat(_num); }
	inline explicit operator float() const noexcept { return HalfToFloat(_num); }
	inline explicit operator double() const noexcept { return HalfToFloat(_num); }
	inline explicit operator Complex() const noexcept { return Complex(HalfToFloat(_num)); }
	inline Half &operator+=(Float var) {
		_num = FloatToHalf(ToFloat() + var);
		return *this;
	}
	inline Half &operator-=(Float var) {
		_num = FloatToHalf(ToFloat() - var);
		return *this;
	}
	inline Half &operator*=(Float var) {
		_num = FloatToHalf(ToFloat() * var);
		return *this;
	}
	inline Half &operator/=(Float var) {
		_num = FloatToHalf(ToFloat() / var);
		return *this;
	}
	inline Half &operator+=(const Half &var) {
		_num = FloatToHalf(ToFloat() + var.ToFloat());
		return *this;
	}
	inline Half &operator-=(const Half &var) {
		_num = FloatToHalf(ToFloat() - var.ToFloat());
		return *this;
	}
	inline Half &operator*=(const Half &var) {
		_num = FloatToHalf(ToFloat() * var.ToFloat());
		return *this;
	}
	inline Half &operator/=(const Half &var) {
		_num = FloatToHalf(ToFloat() / var.ToFloat());
		return *this;
	}
	inline Half operator-() const { return Half(-HalfToFloat(_num)); }
	inline Half operator+() const { return *this; }
public:
	static void Bootup();
private:
	static UInt32 ConvertMantissa(int i);
	static void GenerateMantissaTable();
	static void GenerateExponentTable();
	static void GenerateOffsetTable();
	static void GenerateBaseTable();
	static void GenerateShiftTable();
	static Float HalfToFloat(UInt16 num);
	static UInt16 FloatToHalf(Float num);
};

inline Half operator+(const Half &varL, Float varR) {
	return Half(varL) += varR;
}

inline Half operator-(const Half &varL, Float varR) {
	return Half(varL) -= varR;
}

inline Half operator*(const Half &varL, Float varR) {
	return Half(varL) *= varR;
}

inline Half operator/(const Half &varL, Float varR) {
	return Half(varL) /= varR;
}

inline Half operator+(Float varL, const Half &varR) {
	return Half(varL) += varR;
}

inline Half operator-(Float varL, const Half &varR) {
	return Half(varL) -= varR;
}

inline Half operator*(Float varL, const Half &varR) {
	return Half(varL) *= varR;
}

inline Half operator/(Float varL, const Half &varR) {
	return Half(varL) /= varR;
}

inline Half operator+(const Half &varL, const Half &varR) {
	return Half(varL) += varR;
}

inline Half operator-(const Half &varL, const Half &varR) {
	return Half(varL) -= varR;
}

inline Half operator*(const Half &varL, const Half &varR) {
	return Half(varL) *= varR;
}

inline Half operator/(const Half &varL, const Half &varR) {
	return Half(varL) /= varR;
}

inline bool operator<(const Half &varL, const Half &varR) {
	return varL.ToFloat() < varR.ToFloat();
}

inline bool operator>(const Half &varL, const Half &varR) {
	return varL.ToFloat() > varR.ToFloat();
}

inline bool operator<=(const Half &varL, const Half &varR) {
	return varL.ToFloat() <= varR.ToFloat();
}

inline bool operator>=(const Half &varL, const Half &varR) {
	return varL.ToFloat() >= varR.ToFloat();
}

inline bool operator==(const Half &varL, const Half &varR) {
	return varL.ToFloat() == varR.ToFloat();
}

inline bool operator!=(const Half &varL, const Half &varR) {
	return varL.ToFloat() != varR.ToFloat();
}

}

#endif
