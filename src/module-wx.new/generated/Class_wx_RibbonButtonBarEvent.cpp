//----------------------------------------------------------------------------
// wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
Object_wx_RibbonButtonBarEvent::~Object_wx_RibbonButtonBarEvent()
{
}

Object *Object_wx_RibbonButtonBarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonButtonBarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonButtonBarEvent:");
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
Gura_DeclareMethod(wx_RibbonButtonBarEvent, wxRibbonButtonBarEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, wxRibbonButtonBarEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//int bar = arg.GetNumber(2)
	//int button = arg.GetNumber(3)
	//pThis->GetEntity()->wxRibbonButtonBarEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBarEvent, GetBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, GetBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBarEvent, SetBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, SetBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBarEvent, GetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, GetButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBarEvent, SetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, SetButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBarEvent, PopupMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, PopupMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->PopupMenu();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonButtonBarEvent)
{
	Gura_AssignMethod(wx_RibbonButtonBarEvent, wxRibbonButtonBarEvent);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, GetBar);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, SetBar);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, GetButton);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, SetButton);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, PopupMenu);
}

Gura_ImplementDescendantCreator(wx_RibbonButtonBarEvent)
{
	return new Object_wx_RibbonButtonBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
