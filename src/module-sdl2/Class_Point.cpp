#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Point implementation
//-----------------------------------------------------------------------------
Object_Point::~Object_Point()
{
}

Object *Object_Point::Clone() const
{
	return nullptr;
}

String Object_Point::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.Point:x=%d,y=%d>", _point.x, _point.y);
	return String(buff);
}

bool Object_Point::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(x));
	symbols.insert(Gura_UserSymbol(y));
	return true;
}

Value Object_Point::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							 const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		return Value(_point.x);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		return Value(_point.y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Point::DoSetProp(Environment &env, Signal &sig,
							 const Symbol *pSymbol, const Value &value,
							 const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_point.x = static_cast<Sint16>(value.GetInt());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_point.y = static_cast<Sint16>(value.GetInt());
		return value;
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
// sdl2.Point(x?:number, y?:number)
Gura_DeclareFunction(Point)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Point));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(Point)
{
	SDL_Point point;
	point.x = args.IsValid(0)? args.GetInt(0) : 0;
	point.y = args.IsValid(1)? args.GetInt(1) : 0;
	return Value(new Object_Point(point));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Point
//-----------------------------------------------------------------------------
// implementation of class Point
Gura_ImplementUserClass(Point)
{
	Gura_AssignFunction(Point);
}

Gura_EndModuleScope(sdl2)
