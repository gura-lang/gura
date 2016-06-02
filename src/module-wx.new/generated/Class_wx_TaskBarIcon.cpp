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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TaskBarIcon, wxTaskBarIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarIcon, wxTaskBarIcon)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iconType = arg.GetNumber(0)
	//pThis->GetEntity()->wxTaskBarIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, Destroy)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, IsIconInstalled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, IsIconInstalled)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIconInstalled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, IsOk)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, PopupMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarIcon, PopupMenu)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->PopupMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, RemoveIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, RemoveIcon)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RemoveIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarIcon, SetIcon)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//int tooltip = arg.GetNumber(1)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, IsAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, IsAvailable)
{
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAvailable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, CreatePopupMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarIcon, CreatePopupMenu)
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
	Gura_AssignMethod(wx_TaskBarIcon, wxTaskBarIcon);
	Gura_AssignMethod(wx_TaskBarIcon, Destroy);
	Gura_AssignMethod(wx_TaskBarIcon, IsIconInstalled);
	Gura_AssignMethod(wx_TaskBarIcon, IsOk);
	Gura_AssignMethod(wx_TaskBarIcon, PopupMenu);
	Gura_AssignMethod(wx_TaskBarIcon, RemoveIcon);
	Gura_AssignMethod(wx_TaskBarIcon, SetIcon);
	Gura_AssignMethod(wx_TaskBarIcon, IsAvailable);
	Gura_AssignMethod(wx_TaskBarIcon, CreatePopupMenu);
}

Gura_ImplementDescendantCreator(wx_TaskBarIcon)
{
	return new Object_wx_TaskBarIcon((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
