//=============================================================================
// MonitorBasic
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// MonitorDebugger
//-----------------------------------------------------------------------------
MonitorDebugger::MonitorDebugger()
{
}

bool MonitorDebugger::OnExprPre(Environment &env, const Expr *pExprNext)
{
	const Expr *pExprParent = pExprNext->GetParent();
	if (pExprParent == nullptr || pExprParent->IsRoot() || pExprParent->IsBlock()) {
		::printf("%s\n", pExprNext->ToString(Expr::SCRSTYLE_Brief).c_str());
		::fgetc(stdin);
	}
	return true;
}

bool MonitorDebugger::OnExprPost(Environment &env, const Expr *pExpr, Value &valueRtn)
{
	return true;
}

}
