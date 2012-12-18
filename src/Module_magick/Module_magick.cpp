//-----------------------------------------------------------------------------
// Gura magick module
//-----------------------------------------------------------------------------
#include "Module_magick.h"

Gura_BeginModule(magick)

//-----------------------------------------------------------------------------
// Gura module functions: magick
//-----------------------------------------------------------------------------
// magick.skeleton()
Gura_DeclareFunction(skeleton)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(skeleton)
{
	return Value::Null;
}

// result = magick.adder(num1:number, num2:number)
Gura_DeclareFunction(adder)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
}

Gura_ImplementFunction(adder)
{
	return Value(args.GetNumber(0) + args.GetNumber(1));
}

// result = magick.adder2(num1:number, num2:number):map
// automapping version of adder(). see differences in their implementations.
Gura_DeclareFunction(adder2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
}

Gura_ImplementFunction(adder2)
{
	return Value(args.GetNumber(0) + args.GetNumber(1));
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(hoge_symbol);
	// value assignment
	Gura_AssignValue(foo, Value(env, "a value in magick module"));
	// function assignment
	Gura_AssignFunction(skeleton);
	Gura_AssignFunction(adder);
	Gura_AssignFunction(adder2);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(magick, magick)

Gura_RegisterModule(magick)
