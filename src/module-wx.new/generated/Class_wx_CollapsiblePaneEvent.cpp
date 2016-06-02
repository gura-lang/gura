//----------------------------------------------------------------------------
// wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Object_wx_CollapsiblePaneEvent::~Object_wx_CollapsiblePaneEvent()
{
}

Object *Object_wx_CollapsiblePaneEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CollapsiblePaneEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CollapsiblePaneEvent:");
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
Gura_DeclareMethod(wx_CollapsiblePaneEvent, wxCollapsiblePaneEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "collapsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, wxCollapsiblePaneEvent)
{
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int generator = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int collapsed = arg.GetNumber(2)
	//pThis->GetEntity()->wxCollapsiblePaneEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePaneEvent, GetCollapsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, GetCollapsed)
{
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCollapsed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePaneEvent, SetCollapsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, SetCollapsed)
{
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int collapsed = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollapsed();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsiblePaneEvent)
{
	Gura_AssignMethod(wx_CollapsiblePaneEvent, wxCollapsiblePaneEvent);
	Gura_AssignMethod(wx_CollapsiblePaneEvent, GetCollapsed);
	Gura_AssignMethod(wx_CollapsiblePaneEvent, SetCollapsed);
}

Gura_ImplementDescendantCreator(wx_CollapsiblePaneEvent)
{
	return new Object_wx_CollapsiblePaneEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
