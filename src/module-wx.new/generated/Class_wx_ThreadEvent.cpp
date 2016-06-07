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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ThreadEvent, "ThreadEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ThreadEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ThreadEvent)
{
	//wxEventType eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxThreadEvent(eventType, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ThreadEvent, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, __Clone)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEvent* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __GetEventCategory, "GetEventCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, __GetEventCategory)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEventCategory _rtn = pThis->GetEntity()->GetEventCategory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __SetPayload, "SetPayload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "payload", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, __SetPayload)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const T& payload = arg.GetNumber(0)
	//pThis->GetEntity()->SetPayload(payload);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __GetPayload, "GetPayload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, __GetPayload)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T _rtn = pThis->GetEntity()->GetPayload();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __GetExtraLong, "GetExtraLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, __GetExtraLong)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetExtraLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __GetInt, "GetInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, __GetInt)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetInt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadEvent, __GetString)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __SetExtraLong, "SetExtraLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraLong", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, __SetExtraLong)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long extraLong = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraLong(extraLong);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __SetInt, "SetInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "intCommand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, __SetInt)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int intCommand = arg.GetNumber(0)
	//pThis->GetEntity()->SetInt(intCommand);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ThreadEvent, __SetString, "SetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadEvent, __SetString)
{
	Object_wx_ThreadEvent *pThis = Object_wx_ThreadEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->SetString(string);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxThreadEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThreadEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__ThreadEvent);
	// Method assignment
	Gura_AssignMethod(wx_ThreadEvent, __Clone);
	Gura_AssignMethod(wx_ThreadEvent, __GetEventCategory);
	Gura_AssignMethod(wx_ThreadEvent, __SetPayload);
	Gura_AssignMethod(wx_ThreadEvent, __GetPayload);
	Gura_AssignMethod(wx_ThreadEvent, __GetExtraLong);
	Gura_AssignMethod(wx_ThreadEvent, __GetInt);
	Gura_AssignMethod(wx_ThreadEvent, __GetString);
	Gura_AssignMethod(wx_ThreadEvent, __SetExtraLong);
	Gura_AssignMethod(wx_ThreadEvent, __SetInt);
	Gura_AssignMethod(wx_ThreadEvent, __SetString);
}

Gura_ImplementDescendantCreator(wx_ThreadEvent)
{
	return new Object_wx_ThreadEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
