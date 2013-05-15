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
			Parser::ElemType elemType, OpType opType,
			unsigned long flags = FLAG_Map, ValueType valType = VTYPE_any);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual Expr *DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const;
	virtual Expr *OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const;
};

//-----------------------------------------------------------------------------
// FuncBinaryOperator
//-----------------------------------------------------------------------------
class FuncBinaryOperator : public Function {
public:
	FuncBinaryOperator(Environment &env, const Symbol *pSymbol,
			Parser::ElemType elemType, OpType opType,
			unsigned long flags = FLAG_Map, ValueType valType = VTYPE_any);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	virtual Expr *DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const;
	virtual Expr *OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const;
};

//-----------------------------------------------------------------------------
// basic Operators
//-----------------------------------------------------------------------------
class Func_Pos : public FuncUnaryOperator {
public:
	Func_Pos(Environment &env);
};

class Func_Neg : public FuncUnaryOperator {
public:
	Func_Neg(Environment &env);
};

class Func_Inv : public FuncUnaryOperator {
public:
	Func_Inv(Environment &env);
};

class Func_Not : public FuncUnaryOperator {
public:
	Func_Not(Environment &env);
};

class Func_SeqInf : public FuncUnaryOperator {
public:
	Func_SeqInf(Environment &env);
};

class Func_Add : public FuncBinaryOperator {
public:
	Func_Add(Environment &env);
};

class Func_Sub : public FuncBinaryOperator {
public:
	Func_Sub(Environment &env);
};

class Func_Mul : public FuncBinaryOperator {
public:
	Func_Mul(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
};

class Func_Div : public FuncBinaryOperator {
public:
	Func_Div(Environment &env);
};

class Func_Mod : public FuncBinaryOperator {
public:
	Func_Mod(Environment &env);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
};

class Func_Pow : public FuncBinaryOperator {
public:
	Func_Pow(Environment &env);
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

class Func_OrOr : public FuncBinaryOperator {
public:
	Func_OrOr(Environment &env);
};

class Func_AndAnd : public FuncBinaryOperator {
public:
	Func_AndAnd(Environment &env);
};

class Func_Seq : public FuncBinaryOperator {
public:
	Func_Seq(Environment &env);
};

}

#endif
