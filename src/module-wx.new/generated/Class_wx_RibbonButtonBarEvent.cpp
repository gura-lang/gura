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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RibbonButtonBarEvent, "RibbonButtonBarEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonButtonBarEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonButtonBarEvent)
{
	//wxEventType command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//wxRibbonButtonBar* bar = arg.GetNumber(2)
	//wxRibbonButtonBarButtonBase* button = arg.GetNumber(3)
	//wxRibbonButtonBarEvent(command_type, win_id, bar, button);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonButtonBarEvent, __GetBar, "GetBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, __GetBar)
{
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonButtonBar* _rtn = pThis->GetEntity()->GetBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonButtonBarEvent, __SetBar, "SetBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, __SetBar)
{
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonButtonBar* bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetBar(bar);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonButtonBarEvent, __GetButton, "GetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, __GetButton)
{
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonButtonBarButtonBase* _rtn = pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonButtonBarEvent, __SetButton, "SetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, __SetButton)
{
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonButtonBarButtonBase* bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetButton(bar);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonButtonBarEvent, __PopupMenu, "PopupMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBarEvent, __PopupMenu)
{
	Object_wx_RibbonButtonBarEvent *pThis = Object_wx_RibbonButtonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* menu = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->PopupMenu(menu);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonButtonBarEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonButtonBarEvent);
	// Method assignment
	Gura_AssignMethod(wx_RibbonButtonBarEvent, __GetBar);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, __SetBar);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, __GetButton);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, __SetButton);
	Gura_AssignMethod(wx_RibbonButtonBarEvent, __PopupMenu);
}

Gura_ImplementDescendantCreator(wx_RibbonButtonBarEvent)
{
	return new Object_wx_RibbonButtonBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
