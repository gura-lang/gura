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
	symbols.insert(Gura_Symbol(w));
	return true;
}

Value Object_vertex::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_vertex.x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_vertex.y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(z))) {
		return Value(_vertex.z);
	} else if (pSymbol->IsIdentical(Gura_Symbol(w))) {
		return Value(_vertex.w);
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
		_vertex.x = x;
		return Value(x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double y = value.GetDouble();
		_vertex.y = y;
		return Value(y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(z))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double z = value.GetDouble();
		_vertex.z = z;
		return Value(z);
	} else if (pSymbol->IsIdentical(Gura_Symbol(w))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		evaluatedFlag = true;
		double w = value.GetDouble();
		_vertex.w = w;
		return Value(w);
	}
	return Value::Nil;
}

String Object_vertex::ToString(bool exprFlag)
{
	String str;
	str += "<vertex:";
	str += _vertex.ToString();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// vertex(x:number, y:number, z?:number, w?:number):map {block?}
Gura_DeclareFunction(vertex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "z", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "w", VTYPE_number, OCCUR_ZeroOrOnce);
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
	double w = arg.Is_number(3)? arg.GetDouble(3) : 1;
	return ReturnValue(env, arg,
					   Value(new Object_vertex(env, Vertex(x, y, z, w))));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// vertex#tolist():[w] {block?}
Gura_DeclareMethod(vertex, tolist)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(w));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(vertex, tolist)
{
	const Vertex &vertex = Object_vertex::GetObjectThis(arg)->GetVertex();
	if (arg.IsSet(Gura_Symbol(w))) {
		return ReturnValue(
			env, arg, Value::CreateList(
				env, Value(vertex.x), Value(vertex.y), Value(vertex.z), Value(vertex.w)));
	} else {
		return ReturnValue(
			env, arg, Value::CreateList(
				env, Value(vertex.x), Value(vertex.y), Value(vertex.z)));
	}
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_vertex::Class_vertex(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_vertex)
{
}

void Class_vertex::Prepare(Environment &env)
{
	Gura_AssignMethod(vertex, tolist);
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
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
