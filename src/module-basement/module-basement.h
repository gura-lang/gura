//-----------------------------------------------------------------------------
// Gura module: basement
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_BASEMENT_H__
#define __GURA_MODULE_BASEMENT_H__
#include <gura.h>

Gura_BeginModuleHeader(basement)

GURA_DLLEXPORT bool MixIn(Environment &env);
GURA_DLLEXPORT Module *Import(Environment &env);

Gura_EndModuleHeader(basement)

#endif
