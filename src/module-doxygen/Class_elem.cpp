//=============================================================================
// Class_elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_elem
//-----------------------------------------------------------------------------
Object_elem::~Object_elem()
{
}

Object *Object_elem::Clone() const
{
	return nullptr;
}

bool Object_elem::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return _pElem->DoDirProp(env, symbols);
}

Value Object_elem::DoGetProp(Environment &env, const Symbol *pSymbol,
							 const SymbolSet &attrs, bool &evaluatedFlag)
{
	return _pElem->DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Object_elem::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.elem:";
	rtn += _pElem->MakeTypeName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// doxygen.elem#index
Gura_DeclareProperty_R(elem, index)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(elem, index)
{
	const Elem *pElem = Object_elem::GetObject(valueThis)->GetElem();
	return Value(pElem->GetIndex());
}

// doxygen.elem#next
Gura_DeclareProperty_R(elem, next)
{
	SetPropAttr(VTYPE_elem, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(elem, next)
{
	const Elem *pElem = Object_elem::GetObject(valueThis)->GetElem();
	const Elem *pElemNext = pElem->GetElemNext();
	return (pElemNext == nullptr)? Value::Nil : Value(new Object_elem(pElemNext->Reference()));
}

// doxygen.elem#prev
Gura_DeclareProperty_R(elem, prev)
{
	SetPropAttr(VTYPE_elem, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(elem, prev)
{
	const Elem *pElem = Object_elem::GetObject(valueThis)->GetElem();
	const Elem *pElemPrev = pElem->GetElemPrev();
	return (pElemPrev == nullptr)? Value::Nil : Value(new Object_elem(pElemPrev->Reference()));
}

// doxygen.elem#typename
Gura_DeclarePropertyAlias_R(elem, typename_, "typename")
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(elem, typename_)
{
	const Elem *pElem = Object_elem::GetObject(valueThis)->GetElem();
	return Value(pElem->MakeTypeName());
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.elem#isstreakfirst()
Gura_DeclareMethod(elem, isstreakfirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target element is at the first in a streak of\n"
		"elements of the same type.\n");
}

Gura_ImplementMethod(elem, isstreakfirst)
{
	const Elem *pElem = Object_elem::GetObjectThis(arg)->GetElem();
	return Value(pElem->IsStreakFirst());
}

// doxygen.elem#isstreaklast()
Gura_DeclareMethod(elem, isstreaklast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target element is at the last in a streak of\n"
		"elements of the same type.\n");
}

Gura_ImplementMethod(elem, isstreaklast)
{
	const Elem *pElem = Object_elem::GetObjectThis(arg)->GetElem();
	return Value(pElem->IsStreakLast());
}

// doxygen.elem#print(indent?:number, out?:stream):void
Gura_DeclareMethod(elem, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Prints out the content of the element to `out` with an indentation level\n"
		"specified by `indent` that starts from zero.\n"
		"If `out` is omitted, the result would be put out to standard output.\n");
}

Gura_ImplementMethod(elem, print)
{
	const Elem *pElem = Object_elem::GetObjectThis(arg)->GetElem();
	int indentLevel = arg.IsValid(0)? arg.GetInt(0) : 0;
	Stream &stream = arg.IsValid(1)? arg.GetStream(1) : *env.GetConsole();
	pElem->Print(env, stream, indentLevel);
	return Value::Nil;
}

// doxygen.elem#render(renderer:doxygen.renderer):void
Gura_DeclareMethod(elem, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_renderer, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Renders the element content using `doxygen.renderer`.\n");
}

Gura_ImplementMethod(elem, render)
{
	const Elem *pElem = Object_elem::GetObjectThis(arg)->GetElem();
	Renderer *pRenderer = Object_renderer::GetObject(arg, 0)->GetRenderer();
	pElem->Render(pRenderer);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.elem
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(elem)
{
	// Assignment of properties
	Gura_AssignProperty(elem, index);
	Gura_AssignProperty(elem, next);
	Gura_AssignProperty(elem, prev);
	Gura_AssignProperty(elem, typename_);
	// Assignment of methods
	Gura_AssignMethod(elem, isstreakfirst);
	Gura_AssignMethod(elem, isstreaklast);
	Gura_AssignMethod(elem, print);
	Gura_AssignMethod(elem, render);
	// Assignment of value
	Gura_AssignValue(elem, Value(Reference()));
}

Gura_EndModuleScope(doxygen)
