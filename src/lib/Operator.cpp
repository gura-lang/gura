//=============================================================================
// Operator
//=============================================================================
#include "stdafx.h"

namespace Gura {

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
	"?",	// OPTYPE_Question
	"*",	// OPTYPE_Each
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
	"&",	// OPTYPE_And
	"|",	// OPTYPE_Or
	"^",	// OPTYPE_Xor
	"<<",	// OPTYPE_Shl
	">>",	// OPTYPE_Shr
	"||",	// OPTYPE_OrOr
	"&&",	// OPTYPE_AndAnd
	"..",	// OPTYPE_Seq
	"=>",	// OPTYPE_Pair
};

const OperatorEntry *Operator::Lookup(ValueType valType, bool suffixFlag) const
{
	EntryDict::const_iterator iter = _entryDict.find(CalcKey(valType, suffixFlag));
	if (iter != _entryDict.end()) return iter->second;
	iter = _entryDict.find(CalcKey(VTYPE_any, suffixFlag));
	if (iter != _entryDict.end()) return iter->second;
	return NULL;
}

const OperatorEntry *Operator::Lookup(ValueType valTypeLeft, ValueType valTypeRight) const
{
	EntryDict::const_iterator iter = _entryDict.find(CalcKey(valTypeLeft, valTypeRight));
	if (iter != _entryDict.end()) return iter->second;
	iter = _entryDict.find(CalcKey(valTypeLeft, VTYPE_any));
	if (iter != _entryDict.end()) return iter->second;
	iter = _entryDict.find(CalcKey(VTYPE_any, valTypeRight));
	if (iter != _entryDict.end()) return iter->second;
	iter = _entryDict.find(CalcKey(VTYPE_any, VTYPE_any));
	if (iter != _entryDict.end()) return iter->second;
	return NULL;
}

Expr *Operator::MathDiffUnary(Environment &env, Signal sig,
							const Expr *pExprChild, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

Expr *Operator::MathDiffBinary(Environment &env, Signal sig,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

Expr *Operator::MathOptimizeConst(Environment &env, Signal sig,
								Expr_Value *pExprChild, bool suffixFlag) const
{
	Value value = pExprChild->GetValue();
	Expr::Delete(pExprChild);
	Value result = EvalUnary(env, sig, value, suffixFlag);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(result);
}

Expr *Operator::MathOptimizeConst(Environment &env, Signal sig,
								Expr_Value *pExprLeft, Expr_Value *pExprRight) const
{
	Value valueLeft = pExprLeft->GetValue();
	Value valueRight = pExprRight->GetValue();
	Expr::Delete(pExprLeft);
	Expr::Delete(pExprRight);
	Value result = EvalBinary(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(result);
}

Expr *Operator::MathOptimizeUnary(Environment &env, Signal sig, Expr *pExprChild) const
{
	SetError_MathOptimizeError(sig);
	return NULL;
}

Expr *Operator::MathOptimizeBinary(Environment &env, Signal sig,
										Expr *pExprLeft, Expr *pExprRight) const
{
	SetError_MathOptimizeError(sig);
	return NULL;
}

Value Operator::EvalUnary(Environment &env, Signal sig, const Value &value, bool suffixFlag) const
{
	const OperatorEntry *pOperatorEntry = Lookup(value.GetValueType(), suffixFlag);
	if (pOperatorEntry == NULL) {
		SetError_InvalidValueType(sig, GetOpType(), value, suffixFlag);
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

Value Operator::EvalMapUnary(Environment &env, Signal sig, const Value &value, bool suffixFlag) const
{
	if (!_mapFlag || !value.IsListOrIterator() || value.GetNoMapFlag()) {
		return EvalUnary(env, sig, value, suffixFlag);
	}
	AutoPtr<Iterator> pIterator(new Iterator_UnaryOperatorMap(
							new Environment(env), sig, this, value, suffixFlag));
	if (value.Is_iterator()) {
		return Value(new Object_iterator(env, pIterator.release()));
	}
	return pIterator->ToList(env, sig, true, false);
}

Value Operator::EvalMapBinary(Environment &env, Signal sig,
							const Value &valueLeft, const Value &valueRight) const
{
	if (!_mapFlag || ((!valueLeft.IsListOrIterator() || valueLeft.GetNoMapFlag()) &&
				(!valueRight.IsListOrIterator() || valueRight.GetNoMapFlag()))) {
		return EvalBinary(env, sig, valueLeft, valueRight);
	}
	AutoPtr<Iterator> pIterator(new Iterator_BinaryOperatorMap(new Environment(env), sig,
									this, valueLeft, valueRight));
	if (valueLeft.Is_iterator() || valueRight.Is_iterator()) {
		return Value(new Object_iterator(env, pIterator.release()));
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

void Operator::Assign(Environment &env, OperatorEntry *pOperatorEntry)
{
	Operator *pOperator = env.GetOperator(pOperatorEntry->GetOpType());
	EntryDict &entryDict = pOperator->GetEntryDict();
	Key key = pOperatorEntry->CalcKey();
	EntryDict::iterator iter = entryDict.find(key);
	if (iter == entryDict.end()) {
		entryDict[key] = pOperatorEntry;
	} else {
		delete iter->second;
		iter->second = pOperatorEntry;
	}
}

void Operator::SetError_InvalidValueType(Signal &sig, OpType opType,
										const Value &value, bool suffixFlag)
{
	if (suffixFlag) {
		sig.SetError(ERR_TypeError, "can't evaluate (%s %s)",
					value.MakeValueTypeName().c_str(), GetMathSymbol(opType));
	} else {
		sig.SetError(ERR_TypeError, "can't evaluate (%s %s)",
					GetMathSymbol(opType), value.MakeValueTypeName().c_str());
	}
}

void Operator::SetError_InvalidValueType(Signal &sig, OpType opType,
						const Value &valueLeft, const Value &valueRight)
{
	sig.SetError(ERR_TypeError, "can't evaluate (%s %s %s)",
		valueLeft.MakeValueTypeName().c_str(), GetMathSymbol(opType), valueRight.MakeValueTypeName().c_str());
}

void Operator::SetError_DivideByZero(Signal &sig)
{
	sig.SetError(ERR_ZeroDivisionError, "divide by zero");
}

void Operator::SetError_MathDiffError(Signal &sig)
{
	sig.SetError(ERR_ValueError, "failed to generate a differential function");
}

void Operator::SetError_MathOptimizeError(Signal &sig)
{
	sig.SetError(ERR_ValueError, "mathematical optimization is not supported");
}

//-----------------------------------------------------------------------------
// Operator_Pos
//-----------------------------------------------------------------------------
Expr *Operator_Pos::MathOptimize(Environment &env, Signal sig, Expr *pExprChild)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return NULL;
	}
	return pExprChild;
}

Expr *Operator_Pos::MathDiffUnary(Environment &env, Signal sig,
							const Expr *pExprChild, const Symbol *pSymbol) const
{
	AutoPtr<Expr> pExprDiff(pExprChild->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	return Operator_Pos::MathOptimize(env, sig, pExprDiff.release());
}

Expr *Operator_Pos::MathOptimizeUnary(Environment &env, Signal sig, Expr *pExprChild) const
{
	return Operator_Pos::MathOptimize(env, sig, pExprChild);
}

//-----------------------------------------------------------------------------
// Operator_Neg
//-----------------------------------------------------------------------------
Expr *Operator_Neg::MathDiffUnary(Environment &env, Signal sig,
							const Expr *pExprChild, const Symbol *pSymbol) const
{
	AutoPtr<Expr> pExprDiff(pExprChild->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	return Operator_Neg::MathOptimize(env, sig, pExprDiff.release());
}

Expr *Operator_Neg::MathOptimizeUnary(Environment &env, Signal sig, Expr *pExprChild) const
{
	return Operator_Neg::MathOptimize(env, sig, pExprChild);
}

Expr *Operator_Neg::MathOptimize(Environment &env, Signal sig, Expr *pExprChild)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return NULL;
	}
	if (pExprChild->IsValue()) {
		bool suffixFlag = false;
		return env.GetOperator(OPTYPE_Neg)->MathOptimizeConst(env, sig,
							dynamic_cast<Expr_Value *>(pExprChild), suffixFlag);
	} else if (pExprChild->IsUnaryOp(OPTYPE_Neg)) {
		// -(-n) = n
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprChild)->GetChild()->Clone();
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
// Operator_Question
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Each
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Add
//-----------------------------------------------------------------------------
Expr *Operator_Add::MathDiffBinary(Environment &env, Signal sig,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	// (f(x) + g(x))' = f'(x) + g'(x)
	return Operator_Add::MathOptimize(
		env, sig, pExprDiff1.release(), pExprDiff2.release());
}

Expr *Operator_Add::MathOptimizeBinary(Environment &env, Signal sig,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Add::MathOptimize(env, sig, pExprLeft, pExprRight);
}

Expr *Operator_Add::MathOptimize(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v + v = v
		return env.GetOperator(OPTYPE_Add)->MathOptimizeConst(env, sig,
					dynamic_cast<Expr_Value *>(pExprLeft),
					dynamic_cast<Expr_Value *>(pExprRight));
	} else if (pExprLeft->IsConstNumber(0)) {
		// 0 + m = m
		Expr::Delete(pExprLeft);
		return pExprRight;
	} else if (pExprRight->IsConstNumber(0)) {
		// n + 0 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// n + (-m) = n - m
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprRight);
		return Operator_Sub::MathOptimize(env, sig, pExprLeft, pExpr);
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsIdentifier()) {
		// n + n = n * 2
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Operator_Mul::MathOptimize(env, sig, pExprLeft, new Expr_Value(2));
		}
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsBinaryOp(OPTYPE_Mul)) {
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n + n * m = n * (1 + m)
				Expr *pExprMulR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprRight);
				return Operator_Mul::MathOptimize(
					env, sig,
					pExprLeft,
					Operator_Add::MathOptimize(env, sig, new Expr_Value(1), pExprMulR));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Mul) && pExprRight->IsIdentifier()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n * m + n = n * (m + 1)
				Expr *pExprMulL = pExprBinOpL->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				return Operator_Mul::MathOptimize(
					env, sig,
					pExprRight,
					Operator_Add::MathOptimize(env, sig, pExprMulL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Mul) && pExprRight->IsBinaryOp(OPTYPE_Mul)) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier() && pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			const Expr_Identifier *pExprIdentifierR =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n * m + n * p = n * (m + p)
				Expr *pExprBase = pExprBinOpL->GetLeft()->Clone();
				Expr *pExprMulL = pExprBinOpL->GetRight()->Clone();
				Expr *pExprMulR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Mul::MathOptimize(
					env, sig,
					pExprBase,
					Operator_Add::MathOptimize(env, sig, pExprMulL, pExprMulR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Sub
//-----------------------------------------------------------------------------
Expr *Operator_Sub::MathDiffBinary(Environment &env, Signal sig,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	// (f(x) - g(x))' = f'(x) - g'(x)
	return Operator_Sub::MathOptimize(
		env, sig, pExprDiff1.release(), pExprDiff2.release());
}

Expr *Operator_Sub::MathOptimizeBinary(Environment &env, Signal sig,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Sub::MathOptimize(env, sig, pExprLeft, pExprRight);
}

Expr *Operator_Sub::MathOptimize(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v - v = v
		return env.GetOperator(OPTYPE_Sub)->MathOptimizeConst(env, sig,
					dynamic_cast<Expr_Value *>(pExprLeft),
					dynamic_cast<Expr_Value *>(pExprRight));
	} else if (pExprLeft->IsConstNumber(0)) {
		// 0 - m = -m
		Expr::Delete(pExprLeft);
		return Operator_Neg::MathOptimize(env, sig, pExprRight);
	} else if (pExprRight->IsConstNumber(0)) {
		// n - 0 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// n - (-m) = n + m
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprRight);
		return Operator_Add::MathOptimize(env, sig, pExprLeft, pExpr);
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsIdentifier()) {
		// n - n = 0
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
			Expr::Delete(pExprLeft);
			Expr::Delete(pExprRight);
			return new Expr_Value(0);
		}
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsBinaryOp(OPTYPE_Mul)) {
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n - n * m = n * (1 - m)
				Expr *pExprMulR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprRight);
				return Operator_Mul::MathOptimize(
					env, sig,
					pExprLeft,
					Operator_Sub::MathOptimize(env, sig, new Expr_Value(1), pExprMulR));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Mul) && pExprRight->IsIdentifier()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n * m - n = n * (m - 1)
				Expr *pExprMulL = pExprBinOpL->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				return Operator_Mul::MathOptimize(
					env, sig,
					pExprRight,
					Operator_Sub::MathOptimize(env, sig, pExprMulL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Mul) && pExprRight->IsBinaryOp(OPTYPE_Mul)) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier() && pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			const Expr_Identifier *pExprIdentifierR =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n * m - n * p = n * (m - p)
				Expr *pExprBase = pExprBinOpL->GetLeft()->Clone();
				Expr *pExprMulL = pExprBinOpL->GetRight()->Clone();
				Expr *pExprMulR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Mul::MathOptimize(
					env, sig,
					pExprBase,
					Operator_Sub::MathOptimize(env, sig, pExprMulL, pExprMulR));
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
	if (valueLeft.Is_function()) {
		const Function *pFunc = valueLeft.GetFunction();
		if (pFunc->IsUnary()) {
			// nothing to do
		} else if (valueRight.Is_list()) {
			const ValueList &valList = valueRight.GetList();
			if (valList.IsFlat()) {
				ValueList valListComp = valList;
				if (!pFunc->GetDeclOwner().Compensate(env, sig, valListComp)) {
					return Value::Null;
				}
				AutoPtr<Args> pArgsSub(new Args());
				pArgsSub->SetValueListArg(valListComp);
				return pFunc->Eval(env, sig, *pArgsSub);
			}
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			AutoPtr<Iterator> pIteratorFuncBinder(new Iterator_FuncBinder(new Environment(env),
						Function::Reference(pFunc),
						Object_function::GetObject(valueLeft)->GetThis(), pIterator.release()));
			AutoPtr<Args> pArgsSub(new Args());
			pArgsSub->SetValues(valueLeft, valueRight);
			return pIteratorFuncBinder->Eval(env, sig, *pArgsSub);
		} else if (valueRight.Is_iterator()) {
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			AutoPtr<Iterator> pIteratorFuncBinder(new Iterator_FuncBinder(new Environment(env),
						Function::Reference(pFunc),
						Object_function::GetObject(valueLeft)->GetThis(), pIterator.release()));
			if (pFunc->IsRsltNormal() ||
						pFunc->IsRsltIterator() || pFunc->IsRsltXIterator()) {
				return Value(new Object_iterator(env, pIteratorFuncBinder.release()));
			} else {
				AutoPtr<Args> pArgsSub(new Args());
				pArgsSub->SetValues(valueLeft, valueRight);
				return pIteratorFuncBinder->Eval(env, sig, *pArgsSub);
			}
		}
	} else if ((valueLeft.Is_matrix() && valueRight.Is_list()) ||
			   (valueLeft.Is_list() && valueRight.Is_matrix())) {
		return EvalBinary(env, sig, valueLeft, valueRight);
	}
	return Operator::EvalMapBinary(env, sig, valueLeft, valueRight);
}

Expr *Operator_Mul::MathDiffBinary(Environment &env, Signal sig,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	// (f(x)g(x))' = f'(x)g(x) + f(x)g'(x)
	return Operator_Add::MathOptimize(
		env, sig,
		Operator_Mul::MathOptimize(
			env, sig, pExprDiff1.release(), pExprRight->Clone()),
		Operator_Mul::MathOptimize(
			env, sig, pExprLeft->Clone(), pExprDiff2.release()));
}

Expr *Operator_Mul::MathOptimizeBinary(Environment &env, Signal sig,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Mul::MathOptimize(env, sig, pExprLeft, pExprRight);
}

Expr *Operator_Mul::MathOptimize(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v * v = v
		return env.GetOperator(OPTYPE_Mul)->MathOptimizeConst(env, sig,
					dynamic_cast<Expr_Value *>(pExprLeft),
					dynamic_cast<Expr_Value *>(pExprRight));
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
		return Operator_Neg::MathOptimize(env, sig, pExprRight);
	} else if (pExprRight->IsConstNumber(-1)) {
		// n * (-1) = -n
		Expr::Delete(pExprRight);
		return Operator_Neg::MathOptimize(env, sig, pExprLeft);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg) && pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) * (-m) = n * m
		Expr *pExpr1 =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr *pExpr2 =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Operator_Mul::MathOptimize(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) * m = -(n * m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Neg::MathOptimize(
			env, sig,
			Operator_Mul::MathOptimize(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// n * (-m) = -(n * m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprRight);
		return Operator_Neg::MathOptimize(
			env, sig,
			Operator_Mul::MathOptimize(env, sig, pExprLeft, pExpr));
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsIdentifier()) {
		// n * n = n ** 2
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Operator_Pow::MathOptimize(env, sig, pExprLeft, new Expr_Value(2));
		}
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsBinaryOp(OPTYPE_Pow)) {
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n * n ** m = n ** (m + 1)
				Expr *pExprPowR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprRight);
				return Operator_Pow::MathOptimize(
					env, sig,
					pExprLeft,
					Operator_Add::MathOptimize(env, sig, pExprPowR, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Div)) {
		// n / m * l = n * l / m
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		Expr *pExprLeftL = pExprBinOpL->GetLeft()->Clone();
		Expr *pExprLeftR = pExprBinOpL->GetRight()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Div::MathOptimize(
			env, sig,
			Operator_Mul::MathOptimize(env, sig, pExprLeftL, pExprRight),
			pExprLeftR);
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Pow) && pExprRight->IsIdentifier()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n ** m * n = n ** (m + 1)
				Expr *pExprPowL = pExprBinOpL->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				return Operator_Pow::MathOptimize(
					env, sig,
					pExprRight,
					Operator_Add::MathOptimize(env, sig, pExprPowL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Pow) && pExprRight->IsBinaryOp(OPTYPE_Pow)) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier() && pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			const Expr_Identifier *pExprIdentifierR =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n ** m * n ** p = n ** (m + p)
				Expr *pExprBase = pExprBinOpL->GetLeft()->Clone();
				Expr *pExprPowL = pExprBinOpL->GetRight()->Clone();
				Expr *pExprPowR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Pow::MathOptimize(
					env, sig,
					pExprBase,
					Operator_Add::MathOptimize(env, sig, pExprPowL, pExprPowR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Div
//-----------------------------------------------------------------------------
Expr *Operator_Div::MathDiffBinary(Environment &env, Signal sig,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	// (f(x) / g(x))' = (f'(x)g(x) - f(x)g'(x)) / {g(x)}^2
	return Operator_Div::MathOptimize(
		env, sig,
		Operator_Sub::MathOptimize(
			env, sig,
			Operator_Mul::MathOptimize(
				env, sig, pExprDiff1.release(), pExprRight->Clone()),
			Operator_Mul::MathOptimize(
				env, sig, pExprLeft->Clone(), pExprDiff2.release())),
		Operator_Pow::MathOptimize(
			env, sig, pExprRight->Clone(), new Expr_Value(2)));
}

Expr *Operator_Div::MathOptimizeBinary(Environment &env, Signal sig,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Div::MathOptimize(env, sig, pExprLeft, pExprRight);
}

Expr *Operator_Div::MathOptimize(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
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
		return Operator_Neg::MathOptimize(env, sig, pExprLeft);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg) && pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) / (-m) = n / m
		Expr *pExpr1 =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr *pExpr2 =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Operator_Div::MathOptimize(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) / m = -(n / m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Neg::MathOptimize(
			env, sig,
			Operator_Div::MathOptimize(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// n / (-m) = -(n / m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprRight);
		return Operator_Neg::MathOptimize(
			env, sig,
			Operator_Div::MathOptimize(env, sig, pExprLeft, pExpr));
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsIdentifier()) {
		// n / n = 1
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
			Expr::Delete(pExprLeft);
			Expr::Delete(pExprRight);
			return new Expr_Value(1);
		}
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsBinaryOp(OPTYPE_Pow)) {
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n / n ** m = n ** (1 - m)
				Expr *pExprPowR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprRight);
				return Operator_Pow::MathOptimize(
					env, sig,
					pExprLeft,
					Operator_Sub::MathOptimize(env, sig, new Expr_Value(1), pExprPowR));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Pow) && pExprRight->IsIdentifier()) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n ** m / n = n ** (m - 1)
				Expr *pExprPowL = pExprBinOpL->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				return Operator_Pow::MathOptimize(
					env, sig,
					pExprRight,
					Operator_Sub::MathOptimize(env, sig, pExprPowL, new Expr_Value(1)));
			}
		}
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Pow) && pExprRight->IsBinaryOp(OPTYPE_Pow)) {
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		const Expr_BinaryOp *pExprBinOpR =
							dynamic_cast<const Expr_BinaryOp *>(pExprRight);
		if (pExprBinOpL->GetLeft()->IsIdentifier() && pExprBinOpR->GetLeft()->IsIdentifier()) {
			const Expr_Identifier *pExprIdentifierL =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpL->GetLeft());
			const Expr_Identifier *pExprIdentifierR =
								dynamic_cast<const Expr_Identifier *>(pExprBinOpR->GetLeft());
			if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
				// n ** m / n ** p = n ** (m - p)
				Expr *pExprBase = pExprBinOpL->GetLeft()->Clone();
				Expr *pExprPowL = pExprBinOpL->GetRight()->Clone();
				Expr *pExprPowR = pExprBinOpR->GetRight()->Clone();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Operator_Pow::MathOptimize(
					env, sig,
					pExprBase,
					Operator_Sub::MathOptimize(env, sig, pExprPowL, pExprPowR));
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
	if (valueLeft.Is_function()) {
		const Function *pFunc = valueLeft.GetFunction();
		Value result;
		if (!valueRight.Is_list()) {
			AutoPtr<Args> pArgsSub(new Args());
			pArgsSub->SetValue(valueRight);
			result = pFunc->Eval(env, sig, *pArgsSub);
		} else if (pFunc->GetMapFlag() == Function::MAP_Off ||
				!pFunc->GetDeclOwner().ShouldImplicitMap(valueRight.GetList())) {
			AutoPtr<Args> pArgsSub(new Args());
			pArgsSub->SetValueListArg(valueRight.GetList());
			result = pFunc->Eval(env, sig, *pArgsSub);
		} else if (pFunc->IsUnary()) {
			AutoPtr<Args> pArgsSub(new Args());
			pArgsSub->SetValue(valueRight);
			result = pFunc->EvalMap(env, sig, *pArgsSub);
		} else {
			AutoPtr<Args> pArgsSub(new Args());
			pArgsSub->SetValueListArg(valueRight.GetList());
			result = pFunc->EvalMap(env, sig, *pArgsSub);
		}
		return result;
	} else if (valueLeft.Is_string()) {
		const char *format = valueLeft.GetString();
		if (!valueRight.Is_list()) {
			String str = Formatter::Format(sig, format, ValueList(valueRight));
			if (sig.IsSignalled()) return Value::Null;
			return Value(str);
		} else {
			const ValueList &valList = valueRight.GetList();
			if (valList.IsFlat() && !valList.DoesContainIterator()) {
				String str = Formatter::Format(sig, format, valList);
				if (sig.IsSignalled()) return Value::Null;
				return Value(str);
			} else {
				IteratorOwner iterOwner;
				foreach_const (ValueList, pValue, valList) {
					AutoPtr<Iterator> pIterator;
					if (pValue->Is_list() || pValue->Is_iterator()) {
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
Expr *Operator_Pow::MathDiffBinary(Environment &env, Signal sig,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, sig, pSymbol));
	if (sig.IsSignalled()) return NULL;
	// (f(x) ** g(x))' = f'(x)g(x)(f(x) ** (g(x) - 1)) + g'(x)log(f(x))(f(x) ** g(x))
	return Operator_Add::MathOptimize(
		env, sig,
		Operator_Mul::MathOptimize(
			env, sig,
			Operator_Mul::MathOptimize(
				env, sig, pExprDiff1.release(), pExprRight->Clone()),
			Operator_Pow::MathOptimize(
				env, sig,
				pExprLeft->Clone(),
				Operator_Sub::MathOptimize(
					env, sig, pExprRight->Clone(), new Expr_Value(1)))),
		Operator_Mul::MathOptimize(
			env, sig,
			Operator_Mul::MathOptimize(
				env, sig,
				pExprDiff2.release(),
				Expr_Caller::Create(
					Gura_Symbol(math), Gura_Symbol(log), pExprLeft->Clone())),
			Operator_Pow::MathOptimize(
				env, sig, pExprLeft->Clone(), pExprRight->Clone())));
}

Expr *Operator_Pow::MathOptimizeBinary(Environment &env, Signal sig,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Pow::MathOptimize(env, sig, pExprLeft, pExprRight);
}

Expr *Operator_Pow::MathOptimize(Environment &env, Signal sig, Expr *pExprLeft, Expr *pExprRight)
{
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return NULL;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v ** v = v
		return env.GetOperator(OPTYPE_Pow)->MathOptimizeConst(env, sig,
					dynamic_cast<Expr_Value *>(pExprLeft),
					dynamic_cast<Expr_Value *>(pExprRight));
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
		return Operator_Div::MathOptimize(env, sig, new Expr_Value(1), pExprLeft);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg) && pExprRight->IsConstEvenNumber()) {
		// (-n) ** (2m) = n ** (2m)
		Expr *pExpr = dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Pow::MathOptimize(env, sig, pExpr, pExprRight);
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Pow)) {
		// n ** m ** l = n ** (m * l)
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		Expr *pExprLeftL = pExprBinOpL->GetLeft()->Clone();
		Expr *pExprLeftR = pExprBinOpL->GetRight()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Pow::MathOptimize(
			env, sig,
			pExprLeftL,
			Operator_Mul::MathOptimize(env, sig, pExprLeftR, pExprRight));
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
// Operator_And
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Operator_Or
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
// Operator_Pair
//-----------------------------------------------------------------------------
Value Operator_Pair::EvalMapBinary(Environment &env, Signal sig,
							const Value &valueLeft, const Value &valueRight) const
{
	return EvalBinary(env, sig, valueLeft, valueRight);
}

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

void OperatorEntry::SetError_InvalidValueType(Signal &sig, const Value &value, bool suffixFlag) const
{
	Operator::SetError_InvalidValueType(sig, GetOpType(), value, suffixFlag);
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

Gura_ImplementUnaryOperator(Pos, rational)
{
	const Rational &a = value.GetRational();
	if (a.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	if (a.numer == 0) return Value::Zero;
	return Value(+a);
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

Gura_ImplementUnaryOperator(Neg, rational)
{
	const Rational &a = value.GetRational();
	if (a.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	if (a.numer == 0) return Value::Zero;
	return Value(-a);
}

Gura_ImplementUnaryOperator(Neg, matrix)
{
	return Matrix::Neg(env, sig, Object_matrix::GetObject(value)->GetMatrix());
}

Gura_ImplementUnaryOperator(Neg, timedelta)
{
	TimeDelta td = Object_timedelta::GetObject(value)->GetTimeDelta();
	return Value(new Object_timedelta(env, TimeDelta(-td.GetDays(), -td.GetSecsRaw(), -td.GetUSecs())));
}

//-----------------------------------------------------------------------------
// UnaryOperator(Invert, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Inv, number)
{
	ULong num = ~static_cast<ULong>(value.GetNumber());
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
// UnaryOperator(SeqInf, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(SeqInf, number)
{
	Number numBegin = value.GetNumber();
	return Value(new Object_iterator(env, new Iterator_SequenceInf(numBegin)));
}

//-----------------------------------------------------------------------------
// UnaryOperator(Question, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(Question, any)
{
	bool rtn = value.GetBoolean();
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// UnaryOperator(Each, *)
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(Each, any)
{
	AutoPtr<Iterator> pIterator(value.CreateIterator(sig));
	if (pIterator.IsNull()) return Value::Null;
	return Value(new Object_iterator(env, pIterator.release()));
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

Gura_ImplementBinaryOperator(Add, rational, rational)
{
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a + b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Add, rational, number)
{
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a + b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Add, number, rational)
{
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a + b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
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
	DateTime dateTime = Object_datetime::GetObject(valueLeft)->GetDateTime();
	const TimeDelta &timeDelta = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	dateTime.Plus(timeDelta);
	return Value(new Object_datetime(env, dateTime));
}

Gura_ImplementBinaryOperator(Add, timedelta, datetime)
{
	const TimeDelta &timeDelta = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	DateTime dateTime = Object_datetime::GetObject(valueRight)->GetDateTime();
	dateTime.Plus(timeDelta);
	return Value(new Object_datetime(env, dateTime));
}

Gura_ImplementBinaryOperator(Add, timedelta, timedelta)
{
	TimeDelta td1 = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	TimeDelta td2 = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	return Value(new Object_timedelta(env, TimeDelta(
			td1.GetDays() + td2.GetDays(),
			td1.GetSecsRaw() + td2.GetSecsRaw(),
			td1.GetUSecs() + td2.GetUSecs())));
}

Gura_ImplementBinaryOperator(Add, string, string)
{
	String str(valueLeft.GetString());
	str += valueRight.GetString();
	return Value(str);
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
	str += valueRight.ToString();
	return Value(str);
}

Gura_ImplementBinaryOperator(Add, any, string)
{
	String str(valueLeft.ToString());
	str += valueRight.GetString();
	return Value(str);
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

Gura_ImplementBinaryOperator(Sub, rational, rational)
{
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a - b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Sub, rational, number)
{
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a - b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Sub, number, rational)
{
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a - b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
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
	DateTime dateTime = Object_datetime::GetObject(valueLeft)->GetDateTime();
	dateTime.Minus(Object_timedelta::GetObject(valueRight)->GetTimeDelta());
	return Value(new Object_datetime(env, dateTime));
}

Gura_ImplementBinaryOperator(Sub, datetime, datetime)
{
	const DateTime &dt1 = Object_datetime::GetObject(valueLeft)->GetDateTime();
	const DateTime &dt2 = Object_datetime::GetObject(valueRight)->GetDateTime();
	if ((dt1.HasTZOffset() && !dt2.HasTZOffset()) ||
								(!dt1.HasTZOffset() && dt2.HasTZOffset())) {
		sig.SetError(ERR_ValueError, "failed to calculate datetime difference");
		return Value::Null;
	}
	return Value(new Object_timedelta(env, dt1.Minus(dt2)));
}

Gura_ImplementBinaryOperator(Sub, timedelta, timedelta)
{
	TimeDelta td1 = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	TimeDelta td2 = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	return Value(new Object_timedelta(env, TimeDelta(
			td1.GetDays() - td2.GetDays(),
			td1.GetSecsRaw() - td2.GetSecsRaw(),
			td1.GetUSecs() - td2.GetUSecs())));
}

Gura_ImplementBinaryOperator(Sub, color, color)
{
	const Color &color1 = Object_color::GetObject(valueLeft)->GetColor();
	const Color &color2 = Object_color::GetObject(valueRight)->GetColor();
	return Value(::sqrt(static_cast<double>(color1.CalcDistSqu(color2))));
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

Gura_ImplementBinaryOperator(Mul, rational, rational)
{
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a * b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Mul, rational, number)
{
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a * b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Mul, number, rational)
{
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.denom == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a * b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
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
	const TimeDelta &td = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	long num = valueRight.GetLong();
	return Value(new Object_timedelta(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num)));
}

Gura_ImplementBinaryOperator(Mul, number, timedelta)
{
	const TimeDelta &td = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	long num = valueLeft.GetLong();
	return Value(new Object_timedelta(env,
		TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num)));
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
	return Value(str);
}

Gura_ImplementBinaryOperator(Mul, number, string)
{
	String str;
	for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
		str += valueRight.GetString();
	}
	return Value(str);
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
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(valueLeft.GetNumber() / numRight);
}

Gura_ImplementBinaryOperator(Div, complex, complex)
{
	Complex numRight = valueRight.GetComplex();
	if (numRight == Complex(0.)) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(valueLeft.GetComplex() / valueRight.GetComplex());
}

Gura_ImplementBinaryOperator(Div, rational, rational)
{
	const Rational &a = valueLeft.GetRational();
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.numer == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a / b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Div, rational, number)
{
	const Rational &a = valueLeft.GetRational();
	const Rational b = Rational::FromNumber(valueRight.GetNumber());
	if (a.denom == 0 || b.numer == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a / b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Div, number, rational)
{
	const Rational a = Rational::FromNumber(valueLeft.GetNumber());
	const Rational &b = valueRight.GetRational();
	if (a.denom == 0 || b.numer == 0) {
		Rational::SetError_DenominatorZero(sig);
		return Value::Null;
	}
	Rational c = a / b;
	if (c.numer == 0) return Value::Zero;
	return Value(c);
}

Gura_ImplementBinaryOperator(Div, number, complex)
{
	Complex numRight = valueRight.GetComplex();
	if (numRight == Complex(0.)) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(valueLeft.GetNumber() / numRight);
}

Gura_ImplementBinaryOperator(Div, complex, number)
{
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
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
	Number numRight = valueRight.GetNumber();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(::fmod(valueLeft.GetNumber(), numRight));
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
	int cmp = Value::Compare(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Null;
	return Value(cmp == 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Ne, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ne, any, any)
{
	int cmp = Value::Compare(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Null;
	return Value(cmp != 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Gt, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Gt, any, any)
{
	int cmp = Value::Compare(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Null;
	return Value(cmp > 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Lt, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Lt, any, any)
{
	int cmp = Value::Compare(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Null;
	return Value(cmp < 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Ge, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Ge, any, any)
{
	int cmp = Value::Compare(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Null;
	return Value(cmp >= 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Le, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Le, any, any)
{
	int cmp = Value::Compare(env, sig, valueLeft, valueRight);
	if (sig.IsSignalled()) return Value::Null;
	return Value(cmp <= 0);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Cmp, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Cmp, boolean, boolean)
{
	return Value(Value::CompareBoolean(valueLeft.GetBoolean(), valueRight.GetBoolean()));
}

Gura_ImplementBinaryOperator(Cmp, complex, complex)
{
	return Value(Value::CompareComplex(valueLeft.GetComplex(), valueRight.GetComplex()));
}

Gura_ImplementBinaryOperator(Cmp, number, number)
{
	return Value(Value::CompareNumber(valueLeft.GetNumber(), valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(Cmp, rational, rational)
{
	return Value(Value::CompareRational(valueLeft.GetRational(), valueRight.GetRational()));
}

Gura_ImplementBinaryOperator(Cmp, number, rational)
{
	const Rational &ratio = valueRight.GetRational();
	if (ratio.denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(Value::CompareNumber(valueLeft.GetNumber(), ratio.numer / ratio.denom));
}

Gura_ImplementBinaryOperator(Cmp, rational, number)
{
	const Rational &ratio = valueLeft.GetRational();
	if (ratio.denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	return Value(Value::CompareNumber(ratio.numer / ratio.denom, valueRight.GetNumber()));
}

Gura_ImplementBinaryOperator(Cmp, string, string)
{
	return Value(Value::CompareString(valueLeft.GetString(), valueRight.GetString(), false));
}

Gura_ImplementBinaryOperator(Cmp, symbol, symbol)
{
	return Value(Value::CompareSymbol(valueLeft.GetSymbol(), valueRight.GetSymbol()));
}

Gura_ImplementBinaryOperator(Cmp, binary, binary)
{
	const Binary &buff1 = valueLeft.GetBinary();
	const Binary &buff2 = valueRight.GetBinary();
	return
		(buff1.size() < buff2.size())? -1 :
		(buff1.size() > buff2.size())? +1 :
		::memcmp(buff1.data(), buff2.data(), buff1.size());
}

Gura_ImplementBinaryOperator(Cmp, datetime, datetime)
{
	const DateTime &dt1 = Object_datetime::GetObject(valueLeft)->GetDateTime();
	const DateTime &dt2 = Object_datetime::GetObject(valueRight)->GetDateTime();
	return DateTime::Compare(dt1, dt2);
}

Gura_ImplementBinaryOperator(Cmp, list, list)
{
	const ValueList &valList1 = valueLeft.GetList();
	const ValueList &valList2 = valueRight.GetList();
	if (valList1.size() < valList2.size()) return Value(-1);
	if (valList1.size() > valList2.size()) return Value(+1);
	ValueList::const_iterator pValue1 = valList1.begin();
	ValueList::const_iterator pValue2 = valList2.begin();
	for ( ; pValue1 != valList1.end(); pValue1++, pValue2++) {
		int cmp = Value::Compare(env, sig, *pValue1, *pValue2);
		if (sig.IsSignalled()) return Value::Null;
		if (cmp < 0) return Value(-1);
		if (cmp > 0) return Value(+1);
	}
	return Value(0);
}

Gura_ImplementBinaryOperator(Cmp, timedelta, timedelta)
{
	const TimeDelta &td1 = Object_timedelta::GetObject(valueLeft)->GetTimeDelta();
	const TimeDelta &td2 = Object_timedelta::GetObject(valueRight)->GetTimeDelta();
	return TimeDelta::Compare(td1, td2);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Contains, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Contains, any, any)
{
	if (valueLeft.Is_list() || valueLeft.Is_iterator()) {
		AutoPtr<Iterator_Contains> pIterator(new Iterator_Contains(valueLeft.CreateIterator(sig)));
		if (sig.IsSignalled()) return Value::Null;
		ValueList &valListToFind = pIterator->GetValueListToFind();
		if (valueRight.Is_list()) {
			valListToFind.Append(valueRight.GetList());
		} else if (valueRight.Is_iterator()) {
			AutoPtr<Iterator> pIteratorToFind(valueRight.CreateIterator(sig));
			if (pIteratorToFind.IsNull()) return Value::Null;
			valListToFind.Append(env, sig, pIteratorToFind.get());
			if (sig.IsSignalled()) return Value::Null;
		} else {
			valListToFind.push_back(valueRight);
		}
		if (valueLeft.Is_iterator()) {
			return Value(new Object_iterator(env, pIterator.release()));
		}
		return pIterator->ToList(env, sig, true, false);
	} else if (valueRight.Is_list()) {
		bool foundFlag = valueRight.GetList().DoesContain(env, sig, valueLeft);
		if (sig.IsSignalled()) return Value::Null;
		return Value(foundFlag);
	} else if (valueRight.Is_iterator()) {
		AutoPtr<Iterator> pIteratorToFind(valueRight.CreateIterator(sig));
		if (pIteratorToFind.IsNull()) return Value::Null;
		bool foundFlag = pIteratorToFind->DoesContain(env, sig, valueLeft);
		if (sig.IsSignalled()) return Value::Null;
		return Value(foundFlag);
	} else {
		int cmp = Value::Compare(env, sig, valueLeft, valueRight);
		if (sig.IsSignalled()) return Value::Null;
		return Value(cmp == 0);
	}
}

//-----------------------------------------------------------------------------
// BinaryOperator(And, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(And, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) &
						static_cast<ULong>(valueRight.GetNumber()));
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
// BinaryOperator(Xor, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Xor, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) ^
						static_cast<ULong>(valueRight.GetNumber()));
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
	return Value(static_cast<ULong>(valueLeft.GetNumber()) <<
							static_cast<ULong>(valueRight.GetNumber()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Shr, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shr, number, number)
{
	return Value(static_cast<ULong>(valueLeft.GetNumber()) >>
							static_cast<ULong>(valueRight.GetNumber()));
}

//-----------------------------------------------------------------------------
// BinaryOperator(OrOr, any, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(OrOr, any, any)
{
	if (valueLeft.GetBoolean()) return valueLeft;
	return valueRight;
}

//-----------------------------------------------------------------------------
// BinaryOperator(AndAnd, any, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(AndAnd, any, any)
{
	if (!valueLeft.GetBoolean()) return valueLeft;
	return valueRight;
}

//-----------------------------------------------------------------------------
// BinaryOperator(Seq, *, *)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Seq, number, number)
{
	Number numBegin = valueLeft.GetNumber();
	Number numEnd = valueRight.GetNumber();
	Number numStep = (numEnd >= numBegin)? +1 : -1;
	return Value(new Object_iterator(env, new Iterator_Sequence(numBegin, numEnd, numStep)));
}

//-----------------------------------------------------------------------------
// BinaryOperator(Pair, symbol, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pair, symbol, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Pair, string, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pair, string, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// BinaryOperator(Pair, number, any)
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Pair, number, any)
{
	return Value::CreateList(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// OperatorEntryCustom
//-----------------------------------------------------------------------------
Value OperatorEntryCustom::DoEval(Environment &env, Signal sig, const Value &value) const
{
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValue(value);
	return _pFunc->Eval(env, sig, *pArgs);
}

Value OperatorEntryCustom::DoEval(Environment &env, Signal sig,
					const Value &valueLeft, const Value &valueRight) const
{
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValues(valueLeft, valueRight);
	return _pFunc->Eval(env, sig, *pArgs);
}

//-----------------------------------------------------------------------------
// Operator assignment
//-----------------------------------------------------------------------------
void Operator::AssignOperators(Environment &env)
{
	env.SetOperator(OPTYPE_Pos,			new Operator_Pos());
	env.SetOperator(OPTYPE_Neg,			new Operator_Neg());
	env.SetOperator(OPTYPE_Inv,			new Operator_Inv());
	env.SetOperator(OPTYPE_Not,			new Operator_Not());
	env.SetOperator(OPTYPE_SeqInf,		new Operator_SeqInf());
	env.SetOperator(OPTYPE_Question,	new Operator_Question());
	env.SetOperator(OPTYPE_Each,		new Operator_Each());
	env.SetOperator(OPTYPE_Add,			new Operator_Add());
	env.SetOperator(OPTYPE_Sub,			new Operator_Sub());
	env.SetOperator(OPTYPE_Mul,			new Operator_Mul());
	env.SetOperator(OPTYPE_Div,			new Operator_Div());
	env.SetOperator(OPTYPE_Mod,			new Operator_Mod());
	env.SetOperator(OPTYPE_Pow,			new Operator_Pow());
	env.SetOperator(OPTYPE_Eq,			new Operator_Eq());
	env.SetOperator(OPTYPE_Ne,			new Operator_Ne());
	env.SetOperator(OPTYPE_Gt,			new Operator_Gt());
	env.SetOperator(OPTYPE_Lt,			new Operator_Lt());
	env.SetOperator(OPTYPE_Ge,			new Operator_Ge());
	env.SetOperator(OPTYPE_Le,			new Operator_Le());
	env.SetOperator(OPTYPE_Cmp,			new Operator_Cmp());
	env.SetOperator(OPTYPE_Contains,	new Operator_Contains());
	env.SetOperator(OPTYPE_And,			new Operator_And());
	env.SetOperator(OPTYPE_Or,			new Operator_Or());
	env.SetOperator(OPTYPE_Xor,			new Operator_Xor());
	env.SetOperator(OPTYPE_Shl,			new Operator_Shl());
	env.SetOperator(OPTYPE_Shr,			new Operator_Shr());
	env.SetOperator(OPTYPE_OrOr,		new Operator_OrOr());
	env.SetOperator(OPTYPE_AndAnd,		new Operator_AndAnd());
	env.SetOperator(OPTYPE_Seq,			new Operator_Seq());
	env.SetOperator(OPTYPE_Pair,		new Operator_Pair());
	Gura_AssignUnaryOperator(Pos, number);
	Gura_AssignUnaryOperator(Pos, complex);
	Gura_AssignUnaryOperator(Pos, rational);
	Gura_AssignUnaryOperator(Pos, matrix);
	Gura_AssignUnaryOperator(Pos, timedelta);
	Gura_AssignUnaryOperator(Neg, number);
	Gura_AssignUnaryOperator(Neg, complex);
	Gura_AssignUnaryOperator(Neg, rational);
	Gura_AssignUnaryOperator(Neg, matrix);
	Gura_AssignUnaryOperator(Neg, timedelta);
	Gura_AssignUnaryOperator(Inv, number);
	Gura_AssignUnaryOperator(Not, any);
	Gura_AssignUnaryOperatorSuffix(SeqInf, number);
	Gura_AssignUnaryOperatorSuffix(Question, any);
	Gura_AssignUnaryOperatorSuffix(Each, any);
	Gura_AssignBinaryOperator(Add, number, number);
	Gura_AssignBinaryOperator(Add, number, complex);
	Gura_AssignBinaryOperator(Add, number, rational);
	Gura_AssignBinaryOperator(Add, complex, number);
	Gura_AssignBinaryOperator(Add, complex, complex);
	Gura_AssignBinaryOperator(Add, rational, number);
	Gura_AssignBinaryOperator(Add, rational, rational);
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
	Gura_AssignBinaryOperator(Sub, number, complex);
	Gura_AssignBinaryOperator(Sub, number, rational);
	Gura_AssignBinaryOperator(Sub, complex, number);
	Gura_AssignBinaryOperator(Sub, complex, complex);
	Gura_AssignBinaryOperator(Sub, rational, number);
	Gura_AssignBinaryOperator(Sub, rational, rational);
	Gura_AssignBinaryOperator(Sub, matrix, matrix);
	Gura_AssignBinaryOperator(Sub, datetime, timedelta);
	Gura_AssignBinaryOperator(Sub, datetime, datetime);
	Gura_AssignBinaryOperator(Sub, timedelta, timedelta);
	Gura_AssignBinaryOperator(Sub, color, color);
	Gura_AssignBinaryOperator(Sub, pointer, number);
	Gura_AssignBinaryOperator(Sub, pointer, pointer);
	Gura_AssignBinaryOperator(Mul, number, number);
	Gura_AssignBinaryOperator(Mul, number, complex);
	Gura_AssignBinaryOperator(Mul, number, rational);
	Gura_AssignBinaryOperator(Mul, complex, number);
	Gura_AssignBinaryOperator(Mul, complex, complex);
	Gura_AssignBinaryOperator(Mul, rational, number);
	Gura_AssignBinaryOperator(Mul, rational, rational);
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
	Gura_AssignBinaryOperator(Div, number, complex);
	Gura_AssignBinaryOperator(Div, number, rational);
	Gura_AssignBinaryOperator(Div, complex, number);
	Gura_AssignBinaryOperator(Div, complex, complex);
	Gura_AssignBinaryOperator(Div, rational, number);
	Gura_AssignBinaryOperator(Div, rational, rational);
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
	Gura_AssignBinaryOperator(Cmp, boolean, boolean);
	Gura_AssignBinaryOperator(Cmp, complex, complex);
	Gura_AssignBinaryOperator(Cmp, number, number);
	Gura_AssignBinaryOperator(Cmp, rational, rational);
	Gura_AssignBinaryOperator(Cmp, number, rational);
	Gura_AssignBinaryOperator(Cmp, rational, number);
	Gura_AssignBinaryOperator(Cmp, string, string);
	Gura_AssignBinaryOperator(Cmp, symbol, symbol);
	Gura_AssignBinaryOperator(Cmp, binary, binary);
	Gura_AssignBinaryOperator(Cmp, datetime, datetime);
	Gura_AssignBinaryOperator(Cmp, list, list);
	Gura_AssignBinaryOperator(Cmp, timedelta, timedelta);
	Gura_AssignBinaryOperator(Contains, any, any);
	Gura_AssignBinaryOperator(And, number, number);
	Gura_AssignBinaryOperator(And, boolean, boolean);
	Gura_AssignBinaryOperator(And, nil, any);
	Gura_AssignBinaryOperator(And, any, nil);
	Gura_AssignBinaryOperator(Or, number, number);
	Gura_AssignBinaryOperator(Or, boolean, boolean);
	Gura_AssignBinaryOperator(Or, nil, any);
	Gura_AssignBinaryOperator(Or, any, nil);
	Gura_AssignBinaryOperator(Xor, number, number);
	Gura_AssignBinaryOperator(Xor, boolean, boolean);
	Gura_AssignBinaryOperator(Shl, number, number);
	Gura_AssignBinaryOperator(Shr, number, number);
	Gura_AssignBinaryOperator(OrOr, any, any);
	Gura_AssignBinaryOperator(AndAnd, any, any);
	Gura_AssignBinaryOperator(Seq, number, number);
	Gura_AssignBinaryOperator(Pair, symbol, any);
	Gura_AssignBinaryOperator(Pair, string, any);
	Gura_AssignBinaryOperator(Pair, number, any);
}

}
