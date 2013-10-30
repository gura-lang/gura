//-----------------------------------------------------------------------------
// Gura sys module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_SYS_H__
#define __GURA_MODULE_SYS_H__
#include <gura.h>

Gura_BeginModuleHeader(sys, sys)

bool SetCmdLineArgs(Module *pModule, Signal sig, int argc, const char *argv[]);

Gura_EndModuleHeader(sys, sys)

#endif
