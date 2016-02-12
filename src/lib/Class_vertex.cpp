//=============================================================================
// Gura class: vertex
//=============================================================================
#include "stdafx.h"

namespace Gura {

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

bool Object_vertex::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	symbols.insert(Gura_Symbol(z));
	return true;
}

Value Object_vertex::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_pVertex->x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_pVertex->y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(z))) {
		return Value(_pVertex->z);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_vertex::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double x = value.GetDouble();
		_pVertex->x = x;
		return Value(x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double y = value.GetDouble();
		_pVertex->y = y;
		return Value(y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(z))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double z = value.GetDouble();
		_pVertex->z = z;
		return Value(z);
	}
	return Value::Nil;
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
		Gura_Symbol(en), Help::FMT_markdown,
		"");
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
// Implementation of methods
//-----------------------------------------------------------------------------
// vertex.normal(v1:vertex, v2:vertex, v3:vertex):[unit] {block?}
Gura_DeclareClassMethod(vertex, normal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "v1", VTYPE_vertex, OCCUR_Once);
	DeclareArg(env, "v2", VTYPE_vertex, OCCUR_Once);
	DeclareArg(env, "v3", VTYPE_vertex, OCCUR_Once);
	DeclareAttr(Gura_Symbol(unit));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementClassMethod(vertex, normal)
{
	const Vertex &v1 = Object_vertex::GetObject(arg, 0)->GetVertex();
	const Vertex &v2 = Object_vertex::GetObject(arg, 1)->GetVertex();
	const Vertex &v3 = Object_vertex::GetObject(arg, 2)->GetVertex();
	bool unitFlag = arg.IsSet(Gura_Symbol(unit));
	return ReturnValue(
		env, arg, Value(new Object_vertex(env, Vertex::CalcNormal(v1, v2, v3, unitFlag))));
}

// vertex#rotate@x(angle:number):[deg] {block?}
Gura_DeclareMethodAlias(vertex, rotate_x, "rotate@x")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `vertex` that is rotated from the target `vertex`\n"
		"around X-axis by the specified `angle` in radian.\n"
		"It would be rotated in a direction of tilting Y-axis toward Z-axis.\n"
		"\n"
		"If the attribute `:deg` is specified, you can specify the `angle` in degree unit.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementMethod(vertex, rotate_x)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	return ReturnValue(env, arg, Value(new Object_vertex(env, vertex.RotateX(angle))));
}

// vertex#rotate@y(angle:number):[deg] {block?}
Gura_DeclareMethodAlias(vertex, rotate_y, "rotate@y")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `vertex` that is rotated from the target `vertex`\n"
		"around Y-axis by the specified `angle` in radian.\n"
		"It would be rotated in a direction of tilting Z-axis toward X-axis.\n"
		"\n"
		"If the attribute `:deg` is specified, you can specify the `angle` in degree unit.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementMethod(vertex, rotate_y)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	return ReturnValue(env, arg, Value(new Object_vertex(env, vertex.RotateY(angle))));
}

// vertex#rotate@z(angle:number):[deg] {block?}
Gura_DeclareMethodAlias(vertex, rotate_z, "rotate@z")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `vertex` that is rotated from the target `vertex`\n"
		"around Z-axis by the specified `angle` in radian.\n"
		"It would be rotated in a direction of tilting X-axis toward Y-axis.\n"
		"\n"
		"If the attribute `:deg` is specified, you can specify the `angle` in degree unit.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("v", "vertex"));
}

Gura_ImplementMethod(vertex, rotate_z)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	return ReturnValue(env, arg, Value(new Object_vertex(env, vertex.RotateZ(angle))));
}

// vertex#tolist() {block?}
Gura_DeclareMethod(vertex, tolist)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `list` that contains coordinate values `[x, y, z]` of the target `vertex`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("list", "list"));
}

Gura_ImplementMethod(vertex, tolist)
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
		Gura_Symbol(en), Help::FMT_markdown,
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
Class_vertex::Class_vertex(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_vertex)
{
}

void Class_vertex::Prepare(Environment &env)
{
	Gura_AssignMethod(vertex, normal);
	Gura_AssignMethod(vertex, rotate_x);
	Gura_AssignMethod(vertex, rotate_y);
	Gura_AssignMethod(vertex, rotate_z);
	Gura_AssignMethod(vertex, tolist);
	Gura_AssignMethod(vertex, translate);
	Gura_AssignFunction(vertex);
	Gura_AssignClassValue(zero, Value(new Object_vertex(env, Vertex::Zero)));
}

bool Class_vertex::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
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
