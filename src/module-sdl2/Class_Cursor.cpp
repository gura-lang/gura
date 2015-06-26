#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Cursor implementation
//-----------------------------------------------------------------------------
Object_Cursor::~Object_Cursor()
{
	if (_ownerFlag) ::SDL_FreeCursor(_pCursor);
}

Object *Object_Cursor::Clone() const
{
	return nullptr;
}

String Object_Cursor::ToString(bool exprFlag)
{
	return String("<sdl2.Cursor>");
}

bool Object_Cursor::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_Cursor::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Cursor::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Cursor
//-----------------------------------------------------------------------------
// implementation of class Cursor
Gura_ImplementUserClass(Cursor)
{
	Gura_AssignValue(Cursor, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
