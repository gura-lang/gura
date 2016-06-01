//----------------------------------------------------------------------------
// wxTreeListEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListEvent
//----------------------------------------------------------------------------
Object_wx_TreeListEvent::~Object_wx_TreeListEvent()
{
}

Object *Object_wx_TreeListEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListEvent:");
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
Gura_DeclareMethod(wx_TreeListEvent, wxTreeListEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListEvent, wxTreeListEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListEvent *pThis = Object_wx_TreeListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTreeListEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListEvent, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListEvent, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListEvent *pThis = Object_wx_TreeListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListEvent, GetOldCheckedState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListEvent, GetOldCheckedState)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListEvent *pThis = Object_wx_TreeListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOldCheckedState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeListEvent, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListEvent, GetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeListEvent *pThis = Object_wx_TreeListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeListEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListEvent)
{
	Gura_AssignMethod(wx_TreeListEvent, wxTreeListEvent);
	Gura_AssignMethod(wx_TreeListEvent, GetItem);
	Gura_AssignMethod(wx_TreeListEvent, GetOldCheckedState);
	Gura_AssignMethod(wx_TreeListEvent, GetColumn);
}

Gura_ImplementDescendantCreator(wx_TreeListEvent)
{
	return new Object_wx_TreeListEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
