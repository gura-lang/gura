//-----------------------------------------------------------------------------
// Gura module: example
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(example)

//-----------------------------------------------------------------------------
// Object_foo implementation
//-----------------------------------------------------------------------------
Object_foo::~Object_foo()
{
}

Object *Object_foo::Clone() const
{
	return new Object_foo(*this);
}

String Object_foo::ToString(bool exprFlag)
{
	return String("<foo>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_foo
//-----------------------------------------------------------------------------
// example.foo#test()
Gura_DeclareMethod(foo, test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(foo, test)
{
	Object_foo *pThis = Object_foo::GetThisObj(args);
	return Value("foo object");
}

// implementation of class foo
Gura_ImplementUserClass(foo)
{
	Gura_AssignMethod(foo, test);
}

//-----------------------------------------------------------------------------
// Gura module functions: example
//-----------------------------------------------------------------------------
// example.foo()
Gura_DeclareFunction(foo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(foo)
{
	return Value(new Object_foo());
}

// result = example.adder(num1:number, num2:number)
Gura_DeclareFunction(adder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
}

Gura_ImplementFunction(adder)
{
	return Value(args.GetNumber(0) + args.GetNumber(1));
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(hoge_symbol);
	// class realization
	Gura_RealizeAndPrepareUserClass(foo, env.LookupClass(VTYPE_object));
	// value assignment
	Gura_AssignValue(foo, Value("a value in example module"));
	// function assignment
	Gura_AssignFunction(foo);
	Gura_AssignFunction(adder);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(example, example)

Gura_RegisterModule(example)
