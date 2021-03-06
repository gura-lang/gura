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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HeaderCtrlEvent, "HeaderCtrlEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HeaderCtrlEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HeaderCtrlEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//wxHeaderCtrlEvent(commandType, winid);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HeaderCtrlEvent_1, "HeaderCtrlEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HeaderCtrlEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HeaderCtrlEvent_1)
{
	//const wxHeaderCtrlEvent& event = arg.GetNumber(0)
	//wxHeaderCtrlEvent(event);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HeaderCtrlEvent, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, __GetColumn)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlEvent, __SetColumn, "SetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, __SetColumn)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlEvent, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, __GetWidth)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlEvent, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, __SetWidth)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth(width);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlEvent, __GetNewOrder, "GetNewOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, __GetNewOrder)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int _rtn = pThis->GetEntity()->GetNewOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderCtrlEvent, __SetNewOrder, "SetNewOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderCtrlEvent, __SetNewOrder)
{
	Object_wx_HeaderCtrlEvent *pThis = Object_wx_HeaderCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int order = arg.GetNumber(0)
	//pThis->GetEntity()->SetNewOrder(order);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrlEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__HeaderCtrlEvent);
	Gura_AssignFunction(__HeaderCtrlEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_HeaderCtrlEvent, __GetColumn);
	Gura_AssignMethod(wx_HeaderCtrlEvent, __SetColumn);
	Gura_AssignMethod(wx_HeaderCtrlEvent, __GetWidth);
	Gura_AssignMethod(wx_HeaderCtrlEvent, __SetWidth);
	Gura_AssignMethod(wx_HeaderCtrlEvent, __GetNewOrder);
	Gura_AssignMethod(wx_HeaderCtrlEvent, __SetNewOrder);
}

Gura_ImplementDescendantCreator(wx_HeaderCtrlEvent)
{
	return new Object_wx_HeaderCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
