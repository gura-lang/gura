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
	virtual Value DoEval(Environment &env, const Value &value) const; \
}; \
Value OperatorEntry_##op##_##type::DoEval(Environment &env, const Value &value) const

#define Gura_ImplementUnaryOperatorSuffix(op, type) \
class OperatorEntry_##op##_##type##_suffix : public OperatorEntry { \
public: \
	inline OperatorEntry_##op##_##type##_suffix() : \
					OperatorEntry(OPTYPE_##op, VTYPE_undefined, VTYPE_##type) {} \
	virtual Value DoEval(Environment &env, const Value &value) const; \
}; \
Value OperatorEntry_##op##_##type##_suffix::DoEval(Environment &env, const Value &value) const

#define Gura_ImplementBinaryOperator(op, typeL, typeR) \
class OperatorEntry_##op##_##typeL##_##typeR : public OperatorEntry { \
public: \
	inline OperatorEntry_##op##_##typeL##_##typeR() : \
					OperatorEntry(OPTYPE_##op, VTYPE_##typeL, VTYPE_##typeR) {} \
	virtual Value DoEval(Environment &env, \
				const Value &valueLeft, const Value &valueRight) const; \
}; \
Value OperatorEntry_##op##_##typeL##_##typeR::DoEval(Environment &env, \
					const Value &valueLeft, const Value &valueRight) const

#define Gura_AssignUnaryOperator(op, type) \
Operator::Assign(env, new OperatorEntry_##op##_##type())

#define Gura_AssignUnaryOperatorSuffix(op, type) \
Operator::Assign(env, new OperatorEntry_##op##_##type##_suffix())

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
	inline EntryDict &GetEntryDict() { return _entryDict; }
	inline const EntryDict &GetEntryDict() const { return _entryDict; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetName() const { return _symbolInfoTbl[_opType].name; }
	inline static const SymbolInfo &GetSymbolInfo(OpType opType) { return _symbolInfoTbl[opType]; }
	inline static Key CalcKey(ValueType valType, bool suffixFlag) {
		if (suffixFlag) {
			return static_cast<Key>((static_cast<ULong>(valType) << 16) +
							static_cast<ULong>(VTYPE_undefined));
		} else {
			return static_cast<Key>((static_cast<ULong>(VTYPE_undefined) << 16) +
							static_cast<ULong>(valType));
		}
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
	Value EvalUnary(Environment &env, const Value &value) const;
	Value EvalBinary(Environment &env,
					 const Value &valueLeft, const Value &valueRight) const;
	virtual Value EvalMapUnary(Environment &env, const Value &value) const;
	virtual Value EvalMapBinary(Environment &env,
					const Value &valueLeft, const Value &valueRight) const;
	static void SetError_InvalidValueType(Signal &sig, OpType opType, const Value &value);
	static void SetError_InvalidValueType(Signal &sig, OpType opType,
					const Value &valueLeft, const Value &valueRight);
	static void Assign(Environment &env, OperatorEntry *pOperatorEntry);
	static void SetError_DivideByZero(Signal &sig);
	static void SetError_MathDiffError(Signal &sig);
	static void SetError_MathOptimizeError(Signal &sig);
	static void Initialize(Environment &env);
private:
	static void AssignOperatorBasic(Environment &env);
	//static void AssignOperator_array(Environment &env);
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
};

//-----------------------------------------------------------------------------
// Operator_Mul
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Mul : public Operator {
public:
	inline Operator_Mul() : Operator(OPTYPE_Mul) {}
	virtual Value EvalMapBinary(Environment &env,
					const Value &valueLeft, const Value &valueRight) const;
	virtual Expr *MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const;
	virtual Expr *MathOptimizeBinary(Environment &env,
										Expr *pExprLeft, Expr *pExprRight) const;
	static Expr *MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight);
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
};

//-----------------------------------------------------------------------------
// Operator_Mod
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Mod : public Operator {
public:
	inline Operator_Mod() : Operator(OPTYPE_Mod) {}
	virtual Value EvalMapBinary(Environment &env,
					const Value &valueLeft, const Value &valueRight) const;
};

//-----------------------------------------------------------------------------
// Operator_ModMod
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_ModMod : public Operator {
public:
	inline Operator_ModMod() : Operator(OPTYPE_ModMod) {}
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
};

//-----------------------------------------------------------------------------
// Operator_Eq
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Eq : public Operator {
public:
	inline Operator_Eq() : Operator(OPTYPE_Eq) {}
};

//-----------------------------------------------------------------------------
// Operator_Ne
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Ne : public Operator {
public:
	inline Operator_Ne() : Operator(OPTYPE_Ne) {}
};

//-----------------------------------------------------------------------------
// Operator_Gt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Gt : public Operator {
public:
	inline Operator_Gt() : Operator(OPTYPE_Gt) {}
};

//-----------------------------------------------------------------------------
// Operator_Lt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Lt : public Operator {
public:
	inline Operator_Lt() : Operator(OPTYPE_Lt) {}
};

//-----------------------------------------------------------------------------
// Operator_Ge
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Ge : public Operator {
public:
	inline Operator_Ge() : Operator(OPTYPE_Ge) {}
};

//-----------------------------------------------------------------------------
// Operator_Le
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Le : public Operator {
public:
	inline Operator_Le() : Operator(OPTYPE_Le) {}
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
	inline Operator_Contains() : Operator(OPTYPE_Contains) {}
	virtual Value EvalMapBinary(Environment &env,
					const Value &valueLeft, const Value &valueRight) const;
};

//-----------------------------------------------------------------------------
// Operator_Or
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Or : public Operator {
public:
	inline Operator_Or() : Operator(OPTYPE_Or) {}
};

//-----------------------------------------------------------------------------
// Operator_And
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_And : public Operator {
public:
	inline Operator_And() : Operator(OPTYPE_And) {}
};

//-----------------------------------------------------------------------------
// Operator_Xor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Xor : public Operator {
public:
	inline Operator_Xor() : Operator(OPTYPE_Xor) {}
};

//-----------------------------------------------------------------------------
// Operator_Shl
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Shl : public Operator {
public:
	inline Operator_Shl() : Operator(OPTYPE_Shl) {}
};

//-----------------------------------------------------------------------------
// Operator_Shr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Shr : public Operator {
public:
	inline Operator_Shr() : Operator(OPTYPE_Shr) {}
};

//-----------------------------------------------------------------------------
// Operator_OrOr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_OrOr : public Operator {
public:
	inline Operator_OrOr() : Operator(OPTYPE_OrOr) {}
};

//-----------------------------------------------------------------------------
// Operator_AndAnd
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_AndAnd : public Operator {
public:
	inline Operator_AndAnd() : Operator(OPTYPE_AndAnd) {}
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
	inline Operator_Pair() : Operator(OPTYPE_Pair) {}
	virtual Value EvalMapBinary(Environment &env,
					const Value &valueLeft, const Value &valueRight) const;
};

//-----------------------------------------------------------------------------
// Operator_Math_abs
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_abs : public Operator {
public:
	inline Operator_Math_abs() : Operator(OPTYPE_Math_abs) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_acos
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_acos : public Operator {
public:
	inline Operator_Math_acos() : Operator(OPTYPE_Math_acos) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_arg
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_arg : public Operator {
public:
	inline Operator_Math_arg() : Operator(OPTYPE_Math_arg) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_asin
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_asin : public Operator {
public:
	inline Operator_Math_asin() : Operator(OPTYPE_Math_asin) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_atan
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_atan : public Operator {
public:
	inline Operator_Math_atan() : Operator(OPTYPE_Math_atan) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_atan2
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_atan2 : public Operator {
public:
	inline Operator_Math_atan2() : Operator(OPTYPE_Math_atan2) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_ceil
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_ceil : public Operator {
public:
	inline Operator_Math_ceil() : Operator(OPTYPE_Math_ceil) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_conj
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_conj : public Operator {
public:
	inline Operator_Math_conj() : Operator(OPTYPE_Math_conj) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_cos
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_cos : public Operator {
public:
	inline Operator_Math_cos() : Operator(OPTYPE_Math_cos) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_cosh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_cosh : public Operator {
public:
	inline Operator_Math_cosh() : Operator(OPTYPE_Math_cosh) {}
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
};

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
};

//-----------------------------------------------------------------------------
// Operator_Math_floor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_floor : public Operator {
public:
	inline Operator_Math_floor() : Operator(OPTYPE_Math_floor) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_hypot
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_hypot : public Operator {
public:
	inline Operator_Math_hypot() : Operator(OPTYPE_Math_hypot) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_imag
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_imag : public Operator {
public:
	inline Operator_Math_imag() : Operator(OPTYPE_Math_imag) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_log
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_log : public Operator {
public:
	inline Operator_Math_log() : Operator(OPTYPE_Math_log) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_log10
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_log10 : public Operator {
public:
	inline Operator_Math_log10() : Operator(OPTYPE_Math_log10) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_norm
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_norm : public Operator {
public:
	inline Operator_Math_norm() : Operator(OPTYPE_Math_norm) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_ramp
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_ramp : public Operator {
public:
	inline Operator_Math_ramp() : Operator(OPTYPE_Math_ramp) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_real
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_real : public Operator {
public:
	inline Operator_Math_real() : Operator(OPTYPE_Math_real) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_sin
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_sin : public Operator {
public:
	inline Operator_Math_sin() : Operator(OPTYPE_Math_sin) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_sinh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_sinh : public Operator {
public:
	inline Operator_Math_sinh() : Operator(OPTYPE_Math_sinh) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_sqrt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_sqrt : public Operator {
public:
	inline Operator_Math_sqrt() : Operator(OPTYPE_Math_sqrt) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_tan
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_tan : public Operator {
public:
	inline Operator_Math_tan() : Operator(OPTYPE_Math_tan) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_tanh : public Operator {
public:
	inline Operator_Math_tanh() : Operator(OPTYPE_Math_tanh) {}
};

//-----------------------------------------------------------------------------
// Operator_Math_unitstep
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Math_unitstep : public Operator {
public:
	inline Operator_Math_unitstep() : Operator(OPTYPE_Math_unitstep) {}
};

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
	virtual Value DoEval(Environment &env, const Value &value) const;
	virtual Value DoEval(Environment &env,
					const Value &valueLeft, const Value &valueRight) const;
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
	virtual Value DoEval(Environment &env, const Value &value) const;
	virtual Value DoEval(Environment &env,
				const Value &valueLeft, const Value &valueRight) const;
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
	virtual Value DoEval(Environment &env, const Value &value) const;
	virtual Value DoEval(Environment &env,
				const Value &valueLeft, const Value &valueRight) const;
};

}

#endif
