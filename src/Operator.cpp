#include "stdafx.h"

namespace Gura {

static Expr *OptimizeConst(Environment &env, Signal sig,
						const Function &func, Expr *pExprChild);
static Expr *OptimizeConst(Environment &env, Signal sig,
						const Function &func, Expr *pExprLeft, Expr *pExprRight);

//-----------------------------------------------------------------------------
// Operator assignment
//-----------------------------------------------------------------------------
void AssignOperators(Environment &env)
{
	Environment::Global *pGlobal = env.GetGlobal();
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Pos		= new Func_Pos(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Neg		= new Func_Neg(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Invert	= new Func_Invert(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Not		= new Func_Not(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Plus		= new Func_Plus(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Minus	= new Func_Minus(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Multiply	= new Func_Multiply(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Divide	= new Func_Divide(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Modulo	= new Func_Modulo(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_format	= new Func_format(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Power	= new Func_Power(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Equal	= new Func_Equal(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_NotEqual	= new Func_NotEqual(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Greater	= new Func_Greater(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Less		= new Func_Less(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_GreaterEq= new Func_GreaterEq(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_LessEq	= new Func_LessEq(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Compare	= new Func_Compare(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_ContainCheck= new Func_ContainCheck(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Or		= new Func_Or(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_And		= new Func_And(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Xor		= new Func_Xor(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_ShiftL	= new Func_ShiftL(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_ShiftR	= new Func_ShiftR(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_OrOr		= new Func_OrOr(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_AndAnd	= new Func_AndAnd(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_Sequence	= new Func_Sequence(env)));
	env.AssignFunction(Function::Reference(pGlobal->_pFunc_SequenceInf = new Func_SequenceInf(env)));
}

//-----------------------------------------------------------------------------
// basic operator
//-----------------------------------------------------------------------------
// +n
bool Func_Pos::IsPos() const { return true; }

Func_Pos::Func_Pos(Environment &env) :
			Function(env, Symbol::Add("__pos__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Plus, "+");	// revise this later
	DeclareArg(env, "n", VTYPE_any);
}

Value Func_Pos::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &value = args.GetValue(0);
	if (value.IsNumber()) {
		return value;
	} else if (value.IsComplex()) {
		return value;
	} else if (value.IsMatrix()) {
		return value;
	} else {
		bool evaluatedFlag = false;
		Value result = EvalOverrideUnary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValType(sig, value);
	return Value::Null;
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

// -n
bool Func_Neg::IsNeg() const { return true; }

Func_Neg::Func_Neg(Environment &env) :
			Function(env, Symbol::Add("__neg__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Minus, "-");	// revise this later
	DeclareArg(env, "n", VTYPE_any);
}

Value Func_Neg::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(-value.GetNumber());
		return result;
	} else if (value.IsComplex()) {
		result.SetComplex(-value.GetComplex());
		return result;
	} else if (value.IsMatrix()) {
		return Object_matrix::OperatorNeg(env, sig, value.GetMatrixObj());
	} else if (value.IsTimeDelta()) {
		TimeDelta td = value.GetTimeDelta();
		return Value(env, TimeDelta(-td.GetDays(), -td.GetSecsRaw(), -td.GetUSecs()));
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideUnary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValType(sig, value);
	return result;
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
		return OptimizeConst(env, sig, env.GetFunc_Neg(), pExprChild);
	} else if (pExprChild->IsOperatorNeg()) {
		// -(-n) = n
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprChild)->GetChild()->IncRef();
		Expr::Delete(pExprChild);
		return pExpr;
	} else {
		return new Expr_UnaryOp(env.GetFunc_Neg(), pExprChild, false);
	}
}

// ~x
Func_Invert::Func_Invert(Environment &env) :
			Function(env, Symbol::Add("__invert__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Invert, "~");
	DeclareArg(env, "n", VTYPE_any);
}

Value Func_Invert::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		unsigned long num = ~static_cast<unsigned long>(value.GetNumber());
		result.SetNumber(static_cast<Number>(num));
		return result;
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideUnary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValType(sig, value);
	return result;
}

// !n
Func_Not::Func_Not(Environment &env) :
			Function(env, Symbol::Add("__not__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Not, "!");
	DeclareArg(env, "flag", VTYPE_any);
}

Value Func_Not::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	do {
		bool evaluatedFlag = false;
		result = EvalOverrideUnary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	result.SetBoolean(!args.GetBoolean(0));
	return result;
}

// n + m
bool Func_Plus::IsPlus() const { return true; }

Func_Plus::Func_Plus(Environment &env) :
			Function(env, Symbol::Add("__add__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Plus, "+");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Plus::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		result.SetNumber(valueLeft.GetNumber() + valueRight.GetNumber());
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsComplex()) {
		result.SetComplex(valueLeft.GetComplex() + valueRight.GetComplex());
		return result;
	} else if (valueLeft.IsNumber() && valueRight.IsComplex()) {
		result.SetComplex(valueLeft.GetNumber() + valueRight.GetComplex());
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsNumber()) {
		result.SetComplex(valueLeft.GetComplex() + valueRight.GetNumber());
		return result;
	} else if (valueLeft.IsMatrix() && valueRight.IsMatrix()) {
		return Object_matrix::OperatorPlusMinus(env, sig, env.GetFunc_Plus(),
						valueLeft.GetMatrixObj(), valueRight.GetMatrixObj());
	} else if (valueLeft.IsDateTime() && valueRight.IsTimeDelta()) {
		DateTime dateTime = valueLeft.GetDateTime();
		dateTime.Plus(valueRight.GetTimeDelta());
		return Value(env, dateTime);
	} else if (valueLeft.IsTimeDelta() && valueRight.IsDateTime()) {
		DateTime dateTime = valueRight.GetDateTime();
		dateTime.Plus(valueLeft.GetTimeDelta());
		return Value(env, dateTime);
	} else if (valueLeft.IsTimeDelta() && valueRight.IsTimeDelta()) {
		TimeDelta td1 = valueLeft.GetTimeDelta();
		TimeDelta td2 = valueRight.GetTimeDelta();
		return Value(env, TimeDelta(
				td1.GetDays() + td2.GetDays(),
				td1.GetSecsRaw() + td2.GetSecsRaw(),
				td1.GetUSecs() + td2.GetUSecs()));
	} else if (valueLeft.IsString() && valueRight.IsString()) {
		String str(valueLeft.GetString());
		str += valueRight.GetString();
		result = Value(env, str.c_str());
		return result;
	} else if (valueLeft.IsBinary() && valueRight.IsBinary()) {
		Binary buff(valueLeft.GetBinary());
		buff += valueRight.GetBinary();
		result.InitAsBinary(env, buff, true);
		return result;
	} else if (valueLeft.IsBinary() && valueRight.IsString()) {
		Binary buff(valueLeft.GetBinary());
		buff += valueRight.GetString();
		result.InitAsBinary(env, buff, true);
		return result;
	} else if (valueLeft.IsString() && valueRight.IsBinary()) {
		Binary buff;
		buff += valueLeft.GetString();
		buff += valueRight.GetBinary();
		result.InitAsBinary(env, buff, true);
		return result;
	} else if (valueLeft.IsBinaryPtr() && valueRight.IsNumber()) {
		Object_binaryptr *pObj =
			dynamic_cast<Object_binaryptr *>(valueLeft.GetBinaryPtr()->Clone());
		pObj->UnpackForward(sig,
							static_cast<int>(valueRight.GetNumber()), true);
		if (sig.IsSignalled()) return Value::Null;
		Value result;
		result.InitAsObject(pObj);
		return result;
	} else if (valueLeft.IsString()) {
		String str(valueLeft.GetString());
		str += valueRight.ToString(sig);
		result = Value(env, str.c_str());
		return result;
	} else if (valueRight.IsString()) {
		String str(valueLeft.ToString(sig));
		str += valueRight.GetString();
		result = Value(env, str.c_str());
		return result;
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return Value::Null;
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
		return OptimizeConst(env, sig, env.GetFunc_Plus(), pExprLeft, pExprRight);
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
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->IncRef();
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
				Expr *pExprMultiplyR = pExprBinOpR->GetRight()->IncRef();
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
				Expr *pExprMultiplyL = pExprBinOpL->GetRight()->IncRef();
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
				Expr *pExprBase = pExprBinOpL->GetLeft()->IncRef();
				Expr *pExprMultiplyL = pExprBinOpL->GetRight()->IncRef();
				Expr *pExprMultiplyR = pExprBinOpR->GetRight()->IncRef();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Multiply::OptimizedExpr(env, sig, pExprBase,
					Func_Plus::OptimizedExpr(env, sig, pExprMultiplyL, pExprMultiplyR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetFunc_Plus(), pExprLeft, pExprRight);
}

// n - m
bool Func_Minus::IsMinus() const { return true; }

Func_Minus::Func_Minus(Environment &env) :
			Function(env, Symbol::Add("__sub__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Minus, "-");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Minus::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		result.SetNumber(valueLeft.GetNumber() - valueRight.GetNumber());
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsComplex()) {
		result.SetComplex(valueLeft.GetComplex() - valueRight.GetComplex());
		return result;
	} else if (valueLeft.IsNumber() && valueRight.IsComplex()) {
		result.SetComplex(valueLeft.GetNumber() - valueRight.GetComplex());
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsNumber()) {
		result.SetComplex(valueLeft.GetComplex() - valueRight.GetNumber());
		return result;
	} else if (valueLeft.IsMatrix() && valueRight.IsMatrix()) {
		return Object_matrix::OperatorPlusMinus(env, sig, env.GetFunc_Minus(),
						valueLeft.GetMatrixObj(), valueRight.GetMatrixObj());
	} else if (valueLeft.IsDateTime() && valueRight.IsTimeDelta()) {
		DateTime dateTime = valueLeft.GetDateTime();
		dateTime.Minus(valueRight.GetTimeDelta());
		return Value(env, dateTime);
	} else if (valueLeft.IsDateTime() && valueRight.IsDateTime()) {
		const DateTime &dt1 = valueLeft.GetDateTime();
		const DateTime &dt2 = valueRight.GetDateTime();
		if ((dt1.HasTZOffset() && !dt2.HasTZOffset()) ||
									(!dt1.HasTZOffset() && dt2.HasTZOffset())) {
			sig.SetError(ERR_ValueError, "failed to calculate datetime difference");
			return Value::Null;
		}
		return Value(env, dt1.Minus(dt2));
	} else if (valueLeft.IsTimeDelta() && valueRight.IsTimeDelta()) {
		TimeDelta td1 = valueLeft.GetTimeDelta();
		TimeDelta td2 = valueRight.GetTimeDelta();
		return Value(env, TimeDelta(
				td1.GetDays() - td2.GetDays(),
				td1.GetSecsRaw() - td2.GetSecsRaw(),
				td1.GetUSecs() - td2.GetUSecs()));
	} else if (valueLeft.IsColor() && valueRight.IsColor()) {
		const Color &color1 = valueLeft.GetColorObj()->GetColor();
		const Color &color2 = valueRight.GetColorObj()->GetColor();
		return Value(::sqrt(static_cast<double>(color1.CalcDist(color2))));
	} else if (valueLeft.IsBinaryPtr() && valueRight.IsNumber()) {
		Object_binaryptr *pObj =
			dynamic_cast<Object_binaryptr *>(valueLeft.GetBinaryPtr()->Clone());
		pObj->UnpackForward(sig,
							-static_cast<int>(valueRight.GetNumber()), true);
		if (sig.IsSignalled()) return Value::Null;
		Value result;
		result.InitAsObject(pObj);
		return result;
	} else if (valueLeft.IsBinaryPtr() && valueRight.IsBinaryPtr()) {
		const Object_binaryptr *pObj1 = valueLeft.GetBinaryPtr();
		const Object_binaryptr *pObj2 = valueRight.GetBinaryPtr();
		if (&pObj1->GetBinary() != &pObj2->GetBinary()) {
			sig.SetError(ERR_ValueError,
				"cannot calculate difference between pointers of different binaries");
			return Value::Null;
		}
		int offset1 = static_cast<int>(pObj1->GetOffset());
		int offset2 = static_cast<int>(pObj2->GetOffset());
		return Value(static_cast<Number>(offset1 - offset2));
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
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
		return OptimizeConst(env, sig, env.GetFunc_Minus(), pExprLeft, pExprRight);
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
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->IncRef();
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
				Expr *pExprMultiplyR = pExprBinOpR->GetRight()->IncRef();
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
				Expr *pExprMultiplyL = pExprBinOpL->GetRight()->IncRef();
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
				Expr *pExprBase = pExprBinOpL->GetLeft()->IncRef();
				Expr *pExprMultiplyL = pExprBinOpL->GetRight()->IncRef();
				Expr *pExprMultiplyR = pExprBinOpR->GetRight()->IncRef();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Multiply::OptimizedExpr(env, sig, pExprBase,
					Func_Minus::OptimizedExpr(env, sig, pExprMultiplyL, pExprMultiplyR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetFunc_Minus(), pExprLeft, pExprRight);
}

// n * m
bool Func_Multiply::IsMultiply() const { return true; }

Func_Multiply::Func_Multiply(Environment &env) :
			Function(env, Symbol::Add("__mul__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Multiply, "*");
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
				const Function *pFuncSuccRequester = NULL;
				Args argsSub(valListComp, Value::Null, NULL, false, &pFuncSuccRequester);
				return pFunc->Eval(env, sig, argsSub);
			}
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			AutoPtr<Iterator> pIteratorFuncBinder(new Iterator_FuncBinder(env,
						Function::Reference(pFunc),
						valueLeft.GetFunctionObj()->GetSelf(), pIterator.release()));
			return pIteratorFuncBinder->Eval(env, sig, argsSub);
		} else if (valueRight.IsIterator()) {
			AutoPtr<Iterator> pIterator(valueRight.CreateIterator(sig));
			if (sig.IsSignalled()) return Value::Null;
			AutoPtr<Iterator> pIteratorFuncBinder(new Iterator_FuncBinder(env,
						Function::Reference(pFunc),
						valueLeft.GetFunctionObj()->GetSelf(), pIterator.release()));
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

Value Func_Multiply::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		result.SetNumber(valueLeft.GetNumber() * valueRight.GetNumber());
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsComplex()) {
		result.SetComplex(valueLeft.GetComplex() * valueRight.GetComplex());
		return result;
	} else if (valueLeft.IsNumber() && valueRight.IsComplex()) {
		result.SetComplex(valueLeft.GetNumber() * valueRight.GetComplex());
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsNumber()) {
		result.SetComplex(valueLeft.GetComplex() * valueRight.GetNumber());
		return result;
	} else if (valueLeft.IsMatrix() && valueRight.IsMatrix()) {
		return Object_matrix::OperatorMultiply(env, sig,
						valueLeft.GetMatrixObj(), valueRight.GetMatrixObj());
	} else if (valueRight.IsMatrix()) {
		return Object_matrix::OperatorMultiply(env, sig,
						valueLeft, valueRight.GetMatrixObj());
	} else if (valueLeft.IsMatrix()) {
		return Object_matrix::OperatorMultiply(env, sig,
						valueLeft.GetMatrixObj(), valueRight);
	} else if (valueLeft.IsTimeDelta() && valueRight.IsNumber()) {
		const TimeDelta &td = valueLeft.GetTimeDelta();
		long num = valueRight.GetLong();
		return Value(env,
			TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num));
	} else if (valueLeft.IsNumber() && valueRight.IsTimeDelta()) {
		const TimeDelta &td = valueRight.GetTimeDelta();
		long num = valueLeft.GetLong();
		return Value(env,
			TimeDelta(td.GetDays() * num, td.GetSecsRaw() * num, td.GetUSecs() * num));
	} else if (valueLeft.IsFunction()) {
		const Object_function *pObj = valueLeft.GetFunctionObj();
		if (pObj->GetFunction()->IsUnary()) {
			ValueList valListArg(valueRight);
			result = pObj->Eval(env, sig, valListArg);
			if (sig.IsSignalled()) return Value::Null;
		} else {
			sig.SetError(ERR_TypeError, "unary function is expected for multiplier-form applier");
			return Value::Null;
		}
		return result;
	} else if (valueLeft.IsString() && valueRight.IsNumber()) {
		String str;
		for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
			str += valueLeft.GetString();
		}
		result = Value(env, str.c_str());
		return result;
	} else if (valueLeft.IsNumber() && valueRight.IsString()) {
		String str;
		for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
			str += valueRight.GetString();
		}
		result = Value(env, str.c_str());
		return result;
	} else if (valueLeft.IsBinary() && valueRight.IsNumber()) {
		Binary buff;
		for (int cnt = static_cast<int>(valueRight.GetNumber()); cnt > 0; cnt--) {
			buff += valueLeft.GetBinary();
		}
		result.InitAsBinary(env, buff, true);
		return result;
	} else if (valueLeft.IsNumber() && valueRight.IsBinary()) {
		Binary buff;
		for (int cnt = static_cast<int>(valueLeft.GetNumber()); cnt > 0; cnt--) {
			buff += valueRight.GetBinary();
		}
		result.InitAsBinary(env, buff, true);
		return result;
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
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
		Func_Multiply::OptimizedExpr(env, sig, pExprDiff1, pExprArg2->IncRef()),
		Func_Multiply::OptimizedExpr(env, sig, pExprArg1->IncRef(), pExprDiff2));
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
		return OptimizeConst(env, sig, env.GetFunc_Multiply(), pExprLeft, pExprRight);
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
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->IncRef();
		Expr *pExpr2 =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->IncRef();
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Func_Multiply::OptimizedExpr(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsOperatorNeg()) {
		// (-n) * m = -(n * m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->IncRef();
		Expr::Delete(pExprLeft);
		return Func_Neg::OptimizedExpr(env, sig,
			Func_Multiply::OptimizedExpr(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsOperatorNeg()) {
		// n * (-m) = -(n * m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->IncRef();
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
				Expr *pExprPowerR = pExprBinOpR->GetRight()->IncRef();
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
				Expr *pExprPowerL = pExprBinOpL->GetRight()->IncRef();
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
				Expr *pExprBase = pExprBinOpL->GetLeft()->IncRef();
				Expr *pExprPowerL = pExprBinOpL->GetRight()->IncRef();
				Expr *pExprPowerR = pExprBinOpR->GetRight()->IncRef();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Power::OptimizedExpr(env, sig, pExprBase,
					Func_Plus::OptimizedExpr(env, sig, pExprPowerL, pExprPowerR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetFunc_Multiply(), pExprLeft, pExprRight);
}

// n / m
bool Func_Divide::IsDivide() const { return true; }

Func_Divide::Func_Divide(Environment &env) :
			Function(env, Symbol::Add("__div__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Divide, "/");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Divide::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		Number numRight = valueRight.GetNumber();
		if (numRight == 0) {
			SetError_DivideByZero(sig);
			return Value::Null;
		}
		result.SetNumber(valueLeft.GetNumber() / numRight);
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsComplex()) {
		Complex numRight = valueRight.GetComplex();
		if (numRight == Complex(0.)) {
			SetError_DivideByZero(sig);
			return Value::Null;
		}
		result.SetComplex(valueLeft.GetComplex() / valueRight.GetComplex());
		return result;
	} else if (valueLeft.IsNumber() && valueRight.IsComplex()) {
		Complex numRight = valueRight.GetComplex();
		if (numRight == Complex(0.)) {
			SetError_DivideByZero(sig);
			return Value::Null;
		}
		result.SetComplex(valueLeft.GetNumber() / numRight);
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsNumber()) {
		Number numRight = valueRight.GetNumber();
		if (numRight == 0) {
			SetError_DivideByZero(sig);
			return Value::Null;
		}
		result.SetComplex(valueLeft.GetComplex() / numRight);
		return result;
	} else if (valueLeft.IsMatrix() && !valueRight.IsMatrix()) {
		return Object_matrix::OperatorDivide(env, sig,
						valueLeft.GetMatrixObj(), valueRight);
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
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
			Func_Multiply::OptimizedExpr(env, sig, pExprDiff1, pExprArg2->IncRef()),
			Func_Multiply::OptimizedExpr(env, sig, pExprArg1->IncRef(), pExprDiff2)),
		Func_Power::OptimizedExpr(env, sig, pExprArg2->IncRef(), new Expr_Value(2)));
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
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->IncRef();
		Expr *pExpr2 =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->IncRef();
		Expr::Delete(pExprLeft);
		Expr::Delete(pExprRight);
		return Func_Divide::OptimizedExpr(env, sig, pExpr1, pExpr2);
	} else if (pExprLeft->IsOperatorNeg()) {
		// (-n) / m = -(n / m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->IncRef();
		Expr::Delete(pExprLeft);
		return Func_Neg::OptimizedExpr(env, sig,
			Func_Divide::OptimizedExpr(env, sig, pExpr, pExprRight));
	} else if (pExprRight->IsOperatorNeg()) {
		// n / (-m) = -(n / m)
		Expr *pExpr =
			dynamic_cast<const Expr_UnaryOp *>(pExprRight)->GetChild()->IncRef();
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
				Expr *pExprPowerR = pExprBinOpR->GetRight()->IncRef();
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
				Expr *pExprPowerL = pExprBinOpL->GetRight()->IncRef();
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
				Expr *pExprBase = pExprBinOpL->GetLeft()->IncRef();
				Expr *pExprPowerL = pExprBinOpL->GetRight()->IncRef();
				Expr *pExprPowerR = pExprBinOpR->GetRight()->IncRef();
				Expr::Delete(pExprLeft);
				Expr::Delete(pExprRight);
				return Func_Power::OptimizedExpr(env, sig, pExprBase,
					Func_Minus::OptimizedExpr(env, sig, pExprPowerL, pExprPowerR));
			}
		}
	}
	return new Expr_BinaryOp(env.GetFunc_Divide(), pExprLeft, pExprRight);
}

// mod(n, m):map
bool Func_Modulo::IsModulo() const { return true; }

Func_Modulo::Func_Modulo(Environment &env) :
			Function(env, Symbol::Add("mod"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Modulo, "%");
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

Value Func_Modulo::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		result.SetNumber(::fmod(valueLeft.GetNumber(), valueRight.GetNumber()));
		return result;
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValType(sig, valueLeft, valueRight);
	return result;
}

// format(format, value*):map
Func_format::Func_format(Environment &env) :
			Function(env, Symbol::Add("format"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string);
	DeclareArg(env, "values", VTYPE_any, OCCUR_ZeroOrMore);
}

Value Func_format::DoEval(Environment &env, Signal sig, Args &args) const
{
	return Value(env, Formatter::Format(sig,
						args.GetString(0), args.GetList(1)).c_str());
}

// n ** m
bool Func_Power::IsPower() const { return true; }

Func_Power::Func_Power(Environment &env) :
			Function(env, Symbol::Add("__pow__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Power, "**");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Power::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		result.SetNumber(::pow(valueLeft.GetNumber(), valueRight.GetNumber()));
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsComplex()) {
		result.SetComplex(std::pow(valueLeft.GetComplex(), valueRight.GetComplex()));
		return result;
	} else if (valueLeft.IsNumber() && valueRight.IsComplex()) {
		result.SetComplex(std::pow(valueLeft.GetNumber(), valueRight.GetComplex()));
		return result;
	} else if (valueLeft.IsComplex() && valueRight.IsNumber()) {
		result.SetComplex(std::pow(valueLeft.GetComplex(), valueRight.GetNumber()));
		return result;
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
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
			Func_Multiply::OptimizedExpr(env, sig, pExprDiff1, pExprArg2->IncRef()),
			Func_Power::OptimizedExpr(env, sig,
				pExprArg1->IncRef(),
				Func_Minus::OptimizedExpr(env, sig, pExprArg2->IncRef(), new Expr_Value(1)))),
		Func_Multiply::OptimizedExpr(env, sig,
			Func_Multiply::OptimizedExpr(env, sig,
				pExprDiff2,
				Gura_Module(math)::CreateFuncExpr("log", pExprArg1->IncRef())),
			Func_Power::OptimizedExpr(env, sig, pExprArg1->IncRef(), pExprArg2->IncRef())));
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
		return OptimizeConst(env, sig, env.GetFunc_Power(), pExprLeft, pExprRight);
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
			dynamic_cast<const Expr_UnaryOp *>(pExprLeft)->GetChild()->IncRef();
		Expr::Delete(pExprLeft);
		return Func_Power::OptimizedExpr(env, sig, pExpr, pExprRight);
	//} else if (pExprRight->IsConstNumber(0.5)) {
	//	// n ** 0.5 = math.sqrt(n)
	//	Expr::Delete(pExprRight);
	//	return Gura_Module(math)::CreateFuncExpr("sqrt", pExprLeft);
	}
	return new Expr_BinaryOp(env.GetFunc_Power(), pExprLeft, pExprRight);
}

// n == m
Func_Equal::Func_Equal(Environment &env) :
			Function(env, Symbol::Add("__eq__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Equal, "==");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Equal::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	do {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	int cmp = Value::Compare(args.GetValue(0), args.GetValue(1));
	result.SetBoolean(cmp == 0);
	return result;
}

// n != m
Func_NotEqual::Func_NotEqual(Environment &env) :
			Function(env, Symbol::Add("__ne__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_NotEqual, "!=");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_NotEqual::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	do {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	int cmp = Value::Compare(args.GetValue(0), args.GetValue(1));
	result.SetBoolean(cmp != 0);
	return result;
}

// n > m
Func_Greater::Func_Greater(Environment &env) :
			Function(env, Symbol::Add("__gt__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Greater, ">");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Greater::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	do {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	int cmp = Value::Compare(args.GetValue(0), args.GetValue(1));
	result.SetBoolean(cmp > 0);
	return result;
}

// n < m
Func_Less::Func_Less(Environment &env) :
			Function(env, Symbol::Add("__lt__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Less, "<");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Less::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	do {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	int cmp = Value::Compare(args.GetValue(0), args.GetValue(1));
	result.SetBoolean(cmp < 0);
	return result;
}

// n >= m
Func_GreaterEq::Func_GreaterEq(Environment &env) :
			Function(env, Symbol::Add("__ge__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_GreaterEq, ">=");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_GreaterEq::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	do {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	int cmp = Value::Compare(args.GetValue(0), args.GetValue(1));
	result.SetBoolean(cmp >= 0);
	return result;
}

// n <= m
Func_LessEq::Func_LessEq(Environment &env) :
			Function(env, Symbol::Add("__le__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_LessEq, "<=");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_LessEq::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	do {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	int cmp = Value::Compare(args.GetValue(0), args.GetValue(1));
	result.SetBoolean(cmp <= 0);
	return result;
}

// n <=> m
Func_Compare::Func_Compare(Environment &env) :
			Function(env, Symbol::Add("__cmp__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Compare, "<=>");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Compare::DoEval(Environment &env, Signal sig, Args &args) const
{
	do {
		bool evaluatedFlag = false;
		Value result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	} while (0);
	int cmp = Value::Compare(args.GetValue(0), args.GetValue(1));
	return Value(static_cast<Number>(cmp));
}

// n in m
bool Func_ContainCheck::IsContainCheck() const { return true; }

Func_ContainCheck::Func_ContainCheck(Environment &env) :
			Function(env, Symbol::Add("in"), FUNCTYPE_Function)
{
	SetOperatorInfo(Parser::ETYPE_ContainCheck, "in");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_ContainCheck::DoEval(Environment &env, Signal sig, Args &args) const
{
	Value result;
	if (args.IsList(0) || args.IsIterator(0)) {
		ValueList &valList = result.InitAsList(env);
		AutoPtr<Iterator> pIterator(args.GetValue(0).CreateIterator(sig));
		if (pIterator.IsNull()) return Value::Null;
		if (args.IsList(1)) {
			const ValueList &valListToFind = args.GetList(1);
			Value value;
			while (pIterator->Next(env, sig, value)) {
				valList.push_back(valListToFind.IsContain(value));
			}
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		} else if (args.IsIterator(1)) {
			Value value;
			while (pIterator->Next(env, sig, value)) {
				AutoPtr<Iterator> pIteratorToFind(args.GetValue(1).CreateIterator(sig));
				if (pIteratorToFind.IsNull()) break;
				bool foundFlag = pIteratorToFind->IsContain(env, sig, value);
				if (sig.IsSignalled()) break;
				valList.push_back(foundFlag);
			}
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		} else {
			const Value &valueToCompare = args.GetValue(1);
			Value value;
			while (pIterator->Next(env, sig, value)) {
				valList.push_back(Value::Compare(value, valueToCompare) == 0);
			}
			if (sig.IsSignalled()) {
				return Value::Null;
			}
		}
	} else {
		const Value &value = args.GetValue(0);
		if (args.IsList(1)) {
			result.SetBoolean(args.GetList(1).IsContain(value));
		} else if (args.IsIterator(1)) {
			AutoPtr<Iterator> pIteratorToFind(args.GetValue(1).CreateIterator(sig));
			if (pIteratorToFind.IsNull()) return Value::Null;
			bool foundFlag = pIteratorToFind->IsContain(env, sig, value);
			if (sig.IsSignalled()) return Value::Null;
			result.SetBoolean(foundFlag);
		} else {
			int cmp = Value::Compare(value, args.GetValue(1));
			result.SetBoolean(cmp == 0);
		}
	}
	return result;
}

// n | m
Func_Or::Func_Or(Environment &env) :
			Function(env, Symbol::Add("__or__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Or, "|");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Or::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		unsigned long num = valueLeft.GetULong() | valueRight.GetULong();
		result.SetNumber(num);
		return result;
	} else if (valueLeft.IsBoolean() && valueRight.IsBoolean()) {
		return valueLeft.GetBoolean() || valueRight.GetBoolean();
	} else if (valueLeft.IsInvalid()) {
		return valueRight;	// nil | any -> any
	} else if (valueRight.IsInvalid()) {
		return valueLeft;	// any | nil -> any
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
}

// n & m
Func_And::Func_And(Environment &env) :
			Function(env, Symbol::Add("__and__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_And, "&");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_And::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		unsigned long num = static_cast<unsigned long>(valueLeft.GetNumber()) &
							static_cast<unsigned long>(valueRight.GetNumber());
		result.SetNumber(num);
		return result;
	} else if (valueLeft.IsBoolean() && valueRight.IsBoolean()) {
		return valueLeft.GetBoolean() && valueRight.GetBoolean();
	} else if (valueLeft.IsInvalid()) {
		return Value::Null;	// nil & any -> nil
	} else if (valueRight.IsInvalid()) {
		return Value::Null;	// any & nil -> nil
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
}

// n ^ m
Func_Xor::Func_Xor(Environment &env) :
			Function(env, Symbol::Add("__xor__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Xor, "^");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Xor::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		unsigned long num = static_cast<unsigned long>(valueLeft.GetNumber()) ^
							static_cast<unsigned long>(valueRight.GetNumber());
		result.SetNumber(num);
		return result;
	} else if (valueLeft.IsBoolean() && valueRight.IsBoolean()) {
		bool flagLeft = valueLeft.GetBoolean();
		bool flagRight = valueRight.GetBoolean();
		return (flagLeft && !flagRight) || (!flagLeft && flagRight);
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
}

// n << m
Func_ShiftL::Func_ShiftL(Environment &env) :
			Function(env, Symbol::Add("__shl__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_ShiftL, "<<");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_ShiftL::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		unsigned long num = static_cast<unsigned long>(valueLeft.GetNumber()) <<
							static_cast<unsigned long>(valueRight.GetNumber());
		result.SetNumber(num);
		return result;
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
}

// n >> m
Func_ShiftR::Func_ShiftR(Environment &env) :
			Function(env, Symbol::Add("__shr__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_ShiftR, ">>");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_ShiftR::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		unsigned long num = static_cast<unsigned long>(valueLeft.GetNumber()) >>
							static_cast<unsigned long>(valueRight.GetNumber());
		result.SetNumber(num);
		return result;
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
}

// n || m
// this function takes quoted values as its arguments to implement
// a short-circuit evaluation.
Func_OrOr::Func_OrOr(Environment &env) :
			Function(env, Symbol::Add("__oror__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_OrOr, "||");
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

// n && m
// this function takes quoted values as its arguments to implement
// a short-circuit evaluation.
Func_AndAnd::Func_AndAnd(Environment &env) :
			Function(env, Symbol::Add("__andand__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_AndAnd, "&&");
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

// n .. m
bool Func_Sequence::IsSequence() const { return true; }

Func_Sequence::Func_Sequence(Environment &env) :
			Function(env, Symbol::Add("__seq__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Sequence, "..");
	DeclareArg(env, "n", VTYPE_any);
	DeclareArg(env, "m", VTYPE_any);
}

Value Func_Sequence::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &valueLeft = args.GetValue(0);
	const Value &valueRight = args.GetValue(1);
	Value result;
	if (valueLeft.IsNumber() && valueRight.IsNumber()) {
		Number numBegin = valueLeft.GetNumber();
		Number numEnd = valueRight.GetNumber();
		Number numStep = (numEnd >= numBegin)? +1 : -1;
		return Value(env, new Iterator_Sequence(numBegin, numEnd, numStep));
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValTypeM(sig, valueLeft, valueRight);
	return result;
}

// n ..
Func_SequenceInf::Func_SequenceInf(Environment &env) :
			Function(env, Symbol::Add("__seqinf__"), FUNCTYPE_Function)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetOperatorInfo(Parser::ETYPE_Sequence, "..");
	DeclareArg(env, "n", VTYPE_any);
}

Value Func_SequenceInf::DoEval(Environment &env, Signal sig, Args &args) const
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		Number numBegin = value.GetNumber();
		return Value(env, new Iterator_SequenceInf(numBegin));
	} else {
		bool evaluatedFlag = false;
		result = EvalOverrideBinary(sig, args, evaluatedFlag);
		if (evaluatedFlag) return result;
	}
	SetError_InvalidValType(sig, value);
	return result;
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Expr *OptimizeConst(Environment &env, Signal sig,
									const Function &func, Expr *pExprChild)
{
	ValueList valListArg(dynamic_cast<Expr_Value *>(pExprChild)->GetValue());
	Expr::Delete(pExprChild);
	Args args(valListArg);
	Value value = func.Eval(env, sig, args);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(value);
}

Expr *OptimizeConst(Environment &env, Signal sig,
					const Function &func, Expr *pExprLeft, Expr *pExprRight)
{
	ValueList valListArg(
		dynamic_cast<Expr_Value *>(pExprLeft)->GetValue(),
		dynamic_cast<Expr_Value *>(pExprRight)->GetValue());
	Expr::Delete(pExprLeft);
	Expr::Delete(pExprRight);
	Args args(valListArg);
	Value value = func.Eval(env, sig, args);
	if (sig.IsSignalled()) return NULL;
	return new Expr_Value(value);
}

}
