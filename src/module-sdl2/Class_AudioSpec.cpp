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
	const SDL_AudioSpec &spec = *Object_AudioSpec::GetObject(valueThis)->GetEntity();
	return Value(spec.channels);
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
	const SDL_AudioSpec &spec = *Object_AudioSpec::GetObject(valueThis)->GetEntity();
	return Value(spec.format);
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
	const SDL_AudioSpec &spec = *Object_AudioSpec::GetObject(valueThis)->GetEntity();
	return Value(spec.freq);
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
	const SDL_AudioSpec &spec = *Object_AudioSpec::GetObject(valueThis)->GetEntity();
	return Value(spec.samples);
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
	const SDL_AudioSpec &spec = *Object_AudioSpec::GetObject(valueThis)->GetEntity();
	return Value(spec.silence);
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
	const SDL_AudioSpec &spec = *Object_AudioSpec::GetObject(valueThis)->GetEntity();
	return Value(spec.size);
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
	Gura_AssignProperty(AudioSpec, callback);
	Gura_AssignProperty(AudioSpec, channels);
	Gura_AssignProperty(AudioSpec, format);
	Gura_AssignProperty(AudioSpec, freq);
	Gura_AssignProperty(AudioSpec, samples);
	Gura_AssignProperty(AudioSpec, silence);
	Gura_AssignProperty(AudioSpec, size);
	Gura_AssignProperty(AudioSpec, userdata);
}

Gura_EndModuleScope(sdl2)
