//----------------------------------------------------------------------------
// wxFileSystem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystem
//----------------------------------------------------------------------------
Object_wx_FileSystem::~Object_wx_FileSystem()
{
}

Object *Object_wx_FileSystem::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystem::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystem:");
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
Gura_DeclareFunctionAlias(__wxFileSystem, "wxFileSystem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileSystem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileSystem)
{
	//wxFileSystem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileSystem, __AddHandler, "AddHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __AddHandler)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __RemoveHandler, "RemoveHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __RemoveHandler)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __ChangePathTo, "ChangePathTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "is_dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __ChangePathTo)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//int is_dir = arg.GetNumber(1)
	//pThis->GetEntity()->ChangePathTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __FileNameToURL, "FileNameToURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __FileNameToURL)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->FileNameToURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __FindFileInPath, "FindFileInPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pStr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __FindFileInPath)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pStr = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int file = arg.GetNumber(2)
	//pThis->GetEntity()->FindFileInPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __FindFirst, "FindFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __FindFirst)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wildcard = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->FindFirst();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __FindNext, "FindNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystem, __FindNext)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FindNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystem, __GetPath)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __HasHandlerForPath, "HasHandlerForPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __HasHandlerForPath)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->HasHandlerForPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __OpenFile, "OpenFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __OpenFile)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->OpenFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystem, __URLToFileName, "URLToFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, __URLToFileName)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->URLToFileName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystem)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFileSystem);
	// Method assignment
	Gura_AssignMethod(wx_FileSystem, __AddHandler);
	Gura_AssignMethod(wx_FileSystem, __RemoveHandler);
	Gura_AssignMethod(wx_FileSystem, __ChangePathTo);
	Gura_AssignMethod(wx_FileSystem, __FileNameToURL);
	Gura_AssignMethod(wx_FileSystem, __FindFileInPath);
	Gura_AssignMethod(wx_FileSystem, __FindFirst);
	Gura_AssignMethod(wx_FileSystem, __FindNext);
	Gura_AssignMethod(wx_FileSystem, __GetPath);
	Gura_AssignMethod(wx_FileSystem, __HasHandlerForPath);
	Gura_AssignMethod(wx_FileSystem, __OpenFile);
	Gura_AssignMethod(wx_FileSystem, __URLToFileName);
}

Gura_ImplementDescendantCreator(wx_FileSystem)
{
	return new Object_wx_FileSystem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
