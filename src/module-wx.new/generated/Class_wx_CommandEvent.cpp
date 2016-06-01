//----------------------------------------------------------------------------
// wxCommandEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommandEvent
//----------------------------------------------------------------------------
Object_wx_CommandEvent::~Object_wx_CommandEvent()
{
}

Object *Object_wx_CommandEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CommandEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CommandEvent:");
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
Gura_DeclareMethod(wx_CommandEvent, wxCommandEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandEventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, wxCommandEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandEventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxCommandEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, GetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, GetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, GetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, GetExtraLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExtraLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, GetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, GetInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, IsChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, IsSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, IsSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clientData = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clientObject = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraLong", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetExtraLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int extraLong = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "intCommand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int intCommand = arg.GetNumber(0)
	//pThis->GetEntity()->SetInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandEvent, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommandEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandEvent)
{
	Gura_AssignMethod(wx_CommandEvent, wxCommandEvent);
	Gura_AssignMethod(wx_CommandEvent, GetClientData);
	Gura_AssignMethod(wx_CommandEvent, GetClientObject);
	Gura_AssignMethod(wx_CommandEvent, GetExtraLong);
	Gura_AssignMethod(wx_CommandEvent, GetInt);
	Gura_AssignMethod(wx_CommandEvent, GetSelection);
	Gura_AssignMethod(wx_CommandEvent, GetString);
	Gura_AssignMethod(wx_CommandEvent, IsChecked);
	Gura_AssignMethod(wx_CommandEvent, IsSelection);
	Gura_AssignMethod(wx_CommandEvent, SetClientData);
	Gura_AssignMethod(wx_CommandEvent, SetClientObject);
	Gura_AssignMethod(wx_CommandEvent, SetExtraLong);
	Gura_AssignMethod(wx_CommandEvent, SetInt);
	Gura_AssignMethod(wx_CommandEvent, SetString);
}

Gura_ImplementDescendantCreator(wx_CommandEvent)
{
	return new Object_wx_CommandEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
