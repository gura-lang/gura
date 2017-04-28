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

Fundamental::Fundamental(Environment &envOuter, EnvType envType) :
											Environment(envOuter, envType)
{
}

bool Fundamental::IsFunction() const { return false; }

Iterator *Fundamental::CreateIterator(Signal &sig)
{
	sig.SetError(ERR_ValueError, "object cannot generate iterator");
	return nullptr;
}

bool Fundamental::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Fundamental::EmptyIndexGet(Environment &env)
{
	env.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
	return Value::Nil;
}

void Fundamental::EmptyIndexSet(Environment &env, const Value &value)
{
	env.SetError(ERR_ValueError, "empty-indexed setting access is not supported");
}

Value Fundamental::IndexGet(Environment &env, const Value &valueIdx)
{
	env.SetError(ERR_ValueError, "indexed getting access is not supported");
	return Value::Nil;
}

void Fundamental::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	env.SetError(ERR_ValueError, "indexed setting access is not supported");
}

void Fundamental::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
