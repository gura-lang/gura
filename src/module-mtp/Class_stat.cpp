//=============================================================================
// Gura class: mtp.stat
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Stat
//-----------------------------------------------------------------------------
Stat::Stat(const LIBMTP_file_t *fileInfo) : _cntRef(1),
	_fileName(fileInfo->filename), _fileSize(fileInfo->filesize),
	_dtModification(&fileInfo->modificationdate), _fileType(fileInfo->filetype)
{
}

Stat::Stat(const char *fileName, size_t fileSize, const DateTime &dtModification, LIBMTP_filetype_t fileType) :
	_fileName(fileName), _fileSize(fileSize),
	_dtModification(dtModification), _fileType(fileType)
{
}

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
	Gura_AssignProperty(stat, filename);
	Gura_AssignProperty(stat, mtime);
	Gura_AssignProperty(stat, size);
	// Assignment of method
	Gura_AssignMethod(stat, method1);
	// Assignment of value
	Gura_AssignValue(stat, Value(Reference()));
}

Gura_EndModuleScope(mtp)
