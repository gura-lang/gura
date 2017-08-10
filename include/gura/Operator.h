//=============================================================================
// Operator
//=============================================================================
#ifndef __GURA_OPERATOR_H__
#define __GURA_OPERATOR_H__

#include "Common.h"

#define Gura_ImplementUnaryOperator(op, type) \
class OperatorEntry_##op##_##type : public OperatorEntry { \
public: \
	inline OperatorEntry_##op##_##type() : \
					OperatorEntry(OPTYPE_##op, VTYPE_##type, VTYPE_undefined) {} \
	virtual Value DoEval(Environment &env, const Value &value, ULong flags) const; \
}; \
Value OperatorEntry_##op##_##type::DoEval(Environment &env, const Value &value, ULong flags) const

#define Gura_ImplementBinaryOperator(op, typeL, typeR) \
class OperatorEntry_##op##_##typeL##_##typeR : public OperatorEntry { \
public: \
	inline OperatorEntry_##op##_##typeL##_##typeR() : \
					OperatorEntry(OPTYPE_##op, VTYPE_##typeL, VTYPE_##typeR) {} \
	virtual Value DoEval(Environment &env, \
	const Value &valueLeft, const Value &valueRight, ULong flags) const; \
}; \
Value OperatorEntry_##op##_##typeL##_##typeR::DoEval(Environment &env, \
					 const Value &valueLeft, const Value &valueRight, ULong flags) const

#define Gura_AssignUnaryOperator(op, type) \
Operator::Assign(env, new OperatorEntry_##op##_##type())

#define Gura_AssignBinaryOperator(op, typeL, typeR) \
Operator::Assign(env, new OperatorEntry_##op##_##typeL##_##typeR())

namespace Gura {

// the order of Operator::_symbolInfoTbl depends on OpType numbers.
enum OpType {
	OPTYPE_None,
	// unary operators
	OPTYPE_unary,
	OPTYPE_Pos		= OPTYPE_unary,
	OPTYPE_Neg,
	OPTYPE_Inv,
	OPTYPE_Not,
	// suffixed unary operators
	OPTYPE_suffixed_unary,
	OPTYPE_SeqInf	= OPTYPE_suffixed_unary,
	OPTYPE_Question,
	OPTYPE_Each,
	OPTYPE_PostPos,
	OPTYPE_PostMod,
	// binary operators
	OPTYPE_binary,
	OPTYPE_Add		= OPTYPE_binary,
	OPTYPE_Sub,
	OPTYPE_Mul,
	OPTYPE_Div,
	OPTYPE_Mod,
	OPTYPE_ModMod,
	OPTYPE_DotProd,
	OPTYPE_CrossProd,
	OPTYPE_Concat,
	OPTYPE_Difference,
	OPTYPE_Intersection,
	OPTYPE_Union,
	OPTYPE_Pow,
	OPTYPE_Eq,
	OPTYPE_Ne,
	OPTYPE_Gt,
	OPTYPE_Lt,
	OPTYPE_Ge,
	OPTYPE_Le,
	OPTYPE_Cmp,
	OPTYPE_Contains,
	OPTYPE_And,
	OPTYPE_Or,
	OPTYPE_Xor,
	OPTYPE_Shl,
	OPTYPE_Shr,
	OPTYPE_OrOr,
	OPTYPE_AndAnd,
	OPTYPE_Seq,
	OPTYPE_Pair,
	// mathematical functions
	OPTYPE_math,
	OPTYPE_Math_abs = OPTYPE_math,
	OPTYPE_Math_acos,
	OPTYPE_Math_arg,
	OPTYPE_Math_asin,
	OPTYPE_Math_atan,
	OPTYPE_Math_atan2,
	OPTYPE_Math_ceil,
	OPTYPE_Math_conj,
	OPTYPE_Math_cos,
	OPTYPE_Math_cosh,
	OPTYPE_Math_covariance,
	OPTYPE_Math_cross,
	OPTYPE_Math_delta,
	OPTYPE_Math_dot,
	OPTYPE_Math_exp,
	OPTYPE_Math_floor,
	OPTYPE_Math_hypot,
	OPTYPE_Math_imag,
	OPTYPE_Math_log,
	OPTYPE_Math_log10,
	OPTYPE_Math_norm,
	OPTYPE_Math_ramp,
	OPTYPE_Math_real,
	OPTYPE_Math_sigmoid,
	OPTYPE_Math_sin,
	OPTYPE_Math_sinh,
	OPTYPE_Math_sqrt,
	OPTYPE_Math_tan,
	OPTYPE_Math_tanh,
	OPTYPE_Math_unitstep,
	OPTYPE_max,
};

class Expr_Value;
class Function;
class OperatorEntry;

//-----------------------------------------------------------------------------
// Operator == override
//-----------------------------------------------------------------------------
inline bool operator==(Boolean a, Half b)			{ return a == static_cast<Boolean>(b); }
inline bool operator==(Int8 a, Half b)				{ return a == static_cast<Int8>(b); }
inline bool operator==(UInt8 a, Half b)				{ return a == static_cast<UInt8>(b); }
inline bool operator==(Int16 a, Half b)				{ return a == static_cast<Int16>(b); }
inline bool operator==(UInt16 a, Half b)			{ return a == static_cast<UInt16>(b); }
inline bool operator==(Int32 a, Half b)				{ return a == static_cast<Int32>(b); }
inline bool operator==(UInt32 a, Half b)			{ return a == static_cast<UInt32>(b); }
inline bool operator==(Int64 a, Half b)				{ return a == static_cast<Int64>(b); }
inline bool operator==(UInt64 a, Half b)			{ return a == static_cast<UInt64>(b); }
inline bool operator==(Float a, Half b)				{ return a == static_cast<Float>(b); }
inline bool operator==(Double a, Half b)			{ return a == static_cast<Double>(b); }

inline bool operator==(Half a, Boolean b)			{ return static_cast<Boolean>(a) == b; }
inline bool operator==(Half a, Int8 b)				{ return static_cast<Int8>(a) == b; }
inline bool operator==(Half a, UInt8 b)				{ return static_cast<UInt8>(a) == b; }
inline bool operator==(Half a, Int16 b)				{ return static_cast<Int16>(a) == b; }
inline bool operator==(Half a, UInt16 b)			{ return static_cast<UInt16>(a) == b; }
inline bool operator==(Half a, Int32 b)				{ return static_cast<Int32>(a) == b; }
inline bool operator==(Half a, UInt32 b)			{ return static_cast<UInt32>(a) == b; }
inline bool operator==(Half a, Int64 b)				{ return static_cast<Int64>(a) == b; }
inline bool operator==(Half a, UInt64 b)			{ return static_cast<UInt64>(a) == b; }
inline bool operator==(Half a, Float b)				{ return static_cast<Float>(a) == b; }
inline bool operator==(Half a, Double b)			{ return static_cast<Double>(a) == b; }

inline bool operator==(Int8 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(UInt8 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(Int16 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(UInt16 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(Int32 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(UInt32 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(Int64 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(UInt64 a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(Half a, const Complex &b)	{ return static_cast<Float>(a) == b.real() && b.imag() == 0; }
inline bool operator==(Float a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }
inline bool operator==(Double a, const Complex &b)	{ return a == b.real() && b.imag() == 0; }

inline bool operator==(const Complex &a, Int8 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, UInt8 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, Int16 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, UInt16 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, Int32 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, UInt32 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, Int64 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, UInt64 b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, Half b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, Float b)	{ return operator==(b, a); }
inline bool operator==(const Complex &a, Double b)	{ return operator==(b, a); }

//-----------------------------------------------------------------------------
// Operator != override
//-----------------------------------------------------------------------------
inline bool operator!=(Boolean a, Half b)			{ return a != static_cast<Boolean>(b); }
inline bool operator!=(Int8 a, Half b)				{ return a != static_cast<Int8>(b); }
inline bool operator!=(UInt8 a, Half b)				{ return a != static_cast<UInt8>(b); }
inline bool operator!=(Int16 a, Half b)				{ return a != static_cast<Int16>(b); }
inline bool operator!=(UInt16 a, Half b)			{ return a != static_cast<UInt16>(b); }
inline bool operator!=(Int32 a, Half b)				{ return a != static_cast<Int32>(b); }
inline bool operator!=(UInt32 a, Half b)			{ return a != static_cast<UInt32>(b); }
inline bool operator!=(Int64 a, Half b)				{ return a != static_cast<Int64>(b); }
inline bool operator!=(UInt64 a, Half b)			{ return a != static_cast<UInt64>(b); }
inline bool operator!=(Float a, Half b)				{ return a != static_cast<Float>(b); }
inline bool operator!=(Double a, Half b)			{ return a != static_cast<Double>(b); }

inline bool operator!=(Half a, Boolean b)			{ return static_cast<Boolean>(a) != b; }
inline bool operator!=(Half a, Int8 b)				{ return static_cast<Int8>(a) != b; }
inline bool operator!=(Half a, UInt8 b)				{ return static_cast<UInt8>(a) != b; }
inline bool operator!=(Half a, Int16 b)				{ return static_cast<Int16>(a) != b; }
inline bool operator!=(Half a, UInt16 b)			{ return static_cast<UInt16>(a) != b; }
inline bool operator!=(Half a, Int32 b)				{ return static_cast<Int32>(a) != b; }
inline bool operator!=(Half a, UInt32 b)			{ return static_cast<UInt32>(a) != b; }
inline bool operator!=(Half a, Int64 b)				{ return static_cast<Int64>(a) != b; }
inline bool operator!=(Half a, UInt64 b)			{ return static_cast<UInt64>(a) != b; }
inline bool operator!=(Half a, Float b)				{ return static_cast<Float>(a) != b; }
inline bool operator!=(Half a, Double b)			{ return static_cast<Double>(a) != b; }

inline bool operator!=(Int8 a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(UInt8 a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(Int16 a, const Complex &b) 	{ return !operator==(a, b); }
inline bool operator!=(UInt16 a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(Int32 a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(UInt32 a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(Int64 a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(UInt64 a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(Half a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(Float a, const Complex &b)	{ return !operator==(a, b); }
inline bool operator!=(Double a, const Complex &b)	{ return !operator==(a, b); }

inline bool operator!=(const Complex &a, Int8 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, UInt8 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, Int16 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, UInt16 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, Int32 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, UInt32 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, Int64 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, UInt64 b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, Half b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, Float b)	{ return operator!=(b, a); }
inline bool operator!=(const Complex &a, Double b)	{ return operator!=(b, a); }

//-----------------------------------------------------------------------------
// Operator > override
//-----------------------------------------------------------------------------
inline bool operator>(Boolean a, Half b)			{ return a > static_cast<Boolean>(b); }
inline bool operator>(Int8 a, Half b)				{ return a > static_cast<Int8>(b); }
inline bool operator>(UInt8 a, Half b)				{ return a > static_cast<UInt8>(b); }
inline bool operator>(Int16 a, Half b)				{ return a > static_cast<Int16>(b); }
inline bool operator>(UInt16 a, Half b)				{ return a > static_cast<UInt16>(b); }
inline bool operator>(Int32 a, Half b)				{ return a > static_cast<Int32>(b); }
inline bool operator>(UInt32 a, Half b)				{ return a > static_cast<UInt32>(b); }
inline bool operator>(Int64 a, Half b)				{ return a > static_cast<Int64>(b); }
inline bool operator>(UInt64 a, Half b)				{ return a > static_cast<UInt64>(b); }
inline bool operator>(Float a, Half b)				{ return a > static_cast<Float>(b); }
inline bool operator>(Double a, Half b)				{ return a > static_cast<Double>(b); }

inline bool operator>(Half a, Boolean b)			{ return static_cast<Boolean>(a) > b; }
inline bool operator>(Half a, Int8 b)				{ return static_cast<Int8>(a) > b; }
inline bool operator>(Half a, UInt8 b)				{ return static_cast<UInt8>(a) > b; }
inline bool operator>(Half a, Int16 b)				{ return static_cast<Int16>(a) > b; }
inline bool operator>(Half a, UInt16 b)				{ return static_cast<UInt16>(a) > b; }
inline bool operator>(Half a, Int32 b)				{ return static_cast<Int32>(a) > b; }
inline bool operator>(Half a, UInt32 b)				{ return static_cast<UInt32>(a) > b; }
inline bool operator>(Half a, Int64 b)				{ return static_cast<Int64>(a) > b; }
inline bool operator>(Half a, UInt64 b)				{ return static_cast<UInt64>(a) > b; }
inline bool operator>(Half a, Float b)				{ return static_cast<Float>(a) > b; }
inline bool operator>(Half a, Double b)				{ return static_cast<Double>(a) > b; }

inline bool operator>(const Complex &a, const Complex &b) { return false; }

inline bool operator>(Int8 a, const Complex &b)		{ return false; }
inline bool operator>(UInt8 a, const Complex &b)	{ return false; }
inline bool operator>(Int16 a, const Complex &b)	{ return false; }
inline bool operator>(UInt16 a, const Complex &b)	{ return false; }
inline bool operator>(Int32 a, const Complex &b)	{ return false; }
inline bool operator>(UInt32 a, const Complex &b)	{ return false; }
inline bool operator>(Int64 a, const Complex &b)	{ return false; }
inline bool operator>(UInt64 a, const Complex &b)	{ return false; }
inline bool operator>(Half a, const Complex &b)		{ return false; }
inline bool operator>(Float a, const Complex &b)	{ return false; }
inline bool operator>(Double a, const Complex &b)	{ return false; }

inline bool operator>(const Complex &a, Int8 b)		{ return false; }
inline bool operator>(const Complex &a, UInt8 b)	{ return false; }
inline bool operator>(const Complex &a, Int16 b)	{ return false; }
inline bool operator>(const Complex &a, UInt16 b)	{ return false; }
inline bool operator>(const Complex &a, Int32 b)	{ return false; }
inline bool operator>(const Complex &a, UInt32 b)	{ return false; }
inline bool operator>(const Complex &a, Int64 b)	{ return false; }
inline bool operator>(const Complex &a, UInt64 b)	{ return false; }
inline bool operator>(const Complex &a, Half b)		{ return false; }
inline bool operator>(const Complex &a, Float b)	{ return false; }
inline bool operator>(const Complex &a, Double b)	{ return false; }

//-----------------------------------------------------------------------------
// Operator < override
//-----------------------------------------------------------------------------
inline bool operator<(Boolean a, Half b)			{ return a < static_cast<Boolean>(b); }
inline bool operator<(Int8 a, Half b)				{ return a < static_cast<Int8>(b); }
inline bool operator<(UInt8 a, Half b)				{ return a < static_cast<UInt8>(b); }
inline bool operator<(Int16 a, Half b)				{ return a < static_cast<Int16>(b); }
inline bool operator<(UInt16 a, Half b)				{ return a < static_cast<UInt16>(b); }
inline bool operator<(Int32 a, Half b)				{ return a < static_cast<Int32>(b); }
inline bool operator<(UInt32 a, Half b)				{ return a < static_cast<UInt32>(b); }
inline bool operator<(Int64 a, Half b)				{ return a < static_cast<Int64>(b); }
inline bool operator<(UInt64 a, Half b)				{ return a < static_cast<UInt64>(b); }
inline bool operator<(Float a, Half b)				{ return a < static_cast<Float>(b); }
inline bool operator<(Double a, Half b)				{ return a < static_cast<Double>(b); }

inline bool operator<(Half a, Boolean b)			{ return static_cast<Boolean>(a) < b; }
inline bool operator<(Half a, Int8 b)				{ return static_cast<Int8>(a) < b; }
inline bool operator<(Half a, UInt8 b)				{ return static_cast<UInt8>(a) < b; }
inline bool operator<(Half a, Int16 b)				{ return static_cast<Int16>(a) < b; }
inline bool operator<(Half a, UInt16 b)				{ return static_cast<UInt16>(a) < b; }
inline bool operator<(Half a, Int32 b)				{ return static_cast<Int32>(a) < b; }
inline bool operator<(Half a, UInt32 b)				{ return static_cast<UInt32>(a) < b; }
inline bool operator<(Half a, Int64 b)				{ return static_cast<Int64>(a) < b; }
inline bool operator<(Half a, UInt64 b)				{ return static_cast<UInt64>(a) < b; }
inline bool operator<(Half a, Float b)				{ return static_cast<Float>(a) < b; }
inline bool operator<(Half a, Double b)				{ return static_cast<Double>(a) < b; }

inline bool operator<(const Complex &a, const Complex &b) { return false; }

inline bool operator<(Int8 a, const Complex &b)		{ return false; }
inline bool operator<(UInt8 a, const Complex &b)	{ return false; }
inline bool operator<(Int16 a, const Complex &b)	{ return false; }
inline bool operator<(UInt16 a, const Complex &b)	{ return false; }
inline bool operator<(Int32 a, const Complex &b)	{ return false; }
inline bool operator<(UInt32 a, const Complex &b)	{ return false; }
inline bool operator<(Int64 a, const Complex &b)	{ return false; }
inline bool operator<(UInt64 a, const Complex &b)	{ return false; }
inline bool operator<(Half a, const Complex &b)		{ return false; }
inline bool operator<(Float a, const Complex &b)	{ return false; }
inline bool operator<(Double a, const Complex &b)	{ return false; }

inline bool operator<(const Complex &a, Int8 b)		{ return false; }
inline bool operator<(const Complex &a, UInt8 b)	{ return false; }
inline bool operator<(const Complex &a, Int16 b)	{ return false; }
inline bool operator<(const Complex &a, UInt16 b)	{ return false; }
inline bool operator<(const Complex &a, Int32 b)	{ return false; }
inline bool operator<(const Complex &a, UInt32 b)	{ return false; }
inline bool operator<(const Complex &a, Int64 b)	{ return false; }
inline bool operator<(const Complex &a, UInt64 b)	{ return false; }
inline bool operator<(const Complex &a, Half b)		{ return false; }
inline bool operator<(const Complex &a, Float b)	{ return false; }
inline bool operator<(const Complex &a, Double b)	{ return false; }

//-----------------------------------------------------------------------------
// Operator >= override
//-----------------------------------------------------------------------------
inline bool operator>=(Boolean a, Half b)			{ return a >= static_cast<Boolean>(b); }
inline bool operator>=(Int8 a, Half b)				{ return a >= static_cast<Int8>(b); }
inline bool operator>=(UInt8 a, Half b)				{ return a >= static_cast<UInt8>(b); }
inline bool operator>=(Int16 a, Half b)				{ return a >= static_cast<Int16>(b); }
inline bool operator>=(UInt16 a, Half b)			{ return a >= static_cast<UInt16>(b); }
inline bool operator>=(Int32 a, Half b)				{ return a >= static_cast<Int32>(b); }
inline bool operator>=(UInt32 a, Half b)			{ return a >= static_cast<UInt32>(b); }
inline bool operator>=(Int64 a, Half b)				{ return a >= static_cast<Int64>(b); }
inline bool operator>=(UInt64 a, Half b)			{ return a >= static_cast<UInt64>(b); }
inline bool operator>=(Float a, Half b)				{ return a >= static_cast<Float>(b); }
inline bool operator>=(Double a, Half b)			{ return a >= static_cast<Double>(b); }

inline bool operator>=(Half a, Boolean b)			{ return static_cast<Boolean>(a) >= b; }
inline bool operator>=(Half a, Int8 b)				{ return static_cast<Int8>(a) >= b; }
inline bool operator>=(Half a, UInt8 b)				{ return static_cast<UInt8>(a) >= b; }
inline bool operator>=(Half a, Int16 b)				{ return static_cast<Int16>(a) >= b; }
inline bool operator>=(Half a, UInt16 b)			{ return static_cast<UInt16>(a) >= b; }
inline bool operator>=(Half a, Int32 b)				{ return static_cast<Int32>(a) >= b; }
inline bool operator>=(Half a, UInt32 b)			{ return static_cast<UInt32>(a) >= b; }
inline bool operator>=(Half a, Int64 b)				{ return static_cast<Int64>(a) >= b; }
inline bool operator>=(Half a, UInt64 b)			{ return static_cast<UInt64>(a) >= b; }
inline bool operator>=(Half a, Float b)				{ return static_cast<Float>(a) >= b; }
inline bool operator>=(Half a, Double b)			{ return static_cast<Double>(a) >= b; }

inline bool operator>=(const Complex &a, const Complex &b) { return false; }

inline bool operator>=(Int8 a, const Complex &b)	{ return false; }
inline bool operator>=(UInt8 a, const Complex &b)	{ return false; }
inline bool operator>=(Int16 a, const Complex &b)	{ return false; }
inline bool operator>=(UInt16 a, const Complex &b)	{ return false; }
inline bool operator>=(Int32 a, const Complex &b)	{ return false; }
inline bool operator>=(UInt32 a, const Complex &b)	{ return false; }
inline bool operator>=(Int64 a, const Complex &b)	{ return false; }
inline bool operator>=(UInt64 a, const Complex &b)	{ return false; }
inline bool operator>=(Half a, const Complex &b)	{ return false; }
inline bool operator>=(Float a, const Complex &b)	{ return false; }
inline bool operator>=(Double a, const Complex &b)	{ return false; }

inline bool operator>=(const Complex &a, Int8 b)	{ return false; }
inline bool operator>=(const Complex &a, UInt8 b)	{ return false; }
inline bool operator>=(const Complex &a, Int16 b)	{ return false; }
inline bool operator>=(const Complex &a, UInt16 b)	{ return false; }
inline bool operator>=(const Complex &a, Int32 b)	{ return false; }
inline bool operator>=(const Complex &a, UInt32 b)	{ return false; }
inline bool operator>=(const Complex &a, Int64 b)	{ return false; }
inline bool operator>=(const Complex &a, UInt64 b)	{ return false; }
inline bool operator>=(const Complex &a, Half b)	{ return false; }
inline bool operator>=(const Complex &a, Float b)	{ return false; }
inline bool operator>=(const Complex &a, Double b)	{ return false; }

//-----------------------------------------------------------------------------
// Operator <= override
//-----------------------------------------------------------------------------
inline bool operator<=(Boolean a, Half b)			{ return a <= static_cast<Boolean>(b); }
inline bool operator<=(Int8 a, Half b)				{ return a <= static_cast<Int8>(b); }
inline bool operator<=(UInt8 a, Half b)				{ return a <= static_cast<UInt8>(b); }
inline bool operator<=(Int16 a, Half b)				{ return a <= static_cast<Int16>(b); }
inline bool operator<=(UInt16 a, Half b)			{ return a <= static_cast<UInt16>(b); }
inline bool operator<=(Int32 a, Half b)				{ return a <= static_cast<Int32>(b); }
inline bool operator<=(UInt32 a, Half b)			{ return a <= static_cast<UInt32>(b); }
inline bool operator<=(Int64 a, Half b)				{ return a <= static_cast<Int64>(b); }
inline bool operator<=(UInt64 a, Half b)			{ return a <= static_cast<UInt64>(b); }
inline bool operator<=(Float a, Half b)				{ return a <= static_cast<Float>(b); }
inline bool operator<=(Double a, Half b)			{ return a <= static_cast<Double>(b); }

inline bool operator<=(Half a, Boolean b)			{ return static_cast<Boolean>(a) <= b; }
inline bool operator<=(Half a, Int8 b)				{ return static_cast<Int8>(a) <= b; }
inline bool operator<=(Half a, UInt8 b)				{ return static_cast<UInt8>(a) <= b; }
inline bool operator<=(Half a, Int16 b)				{ return static_cast<Int16>(a) <= b; }
inline bool operator<=(Half a, UInt16 b)			{ return static_cast<UInt16>(a) <= b; }
inline bool operator<=(Half a, Int32 b)				{ return static_cast<Int32>(a) <= b; }
inline bool operator<=(Half a, UInt32 b)			{ return static_cast<UInt32>(a) <= b; }
inline bool operator<=(Half a, Int64 b)				{ return static_cast<Int64>(a) <= b; }
inline bool operator<=(Half a, UInt64 b)			{ return static_cast<UInt64>(a) <= b; }
inline bool operator<=(Half a, Float b)				{ return static_cast<Float>(a) <= b; }
inline bool operator<=(Half a, Double b)			{ return static_cast<Double>(a) <= b; }

inline bool operator<=(const Complex &a, const Complex &b) { return false; }

inline bool operator<=(Int8 a, const Complex &b)	{ return false; }
inline bool operator<=(UInt8 a, const Complex &b)	{ return false; }
inline bool operator<=(Int16 a, const Complex &b)	{ return false; }
inline bool operator<=(UInt16 a, const Complex &b)	{ return false; }
inline bool operator<=(Int32 a, const Complex &b)	{ return false; }
inline bool operator<=(UInt32 a, const Complex &b)	{ return false; }
inline bool operator<=(Int64 a, const Complex &b)	{ return false; }
inline bool operator<=(UInt64 a, const Complex &b)	{ return false; }
inline bool operator<=(Half a, const Complex &b)	{ return false; }
inline bool operator<=(Float a, const Complex &b)	{ return false; }
inline bool operator<=(Double a, const Complex &b)	{ return false; }

inline bool operator<=(const Complex &a, Int8 b)	{ return false; }
inline bool operator<=(const Complex &a, UInt8 b)	{ return false; }
inline bool operator<=(const Complex &a, Int16 b)	{ return false; }
inline bool operator<=(const Complex &a, UInt16 b)	{ return false; }
inline bool operator<=(const Complex &a, Int32 b)	{ return false; }
inline bool operator<=(const Complex &a, UInt32 b)	{ return false; }
inline bool operator<=(const Complex &a, Int64 b)	{ return false; }
inline bool operator<=(const Complex &a, UInt64 b)	{ return false; }
inline bool operator<=(const Complex &a, Half b)	{ return false; }
inline bool operator<=(const Complex &a, Float b)	{ return false; }
inline bool operator<=(const Complex &a, Double b)	{ return false; }

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator {
public:
	struct SymbolInfo {
		const char *symbol;
		const char *name;
	};
public:
	typedef ULong Key;
	typedef std::map<Key, OperatorEntry *> EntryDict;
	typedef std::vector<OperatorEntry *> EntryList;
private:
	OpType _opType;
	const Symbol *_pSymbol;
	bool _mapFlag;
	EntryDict _entryDict;
	static const SymbolInfo _symbolInfoTbl[];
public:
	// unary operators
	static Operator *Pos;
	static Operator *Neg;
	static Operator *Inv;
	static Operator *Not;
	// suffixed unary operators
	static Operator *SeqInf;
	static Operator *Question;
	static Operator *Each;
	static Operator *PostPos;
	static Operator *PostMod;
	// binary operators
	static Operator *Add;
	static Operator *Sub;
	static Operator *Mul;
	static Operator *Div;
	static Operator *Mod;
	static Operator *ModMod;
	static Operator *DotProd;
	static Operator *CrossProd;
	static Operator *Concat;
	static Operator *Difference;
	static Operator *Intersection;
	static Operator *Union;
	static Operator *Pow;
	static Operator *Eq;
	static Operator *Ne;
	static Operator *Gt;
	static Operator *Lt;
	static Operator *Ge;
	static Operator *Le;
	static Operator *Cmp;
	static Operator *Contains;
	static Operator *And;
	static Operator *Or;
	static Operator *Xor;
	static Operator *Shl;
	static Operator *Shr;
	static Operator *OrOr;
	static Operator *AndAnd;
	static Operator *Seq;
	static Operator *Pair;
	// mathematical functions
	static Operator *Math_abs;
	static Operator *Math_acos;
	static Operator *Math_arg;
	static Operator *Math_asin;
	static Operator *Math_atan;
	static Operator *Math_atan2;
	static Operator *Math_ceil;
	static Operator *Math_conj;
	static Operator *Math_cos;
	static Operator *Math_cosh;
	static Operator *Math_covariance;
	static Operator *Math_cross;
	static Operator *Math_delta;
	static Operator *Math_dot;
	static Operator *Math_exp;
	static Operator *Math_floor;
	static Operator *Math_hypot;
	static Operator *Math_imag;
	static Operator *Math_log;
	static Operator *Math_log10;
	static Operator *Math_norm;
	static Operator *Math_ramp;
	static Operator *Math_real;
	static Operator *Math_sigmoid;
	static Operator *Math_sin;
	static Operator *Math_sinh;
	static Operator *Math_sqrt;
	static Operator *Math_tan;
	static Operator *Math_tanh;
	static Operator *Math_unitstep;
public:
	inline Operator(OpType opType, bool mapFlag = true) :
		_opType(opType), _pSymbol(Symbol::Add(_symbolInfoTbl[opType].symbol)), _mapFlag(mapFlag) {}
	inline OpType GetOpType() const { return _opType; }
	inline bool IsOpType(OpType opType) const { return _opType == opType; }
	inline EntryDict &GetEntryDict() { return _entryDict; }
	inline const EntryDict &GetEntryDict() const { return _entryDict; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetName() const { return _symbolInfoTbl[_opType].name; }
	inline static const SymbolInfo &GetSymbolInfo(OpType opType) { return _symbolInfoTbl[opType]; }
	inline static Key CalcKey(ValueType valType) {
		return static_cast<Key>(static_cast<ULong>(valType));
	}
	inline static Key CalcKey(ValueType valTypeLeft, ValueType valTypeRight) {
		return static_cast<Key>((static_cast<ULong>(valTypeRight) << 16) +
								static_cast<ULong>(valTypeLeft));
	}
	inline static ValueType ExtractValueTypeLeft(Key key) {
		return static_cast<ValueType>(static_cast<ULong>(key) & 0xffff);
	}
	inline static ValueType ExtractValueTypeRight(Key key) {
		return static_cast<ValueType>((static_cast<ULong>(key) >> 16) & 0xffff);
	}
	inline static ValueType ExtractValueType(Key key) {
		ValueType valType = ExtractValueTypeLeft(key);
		if (valType != VTYPE_undefined) return valType;
		return ExtractValueTypeRight(key);
	}
	inline static bool IsUnaryOperator(OpType opType) {
		return opType < OPTYPE_suffixed_unary;
	}
	inline static bool IsSuffixedUnaryOperator(OpType opType) {
		return OPTYPE_suffixed_unary <= opType && opType < OPTYPE_binary;
	}
	inline static bool IsBinaryOperator(OpType opType) {
		return OPTYPE_binary <= opType && opType < OPTYPE_math;
	}
	inline static bool IsMathFunction(OpType opType) {
		return OPTYPE_math <= opType;
	}
	inline bool IsUnaryOperator() const { return IsUnaryOperator(_opType); }
	inline bool IsSuffixedUnaryOperator() const { return IsSuffixedUnaryOperator(_opType); }
	inline bool IsBinaryOperator() const { return IsBinaryOperator(_opType); }
	inline bool IsMathFunction() const { return IsMathFunction(_opType); }
	const OperatorEntry *Lookup(ValueType valType) const;
	const OperatorEntry *Lookup(ValueType valTypeLeft, ValueType valTypeRight) const;
	virtual Expr *MathDiffUnary(Environment &env,
							const Expr *pExprChild, const Symbol *pSymbol) const;
	virtual Expr *MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const;
	Expr *MathOptimizeConst(Environment &env, Expr_Value *pExprChild) const;
	Expr *MathOptimizeConst(Environment &env,
									Expr_Value *pExprLeft, Expr_Value *pExprRight) const;
	virtual Expr *MathOptimizeUnary(Environment &env, Expr *pExprChild) const;
	virtual Expr *MathOptimizeBinary(Environment &env,
									Expr *pExprLeft, Expr *pExprRight) const;
	static OpType LookupUnaryOpType(const char *str);
	static OpType LookupBinaryOpType(const char *str);
	virtual Value ExecUnary(Environment &env, const Expr *pExprChild) const;
	virtual Value ExecBinary(Environment &env, const Expr *pExprLeft, const Expr *pExprRight) const;
	Value EvalUnary(Environment &env, const Value &value, ULong flags) const;
	Value EvalBinary(Environment &env,
					 const Value &valueLeft, const Value &valueRight, ULong flags) const;
	virtual Value EvalMapUnary(Environment &env, const Value &value, ULong flags) const;
	virtual Value EvalMapBinary(Environment &env,
								const Value &valueLeft, const Value &valueRight, ULong flags) const;
	static void SetError_InvalidValueType(Signal &sig, OpType opType, const Value &value);
	static void SetError_InvalidValueType(Signal &sig, OpType opType,
					const Value &valueLeft, const Value &valueRight);
	static void Assign(Environment &env, OperatorEntry *pOperatorEntry);
	static void SetError_DivideByZero(Signal &sig);
	static void SetError_MathDiffError(Signal &sig);
	static void SetError_MathOptimizeError(Signal &sig);
	static void Bootup(Environment &env);
private:
	static void AssignOperatorBasic(Environment &env);
};

//-----------------------------------------------------------------------------
// Operator_Pos
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Pos : public Operator {
public:
	inline Operator_Pos() : Operator(OPTYPE_Pos) {}
	virtual Expr *MathDiffUnary(Environment &env,
							const Expr *pExprChild, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeUnary(Environment &env, Expr *pExprChild) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprChild);
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(+var);
	}
};

//-----------------------------------------------------------------------------
// Operator_Neg
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Neg : public Operator {
public:
	inline Operator_Neg() : Operator(OPTYPE_Neg) {}
	virtual Expr *MathDiffUnary(Environment &env,
							const Expr *pExprChild, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeUnary(Environment &env, Expr *pExprChild) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprChild);
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(-var);
	}
};

//-----------------------------------------------------------------------------
// Operator_Inv
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Inv : public Operator {
public:
	inline Operator_Inv() : Operator(OPTYPE_Inv) {}
};

//-----------------------------------------------------------------------------
// Operator_Not
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Not : public Operator {
public:
	inline Operator_Not() : Operator(OPTYPE_Not) {}
};

//-----------------------------------------------------------------------------
// Operator_SeqInf
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_SeqInf : public Operator {
public:
	inline Operator_SeqInf() : Operator(OPTYPE_SeqInf) {}
};

//-----------------------------------------------------------------------------
// Operator_Question
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Question : public Operator {
public:
	inline Operator_Question() : Operator(OPTYPE_Question, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Each
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Each : public Operator {
public:
	inline Operator_Each() : Operator(OPTYPE_Each, false) {}
};

//-----------------------------------------------------------------------------
// Operator_PostPos
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_PostPos : public Operator {
public:
	inline Operator_PostPos() : Operator(OPTYPE_PostPos, false) {}
};

//-----------------------------------------------------------------------------
// Operator_PostMod
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_PostMod : public Operator {
public:
	inline Operator_PostMod() : Operator(OPTYPE_PostMod, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Add
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Add : public Operator {
public:
	inline Operator_Add() : Operator(OPTYPE_Add) {}
	virtual Expr *MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeBinary(Environment &env,
										Expr *pExprLeft, Expr *pExprRight) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight);
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) + static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Sub
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Sub : public Operator {
public:
	inline Operator_Sub() : Operator(OPTYPE_Sub) {}
	virtual Expr *MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeBinary(Environment &env,
										Expr *pExprLeft, Expr *pExprRight) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight);
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) - static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Mul
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Mul : public Operator {
public:
	inline Operator_Mul() : Operator(OPTYPE_Mul) {}
	virtual Value EvalMapBinary(Environment &env,
								const Value &valueLeft, const Value &valueRight, ULong flags) const;
	virtual Expr *MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeBinary(Environment &env,
										Expr *pExprLeft, Expr *pExprRight) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight);
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) * static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Div
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Div : public Operator {
public:
	inline Operator_Div() : Operator(OPTYPE_Div) {}
	virtual Expr *MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeBinary(Environment &env,
										Expr *pExprLeft, Expr *pExprRight) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight);
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) / static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Mod
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Mod : public Operator {
public:
	inline Operator_Mod() : Operator(OPTYPE_Mod) {}
	virtual Value EvalMapBinary(Environment &env,
								const Value &valueLeft, const Value &valueRight, ULong flags) const;
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) % static_cast<T_Result>(varR);
	}
};

#define Gura_ImplementMod_Half(T_Other) \
template<> inline void Operator_Mod::Calc<Half, T_Other, Half>( \
				Half &result, const T_Other &varL, const Half &varR) {		\
	result = Half(::fmodf(static_cast<Float>(varL), static_cast<Float>(varR))); \
} \
template<> inline void Operator_Mod::Calc<Half, Half, T_Other>( \
				Half &result, const Half &varL, const T_Other &varR) {		\
	result = Half(::fmodf(static_cast<Float>(varL), static_cast<Float>(varR))); \
}

#define Gura_ImplementMod_Float(T_Other) \
template<> inline void Operator_Mod::Calc<Float, T_Other, Float>( \
				Float &result, const T_Other &varL, const Float &varR) {		\
	result = ::fmodf(static_cast<Float>(varL), varR);				\
} \
template<> inline void Operator_Mod::Calc<Float, Float, T_Other>( \
				Float &result, const Float &varL, const T_Other &varR) {		\
	result = ::fmodf(varL, static_cast<Float>(varR));				\
}

#define Gura_ImplementMod_Double(T_Other) \
template<> inline void Operator_Mod::Calc<Double, T_Other, Double>( \
				Double &result, const T_Other &varL, const Double &varR) {	\
	result = ::fmod(static_cast<Double>(varL), varR);				\
} \
template<> inline void Operator_Mod::Calc<Double, Double, T_Other>( \
				Double &result, const Double &varL, const T_Other &varR) {	\
	result = ::fmod(varL, static_cast<Double>(varR));				\
}

#define Gura_ImplementMod_Complex(T_Other) \
template<> inline void Operator_Mod::Calc<Complex, T_Other, Complex>( \
				Complex &result, const T_Other &varL, const Complex &varR) {	\
	result = ::fmod(static_cast<Double>(varL), varR.real());			\
} \
template<> inline void Operator_Mod::Calc<Complex, Complex, T_Other>( \
				Complex &result, const Complex &varL, const T_Other &varR) {	\
	result = ::fmod(varL.real(), static_cast<Double>(varR));			\
}

template<> inline void Operator_Mod::Calc<Half, Half, Half>(
				Half &result, const Half &varL, const Half &varR)
{
	result = Half(::fmodf(static_cast<Float>(varL), static_cast<Float>(varR)));
}

template<> inline void Operator_Mod::Calc<Float, Float, Float>(
				Float &result, const Float &varL, const Float &varR)
{
	result = ::fmodf(static_cast<Float>(varL), varR);
}

template<> inline void Operator_Mod::Calc<Double, Double, Double>(
				Double &result, const Double &varL, const Double &varR)
{
	result = ::fmod(varL, varR);
}

template<> inline void Operator_Mod::Calc<Complex, Complex, Complex>( \
				Complex &result, const Complex &varL, const Complex &varR) {	\
	result = ::fmod(varL.real(), varR.real());							\
}

Gura_ImplementMod_Half(Boolean)
Gura_ImplementMod_Half(Int8)
Gura_ImplementMod_Half(UInt8)
Gura_ImplementMod_Half(Int16)
Gura_ImplementMod_Half(UInt16)
Gura_ImplementMod_Half(Int32)
Gura_ImplementMod_Half(UInt32)
Gura_ImplementMod_Half(Int64)
Gura_ImplementMod_Half(UInt64)
Gura_ImplementMod_Half(Float)
Gura_ImplementMod_Half(Double)

Gura_ImplementMod_Float(Boolean)
Gura_ImplementMod_Float(Int8)
Gura_ImplementMod_Float(UInt8)
Gura_ImplementMod_Float(Int16)
Gura_ImplementMod_Float(UInt16)
Gura_ImplementMod_Float(Int32)
Gura_ImplementMod_Float(UInt32)
Gura_ImplementMod_Float(Int64)
Gura_ImplementMod_Float(UInt64)
Gura_ImplementMod_Float(Half)
Gura_ImplementMod_Float(Double)

Gura_ImplementMod_Double(Boolean)
Gura_ImplementMod_Double(Int8)
Gura_ImplementMod_Double(UInt8)
Gura_ImplementMod_Double(Int16)
Gura_ImplementMod_Double(UInt16)
Gura_ImplementMod_Double(Int32)
Gura_ImplementMod_Double(UInt32)
Gura_ImplementMod_Double(Int64)
Gura_ImplementMod_Double(UInt64)
Gura_ImplementMod_Double(Half)
Gura_ImplementMod_Double(Float)

Gura_ImplementMod_Complex(Boolean)
Gura_ImplementMod_Complex(Int8)
Gura_ImplementMod_Complex(UInt8)
Gura_ImplementMod_Complex(Int16)
Gura_ImplementMod_Complex(UInt16)
Gura_ImplementMod_Complex(Int32)
Gura_ImplementMod_Complex(UInt32)
Gura_ImplementMod_Complex(Int64)
Gura_ImplementMod_Complex(UInt64)
Gura_ImplementMod_Complex(Half)
Gura_ImplementMod_Complex(Float)
Gura_ImplementMod_Complex(Double)

//-----------------------------------------------------------------------------
// Operator_ModMod
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_ModMod : public Operator {
public:
	inline Operator_ModMod() : Operator(OPTYPE_ModMod) {}
	virtual Value ExecBinary(Environment &env, const Expr *pExprLeft, const Expr *pExprRight) const;
};

//-----------------------------------------------------------------------------
// Operator_DotProd
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_DotProd : public Operator {
public:
	inline Operator_DotProd() : Operator(OPTYPE_DotProd) {}
};

//-----------------------------------------------------------------------------
// Operator_CrossProd
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_CrossProd : public Operator {
public:
	inline Operator_CrossProd() : Operator(OPTYPE_CrossProd) {}
};

//-----------------------------------------------------------------------------
// Operator_Concat
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Concat : public Operator {
public:
	inline Operator_Concat() : Operator(OPTYPE_Concat, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Difference
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Difference : public Operator {
public:
	inline Operator_Difference() : Operator(OPTYPE_Difference, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Intersection
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Intersection : public Operator {
public:
	inline Operator_Intersection() : Operator(OPTYPE_Intersection, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Union
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Union : public Operator {
public:
	inline Operator_Union() : Operator(OPTYPE_Union, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Pow
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Pow : public Operator {
public:
	inline Operator_Pow() : Operator(OPTYPE_Pow) {}
	virtual Expr *MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeBinary(Environment &env,
										Expr *pExprLeft, Expr *pExprRight) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight);
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(
			std::pow(static_cast<double>(varL), static_cast<double>(varR)));
	}
};

#define Gura_ImplementPow_Complex(T_Other) \
template<> inline void Operator_Pow::Calc<Complex, T_Other, Complex>( \
				Complex &result, const T_Other &varL, const Complex &varR) {	\
	result = std::pow(static_cast<Double>(varL), varR);			\
} \
template<> inline void Operator_Pow::Calc<Complex, Complex, T_Other>( \
				Complex &result, const Complex &varL, const T_Other &varR) {	\
	result = std::pow(varL, static_cast<Double>(varR));			\
}

template<> inline void Operator_Pow::Calc<Complex, Complex, Complex>(
				Complex &result, const Complex &varL, const Complex &varR) {
	result = std::pow<Double, Double>(varL, varR);
}

Gura_ImplementPow_Complex(Boolean)
Gura_ImplementPow_Complex(Int8)
Gura_ImplementPow_Complex(UInt8)
Gura_ImplementPow_Complex(Int16)
Gura_ImplementPow_Complex(UInt16)
Gura_ImplementPow_Complex(Int32)
Gura_ImplementPow_Complex(UInt32)
Gura_ImplementPow_Complex(Int64)
Gura_ImplementPow_Complex(UInt64)
Gura_ImplementPow_Complex(Half)
Gura_ImplementPow_Complex(Float)
Gura_ImplementPow_Complex(Double)

//-----------------------------------------------------------------------------
// Operator_Eq
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Eq : public Operator {
public:
	inline Operator_Eq() : Operator(OPTYPE_Eq) {}
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL == varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Ne
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Ne : public Operator {
public:
	inline Operator_Ne() : Operator(OPTYPE_Ne) {}
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL != varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Gt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Gt : public Operator {
public:
	inline Operator_Gt() : Operator(OPTYPE_Gt) {}
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL > varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Lt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Lt : public Operator {
public:
	inline Operator_Lt() : Operator(OPTYPE_Lt) {}
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL < varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Ge
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Ge : public Operator {
public:
	inline Operator_Ge() : Operator(OPTYPE_Ge) {}
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL >= varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Le
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Le : public Operator {
public:
	inline Operator_Le() : Operator(OPTYPE_Le) {}
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL <= varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Cmp
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Cmp : public Operator {
public:
	inline Operator_Cmp() : Operator(OPTYPE_Cmp) {}
};

//-----------------------------------------------------------------------------
// Operator_Contains
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Contains : public Operator {
public:
	inline Operator_Contains() : Operator(OPTYPE_Contains, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Or
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Or : public Operator {
public:
	inline Operator_Or() : Operator(OPTYPE_Or) {}
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) | static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_And
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_And : public Operator {
public:
	inline Operator_And() : Operator(OPTYPE_And) {}
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) & static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Xor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Xor : public Operator {
public:
	inline Operator_Xor() : Operator(OPTYPE_Xor) {}
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) ^ static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Shl
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Shl : public Operator {
public:
	inline Operator_Shl() : Operator(OPTYPE_Shl) {}
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) << static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_Shr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Shr : public Operator {
public:
	inline Operator_Shr() : Operator(OPTYPE_Shr) {}
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(varL) >> static_cast<T_Result>(varR);
	}
};

//-----------------------------------------------------------------------------
// Operator_OrOr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_OrOr : public Operator {
public:
	inline Operator_OrOr() : Operator(OPTYPE_OrOr) {}
	virtual Value ExecBinary(Environment &env, const Expr *pExprLeft, const Expr *pExprRight) const;
};

//-----------------------------------------------------------------------------
// Operator_AndAnd
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_AndAnd : public Operator {
public:
	inline Operator_AndAnd() : Operator(OPTYPE_AndAnd) {}
	virtual Value ExecBinary(Environment &env, const Expr *pExprLeft, const Expr *pExprRight) const;
};

//-----------------------------------------------------------------------------
// Operator_Seq
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Seq : public Operator {
public:
	inline Operator_Seq() : Operator(OPTYPE_Seq) {}
};

//-----------------------------------------------------------------------------
// Operator_Pair
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Pair : public Operator {
public:
	inline Operator_Pair() : Operator(OPTYPE_Pair, false) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_abs
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_abs : public Operator {
public:
	inline Operator_Math_abs() : Operator(OPTYPE_Math_abs) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::fabs(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_abs::Calc(Complex &result, const Complex &var)
{
	result = std::abs(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_acos
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_acos : public Operator {
public:
	inline Operator_Math_acos() : Operator(OPTYPE_Math_acos) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::acos(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_acos::Calc(Complex &result, const Complex &var)
{
	result = std::acos(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_arg
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_arg : public Operator {
public:
	inline Operator_Math_arg() : Operator(OPTYPE_Math_arg) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(0);
	}
};

template<> inline void Operator_Math_arg::Calc(Double &result, const Complex &var)
{
	result = std::arg(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_asin
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_asin : public Operator {
public:
	inline Operator_Math_asin() : Operator(OPTYPE_Math_asin) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::asin(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_asin::Calc(Complex &result, const Complex &var)
{
	result = std::asin(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_atan
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_atan : public Operator {
public:
	inline Operator_Math_atan() : Operator(OPTYPE_Math_atan) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::atan(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_atan::Calc(Complex &result, const Complex &var)
{
	result = std::atan(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_atan2
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_atan2 : public Operator {
public:
	inline Operator_Math_atan2() : Operator(OPTYPE_Math_atan2) {}
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(::atan2(static_cast<Double>(varL), static_cast<Double>(varR)));
	}
};

#define Gura_ImplementMath_atan2_Complex(T_Other) \
template<> inline void Operator_Math_atan2::Calc<Complex, T_Other, Complex>( \
				Complex &result, const T_Other &varL, const Complex &varR) {	\
	result = ::atan2(static_cast<Double>(varL), varR.real());			\
} \
template<> inline void Operator_Math_atan2::Calc<Complex, Complex, T_Other>( \
				Complex &result, const Complex &varL, const T_Other &varR) {	\
	result = ::atan2(varL.real(), static_cast<Double>(varR));			\
}

template<> inline void Operator_Math_atan2::Calc<Complex, Complex, Complex>( \
				Complex &result, const Complex &varL, const Complex &varR) {	\
	result = ::atan2(varL.real(), varR.real());							\
}

Gura_ImplementMath_atan2_Complex(Boolean)
Gura_ImplementMath_atan2_Complex(Int8)
Gura_ImplementMath_atan2_Complex(UInt8)
Gura_ImplementMath_atan2_Complex(Int16)
Gura_ImplementMath_atan2_Complex(UInt16)
Gura_ImplementMath_atan2_Complex(Int32)
Gura_ImplementMath_atan2_Complex(UInt32)
Gura_ImplementMath_atan2_Complex(Int64)
Gura_ImplementMath_atan2_Complex(UInt64)
Gura_ImplementMath_atan2_Complex(Half)
Gura_ImplementMath_atan2_Complex(Float)
Gura_ImplementMath_atan2_Complex(Double)

//-----------------------------------------------------------------------------
// Operator_Math_ceil
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_ceil : public Operator {
public:
	inline Operator_Math_ceil() : Operator(OPTYPE_Math_ceil) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::ceil(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_ceil::Calc(Complex &result, const Complex &var)
{
	result = Complex(::ceil(var.real()), ::ceil(var.imag()));
}

//-----------------------------------------------------------------------------
// Operator_Math_conj
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_conj : public Operator {
public:
	inline Operator_Math_conj() : Operator(OPTYPE_Math_conj) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(var);
	}
};

template<> inline void Operator_Math_conj::Calc(Complex &result, const Complex &var)
{
	result = std::conj(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_cos
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_cos : public Operator {
public:
	inline Operator_Math_cos() : Operator(OPTYPE_Math_cos) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::cos(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_cos::Calc(Complex &result, const Complex &var)
{
	result = std::cos(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_cosh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_cosh : public Operator {
public:
	inline Operator_Math_cosh() : Operator(OPTYPE_Math_cosh) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::cosh(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_cosh::Calc(Complex &result, const Complex &var)
{
	result = std::cosh(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_covariance
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_covariance : public Operator {
public:
	inline Operator_Math_covariance() : Operator(OPTYPE_Math_covariance) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_cross
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_cross : public Operator {
public:
	inline Operator_Math_cross() : Operator(OPTYPE_Math_cross) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_delta
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_delta : public Operator {
public:
	inline Operator_Math_delta() : Operator(OPTYPE_Math_delta) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>((var == 0)? 1 : 0);
	}
};

template<> inline void Operator_Math_delta::Calc(Complex &result, const Complex &var)
{
	result = Complex((var == Complex::Zero)? 1 : 0);
}

//-----------------------------------------------------------------------------
// Operator_Math_dot
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_dot : public Operator {
public:
	inline Operator_Math_dot() : Operator(OPTYPE_Math_dot) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_exp
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_exp : public Operator {
public:
	inline Operator_Math_exp() : Operator(OPTYPE_Math_exp) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::exp(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_exp::Calc(Complex &result, const Complex &var)
{
	result = std::exp(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_floor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_floor : public Operator {
public:
	inline Operator_Math_floor() : Operator(OPTYPE_Math_floor) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::floor(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_floor::Calc(Complex &result, const Complex &var)
{
	result = Complex(::floor(var.real()), ::floor(var.imag()));
}

//-----------------------------------------------------------------------------
// Operator_Math_hypot
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_hypot : public Operator {
public:
	inline Operator_Math_hypot() : Operator(OPTYPE_Math_hypot) {}
public:
	template<typename T_Result, typename T_VarL, typename T_VarR>
	inline static void Calc(T_Result &result, const T_VarL &varL, const T_VarR &varR) {
		result = static_cast<T_Result>(::hypot(static_cast<Double>(varL), static_cast<Double>(varR)));
	}
};

#define Gura_ImplementMath_hypot_Complex(T_Other) \
template<> inline void Operator_Math_hypot::Calc<Complex, T_Other, Complex>( \
				Complex &result, const T_Other &varL, const Complex &varR) {	\
	result = ::hypot(static_cast<Double>(varL), varR.real());			\
} \
template<> inline void Operator_Math_hypot::Calc<Complex, Complex, T_Other>( \
				Complex &result, const Complex &varL, const T_Other &varR) {	\
	result = ::hypot(varL.real(), static_cast<Double>(varR));			\
}

template<> inline void Operator_Math_hypot::Calc<Complex, Complex, Complex>( \
				Complex &result, const Complex &varL, const Complex &varR) {	\
	result = ::hypot(varL.real(), varR.real());							\
}

Gura_ImplementMath_hypot_Complex(Boolean)
Gura_ImplementMath_hypot_Complex(Int8)
Gura_ImplementMath_hypot_Complex(UInt8)
Gura_ImplementMath_hypot_Complex(Int16)
Gura_ImplementMath_hypot_Complex(UInt16)
Gura_ImplementMath_hypot_Complex(Int32)
Gura_ImplementMath_hypot_Complex(UInt32)
Gura_ImplementMath_hypot_Complex(Int64)
Gura_ImplementMath_hypot_Complex(UInt64)
Gura_ImplementMath_hypot_Complex(Half)
Gura_ImplementMath_hypot_Complex(Float)
Gura_ImplementMath_hypot_Complex(Double)

//-----------------------------------------------------------------------------
// Operator_Math_imag
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_imag : public Operator {
public:
	inline Operator_Math_imag() : Operator(OPTYPE_Math_imag) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(0);
	}
};

template<> inline void Operator_Math_imag::Calc(Double &result, const Complex &var)
{
	result = std::imag(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_log
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_log : public Operator {
public:
	inline Operator_Math_log() : Operator(OPTYPE_Math_log) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::log(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_log::Calc(Complex &result, const Complex &var)
{
	result = std::log(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_log10
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_log10 : public Operator {
public:
	inline Operator_Math_log10() : Operator(OPTYPE_Math_log10) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::log10(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_log10::Calc(Complex &result, const Complex &var)
{
	result = std::log10(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_norm
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_norm : public Operator {
public:
	inline Operator_Math_norm() : Operator(OPTYPE_Math_norm) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		T_Result varCasted = static_cast<T_Result>(var);
		result =  varCasted * varCasted;
	}
};

template<> inline void Operator_Math_norm::Calc(Complex &result, const Complex &var)
{
	result = std::norm(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_ramp
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_ramp : public Operator {
public:
	inline Operator_Math_ramp() : Operator(OPTYPE_Math_ramp) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>((var >= 0)? var : 0);
	}
};

template<> inline void Operator_Math_ramp::Calc(Complex &result, const Complex &var)
{
	result = (var.imag() == 0 && var.real() >= 0)? var : Complex::Zero;
}

//-----------------------------------------------------------------------------
// Operator_Math_real
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_real : public Operator {
public:
	inline Operator_Math_real() : Operator(OPTYPE_Math_real) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(var);
	}
};

template<> inline void Operator_Math_real::Calc(Double &result, const Complex &var)
{
	result = std::real(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_sigmoid
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_sigmoid : public Operator {
public:
	inline Operator_Math_sigmoid() : Operator(OPTYPE_Math_sigmoid) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(1 / (1 + ::exp(-static_cast<Double>(var))));
	}
};

template<> inline void Operator_Math_sigmoid::Calc(Complex &result, const Complex &var)
{
	result = 1. / (1. + std::exp(-var));
}

//-----------------------------------------------------------------------------
// Operator_Math_sin
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_sin : public Operator {
public:
	inline Operator_Math_sin() : Operator(OPTYPE_Math_sin) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::sin(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_sin::Calc(Complex &result, const Complex &var)
{
	result = std::sin(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_sinh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_sinh : public Operator {
public:
	inline Operator_Math_sinh() : Operator(OPTYPE_Math_sinh) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::sinh(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_sinh::Calc(Complex &result, const Complex &var)
{
	result = std::sinh(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_sqrt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_sqrt : public Operator {
public:
	inline Operator_Math_sqrt() : Operator(OPTYPE_Math_sqrt) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::sqrt(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_sqrt::Calc(Complex &result, const Complex &var)
{
	result = std::sqrt(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_tan
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_tan : public Operator {
public:
	inline Operator_Math_tan() : Operator(OPTYPE_Math_tan) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::tan(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_tan::Calc(Complex &result, const Complex &var)
{
	result = std::tan(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_tanh : public Operator {
public:
	inline Operator_Math_tanh() : Operator(OPTYPE_Math_tanh) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>(::tanh(static_cast<Double>(var)));
	}
};

template<> inline void Operator_Math_tanh::Calc(Complex &result, const Complex &var)
{
	result = std::tanh(var);
}

//-----------------------------------------------------------------------------
// Operator_Math_unitstep
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_unitstep : public Operator {
public:
	inline Operator_Math_unitstep() : Operator(OPTYPE_Math_unitstep) {}
public:
	template<typename T_Result, typename T_Var>
	inline static void Calc(T_Result &result, const T_Var &var) {
		result = static_cast<T_Result>((var >= 0)? 1 : 0);
	}
};

template<> inline void Operator_Math_unitstep::Calc(Complex &result, const Complex &var)
{
	result = (var.imag() == 0 && var.real() >= 0)? Complex(1) : Complex::Zero;
}

//-----------------------------------------------------------------------------
// OperatorEntry
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE OperatorEntry {
protected:
	OpType _opType;
	ValueType _valTypeLeft;
	ValueType _valTypeRight;
public:
	inline OperatorEntry(OpType opType, ValueType valTypeLeft, ValueType valTypeRight) :
			_opType(opType), _valTypeLeft(valTypeLeft), _valTypeRight(valTypeRight) {}
	virtual ~OperatorEntry();
	inline OpType GetOpType() const { return _opType; }
	inline ValueType GetValueType() const { return _valTypeLeft; }
	inline ValueType GetValueTypeLeft() const { return _valTypeLeft; }
	inline ValueType GetValueTypeRight() const { return _valTypeRight; }
	inline Operator::Key CalcKey() const { return Operator::CalcKey(_valTypeLeft, _valTypeRight); }
	inline const Operator::SymbolInfo &GetSymbolInfo() const {
		return Operator::GetSymbolInfo(_opType);
	}
	inline bool IsIdentical(const OperatorEntry &operatorEntry) const {
		return GetOpType() == operatorEntry.GetOpType() &&
			GetValueTypeLeft() == operatorEntry.GetValueTypeLeft() &&
			GetValueTypeRight() == operatorEntry.GetValueTypeRight();
	}
	virtual Value DoEval(Environment &env, const Value &value, ULong flags) const;
	virtual Value DoEval(Environment &env,
						 const Value &valueLeft, const Value &valueRight, ULong flags) const;
	void SetError_InvalidValueType(Signal &sig, const Value &value) const;
	void SetError_InvalidValueType(Signal &sig, const Value &valueLeft, const Value &valueRight) const;
};

//-----------------------------------------------------------------------------
// OperatorEntryCustom
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE OperatorEntryCustom : public OperatorEntry {
private:
	AutoPtr<Function> _pFunc;
public:
	inline OperatorEntryCustom(OpType opType, ValueType valTypeL, ValueType valTypeR, Function *pFunc) :
					OperatorEntry(opType, valTypeL, valTypeR), _pFunc(pFunc) {}
	virtual Value DoEval(Environment &env, const Value &value, ULong flags) const;
	virtual Value DoEval(Environment &env,
						 const Value &valueLeft, const Value &valueRight, ULong flags) const;
};

//-----------------------------------------------------------------------------
// OperatorEntryDerived
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE OperatorEntryDerived : public OperatorEntry {
private:
	OperatorEntry *_pOperatorEntryOrg;
public:
	inline OperatorEntryDerived(OperatorEntry *pOperatorEntryOrg,
								ValueType valTypeL, ValueType valTypeR) :
			OperatorEntry(pOperatorEntryOrg->GetOpType(), valTypeL, valTypeR),
			_pOperatorEntryOrg(pOperatorEntryOrg) {}
	virtual Value DoEval(Environment &env, const Value &value, ULong flags) const;
	virtual Value DoEval(Environment &env,
						 const Value &valueLeft, const Value &valueRight, ULong flags) const;
};

}

#endif
