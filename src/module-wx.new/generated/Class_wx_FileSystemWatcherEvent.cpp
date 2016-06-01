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
Gura_DeclareMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "changeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "watchid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int changeType = arg.GetNumber(0)
	//int watchid = arg.GetNumber(1)
	//pThis->GetEntity()->wxFileSystemWatcherEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "changeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "warningType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "errorMsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "watchid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int changeType = arg.GetNumber(0)
	//int warningType = arg.GetNumber(1)
	//int errorMsg = arg.GetNumber(2)
	//int watchid = arg.GetNumber(3)
	//pThis->GetEntity()->wxFileSystemWatcherEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "changeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newPath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "watchid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int changeType = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int newPath = arg.GetNumber(2)
	//int watchid = arg.GetNumber(3)
	//pThis->GetEntity()->wxFileSystemWatcherEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, GetNewPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, GetNewPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNewPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, GetChangeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, GetChangeType)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChangeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, IsError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, IsError)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, GetErrorDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, GetErrorDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetErrorDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, GetWarningType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, GetWarningType)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWarningType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemWatcherEvent, ToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemWatcherEvent, ToString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemWatcherEvent *pThis = Object_wx_FileSystemWatcherEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemWatcherEvent)
{
	Gura_AssignMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent_1);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, wxFileSystemWatcherEvent_2);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, GetPath);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, GetNewPath);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, GetChangeType);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, IsError);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, GetErrorDescription);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, GetWarningType);
	Gura_AssignMethod(wx_FileSystemWatcherEvent, ToString);
}

Gura_ImplementDescendantCreator(wx_FileSystemWatcherEvent)
{
	return new Object_wx_FileSystemWatcherEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
