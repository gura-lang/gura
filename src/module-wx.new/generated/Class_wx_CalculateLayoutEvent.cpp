//----------------------------------------------------------------------------
// wxCalculateLayoutEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCalculateLayoutEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Object_wx_CalculateLayoutEvent::~Object_wx_CalculateLayoutEvent()
{
}

Object *Object_wx_CalculateLayoutEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CalculateLayoutEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CalculateLayoutEvent:");
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
Gura_DeclareMethod(wx_CalculateLayoutEvent, wxCalculateLayoutEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, wxCalculateLayoutEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->wxCalculateLayoutEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, GetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalculateLayoutEvent, SetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, SetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalculateLayoutEvent)
{
	Gura_AssignMethod(wx_CalculateLayoutEvent, wxCalculateLayoutEvent);
	Gura_AssignMethod(wx_CalculateLayoutEvent, GetFlags);
	Gura_AssignMethod(wx_CalculateLayoutEvent, GetRect);
	Gura_AssignMethod(wx_CalculateLayoutEvent, SetFlags);
	Gura_AssignMethod(wx_CalculateLayoutEvent, SetRect);
}

Gura_ImplementDescendantCreator(wx_CalculateLayoutEvent)
{
	return new Object_wx_CalculateLayoutEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
