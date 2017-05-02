//=============================================================================
// Fundamental
//=============================================================================
#ifndef __GURA_FUNDAMENTAL_H__
#define __GURA_FUNDAMENTAL_H__

#include "Common.h"
#include "Environment.h"
#include "Function.h"
#include "Iterator.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Indexer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Indexer {
public:
	typedef std::pair<ValueList::const_iterator, ValueList::const_iterator> IteratorPair;
	typedef std::vector<IteratorPair> IteratorPairStack;
public:
	virtual Value EvalIndexGet(Environment &env, const ValueList &valListIdx);
	virtual void EvalIndexSet(Environment &env, const ValueList &valListIdx, const Value &value);
	virtual Value EmptyIndexGet(Environment &env);
	virtual void EmptyIndexSet(Environment &env, const Value &value);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
};

//-----------------------------------------------------------------------------
// Fundamental
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Fundamental : public Environment, public Indexer {
public:
	Gura_DeclareReferenceAccessor(Fundamental);
protected:
	Fundamental(const Fundamental &fund);
	Fundamental(Environment &envOuter, EnvType envType);
public:
	virtual bool IsFunction() const;
	virtual Iterator *CreateIterator(Signal &sig);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual String ToString(bool exprFlag) = 0;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
