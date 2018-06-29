//=============================================================================
// Gura class: mtp.storage
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Implementation of Object_storage
//-----------------------------------------------------------------------------
Object_storage::Object_storage() : Object(Gura_UserClass(storage))
{
}

String Object_storage::ToString(bool exprFlag)
{
	String rtn = "<mtp.storage:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.storage#prop1
Gura_DeclareProperty_R(storage, prop1)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, prop1)
{
	//Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// mtp.storage#method1()
Gura_DeclareMethod(storage, method1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "arg1", VTYPE_string);
	//DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(storage, method1)
{
	//Object_storage *pThis = Object_storage::GetObjectThis(arg);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class mtp.storage
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(storage)
{
	// Assignment of property
	Gura_AssignProperty(storage, prop1);
	// Assignment of method
	Gura_AssignMethod(storage, method1);
	// Assignment of value
	Gura_AssignValue(storage, Value(Reference()));
}

Gura_EndModuleScope(mtp)
