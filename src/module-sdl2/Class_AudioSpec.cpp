#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_AudioSpec implementation
//-----------------------------------------------------------------------------
Object_AudioSpec::~Object_AudioSpec()
{
}

Object *Object_AudioSpec::Clone() const
{
	return NULL;
}

String Object_AudioSpec::ToString(bool exprFlag)
{
	return String("<sdl2.AudioSpec>");
}

bool Object_AudioSpec::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(freq));
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(channels));
	symbols.insert(Gura_UserSymbol(samples));
	symbols.insert(Gura_UserSymbol(silence));
	symbols.insert(Gura_UserSymbol(size));
	symbols.insert(Gura_UserSymbol(callback));
	symbols.insert(Gura_UserSymbol(userdata));
	return true;
}

Value Object_AudioSpec::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(freq))) {
		return Value(_spec.freq);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Value(_spec.format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(channels))) {
		return Value(_spec.format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(samples))) {
		return Value(_spec.samples);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(silence))) {
		return Value(_spec.silence);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(size))) {
		return Value(_spec.size);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(callback))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(userdata))) {
		return Value::Null;
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_AudioSpec::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for AudioSpec
//-----------------------------------------------------------------------------
// implementation of class AudioSpec
Gura_ImplementUserClass(AudioSpec)
{
}

Gura_EndModuleScope(sdl2)
