//----------------------------------------------------------------------------
// wxTaskBarIcon
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarIcon
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarIcon
//----------------------------------------------------------------------------
Object_wx_TaskBarIcon::~Object_wx_TaskBarIcon()
{
}

Object *Object_wx_TaskBarIcon::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarIcon::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarIcon:");
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
Gura_DeclareFunctionAlias(__wxTaskBarIcon, "wxTaskBarIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconType", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TaskBarIcon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxTaskBarIcon)
{
	//int iconType = arg.GetNumber(0)
	//wxTaskBarIcon();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TaskBarIcon, __Destroy, "Destroy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, __Destroy)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarIcon, __IsIconInstalled, "IsIconInstalled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, __IsIconInstalled)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIconInstalled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarIcon, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, __IsOk)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarIcon, __PopupMenu, "PopupMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarIcon, __PopupMenu)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->PopupMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarIcon, __RemoveIcon, "RemoveIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, __RemoveIcon)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RemoveIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarIcon, __SetIcon, "SetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarIcon, __SetIcon)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//int tooltip = arg.GetNumber(1)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarIcon, __IsAvailable, "IsAvailable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, __IsAvailable)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAvailable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarIcon, __CreatePopupMenu, "CreatePopupMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, __CreatePopupMenu)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreatePopupMenu();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarIcon
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarIcon)
{
	// Constructor assignment
	Gura_AssignFunction(__wxTaskBarIcon);
	// Method assignment
	Gura_AssignMethod(wx_TaskBarIcon, __Destroy);
	Gura_AssignMethod(wx_TaskBarIcon, __IsIconInstalled);
	Gura_AssignMethod(wx_TaskBarIcon, __IsOk);
	Gura_AssignMethod(wx_TaskBarIcon, __PopupMenu);
	Gura_AssignMethod(wx_TaskBarIcon, __RemoveIcon);
	Gura_AssignMethod(wx_TaskBarIcon, __SetIcon);
	Gura_AssignMethod(wx_TaskBarIcon, __IsAvailable);
	Gura_AssignMethod(wx_TaskBarIcon, __CreatePopupMenu);
}

Gura_ImplementDescendantCreator(wx_TaskBarIcon)
{
	return new Object_wx_TaskBarIcon((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
