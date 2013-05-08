#ifndef __GURA_OPFUNCTION_H__
#define __GURA_OPFUNCTION_H__

#include "Common.h"
#include "Function.h"

namespace Gura {

void AssignOperators(Environment &env);

//-----------------------------------------------------------------------------
// basic operations
//-----------------------------------------------------------------------------
class Func_Pos : public Function {
public:
	Func_Pos(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsPos() const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild);
};

class Func_Neg : public Function {
public:
	Func_Neg(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsNeg() const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild);
};

class Func_Invert : public Function {
public:
	Func_Invert(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Not : public Function {
public:
	Func_Not(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Plus : public Function {
public:
	Func_Plus(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsPlus() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Minus : public Function {
public:
	Func_Minus(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsMinus() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Multiply : public Function {
public:
	Func_Multiply(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsMultiply() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Divide : public Function {
public:
	Func_Divide(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsDivide() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Modulo : public Function {
public:
	Func_Modulo(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsModulo() const;
};

class Func_format : public Function {
public:
	Func_format(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Power : public Function {
public:
	Func_Power(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsPower() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
	static Expr *OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight);
};

class Func_Equal : public Function {
public:
	Func_Equal(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_NotEqual : public Function {
public:
	Func_NotEqual(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Greater : public Function {
public:
	Func_Greater(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Less : public Function {
public:
	Func_Less(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_GreaterEq : public Function {
public:
	Func_GreaterEq(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_LessEq : public Function {
public:
	Func_LessEq(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Compare : public Function {
public:
	Func_Compare(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_ContainCheck : public Function {
public:
	Func_ContainCheck(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual bool IsContainCheck() const;
};

class Func_Or : public Function {
public:
	Func_Or(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_And : public Function {
public:
	Func_And(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_Xor : public Function {
public:
	Func_Xor(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_ShiftL : public Function {
public:
	Func_ShiftL(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_ShiftR : public Function {
public:
	Func_ShiftR(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
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

class Func_Sequence : public Function {
public:
	Func_Sequence(Environment &env);
	virtual bool IsSequence() const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

class Func_SequenceInf : public Function {
public:
	Func_SequenceInf(Environment &env);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

}

#endif
