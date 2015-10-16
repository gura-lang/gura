//=============================================================================
// Operator
//=============================================================================
#include "stdafx.h"
#include <math.h>

namespace Gura {

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
const Operator::SymbolInfo Operator::_symbolInfoTbl[] = {
	{ "",		"None"		},
	// unary operators
	{ "+",		"Pos"		},
	{ "-",		"Neg"		},
	{ "~",		"Inv"		},
	{ "!",		"Not"		},
	{ "..",		"SeqInf"	},
	{ "?",		"Question"	},
	{ "*",		"Each"		},
	// binary operators
	{ "+",		"Add"		},
	{ "-",		"Sub"		},
	{ "*",		"Mul"		},
	{ "/",		"Div"		},
	{ "%",		"Mod"		},
	{ "**",		"Pow"		},
	{ "==",		"Eq"		},
	{ "!=",		"Ne"		},
	{ ">",		"Gt"		},
	{ "<",		"Lt"		},
	{ ">=",		"Ge"		},
	{ "<=",		"Le"		},
	{ "<=>",	"Cmp"		},
	{ "in",		"Contains"	},
	{ "&",		"And"		},
	{ "|",		"Or"		},
	{ "^",		"Xor"		},
	{ "<<",		"Shl"		},
	{ ">>",		"Shr"		},
	{ "||",		"OrOr"		},
	{ "&&",		"AndAnd"	},
	{ "..",		"Seq"		},
	{ "=>",		"Pair"		},
};

Operator *Operator::Pos			= nullptr;
Operator *Operator::Neg			= nullptr;
Operator *Operator::Inv			= nullptr;
Operator *Operator::Not			= nullptr;
Operator *Operator::SeqInf		= nullptr;
Operator *Operator::Question	= nullptr;
Operator *Operator::Each		= nullptr;
Operator *Operator::Add			= nullptr;
Operator *Operator::Sub			= nullptr;
Operator *Operator::Mul			= nullptr;
Operator *Operator::Div			= nullptr;
Operator *Operator::Mod			= nullptr;
Operator *Operator::Pow			= nullptr;
Operator *Operator::Eq			= nullptr;
Operator *Operator::Ne			= nullptr;
Operator *Operator::Gt			= nullptr;
Operator *Operator::Lt			= nullptr;
Operator *Operator::Ge			= nullptr;
Operator *Operator::Le			= nullptr;
Operator *Operator::Cmp			= nullptr;
Operator *Operator::Contains	= nullptr;
Operator *Operator::And			= nullptr;
Operator *Operator::Or			= nullptr;
Operator *Operator::Xor			= nullptr;
Operator *Operator::Shl			= nullptr;
Operator *Operator::Shr			= nullptr;
Operator *Operator::OrOr		= nullptr;
Operator *Operator::AndAnd		= nullptr;
Operator *Operator::Seq			= nullptr;
Operator *Operator::Pair		= nullptr;

const OperatorEntry *Operator::Lookup(ValueType valType, bool suffixFlag) const
{
	EntryDict::const_iterator iter = _entryDict.find(CalcKey(valType, suffixFlag));
	if (iter != _entryDict.end()) return iter->second;
	iter = _entryDict.find(CalcKey(VTYPE_any, suffixFlag));
	if (iter != _entryDict.end()) return iter->second;
	return nullptr;
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
	return nullptr;
}

Expr *Operator::MathDiffUnary(Environment &env,
							const Expr *pExprChild, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	SetError_MathDiffError(sig);
	return nullptr;
}

Expr *Operator::MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	SetError_MathDiffError(sig);
	return nullptr;
}

Expr *Operator::MathOptimizeConst(Environment &env,
								Expr_Value *pExprChild, bool suffixFlag) const
{
	Signal &sig = env.GetSignal();
	Value value = pExprChild->GetValue();
	Expr::Delete(pExprChild);
	Value result = EvalUnary(env, value, suffixFlag);
	if (sig.IsSignalled()) return nullptr;
	return new Expr_Value(result);
}

Expr *Operator::MathOptimizeConst(Environment &env,
								Expr_Value *pExprLeft, Expr_Value *pExprRight) const
{
	Signal &sig = env.GetSignal();
	Value valueLeft = pExprLeft->GetValue();
	Value valueRight = pExprRight->GetValue();
	Expr::Delete(pExprLeft);
	Expr::Delete(pExprRight);
	Value result = EvalBinary(env, valueLeft, valueRight);
	if (sig.IsSignalled()) return nullptr;
	return new Expr_Value(result);
}

Expr *Operator::MathOptimizeUnary(Environment &env, Expr *pExprChild) const
{
	Signal &sig = env.GetSignal();
	SetError_MathOptimizeError(sig);
	return nullptr;
}

Expr *Operator::MathOptimizeBinary(Environment &env,
										Expr *pExprLeft, Expr *pExprRight) const
{
	Signal &sig = env.GetSignal();
	SetError_MathOptimizeError(sig);
	return nullptr;
}

Value Operator::EvalUnary(Environment &env, const Value &value, bool suffixFlag) const
{
	Signal &sig = env.GetSignal();
	const OperatorEntry *pOperatorEntry = Lookup(value.GetValueType(), suffixFlag);
	if (pOperatorEntry == nullptr) {
		SetError_InvalidValueType(sig, GetOpType(), value, suffixFlag);
		return Value::Nil;
	}
	return pOperatorEntry->DoEval(env, value);
}

Value Operator::EvalBinary(Environment &env, const Value &valueLeft, const Value &valueRight) const
{
	Signal &sig = env.GetSignal();
	const OperatorEntry *pOperatorEntry =
					Lookup(valueLeft.GetValueType(), valueRight.GetValueType());
	if (pOperatorEntry == nullptr) {
		SetError_InvalidValueType(sig, GetOpType(), valueLeft, valueRight);
		return Value::Nil;
	}
	return pOperatorEntry->DoEval(env, valueLeft, valueRight);
}

Value Operator::EvalMapUnary(Environment &env, const Value &value, bool suffixFlag) const
{
	if (!_mapFlag || !value.IsListOrIterator() || value.GetNoMapFlag()) {
		return EvalUnary(env, value, suffixFlag);
	}
	AutoPtr<Iterator> pIterator(new Iterator_UnaryOperatorMap(
							new Environment(env), this, value, suffixFlag));
	if (value.Is_iterator()) {
		return Value(new Object_iterator(env, pIterator.release()));
	}
	return pIterator->ToList(env, true, false);
}

Value Operator::EvalMapBinary(Environment &env,
							const Value &valueLeft, const Value &valueRight) const
{
	if (!_mapFlag || ((!valueLeft.IsListOrIterator() || valueLeft.GetNoMapFlag()) &&
				(!valueRight.IsListOrIterator() || valueRight.GetNoMapFlag()))) {
		return EvalBinary(env, valueLeft, valueRight);
	}
	AutoPtr<Iterator> pIterator(new Iterator_BinaryOperatorMap(new Environment(env),
									this, valueLeft, valueRight));
	if (valueLeft.Is_iterator() || valueRight.Is_iterator()) {
		return Value(new Object_iterator(env, pIterator.release()));
	}
	return pIterator->ToList(env, true, false);
}

OpType Operator::LookupUnaryOpType(const char *str)
{
	for (size_t i = OPTYPE_unary; i < OPTYPE_binary; i++) {
		if (::strcmp(_symbolInfoTbl[i].symbol, str) == 0) return static_cast<OpType>(i);
	}
	return OPTYPE_None;
}

OpType Operator::LookupBinaryOpType(const char *str)
{
	for (size_t i = OPTYPE_binary; i < OPTYPE_max; i++) {
		if (::strcmp(_symbolInfoTbl[i].symbol, str) == 0) return static_cast<OpType>(i);
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
					value.MakeValueTypeName().c_str(), GetSymbolInfo(opType).symbol);
	} else {
		sig.SetError(ERR_TypeError, "can't evaluate (%s %s)",
					GetSymbolInfo(opType).symbol, value.MakeValueTypeName().c_str());
	}
}

void Operator::SetError_InvalidValueType(Signal &sig, OpType opType,
						const Value &valueLeft, const Value &valueRight)
{
	sig.SetError(ERR_TypeError, "can't evaluate (%s %s %s)",
				 valueLeft.MakeValueTypeName().c_str(), GetSymbolInfo(opType).symbol,
				 valueRight.MakeValueTypeName().c_str());
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
Expr *Operator_Pos::MathOptimize(Environment &env, Expr *pExprChild)
{
	Signal &sig = env.GetSignal();
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return nullptr;
	}
	return pExprChild;
}

Expr *Operator_Pos::MathDiffUnary(Environment &env,
							const Expr *pExprChild, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExprDiff(pExprChild->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	return Operator_Pos::MathOptimize(env, pExprDiff.release());
}

Expr *Operator_Pos::MathOptimizeUnary(Environment &env, Expr *pExprChild) const
{
	return Operator_Pos::MathOptimize(env, pExprChild);
}

//-----------------------------------------------------------------------------
// Operator_Neg
//-----------------------------------------------------------------------------
Expr *Operator_Neg::MathDiffUnary(Environment &env,
							const Expr *pExprChild, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExprDiff(pExprChild->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	return Operator_Neg::MathOptimize(env, pExprDiff.release());
}

Expr *Operator_Neg::MathOptimizeUnary(Environment &env, Expr *pExprChild) const
{
	return Operator_Neg::MathOptimize(env, pExprChild);
}

Expr *Operator_Neg::MathOptimize(Environment &env, Expr *pExprChild)
{
	Signal &sig = env.GetSignal();
	if (sig.IsSignalled()) {
		Expr::Delete(pExprChild);
		return nullptr;
	}
	if (pExprChild->IsValue()) {
		bool suffixFlag = false;
		return env.GetOperator(OPTYPE_Neg)->MathOptimizeConst(env,
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
Expr *Operator_Add::MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	// (f(x) + g(x))' = f'(x) + g'(x)
	return Operator_Add::MathOptimize(
		env, pExprDiff1.release(), pExprDiff2.release());
}

Expr *Operator_Add::MathOptimizeBinary(Environment &env,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Add::MathOptimize(env, pExprLeft, pExprRight);
}

Expr *Operator_Add::MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight)
{
	Signal &sig = env.GetSignal();
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return nullptr;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v + v = v
		return env.GetOperator(OPTYPE_Add)->MathOptimizeConst(env,
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
		return Operator_Sub::MathOptimize(env, pExprLeft, pExpr);
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsIdentifier()) {
		// n + n = n * 2
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Operator_Mul::MathOptimize(env, pExprLeft, new Expr_Value(2));
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
					env,
					pExprLeft,
					Operator_Add::MathOptimize(env, new Expr_Value(1), pExprMulR));
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
					env,
					pExprRight,
					Operator_Add::MathOptimize(env, pExprMulL, new Expr_Value(1)));
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
					env,
					pExprBase,
					Operator_Add::MathOptimize(env, pExprMulL, pExprMulR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Sub
//-----------------------------------------------------------------------------
Expr *Operator_Sub::MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	// (f(x) - g(x))' = f'(x) - g'(x)
	return Operator_Sub::MathOptimize(
		env, pExprDiff1.release(), pExprDiff2.release());
}

Expr *Operator_Sub::MathOptimizeBinary(Environment &env,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Sub::MathOptimize(env, pExprLeft, pExprRight);
}

Expr *Operator_Sub::MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight)
{
	Signal &sig = env.GetSignal();
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return nullptr;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v - v = v
		return env.GetOperator(OPTYPE_Sub)->MathOptimizeConst(env,
					dynamic_cast<Expr_Value *>(pExprLeft),
					dynamic_cast<Expr_Value *>(pExprRight));
	} else if (pExprLeft->IsConstNumber(0)) {
		// 0 - m = -m
		Expr::Delete(pExprLeft);
		return Operator_Neg::MathOptimize(env, pExprRight);
	} else if (pExprRight->IsConstNumber(0)) {
		// n - 0 = n
		Expr::Delete(pExprRight);
		return pExprLeft;
	} else if (pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// n - (-m) = n + m
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprRight);
		return Operator_Add::MathOptimize(env, pExprLeft, pExpr);
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
					env,
					pExprLeft,
					Operator_Sub::MathOptimize(env, new Expr_Value(1), pExprMulR));
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
					env,
					pExprRight,
					Operator_Sub::MathOptimize(env, pExprMulL, new Expr_Value(1)));
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
					env,
					pExprBase,
					Operator_Sub::MathOptimize(env, pExprMulL, pExprMulR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Sub), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Mul
//-----------------------------------------------------------------------------
Value Operator_Mul::EvalMapBinary(Environment &env,
							const Value &valueLeft, const Value &valueRight) const
{
	Signal &sig = env.GetSignal();
	if (valueLeft.Is_function() || valueLeft.IsClass()) {
		const Function *pFunc = nullptr;
		Value valueThis;
		if (valueLeft.Is_function()) {
			pFunc = valueLeft.GetFunction();
			valueThis = Object_function::GetObject(valueLeft)->GetValueThis();
		} else { // valueLeft.IsClass()
			Class *pClass = valueLeft.GetClassItself();
			pFunc = pClass->GetConstructor();
			if (pFunc == nullptr) {
				pClass->SetError_NoConstructor();
				return Value::Nil;
			}
		}
		if (pFunc->IsUnary()) {
			// nothing to do
		} else if (valueRight.Is_list()) {
			const ValueList &valList = valueRight.GetList();
			if (valList.IsFlat()) {
				AutoPtr<Argument> pArgSub(new Argument(pFunc));
				if (!pArgSub->StoreValues(env, valList)) return Value::Nil;
				if (!pArgSub->Complete(env)) return Value::Nil;
				return pFunc->Eval(env, *pArgSub);
			}
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Nil;
			AutoPtr<Iterator> pIteratorFuncBinder(
				new Iterator_FuncBinder(
					new Environment(env), Function::Reference(pFunc),
					valueThis, pIterator.release()));
			ResultComposer resultComposer(env, pFunc);
			resultComposer.AddValues(env, pIteratorFuncBinder.get());
			return resultComposer.GetValueResult();
		} else if (valueRight.Is_iterator()) {
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Nil;
			AutoPtr<Iterator> pIteratorFuncBinder(
				new Iterator_FuncBinder(
					new Environment(env), Function::Reference(pFunc),
					valueThis, pIterator.release()));
			if (pFunc->IsResultNormal() ||
						pFunc->IsResultIterator() || pFunc->IsResultXIterator()) {
				return Value(new Object_iterator(env, pIteratorFuncBinder.release()));
			} else {
				ResultComposer resultComposer(env, pFunc);
				resultComposer.AddValues(env, pIteratorFuncBinder.get());
				return resultComposer.GetValueResult();
			}
		}
	} else if ((valueLeft.Is_matrix() && valueRight.Is_list()) ||
			   (valueLeft.Is_list() && valueRight.Is_matrix())) {
		return EvalBinary(env, valueLeft, valueRight);
	}
	return Operator::EvalMapBinary(env, valueLeft, valueRight);
}

Expr *Operator_Mul::MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	// (f(x)g(x))' = f'(x)g(x) + f(x)g'(x)
	return Operator_Add::MathOptimize(
		env,
		Operator_Mul::MathOptimize(
			env, pExprDiff1.release(), pExprRight->Clone()),
		Operator_Mul::MathOptimize(
			env, pExprLeft->Clone(), pExprDiff2.release()));
}

Expr *Operator_Mul::MathOptimizeBinary(Environment &env,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Mul::MathOptimize(env, pExprLeft, pExprRight);
}

Expr *Operator_Mul::MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight)
{
	Signal &sig = env.GetSignal();
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return nullptr;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v * v = v
		return env.GetOperator(OPTYPE_Mul)->MathOptimizeConst(env,
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
		return Operator_Neg::MathOptimize(env, pExprRight);
	} else if (pExprRight->IsConstNumber(-1)) {
		// n * (-1) = -n
		Expr::Delete(pExprRight);
		return Operator_Neg::MathOptimize(env, pExprLeft);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg) && pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) * (-m) = n * m
		Expr *pExpr1 =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr *pExpr2 =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Operator_Mul::MathOptimize(env, pExpr1, pExpr2);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) * m = -(n * m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Neg::MathOptimize(
			env,
			Operator_Mul::MathOptimize(env, pExpr, pExprRight));
	} else if (pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// n * (-m) = -(n * m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprRight);
		return Operator_Neg::MathOptimize(
			env,
			Operator_Mul::MathOptimize(env, pExprLeft, pExpr));
	} else if (pExprLeft->IsIdentifier() && pExprRight->IsIdentifier()) {
		// n * n = n ** 2
		const Expr_Identifier *pExprIdentifierL =
							dynamic_cast<const Expr_Identifier *>(pExprLeft);
		const Expr_Identifier *pExprIdentifierR =
							dynamic_cast<const Expr_Identifier *>(pExprRight);
		if (pExprIdentifierL->GetSymbol()->IsIdentical(pExprIdentifierR->GetSymbol())) {
			Expr::Delete(pExprRight);
			return Operator_Pow::MathOptimize(env, pExprLeft, new Expr_Value(2));
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
					env,
					pExprLeft,
					Operator_Add::MathOptimize(env, pExprPowR, new Expr_Value(1)));
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
			env,
			Operator_Mul::MathOptimize(env, pExprLeftL, pExprRight),
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
					env,
					pExprRight,
					Operator_Add::MathOptimize(env, pExprPowL, new Expr_Value(1)));
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
					env,
					pExprBase,
					Operator_Add::MathOptimize(env, pExprPowL, pExprPowR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Div
//-----------------------------------------------------------------------------
Expr *Operator_Div::MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	// (f(x) / g(x))' = (f'(x)g(x) - f(x)g'(x)) / {g(x)}^2
	return Operator_Div::MathOptimize(
		env,
		Operator_Sub::MathOptimize(
			env,
			Operator_Mul::MathOptimize(
				env, pExprDiff1.release(), pExprRight->Clone()),
			Operator_Mul::MathOptimize(
				env, pExprLeft->Clone(), pExprDiff2.release())),
		Operator_Pow::MathOptimize(
			env, pExprRight->Clone(), new Expr_Value(2)));
}

Expr *Operator_Div::MathOptimizeBinary(Environment &env,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Div::MathOptimize(env, pExprLeft, pExprRight);
}

Expr *Operator_Div::MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight)
{
	Signal &sig = env.GetSignal();
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return nullptr;
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
		return Operator_Neg::MathOptimize(env, pExprLeft);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg) && pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) / (-m) = n / m
		Expr *pExpr1 =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr *pExpr2 =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Operator_Div::MathOptimize(env, pExpr1, pExpr2);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg)) {
		// (-n) / m = -(n / m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Neg::MathOptimize(
			env,
			Operator_Div::MathOptimize(env, pExpr, pExprRight));
	} else if (pExprRight->IsUnaryOp(OPTYPE_Neg)) {
		// n / (-m) = -(n / m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->Clone();
		Expr::Delete(pExprRight);
		return Operator_Neg::MathOptimize(
			env,
			Operator_Div::MathOptimize(env, pExprLeft, pExpr));
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
					env,
					pExprLeft,
					Operator_Sub::MathOptimize(env, new Expr_Value(1), pExprPowR));
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
					env,
					pExprRight,
					Operator_Sub::MathOptimize(env, pExprPowL, new Expr_Value(1)));
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
					env,
					pExprBase,
					Operator_Sub::MathOptimize(env, pExprPowL, pExprPowR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), pExprLeft, pExprRight);
}

//-----------------------------------------------------------------------------
// Operator_Mod
//-----------------------------------------------------------------------------
Value Operator_Mod::EvalMapBinary(Environment &env,
							const Value &valueLeft, const Value &valueRight) const
{
	Signal &sig = env.GetSignal();
	if (valueLeft.Is_function() || valueLeft.IsClass()) {
		const Function *pFunc = nullptr;
		Value valueThis;
		if (valueLeft.Is_function()) {
			pFunc = valueLeft.GetFunction();
			valueThis = Object_function::GetObject(valueLeft)->GetValueThis();
		} else { // valueLeft.IsClass()
			Class *pClass = valueLeft.GetClassItself();
			pFunc = pClass->GetConstructor();
			if (pFunc == nullptr) {
				pClass->SetError_NoConstructor();
				return Value::Nil;
			}
		}
		AutoPtr<Argument> pArgSub(new Argument(pFunc));
		pArgSub->SetValueThis(valueThis);
		if (!valueRight.Is_list() || pFunc->IsUnary()) {
			if (!pArgSub->StoreValue(env, valueRight)) return Value::Nil;
		} else {
			if (!pArgSub->StoreValues(env, valueRight.GetList())) return Value::Nil;
		}
		return pFunc->EvalAuto(env, *pArgSub);
	} else if (valueLeft.Is_string()) {
		const char *format = valueLeft.GetString();
		if (!valueRight.Is_list()) {
			String str = Formatter::FormatValueList(sig, format, ValueList(valueRight));
			if (sig.IsSignalled()) return Value::Nil;
			return Value(str);
		} else {
			const ValueList &valList = valueRight.GetList();
			if (valList.IsFlat() && !valList.DoesContainIterator()) {
				String str = Formatter::FormatValueList(sig, format, valList);
				if (sig.IsSignalled()) return Value::Nil;
				return Value(str);
			} else {
				IteratorOwner iterOwner;
				foreach_const (ValueList, pValue, valList) {
					AutoPtr<Iterator> pIterator;
					if (pValue->Is_list() || pValue->Is_iterator()) {
						pIterator.reset(pValue->CreateIterator(sig));
						if (pIterator.IsNull()) return Value::Nil;
					} else {
						pIterator.reset(new Iterator_Constant(*pValue));
					}
					iterOwner.push_back(pIterator.release());
				}
				return Formatter::FormatIterator(env, format, iterOwner);
			}
		}
	}
	return Operator::EvalMapBinary(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// Operator_Pow
//-----------------------------------------------------------------------------
Expr *Operator_Pow::MathDiffBinary(Environment &env,
		const Expr *pExprLeft, const Expr *pExprRight, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExprDiff1(pExprLeft->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	AutoPtr<Expr> pExprDiff2(pExprRight->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	// (f(x) ** g(x))' = f'(x)g(x)(f(x) ** (g(x) - 1)) + g'(x)log(f(x))(f(x) ** g(x))
	return Operator_Add::MathOptimize(
		env,
		Operator_Mul::MathOptimize(
			env,
			Operator_Mul::MathOptimize(
				env, pExprDiff1.release(), pExprRight->Clone()),
			Operator_Pow::MathOptimize(
				env,
				pExprLeft->Clone(),
				Operator_Sub::MathOptimize(
					env, pExprRight->Clone(), new Expr_Value(1)))),
		Operator_Mul::MathOptimize(
			env,
			Operator_Mul::MathOptimize(
				env,
				pExprDiff2.release(),
				Expr_Caller::Create(
					Gura_Symbol(math), Gura_Symbol(log), pExprLeft->Clone())),
			Operator_Pow::MathOptimize(
				env, pExprLeft->Clone(), pExprRight->Clone())));
}

Expr *Operator_Pow::MathOptimizeBinary(Environment &env,
									Expr *pExprLeft, Expr *pExprRight) const
{
	return Operator_Pow::MathOptimize(env, pExprLeft, pExprRight);
}

Expr *Operator_Pow::MathOptimize(Environment &env, Expr *pExprLeft, Expr *pExprRight)
{
	Signal &sig = env.GetSignal();
	if (sig.IsSignalled()) {
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return nullptr;
	}
	if (pExprLeft->IsValue() && pExprRight->IsValue()) {
		// v ** v = v
		return env.GetOperator(OPTYPE_Pow)->MathOptimizeConst(env,
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
		return Operator_Div::MathOptimize(env, new Expr_Value(1), pExprLeft);
	} else if (pExprLeft->IsUnaryOp(OPTYPE_Neg) && pExprRight->IsConstEvenNumber()) {
		// (-n) ** (2m) = n ** (2m)
		Expr *pExpr = dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Pow::MathOptimize(env, pExpr, pExprRight);
	} else if (pExprLeft->IsBinaryOp(OPTYPE_Pow)) {
		// n ** m ** l = n ** (m * l)
		const Expr_BinaryOp *pExprBinOpL =
							dynamic_cast<const Expr_BinaryOp *>(pExprLeft);
		Expr *pExprLeftL = pExprBinOpL->GetLeft()->Clone();
		Expr *pExprLeftR = pExprBinOpL->GetRight()->Clone();
		Expr::Delete(pExprLeft);
		return Operator_Pow::MathOptimize(
			env,
			pExprLeftL,
			Operator_Mul::MathOptimize(env, pExprLeftR, pExprRight));
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
Value Operator_Contains::EvalMapBinary(Environment &env,
							const Value &valueLeft, const Value &valueRight) const
{
	return EvalBinary(env, valueLeft, valueRight);
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
Value Operator_Pair::EvalMapBinary(Environment &env,
							const Value &valueLeft, const Value &valueRight) const
{
	return EvalBinary(env, valueLeft, valueRight);
}

//-----------------------------------------------------------------------------
// OperatorEntry
//-----------------------------------------------------------------------------
OperatorEntry::~OperatorEntry()
{
}

Value OperatorEntry::DoEval(Environment &env, const Value &value) const
{
	return Value::Nil;
}

Value OperatorEntry::DoEval(Environment &env,
				const Value &valueLeft, const Value &valueRight) const
{
	return Value::Nil;
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
// Operator initialization
//-----------------------------------------------------------------------------
void Operator::Initialize(Environment &env)
{
	env.SetOperator(OPTYPE_Pos,			Operator::Pos		= new Operator_Pos());
	env.SetOperator(OPTYPE_Neg,			Operator::Neg		= new Operator_Neg());
	env.SetOperator(OPTYPE_Inv,			Operator::Inv		= new Operator_Inv());
	env.SetOperator(OPTYPE_Not,			Operator::Not		= new Operator_Not());
	env.SetOperator(OPTYPE_SeqInf,		Operator::SeqInf	= new Operator_SeqInf());
	env.SetOperator(OPTYPE_Question,	Operator::Question	= new Operator_Question());
	env.SetOperator(OPTYPE_Each,		Operator::Each		= new Operator_Each());
	env.SetOperator(OPTYPE_Add,			Operator::Add		= new Operator_Add());
	env.SetOperator(OPTYPE_Sub,			Operator::Sub		= new Operator_Sub());
	env.SetOperator(OPTYPE_Mul,			Operator::Mul		= new Operator_Mul());
	env.SetOperator(OPTYPE_Div,			Operator::Div		= new Operator_Div());
	env.SetOperator(OPTYPE_Mod,			Operator::Mod		= new Operator_Mod());
	env.SetOperator(OPTYPE_Pow,			Operator::Pow		= new Operator_Pow());
	env.SetOperator(OPTYPE_Eq,			Operator::Eq		= new Operator_Eq());
	env.SetOperator(OPTYPE_Ne,			Operator::Ne		= new Operator_Ne());
	env.SetOperator(OPTYPE_Gt,			Operator::Gt		= new Operator_Gt());
	env.SetOperator(OPTYPE_Lt,			Operator::Lt		= new Operator_Lt());
	env.SetOperator(OPTYPE_Ge,			Operator::Ge		= new Operator_Ge());
	env.SetOperator(OPTYPE_Le,			Operator::Le		= new Operator_Le());
	env.SetOperator(OPTYPE_Cmp,			Operator::Cmp		= new Operator_Cmp());
	env.SetOperator(OPTYPE_Contains,	Operator::Contains	= new Operator_Contains());
	env.SetOperator(OPTYPE_And,			Operator::And		= new Operator_And());
	env.SetOperator(OPTYPE_Or,			Operator::Or		= new Operator_Or());
	env.SetOperator(OPTYPE_Xor,			Operator::Xor		= new Operator_Xor());
	env.SetOperator(OPTYPE_Shl,			Operator::Shl		= new Operator_Shl());
	env.SetOperator(OPTYPE_Shr,			Operator::Shr		= new Operator_Shr());
	env.SetOperator(OPTYPE_OrOr,		Operator::OrOr		= new Operator_OrOr());
	env.SetOperator(OPTYPE_AndAnd,		Operator::AndAnd	= new Operator_AndAnd());
	env.SetOperator(OPTYPE_Seq,			Operator::Seq		= new Operator_Seq());
	env.SetOperator(OPTYPE_Pair,		Operator::Pair		= new Operator_Pair());
}

}
