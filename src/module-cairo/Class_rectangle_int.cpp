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
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, height)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	return Value(rectangle.height);
}

Gura_ImplementPropertySetter(rectangle_int, height)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	rectangle.height = value.GetInt();
	return Value(rectangle.height);
}

// cairo.rectangle_int#width
Gura_DeclareProperty_RW(rectangle_int, width)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, width)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	return Value(rectangle.width);
}

Gura_ImplementPropertySetter(rectangle_int, width)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	rectangle.width = value.GetInt();
	return Value(rectangle.width);
}

// cairo.rectangle_int#x
Gura_DeclareProperty_RW(rectangle_int, x)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, x)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	return Value(rectangle.x);
}

Gura_ImplementPropertySetter(rectangle_int, x)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	rectangle.x = value.GetInt();
	return Value(rectangle.x);
}

// cairo.rectangle_int#y
Gura_DeclareProperty_RW(rectangle_int, y)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle_int, y)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	return Value(rectangle.y);
}

Gura_ImplementPropertySetter(rectangle_int, y)
{
	cairo_rectangle_int_t &rectangle =
		Object_rectangle_int::GetObject(valueThis)->GetEntity();
	rectangle.y = value.GetInt();
	return Value(rectangle.y);
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
