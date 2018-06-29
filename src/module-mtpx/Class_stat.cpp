//=============================================================================
// Gura class: mtp.stat
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Implementation of Object_stat
//-----------------------------------------------------------------------------
Object_stat::Object_stat() : Object(Gura_UserClass(stat))
{
}

String Object_stat::ToString(bool exprFlag)
{
	String rtn = "<mtp.stat:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.stat#prop1
Gura_DeclareProperty_R(stat, prop1)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, prop1)
{
	//Object_stat *pObjThis = Object_stat::GetObject(valueThis);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// mtp.stat#method1()
Gura_DeclareMethod(stat, method1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "arg1", VTYPE_string);
	//DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(stat, method1)
{
	//Object_stat *pThis = Object_stat::GetObjectThis(arg);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class mtp.stat
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(stat)
{
	// Assignment of property
	Gura_AssignProperty(stat, prop1);
	// Assignment of method
	Gura_AssignMethod(stat, method1);
	// Assignment of value
	Gura_AssignValue(stat, Value(Reference()));
}

Gura_EndModuleScope(mtp)
