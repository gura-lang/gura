//=============================================================================
// Fundamental
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Fundamental
//-----------------------------------------------------------------------------
Fundamental::Fundamental(const Fundamental &fund) : Environment(fund)
{
}

Fundamental::Fundamental(Environment *pEnvOuter, EnvType envType) :
											Environment(pEnvOuter, envType)
{
}

bool Fundamental::IsFunction() const { return false; }

Iterator *Fundamental::CreateIterator(Signal &sig)
{
	sig.SetError(ERR_ValueError, "object cannot generate iterator");
	return nullptr;
}

Value Fundamental::DoCall(
	Environment &env, const ExprList &exprListArg, const Expr_Block *pExprBlock,
	const SymbolSet &attrs, const SymbolSet &attrsOpt,
	const Value &valueThis, Iterator *pIteratorThis, bool listThisFlag,
	TrailCtrlHolder *pTrailCtrlHolder)
{
	Signal &sig = env.GetSignal();
	sig.SetError(ERR_TypeError, "object is not callable");
	return Value::Null;
}

bool Fundamental::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

void Fundamental::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
