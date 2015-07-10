//-----------------------------------------------------------------------------
// Gura module: base64
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_BASE64_H__
#define __GURA_MODULE_BASE64_H__
#include <gura.h>

Gura_BeginModuleHeader(base64)

GURA_DLLEXPORT bool MixIn(Environment &env, Signal &sig);
GURA_DLLEXPORT Module *Import(Environment &env, Signal &sig);

Gura_EndModuleHeader(base64)

#endif
