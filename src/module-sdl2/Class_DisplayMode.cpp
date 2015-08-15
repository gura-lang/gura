#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_DisplayMode implementation
//-----------------------------------------------------------------------------
Object_DisplayMode::~Object_DisplayMode()
{
}

Object *Object_DisplayMode::Clone() const
{
	return nullptr;
}

String Object_DisplayMode::ToString(bool exprFlag)
{
	return String("<sdl2.DisplayMode>");
}

bool Object_DisplayMode::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(w));
	symbols.insert(Gura_UserSymbol(h));
	symbols.insert(Gura_UserSymbol(refresh_rate));
	return true;
}

Value Object_DisplayMode::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Value(_mode.format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		return Value(_mode.w);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		return Value(_mode.h);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(refresh_rate))) {
		return Value(_mode.refresh_rate);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_DisplayMode::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		_mode.format = value.GetLong();
		return Value(_mode.format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		_mode.w = value.GetInt();
		return Value(_mode.w);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		_mode.h = value.GetInt();
		return Value(_mode.h);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(refresh_rate))) {
		_mode.refresh_rate = value.GetInt();
		return Value(_mode.refresh_rate);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for DisplayMode
//-----------------------------------------------------------------------------
// sdl2.DisplayMode()
Gura_DeclareFunction(DisplayMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(DisplayMode));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(DisplayMode)
{
	SDL_DisplayMode mode;
	::memset(&mode, 0x00, sizeof(mode));
	return Value(new Object_DisplayMode(mode));
}

// implementation of class DisplayMode
Gura_ImplementUserClass(DisplayMode)
{
	Gura_AssignFunction(DisplayMode);
}

Gura_EndModuleScope(sdl2)
