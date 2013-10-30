//-----------------------------------------------------------------------------
// Gura uuid module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_UUID_H__
#define __GURA_MODULE_UUID_H__
#include <gura.h>
#ifdef GURA_ON_MSWIN
#include <unknwn.h>
#else
#include <uuid/uuid.h>
#endif

Gura_BeginModuleHeader(uuid, uuid)
Gura_EndModuleHeader(uuid, uuid)

#endif
