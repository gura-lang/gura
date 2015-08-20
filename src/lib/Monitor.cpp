//=============================================================================
// Monitor
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Monitor
//-----------------------------------------------------------------------------
Monitor::Monitor() : _cntRef(1)
{
}

Monitor::~Monitor()
{
}

Monitor::Command Monitor::OnExprPre(Environment &env, const Expr *pExprNext)
{
	return CMD_Run;
}

Monitor::Command Monitor::OnExprPost(Environment &env, const Expr *pExpr, Value &valueRtn)
{
	return CMD_Run;
}

}
