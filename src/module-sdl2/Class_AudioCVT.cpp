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

bool Object_AudioCVT::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(needed));
	symbols.insert(Gura_UserSymbol(src_format));
	symbols.insert(Gura_UserSymbol(dst_format));
	symbols.insert(Gura_UserSymbol(rate_incr));
	symbols.insert(Gura_UserSymbol(buf));
	symbols.insert(Gura_UserSymbol(len));
	symbols.insert(Gura_UserSymbol(len_cvt));
	symbols.insert(Gura_UserSymbol(len_mult));
	symbols.insert(Gura_UserSymbol(len_ratio));
	return true;
}

Value Object_AudioCVT::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(needed))) {
		return Value(_cvt.needed);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(src_format))) {
		return Value(_cvt.src_format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(dst_format))) {
		return Value(_cvt.dst_format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(rate_incr))) {
		return Value(_cvt.rate_incr);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(buf))) {
		return Value::Nil;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(len))) {
		return Value(_cvt.len);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(len_cvt))) {
		return Value(_cvt.len_cvt);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(len_mult))) {
		return Value(_cvt.len_mult);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(len_ratio))) {
		return Value(_cvt.len_ratio);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_AudioCVT::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.AudioCVT#buf
Gura_DeclareProperty_R(AudioCVT, buf)
{
	SetPropAttr(VTYPE_any);
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
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, dst_format)
{
	return Value::Nil;
}

// sdl2.AudioCVT#len
Gura_DeclareProperty_R(AudioCVT, len)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len)
{
	return Value::Nil;
}

// sdl2.AudioCVT#len_cvt
Gura_DeclareProperty_R(AudioCVT, len_cvt)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len_cvt)
{
	return Value::Nil;
}

// sdl2.AudioCVT#len_mult
Gura_DeclareProperty_R(AudioCVT, len_mult)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len_mult)
{
	return Value::Nil;
}

// sdl2.AudioCVT#len_ratio
Gura_DeclareProperty_R(AudioCVT, len_ratio)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, len_ratio)
{
	return Value::Nil;
}

// sdl2.AudioCVT#needed
Gura_DeclareProperty_R(AudioCVT, needed)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, needed)
{
	return Value::Nil;
}

// sdl2.AudioCVT#rate_incr
Gura_DeclareProperty_R(AudioCVT, rate_incr)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, rate_incr)
{
	return Value::Nil;
}

// sdl2.AudioCVT#src_format
Gura_DeclareProperty_R(AudioCVT, src_format)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(AudioCVT, src_format)
{
	return Value::Nil;
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
#if 0
	Gura_AssignProperty(AudioCVT, buf);
	Gura_AssignProperty(AudioCVT, dst_format);
	Gura_AssignProperty(AudioCVT, len);
	Gura_AssignProperty(AudioCVT, len_cvt);
	Gura_AssignProperty(AudioCVT, len_mult);
	Gura_AssignProperty(AudioCVT, len_ratio);
	Gura_AssignProperty(AudioCVT, needed);
	Gura_AssignProperty(AudioCVT, rate_incr);
	Gura_AssignProperty(AudioCVT, src_format);
#endif
}

Gura_EndModuleScope(sdl2)
