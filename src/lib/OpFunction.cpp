#include "stdafx.h"

namespace Gura {

static Expr *OptimizeConst(Environment &env, Signal sig,
						const Function *func, Expr *pExprChild);
static Expr *OptimizeConst(Environment &env, Signal sig,
						const Function *func, Expr *pExprLeft, Expr *pExprRight);

//-----------------------------------------------------------------------------
// Operator assignment
//-----------------------------------------------------------------------------
void AssignOpFunctions(Environment &env)
{
	Environment::Global *pGlobal = env.GetGlobal();
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Pos]			= new Func_Pos(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Neg]			= new Func_Neg(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Invert]		= new Func_Invert(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Not]			= new Func_Not(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Plus]		= new Func_Plus(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Minus]		= new Func_Minus(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Multiply]	= new Func_Multiply(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Divide]		= new Func_Divide(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Modulo]		= new Func_Modulo(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Power]		= new Func_Power(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Equal]		= new Func_Equal(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_NotEqual]	= new Func_NotEqual(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Greater]		= new Func_Greater(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Less]		= new Func_Less(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_GreaterEq]	= new Func_GreaterEq(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_LessEq]		= new Func_LessEq(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Compare]		= new Func_Compare(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_ContainCheck] = new Func_ContainCheck(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Or]			= new Func_Or(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_And]			= new Func_And(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Xor]			= new Func_Xor(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_ShiftL]		= new Func_ShiftL(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_ShiftR]		= new Func_ShiftR(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_OrOr]		= new Func_OrOr(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_AndAnd]		= new Func_AndAnd(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_Sequence]	= new Func_Sequence(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pOpFuncTbl[OPTYPE_SequenceInf] = new Func_SequenceInf(env)));
}

//-----------------------------------------------------------------------------
// FuncUnaryOperation
//-----------------------------------------------------------------------------
FuncUnaryOperation::FuncUnaryOperation(Environment &env, const Symbol *pSymbol) :
						Function(env, pSymbol, FUNCTYPE_Function, FLAG_None)
{
}

Value FuncUnaryOperation::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &value = args.GetValue(0);
	const Operator *pOperator = Operator::Lookup(env, GetOpType(), value.GetValueType());
	if (pOperator == NULL) {
		Operator::SetError_InvalidValueType(sig, GetOpType(), value);
		return Value::Null;
	}
	return pOperator->DoEval(env, sig, value);
}

//-----------------------------------------------------------------------------
// FuncBinaryOperation
//-----------------------------------------------------------------------------
FuncBinaryOperation::FuncBinaryOperation(Environment &env, const Symbol *pSymbol) :
						Function(env, pSymbol, FUNCTYPE_Function, FLAG_None)
{
}

Value FuncBinaryOperation::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	const Operator *pOperator = Operator::Lookup(env, GetOpType(),
						valueLeft.GetValueType(), valueRight.GetValueType());
	if (pOperator == NULL) {
		Operator::SetError_InvalidValueType(sig, GetOpType(), valueLeft, valueRight);
		return Value::Null;
	}
	return pOperator->DoEval(env, sig, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// +n
//-----------------------------------------------------------------------------
bool Func_Pos::IsPos() const { return true; }

Func_Pos::Func_Pos(Environment &env) : FuncUnaryOperation(env, Symbol::Add("__pos__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Plus, OPTYPE_Pos);	// revise this later
	DeclareArg(env, "n", VTYPE_any);
}

Expr *Func_Pos::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	Expr *pExprDiff = pExprArg->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	return Func_Pos::OptimizedExpr(env, sig, pExprDiff);
}

Expr *Func_Pos::OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const
{
	return Func_Pos::OptimizedExpr(env, sig, pExprOpt);
}

Expr *Func_Pos::OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return NULL;
	}
	return pExprChild;
}

//-----------------------------------------------------------------------------
// -n
//-----------------------------------------------------------------------------
bool Func_Neg::IsNeg() const { return true; }

Func_Neg::Func_Neg(Environment &env) : FuncUnaryOperation(env, Symbol::Add("__neg__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Minus, OPTYPE_Neg);	// revise this later
	DeclareArg(env, "n", VTYPE_any);
}

Expr *Func_Neg::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	Expr *pExprWork = pExprArg->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	return Func_Neg::OptimizedExpr(env, sig, pExprWork);
}

Expr *Func_Neg::OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const
{
	return Func_Neg::OptimizedExpr(env, sig, pExprOpt);
}

Expr *Func_Neg::OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return NULL;
	}
	if (pExprChild->IsValue()) {
		return OptimizeConst(env, sig, env.GetOpFunc(OPTYPE_Neg), pExprChild);
	} else if (pExprChild->IsOperatorNeg()) {
		// -(-n) = n
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprChild)->GetChild());
		Expr::Delete(pExprChild);
		return pExpr;
	} else {
		return new Expr_UnaryOp(env.GetOpFunc(OPTYPE_Neg), pExprChild, false);
	}
}

//-----------------------------------------------------------------------------
// ~x
//-----------------------------------------------------------------------------
Func_Invert::Func_Invert(Environment &env) : FuncUnaryOperation(env, Symbol::Add("__invert__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Invert, OPTYPE_Invert);
	DeclareArg(env, "n", VTYPE_any);
}

//-----------------------------------------------------------------------------
// !n
//-----------------------------------------------------------------------------
Func_Not::Func_Not(Environment &env) : FuncUnaryOperation(env, Symbol::Add("__not__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Not, OPTYPE_Not);
	DeclareArg(env, "flag", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n + m
//-----------------------------------------------------------------------------
bool Func_Plus::IsPlus() const { return true; }

Func_Plus::Func_Plus(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__add__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Plus, OPTYPE_Plus);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Expr *Func_Plus::DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const
{
	Expr *pExprDiff1 = pExprArg1->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	Expr *pExprDiff2 = pExprArg2->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) {
		Expr::Delete(pExprDiff1);
		return NULL;
	}
	// (f(x) + g(x))' = f'(x) + g'(x)
	return Func_Plus::OptimizedExpr(env, sig, pExprDiff1, pExprDiff2);
}

Expr *Func_Plus::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Func_Plus::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Func_Plus::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOpFunc(OPTYPE_Plus), pExprLeft, pExprRight);
	} else if (pExprLeft->IsConstNumber(0)) {
		// 0 + m = m
		Expr::Delete(pExprLeft);
		return pExprRight;
	} else if (pExprRight->IsConstNumber(0)) {
		// n + 0 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsOperatorNeg()) {
		// n + (-m) = n - m
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprRight);
		return Func_Minus::OptimizedExpr(env, sig, pExprLeft, pExpr);
	} else if (pExprLeft->IsSymbol() && pExprRight->IsSymbol()) {
		// n + n = n * 2
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Func_Multiply::OptimizedExpr(env, sig, pExprLeft, new Expr_Value(2));
		}
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorMultiply()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n + n * m = n * (1 + m)
				Expr *pExprMultiplyR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Func_Multiply::OptimizedExpr(env, sig, pExprLeft,
					Func_Plus::OptimizedExpr(env, sig, new Expr_Value(1), pExprMultiplyR));
			}
		}
	} else if (pExprLeft->IsOperatorMultiply() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * m + n = n * (m + 1)
				Expr *pExprMultiplyL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Func_Multiply::OptimizedExpr(env, sig, pExprRight,
					Func_Plus::OptimizedExpr(env, sig, pExprMultiplyL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorMultiply() && pExprRight->IsOperatorMultiply()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol() && pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			const Expr_Symbol *pExprSymbolR =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * m + n * p = n * (m + p)
				Expr *pExprBase = Expr::Reference(pExprBinOpL->GetLeft());
				Expr *pExprMultiplyL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprMultiplyR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Multiply::OptimizedExpr(env, sig, pExprBase,
					Func_Plus::OptimizedExpr(env, sig, pExprMultiplyL, pExprMultiplyR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Plus), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// n - m
//-----------------------------------------------------------------------------
bool Func_Minus::IsMinus() const { return true; }

Func_Minus::Func_Minus(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__sub__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Minus, OPTYPE_Minus);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Expr *Func_Minus::DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const
{
	Expr *pExprDiff1 = pExprArg1->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	Expr *pExprDiff2 = pExprArg2->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) {
		Expr::Delete(pExprDiff1);
		return NULL;
	}
	// (f(x) - g(x))' = f'(x) - g'(x)
	return Func_Minus::OptimizedExpr(env, sig, pExprDiff1, pExprDiff2);
}

Expr *Func_Minus::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Func_Minus::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Func_Minus::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOpFunc(OPTYPE_Minus), pExprLeft, pExprRight);
	} else if (pExprLeft->IsConstNumber(0)) {
		// 0 - m = -m
		Expr::Delete(pExprLeft);
		return Func_Neg::OptimizedExpr(env, sig, pExprRight);
	} else if (pExprRight->IsConstNumber(0)) {
		// n - 0 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsOperatorNeg()) {
		// n - (-m) = n + m
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprRight);
		return Func_Plus::OptimizedExpr(env, sig, pExprLeft, pExpr);
	} else if (pExprLeft->IsSymbol() && pExprRight->IsSymbol()) {
		// n - n = 0
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
			Expr::Delete(pExprLeft);
			Expr::Delete(pExprRight);
			return new Expr_Value(0);
		}
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorMultiply()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n - n * m = n * (1 - m)
				Expr *pExprMultiplyR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Func_Multiply::OptimizedExpr(env, sig, pExprLeft,
					Func_Minus::OptimizedExpr(env, sig, new Expr_Value(1), pExprMultiplyR));
			}
		}
	} else if (pExprLeft->IsOperatorMultiply() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * m - n = n * (m - 1)
				Expr *pExprMultiplyL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Func_Multiply::OptimizedExpr(env, sig, pExprRight,
					Func_Minus::OptimizedExpr(env, sig, pExprMultiplyL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorMultiply() && pExprRight->IsOperatorMultiply()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol() && pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			const Expr_Symbol *pExprSymbolR =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * m - n * p = n * (m - p)
				Expr *pExprBase = Expr::Reference(pExprBinOpL->GetLeft());
				Expr *pExprMultiplyL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprMultiplyR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Multiply::OptimizedExpr(env, sig, pExprBase,
					Func_Minus::OptimizedExpr(env, sig, pExprMultiplyL, pExprMultiplyR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Minus), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// n * m
//-----------------------------------------------------------------------------
bool Func_Multiply::IsMultiply() const { return true; }

Func_Multiply::Func_Multiply(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__mul__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Multiply, OPTYPE_Multiply);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Multiply::EvalExpr(Environment &env, Signal sig, Args &args) const
{
	const ExprList &exprListArg = args.GetExprListArg();
	ValueList valListArg;
	Value valueWithDict;
	valueWithDict.InitAsDict(env, false);
	if (!_declOwner.PrepareArgs(env, sig, exprListArg, valListArg, valueWithDict)) {
		return Value::Null;
	}
	const Value &valueLeft = valListArg[0];
	const Value &valueRight = valListArg[1];
	Args argsSub(args, valListArg, valueWithDict, _resultMode, _flags);
	if (valueLeft.IsFunction()) {
		const Function *pFunc = valueLeft.GetFunction();
		if (pFunc->IsUnary()) {
			// nothing to do
		} else if (valueRight.IsList()) {
			const ValueList &valList = valueRight.GetList();
			if (valList.IsFlat()) {
				ValueList valListComp = valList;
				if (!pFunc->GetDeclOwner().Compensate(env, sig, valListComp)) {
					return Value::Null;
				}
				const Function *pFuncLeader = NULL;
				Args argsSub(valListComp, Value::Null, NULL, false, &pFuncLeader);
				return pFunc->Eval(env, sig, argsSub);
			}
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			AutoPtr<Iterator> pIteratorFuncBinder(new Iterator_FuncBinder(env,
						Function::Reference(pFunc),
						Object_function::GetObject(valueLeft)->GetThis(), pIterator.release()));
			return pIteratorFuncBinder->Eval(env, sig, argsSub);
		} else if (valueRight.IsIterator()) {
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			AutoPtr<Iterator> pIteratorFuncBinder(new Iterator_FuncBinder(env,
						Function::Reference(pFunc),
						Object_function::GetObject(valueLeft)->GetThis(), pIterator.release()));
			if (pFunc->IsRsltNormal() ||
						pFunc->IsRsltIterator() || pFunc->IsRsltXIterator()) {
				return Value(env, pIteratorFuncBinder.release());
			} else {
				return pIteratorFuncBinder->Eval(env, sig, argsSub);
			}
		}
	} else if (valueLeft.IsMatrix() && valueRight.IsList() ||
			   valueLeft.IsList() && valueRight.IsMatrix()) {
		return Eval(env, sig, argsSub);
	}
	if (_declOwner.ShouldImplicitMap(argsSub)) {
		return EvalMap(env, sig, argsSub);
	} else {
		return Eval(env, sig, argsSub);
	}
}

Expr *Func_Multiply::DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const
{
	Expr *pExprDiff1 = pExprArg1->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	Expr *pExprDiff2 = pExprArg2->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) {
		Expr::Delete(pExprDiff1);
		return NULL;
	}
	// (f(x)g(x))' = f'(x)g(x) + f(x)g'(x)
	return Func_Plus::OptimizedExpr(env, sig,
		Func_Multiply::OptimizedExpr(env, sig, pExprDiff1, Expr::Reference(pExprArg2)),
		Func_Multiply::OptimizedExpr(env, sig, Expr::Reference(pExprArg1), pExprDiff2));
}

Expr *Func_Multiply::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Func_Multiply::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Func_Multiply::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOpFunc(OPTYPE_Multiply), pExprLeft, pExprRight);
	} else if (pExprLeft->IsConstNumber(0)) {
		// n * 0 = 0
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsConstNumber(0)) {
		// 0 * m = 0
		Expr::Delete(pExprLeft);
		return pExprRight;
	} else if (pExprLeft->IsConstNumber(1)) {
		// 1 * m = m
		Expr::Delete(pExprLeft);
		return pExprRight;
	} else if (pExprRight->IsConstNumber(1)) {
		// n * 1 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprLeft->IsConstNumber(-1)) {
		// -1 * m = -m
		Expr::Delete(pExprLeft);
		return Func_Neg::OptimizedExpr(env, sig, pExprRight);
	} else if (pExprRight->IsConstNumber(-1)) {
		// n * (-1) = -n
		Expr::Delete(pExprRight);
		return Func_Neg::OptimizedExpr(env, sig, pExprLeft);
	} else if (pExprLeft->IsOperatorNeg() && pExprRight->IsOperatorNeg()) {
		// (-n) * (-m) = n * m
		Expr *pExpr1 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr *pExpr2 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Func_Multiply::OptimizedExpr(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsOperatorNeg()) {
		// (-n) * m = -(n * m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr::Delete(pExprLeft);
		return Func_Neg::OptimizedExpr(env, sig,
			Func_Multiply::OptimizedExpr(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsOperatorNeg()) {
		// n * (-m) = -(n * m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprRight);
		return Func_Neg::OptimizedExpr(env, sig,
			Func_Multiply::OptimizedExpr(env, sig, pExprLeft, pExpr));
	} else if (pExprLeft->IsSymbol() && pExprRight->IsSymbol()) {
		// n * n = n ** 2
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Func_Power::OptimizedExpr(env, sig, pExprLeft, new Expr_Value(2));
		}
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorPower()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * n ** m = n ** (m + 1)
				Expr *pExprPowerR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Func_Power::OptimizedExpr(env, sig, pExprLeft,
					Func_Plus::OptimizedExpr(env, sig, pExprPowerR, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorPower() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n ** m * n = n ** (m + 1)
				Expr *pExprPowerL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Func_Power::OptimizedExpr(env, sig, pExprRight,
					Func_Plus::OptimizedExpr(env, sig, pExprPowerL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorPower() && pExprRight->IsOperatorPower()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol() && pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			const Expr_Symbol *pExprSymbolR =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n ** m * n ** p = n ** (m + p)
				Expr *pExprBase = Expr::Reference(pExprBinOpL->GetLeft());
				Expr *pExprPowerL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprPowerR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Power::OptimizedExpr(env, sig, pExprBase,
					Func_Plus::OptimizedExpr(env, sig, pExprPowerL, pExprPowerR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Multiply), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// n / m
//-----------------------------------------------------------------------------
bool Func_Divide::IsDivide() const { return true; }

Func_Divide::Func_Divide(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__div__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Divide, OPTYPE_Divide);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Expr *Func_Divide::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Func_Divide::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Func_Divide::DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const
{
	Expr *pExprDiff1 = pExprArg1->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	Expr *pExprDiff2 = pExprArg2->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) {
		Expr::Delete(pExprDiff1);
		return NULL;
	}
	// (f(x) / g(x))' = (f'(x)g(x) - f(x)g'(x)) / {g(x)}^2
	return Func_Divide::OptimizedExpr(env, sig,
		Func_Minus::OptimizedExpr(env, sig,
			Func_Multiply::OptimizedExpr(env, sig, pExprDiff1, Expr::Reference(pExprArg2)),
			Func_Multiply::OptimizedExpr(env, sig, Expr::Reference(pExprArg1), pExprDiff2)),
		Func_Power::OptimizedExpr(env, sig, Expr::Reference(pExprArg2), new Expr_Value(2)));
}

Expr *Func_Divide::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsConstNumber(0)) {
		// 0 / m = 0
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsConstNumber(1)) {
		// n / 1 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsConstNumber(-1)) {
		// n / (-1) = -n
		Expr::Delete(pExprRight);
		return Func_Neg::OptimizedExpr(env, sig, pExprLeft);
	} else if (pExprLeft->IsOperatorNeg() && pExprRight->IsOperatorNeg()) {
		// (-n) / (-m) = n / m
		Expr *pExpr1 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr *pExpr2 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Func_Divide::OptimizedExpr(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsOperatorNeg()) {
		// (-n) / m = -(n / m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr::Delete(pExprLeft);
		return Func_Neg::OptimizedExpr(env, sig,
			Func_Divide::OptimizedExpr(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsOperatorNeg()) {
		// n / (-m) = -(n / m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprRight);
		return Func_Neg::OptimizedExpr(env, sig,
			Func_Divide::OptimizedExpr(env, sig, pExprLeft, pExpr));
	} else if (pExprLeft->IsSymbol() && pExprRight->IsSymbol()) {
		// n / n = 1
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
			Expr::Delete(pExprLeft);
			Expr::Delete(pExprRight);
			return new Expr_Value(1);
		}
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorPower()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n / n ** m = n ** (1 - m)
				Expr *pExprPowerR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Func_Power::OptimizedExpr(env, sig, pExprLeft,
					Func_Minus::OptimizedExpr(env, sig, new Expr_Value(1), pExprPowerR));
			}
		}
	} else if (pExprLeft->IsOperatorPower() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n ** m / n = n ** (m - 1)
				Expr *pExprPowerL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Func_Power::OptimizedExpr(env, sig, pExprRight,
					Func_Minus::OptimizedExpr(env, sig, pExprPowerL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorPower() && pExprRight->IsOperatorPower()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol() && pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			const Expr_Symbol *pExprSymbolR =
								dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n ** m / n ** p = n ** (m - p)
				Expr *pExprBase = Expr::Reference(pExprBinOpL->GetLeft());
				Expr *pExprPowerL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprPowerR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Power::OptimizedExpr(env, sig, pExprBase,
					Func_Minus::OptimizedExpr(env, sig, pExprPowerL, pExprPowerR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Divide), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// mod(n, m):map
//-----------------------------------------------------------------------------
bool Func_Modulo::IsModulo() const { return true; }

Func_Modulo::Func_Modulo(Environment &env) : FuncBinaryOperation(env, Symbol::Add("mod"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Modulo, OPTYPE_Modulo);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Modulo::EvalExpr(Environment &env, Signal sig, Args &args) const
{
	const ExprList &exprListArg = args.GetExprListArg();
	ValueList valListArg;
	Value valueWithDict;
	valueWithDict.InitAsDict(env, false);
	if (!_declOwner.PrepareArgs(env, sig, exprListArg, valListArg, valueWithDict)) {
		return Value::Null;
	}
	const Value &valueLeft = valListArg[0];
	const Value &valueRight = valListArg[1];
	if (valueLeft.IsFunction()) {
		const Function *pFunc = valueLeft.GetFunction();
		Value result;
		if (!valueRight.IsList()) {
			ValueList valListArg(valueRight);
			Args argsSub(valListArg);
			result = pFunc->Eval(env, sig, argsSub);
		} else if (pFunc->GetMapFlag() == MAP_Off ||
				!pFunc->GetDeclOwner().ShouldImplicitMap(valueRight.GetList())) {
			Args argsSub(valueRight.GetList());
			result = pFunc->Eval(env, sig, argsSub);
		} else if (pFunc->IsUnary()) {
			ValueList valListArg(valueRight);
			Args argsSub(valListArg);
			result = pFunc->EvalMap(env, sig, argsSub);
		} else {
			Args argsSub(valueRight.GetList());
			result = pFunc->EvalMap(env, sig, argsSub);
		}
		return result;
	} else if (valueLeft.IsString()) {
		const char *format = valueLeft.GetString();
		if (!valueRight.IsList()) {
			String str = Formatter::Format(sig, format, ValueList(valueRight));
			if (sig.IsSignalled()) return Value::Null;
			return Value(env, str.c_str());
		} else {
			const ValueList &valList = valueRight.GetList();
			if (valList.IsFlat() && !valList.IsContainIterator()) {
				String str = Formatter::Format(sig, format, valList);
				if (sig.IsSignalled()) return Value::Null;
				return Value(env, str.c_str());
			} else {
				IteratorOwner iterOwner;
				foreach_const (ValueList, pValue, valList) {
					AutoPtr<Iterator> pIterator;
					if (pValue->IsList() || pValue->IsIterator()) {
						pIterator.reset(pValue->CreateIterator(sig));
						if (pIterator.IsNull()) return Value::Null;
					} else {
						pIterator.reset(new Iterator_Constant(*pValue));
					}
					iterOwner.push_back(pIterator.release());
				}
				return Formatter::Format(env, sig, format, iterOwner);
			}
		}
	}
	Args argsSub(args, valListArg, valueWithDict, _resultMode, _flags);
	if (_declOwner.ShouldImplicitMap(valListArg)) {
		return EvalMap(env, sig, argsSub);
	} else {
		return Eval(env, sig, argsSub);
	}
}

//-----------------------------------------------------------------------------
// n ** m
//-----------------------------------------------------------------------------
bool Func_Power::IsPower() const { return true; }

Func_Power::Func_Power(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__pow__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Power, OPTYPE_Power);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Expr *Func_Power::DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const
{
	Expr *pExprDiff1 = pExprArg1->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	Expr *pExprDiff2 = pExprArg2->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) {
		Expr::Delete(pExprDiff1);
		return NULL;
	}
	// (f(x) ** g(x))' = f'(x)g(x)(f(x) ** (g(x) - 1)) + g'(x)log(f(x))(f(x) ** g(x))
	return Func_Plus::OptimizedExpr(env, sig,
		Func_Multiply::OptimizedExpr(env, sig,
			Func_Multiply::OptimizedExpr(env, sig, pExprDiff1, Expr::Reference(pExprArg2)),
			Func_Power::OptimizedExpr(env, sig,
				Expr::Reference(pExprArg1),
				Func_Minus::OptimizedExpr(env, sig, Expr::Reference(pExprArg2), new Expr_Value(1)))),
		Func_Multiply::OptimizedExpr(env, sig,
			Func_Multiply::OptimizedExpr(env, sig,
				pExprDiff2,
				Gura_Module(math)::CreateFuncExpr("log", Expr::Reference(pExprArg1))),
			Func_Power::OptimizedExpr(env, sig, Expr::Reference(pExprArg1), Expr::Reference(pExprArg2))));
}

Expr *Func_Power::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Func_Power::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Func_Power::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOpFunc(OPTYPE_Power), pExprLeft, pExprRight);
	} else if (pExprLeft->IsConstNumber(0)) {
		// 0 ** m = 0
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprLeft->IsConstNumber(1)) {
		// 1 ** m = 1
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsConstNumber(0)) {
		// n ** 0 = 1
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return new Expr_Value(1);
	} else if (pExprRight->IsConstNumber(1)) {
		// n ** 1 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsConstNumber(-1)) {
		// n ** (-1) = 1 / n
		Expr::Delete(pExprRight);
		return Func_Divide::OptimizedExpr(env, sig, new Expr_Value(1), pExprLeft);
	} else if (pExprLeft->IsOperatorNeg() && pExprRight->IsConstEvenNumber()) {
		// (-n) ** (2m) = n ** (2m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr::Delete(pExprLeft);
		return Func_Power::OptimizedExpr(env, sig, pExpr, pExprRight);
	//} else if (pExprRight->IsConstNumber(0.5)) {
	//	// n ** 0.5 = math.sqrt(n)
	//	Expr::Delete(pExprRight);
	//	return Gura_Module(math)::CreateFuncExpr("sqrt", pExprLeft);
	}
	return new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Power), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// n == m
//-----------------------------------------------------------------------------
Func_Equal::Func_Equal(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__eq__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Equal, OPTYPE_Equal);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n != m
//-----------------------------------------------------------------------------
Func_NotEqual::Func_NotEqual(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__ne__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_NotEqual, OPTYPE_NotEqual);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n > m
//-----------------------------------------------------------------------------
Func_Greater::Func_Greater(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__gt__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Greater, OPTYPE_Greater);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n < m
//-----------------------------------------------------------------------------
Func_Less::Func_Less(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__lt__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Less, OPTYPE_Less);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n >= m
//-----------------------------------------------------------------------------
Func_GreaterEq::Func_GreaterEq(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__ge__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_GreaterEq, OPTYPE_GreaterEq);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n <= m
//-----------------------------------------------------------------------------
Func_LessEq::Func_LessEq(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__le__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_LessEq, OPTYPE_LessEq);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n <=> m
//-----------------------------------------------------------------------------
Func_Compare::Func_Compare(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__cmp__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Compare, OPTYPE_Compare);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n in m
//-----------------------------------------------------------------------------
bool Func_ContainCheck::IsContainCheck() const { return true; }

Func_ContainCheck::Func_ContainCheck(Environment &env) : FuncBinaryOperation(env, Symbol::Add("in"))
{
	SetOperatorInfo(Parser::ETYPE_ContainCheck, OPTYPE_ContainCheck);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n | m
//-----------------------------------------------------------------------------
Func_Or::Func_Or(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__or__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Or, OPTYPE_Or);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n & m
//-----------------------------------------------------------------------------
Func_And::Func_And(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__and__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_And, OPTYPE_And);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n ^ m
//-----------------------------------------------------------------------------
Func_Xor::Func_Xor(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__xor__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Xor, OPTYPE_Xor);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n << m
//-----------------------------------------------------------------------------
Func_ShiftL::Func_ShiftL(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__shl__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_ShiftL, OPTYPE_ShiftL);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n >> m
//-----------------------------------------------------------------------------
Func_ShiftR::Func_ShiftR(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__shr__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_ShiftR, OPTYPE_ShiftR);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n || m
// this function takes quoted values as its arguments to implement
// a short-circuit evaluation.
//-----------------------------------------------------------------------------
Func_OrOr::Func_OrOr(Environment &env) :
			Function(env, Symbol::Add("__oror__"), FUNCTYPE_Function, FLAG_None)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_OrOr, OPTYPE_OrOr);
	DeclareArg(env, "n", VTYPE_quote);
	DeclareArg(env, "m", VTYPE_quote);
}

Value Func_OrOr::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	result = args.GetExpr(0)->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	if (result.GetBoolean()) return result;
	result = args.GetExpr(1)->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

//-----------------------------------------------------------------------------
// n && m
// this function takes quoted values as its arguments to implement
// a short-circuit evaluation.
//-----------------------------------------------------------------------------
Func_AndAnd::Func_AndAnd(Environment &env) :
			Function(env, Symbol::Add("__andand__"), FUNCTYPE_Function, FLAG_None)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_AndAnd, OPTYPE_AndAnd);
	DeclareArg(env, "n", VTYPE_quote);
	DeclareArg(env, "m", VTYPE_quote);
}

Value Func_AndAnd::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	result = args.GetExpr(0)->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	if (!result.GetBoolean()) return result;
	result = args.GetExpr(1)->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

//-----------------------------------------------------------------------------
// n .. m
//-----------------------------------------------------------------------------
bool Func_Sequence::IsSequence() const { return true; }

Func_Sequence::Func_Sequence(Environment &env) : FuncBinaryOperation(env, Symbol::Add("__seq__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Sequence, OPTYPE_Sequence);
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

//-----------------------------------------------------------------------------
// n ..
//-----------------------------------------------------------------------------
Func_SequenceInf::Func_SequenceInf(Environment &env) : FuncUnaryOperation(env, Symbol::Add("__seqinf__"))
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Sequence, OPTYPE_SequenceInf);
	DeclareArg(env, "n", VTYPE_any);
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Expr *OptimizeConst(Environment &env, Signal sig,
									const Function *pFunc, Expr *pExprChild)
{
	ValueList valListArg(dynamic_cast<Expr_Value *>(pExprChild)->GetValue());
	Expr::Delete(pExprChild);
	Args args(valListArg);
	Value value = pFunc->Eval(env, sig, args);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(value);
}

Expr *OptimizeConst(Environment &env, Signal sig,
					const Function *pFunc, Expr *pExprLeft, Expr *pExprRight)
{
	ValueList valListArg(
		dynamic_cast<Expr_Value *>(pExprLeft)->GetValue(),
		dynamic_cast<Expr_Value *>(pExprRight)->GetValue());
	Expr::Delete(pExprLeft);
	Expr::Delete(pExprRight);
	Args args(valListArg);
	Value value = pFunc->Eval(env, sig, args);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(value);
}

}
