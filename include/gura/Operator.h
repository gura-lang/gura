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
	inline static OperatorEntry_##op##_##type *Create() { \
		return new OperatorEntry_##op##_##type(); \
	} \
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const; \
}; \
Value OperatorEntry_##op##_##type::DoEval(Environment &env, Signal sig, const Value &value) const

#define Gura_ImplementUnaryOperatorSuffix(op, type) \
class OperatorEntry_##op##_##type##_suffix : public OperatorEntry { \
public: \
	inline OperatorEntry_##op##_##type##_suffix() : \
					OperatorEntry(OPTYPE_##op, VTYPE_undefined, VTYPE_##type) {} \
	inline static OperatorEntry_##op##_##type##_suffix *Create() { \
		return new OperatorEntry_##op##_##type##_suffix(); \
	} \
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const; \
}; \
Value OperatorEntry_##op##_##type##_suffix::DoEval(Environment &env, Signal sig, const Value &value) const

#define Gura_ImplementBinaryOperator(op, typeL, typeR) \
class OperatorEntry_##op##_##typeL##_##typeR : public OperatorEntry { \
public: \
	inline OperatorEntry_##op##_##typeL##_##typeR() : \
					OperatorEntry(OPTYPE_##op, VTYPE_##typeL, VTYPE_##typeR) {} \
	inline static OperatorEntry_##op##_##typeL##_##typeR *Create() { \
		return new OperatorEntry_##op##_##typeL##_##typeR(); \
	} \
	virtual Value DoEval(Environment &env, Signal sig, \
				const Value &valueLeft, const Value &valueRight) const; \
}; \
Value OperatorEntry_##op##_##typeL##_##typeR::DoEval(Environment &env, Signal sig, \
					const Value &valueLeft, const Value &valueRight) const

#define Gura_AssignUnaryOperator(op, type) \
Operator::Assign(env, new OperatorEntry_##op##_##type())

#define Gura_AssignUnaryOperatorSuffix(op, type) \
Operator::Assign(env, new OperatorEntry_##op##_##type##_suffix())

#define Gura_AssignBinaryOperator(op, typeL, typeR) \
Operator::Assign(env, new OperatorEntry_##op##_##typeL##_##typeR())

namespace Gura {

// the order of Operator::_mathSymbolTbl depends on OpType numbers.
enum OpType {
	OPTYPE_None,
	// unary operators
	OPTYPE_unary,
	OPTYPE_Pos		= OPTYPE_unary,
	OPTYPE_Neg,
	OPTYPE_Inv,
	OPTYPE_Not,
	OPTYPE_SeqInf,
	OPTYPE_Question,
	// binary operators
	OPTYPE_binary,
	OPTYPE_Add		= OPTYPE_binary,
	OPTYPE_Sub,
	OPTYPE_Mul,
	OPTYPE_Div,
	OPTYPE_Mod,
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
	typedef ULong Key;
	typedef std::map<Key, OperatorEntry *> EntryDict;
private:
	OpType _opType;
	const Symbol *_pSymbol;
	bool _mapFlag;
	EntryDict _entryDict;
	static const char *_mathSymbolTbl[];
public:
	inline Operator(OpType opType, bool mapFlag = true) :
		_opType(opType), _pSymbol(Symbol::Add(_mathSymbolTbl[opType])), _mapFlag(mapFlag) {}
	inline OpType GetOpType() const { return _opType; }
	inline EntryDict &GetEntryDict() { return _entryDict; }
	inline const EntryDict &GetEntryDict() const { return _entryDict; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline static const char *GetMathSymbol(OpType opType) { return _mathSymbolTbl[opType]; }
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
	const OperatorEntry *Lookup(ValueType valType, bool suffixFlag) const;
	const OperatorEntry *Lookup(ValueType valTypeLeft, ValueType valTypeRight) const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	Expr *OptimizeConst(Environment &env, Signal sig,
									Expr_Value *pExprChild, bool suffixFlag) const;
	Expr *OptimizeConst(Environment &env, Signal sig,
									Expr_Value *pExprLeft, Expr_Value *pExprRight) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const;
	static OpType LookupUnaryOpType(const char *str);
	static OpType LookupBinaryOpType(const char *str);
	Value EvalUnary(Environment &env, Signal sig, const Value &value, bool suffixFlag) const;
	Value EvalBinary(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
	virtual Value EvalMapUnary(Environment &env, Signal sig,
									const Value &value, bool suffixFlag) const;
	virtual Value EvalMapBinary(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
	static void SetError_InvalidValueType(Signal &sig, OpType opType,
									const Value &value, bool suffixFlag);
	static void SetError_InvalidValueType(Signal &sig, OpType opType,
					const Value &valueLeft, const Value &valueRight);
	static void Assign(Environment &env, OperatorEntry *pOperatorEntry);
	static void SetError_DivideByZero(Signal &sig);
	static void SetError_MathDiffError(Signal &sig);
	static void SetError_MathOptimizeError(Signal &sig);
	static void AssignOperators(Environment &env);
};

//-----------------------------------------------------------------------------
// Operator_Pos
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Pos : public Operator {
public:
	inline Operator_Pos() : Operator(OPTYPE_Pos) {}
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizeExpr(Environment &env, Signal sig, Expr *pExprChild);
};

//-----------------------------------------------------------------------------
// Operator_Neg
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Neg : public Operator {
public:
	inline Operator_Neg() : Operator(OPTYPE_Neg) {}
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizeExpr(Environment &env, Signal sig, Expr *pExprChild);
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
// Operator_Add
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Add : public Operator {
public:
	inline Operator_Add() : Operator(OPTYPE_Add) {}
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizeExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

//-----------------------------------------------------------------------------
// Operator_Sub
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Sub : public Operator {
public:
	inline Operator_Sub() : Operator(OPTYPE_Sub) {}
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizeExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

//-----------------------------------------------------------------------------
// Operator_Mul
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Mul : public Operator {
public:
	inline Operator_Mul() : Operator(OPTYPE_Mul) {}
	virtual Value EvalMapBinary(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizeExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

//-----------------------------------------------------------------------------
// Operator_Div
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Div : public Operator {
public:
	inline Operator_Div() : Operator(OPTYPE_Div) {}
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizeExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

//-----------------------------------------------------------------------------
// Operator_Mod
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Mod : public Operator {
public:
	inline Operator_Mod() : Operator(OPTYPE_Mod) {}
	virtual Value EvalMapBinary(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
};

//-----------------------------------------------------------------------------
// Operator_Pow
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Operator_Pow : public Operator {
public:
	inline Operator_Pow() : Operator(OPTYPE_Pow) {}
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizeExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
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
	virtual Value EvalMapBinary(Environment &env, Signal sig,
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
	virtual Value EvalMapBinary(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
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
	inline OpType GetOpType() const { return _opType; }
	inline ValueType GetValueType() const { return _valTypeLeft; }
	inline ValueType GetValueTypeLeft() const { return _valTypeLeft; }
	inline ValueType GetValueTypeRight() const { return _valTypeRight; }
	inline Operator::Key CalcKey() const { return Operator::CalcKey(_valTypeLeft, _valTypeRight); }
	inline const char *GetMathSymbol() const { return Operator::GetMathSymbol(_opType); }
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const;
	virtual Value DoEval(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const;
	void SetError_InvalidValueType(Signal &sig, const Value &value, bool suffixFlag) const;
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
	virtual Value DoEval(Environment &env, Signal sig, const Value &value) const;
	virtual Value DoEval(Environment &env, Signal sig,
				const Value &valueLeft, const Value &valueRight) const;
};

}

#endif
