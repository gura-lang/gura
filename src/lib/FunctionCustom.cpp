//=============================================================================
// FunctionCustom
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ExprVisitor_Replace
//-----------------------------------------------------------------------------
class ExprVisitor_Replace : public ExprVisitor {
private:
	const Symbol *_pSymbol;
	const Expr *_pExprSub;
public:
	inline ExprVisitor_Replace(const Symbol *pSymbol, const Expr *pExprSub) :
		_pSymbol(pSymbol), _pExprSub(pExprSub) {}
	virtual bool Visit(Expr *pExpr);
};

//-----------------------------------------------------------------------------
// FunctionCustom
//-----------------------------------------------------------------------------
bool FunctionCustom::IsCustom() const { return true; }

FunctionCustom::FunctionCustom(Environment &envScope,
				const Symbol *pSymbol, Expr *pExprBody, FunctionType funcType) :
		Function(envScope, pSymbol, funcType, FLAG_None), _pExprBody(pExprBody)
{
}

FunctionCustom::~FunctionCustom()
{
}

Value FunctionCustom::DoEval(Environment &env, Argument &arg) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Environment> pEnvLocal(arg.PrepareEnvironment(env, _funcType != FUNCTYPE_Block));
	if (pEnvLocal.IsNull()) return Value::Nil;
#if 0
	Sequence *pSequence = new FunctionCustom::SequenceEx(pEnvLocal.release(),
								dynamic_cast<FunctionCustom *>(Reference()));
	return Sequence::Return(sig, pSequence);
#else
	Value result = GetExprBody()->Exec(*pEnvLocal);
	EnvType envType = pEnvLocal->GetEnvType();
	if (envType == ENVTYPE_block) {
		// nothing to do. simply pass the signal to the outside.
	} else if (!sig.IsSignalled()) {
		// nothing to do
	} else if (sig.IsBreak()) {
		sig.ClearSignal();
	} else if (sig.IsContinue()) {
		sig.ClearSignal();
	} else if (sig.IsReturn()) {
		result = sig.GetValue();
		sig.ClearSignal();
	}
	return result;
#endif
}

Expr *FunctionCustom::MathDiff(Environment &env,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Expr> pExpr(GetExprBody()->MathDiff(env, pSymbol));
	if (sig.IsSignalled()) return nullptr;
	ExprVisitor_Replace visitor(pSymbol, pExprArg);
	pExpr->Accept(visitor);
	return pExpr.release();
}

FunctionCustom *FunctionCustom::CreateBlockFunc(Environment &env,
	const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType)
{
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env, pSymbol,
		new Expr_Block(pExprBlock->GetExprOwner().Reference(), nullptr), funcType));
	pFunc->SetFlag(FLAG_CutExtraArgs);
	const ExprOwner *pExprOwnerParam = pExprBlock->GetExprOwnerParam();
	if (pExprOwnerParam != nullptr) {
		CallerInfo callerInfo(*pExprOwnerParam, nullptr, nullptr, nullptr);
		if (!pFunc->CustomDeclare(env, callerInfo, SymbolSet::Empty)) {
			return nullptr;
		}
	}
	return pFunc.release();
}

//-----------------------------------------------------------------------------
// ExprVisitor_Replace
//-----------------------------------------------------------------------------
bool ExprVisitor_Replace::Visit(Expr *pExpr)
{
	if (pExpr->IsBlock()) {
		Expr_Block *pExprEx = dynamic_cast<Expr_Block *>(pExpr);
		foreach (ExprList, ppExprElem, pExprEx->GetExprOwner()) {
			Expr *pExprElem = *ppExprElem;
			if (pExprElem->IsSymbol(_pSymbol)) {
				*ppExprElem = _pExprSub->Clone();
				(*ppExprElem)->SetParent(pExpr);
				Expr::Delete(pExprElem);
			} else {
				pExprElem->Accept(*this);
			}
		}
		return false;
	} else if (pExpr->IsCaller()) {
		Expr_Caller *pExprEx = dynamic_cast<Expr_Caller *>(pExpr);
		foreach (ExprList, ppExprElem, pExprEx->GetExprOwner()) {
			Expr *pExprElem = *ppExprElem;
			if (pExprElem->IsSymbol(_pSymbol)) {
				*ppExprElem = _pExprSub->Clone();
				(*ppExprElem)->SetParent(pExpr);
				Expr::Delete(pExprElem);
			} else {
				pExprElem->Accept(*this);
			}
		}
		return false;
	} else if (pExpr->IsUnaryOp()) {
		Expr_UnaryOp *pExprEx = dynamic_cast<Expr_UnaryOp *>(pExpr);
		if (pExprEx->GetChild()->IsSymbol(_pSymbol)) {
			pExprEx->SetChild(_pExprSub->Clone());
		} else {
			pExprEx->GetChild()->Accept(*this);
		}
		return false;
	} else if (pExpr->IsBinaryOp()) {
		Expr_BinaryOp *pExprEx = dynamic_cast<Expr_BinaryOp *>(pExpr);
		if (pExprEx->GetLeft()->IsSymbol(_pSymbol)) {
			pExprEx->SetLeft(_pExprSub->Clone());
		} else {
			pExprEx->GetLeft()->Accept(*this);
		}
		if (pExprEx->GetRight()->IsSymbol(_pSymbol)) {
			pExprEx->SetRight(_pExprSub->Clone());
		} else {
			pExprEx->GetRight()->Accept(*this);
		}
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// FunctionCustom::SequenceEx
//-----------------------------------------------------------------------------
FunctionCustom::SequenceEx::SequenceEx(Environment *pEnv, FunctionCustom *pFunctionCustom) :
				Sequence(pEnv), _pFunctionCustom(pFunctionCustom), _idxExpr(0)
{
	const Expr *pExprBody = _pFunctionCustom->GetExprBody();
	if (pExprBody == nullptr) {
		_pExprOwner.reset(new ExprOwner());
	} else if (pExprBody->IsBlock()) {
		const Expr_Block *pExprBlock = dynamic_cast<const Expr_Block *>(pExprBody);
		_pExprOwner.reset(pExprBlock->GetExprOwner().Reference());
	} else {
		_pExprOwner.reset(new ExprOwner());
		_pExprOwner->push_back(pExprBody->Reference());
	}
}

bool FunctionCustom::SequenceEx::DoStep(Signal &sig, Value &result)
{
	if (_idxExpr >= _pExprOwner->size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = (*_pExprOwner)[_idxExpr++];
	result = pExpr->Exec(env, true);
	if (env.GetEnvType() == ENVTYPE_block) {
		// nothing to do. simply pass the signal to the outside.
	} else if (!sig.IsSignalled()) {
		// nothing to do
	} else if (sig.IsBreak()) {
		sig.ClearSignal();
	} else if (sig.IsContinue()) {
		sig.ClearSignal();
	} else if (sig.IsReturn()) {
		result = sig.GetValue();
		sig.ClearSignal();
	} else {
		return false;
	}
	if (_idxExpr < _pExprOwner->size()) return true;
	_doneFlag = true;
	return true;
}

String FunctionCustom::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:functioncustom>";
	return str;
}

}
