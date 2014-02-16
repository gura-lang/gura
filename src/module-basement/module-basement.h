//-----------------------------------------------------------------------------
// Gura module: basement
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_BASEMENT_H__
#define __GURA_MODULE_BASEMENT_H__
#include <gura.h>

Gura_BeginModuleHeader(basement)

GURA_DLLEXPORT bool MixIn(Environment &env, Signal sig);
GURA_DLLEXPORT Module *Import(Environment &env, Signal sig);

Gura_EndModuleHeader(basement)

#endif
