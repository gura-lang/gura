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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FileSystemWatcher, "FileSystemWatcher")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileSystemWatcher));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileSystemWatcher)
{
	//wxFileSystemWatcher();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileSystemWatcher, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "events", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __Add)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int events = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcher, __AddTree, "AddTree")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "events", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __AddTree)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int events = arg.GetNumber(1)
	//int filter = arg.GetNumber(2)
	//pThis->GetEntity()->AddTree();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcher, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __Remove)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcher, __RemoveTree, "RemoveTree")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __RemoveTree)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveTree();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcher, __RemoveAll, "RemoveAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __RemoveAll)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RemoveAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcher, __GetWatchedPathsCount, "GetWatchedPathsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __GetWatchedPathsCount)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWatchedPathsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcher, __GetWatchedPaths, "GetWatchedPaths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __GetWatchedPaths)
{
	Object_wx_FileSystemWatcher *pThis = Object_wx_FileSystemWatcher::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetWatchedPaths();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcher, __SetOwner, "SetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcher, __SetOwner)
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
	// Constructor assignment
	Gura_AssignFunction(__FileSystemWatcher);
	// Method assignment
	Gura_AssignMethod(wx_FileSystemWatcher, __Add);
	Gura_AssignMethod(wx_FileSystemWatcher, __AddTree);
	Gura_AssignMethod(wx_FileSystemWatcher, __Remove);
	Gura_AssignMethod(wx_FileSystemWatcher, __RemoveTree);
	Gura_AssignMethod(wx_FileSystemWatcher, __RemoveAll);
	Gura_AssignMethod(wx_FileSystemWatcher, __GetWatchedPathsCount);
	Gura_AssignMethod(wx_FileSystemWatcher, __GetWatchedPaths);
	Gura_AssignMethod(wx_FileSystemWatcher, __SetOwner);
}

Gura_ImplementDescendantCreator(wx_FileSystemWatcher)
{
	return new Object_wx_FileSystemWatcher((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
