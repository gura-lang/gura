//=============================================================================
// Gura class: error
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_error
//-----------------------------------------------------------------------------
Object_error::Object_error(const Object_error &obj) : Object(obj), _err(obj._err)
{
}

Object *Object_error::Clone() const
{
	return new Object_error(*this);
}

String Object_error::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<error:";
	rtn += _err.GetTypeName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// error#source
Gura_DeclareProperty_R(error, source)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(error, source)
{
	const Gura::Error &err = Object_error::GetObject(valueThis)->GetError();
	const char *sourceName = err.GetSourceName();
	if (sourceName == nullptr) return Value::Nil;
	return Value(sourceName);
}

// error#lineno
Gura_DeclareProperty_R(error, lineno)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(error, lineno)
{
	const Gura::Error &err = Object_error::GetObject(valueThis)->GetError();
	return Value(err.GetLineNoTop());
}

// error#linenobtm
Gura_DeclareProperty_R(error, linenobtm)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(error, linenobtm)
{
	const Gura::Error &err = Object_error::GetObject(valueThis)->GetError();
	return Value(err.GetLineNoBtm());
}

// error#postext
Gura_DeclareProperty_R(error, postext)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(error, postext)
{
	const Gura::Error &err = Object_error::GetObject(valueThis)->GetError();
	return Value(err.MakePosText());
}

// error#text:[lineno]
Gura_DeclareProperty_R(error, text)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(error, text)
{
	const Gura::Error &err = Object_error::GetObject(valueThis)->GetError();
	bool lineInfoFlag = attrs.IsSet(Gura_Symbol(lineno));
	return Value(err.MakeText(lineInfoFlag));
}

// error#trace
Gura_DeclareProperty_R(error, trace)
{
	SetPropAttr(VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(error, trace)
{
	const Gura::Error &err = Object_error::GetObject(valueThis)->GetError();
	AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
	err.GetExprCauseOwner().ExtractTrace(*pExprOwner);
	return Value(new Object_iterator(env, new ExprOwner::Iterator(pExprOwner.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_error::Class_error(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_error)
{
}

void Class_error::DoPrepare(Environment &env)
{
	// Assignment of error types
	Error::AssignErrorTypes(*this);
	// Assignment of properties
	Gura_AssignProperty(error, source);
	Gura_AssignProperty(error, lineno);
	Gura_AssignProperty(error, linenobtm);
	Gura_AssignProperty(error, postext);
	Gura_AssignProperty(error, text);
	Gura_AssignProperty(error, trace);
	// Assignment of values
	Gura_AssignValue(error, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_error::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
