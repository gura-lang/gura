//=============================================================================
// Gura module: glut
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(glut)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// glut.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

void display()
{
}

Gura_ImplementFunction(test)
{
	int argc = 0;
	char *argv[1];
	glutInit(&argc, argv);
	glutCreateWindow("hello");
	glutDisplayFunc(display);
	glutMainLoop();
	return Value::Null;
}

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
void SetError_NotImpFunction(Signal &sig, const char *funcName)
{
	sig.SetError(ERR_RuntimeError, "not implemented function %s", funcName);
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	AssignValues(env);
	AssignFunctions(env);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(glut, glut)

Gura_RegisterModule(glut)
