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
	// Assignment of operator
	AssignOperators(env);
	// Assignment of array creators
	AssignCreators(env);
	// Assignment of methods
	AssignMethods(env);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(arrayt, arrayt)

Gura_RegisterModule(arrayt)
