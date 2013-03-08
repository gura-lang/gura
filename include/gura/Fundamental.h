#ifndef __GURA_FUNDAMENTAL_H__
#define __GURA_FUNDAMENTAL_H__

#include "Common.h"
#include "Environment.h"
#include "Function.h"
#include "Iterator.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ICallable
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ICallable {
public:
	Value Call(Environment &env, Signal sig,
			const Value &valueThis, Iterator *pIteratorThis, bool listThisFlag,
			const Expr_Caller *pExprCaller, const ExprList &exprListArg,
			const Function **ppFuncLeader);
	virtual bool IsLeader() const;
	virtual bool IsTrailer() const;
	virtual bool IsEndMarker() const;
	virtual OccurPattern GetBlockOccurPattern() const;
protected:
	virtual Value DoCall(Environment &env, Signal sig, Args &args) = 0;
};

//-----------------------------------------------------------------------------
// Fundamental
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Fundamental : public Environment, public ICallable {
protected:
	int _cntRef;
protected:
	inline Fundamental(const Fundamental &fund) :
							Environment(fund), _cntRef(fund._cntRef) {}
	Fundamental(Environment *pEnvOuter, EnvType envType);
public:
	virtual ~Fundamental();
	bool BuildContent(Environment &env, Signal sig, const Value &valueThis,
		const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable = NULL);
	inline int DecRef() { if (_cntRef > 0) _cntRef--; return _cntRef; }
	inline int GetRefCnt() const { return _cntRef; }
	virtual bool IsFunction() const;
	virtual Iterator *CreateIterator(Signal sig);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoCall(Environment &env, Signal sig, Args &args);
	virtual String ToString(Signal sig, bool exprFlag) = 0;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
