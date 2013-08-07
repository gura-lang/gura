#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle_int implementation
//-----------------------------------------------------------------------------
Object_rectangle_int::~Object_rectangle_int()
{
}

Object *Object_rectangle_int::Clone() const
{
	return NULL;
}

bool Object_rectangle_int::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	symbols.insert(Gura_Symbol(width));
	symbols.insert(Gura_Symbol(height));
	return true;
}

Value Object_rectangle_int::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_rectangle.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_rectangle.y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		return Value(_rectangle.width);
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		return Value(_rectangle.height);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_rectangle_int::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rectangle.x = value.GetInt();
		return Value(_rectangle.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rectangle.y = value.GetInt();
		return Value(_rectangle.y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rectangle.width = value.GetInt();
		return Value(_rectangle.width);
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_rectangle.height = value.GetInt();
		return Value(_rectangle.height);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_rectangle_int::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn += "<cairo.rectangle_int:";
	do {
		char buff[80];
		::sprintf(buff, "%d,%d,%d,%d",
				_rectangle.x, _rectangle.y, _rectangle.width, _rectangle.height);
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for rectangle_int
//-----------------------------------------------------------------------------
// cairo.rectangle_int(x?:number, y?:number, width?:number, height?:number) {block?}
Gura_DeclareFunction(rectangle_int)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(rectangle_int));
}

Gura_ImplementFunction(rectangle_int)
{
	cairo_rectangle_int_t rectangle;
	rectangle.x = args.IsNumber(0)? args.GetInt(0) : 0;
	rectangle.y = args.IsNumber(1)? args.GetInt(1) : 0;
	rectangle.width = args.IsNumber(2)? args.GetInt(2) : 0;
	rectangle.height = args.IsNumber(3)? args.GetInt(3) : 0;
	AutoPtr<Object_rectangle_int> pObj(new Object_rectangle_int(rectangle));
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// implementation of class rectangle_int
Gura_ImplementUserClass(rectangle_int)
{
	Gura_AssignFunction(rectangle_int);
}

}}
