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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__CollapsiblePaneEvent, "CollapsiblePaneEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "collapsed", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CollapsiblePaneEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CollapsiblePaneEvent)
{
	//wxObject* generator = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//bool collapsed = arg.GetNumber(2)
	//wxCollapsiblePaneEvent(generator, id, collapsed);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CollapsiblePaneEvent, __GetCollapsed, "GetCollapsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, __GetCollapsed)
{
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCollapsed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsiblePaneEvent, __SetCollapsed, "SetCollapsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePaneEvent, __SetCollapsed)
{
	Object_wx_CollapsiblePaneEvent *pThis = Object_wx_CollapsiblePaneEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool collapsed = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollapsed(collapsed);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsiblePaneEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__CollapsiblePaneEvent);
	// Method assignment
	Gura_AssignMethod(wx_CollapsiblePaneEvent, __GetCollapsed);
	Gura_AssignMethod(wx_CollapsiblePaneEvent, __SetCollapsed);
}

Gura_ImplementDescendantCreator(wx_CollapsiblePaneEvent)
{
	return new Object_wx_CollapsiblePaneEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
