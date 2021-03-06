//=============================================================================
// Gura class: argument
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
# Overview

The `argument` class provides measures to access argument information that is passed to a function.
One of its purposes is to check if an attribute is specified in the function call.
It also provides a method to control a leader-trailer sequence,
a mechanism that flow controls such as `if-elsif-else` and `try-catch` utilize.

There's no constructor to realize an instance of `argument` class.
Its instance is implicitly created when a function is called,
and you can refer to it by a variable named `__arg__`.

Below is an example to use `argument` class:

    func(v0, v1, v2):[attr1,attr2] = {
        printf('arg#%d %s\n', 0.., __arg__.values)
        printf('attr1:%s attr2:%s\n', __arg__.isset(`attr1), __arg__.isset(`attr2))
    }

# Property

An `argument` instance has the following properties:

${markdown.makedoc@property(`en, argument)}


# Method

${markdown.makedoc@function(`en
argument.finalize_trailer
argument.isset
argument.quit_trailer
)}
)**";

//-----------------------------------------------------------------------------
// Object_argument
//-----------------------------------------------------------------------------
Object *Object_argument::Clone() const
{
	return new Object_argument(*this);
}

String Object_argument::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<argument:";
	::sprintf(buff, "%ldslots", _pArg->CountSlot());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// argument#function
Gura_DeclareProperty_R(argument, function)
{
	SetPropAttr(VTYPE_function);
	AddHelp(
		Gura_Symbol(en),
		"The `function` instance that has created the argument."
		);
}

Gura_ImplementPropertyGetter(argument, function)
{
	Argument *pArg = Object_argument::GetObject(valueThis)->GetArgument();
	return Value(new Object_function(env, pArg->GetFunction()->Reference()));
}

// argument#values
Gura_DeclareProperty_R(argument, values)
{
	SetPropAttr(VTYPE_function);
	AddHelp(
		Gura_Symbol(en),
		"A list of argument values."
		);
}

Gura_ImplementPropertyGetter(argument, values)
{
	Argument *pArg = Object_argument::GetObject(valueThis)->GetArgument();
	Value rtn;
	pArg->GetSlotValues(rtn.InitAsList(env));
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// argument#finalize_trailer():void
Gura_DeclareMethod(arg, finalize_trailer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Signals finalizing status to trailers after the current function.");
}

Gura_ImplementMethod(arg, finalize_trailer)
{
	//Argument *pArg = Object_argument::GetObjectThis(arg)->GetArgument();
	//pArg->FinalizeTrailer();
	env.SetError(ERR_NotImplementedError, "not implemented yet");
	return Value::Nil;
}

// argument#isset(symbol:symbol)
Gura_DeclareMethod(arg, isset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), 
		"Returns `true` if the function is called with an attribute\n"
		"that matches the specified symbol.\n");
}

Gura_ImplementMethod(arg, isset)
{
	Argument *pArg = Object_argument::GetObjectThis(arg)->GetArgument();
	bool rtn = pArg->IsSet(arg.GetSymbol(0));
	return Value(rtn);
}

// argument#quit_trailer():void
Gura_DeclareMethod(arg, quit_trailer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Cancels evaluation of following trailers.\n"
		"\n"
		"Example:\n"
		"\n"
		"    f(flag:boolean) = {\n"
		"        !flag && __arg__.quit_trailer() \n"
		"    }\n"
		"    \n"
		"    f(true) println('printed')\n"
		"    f(false) println('not printed')\n"
		);
}

Gura_ImplementMethod(arg, quit_trailer)
{
	Argument *pArg = Object_argument::GetObjectThis(arg)->GetArgument();
	pArg->QuitTrailer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Implementation of class
//----------------------------------------------------------------------------
Class_argument::Class_argument(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_argument)
{
}

void Class_argument::DoPrepare(Environment &env)
{
	// Assignment of value
	Gura_AssignValue(argument, Value(Reference()));
	// Assignment of properties
	Gura_AssignProperty(argument, function);
	Gura_AssignProperty(argument, values);
	// Assignment of methods
	Gura_AssignMethod(arg, finalize_trailer);
	Gura_AssignMethod(arg, isset);
	Gura_AssignMethod(arg, quit_trailer);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_argument::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
