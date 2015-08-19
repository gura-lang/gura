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
// Fundamental
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Fundamental : public Environment, public Callable {
protected:
	Fundamental(const Fundamental &fund);
	Fundamental(Environment *pEnvOuter, EnvType envType);
public:
	virtual bool IsFunction() const;
	virtual Iterator *CreateIterator(Signal &sig);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoCall(
		Environment &env, const CallerInfo &callerInfo,
		const Value &valueThis, const Iterator *pIteratorThis, bool listThisFlag,
		const TrailCtrlHolder *pTrailCtrlHolder);
	virtual String ToString(bool exprFlag) = 0;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
