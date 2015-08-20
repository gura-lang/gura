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

bool Monitor::OnExprPre(Environment &env, const Expr *pExprNext)
{
	return true;
}

bool Monitor::OnExprPost(Environment &env, const Expr *pExpr, Value &valueRtn)
{
	return true;
}

}
