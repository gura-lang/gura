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
// Implementation of properties
//-----------------------------------------------------------------------------
// cairo.rectangle#height
Gura_DeclareProperty_RW(rectangle, height)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle, height)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	return Value(rectangle.height);
}

Gura_ImplementPropertySetter(rectangle, height)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	rectangle.height = value.GetDouble();
	return Value(rectangle.height);
}

// cairo.rectangle#width
Gura_DeclareProperty_RW(rectangle, width)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle, width)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	return Value(rectangle.width);
}

Gura_ImplementPropertySetter(rectangle, width)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	rectangle.width = value.GetDouble();
	return Value(rectangle.width);
}

// cairo.rectangle#x
Gura_DeclareProperty_RW(rectangle, x)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle, x)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	return Value(rectangle.x);
}

Gura_ImplementPropertySetter(rectangle, x)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	rectangle.x = value.GetDouble();
	return Value(rectangle.x);
}

// cairo.rectangle#y
Gura_DeclareProperty_RW(rectangle, y)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(rectangle, y)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	return Value(rectangle.y);
}

Gura_ImplementPropertySetter(rectangle, y)
{
	cairo_rectangle_t &rectangle =
		Object_rectangle::GetObject(valueThis)->GetEntity();
	rectangle.y = value.GetDouble();
	return Value(rectangle.y);
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
	rectangle.x = arg.Is_number(0)? arg.GetDouble(0) : 0;
	rectangle.y = arg.Is_number(1)? arg.GetDouble(1) : 0;
	rectangle.width = arg.Is_number(2)? arg.GetDouble(2) : 0;
	rectangle.height = arg.Is_number(3)? arg.GetDouble(3) : 0;
	AutoPtr<Object_rectangle> pObj(new Object_rectangle(rectangle));
	return ReturnValue(env, arg, Value(pObj.release()));
}

// implementation of class rectangle
Gura_ImplementUserClass(rectangle)
{
	// Assignment of properties
	Gura_AssignProperty(rectangle, height);
	Gura_AssignProperty(rectangle, width);
	Gura_AssignProperty(rectangle, x);
	Gura_AssignProperty(rectangle, y);
	Gura_AssignFunction(rectangle);
}

Gura_EndModuleScope(cairo)
