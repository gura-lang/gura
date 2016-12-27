#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle_int implementation
//-----------------------------------------------------------------------------
Object_rectangle_int::~Object_rectangle_int()
{
}

Object *Object_rectangle_int::Clone() const
{
	return nullptr;
}

bool Object_rectangle_int::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	symbols.insert(Gura_Symbol(width));
	symbols.insert(Gura_Symbol(height));
	return true;
}

Value Object_rectangle_int::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return Value::Nil;
}

Value Object_rectangle_int::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rectangle.x = value.GetInt();
		return Value(_rectangle.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rectangle.y = value.GetInt();
		return Value(_rectangle.y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rectangle.width = value.GetInt();
		return Value(_rectangle.width);
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_rectangle.height = value.GetInt();
		return Value(_rectangle.height);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_rectangle_int::ToString(bool exprFlag)
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
// Implementation of properties
//-----------------------------------------------------------------------------
// cairo.rectangle_int#height
Gura_DeclareProperty_RW(rectangle_int, height)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, height)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(rectangle_int, height)
{
	return Value::Nil;
}

// cairo.rectangle_int#width
Gura_DeclareProperty_RW(rectangle_int, width)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, width)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(rectangle_int, width)
{
	return Value::Nil;
}

// cairo.rectangle_int#x
Gura_DeclareProperty_RW(rectangle_int, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, x)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(rectangle_int, x)
{
	return Value::Nil;
}

// cairo.rectangle_int#y
Gura_DeclareProperty_RW(rectangle_int, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, y)
{
	return Value::Nil;
}

Gura_ImplementPropertySetter(rectangle_int, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for rectangle_int
//-----------------------------------------------------------------------------
// cairo.rectangle_int(x?:number, y?:number, width?:number, height?:number) {block?}
Gura_DeclareFunction(rectangle_int)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	rectangle.x = arg.Is_number(0)? arg.GetInt(0) : 0;
	rectangle.y = arg.Is_number(1)? arg.GetInt(1) : 0;
	rectangle.width = arg.Is_number(2)? arg.GetInt(2) : 0;
	rectangle.height = arg.Is_number(3)? arg.GetInt(3) : 0;
	AutoPtr<Object_rectangle_int> pObj(new Object_rectangle_int(rectangle));
	return ReturnValue(env, arg, Value(pObj.release()));
}

// implementation of class rectangle_int
Gura_ImplementUserClass(rectangle_int)
{
	// Assignment of properties
	Gura_AssignProperty(rectangle_int, height);
	Gura_AssignProperty(rectangle_int, width);
	Gura_AssignProperty(rectangle_int, x);
	Gura_AssignProperty(rectangle_int, y);
	Gura_AssignFunction(rectangle_int);
}

Gura_EndModuleScope(cairo)
