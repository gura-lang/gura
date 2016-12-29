#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_AudioCVT implementation
//-----------------------------------------------------------------------------
Object_AudioCVT::~Object_AudioCVT()
{
}

Object *Object_AudioCVT::Clone() const
{
	return nullptr;
}

String Object_AudioCVT::ToString(bool exprFlag)
{
	return String("<sdl2.AudioCVT>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.AudioCVT#buf
Gura_DeclareProperty_R(AudioCVT, buf)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, buf)
{
	return Value::Nil;
}

// sdl2.AudioCVT#dst_format
Gura_DeclareProperty_R(AudioCVT, dst_format)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, dst_format)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.dst_format);
}

// sdl2.AudioCVT#len
Gura_DeclareProperty_R(AudioCVT, len)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.len);
}

// sdl2.AudioCVT#len_cvt
Gura_DeclareProperty_R(AudioCVT, len_cvt)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len_cvt)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.len_cvt);
}

// sdl2.AudioCVT#len_mult
Gura_DeclareProperty_R(AudioCVT, len_mult)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len_mult)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.len_mult);
}

// sdl2.AudioCVT#len_ratio
Gura_DeclareProperty_R(AudioCVT, len_ratio)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len_ratio)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.len_ratio);
}

// sdl2.AudioCVT#needed
Gura_DeclareProperty_R(AudioCVT, needed)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, needed)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.needed != 0);
}

// sdl2.AudioCVT#rate_incr
Gura_DeclareProperty_R(AudioCVT, rate_incr)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, rate_incr)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.rate_incr);
}

// sdl2.AudioCVT#src_format
Gura_DeclareProperty_R(AudioCVT, src_format)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, src_format)
{
	const SDL_AudioCVT &cvt = *Object_AudioCVT::GetObject(valueThis)->GetEntity();
	return Value(cvt.src_format);
}

//-----------------------------------------------------------------------------
// Gura interfaces for AudioCVT
//-----------------------------------------------------------------------------
// sdl2.AudioCVT()
Gura_DeclareFunction(AudioCVT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(AudioCVT));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(AudioCVT)
{
	return Value(new Object_AudioCVT());
}

// implementation of class AudioCVT
Gura_ImplementUserClass(AudioCVT)
{
	// Assignment of function
	Gura_AssignFunction(AudioCVT);
	// Assignment of properties
	Gura_AssignProperty(AudioCVT, buf);
	Gura_AssignProperty(AudioCVT, dst_format);
	Gura_AssignProperty(AudioCVT, len);
	Gura_AssignProperty(AudioCVT, len_cvt);
	Gura_AssignProperty(AudioCVT, len_mult);
	Gura_AssignProperty(AudioCVT, len_ratio);
	Gura_AssignProperty(AudioCVT, needed);
	Gura_AssignProperty(AudioCVT, rate_incr);
	Gura_AssignProperty(AudioCVT, src_format);
}

Gura_EndModuleScope(sdl2)
