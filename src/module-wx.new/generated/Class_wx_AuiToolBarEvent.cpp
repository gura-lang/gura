//----------------------------------------------------------------------------
// wxAuiToolBarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBarEvent
//----------------------------------------------------------------------------
Object_wx_AuiToolBarEvent::~Object_wx_AuiToolBarEvent()
{
}

Object *Object_wx_AuiToolBarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBarEvent:");
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
Gura_DeclareMethodAlias(wx_AuiToolBarEvent, __IsDropDownClicked, "IsDropDownClicked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarEvent, __IsDropDownClicked)
{
	Object_wx_AuiToolBarEvent *pThis = Object_wx_AuiToolBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDropDownClicked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarEvent, __GetClickPoint, "GetClickPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarEvent, __GetClickPoint)
{
	Object_wx_AuiToolBarEvent *pThis = Object_wx_AuiToolBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClickPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarEvent, __GetItemRect, "GetItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarEvent, __GetItemRect)
{
	Object_wx_AuiToolBarEvent *pThis = Object_wx_AuiToolBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarEvent, __GetToolId, "GetToolId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarEvent, __GetToolId)
{
	Object_wx_AuiToolBarEvent *pThis = Object_wx_AuiToolBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolId();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiToolBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBarEvent)
{
	Gura_AssignMethod(wx_AuiToolBarEvent, __IsDropDownClicked);
	Gura_AssignMethod(wx_AuiToolBarEvent, __GetClickPoint);
	Gura_AssignMethod(wx_AuiToolBarEvent, __GetItemRect);
	Gura_AssignMethod(wx_AuiToolBarEvent, __GetToolId);
}

Gura_ImplementDescendantCreator(wx_AuiToolBarEvent)
{
	return new Object_wx_AuiToolBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
