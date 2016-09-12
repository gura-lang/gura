//-----------------------------------------------------------------------------
// Gura module: lexer
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(lexer)

//-----------------------------------------------------------------------------
// Gura module functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	return true;
}

Gura_ModuleTerminate()
{
}


Gura_EndModuleBody(lexer, lexer)

Gura_RegisterModule(lexer)
