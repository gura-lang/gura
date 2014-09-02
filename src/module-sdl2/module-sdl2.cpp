//=============================================================================
// Gura module: sdl2
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(sdl2)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// sdl2.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(sdl2, sdl2)

Gura_RegisterModule(sdl2)
