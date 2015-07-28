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

bool Object_AudioCVT::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, sig, symbols)) return false;
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

Value Object_AudioCVT::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
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
		return Value::Null;
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
	return Value::Null;
}

Value Object_AudioCVT::DoSetProp(Environment &env, Signal &__to_delete__,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
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
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(AudioCVT)
{
	return Value(new Object_AudioCVT());
}

// implementation of class AudioCVT
Gura_ImplementUserClass(AudioCVT)
{
	Gura_AssignFunction(AudioCVT);
}

Gura_EndModuleScope(sdl2)
