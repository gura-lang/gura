#include "stdafx.h"

namespace Gura {

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

Value FunctionCustom::DoEval(Environment &env, Signal sig, Args &args) const
{
	AutoPtr<Environment> pEnvLocal(PrepareEnvironment(env, sig, args));
	if (pEnvLocal.get() == NULL) return Value::Null;
	if (_funcType != FUNCTYPE_Block) {
		Value valueThis(args.GetThis());
		valueThis.AddFlags(VFLAG_Privileged);
		pEnvLocal->AssignValue(Gura_Symbol(this_), valueThis, EXTRA_Public);
	}
	pEnvLocal->AssignValue(Gura_Symbol(__args__),
				Value(new Object_args(env, args.Reference())), EXTRA_Public);
#if 0
	Sequence *pSequence = new FunctionCustom::SequenceEx(pEnvLocal.release(),
								dynamic_cast<FunctionCustom *>(Reference()));
	return Sequence::Return(sig, pSequence);
#else
	SeqPostHandler *pSeqPostHandler = NULL;
	Value result = GetExprBody()->Exec(*pEnvLocal, sig, pSeqPostHandler);
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

Expr *FunctionCustom::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

FunctionCustom *FunctionCustom::CreateBlockFunc(Environment &env, Signal sig,
	const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType)
{
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
							pSymbol, Expr::Reference(pExprBlock), funcType));
	pFunc->GetDeclOwner().AllowTooManyArgs(true);
	const ExprOwner *pExprOwnerParam = pExprBlock->GetExprOwnerParam();
	if (pExprOwnerParam != NULL) {
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetExprOwnerArg(pExprOwnerParam->Reference());
		if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, *pArgs)) {
			return NULL;
		}
	}
	return pFunc.release();
}

//-----------------------------------------------------------------------------
// FunctionCustom::SequenceEx
//-----------------------------------------------------------------------------
FunctionCustom::SequenceEx::SequenceEx(Environment *pEnv, FunctionCustom *pFunctionCustom) :
				Sequence(pEnv), _pFunctionCustom(pFunctionCustom), _idxExpr(0)
{
	const Expr *pExprBody = _pFunctionCustom->GetExprBody();
	if (pExprBody == NULL) {
		_pExprOwner.reset(new ExprOwner());
	} else if (pExprBody->IsBlock()) {
		const Expr_Block *pExprBlock = dynamic_cast<const Expr_Block *>(pExprBody);
		_pExprOwner.reset(pExprBlock->GetExprOwner().Reference());
	} else {
		_pExprOwner.reset(new ExprOwner());
		_pExprOwner->push_back(pExprBody->Reference());
	}
}

bool FunctionCustom::SequenceEx::DoStep(Signal sig, Value &result)
{
	if (_idxExpr >= _pExprOwner->size()) {
		_doneFlag = true;
		return false;
	}
	SeqPostHandler *pSeqPostHandler = NULL;
	Environment &env = *_pEnv;
	const Expr *pExpr = (*_pExprOwner)[_idxExpr++];
	result = pExpr->Exec(env, sig, pSeqPostHandler, true);
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
