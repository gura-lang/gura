//=============================================================================
// Gura module: glut
//=============================================================================
#include "stdafx.h"

#define Gura_AssignValueFont(name) \

Gura_BeginModuleBody(glut)

//-----------------------------------------------------------------------------
// Object_Font
//-----------------------------------------------------------------------------
Object_Font::~Object_Font()
{
}

Object *Object_Font::Clone() const
{
	return NULL;
}

String Object_Font::ToString(bool exprFlag)
{
	return String("<glut.font>");
}

// implementation of class Font
Gura_ImplementUserClass(Font)
{
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// glut.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementFunction(test)
{
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
	// class realization
	Gura_RealizeUserClass(Font, env.LookupClass(VTYPE_object));
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
