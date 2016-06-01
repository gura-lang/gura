//----------------------------------------------------------------------------
// wxMenuEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMenuEvent
//----------------------------------------------------------------------------
Object_wx_MenuEvent::~Object_wx_MenuEvent()
{
}

Object *Object_wx_MenuEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MenuEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MenuEvent:");
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
Gura_DeclareMethod(wx_MenuEvent, wxMenuEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MenuEvent, wxMenuEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int menu = arg.GetNumber(2)
	//pThis->GetEntity()->wxMenuEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuEvent, GetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuEvent, GetMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuEvent, GetMenuId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuEvent, GetMenuId)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMenuId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MenuEvent, IsPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuEvent, IsPopup)
{
	Signal &sig = env.GetSignal();
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPopup();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuEvent)
{
	Gura_AssignMethod(wx_MenuEvent, wxMenuEvent);
	Gura_AssignMethod(wx_MenuEvent, GetMenu);
	Gura_AssignMethod(wx_MenuEvent, GetMenuId);
	Gura_AssignMethod(wx_MenuEvent, IsPopup);
}

Gura_ImplementDescendantCreator(wx_MenuEvent)
{
	return new Object_wx_MenuEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
