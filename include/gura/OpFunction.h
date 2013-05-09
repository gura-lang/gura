#ifndef __GURA_OPFUNCTION_H__
#define __GURA_OPFUNCTION_H__

#include "Common.h"
#include "Function.h"

namespace Gura {

void AssignOpFunctions(Environment &env);

//-----------------------------------------------------------------------------
// FuncUnaryOperation
//-----------------------------------------------------------------------------
class FuncUnaryOperation : public Function {
public:
	FuncUnaryOperation(Environment &env, const Symbol *pSymbol);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// FuncBinaryOperation
//-----------------------------------------------------------------------------
class FuncBinaryOperation : public Function {
public:
	FuncBinaryOperation(Environment &env, const Symbol *pSymbol);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// basic operations
//-----------------------------------------------------------------------------
class Func_Pos : public FuncUnaryOperation {
public:
	Func_Pos(Environment &env);
	virtual bool IsPos() const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild);
};

class Func_Neg : public FuncUnaryOperation {
public:
	Func_Neg(Environment &env);
	virtual bool IsNeg() const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild);
};

class Func_Invert : public FuncUnaryOperation {
public:
	Func_Invert(Environment &env);
};

class Func_Not : public FuncUnaryOperation {
public:
	Func_Not(Environment &env);
};

class Func_Plus : public FuncBinaryOperation {
public:
	Func_Plus(Environment &env);
	virtual bool IsPlus() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Minus : public FuncBinaryOperation {
public:
	Func_Minus(Environment &env);
	virtual bool IsMinus() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Multiply : public FuncBinaryOperation {
public:
	Func_Multiply(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual bool IsMultiply() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Divide : public FuncBinaryOperation {
public:
	Func_Divide(Environment &env);
	virtual bool IsDivide() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Modulo : public FuncBinaryOperation {
public:
	Func_Modulo(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual bool IsModulo() const;
};

class Func_Power : public FuncBinaryOperation {
public:
	Func_Power(Environment &env);
	virtual bool IsPower() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Equal : public FuncBinaryOperation {
public:
	Func_Equal(Environment &env);
};

class Func_NotEqual : public FuncBinaryOperation {
public:
	Func_NotEqual(Environment &env);
};

class Func_Greater : public FuncBinaryOperation {
public:
	Func_Greater(Environment &env);
};

class Func_Less : public FuncBinaryOperation {
public:
	Func_Less(Environment &env);
};

class Func_GreaterEq : public FuncBinaryOperation {
public:
	Func_GreaterEq(Environment &env);
};

class Func_LessEq : public FuncBinaryOperation {
public:
	Func_LessEq(Environment &env);
};

class Func_Compare : public FuncBinaryOperation {
public:
	Func_Compare(Environment &env);
};

class Func_ContainCheck : public FuncBinaryOperation {
public:
	Func_ContainCheck(Environment &env);
	virtual bool IsContainCheck() const;
};

class Func_Or : public FuncBinaryOperation {
public:
	Func_Or(Environment &env);
};

class Func_And : public FuncBinaryOperation {
public:
	Func_And(Environment &env);
};

class Func_Xor : public FuncBinaryOperation {
public:
	Func_Xor(Environment &env);
};

class Func_ShiftL : public FuncBinaryOperation {
public:
	Func_ShiftL(Environment &env);
};

class Func_ShiftR : public FuncBinaryOperation {
public:
	Func_ShiftR(Environment &env);
};

class Func_OrOr : public Function {
public:
	Func_OrOr(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_AndAnd : public Function {
public:
	Func_AndAnd(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Sequence : public FuncBinaryOperation {
public:
	Func_Sequence(Environment &env);
	virtual bool IsSequence() const;
};

class Func_SequenceInf : public FuncUnaryOperation {
public:
	Func_SequenceInf(Environment &env);
};

}

#endif
