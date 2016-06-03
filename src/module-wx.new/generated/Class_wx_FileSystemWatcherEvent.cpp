//----------------------------------------------------------------------------
// wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
Object_wx_FileSystemWatcherEvent::~Object_wx_FileSystemWatcherEvent()
{
}

Object *Object_wx_FileSystemWatcherEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystemWatcherEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystemWatcherEvent:");
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
Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent, "wxFileSystemWatcherEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "changeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "watchid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int changeType = arg.GetNumber(0)
	//int watchid = arg.GetNumber(1)
	//pThis->GetEntity()->wxFileSystemWatcherEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent_1, "wxFileSystemWatcherEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "changeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "warningType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "errorMsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "watchid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent_1)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int changeType = arg.GetNumber(0)
	//int warningType = arg.GetNumber(1)
	//int errorMsg = arg.GetNumber(2)
	//int watchid = arg.GetNumber(3)
	//pThis->GetEntity()->wxFileSystemWatcherEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent_2, "wxFileSystemWatcherEvent_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "changeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newPath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "watchid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent_2)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int changeType = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int newPath = arg.GetNumber(2)
	//int watchid = arg.GetNumber(3)
	//pThis->GetEntity()->wxFileSystemWatcherEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __GetPath)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __GetNewPath, "GetNewPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __GetNewPath)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNewPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __GetChangeType, "GetChangeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __GetChangeType)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChangeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __IsError, "IsError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __IsError)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __GetErrorDescription, "GetErrorDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __GetErrorDescription)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetErrorDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __GetWarningType, "GetWarningType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __GetWarningType)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWarningType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemWatcherEvent, __ToString, "ToString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, __ToString)
{
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemWatcherEvent)
{
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent_1);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __wxFileSystemWatcherEvent_2);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __GetPath);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __GetNewPath);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __GetChangeType);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __IsError);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __GetErrorDescription);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __GetWarningType);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, __ToString);
}

Gura_ImplementDescendantCreator(wx_FileSystemWatcherEvent)
{
	return new Object_wx_FileSystemWatcherEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
