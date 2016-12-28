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
	return nullptr;
}

String Object_AudioSpec::ToString(bool exprFlag)
{
	return String("<sdl2.AudioSpec>");
}

bool Object_AudioSpec::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
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

Value Object_AudioSpec::DoGetProp(Environment &env, const Symbol *pSymbol,
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
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(userdata))) {
		return Value::Nil;
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_AudioSpec::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.AudioSpec#callback
Gura_DeclareProperty_R(AudioSpec, callback)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, callback)
{
	return Value::Nil;
}

// sdl2.AudioSpec#channels
Gura_DeclareProperty_R(AudioSpec, channels)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, channels)
{
	return Value::Nil;
}

// sdl2.AudioSpec#format
Gura_DeclareProperty_R(AudioSpec, format)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, format)
{
	return Value::Nil;
}

// sdl2.AudioSpec#freq
Gura_DeclareProperty_R(AudioSpec, freq)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, freq)
{
	return Value::Nil;
}

// sdl2.AudioSpec#samples
Gura_DeclareProperty_R(AudioSpec, samples)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, samples)
{
	return Value::Nil;
}

// sdl2.AudioSpec#silence
Gura_DeclareProperty_R(AudioSpec, silence)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, silence)
{
	return Value::Nil;
}

// sdl2.AudioSpec#size
Gura_DeclareProperty_R(AudioSpec, size)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, size)
{
	return Value::Nil;
}

// sdl2.AudioSpec#userdata
Gura_DeclareProperty_R(AudioSpec, userdata)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioSpec, userdata)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for AudioSpec
//-----------------------------------------------------------------------------
// sdl2.AudioSpec()
Gura_DeclareFunction(AudioSpec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(AudioSpec));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(AudioSpec)
{
	SDL_AudioSpec spec;
	::memset(&spec, 0x00, sizeof(spec));
	return Value(new Object_AudioSpec(spec));
}

// implementation of class AudioSpec
Gura_ImplementUserClass(AudioSpec)
{
	// Assignment of function
	Gura_AssignFunction(AudioSpec);
	// Assignment of properties
#if 0
	Gura_AssignProperty(AudioSpec, callback);
	Gura_AssignProperty(AudioSpec, channels);
	Gura_AssignProperty(AudioSpec, format);
	Gura_AssignProperty(AudioSpec, freq);
	Gura_AssignProperty(AudioSpec, samples);
	Gura_AssignProperty(AudioSpec, silence);
	Gura_AssignProperty(AudioSpec, size);
	Gura_AssignProperty(AudioSpec, userdata);
#endif
}

Gura_EndModuleScope(sdl2)
