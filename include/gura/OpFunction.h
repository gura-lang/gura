#ifndef __GURA_OPFUNCTION_H__
#define __GURA_OPFUNCTION_H__

#include "Common.h"
#include "Function.h"

namespace Gura {

void AssignOpFunctions(Environment &env);

//-----------------------------------------------------------------------------
// FuncUnaryOperator
//-----------------------------------------------------------------------------
class FuncUnaryOperator : public Function {
public:
	FuncUnaryOperator(Environment &env, const Symbol *pSymbol,
		Parser::ElemType elemType, OpType opType, unsigned long flags = FLAG_Map);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// FuncBinaryOperator
//-----------------------------------------------------------------------------
class FuncBinaryOperator : public Function {
public:
	FuncBinaryOperator(Environment &env, const Symbol *pSymbol,
		Parser::ElemType elemType, OpType opType, unsigned long flags = FLAG_Map);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// basic Operators
//-----------------------------------------------------------------------------
class Func_Pos : public FuncUnaryOperator {
public:
	Func_Pos(Environment &env);
	virtual bool IsPos() const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild);
};

class Func_Neg : public FuncUnaryOperator {
public:
	Func_Neg(Environment &env);
	virtual bool IsNeg() const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild);
};

class Func_Invert : public FuncUnaryOperator {
public:
	Func_Invert(Environment &env);
};

class Func_Not : public FuncUnaryOperator {
public:
	Func_Not(Environment &env);
};

class Func_Plus : public FuncBinaryOperator {
public:
	Func_Plus(Environment &env);
	virtual bool IsPlus() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Minus : public FuncBinaryOperator {
public:
	Func_Minus(Environment &env);
	virtual bool IsMinus() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Multiply : public FuncBinaryOperator {
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

class Func_Divide : public FuncBinaryOperator {
public:
	Func_Divide(Environment &env);
	virtual bool IsDivide() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Modulo : public FuncBinaryOperator {
public:
	Func_Modulo(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual bool IsModulo() const;
};

class Func_Power : public FuncBinaryOperator {
public:
	Func_Power(Environment &env);
	virtual bool IsPower() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Equal : public FuncBinaryOperator {
public:
	Func_Equal(Environment &env);
};

class Func_NotEqual : public FuncBinaryOperator {
public:
	Func_NotEqual(Environment &env);
};

class Func_Greater : public FuncBinaryOperator {
public:
	Func_Greater(Environment &env);
};

class Func_Less : public FuncBinaryOperator {
public:
	Func_Less(Environment &env);
};

class Func_GreaterEq : public FuncBinaryOperator {
public:
	Func_GreaterEq(Environment &env);
};

class Func_LessEq : public FuncBinaryOperator {
public:
	Func_LessEq(Environment &env);
};

class Func_Compare : public FuncBinaryOperator {
public:
	Func_Compare(Environment &env);
};

class Func_ContainCheck : public FuncBinaryOperator {
public:
	Func_ContainCheck(Environment &env);
	virtual bool IsContainCheck() const;
};

class Func_Or : public FuncBinaryOperator {
public:
	Func_Or(Environment &env);
};

class Func_And : public FuncBinaryOperator {
public:
	Func_And(Environment &env);
};

class Func_Xor : public FuncBinaryOperator {
public:
	Func_Xor(Environment &env);
};

class Func_ShiftL : public FuncBinaryOperator {
public:
	Func_ShiftL(Environment &env);
};

class Func_ShiftR : public FuncBinaryOperator {
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

class Func_Sequence : public FuncBinaryOperator {
public:
	Func_Sequence(Environment &env);
	virtual bool IsSequence() const;
};

class Func_SequenceInf : public FuncUnaryOperator {
public:
	Func_SequenceInf(Environment &env);
};

}

#endif
