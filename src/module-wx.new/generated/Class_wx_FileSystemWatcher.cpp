//----------------------------------------------------------------------------
// wxFileSystemWatcher
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemWatcher
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemWatcher
//----------------------------------------------------------------------------
Object_wx_FileSystemWatcher::~Object_wx_FileSystemWatcher()
{
}

Object *Object_wx_FileSystemWatcher::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystemWatcher::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystemWatcher:");
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
Gura_DeclareMethod(wx_FileSystemWatcher, wxFileSystemWatcher)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcher, wxFileSystemWatcher)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFileSystemWatcher();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "events", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, Add)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int events = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, AddTree)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "events", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, AddTree)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int events = arg.GetNumber(1)
	//int filter = arg.GetNumber(2)
	//pThis->GetEntity()->AddTree();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, Remove)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, RemoveTree)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, RemoveTree)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveTree();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, RemoveAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcher, RemoveAll)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RemoveAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, GetWatchedPathsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcher, GetWatchedPathsCount)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWatchedPathsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, GetWatchedPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, GetWatchedPaths)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetWatchedPaths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcher, SetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, SetOwner)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwner();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystemWatcher
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemWatcher)
{
	Gura_AssignMethod(wx_FileSystemWatcher, wxFileSystemWatcher);
	Gura_AssignMethod(wx_FileSystemWatcher, Add);
	Gura_AssignMethod(wx_FileSystemWatcher, AddTree);
	Gura_AssignMethod(wx_FileSystemWatcher, Remove);
	Gura_AssignMethod(wx_FileSystemWatcher, RemoveTree);
	Gura_AssignMethod(wx_FileSystemWatcher, RemoveAll);
	Gura_AssignMethod(wx_FileSystemWatcher, GetWatchedPathsCount);
	Gura_AssignMethod(wx_FileSystemWatcher, GetWatchedPaths);
	Gura_AssignMethod(wx_FileSystemWatcher, SetOwner);
}

Gura_ImplementDescendantCreator(wx_FileSystemWatcher)
{
	return new Object_wx_FileSystemWatcher((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
