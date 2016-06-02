//----------------------------------------------------------------------------
// wxShowEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxShowEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxShowEvent
//----------------------------------------------------------------------------
Object_wx_ShowEvent::~Object_wx_ShowEvent()
{
}

Object *Object_wx_ShowEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ShowEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ShowEvent:");
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
Gura_DeclareMethod(wx_ShowEvent, wxShowEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ShowEvent, wxShowEvent)
{
	Object_wx_ShowEvent *pThis = Object_wx_ShowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int winid = arg.GetNumber(0)
	//int show = arg.GetNumber(1)
	//pThis->GetEntity()->wxShowEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ShowEvent, SetShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ShowEvent, SetShow)
{
	Object_wx_ShowEvent *pThis = Object_wx_ShowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetShow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ShowEvent, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ShowEvent, IsShown)
{
	Object_wx_ShowEvent *pThis = Object_wx_ShowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ShowEvent, GetShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ShowEvent, GetShow)
{
	Object_wx_ShowEvent *pThis = Object_wx_ShowEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxShowEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ShowEvent)
{
	Gura_AssignMethod(wx_ShowEvent, wxShowEvent);
	Gura_AssignMethod(wx_ShowEvent, SetShow);
	Gura_AssignMethod(wx_ShowEvent, IsShown);
	Gura_AssignMethod(wx_ShowEvent, GetShow);
}

Gura_ImplementDescendantCreator(wx_ShowEvent)
{
	return new Object_wx_ShowEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
