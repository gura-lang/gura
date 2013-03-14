//-----------------------------------------------------------------------------
// Gura uuid module
//-----------------------------------------------------------------------------
#ifndef __MODULE_UUID_H__
#define __MODULE_UUID_H__
#include <gura.h>
#ifdef GURA_ON_MSWIN
#include <unknwn.h>
#else
#include <uuid/uuid.h>
#endif

Gura_BeginModule(uuid)
}}

#endif
