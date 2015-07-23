#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle implementation
//-----------------------------------------------------------------------------
Object_rectangle::~Object_rectangle()
{
}

Object *Object_rectangle::Clone() const
{
	return nullptr;
}

bool Object_rectangle::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	symbols.insert(Gura_Symbol(width));
	symbols.insert(Gura_Symbol(height));
	return true;
}

Value Object_rectangle::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
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

Value Object_rectangle::DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_rectangle.x = value.GetDouble();
		return Value(_rectangle.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_rectangle.y = value.GetDouble();
		return Value(_rectangle.y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_rectangle.width = value.GetDouble();
		return Value(_rectangle.width);
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		_rectangle.height = value.GetDouble();
		return Value(_rectangle.height);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_rectangle::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<cairo.rectangle:";
	do {
		char buff[80];
		::sprintf(buff, "%f,%f,%f,%f",
				_rectangle.x, _rectangle.y, _rectangle.width, _rectangle.height);
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Gura interfaces for rectangle
//-----------------------------------------------------------------------------
// cairo.rectangle(x?:number, y?:number, width?:number, height?:number) {block?}
Gura_DeclareFunction(rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(rectangle));
}

Gura_ImplementFunction(rectangle)
{
	cairo_rectangle_t rectangle;
	rectangle.x = args.Is_number(0)? args.GetDouble(0) : 0;
	rectangle.y = args.Is_number(1)? args.GetDouble(1) : 0;
	rectangle.width = args.Is_number(2)? args.GetDouble(2) : 0;
	rectangle.height = args.Is_number(3)? args.GetDouble(3) : 0;
	AutoPtr<Object_rectangle> pObj(new Object_rectangle(rectangle));
	return ReturnValue(env, args, Value(pObj.release()));
}

// implementation of class rectangle
Gura_ImplementUserClass(rectangle)
{
	Gura_AssignFunction(rectangle);
}

Gura_EndModuleScope(cairo)
