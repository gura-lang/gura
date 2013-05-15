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
};

class Func_Neg : public FuncUnaryOperator {
public:
	Func_Neg(Environment &env);
	virtual bool IsNeg() const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
};

class Func_Inv : public FuncUnaryOperator {
public:
	Func_Inv(Environment &env);
};

class Func_Not : public FuncUnaryOperator {
public:
	Func_Not(Environment &env);
};

class Func_Add : public FuncBinaryOperator {
public:
	Func_Add(Environment &env);
	virtual bool IsAdd() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
};

class Func_Sub : public FuncBinaryOperator {
public:
	Func_Sub(Environment &env);
	virtual bool IsSub() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
};

class Func_Mul : public FuncBinaryOperator {
public:
	Func_Mul(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual bool IsMul() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
};

class Func_Div : public FuncBinaryOperator {
public:
	Func_Div(Environment &env);
	virtual bool IsDiv() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
};

class Func_Mod : public FuncBinaryOperator {
public:
	Func_Mod(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual bool IsMod() const;
};

class Func_Pow : public FuncBinaryOperator {
public:
	Func_Pow(Environment &env);
	virtual bool IsPow() const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
};

class Func_Eq : public FuncBinaryOperator {
public:
	Func_Eq(Environment &env);
};

class Func_Ne : public FuncBinaryOperator {
public:
	Func_Ne(Environment &env);
};

class Func_Gt : public FuncBinaryOperator {
public:
	Func_Gt(Environment &env);
};

class Func_Lt : public FuncBinaryOperator {
public:
	Func_Lt(Environment &env);
};

class Func_Ge : public FuncBinaryOperator {
public:
	Func_Ge(Environment &env);
};

class Func_Le : public FuncBinaryOperator {
public:
	Func_Le(Environment &env);
};

class Func_Cmp : public FuncBinaryOperator {
public:
	Func_Cmp(Environment &env);
};

class Func_Contains : public FuncBinaryOperator {
public:
	Func_Contains(Environment &env);
	virtual bool IsContains() const;
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

class Func_Shl : public FuncBinaryOperator {
public:
	Func_Shl(Environment &env);
};

class Func_Shr : public FuncBinaryOperator {
public:
	Func_Shr(Environment &env);
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

class Func_Seq : public FuncBinaryOperator {
public:
	Func_Seq(Environment &env);
	virtual bool IsSeq() const;
};

class Func_SeqInf : public FuncUnaryOperator {
public:
	Func_SeqInf(Environment &env);
};

}

#endif
