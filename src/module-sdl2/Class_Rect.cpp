#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Rect implementation
//-----------------------------------------------------------------------------
Object_Rect::~Object_Rect()
{
}

Object *Object_Rect::Clone() const
{
	return nullptr;
}

String Object_Rect::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.Rect:x=%d,y=%d,w=%d,h=%d>",
			  					_rect.x, _rect.y, _rect.w, _rect.h);
	return String(buff);
}

bool Object_Rect::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(x));
	symbols.insert(Gura_UserSymbol(y));
	symbols.insert(Gura_UserSymbol(w));
	symbols.insert(Gura_UserSymbol(h));
	return true;
}

Value Object_Rect::DoGetProp(Environment &env, const Symbol *pSymbol,
							 const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		return Value(_rect.x);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		return Value(_rect.y);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		return Value(_rect.w);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		return Value(_rect.h);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_Rect::DoSetProp(Environment &env,
							 const Symbol *pSymbol, const Value &value,
							 const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rect.x = static_cast<Sint16>(value.GetInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rect.y = static_cast<Sint16>(value.GetInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rect.w = static_cast<Uint16>(value.GetUInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rect.h = static_cast<Uint16>(value.GetUInt());
		return value;
	}
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
// sdl2.Rect(x?:number, y?:number, w?:number, h?:number)
Gura_DeclareFunction(Rect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Rect));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(Rect)
{
	SDL_Rect rect;
	rect.x = arg.IsValid(0)? arg.GetInt(0) : 0;
	rect.y = arg.IsValid(1)? arg.GetInt(1) : 0;
	rect.w = arg.IsValid(2)? arg.GetInt(2) : 0;
	rect.h = arg.IsValid(3)? arg.GetInt(3) : 0;
	return Value(new Object_Rect(rect));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Rect
//-----------------------------------------------------------------------------
// implementation of class Rect
Gura_ImplementUserClass(Rect)
{
	Gura_AssignFunction(Rect);
}

Gura_EndModuleScope(sdl2)
