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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FileSystem, wxFileSystem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystem, wxFileSystem)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFileSystem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, AddHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, RemoveHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, RemoveHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, ChangePathTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "is_dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, ChangePathTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//int is_dir = arg.GetNumber(1)
	//pThis->GetEntity()->ChangePathTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, FileNameToURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, FileNameToURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->FileNameToURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, FindFileInPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pStr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, FindFileInPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pStr = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int file = arg.GetNumber(2)
	//pThis->GetEntity()->FindFileInPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, FindFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, FindFirst)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int wildcard = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->FindFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, FindNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystem, FindNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FindNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystem, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, HasHandlerForPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, HasHandlerForPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->HasHandlerForPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, OpenFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, OpenFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->OpenFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, URLToFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystem, URLToFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->URLToFileName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystem)
{
	Gura_AssignMethod(wx_FileSystem, wxFileSystem);
	Gura_AssignMethod(wx_FileSystem, AddHandler);
	Gura_AssignMethod(wx_FileSystem, RemoveHandler);
	Gura_AssignMethod(wx_FileSystem, ChangePathTo);
	Gura_AssignMethod(wx_FileSystem, FileNameToURL);
	Gura_AssignMethod(wx_FileSystem, FindFileInPath);
	Gura_AssignMethod(wx_FileSystem, FindFirst);
	Gura_AssignMethod(wx_FileSystem, FindNext);
	Gura_AssignMethod(wx_FileSystem, GetPath);
	Gura_AssignMethod(wx_FileSystem, HasHandlerForPath);
	Gura_AssignMethod(wx_FileSystem, OpenFile);
	Gura_AssignMethod(wx_FileSystem, URLToFileName);
}

Gura_ImplementDescendantCreator(wx_FileSystem)
{
	return new Object_wx_FileSystem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
