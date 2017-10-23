//=============================================================================
// Gura module: arrayt
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(arrayt)

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	AssignCreators(env);
	AssignOperators(env);
	AssignFilters(env);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(arrayt, arrayt)

Gura_RegisterModule(arrayt)
