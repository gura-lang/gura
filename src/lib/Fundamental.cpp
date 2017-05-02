//=============================================================================
// Fundamental
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Indexer
//-----------------------------------------------------------------------------
Value Indexer::EvalIndexGet(Environment &env, const ValueList &valListIdx)
{
	if (valListIdx.empty()) return EmptyIndexGet(env);
	if (valListIdx.size() == 1 && !valListIdx.front().IsListOrIterator()) {
		return IndexGet(env, valListIdx.front());
	}
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	IteratorPairStack iteratorPairStack;
	iteratorPairStack.push_back(IteratorPair(valListIdx.begin(), valListIdx.end()));
	IteratorPairStack::reverse_iterator pIteratorPair = iteratorPairStack.rbegin();
	for (;;) {
		while (pIteratorPair->first == pIteratorPair->second) {
			iteratorPairStack.pop_back();
			if (iteratorPairStack.empty()) goto done;
		}
		ValueList::const_iterator pValueIdx = pIteratorPair->first++;
		if (pValueIdx->Is_iterator()) {
			Iterator *pIterator = pValueIdx->GetIterator();
			Value valueIdx;
			while (pIterator->Next(env, valueIdx)) {
				Value value = IndexGet(env, valueIdx);
				if (env.IsSignalled()) {
					Signal &sig = env.GetSignal();
					if (sig.GetError().GetType() == ERR_IndexError && pIterator->IsInfinite()) {
						sig.ClearSignal();
						goto done;
					}
					return Value::Nil;
				}
				pObjList->AddFast(value);
			}
			if (env.IsSignalled()) return Value::Nil;
		} else if (pValueIdx->Is_list()) {
			const ValueList &valListIdxSub = pValueIdx->GetList();
			iteratorPairStack.push_back(IteratorPair(valListIdxSub.begin(), valListIdxSub.end()));
			pIteratorPair = iteratorPairStack.rbegin();
		} else {
			Value value = IndexGet(env, *pValueIdx);
			if (env.IsSignalled()) return Value::Nil;
			pObjList->AddFast(value);
		}
	}
done:
	pObjList->DetermineValueType();
	return rtn;
}

void Indexer::EvalIndexSet(Environment &env, const ValueList &valListIdx, const Value &value)
{
	if (valListIdx.empty()) return EmptyIndexSet(env, value);
	IteratorPairStack iteratorPairStack;
	iteratorPairStack.push_back(IteratorPair(valListIdx.begin(), valListIdx.end()));
	IteratorPairStack::reverse_iterator pIteratorPair = iteratorPairStack.rbegin();
	for (;;) {
		while (pIteratorPair->first == pIteratorPair->second) {
			iteratorPairStack.pop_back();
			if (iteratorPairStack.empty()) return;
		}
		ValueList::const_iterator pValueIdx = pIteratorPair->first++;
		if (pValueIdx->Is_iterator()) {
			Iterator *pIterator = pValueIdx->GetIterator();
			Value valueIdx;
			while (pIterator->Next(env, valueIdx)) {
				IndexSet(env, valueIdx, value);
				if (env.IsSignalled()) {
					Signal &sig = env.GetSignal();
					if (sig.GetError().GetType() == ERR_IndexError && pIterator->IsInfinite()) {
						sig.ClearSignal();
					}
					return;
				}
			}
			if (env.IsSignalled()) return;
		} else if (pValueIdx->Is_list()) {
			const ValueList &valListIdxSub = pValueIdx->GetList();
			iteratorPairStack.push_back(IteratorPair(valListIdxSub.begin(), valListIdxSub.end()));
			pIteratorPair = iteratorPairStack.rbegin();
		} else {
			IndexSet(env, *pValueIdx, value);
			if (env.IsSignalled()) return;
		}
	}
}

Value Indexer::EmptyIndexGet(Environment &env)
{
	env.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
	return Value::Nil;
}

void Indexer::EmptyIndexSet(Environment &env, const Value &value)
{
	env.SetError(ERR_ValueError, "empty-indexed setting access is not supported");
}

Value Indexer::IndexGet(Environment &env, const Value &valueIdx)
{
	env.SetError(ERR_ValueError, "indexed getting access is not supported");
	return Value::Nil;
}

void Indexer::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	env.SetError(ERR_ValueError, "indexed setting access is not supported");
}

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

void Fundamental::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
