#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ICallable
//-----------------------------------------------------------------------------
Value ICallable::Call(Environment &env, Signal sig,
		const Value &valueThis, Iterator *pIteratorThis, bool listThisFlag,
		const Expr_Caller *pExprCaller, const ExprList &exprListArg,
		const Function **ppFuncLeader)
{
	if (ppFuncLeader != NULL) {
		const Function *pFuncLeader = *ppFuncLeader;
		*ppFuncLeader = NULL;
		if (pFuncLeader != NULL) {
			if (!pFuncLeader->CheckIfTrailer(this)) {
				pExprCaller->SetError(sig,
						ERR_SyntaxError, "invalid trailing process");
				return Value::Null;
			}
		}
	}
	Args args(exprListArg, valueThis, pIteratorThis, listThisFlag, ppFuncLeader,
		pExprCaller->GetAttrs(), pExprCaller->GetAttrsOpt(), pExprCaller->GetBlock());
	Value result = DoCall(env, sig, args);
	if (sig.IsSignalled()) {
		sig.AddExprCause(pExprCaller);
		return Value::Null;
	}
	return result;
}

bool ICallable::IsLeader() const
{
	return false;
}

bool ICallable::IsTrailer() const
{
	return false;
}

bool ICallable::IsEndMarker() const
{
	return false;
}

OccurPattern ICallable::GetBlockOccurPattern() const
{
	return OCCUR_Zero;
}

//-----------------------------------------------------------------------------
// Fundamental
//-----------------------------------------------------------------------------
Fundamental::Fundamental(Environment *pEnvOuter, EnvType envType) :
							Environment(pEnvOuter, envType), _cntRef(1)
{
}

Fundamental::~Fundamental()
{
}

bool Fundamental::IsFunction() const { return false; }

Iterator *Fundamental::CreateIterator(Signal sig)
{
	sig.SetError(ERR_ValueError, "object cannot generate iterator");
	return NULL;
}

Value Fundamental::DoCall(Environment &env, Signal sig, Args &args)
{
	sig.SetError(ERR_TypeError, "object is not callable");
	return Value::Null;
}

bool Fundamental::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

void Fundamental::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
