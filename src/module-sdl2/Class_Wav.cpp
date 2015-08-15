#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Wav implementation
//-----------------------------------------------------------------------------
Object_Wav::~Object_Wav()
{
}

Object *Object_Wav::Clone() const
{
	return nullptr;
}

String Object_Wav::ToString(bool exprFlag)
{
	return String("<sdl2.Wav>");
}

bool Object_Wav::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_Wav::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_Wav::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Wav
//-----------------------------------------------------------------------------
// implementation of class Wav
Gura_ImplementUserClass(Wav)
{
	Gura_AssignValue(Wav, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
