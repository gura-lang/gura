//=============================================================================
// Gura module: mtp
//=============================================================================
#ifndef __GURA_MODULE_MTP_H__
#define __GURA_MODULE_MTP_H__
#include <gura.h>
#if defined(GURA_ON_MSWIN)
#include "Platform_msw.h"
#else
#include "Platform_libmpx.h"
#endif
#include "Class_device.h"
#include "Class_storage.h"
#include "Class_stat.h"

Gura_BeginModuleHeader(mtp)

Gura_DeclareUserSymbol(Undefined);
Gura_DeclareUserSymbol(FixedROM);
Gura_DeclareUserSymbol(RemovableROM);
Gura_DeclareUserSymbol(FixedRAM);
Gura_DeclareUserSymbol(RemovableRAM);
Gura_DeclareUserSymbol(GenericFlat);
Gura_DeclareUserSymbol(GenericHierarchical);
Gura_DeclareUserSymbol(DCF);
Gura_DeclareUserSymbol(ReadWrite);
Gura_DeclareUserSymbol(ReadOnly);
Gura_DeclareUserSymbol(ReadOnlyWithObjectDeletion);

Gura_EndModuleHeader(mtp)

#endif
