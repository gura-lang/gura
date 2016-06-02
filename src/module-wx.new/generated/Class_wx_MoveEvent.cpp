//----------------------------------------------------------------------------
// wxMoveEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMoveEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMoveEvent
//----------------------------------------------------------------------------
Object_wx_MoveEvent::~Object_wx_MoveEvent()
{
}

Object *Object_wx_MoveEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MoveEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MoveEvent:");
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
Gura_DeclareMethod(wx_MoveEvent, wxMoveEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MoveEvent, wxMoveEvent)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxMoveEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MoveEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MoveEvent, GetPosition)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MoveEvent, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MoveEvent, GetRect)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MoveEvent, SetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MoveEvent, SetRect)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MoveEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MoveEvent, SetPosition)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMoveEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MoveEvent)
{
	Gura_AssignMethod(wx_MoveEvent, wxMoveEvent);
	Gura_AssignMethod(wx_MoveEvent, GetPosition);
	Gura_AssignMethod(wx_MoveEvent, GetRect);
	Gura_AssignMethod(wx_MoveEvent, SetRect);
	Gura_AssignMethod(wx_MoveEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_MoveEvent)
{
	return new Object_wx_MoveEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
