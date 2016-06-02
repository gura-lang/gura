//----------------------------------------------------------------------------
// wxThreadEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThreadEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThreadEvent
//----------------------------------------------------------------------------
Object_wx_ThreadEvent::~Object_wx_ThreadEvent()
{
}

Object *Object_wx_ThreadEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ThreadEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ThreadEvent:");
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
Gura_DeclareMethod(wx_ThreadEvent, wxThreadEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, wxThreadEvent)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxThreadEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, Clone)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, GetEventCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, GetEventCategory)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEventCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, SetPayload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "payload", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, SetPayload)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int payload = arg.GetNumber(0)
	//pThis->GetEntity()->SetPayload();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, GetPayload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, GetPayload)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPayload();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, GetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, GetExtraLong)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, GetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, GetInt)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, GetString)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, SetExtraLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraLong", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, SetExtraLong)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extraLong = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, SetInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "intCommand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, SetInt)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int intCommand = arg.GetNumber(0)
	//pThis->GetEntity()->SetInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadEvent, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, SetString)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxThreadEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThreadEvent)
{
	Gura_AssignMethod(wx_ThreadEvent, wxThreadEvent);
	Gura_AssignMethod(wx_ThreadEvent, Clone);
	Gura_AssignMethod(wx_ThreadEvent, GetEventCategory);
	Gura_AssignMethod(wx_ThreadEvent, SetPayload);
	Gura_AssignMethod(wx_ThreadEvent, GetPayload);
	Gura_AssignMethod(wx_ThreadEvent, GetExtraLong);
	Gura_AssignMethod(wx_ThreadEvent, GetInt);
	Gura_AssignMethod(wx_ThreadEvent, GetString);
	Gura_AssignMethod(wx_ThreadEvent, SetExtraLong);
	Gura_AssignMethod(wx_ThreadEvent, SetInt);
	Gura_AssignMethod(wx_ThreadEvent, SetString);
}

Gura_ImplementDescendantCreator(wx_ThreadEvent)
{
	return new Object_wx_ThreadEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
