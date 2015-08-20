//=============================================================================
// Monitor
//=============================================================================
#ifndef __GURA_MONITOR_H__
#define __GURA_MONITOR_H__
#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Monitor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Monitor {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Monitor);
public:
	Monitor();
	virtual ~Monitor();
private:
	inline Monitor(const Monitor &monitor) {}
public:
	virtual bool OnExprPre(Environment &env, const Expr *pExprNext);
	virtual bool OnExprPost(Environment &env, const Expr *pExpr, Value &valueRtn);
public:
	inline static bool NotifyExprPre(Environment &env, const Expr *pExprNext) {
		Monitor *pMonitor = env.GetMonitor();
		return (pMonitor == nullptr) || pMonitor->OnExprPre(env, pExprNext);
	}
	inline static bool NotifyExprPost(Environment &env, const Expr *pExpr, Value &valueRtn) {
		Monitor *pMonitor = env.GetMonitor();
		return (pMonitor == nullptr) || pMonitor->OnExprPost(env, pExpr, valueRtn);
	}
};

}

#endif
