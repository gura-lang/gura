//----------------------------------------------------------------------------
// wxHeaderCtrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderCtrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderCtrlEvent
//----------------------------------------------------------------------------
Object_wx_HeaderCtrlEvent::~Object_wx_HeaderCtrlEvent()
{
}

Object *Object_wx_HeaderCtrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderCtrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderCtrlEvent:");
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
Gura_DeclareMethod(wx_HeaderCtrlEvent, wxHeaderCtrlEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, wxHeaderCtrlEvent)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->wxHeaderCtrlEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlEvent, wxHeaderCtrlEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, wxHeaderCtrlEvent_1)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxHeaderCtrlEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlEvent, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, GetColumn)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlEvent, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, SetColumn)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlEvent, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, GetWidth)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlEvent, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, SetWidth)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlEvent, GetNewOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, GetNewOrder)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNewOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderCtrlEvent, SetNewOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, SetNewOrder)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int order = arg.GetNumber(0)
	//pThis->GetEntity()->SetNewOrder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrlEvent)
{
	Gura_AssignMethod(wx_HeaderCtrlEvent, wxHeaderCtrlEvent);
	Gura_AssignMethod(wx_HeaderCtrlEvent, wxHeaderCtrlEvent_1);
	Gura_AssignMethod(wx_HeaderCtrlEvent, GetColumn);
	Gura_AssignMethod(wx_HeaderCtrlEvent, SetColumn);
	Gura_AssignMethod(wx_HeaderCtrlEvent, GetWidth);
	Gura_AssignMethod(wx_HeaderCtrlEvent, SetWidth);
	Gura_AssignMethod(wx_HeaderCtrlEvent, GetNewOrder);
	Gura_AssignMethod(wx_HeaderCtrlEvent, SetNewOrder);
}

Gura_ImplementDescendantCreator(wx_HeaderCtrlEvent)
{
	return new Object_wx_HeaderCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
