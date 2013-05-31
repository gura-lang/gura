#include "stdafx.h"

namespace Gura {

static void SetError_DivideByZero(Signal sig);
static void SetError_MathDiffError(Signal sig);
static void SetError_MathOptimizeError(Signal sig);
static Expr *OptimizeConst(Environment &env, Signal sig,
						const Operator *pOperator, Expr *pExprChild);
static Expr *OptimizeConst(Environment &env, Signal sig,
						const Operator *pOperator, Expr *pExprLeft, Expr *pExprRight);

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
const char *Operator::_mathSymbolTbl[] = {
	"",		// OPTYPE_None
	// unary operators
	"+",	// OPTYPE_Pos
	"-",	// OPTYPE_Neg
	"~",	// OPTYPE_Inv
	"!",	// OPTYPE_Not
	"..",	// OPTYPE_SeqInf
	// binary operators
	"+",	// OPTYPE_Add
	"-",	// OPTYPE_Sub
	"*",	// OPTYPE_Mul
	"/",	// OPTYPE_Div
	"%",	// OPTYPE_Mod
	"**",	// OPTYPE_Pow
	"==",	// OPTYPE_Eq
	"!=",	// OPTYPE_Ne
	">",	// OPTYPE_Gt
	"<",	// OPTYPE_Lt
	">=",	// OPTYPE_Ge
	"<=",	// OPTYPE_Le
	"<=>",	// OPTYPE_Cmp
	"in",	// OPTYPE_Contains
	"|",	// OPTYPE_Or
	"&",	// OPTYPE_And
	"^",	// OPTYPE_Xor
	"<<",	// OPTYPE_Shl
	">>",	// OPTYPE_Shr
	"||",	// OPTYPE_OrOr
	"&&",	// OPTYPE_AndAnd
	"..",	// OPTYPE_Seq
};

void Operator::Assign(Environment &env, OperatorEntry *pOperatorEntry)
{
	Operator *pOperator = env.GetOperator(pOperatorEntry->GetOpType());
	Map &map = pOperator->GetMap();
	Key key = pOperatorEntry->CalcKey();
	Map::iterator iter = map.find(key);
	if (iter == map.end()) {
		map[key] = pOperatorEntry;
	} else {
		delete iter->second;
		iter->second = pOperatorEntry;
	}
}

const OperatorEntry *Operator::Lookup(ValueType valType) const
{
	Map::const_iterator iter = _map.find(CalcKey(valType));
	if (iter != _map.end()) return iter->second;
	iter = _map.find(CalcKey(VTYPE_any));
	if (iter != _map.end()) return iter->second;
	return NULL;
}

const OperatorEntry *Operator::Lookup(ValueType valTypeLeft, ValueType valTypeRight) const
{
	Map::const_iterator iter = _map.find(CalcKey(valTypeLeft, valTypeRight));
	if (iter != _map.end()) return iter->second;
	iter = _map.find(CalcKey(valTypeLeft, VTYPE_any));
	if (iter != _map.end()) return iter->second;
	iter = _map.find(CalcKey(VTYPE_any, valTypeRight));
	if (iter != _map.end()) return iter->second;
	iter = _map.find(CalcKey(VTYPE_any, VTYPE_any));
	if (iter != _map.end()) return iter->second;
	return NULL;
}

Expr *Operator::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

Expr *Operator::DiffBinary(Environment &env, Signal sig,
		const Expr *pExprArg1, const Expr *pExprArg2, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

Expr *Operator::OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const
{
	SetError_MathOptimizeError(sig);
	return NULL;
}

Expr *Operator::OptimizeBinary(Environment &env, Signal sig,
										Expr *pExprOpt1, Expr *pExprOpt2) const
{
	SetError_MathOptimizeError(sig);
	return NULL;
}

Value Operator::EvalUnary(Environment &env, Signal sig, const Value &value) const
{
	const OperatorEntry *pOperatorEntry = Lookup(value.GetValueType());
	if (pOperatorEntry == NULL) {
		SetError_InvalidValueType(sig, GetOpType(), value);
		return Value::Null;
	}
	return pOperatorEntry->DoEval(env, sig, value);
}

Value Operator::EvalBinary(Environment &env, Signal sig, const Value &valueLeft, const Value &valueRight) const
{
	const OperatorEntry *pOperatorEntry =
					Lookup(valueLeft.GetValueType(), valueRight.GetValueType());
	if (pOperatorEntry == NULL) {
		SetError_InvalidValueType(sig, GetOpType(), valueLeft, valueRight);
		return Value::Null;
	}
	return pOperatorEntry->DoEval(env, sig, valueLeft, valueRight);
}

Value Operator::EvalMapUnary(Environment &env, Signal sig, const Value &value) const
{
	if (!value.IsListOrIterator()) {
		return EvalUnary(env, sig, value);
	}
	AutoPtr<Iterator> pIterator(new Iterator_UnaryOperatorMap(
												env, sig, this, value));
	if (value.IsIterator()) {
		return Value(env, pIterator.release());
	}
	return pIterator->ToList(env, sig, true, false);
}

Value Operator::EvalMapBinary(Environment &env, Signal sig,
							const Value &valueLeft, const Value &valueRight) const
{
	if (!valueLeft.IsListOrIterator() && !valueRight.IsListOrIterator()) {
		return EvalBinary(env, sig, valueLeft, valueRight);
	}
	AutoPtr<Iterator> pIterator(new Iterator_BinaryOperatorMap(env, sig,
									this, valueLeft, valueRight));
	if (valueLeft.IsIterator() || valueRight.IsIterator()) {
		return Value(env, pIterator.release());
	}
	return pIterator->ToList(env, sig, true, false);
}

OpType Operator::LookupUnaryOpType(const char *str)
{
	for (size_t i = OPTYPE_unary; i < OPTYPE_binary; i++) {
		if (::strcmp(_mathSymbolTbl[i], str) == 0) return static_cast<OpType>(i);
	}
	return OPTYPE_None;
}

OpType Operator::LookupBinaryOpType(const char *str)
{
	for (size_t i = OPTYPE_binary; i < OPTYPE_max; i++) {
		if (::strcmp(_mathSymbolTbl[i], str) == 0) return static_cast<OpType>(i);
	}
	return OPTYPE_None;
}

void Operator::SetError_InvalidValueType(Signal &sig, OpType opType, const Value &value)
{
	sig.SetError(ERR_TypeError, "can't evaluate (%s %s)",
					GetMathSymbol(opType), value.MakeValueTypeName().c_str());
}

void Operator::SetError_InvalidValueType(Signal &sig, OpType opType,
						const Value &valueLeft, const Value &valueRight)
{
	sig.SetError(ERR_TypeError, "can't evaluate (%s %s %s)",
		valueLeft.MakeValueTypeName().c_str(), GetMathSymbol(opType), valueRight.MakeValueTypeName().c_str());
}

//-----------------------------------------------------------------------------
// Operator_Pos
//-----------------------------------------------------------------------------
Expr *Operator_Pos::OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return NULL;
	}
	return pExprChild;
}

Expr *Operator_Pos::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	Expr *pExprDiff = pExprArg->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	return Operator_Pos::OptimizedExpr(env, sig, pExprDiff);
}

Expr *Operator_Pos::OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const
{
	return Operator_Pos::OptimizedExpr(env, sig, pExprOpt);
}

//-----------------------------------------------------------------------------
// Operator_Neg
//-----------------------------------------------------------------------------
Expr *Operator_Neg::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	Expr *pExprWork = pExprArg->MathDiff(env, sig, pSymbol);
	if (sig.IsSignalled()) return NULL;
	return Operator_Neg::OptimizedExpr(env, sig, pExprWork);
}

Expr *Operator_Neg::OptimizeUnary(Environment &env, Signal sig, Expr *pExprOpt) const
{
	return Operator_Neg::OptimizedExpr(env, sig, pExprOpt);
}

Expr *Operator_Neg::OptimizedExpr(Environment &env, Signal sig, Expr *pExprChild)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return NULL;
	}
	if (pExprChild->IsValue()) {
		return OptimizeConst(env, sig, env.GetOperator(OPTYPE_Neg), pExprChild);
	} else if (pExprChild->IsOperatorNeg()) {
		// -(-n) = n
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprChild)->GetChild());
		Expr::Delete(pExprChild);
		return pExpr;
	} else {
		return new Expr_UnaryOp(env.GetOperator(OPTYPE_Neg), pExprChild, false);
	}
}

//-----------------------------------------------------------------------------
// Operator_Inv
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Not
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_SeqInf
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Add
//-----------------------------------------------------------------------------
Expr *Operator_Add::DiffBinary(Environment &env, Signal sig,
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
	return Operator_Add::OptimizedExpr(env, sig, pExprDiff1, pExprDiff2);
}

Expr *Operator_Add::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Operator_Add::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Operator_Add::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOperator(OPTYPE_Add), pExprLeft, pExprRight);
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
		return Operator_Sub::OptimizedExpr(env, sig, pExprLeft, pExpr);
	} else if (pExprLeft->IsSymbol() && pExprRight->IsSymbol()) {
		// n + n = n * 2
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Operator_Mul::OptimizedExpr(env, sig, pExprLeft, new Expr_Value(2));
		}
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorMul()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n + n * m = n * (1 + m)
				Expr *pExprMulR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Operator_Mul::OptimizedExpr(env, sig, pExprLeft,
					Operator_Add::OptimizedExpr(env, sig, new Expr_Value(1), pExprMulR));
			}
		}
	} else if (pExprLeft->IsOperatorMul() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * m + n = n * (m + 1)
				Expr *pExprMulL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Operator_Mul::OptimizedExpr(env, sig, pExprRight,
					Operator_Add::OptimizedExpr(env, sig, pExprMulL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorMul() && pExprRight->IsOperatorMul()) {
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
				Expr *pExprMulL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprMulR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Mul::OptimizedExpr(env, sig, pExprBase,
					Operator_Add::OptimizedExpr(env, sig, pExprMulL, pExprMulR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Sub
//-----------------------------------------------------------------------------
Expr *Operator_Sub::DiffBinary(Environment &env, Signal sig,
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
	return Operator_Sub::OptimizedExpr(env, sig, pExprDiff1, pExprDiff2);
}

Expr *Operator_Sub::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Operator_Sub::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Operator_Sub::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOperator(OPTYPE_Sub), pExprLeft, pExprRight);
	} else if (pExprLeft->IsConstNumber(0)) {
		// 0 - m = -m
		Expr::Delete(pExprLeft);
		return Operator_Neg::OptimizedExpr(env, sig, pExprRight);
	} else if (pExprRight->IsConstNumber(0)) {
		// n - 0 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsOperatorNeg()) {
		// n - (-m) = n + m
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprRight);
		return Operator_Add::OptimizedExpr(env, sig, pExprLeft, pExpr);
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
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorMul()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n - n * m = n * (1 - m)
				Expr *pExprMulR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Operator_Mul::OptimizedExpr(env, sig, pExprLeft,
					Operator_Sub::OptimizedExpr(env, sig, new Expr_Value(1), pExprMulR));
			}
		}
	} else if (pExprLeft->IsOperatorMul() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * m - n = n * (m - 1)
				Expr *pExprMulL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Operator_Mul::OptimizedExpr(env, sig, pExprRight,
					Operator_Sub::OptimizedExpr(env, sig, pExprMulL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorMul() && pExprRight->IsOperatorMul()) {
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
				Expr *pExprMulL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprMulR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Mul::OptimizedExpr(env, sig, pExprBase,
					Operator_Sub::OptimizedExpr(env, sig, pExprMulL, pExprMulR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Sub), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Mul
//-----------------------------------------------------------------------------
Value Operator_Mul::EvalMapBinary(Environment &env, Signal sig,
							const Value &valueLeft, const Value &valueRight) const
{
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
			ValueList valListArg(valueLeft, valueRight);
			Args argsSub(valListArg);
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
				ValueList valListArg(valueLeft, valueRight);
				Args argsSub(valListArg);
				return pIteratorFuncBinder->Eval(env, sig, argsSub);
			}
		}
	} else if (valueLeft.IsMatrix() && valueRight.IsList() ||
			   valueLeft.IsList() && valueRight.IsMatrix()) {
		return EvalBinary(env, sig, valueLeft, valueRight);
	}
	return Operator::EvalMapBinary(env, sig, valueLeft, valueRight);
}

Expr *Operator_Mul::DiffBinary(Environment &env, Signal sig,
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
	return Operator_Add::OptimizedExpr(env, sig,
		Operator_Mul::OptimizedExpr(env, sig, pExprDiff1, Expr::Reference(pExprArg2)),
		Operator_Mul::OptimizedExpr(env, sig, Expr::Reference(pExprArg1), pExprDiff2));
}

Expr *Operator_Mul::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Operator_Mul::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Operator_Mul::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOperator(OPTYPE_Mul), pExprLeft, pExprRight);
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
		return Operator_Neg::OptimizedExpr(env, sig, pExprRight);
	} else if (pExprRight->IsConstNumber(-1)) {
		// n * (-1) = -n
		Expr::Delete(pExprRight);
		return Operator_Neg::OptimizedExpr(env, sig, pExprLeft);
	} else if (pExprLeft->IsOperatorNeg() && pExprRight->IsOperatorNeg()) {
		// (-n) * (-m) = n * m
		Expr *pExpr1 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr *pExpr2 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Operator_Mul::OptimizedExpr(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsOperatorNeg()) {
		// (-n) * m = -(n * m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr::Delete(pExprLeft);
		return Operator_Neg::OptimizedExpr(env, sig,
			Operator_Mul::OptimizedExpr(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsOperatorNeg()) {
		// n * (-m) = -(n * m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprRight);
		return Operator_Neg::OptimizedExpr(env, sig,
			Operator_Mul::OptimizedExpr(env, sig, pExprLeft, pExpr));
	} else if (pExprLeft->IsSymbol() && pExprRight->IsSymbol()) {
		// n * n = n ** 2
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Operator_Pow::OptimizedExpr(env, sig, pExprLeft, new Expr_Value(2));
		}
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorPow()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n * n ** m = n ** (m + 1)
				Expr *pExprPowR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Operator_Pow::OptimizedExpr(env, sig, pExprLeft,
					Operator_Add::OptimizedExpr(env, sig, pExprPowR, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorPow() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n ** m * n = n ** (m + 1)
				Expr *pExprPowL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Operator_Pow::OptimizedExpr(env, sig, pExprRight,
					Operator_Add::OptimizedExpr(env, sig, pExprPowL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorPow() && pExprRight->IsOperatorPow()) {
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
				Expr *pExprPowL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprPowR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Pow::OptimizedExpr(env, sig, pExprBase,
					Operator_Add::OptimizedExpr(env, sig, pExprPowL, pExprPowR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Div
//-----------------------------------------------------------------------------
Expr *Operator_Div::DiffBinary(Environment &env, Signal sig,
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
	return Operator_Div::OptimizedExpr(env, sig,
		Operator_Sub::OptimizedExpr(env, sig,
			Operator_Mul::OptimizedExpr(env, sig, pExprDiff1, Expr::Reference(pExprArg2)),
			Operator_Mul::OptimizedExpr(env, sig, Expr::Reference(pExprArg1), pExprDiff2)),
		Operator_Pow::OptimizedExpr(env, sig, Expr::Reference(pExprArg2), new Expr_Value(2)));
}

Expr *Operator_Div::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Operator_Div::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Operator_Div::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
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
		return Operator_Neg::OptimizedExpr(env, sig, pExprLeft);
	} else if (pExprLeft->IsOperatorNeg() && pExprRight->IsOperatorNeg()) {
		// (-n) / (-m) = n / m
		Expr *pExpr1 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr *pExpr2 =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Operator_Div::OptimizedExpr(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsOperatorNeg()) {
		// (-n) / m = -(n / m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr::Delete(pExprLeft);
		return Operator_Neg::OptimizedExpr(env, sig,
			Operator_Div::OptimizedExpr(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsOperatorNeg()) {
		// n / (-m) = -(n / m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild());
		Expr::Delete(pExprRight);
		return Operator_Neg::OptimizedExpr(env, sig,
			Operator_Div::OptimizedExpr(env, sig, pExprLeft, pExpr));
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
	} else if (pExprLeft->IsSymbol() && pExprRight->IsOperatorPow()) {
		const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpR->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n / n ** m = n ** (1 - m)
				Expr *pExprPowR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprRight);
				return Operator_Pow::OptimizedExpr(env, sig, pExprLeft,
					Operator_Sub::OptimizedExpr(env, sig, new Expr_Value(1), pExprPowR));
			}
		}
	} else if (pExprLeft->IsOperatorPow() && pExprRight->IsSymbol()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Symbol *pExprSymbolR =
							dynamic_cast<const Expr_Symbol *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsSymbol()) {
			const Expr_Symbol *pExprSymbolL =
							dynamic_cast<const Expr_Symbol *>(pExprBinOpL->GetLeft());
			if (pExprSymbolL->GetSymbol()->IsIdentical(pExprSymbolR->GetSymbol())) {
				// n ** m / n = n ** (m - 1)
				Expr *pExprPowL = Expr::Reference(pExprBinOpL->GetRight());
				Expr::Delete(pExprLeft);
				return Operator_Pow::OptimizedExpr(env, sig, pExprRight,
					Operator_Sub::OptimizedExpr(env, sig, pExprPowL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsOperatorPow() && pExprRight->IsOperatorPow()) {
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
				Expr *pExprPowL = Expr::Reference(pExprBinOpL->GetRight());
				Expr *pExprPowR = Expr::Reference(pExprBinOpR->GetRight());
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Pow::OptimizedExpr(env, sig, pExprBase,
					Operator_Sub::OptimizedExpr(env, sig, pExprPowL, pExprPowR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Mod
//-----------------------------------------------------------------------------
Value Operator_Mod::EvalMapBinary(Environment &env, Signal sig,
							const Value &valueLeft, const Value &valueRight) const
{
	if (valueLeft.IsFunction()) {
		const Function *pFunc = valueLeft.GetFunction();
		Value result;
		if (!valueRight.IsList()) {
			ValueList valListArg(valueRight);
			Args argsSub(valListArg);
			result = pFunc->Eval(env, sig, argsSub);
		} else if (pFunc->GetMapFlag() == Function::MAP_Off ||
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
	return Operator::EvalMapBinary(env, sig, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// Operator_Pow
//-----------------------------------------------------------------------------
Expr *Operator_Pow::DiffBinary(Environment &env, Signal sig,
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
	return Operator_Add::OptimizedExpr(env, sig,
		Operator_Mul::OptimizedExpr(env, sig,
			Operator_Mul::OptimizedExpr(env, sig, pExprDiff1, Expr::Reference(pExprArg2)),
			Operator_Pow::OptimizedExpr(env, sig,
				Expr::Reference(pExprArg1),
				Operator_Sub::OptimizedExpr(env, sig, Expr::Reference(pExprArg2), new Expr_Value(1)))),
		Operator_Mul::OptimizedExpr(env, sig,
			Operator_Mul::OptimizedExpr(env, sig,
				pExprDiff2,
				Gura_Module(math)::CreateFuncExpr("log", Expr::Reference(pExprArg1))),
			Operator_Pow::OptimizedExpr(env, sig, Expr::Reference(pExprArg1), Expr::Reference(pExprArg2))));
}

Expr *Operator_Pow::OptimizeBinary(Environment &env, Signal sig,
									Expr *pExprOpt1, Expr *pExprOpt2) const
{
	return Operator_Pow::OptimizedExpr(env, sig, pExprOpt1, pExprOpt2);
}

Expr *Operator_Pow::OptimizedExpr(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		return OptimizeConst(env, sig, env.GetOperator(OPTYPE_Pow), pExprLeft, pExprRight);
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
		return Operator_Div::OptimizedExpr(env, sig, new Expr_Value(1), pExprLeft);
	} else if (pExprLeft->IsOperatorNeg() && pExprRight->IsConstEvenNumber()) {
		// (-n) ** (2m) = n ** (2m)
		Expr *pExpr =
			Expr::Reference(dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild());
		Expr::Delete(pExprLeft);
		return Operator_Pow::OptimizedExpr(env, sig, pExpr, pExprRight);
	//} else if (pExprRight->IsConstNumber(0.5)) {
	//	// n ** 0.5 = math.sqrt(n)
	//	Expr::Delete(pExprRight);
	//	return Gura_Module(math)::CreateFuncExpr("sqrt", pExprLeft);
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Eq
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Ne
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Gt
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Lt
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Ge
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Le
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Cmp
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Contains
//-----------------------------------------------------------------------------
Value Operator_Contains::EvalMapBinary(Environment &env, Signal sig,
							const Value &valueLeft, const Value &valueRight) const
{
	return EvalBinary(env, sig, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// Operator_Or
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_And
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Xor
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Shl
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Shr
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_OrOr
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_AndAnd
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Seq
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// OperatorEntry
//-----------------------------------------------------------------------------
Value OperatorEntry::DoEval(Environment &env, Signal sig, const Value &value) const
{
	return Value::Null;
}

Value OperatorEntry::DoEval(Environment &env, Signal sig,
				const Value &valueLeft, const Value &valueRight) const
{
	return Value::Null;
}

void OperatorEntry::SetError_InvalidValueType(Signal &sig, const Value &value) const
{
	Operator::SetError_InvalidValueType(sig, GetOpType(), value);
}

void OperatorEntry::SetError_InvalidValueType(Signal &sig,
						const Value &valueLeft, const Value &valueRight) const
{
	Operator::SetError_InvalidValueType(sig, GetOpType(), valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// UnaryOperator(Pos, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Pos, number)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, complex)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, matrix)
{
	return value;
}

Gura_ImplementUnaryOperator(Pos, timedelta)
{
	return value;
}

//-----------------------------------------------------------------------------
// UnaryOperator(Neg, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Neg, number)
{
	return Value(-value.GetNumber());
}

Gura_ImplementUnaryOperator(Neg, complex)
{
	return Value(-value.GetComplex());
}

Gura_ImplementUnaryOperator(Neg, matrix)
{
	return Matrix::Neg(env, sig, Object_matrix::GetObject(value)->GetMatrix());
}

Gura_ImplementUnaryOperator(Neg, timedelta)
{
	TimeDelta td = value.GetTimeDelta();
	return Value(env, TimeDelta(-td.GetDays(), -td.GetSecsRaw(), -td.GetUSecs()));
}

//-----------------------------------------------------------------------------
// UnaryOperator(Invert, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Inv, number)
{
	unsigned long num = ~static_cast<unsigned long>(value.GetNumber());
	return Value(static_cast<Number>(num));
}

//-----------------------------------------------------------------------------
// UnaryOperator(Not, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Not, any)
{
	bool rtn = !value.GetBoolean();
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// UnaryOperator(SequenceInf, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(SeqInf, number)
{
	Number numBegin = value.GetNumber();
	return Value(env, new Iterator_SequenceInf(numBegin));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Add, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Add, number, number)
{
	return Value(valueLeft.GetNumber() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Add, complex, complex)
{
	return Value(valueLeft.GetComplex() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Add, number, complex)
{
	return Value(valueLeft.GetNumber() + valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Add, complex, number)
{
	return Value(valueLeft.GetComplex() + valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Add, matrix, matrix)
{
	return Matrix::AddSub(env, sig, OPTYPE_Add,
		Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Add, datetime, timedelta)
{
	DateTime dateTime = valueLeft.GetDateTime();
	dateTime.Plus(valueRight.GetTimeDelta());
	return Value(env, dateTime);
}

Gura_ImplementBinaryOperator(Add, timedelta, datetime)
{
	DateTime dateTime = valueRight.GetDateTime();
	dateTime.Plus(valueLeft.GetTimeDelta());
	return Value(env, dateTime);
}

Gura_ImplementBinaryOperator(Add, timedelta, timedelta)
{
	TimeDelta td1 = valueLeft.GetTimeDelta();
	TimeDelta td2 = valueRight.GetTimeDelta();
	return Value(env, TimeDelta(
			td1.GetDays() + td2.GetDays(),
			td1.GetSecsRaw() + td2.GetSecsRaw(),
			td1.GetUSecs() + td2.GetUSecs()));
}

Gura_ImplementBinaryOperator(Add, string, string)
{
	String str(valueLeft.GetString());
	str += valueRight.GetString();
	return Value(env, str.c_str());
}

Gura_ImplementBinaryOperator(Add, binary, binary)
{
	Binary buff(valueLeft.GetBinary());
	buff += valueRight.GetBinary();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Add, binary, string)
{
	Binary buff(valueLeft.GetBinary());
	buff += valueRight.GetString();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Add, string, binary)
{
	Binary buff;
	buff += valueLeft.GetString();
	buff += valueRight.GetBinary();
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Add, pointer, number)
{
	Object_pointer *pObj = dynamic_cast<Object_pointer *>(
						Object_pointer::GetObject(valueLeft)->Clone());
	pObj->UnpackForward(sig,
						static_cast<int>(valueRight.GetNumber()), true);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

Gura_ImplementBinaryOperator(Add, string, any)
{
	String str(valueLeft.GetString());
	str += valueRight.ToString(sig);
	return Value(env, str.c_str());
}

Gura_ImplementBinaryOperator(Add, any, string)
{
	String str(valueLeft.ToString(sig));
	str += valueRight.GetString();
	return Value(env, str.c_str());
}

//-----------------------------------------------------------------------------
// BinaryOperator(Sub, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Sub, number, number)
{
	return Value(valueLeft.GetNumber() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Sub, complex, complex)
{
	return Value(valueLeft.GetComplex() - valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Sub, number, complex)
{
	return Value(valueLeft.GetNumber() - valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Sub, complex, number)
{
	return Value(valueLeft.GetComplex() - valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Sub, matrix, matrix)
{
	return Matrix::AddSub(env, sig, OPTYPE_Sub,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Sub, datetime, timedelta)
{
	DateTime dateTime = valueLeft.GetDateTime();
	dateTime.Minus(valueRight.GetTimeDelta());
	return Value(env, dateTime);
}

Gura_ImplementBinaryOperator(Sub, datetime, datetime)
{
	const DateTime &dt1 = valueLeft.GetDateTime();
	const DateTime &dt2 = valueRight.GetDateTime();
	if ((dt1.HasTZOffset() && !dt2.HasTZOffset()) ||
								(!dt1.HasTZOffset() && dt2.HasTZOffset())) {
		sig.SetError(ERR_ValueError, "failed to calculate datetime difference");
		return Value::Null;
	}
	return Value(env, dt1.Minus(dt2));
}

Gura_ImplementBinaryOperator(Sub, timedelta, timedelta)
{
	TimeDelta td1 = valueLeft.GetTimeDelta();
	TimeDelta td2 = valueRight.GetTimeDelta();
	return Value(env, TimeDelta(
			td1.GetDays() - td2.GetDays(),
			td1.GetSecsRaw() - td2.GetSecsRaw(),
			td1.GetUSecs() - td2.GetUSecs()));
}

Gura_ImplementBinaryOperator(Sub, color, color)
{
	const Color &color1 = Object_color::GetObject(valueLeft)->GetColor();
	const Color &color2 = Object_color::GetObject(valueRight)->GetColor();
	return Value(::sqrt(static_cast<double>(color1.CalcDist(color2))));
}

Gura_ImplementBinaryOperator(Sub, pointer, number)
{
	AutoPtr<Object_pointer> pObj(dynamic_cast<Object_pointer *>(
						Object_pointer::GetObject(valueLeft)->Clone()));
	pObj->UnpackForward(sig,
						-static_cast<int>(valueRight.GetNumber()), true);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj.release());
}

Gura_ImplementBinaryOperator(Sub, pointer, pointer)
{
	const Object_pointer *pObj1 = Object_pointer::GetObject(valueLeft);
	const Object_pointer *pObj2 = Object_pointer::GetObject(valueRight);
	if (&pObj1->GetBinary() != &pObj2->GetBinary()) {
		sig.SetError(ERR_ValueError,
			"cannot calculate difference between pointers of different binaries");
		return Value::Null;
	}
	int offset1 = static_cast<int>(pObj1->GetOffset());
	int offset2 = static_cast<int>(pObj2->GetOffset());
	return Value(static_cast<Number>(offset1 - offset2));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Mul, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mul, number, number)
{
	return Value(valueLeft.GetNumber() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Mul, complex, complex)
{
	return Value(valueLeft.GetComplex() * valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Mul, number, complex)
{
	return Value(valueLeft.GetNumber() * valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Mul, complex, number)
{
	return Value(valueLeft.GetComplex() * valueRight.GetNumber());
}

Gura_ImplementBinaryOperator(Mul, matrix, matrix)
{
	return Matrix::Mul(env, sig,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Mul, list, matrix)
{
	return Matrix::Mul(env, sig,
			valueLeft.GetList(), Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Mul, any, matrix)
{
	return Matrix::Mul(env, sig,
			valueLeft, Object_matrix::GetObject(valueRight)->GetMatrix());
}

Gura_ImplementBinaryOperator(Mul, matrix, list)
{
	return Matrix::Mul(env, sig,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight.GetList());
}

Gura_ImplementBinaryOperator(Mul, matrix, any)
{
	return Matrix::Mul(env, sig,
			Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight);
}

Gura_ImplementBinaryOperator(Mul, timedelta, number)
{
	const TimeDelta &td = valueLeft.GetTimeDelta();
	long num = valueRight.GetLong();
	return Value(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num));
}

Gura_ImplementBinaryOperator(Mul, number, timedelta)
{
	const TimeDelta &td = valueRight.GetTimeDelta();
	long num = valueLeft.GetLong();
	return Value(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num));
}

Gura_ImplementBinaryOperator(Mul, function, any)
{
	const Object_function *pObj = Object_function::GetObject(valueLeft);
	if (pObj->GetFunction()->IsUnary()) {
		ValueList valListArg(valueRight);
		Value result = pObj->Eval(env, sig, valListArg);
		if (sig.IsSignalled()) return Value::Null;
		return result;
	} else {
		sig.SetError(ERR_TypeError, "unary function is expected for multiplier-form applier");
		return Value::Null;
	}
}

Gura_ImplementBinaryOperator(Mul, string, number)
{
	String str;
	for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
		str += valueLeft.GetString();
	}
	return Value(env, str);
}

Gura_ImplementBinaryOperator(Mul, number, string)
{
	String str;
	for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
		str += valueRight.GetString();
	}
	return Value(env, str);
}

Gura_ImplementBinaryOperator(Mul, binary, number)
{
	Binary buff;
	for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
		buff += valueLeft.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

Gura_ImplementBinaryOperator(Mul, number, binary)
{
	Binary buff;
	for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
		buff += valueRight.GetBinary();
	}
	return Value(new Object_binary(env, buff, true));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Div, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Div, number, number)
{
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(valueLeft.GetNumber() / numRight);
}

Gura_ImplementBinaryOperator(Div, complex, complex)
{
	Complex numRight = valueRight.GetComplex();
	if (numRight == Complex(0.)) {
		SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(valueLeft.GetComplex() / valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Div, number, complex)
{
	Complex numRight = valueRight.GetComplex();
	if (numRight == Complex(0.)) {
		SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(valueLeft.GetNumber() / numRight);
}

Gura_ImplementBinaryOperator(Div, complex, number)
{
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(valueLeft.GetComplex() / numRight);
}

Gura_ImplementBinaryOperator(Div, matrix, any)
{
	return Matrix::Div(env, sig,
					Object_matrix::GetObject(valueLeft)->GetMatrix(), valueRight);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Mod, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mod, number, number)
{
	return Value(::fmod(valueLeft.GetNumber(), valueRight.GetNumber()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Pow, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pow, number, number)
{
	return Value(::pow(valueLeft.GetNumber(), valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(Pow, complex, complex)
{
	return Value(std::pow(valueLeft.GetComplex(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Pow, number, complex)
{
	return Value(std::pow(valueLeft.GetNumber(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Pow, complex, number)
{
	return Value(std::pow(valueLeft.GetComplex(), valueRight.GetNumber()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Eq, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Eq, any, any)
{
	return Value(Value::Compare(valueLeft, valueRight) == 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Ne, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ne, any, any)
{
	return Value(Value::Compare(valueLeft, valueRight) != 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Gt, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Gt, any, any)
{
	return Value(Value::Compare(valueLeft, valueRight) > 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Lt, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Lt, any, any)
{
	return Value(Value::Compare(valueLeft, valueRight) < 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Ge, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ge, any, any)
{
	return Value(Value::Compare(valueLeft, valueRight) >= 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Le, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Le, any, any)
{
	return Value(Value::Compare(valueLeft, valueRight) <= 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Cmp, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Cmp, any, any)
{
	return Value(Value::Compare(valueLeft, valueRight));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Contains, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Contains, any, any)
{
	if (valueLeft.IsList() || valueLeft.IsIterator()) {
		Value result;
		ValueList &valList = result.InitAsList(env);
		AutoPtr<Iterator> pIterator(valueLeft.CreateIterator(sig));
		if (pIterator.IsNull()) return Value::Null;
		if (valueRight.IsList()) {
			const ValueList &valListToFind = valueRight.GetList();
			Value value;
			while (pIterator->Next(env, sig, value)) {
				valList.push_back(valListToFind.IsContain(value));
			}
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		} else if (valueRight.IsIterator()) {
			Value value;
			while (pIterator->Next(env, sig, value)) {
				AutoPtr<Iterator> pIteratorToFind(valueRight.CreateIterator(sig));
				if (pIteratorToFind.IsNull()) break;
				bool foundFlag = pIteratorToFind->IsContain(env, sig, value);
				if (sig.IsSignalled()) break;
				valList.push_back(foundFlag);
			}
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		} else {
			Value value;
			while (pIterator->Next(env, sig, value)) {
				valList.push_back(Value::Compare(value, valueRight) == 0);
			}
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		}
		return result;
	} else if (valueRight.IsList()) {
		return Value(valueRight.GetList().IsContain(valueLeft));
	} else if (valueRight.IsIterator()) {
		AutoPtr<Iterator> pIteratorToFind(valueRight.CreateIterator(sig));
		if (pIteratorToFind.IsNull()) return Value::Null;
		bool foundFlag = pIteratorToFind->IsContain(env, sig, valueLeft);
		if (sig.IsSignalled()) return Value::Null;
		return Value(foundFlag);
	} else {
		return Value(Value::Compare(valueLeft, valueRight) == 0);
	}
}

//-----------------------------------------------------------------------------
// BinaryOperator(Or, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Or, number, number)
{
	return Value(valueLeft.GetULong() | valueRight.GetULong());
}

Gura_ImplementBinaryOperator(Or, boolean, boolean)
{
	return Value(valueLeft.GetBoolean() || valueRight.GetBoolean());
}

Gura_ImplementBinaryOperator(Or, nil, any)
{
	return valueRight;	// nil | any -> any
}

Gura_ImplementBinaryOperator(Or, any, nil)
{
	return valueLeft;	// any | nil -> any
}

//-----------------------------------------------------------------------------
// BinaryOperator(And, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(And, number, number)
{
	return Value(static_cast<unsigned long>(valueLeft.GetNumber()) &
						static_cast<unsigned long>(valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(And, boolean, boolean)
{
	return Value(valueLeft.GetBoolean() && valueRight.GetBoolean());
}

Gura_ImplementBinaryOperator(And, nil, any)
{
	return Value::Null;	// nil & any -> nil
}

Gura_ImplementBinaryOperator(And, any, nil)
{
	return Value::Null;	// any & nil -> nil
}

//-----------------------------------------------------------------------------
// BinaryOperator(Xor, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Xor, number, number)
{
	return Value(static_cast<unsigned long>(valueLeft.GetNumber()) ^
						static_cast<unsigned long>(valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(Xor, boolean, boolean)
{
	bool flagLeft = valueLeft.GetBoolean();
	bool flagRight = valueRight.GetBoolean();
	return Value((flagLeft && !flagRight) || (!flagLeft && flagRight));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Shl, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shl, number, number)
{
	return Value(static_cast<unsigned long>(valueLeft.GetNumber()) <<
							static_cast<unsigned long>(valueRight.GetNumber()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Shr, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shr, number, number)
{
	return Value(static_cast<unsigned long>(valueLeft.GetNumber()) >>
							static_cast<unsigned long>(valueRight.GetNumber()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(OrOr, expr, expr)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(OrOr, expr, expr)
{
	Value result;
	result = valueLeft.GetExpr()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	if (result.GetBoolean()) return result;
	result = valueRight.GetExpr()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

//-----------------------------------------------------------------------------
// BinaryOperator(AndAnd, expr, expr)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(AndAnd, expr, expr)
{
	Value result;
	result = valueLeft.GetExpr()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	if (!result.GetBoolean()) return result;
	result = valueRight.GetExpr()->Exec(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return result;
}

//-----------------------------------------------------------------------------
// BinaryOperator(Seq, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Seq, number, number)
{
	Number numBegin = valueLeft.GetNumber();
	Number numEnd = valueRight.GetNumber();
	Number numStep = (numEnd >= numBegin)? +1 : -1;
	return Value(env, new Iterator_Sequence(numBegin, numEnd, numStep));
}

void AssignBasicOperators(Environment &env)
{
	env.SetOperator(OPTYPE_Pos, new Operator_Pos());
	env.SetOperator(OPTYPE_Neg, new Operator_Neg());
	env.SetOperator(OPTYPE_Inv, new Operator_Inv());
	env.SetOperator(OPTYPE_Not, new Operator_Not());
	env.SetOperator(OPTYPE_SeqInf, new Operator_SeqInf());
	env.SetOperator(OPTYPE_Add, new Operator_Add());
	env.SetOperator(OPTYPE_Sub, new Operator_Sub());
	env.SetOperator(OPTYPE_Mul, new Operator_Mul());
	env.SetOperator(OPTYPE_Div, new Operator_Div());
	env.SetOperator(OPTYPE_Mod, new Operator_Mod());
	env.SetOperator(OPTYPE_Pow, new Operator_Pow());
	env.SetOperator(OPTYPE_Eq, new Operator_Eq());
	env.SetOperator(OPTYPE_Ne, new Operator_Ne());
	env.SetOperator(OPTYPE_Gt, new Operator_Gt());
	env.SetOperator(OPTYPE_Lt, new Operator_Lt());
	env.SetOperator(OPTYPE_Ge, new Operator_Ge());
	env.SetOperator(OPTYPE_Le, new Operator_Le());
	env.SetOperator(OPTYPE_Cmp, new Operator_Cmp());
	env.SetOperator(OPTYPE_Contains, new Operator_Contains());
	env.SetOperator(OPTYPE_Or, new Operator_Or());
	env.SetOperator(OPTYPE_And, new Operator_And());
	env.SetOperator(OPTYPE_Xor, new Operator_Xor());
	env.SetOperator(OPTYPE_Shl, new Operator_Shl());
	env.SetOperator(OPTYPE_Shr, new Operator_Shr());
	env.SetOperator(OPTYPE_OrOr, new Operator_OrOr());
	env.SetOperator(OPTYPE_AndAnd, new Operator_AndAnd());
	env.SetOperator(OPTYPE_Seq, new Operator_Seq());
	Gura_AssignUnaryOperator(Pos, number);
	Gura_AssignUnaryOperator(Pos, complex);
	Gura_AssignUnaryOperator(Pos, matrix);
	Gura_AssignUnaryOperator(Pos, timedelta);
	Gura_AssignUnaryOperator(Neg, number);
	Gura_AssignUnaryOperator(Neg, complex);
	Gura_AssignUnaryOperator(Neg, matrix);
	Gura_AssignUnaryOperator(Neg, timedelta);
	Gura_AssignUnaryOperator(Inv, number);
	Gura_AssignUnaryOperator(Not, any);
	Gura_AssignUnaryOperator(SeqInf, number);
	Gura_AssignBinaryOperator(Add, number, number);
	Gura_AssignBinaryOperator(Add, complex, complex);
	Gura_AssignBinaryOperator(Add, number, complex);
	Gura_AssignBinaryOperator(Add, complex, number);
	Gura_AssignBinaryOperator(Add, matrix, matrix);
	Gura_AssignBinaryOperator(Add, datetime, timedelta);
	Gura_AssignBinaryOperator(Add, timedelta, datetime);
	Gura_AssignBinaryOperator(Add, timedelta, timedelta);
	Gura_AssignBinaryOperator(Add, string, string);
	Gura_AssignBinaryOperator(Add, binary, binary);
	Gura_AssignBinaryOperator(Add, binary, string);
	Gura_AssignBinaryOperator(Add, string, binary);
	Gura_AssignBinaryOperator(Add, pointer, number);
	Gura_AssignBinaryOperator(Add, string, any);
	Gura_AssignBinaryOperator(Add, any, string);
	Gura_AssignBinaryOperator(Sub, number, number);
	Gura_AssignBinaryOperator(Sub, complex, complex);
	Gura_AssignBinaryOperator(Sub, number, complex);
	Gura_AssignBinaryOperator(Sub, complex, number);
	Gura_AssignBinaryOperator(Sub, matrix, matrix);
	Gura_AssignBinaryOperator(Sub, datetime, timedelta);
	Gura_AssignBinaryOperator(Sub, datetime, datetime);
	Gura_AssignBinaryOperator(Sub, timedelta, timedelta);
	Gura_AssignBinaryOperator(Sub, color, color);
	Gura_AssignBinaryOperator(Sub, pointer, number);
	Gura_AssignBinaryOperator(Sub, pointer, pointer);
	Gura_AssignBinaryOperator(Mul, number, number);
	Gura_AssignBinaryOperator(Mul, complex, complex);
	Gura_AssignBinaryOperator(Mul, number, complex);
	Gura_AssignBinaryOperator(Mul, complex, number);
	Gura_AssignBinaryOperator(Mul, matrix, matrix);
	Gura_AssignBinaryOperator(Mul, list, matrix);
	Gura_AssignBinaryOperator(Mul, any, matrix);
	Gura_AssignBinaryOperator(Mul, matrix, list);
	Gura_AssignBinaryOperator(Mul, matrix, any);
	Gura_AssignBinaryOperator(Mul, timedelta, number);
	Gura_AssignBinaryOperator(Mul, number, timedelta);
	Gura_AssignBinaryOperator(Mul, function, any);
	Gura_AssignBinaryOperator(Mul, string, number);
	Gura_AssignBinaryOperator(Mul, number, string);
	Gura_AssignBinaryOperator(Mul, binary, number);
	Gura_AssignBinaryOperator(Mul, number, binary);
	Gura_AssignBinaryOperator(Div, number, number);
	Gura_AssignBinaryOperator(Div, complex, complex);
	Gura_AssignBinaryOperator(Div, number, complex);
	Gura_AssignBinaryOperator(Div, complex, number);
	Gura_AssignBinaryOperator(Div, matrix, any);
	Gura_AssignBinaryOperator(Mod, number, number);
	Gura_AssignBinaryOperator(Pow, number, number);
	Gura_AssignBinaryOperator(Pow, complex, complex);
	Gura_AssignBinaryOperator(Pow, number, complex);
	Gura_AssignBinaryOperator(Pow, complex, number);
	Gura_AssignBinaryOperator(Eq, any, any);
	Gura_AssignBinaryOperator(Ne, any, any);
	Gura_AssignBinaryOperator(Gt, any, any);
	Gura_AssignBinaryOperator(Lt, any, any);
	Gura_AssignBinaryOperator(Ge, any, any);
	Gura_AssignBinaryOperator(Le, any, any);
	Gura_AssignBinaryOperator(Cmp, any, any);
	Gura_AssignBinaryOperator(Contains, any, any);
	Gura_AssignBinaryOperator(Or, number, number);
	Gura_AssignBinaryOperator(Or, boolean, boolean);
	Gura_AssignBinaryOperator(Or, nil, any);
	Gura_AssignBinaryOperator(Or, any, nil);
	Gura_AssignBinaryOperator(And, number, number);
	Gura_AssignBinaryOperator(And, boolean, boolean);
	Gura_AssignBinaryOperator(And, nil, any);
	Gura_AssignBinaryOperator(And, any, nil);
	Gura_AssignBinaryOperator(Xor, number, number);
	Gura_AssignBinaryOperator(Xor, boolean, boolean);
	Gura_AssignBinaryOperator(Shl, number, number);
	Gura_AssignBinaryOperator(Shr, number, number);
	Gura_AssignBinaryOperator(OrOr, expr, expr);
	Gura_AssignBinaryOperator(AndAnd, expr, expr);
	Gura_AssignBinaryOperator(Seq, number, number);
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_DivideByZero(Signal sig)
{
	sig.SetError(ERR_ZeroDivisionError, "divide by zero");
}

void SetError_MathDiffError(Signal sig)
{
	sig.SetError(ERR_ValueError, "failed to generate a differential function");
}

void SetError_MathOptimizeError(Signal sig)
{
	sig.SetError(ERR_ValueError, "mathematical optimization is not supported");
}

Expr *OptimizeConst(Environment &env, Signal sig,
									const Operator *pOperator, Expr *pExprChild)
{
	Value value = dynamic_cast<Expr_Value *>(pExprChild)->GetValue();
	Expr::Delete(pExprChild);
	Value result = pOperator->EvalUnary(env, sig, value);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(result);
}

Expr *OptimizeConst(Environment &env, Signal sig,
					const Operator *pOperator, Expr *pExprLeft, Expr *pExprRight)
{
	Value valueLeft = dynamic_cast<Expr_Value *>(pExprLeft)->GetValue();
	Value valueRight = dynamic_cast<Expr_Value *>(pExprRight)->GetValue();
	Expr::Delete(pExprLeft);
	Expr::Delete(pExprRight);
	Value result = pOperator->EvalBinary(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(result);
}

}
