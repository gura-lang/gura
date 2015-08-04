//-----------------------------------------------------------------------------
// Gura module: base64
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_BASE64_H__
#define __GURA_MODULE_BASE64_H__
#include <gura.h>

Gura_BeginModuleHeader(base64)

GURA_DLLEXPORT bool MixIn(Environment &env);
GURA_DLLEXPORT Module *Import(Environment &env);

Gura_EndModuleHeader(base64)

#endif
