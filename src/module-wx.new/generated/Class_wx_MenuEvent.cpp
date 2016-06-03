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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MenuEvent, "MenuEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MenuEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MenuEvent)
{
	//int type = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int menu = arg.GetNumber(2)
	//wxMenuEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MenuEvent, __GetMenu, "GetMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuEvent, __GetMenu)
{
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuEvent, __GetMenuId, "GetMenuId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuEvent, __GetMenuId)
{
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MenuEvent, __IsPopup, "IsPopup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MenuEvent, __IsPopup)
{
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPopup();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__MenuEvent);
	// Method assignment
	Gura_AssignMethod(wx_MenuEvent, __GetMenu);
	Gura_AssignMethod(wx_MenuEvent, __GetMenuId);
	Gura_AssignMethod(wx_MenuEvent, __IsPopup);
}

Gura_ImplementDescendantCreator(wx_MenuEvent)
{
	return new Object_wx_MenuEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
