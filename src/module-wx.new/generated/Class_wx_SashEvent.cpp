//----------------------------------------------------------------------------
// wxSashEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSashEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSashEvent
//----------------------------------------------------------------------------
Object_wx_SashEvent::~Object_wx_SashEvent()
{
}

Object *Object_wx_SashEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SashEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SashEvent:");
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
Gura_DeclareFunctionAlias(__SashEvent, "SashEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SashEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SashEvent)
{
	//int id = arg.GetNumber(0)
	//wxSashEdgePosition edge = arg.GetNumber(1)
	//wxSashEvent(id, edge);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SashEvent, __GetDragRect, "GetDragRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SashEvent, __GetDragRect)
{
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRect _rtn = pThis->GetEntity()->GetDragRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashEvent, __GetDragStatus, "GetDragStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SashEvent, __GetDragStatus)
{
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSashDragStatus _rtn = pThis->GetEntity()->GetDragStatus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashEvent, __GetEdge, "GetEdge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SashEvent, __GetEdge)
{
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSashEdgePosition _rtn = pThis->GetEntity()->GetEdge();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashEvent, __SetEdge, "SetEdge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edge", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashEvent, __SetEdge)
{
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSashEdgePosition edge = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdge(edge);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashEvent, __SetDragRect, "SetDragRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashEvent, __SetDragRect)
{
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragRect(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SashEvent, __SetDragStatus, "SetDragStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "status", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SashEvent, __SetDragStatus)
{
	Object_wx_SashEvent *pThis = Object_wx_SashEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSashDragStatus status = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragStatus(status);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSashEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__SashEvent);
	// Method assignment
	Gura_AssignMethod(wx_SashEvent, __GetDragRect);
	Gura_AssignMethod(wx_SashEvent, __GetDragStatus);
	Gura_AssignMethod(wx_SashEvent, __GetEdge);
	Gura_AssignMethod(wx_SashEvent, __SetEdge);
	Gura_AssignMethod(wx_SashEvent, __SetDragRect);
	Gura_AssignMethod(wx_SashEvent, __SetDragStatus);
}

Gura_ImplementDescendantCreator(wx_SashEvent)
{
	return new Object_wx_SashEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
