//=============================================================================
// Gura class: mtp.stat
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Implementation of Object_stat
//-----------------------------------------------------------------------------
Object_stat::Object_stat(Stat *pStat) : Object(Gura_UserClass(stat)), _pStat(pStat)
{
}

String Object_stat::ToString(bool exprFlag)
{
	String rtn = "<mtp.stat:";
	rtn += _pStat->GetFileName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.stat#dirname
Gura_DeclareProperty_R(stat, dirname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, dirname)
{
	const Stat *pStat = Object_stat::GetObject(valueThis)->GetStat();
	return Value(pStat->GetDirName());
}

// mtp.stat#filename
Gura_DeclareProperty_R(stat, filename)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, filename)
{
	const Stat *pStat = Object_stat::GetObject(valueThis)->GetStat();
	return Value(pStat->GetFileName());
}

// mtp.stat#isdir
Gura_DeclareProperty_R(stat, isdir)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, isdir)
{
	const Stat *pStat = Object_stat::GetObject(valueThis)->GetStat();
	return Value(pStat->IsFolder());
}

// mtp.stat#mtime
Gura_DeclareProperty_R(stat, mtime)
{
	SetPropAttr(VTYPE_datetime);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, mtime)
{
	const Stat *pStat = Object_stat::GetObject(valueThis)->GetStat();
	return Value(new Object_datetime(env, pStat->GetDtModification()));
}

// mtp.stat#pathname
Gura_DeclareProperty_R(stat, pathname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, pathname)
{
	const Stat *pStat = Object_stat::GetObject(valueThis)->GetStat();
	return Value(pStat->MakePathName());
}

// mtp.stat#size
Gura_DeclareProperty_R(stat, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, size)
{
	const Stat *pStat = Object_stat::GetObject(valueThis)->GetStat();
	return Value(pStat->GetFileSize());
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
	Gura_AssignProperty(stat, dirname);
	Gura_AssignProperty(stat, filename);
	Gura_AssignProperty(stat, isdir);
	Gura_AssignProperty(stat, mtime);
	Gura_AssignProperty(stat, pathname);
	Gura_AssignProperty(stat, size);
	// Assignment of method
	Gura_AssignMethod(stat, method1);
	// Assignment of value
	Gura_AssignValue(stat, Value(Reference()));
}

Gura_EndModuleScope(mtp)
