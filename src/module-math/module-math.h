//-----------------------------------------------------------------------------
// Gura math module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_MATH_H__
#define __GURA_MODULE_MATH_H__
#include <gura.h>

Gura_BeginModuleHeader(math)

GURA_DLLEXPORT Expr_Caller *CreateExprCaller(const Symbol *pSymbol, Expr *pExprArg);

Gura_EndModuleHeader(math)

#endif
