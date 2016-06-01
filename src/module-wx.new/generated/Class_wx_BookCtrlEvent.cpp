//----------------------------------------------------------------------------
// wxBookCtrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBookCtrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBookCtrlEvent
//----------------------------------------------------------------------------
Object_wx_BookCtrlEvent::~Object_wx_BookCtrlEvent()
{
}

Object *Object_wx_BookCtrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_BookCtrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.BookCtrlEvent:");
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
Gura_DeclareMethod(wx_BookCtrlEvent, wxBookCtrlEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldSel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlEvent, wxBookCtrlEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int sel = arg.GetNumber(2)
	//int oldSel = arg.GetNumber(3)
	//pThis->GetEntity()->wxBookCtrlEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BookCtrlEvent, GetOldSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BookCtrlEvent, GetOldSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOldSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BookCtrlEvent, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BookCtrlEvent, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BookCtrlEvent, SetOldSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlEvent, SetOldSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetOldSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BookCtrlEvent, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlEvent, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_BookCtrlEvent *pThis = Object_wx_BookCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBookCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BookCtrlEvent)
{
	Gura_AssignMethod(wx_BookCtrlEvent, wxBookCtrlEvent);
	Gura_AssignMethod(wx_BookCtrlEvent, GetOldSelection);
	Gura_AssignMethod(wx_BookCtrlEvent, GetSelection);
	Gura_AssignMethod(wx_BookCtrlEvent, SetOldSelection);
	Gura_AssignMethod(wx_BookCtrlEvent, SetSelection);
}

Gura_ImplementDescendantCreator(wx_BookCtrlEvent)
{
	return new Object_wx_BookCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
