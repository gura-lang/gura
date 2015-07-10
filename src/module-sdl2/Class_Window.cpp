#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

// sdl2.Window#CreateRenderer()
Gura_DeclareMethod(Window, CreateRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(Window, CreateRenderer)
{
	//::SDL_CreateRenderer();
	return Value::Null;
}

// SDL_GL_CreateContext

//-----------------------------------------------------------------------------
// Object_Window implementation
//-----------------------------------------------------------------------------
Object_Window::~Object_Window()
{
	::SDL_DestroyWindow(_pWindow);
}

Object *Object_Window::Clone() const
{
	return nullptr;
}

String Object_Window::ToString(bool exprFlag)
{
	return String("<sdl2.Window>");
}

bool Object_Window::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
{
	return true;
}

Value Object_Window::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Window::DoSetProp(Environment &env, Signal &sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Window
//-----------------------------------------------------------------------------
// implementation of class Window
Gura_ImplementUserClass(Window)
{
	Gura_AssignValue(Window, Value(Reference()));
	Gura_AssignMethod(Window, CreateRenderer);
}

Gura_EndModuleScope(sdl2)
