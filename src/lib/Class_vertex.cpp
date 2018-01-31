//=============================================================================
// Gura class: vertex
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_vertex
//-----------------------------------------------------------------------------
Object_vertex::~Object_vertex()
{
}

Object *Object_vertex::Clone() const
{
	return new Object_vertex(*this);
}

String Object_vertex::ToString(bool exprFlag)
{
	String str;
	str += "<vertex:";
	str += _pVertex->ToString();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// vertex(x:number, y:number, z?:number):map {block?}
Gura_DeclareFunction(vertex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "z", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_vertex));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `vertex` instance that has the given coordinates `x`, `y` and `z`.\n"
		"The argument `z` is optional and set to zero if omitted.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementFunction(vertex)
{
	double x = arg.GetDouble(0);
	double y = arg.GetDouble(1);
	double z = arg.Is_number(2)? arg.GetDouble(2) : 0;
	return ReturnValue(env, arg,
					   Value(new Object_vertex(env, Vertex(x, y, z))));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// vertex#x
Gura_DeclareProperty_RW(vertex, x)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(vertex, x)
{
	const Vertex &vertex = Object_vertex::GetObject(valueThis)->GetVertex();
	return Value(vertex.x);
}

Gura_ImplementPropertySetter(vertex, x)
{
	Vertex &vertex = Object_vertex::GetObject(valueThis)->GetVertex();
	vertex.x = value.GetDouble();
	return Value(vertex.x);
}

// vertex#y
Gura_DeclareProperty_RW(vertex, y)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(vertex, y)
{
	const Vertex &vertex = Object_vertex::GetObject(valueThis)->GetVertex();
	return Value(vertex.y);
}

Gura_ImplementPropertySetter(vertex, y)
{
	Vertex &vertex = Object_vertex::GetObject(valueThis)->GetVertex();
	vertex.y = value.GetDouble();
	return Value(vertex.y);
}

// vertex#z
Gura_DeclareProperty_RW(vertex, z)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(vertex, z)
{
	const Vertex &vertex = Object_vertex::GetObject(valueThis)->GetVertex();
	return Value(vertex.z);
}

Gura_ImplementPropertySetter(vertex, z)
{
	Vertex &vertex = Object_vertex::GetObject(valueThis)->GetVertex();
	vertex.z = value.GetDouble();
	return Value(vertex.z);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// vertex.cross(v1:vertex, v2:vertex):map {block?}
Gura_DeclareClassMethod(vertex, cross)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "v1", VTYPE_vertex, OCCUR_Once);
	DeclareArg(env, "v2", VTYPE_vertex, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates cross product between `v1` and `v2`\n"
		"and returns the result as a `vertex` instance.\n");
}

Gura_ImplementClassMethod(vertex, cross)
{
	Vertex vRtn;
	Vertex::Cross(vRtn, Object_vertex::GetObject(arg, 0)->GetVertex(),
				  Object_vertex::GetObject(arg, 1)->GetVertex());
	return ReturnValue(env, arg, Value(new Object_vertex(env, vRtn)));
}

// vertex.dot(v1:vertex, v2:vertex):map {block?}
Gura_DeclareClassMethod(vertex, dot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "v1", VTYPE_vertex, OCCUR_Once);
	DeclareArg(env, "v2", VTYPE_vertex, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates dot product between `v1` and `v2`\n"
		"and returns the result as a `number` instance.\n");
}

Gura_ImplementClassMethod(vertex, dot)
{
	double rtn;
	Vertex::Dot(rtn, Object_vertex::GetObject(arg, 0)->GetVertex(),
				  Object_vertex::GetObject(arg, 1)->GetVertex());
	return ReturnValue(env, arg, Value(rtn));
}

// vertex#norm()
Gura_DeclareMethod(vertex, norm)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates norm of the vertex instance.");
}

Gura_ImplementMethod(vertex, norm)
{
	double rtn;
	Vertex::Norm(rtn, Object_vertex::GetObjectThis(arg)->GetVertex());
	return Value(rtn);
}

// vertex.normal(v1:vertex, v2:vertex, v3:vertex):map:[unit] {block?}
Gura_DeclareClassMethod(vertex, normal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "v1", VTYPE_vertex, OCCUR_Once);
	DeclareArg(env, "v2", VTYPE_vertex, OCCUR_Once);
	DeclareArg(env, "v3", VTYPE_vertex, OCCUR_Once);
	DeclareAttr(Gura_Symbol(unit));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a normal vector for a face that consists of three vertices given\n"
		"and returns it as a `vertex` instance.\n"
		"\n"
		"In default, it returns a vector before being regulated to have a length of one.\n"
		"Specifying the attribute `:unit` would apply the calculation.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementClassMethod(vertex, normal)
{
	Vertex vRtn;
	Vertex::Normal(vRtn,
				   Object_vertex::GetObject(arg, 0)->GetVertex(),
				   Object_vertex::GetObject(arg, 1)->GetVertex(),
				   Object_vertex::GetObject(arg, 2)->GetVertex(),
				   arg.IsSet(Gura_Symbol(unit)));
	return ReturnValue(env, arg, Value(new Object_vertex(env, vRtn)));
}

// vertex#rotate@x(angle:number):[deg] {block?}
Gura_DeclareMethodAlias(vertex, rotate_at_x, "rotate@x")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `vertex` that is rotated from the target `vertex`\n"
		"around X-axis by the specified `angle` in radian.\n"
		"It would be rotated in a direction of tilting Y-axis toward Z-axis.\n"
		"\n"
		"If the attribute `:deg` is specified, you can specify the `angle` in degree unit.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementMethod(vertex, rotate_at_x)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	return ReturnValue(env, arg, Value(new Object_vertex(env, vertex.RotateX(angle))));
}

// vertex#rotate@y(angle:number):[deg] {block?}
Gura_DeclareMethodAlias(vertex, rotate_at_y, "rotate@y")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `vertex` that is rotated from the target `vertex`\n"
		"around Y-axis by the specified `angle` in radian.\n"
		"It would be rotated in a direction of tilting Z-axis toward X-axis.\n"
		"\n"
		"If the attribute `:deg` is specified, you can specify the `angle` in degree unit.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementMethod(vertex, rotate_at_y)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	return ReturnValue(env, arg, Value(new Object_vertex(env, vertex.RotateY(angle))));
}

// vertex#rotate@z(angle:number):[deg] {block?}
Gura_DeclareMethodAlias(vertex, rotate_at_z, "rotate@z")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `vertex` that is rotated from the target `vertex`\n"
		"around Z-axis by the specified `angle` in radian.\n"
		"It would be rotated in a direction of tilting X-axis toward Y-axis.\n"
		"\n"
		"If the attribute `:deg` is specified, you can specify the `angle` in degree unit.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementMethod(vertex, rotate_at_z)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	return ReturnValue(env, arg, Value(new Object_vertex(env, vertex.RotateZ(angle))));
}

// vertex#list() {block?}
Gura_DeclareMethod(vertex, list)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `list` that contains coordinate values `[x, y, z]` of the target `vertex`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("list", "list"));
}

Gura_ImplementMethod(vertex, list)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	return ReturnValue(
		env, arg, Value::CreateList(
			env, Value(vertex.x), Value(vertex.y), Value(vertex.z)));
}

// vertex#translate(tx:number, ty:number, tz?:number) {block?}
Gura_DeclareMethod(vertex, translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "tx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ty", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `vertex` that is translated from the target `vertex`\n"
		"by the specified offsets `tx`, `ty` and `tz`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementMethod(vertex, translate)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	double tx = arg.GetDouble(0);
	double ty = arg.GetDouble(1);
	double tz = arg.Is_number(2)? arg.GetDouble(2) : 0;
	return ReturnValue(env, arg, Value(new Object_vertex(env, vertex.Translate(tx, ty, tz))));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_vertex::Class_vertex(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_vertex)
{
}

void Class_vertex::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(vertex);
	// Assignment of properties
	Gura_AssignProperty(vertex, x);
	Gura_AssignProperty(vertex, y);
	Gura_AssignProperty(vertex, z);
	// Assignment of methods
	Gura_AssignMethod(vertex, cross);
	Gura_AssignMethod(vertex, dot);
	Gura_AssignMethod(vertex, norm);
	Gura_AssignMethod(vertex, normal);
	Gura_AssignMethod(vertex, rotate_at_x);
	Gura_AssignMethod(vertex, rotate_at_y);
	Gura_AssignMethod(vertex, rotate_at_z);
	Gura_AssignMethod(vertex, list);
	Gura_AssignMethod(vertex, translate);
	// Assignment of value
	Gura_AssignClassValue(zero, Value(new Object_vertex(env, Vertex::Zero)));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

bool Class_vertex::CastFrom(Environment &env, Value &value, ULong flags)
{
	if (value.Is_list()) {
		//const ValueList &valList = value.GetList();
	}
	return false;
}

Object *Class_vertex::CreateDescendant(Environment &env, Class *pClass)
{
	//return new Object_vertex((pClass == nullptr)? this : pClass);
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
