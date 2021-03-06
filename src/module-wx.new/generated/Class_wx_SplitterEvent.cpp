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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SplitterEvent, "SplitterEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "splitter", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SplitterEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SplitterEvent)
{
	//wxEventType eventType = arg.GetNumber(0)
	//wxSplitterWindow* splitter = arg.GetNumber(1)
	//wxSplitterEvent(eventType, splitter);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SplitterEvent, __GetSashPosition, "GetSashPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, __GetSashPosition)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSashPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterEvent, __GetWindowBeingRemoved, "GetWindowBeingRemoved")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, __GetWindowBeingRemoved)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetWindowBeingRemoved();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterEvent, __GetX, "GetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, __GetX)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterEvent, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SplitterEvent, __GetY)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplitterEvent, __SetSashPosition, "SetSashPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplitterEvent, __SetSashPosition)
{
	Object_wx_SplitterEvent *pThis = Object_wx_SplitterEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetSashPosition(pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSplitterEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__SplitterEvent);
	// Method assignment
	Gura_AssignMethod(wx_SplitterEvent, __GetSashPosition);
	Gura_AssignMethod(wx_SplitterEvent, __GetWindowBeingRemoved);
	Gura_AssignMethod(wx_SplitterEvent, __GetX);
	Gura_AssignMethod(wx_SplitterEvent, __GetY);
	Gura_AssignMethod(wx_SplitterEvent, __SetSashPosition);
}

Gura_ImplementDescendantCreator(wx_SplitterEvent)
{
	return new Object_wx_SplitterEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
