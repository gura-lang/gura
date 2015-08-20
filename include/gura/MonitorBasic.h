//=============================================================================
// MonitorBasic
//=============================================================================
#ifndef __GURA_MONITORBASIC_H__
#define __GURA_MONITORBASIC_H__

#include "Monitor.h"

namespace Gura {

//-----------------------------------------------------------------------------
// MonitorDebugger
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE MonitorDebugger : public Monitor {
public:
	MonitorDebugger();
	virtual bool OnExprPre(Environment &env, const Expr *pExprNext);
	virtual bool OnExprPost(Environment &env, const Expr *pExpr, Value &valueRtn);

};

}

#endif
