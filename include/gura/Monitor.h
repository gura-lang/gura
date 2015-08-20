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
public:
	enum Command {
		CMD_Run, CMD_Terminate,
	};
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
	virtual Command OnExprPre(Environment &env, const Expr *pExprNext);
	virtual Command OnExprPost(Environment &env, const Expr *pExpr, Value &valueRtn);
public:
	inline static bool NotifyExprPre(Environment &env, const Expr *pExprNext) {
		Monitor *pMonitor = env.GetMonitor();
		return (pMonitor == nullptr) || (pMonitor->OnExprPre(env, pExprNext) != CMD_Terminate);
	}
	inline static bool NotifyExprPost(Environment &env, const Expr *pExpr, Value &valueRtn) {
		Monitor *pMonitor = env.GetMonitor();
		return (pMonitor == nullptr) ||
			(pMonitor->OnExprPost(env, pExpr, valueRtn) != CMD_Terminate);
	}
};

}

#endif
