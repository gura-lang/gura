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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxMoveEvent, "wxMoveEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MoveEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxMoveEvent)
{
	//int pt = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxMoveEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MoveEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MoveEvent, __GetPosition)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MoveEvent, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MoveEvent, __GetRect)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MoveEvent, __SetRect, "SetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MoveEvent, __SetRect)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MoveEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MoveEvent, __SetPosition)
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
	// Constructor assignment
	Gura_AssignFunction(__wxMoveEvent);
	// Method assignment
	Gura_AssignMethod(wx_MoveEvent, __GetPosition);
	Gura_AssignMethod(wx_MoveEvent, __GetRect);
	Gura_AssignMethod(wx_MoveEvent, __SetRect);
	Gura_AssignMethod(wx_MoveEvent, __SetPosition);
}

Gura_ImplementDescendantCreator(wx_MoveEvent)
{
	return new Object_wx_MoveEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
