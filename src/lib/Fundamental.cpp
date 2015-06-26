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

Iterator *Fundamental::CreateIterator(Signal sig)
{
	sig.SetError(ERR_ValueError, "object cannot generate iterator");
	return nullptr;
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
