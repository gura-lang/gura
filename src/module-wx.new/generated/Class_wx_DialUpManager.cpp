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
Gura_DeclareMethod(wx_DialUpManager, ~wxDialUpManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, ~wxDialUpManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDialUpManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, CancelDialing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, CancelDialing)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CancelDialing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, Dial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nameOfISP", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "username", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "password", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "async", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, Dial)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nameOfISP = arg.GetNumber(0)
	//int username = arg.GetNumber(1)
	//int password = arg.GetNumber(2)
	//int async = arg.GetNumber(3)
	//pThis->GetEntity()->Dial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, DisableAutoCheckOnlineStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, DisableAutoCheckOnlineStatus)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisableAutoCheckOnlineStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, EnableAutoCheckOnlineStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nSeconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, EnableAutoCheckOnlineStatus)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nSeconds = arg.GetNumber(0)
	//pThis->GetEntity()->EnableAutoCheckOnlineStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, GetISPNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "names", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, GetISPNames)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int names = arg.GetNumber(0)
	//pThis->GetEntity()->GetISPNames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, HangUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, HangUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HangUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, IsAlwaysOnline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, IsAlwaysOnline)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAlwaysOnline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, IsDialing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, IsDialing)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDialing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, IsOnline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, IsOnline)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOnline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, SetConnectCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandDial", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "commandHangup", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, SetConnectCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandDial = arg.GetNumber(0)
	//int commandHangup = arg.GetNumber(1)
	//pThis->GetEntity()->SetConnectCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, SetOnlineStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isOnline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, SetOnlineStatus)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int isOnline = arg.GetNumber(0)
	//pThis->GetEntity()->SetOnlineStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpManager, SetWellKnownHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hostname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "portno", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpManager, SetWellKnownHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hostname = arg.GetNumber(0)
	//int portno = arg.GetNumber(1)
	//pThis->GetEntity()->SetWellKnownHost();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialUpManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpManager)
{
	Gura_AssignMethod(wx_DialUpManager, ~wxDialUpManager);
	Gura_AssignMethod(wx_DialUpManager, CancelDialing);
	Gura_AssignMethod(wx_DialUpManager, Create);
	Gura_AssignMethod(wx_DialUpManager, Dial);
	Gura_AssignMethod(wx_DialUpManager, DisableAutoCheckOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, EnableAutoCheckOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, GetISPNames);
	Gura_AssignMethod(wx_DialUpManager, HangUp);
	Gura_AssignMethod(wx_DialUpManager, IsAlwaysOnline);
	Gura_AssignMethod(wx_DialUpManager, IsDialing);
	Gura_AssignMethod(wx_DialUpManager, IsOk);
	Gura_AssignMethod(wx_DialUpManager, IsOnline);
	Gura_AssignMethod(wx_DialUpManager, SetConnectCommand);
	Gura_AssignMethod(wx_DialUpManager, SetOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, SetWellKnownHost);
}

Gura_ImplementDescendantCreator(wx_DialUpManager)
{
	return new Object_wx_DialUpManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
