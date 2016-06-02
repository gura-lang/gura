//----------------------------------------------------------------------------
// wxSplitterEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSplitterEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSplitterEvent
//----------------------------------------------------------------------------
Object_wx_SplitterEvent::~Object_wx_SplitterEvent()
{
}

Object *Object_wx_SplitterEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SplitterEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SplitterEvent:");
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
Gura_DeclareMethod(wx_SplitterEvent, wxSplitterEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "splitter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterEvent, wxSplitterEvent)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int splitter = arg.GetNumber(1)
	//pThis->GetEntity()->wxSplitterEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterEvent, GetSashPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, GetSashPosition)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSashPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterEvent, GetWindowBeingRemoved)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, GetWindowBeingRemoved)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindowBeingRemoved();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterEvent, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, GetX)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterEvent, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, GetY)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplitterEvent, SetSashPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterEvent, SetSashPosition)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetSashPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSplitterEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterEvent)
{
	Gura_AssignMethod(wx_SplitterEvent, wxSplitterEvent);
	Gura_AssignMethod(wx_SplitterEvent, GetSashPosition);
	Gura_AssignMethod(wx_SplitterEvent, GetWindowBeingRemoved);
	Gura_AssignMethod(wx_SplitterEvent, GetX);
	Gura_AssignMethod(wx_SplitterEvent, GetY);
	Gura_AssignMethod(wx_SplitterEvent, SetSashPosition);
}

Gura_ImplementDescendantCreator(wx_SplitterEvent)
{
	return new Object_wx_SplitterEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
