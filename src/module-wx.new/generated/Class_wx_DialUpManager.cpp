//----------------------------------------------------------------------------
// wxDialUpManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialUpManager
//----------------------------------------------------------------------------
Object_wx_DialUpManager::~Object_wx_DialUpManager()
{
}

Object *Object_wx_DialUpManager::Clone() const
{
	return nullptr;
}

String Object_wx_DialUpManager::ToString(bool exprFlag)
{
	String rtn("<wx.DialUpManager:");
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
Gura_DeclareMethodAlias(wx_DialUpManager, __CancelDialing, "CancelDialing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __CancelDialing)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CancelDialing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __Create)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __Dial, "Dial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nameOfISP", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "username", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "password", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "async", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, __Dial)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& nameOfISP = arg.GetNumber(0)
	//const wxString& username = arg.GetNumber(1)
	//const wxString& password = arg.GetNumber(2)
	//bool async = arg.GetNumber(3)
	//pThis->GetEntity()->Dial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __DisableAutoCheckOnlineStatus, "DisableAutoCheckOnlineStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __DisableAutoCheckOnlineStatus)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisableAutoCheckOnlineStatus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __EnableAutoCheckOnlineStatus, "EnableAutoCheckOnlineStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nSeconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, __EnableAutoCheckOnlineStatus)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nSeconds = arg.GetNumber(0)
	//pThis->GetEntity()->EnableAutoCheckOnlineStatus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __GetISPNames, "GetISPNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "names", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, __GetISPNames)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& names = arg.GetNumber(0)
	//pThis->GetEntity()->GetISPNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __HangUp, "HangUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __HangUp)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HangUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __IsAlwaysOnline, "IsAlwaysOnline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __IsAlwaysOnline)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAlwaysOnline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __IsDialing, "IsDialing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __IsDialing)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDialing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __IsOk)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __IsOnline, "IsOnline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, __IsOnline)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOnline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __SetConnectCommand, "SetConnectCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandDial", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "commandHangup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, __SetConnectCommand)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& commandDial = arg.GetNumber(0)
	//const wxString& commandHangup = arg.GetNumber(1)
	//pThis->GetEntity()->SetConnectCommand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __SetOnlineStatus, "SetOnlineStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isOnline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, __SetOnlineStatus)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool isOnline = arg.GetNumber(0)
	//pThis->GetEntity()->SetOnlineStatus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DialUpManager, __SetWellKnownHost, "SetWellKnownHost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hostname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "portno", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, __SetWellKnownHost)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& hostname = arg.GetNumber(0)
	//int portno = arg.GetNumber(1)
	//pThis->GetEntity()->SetWellKnownHost();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialUpManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpManager)
{
	// Class assignment
	Gura_AssignValueEx("DialUpManager", Reference());
	// Method assignment
	Gura_AssignMethod(wx_DialUpManager, __CancelDialing);
	Gura_AssignMethod(wx_DialUpManager, __Create);
	Gura_AssignMethod(wx_DialUpManager, __Dial);
	Gura_AssignMethod(wx_DialUpManager, __DisableAutoCheckOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, __EnableAutoCheckOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, __GetISPNames);
	Gura_AssignMethod(wx_DialUpManager, __HangUp);
	Gura_AssignMethod(wx_DialUpManager, __IsAlwaysOnline);
	Gura_AssignMethod(wx_DialUpManager, __IsDialing);
	Gura_AssignMethod(wx_DialUpManager, __IsOk);
	Gura_AssignMethod(wx_DialUpManager, __IsOnline);
	Gura_AssignMethod(wx_DialUpManager, __SetConnectCommand);
	Gura_AssignMethod(wx_DialUpManager, __SetOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, __SetWellKnownHost);
}

Gura_ImplementDescendantCreator(wx_DialUpManager)
{
	return new Object_wx_DialUpManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
