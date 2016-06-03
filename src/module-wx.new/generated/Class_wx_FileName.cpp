//----------------------------------------------------------------------------
// wxFileName
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileName
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileName
//----------------------------------------------------------------------------
Object_wx_FileName::~Object_wx_FileName()
{
}

Object *Object_wx_FileName::Clone() const
{
	return nullptr;
}

String Object_wx_FileName::ToString(bool exprFlag)
{
	String rtn("<wx.FileName:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxFileName, "wxFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileName)
{
	//wxFileName();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFileName_1, "wxFileName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileName_1)
{
	//int filename = arg.GetNumber(0)
	//wxFileName();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFileName_2, "wxFileName_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileName_2)
{
	//int fullpath = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//wxFileName();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFileName_3, "wxFileName_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileName_3)
{
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//wxFileName();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFileName_4, "wxFileName_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileName_4)
{
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int ext = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//wxFileName();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFileName_5, "wxFileName_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileName));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileName_5)
{
	//int volume = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//wxFileName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileName, __AppendDir, "AppendDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __AppendDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->AppendDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Assign, "Assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Assign)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filepath = arg.GetNumber(0)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Assign_1, "Assign_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Assign_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Assign_2, "Assign_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasExt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Assign_2)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int hasExt = arg.GetNumber(4)
	//int format = arg.GetNumber(5)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Assign_3, "Assign_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Assign_3)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Assign_4, "Assign_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Assign_4)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Assign_5, "Assign_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Assign_5)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int ext = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __AssignCwd, "AssignCwd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __AssignCwd)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//pThis->GetEntity()->AssignCwd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __AssignDir, "AssignDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __AssignDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->AssignDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __AssignHomeDir, "AssignHomeDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __AssignHomeDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AssignHomeDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __AssignTempFileName, "AssignTempFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __AssignTempFileName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//pThis->GetEntity()->AssignTempFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __AssignTempFileName_1, "AssignTempFileName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __AssignTempFileName_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->AssignTempFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __AssignTempFileName_2, "AssignTempFileName_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __AssignTempFileName_2)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->AssignTempFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __Clear)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __ClearExt, "ClearExt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __ClearExt)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearExt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __CreateTempFileName, "CreateTempFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __CreateTempFileName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->CreateTempFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __CreateTempFileName_1, "CreateTempFileName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __CreateTempFileName_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->CreateTempFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __DirExists, "DirExists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __DirExists)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DirExists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __DirExists_1, "DirExists_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __DirExists_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->DirExists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __DirName, "DirName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __DirName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->DirName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __DontFollowLink, "DontFollowLink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __DontFollowLink)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DontFollowLink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Exists, "Exists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Exists)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Exists_1, "Exists_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Exists_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __FileExists, "FileExists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __FileExists)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FileExists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __FileExists_1, "FileExists_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __FileExists_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->FileExists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __FileName, "FileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __FileName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->FileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetCwd, "GetCwd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetCwd)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//pThis->GetEntity()->GetCwd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetDirCount, "GetDirCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetDirCount)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetDirs, "GetDirs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetDirs)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetExt, "GetExt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetExt)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetForbiddenChars, "GetForbiddenChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetForbiddenChars)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetForbiddenChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetFormat, "GetFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetFormat)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetFullName, "GetFullName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetFullName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFullName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetFullPath, "GetFullPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetFullPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetFullPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetHomeDir, "GetHomeDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetHomeDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHomeDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetHumanReadableSize, "GetHumanReadableSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "failmsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetHumanReadableSize)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int failmsg = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->GetHumanReadableSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetHumanReadableSize_1, "GetHumanReadableSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bytes", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nullsize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetHumanReadableSize_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bytes = arg.GetNumber(0)
	//int nullsize = arg.GetNumber(1)
	//int precision = arg.GetNumber(2)
	//int conv = arg.GetNumber(3)
	//pThis->GetEntity()->GetHumanReadableSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetLongPath, "GetLongPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetLongPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetModificationTime, "GetModificationTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetModificationTime)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModificationTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetPathSeparator, "GetPathSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetPathSeparator)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetPathSeparators, "GetPathSeparators")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetPathSeparators)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathSeparators();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetPathTerminators, "GetPathTerminators")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetPathTerminators)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathTerminators();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetPathWithSep, "GetPathWithSep")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetPathWithSep)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathWithSep();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetShortPath, "GetShortPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetShortPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShortPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetSize)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetSize_1, "GetSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetSize_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetTempDir, "GetTempDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetTempDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTempDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetTimes, "GetTimes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dtAccess", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtMod", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtCreate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetTimes)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dtAccess = arg.GetNumber(0)
	//int dtMod = arg.GetNumber(1)
	//int dtCreate = arg.GetNumber(2)
	//pThis->GetEntity()->GetTimes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetVolume, "GetVolume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __GetVolume)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVolume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetVolumeSeparator, "GetVolumeSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetVolumeSeparator)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetVolumeSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __GetVolumeString, "GetVolumeString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "drive", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __GetVolumeString)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int drive = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->GetVolumeString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __HasExt, "HasExt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __HasExt)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasExt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __HasName, "HasName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __HasName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __HasVolume, "HasVolume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __HasVolume)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasVolume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __InsertDir, "InsertDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __InsertDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->InsertDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsAbsolute, "IsAbsolute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsAbsolute)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsAbsolute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsCaseSensitive, "IsCaseSensitive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsCaseSensitive)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsCaseSensitive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsDir, "IsDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __IsDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsDirReadable, "IsDirReadable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __IsDirReadable)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDirReadable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsDirReadable_1, "IsDirReadable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsDirReadable_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->IsDirReadable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsDirWritable, "IsDirWritable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __IsDirWritable)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDirWritable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsDirWritable_1, "IsDirWritable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsDirWritable_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->IsDirWritable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsFileExecutable, "IsFileExecutable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __IsFileExecutable)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFileExecutable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsFileExecutable_1, "IsFileExecutable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsFileExecutable_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->IsFileExecutable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsFileReadable, "IsFileReadable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __IsFileReadable)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFileReadable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsFileReadable_1, "IsFileReadable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsFileReadable_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->IsFileReadable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsFileWritable, "IsFileWritable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __IsFileWritable)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFileWritable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsFileWritable_1, "IsFileWritable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsFileWritable_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->IsFileWritable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __IsOk)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsPathSeparator, "IsPathSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsPathSeparator)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->IsPathSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsMSWUniqueVolumeNamePath, "IsMSWUniqueVolumeNamePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsMSWUniqueVolumeNamePath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->IsMSWUniqueVolumeNamePath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __IsRelative, "IsRelative")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __IsRelative)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsRelative();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __MakeAbsolute, "MakeAbsolute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cwd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __MakeAbsolute)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cwd = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->MakeAbsolute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __MakeRelativeTo, "MakeRelativeTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pathBase", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __MakeRelativeTo)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pathBase = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->MakeRelativeTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Mkdir, "Mkdir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "perm", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Mkdir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int perm = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Mkdir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Mkdir_1, "Mkdir_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "perm", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Mkdir_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int perm = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Mkdir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Normalize, "Normalize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cwd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Normalize)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int cwd = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Normalize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __PrependDir, "PrependDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __PrependDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->PrependDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __RemoveDir, "RemoveDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __RemoveDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __RemoveLastDir, "RemoveLastDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __RemoveLastDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RemoveLastDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __ReplaceEnvVariable, "ReplaceEnvVariable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "envname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacementFmtString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __ReplaceEnvVariable)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int envname = arg.GetNumber(0)
	//int replacementFmtString = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->ReplaceEnvVariable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __ReplaceHomeDir, "ReplaceHomeDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __ReplaceHomeDir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceHomeDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Rmdir, "Rmdir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Rmdir)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Rmdir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Rmdir_1, "Rmdir_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __Rmdir_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Rmdir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SameAs, "SameAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filepath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SameAs)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filepath = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->SameAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetCwd, "SetCwd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __SetCwd)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetCwd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetCwd_1, "SetCwd_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cwd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetCwd_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cwd = arg.GetNumber(0)
	//pThis->GetEntity()->SetCwd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetEmptyExt, "SetEmptyExt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __SetEmptyExt)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetEmptyExt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetExt, "SetExt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetExt)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ext = arg.GetNumber(0)
	//pThis->GetEntity()->SetExt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetFullName, "SetFullName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetFullName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fullname = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetName)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetPermissions, "SetPermissions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "permissions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetPermissions)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int permissions = arg.GetNumber(0)
	//pThis->GetEntity()->SetPermissions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetTimes, "SetTimes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dtAccess", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtMod", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtCreate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetTimes)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dtAccess = arg.GetNumber(0)
	//int dtMod = arg.GetNumber(1)
	//int dtCreate = arg.GetNumber(2)
	//pThis->GetEntity()->SetTimes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SetVolume, "SetVolume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SetVolume)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//pThis->GetEntity()->SetVolume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __ShouldFollowLink, "ShouldFollowLink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __ShouldFollowLink)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldFollowLink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SplitPath, "SplitPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasExt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SplitPath)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int volume = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//int ext = arg.GetNumber(4)
	//int hasExt = arg.GetNumber(5)
	//int format = arg.GetNumber(6)
	//pThis->GetEntity()->SplitPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SplitPath_1, "SplitPath_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SplitPath_1)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int volume = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//int ext = arg.GetNumber(4)
	//int format = arg.GetNumber(5)
	//pThis->GetEntity()->SplitPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SplitPath_2, "SplitPath_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SplitPath_2)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->SplitPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __SplitVolume, "SplitVolume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __SplitVolume)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int volume = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->SplitVolume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __StripExtension, "StripExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, __StripExtension)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fullname = arg.GetNumber(0)
	//pThis->GetEntity()->StripExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileName, __Touch, "Touch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, __Touch)
{
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Touch();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileName
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileName)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFileName);
	Gura_AssignFunction(__wxFileName_1);
	Gura_AssignFunction(__wxFileName_2);
	Gura_AssignFunction(__wxFileName_3);
	Gura_AssignFunction(__wxFileName_4);
	Gura_AssignFunction(__wxFileName_5);
	// Method assignment
	Gura_AssignMethod(wx_FileName, __AppendDir);
	Gura_AssignMethod(wx_FileName, __Assign);
	Gura_AssignMethod(wx_FileName, __Assign_1);
	Gura_AssignMethod(wx_FileName, __Assign_2);
	Gura_AssignMethod(wx_FileName, __Assign_3);
	Gura_AssignMethod(wx_FileName, __Assign_4);
	Gura_AssignMethod(wx_FileName, __Assign_5);
	Gura_AssignMethod(wx_FileName, __AssignCwd);
	Gura_AssignMethod(wx_FileName, __AssignDir);
	Gura_AssignMethod(wx_FileName, __AssignHomeDir);
	Gura_AssignMethod(wx_FileName, __AssignTempFileName);
	Gura_AssignMethod(wx_FileName, __AssignTempFileName_1);
	Gura_AssignMethod(wx_FileName, __AssignTempFileName_2);
	Gura_AssignMethod(wx_FileName, __Clear);
	Gura_AssignMethod(wx_FileName, __ClearExt);
	Gura_AssignMethod(wx_FileName, __CreateTempFileName);
	Gura_AssignMethod(wx_FileName, __CreateTempFileName_1);
	Gura_AssignMethod(wx_FileName, __DirExists);
	Gura_AssignMethod(wx_FileName, __DirExists_1);
	Gura_AssignMethod(wx_FileName, __DirName);
	Gura_AssignMethod(wx_FileName, __DontFollowLink);
	Gura_AssignMethod(wx_FileName, __Exists);
	Gura_AssignMethod(wx_FileName, __Exists_1);
	Gura_AssignMethod(wx_FileName, __FileExists);
	Gura_AssignMethod(wx_FileName, __FileExists_1);
	Gura_AssignMethod(wx_FileName, __FileName);
	Gura_AssignMethod(wx_FileName, __GetCwd);
	Gura_AssignMethod(wx_FileName, __GetDirCount);
	Gura_AssignMethod(wx_FileName, __GetDirs);
	Gura_AssignMethod(wx_FileName, __GetExt);
	Gura_AssignMethod(wx_FileName, __GetForbiddenChars);
	Gura_AssignMethod(wx_FileName, __GetFormat);
	Gura_AssignMethod(wx_FileName, __GetFullName);
	Gura_AssignMethod(wx_FileName, __GetFullPath);
	Gura_AssignMethod(wx_FileName, __GetHomeDir);
	Gura_AssignMethod(wx_FileName, __GetHumanReadableSize);
	Gura_AssignMethod(wx_FileName, __GetHumanReadableSize_1);
	Gura_AssignMethod(wx_FileName, __GetLongPath);
	Gura_AssignMethod(wx_FileName, __GetModificationTime);
	Gura_AssignMethod(wx_FileName, __GetName);
	Gura_AssignMethod(wx_FileName, __GetPath);
	Gura_AssignMethod(wx_FileName, __GetPathSeparator);
	Gura_AssignMethod(wx_FileName, __GetPathSeparators);
	Gura_AssignMethod(wx_FileName, __GetPathTerminators);
	Gura_AssignMethod(wx_FileName, __GetPathWithSep);
	Gura_AssignMethod(wx_FileName, __GetShortPath);
	Gura_AssignMethod(wx_FileName, __GetSize);
	Gura_AssignMethod(wx_FileName, __GetSize_1);
	Gura_AssignMethod(wx_FileName, __GetTempDir);
	Gura_AssignMethod(wx_FileName, __GetTimes);
	Gura_AssignMethod(wx_FileName, __GetVolume);
	Gura_AssignMethod(wx_FileName, __GetVolumeSeparator);
	Gura_AssignMethod(wx_FileName, __GetVolumeString);
	Gura_AssignMethod(wx_FileName, __HasExt);
	Gura_AssignMethod(wx_FileName, __HasName);
	Gura_AssignMethod(wx_FileName, __HasVolume);
	Gura_AssignMethod(wx_FileName, __InsertDir);
	Gura_AssignMethod(wx_FileName, __IsAbsolute);
	Gura_AssignMethod(wx_FileName, __IsCaseSensitive);
	Gura_AssignMethod(wx_FileName, __IsDir);
	Gura_AssignMethod(wx_FileName, __IsDirReadable);
	Gura_AssignMethod(wx_FileName, __IsDirReadable_1);
	Gura_AssignMethod(wx_FileName, __IsDirWritable);
	Gura_AssignMethod(wx_FileName, __IsDirWritable_1);
	Gura_AssignMethod(wx_FileName, __IsFileExecutable);
	Gura_AssignMethod(wx_FileName, __IsFileExecutable_1);
	Gura_AssignMethod(wx_FileName, __IsFileReadable);
	Gura_AssignMethod(wx_FileName, __IsFileReadable_1);
	Gura_AssignMethod(wx_FileName, __IsFileWritable);
	Gura_AssignMethod(wx_FileName, __IsFileWritable_1);
	Gura_AssignMethod(wx_FileName, __IsOk);
	Gura_AssignMethod(wx_FileName, __IsPathSeparator);
	Gura_AssignMethod(wx_FileName, __IsMSWUniqueVolumeNamePath);
	Gura_AssignMethod(wx_FileName, __IsRelative);
	Gura_AssignMethod(wx_FileName, __MakeAbsolute);
	Gura_AssignMethod(wx_FileName, __MakeRelativeTo);
	Gura_AssignMethod(wx_FileName, __Mkdir);
	Gura_AssignMethod(wx_FileName, __Mkdir_1);
	Gura_AssignMethod(wx_FileName, __Normalize);
	Gura_AssignMethod(wx_FileName, __PrependDir);
	Gura_AssignMethod(wx_FileName, __RemoveDir);
	Gura_AssignMethod(wx_FileName, __RemoveLastDir);
	Gura_AssignMethod(wx_FileName, __ReplaceEnvVariable);
	Gura_AssignMethod(wx_FileName, __ReplaceHomeDir);
	Gura_AssignMethod(wx_FileName, __Rmdir);
	Gura_AssignMethod(wx_FileName, __Rmdir_1);
	Gura_AssignMethod(wx_FileName, __SameAs);
	Gura_AssignMethod(wx_FileName, __SetCwd);
	Gura_AssignMethod(wx_FileName, __SetCwd_1);
	Gura_AssignMethod(wx_FileName, __SetEmptyExt);
	Gura_AssignMethod(wx_FileName, __SetExt);
	Gura_AssignMethod(wx_FileName, __SetFullName);
	Gura_AssignMethod(wx_FileName, __SetName);
	Gura_AssignMethod(wx_FileName, __SetPath);
	Gura_AssignMethod(wx_FileName, __SetPermissions);
	Gura_AssignMethod(wx_FileName, __SetTimes);
	Gura_AssignMethod(wx_FileName, __SetVolume);
	Gura_AssignMethod(wx_FileName, __ShouldFollowLink);
	Gura_AssignMethod(wx_FileName, __SplitPath);
	Gura_AssignMethod(wx_FileName, __SplitPath_1);
	Gura_AssignMethod(wx_FileName, __SplitPath_2);
	Gura_AssignMethod(wx_FileName, __SplitVolume);
	Gura_AssignMethod(wx_FileName, __StripExtension);
	Gura_AssignMethod(wx_FileName, __Touch);
}

Gura_ImplementDescendantCreator(wx_FileName)
{
	return new Object_wx_FileName((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
