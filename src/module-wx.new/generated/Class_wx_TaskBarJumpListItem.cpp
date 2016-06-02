//----------------------------------------------------------------------------
// wxTaskBarJumpListItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarJumpListItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarJumpListItem
//----------------------------------------------------------------------------
Object_wx_TaskBarJumpListItem::~Object_wx_TaskBarJumpListItem()
{
}

Object *Object_wx_TaskBarJumpListItem::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarJumpListItem::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarJumpListItem:");
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
Gura_DeclareMethod(wx_TaskBarJumpListItem, wxTaskBarJumpListItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentCategory", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filePath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arguments", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconPath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, wxTaskBarJumpListItem)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parentCategory = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int filePath = arg.GetNumber(3)
	//int arguments = arg.GetNumber(4)
	//int tooltip = arg.GetNumber(5)
	//int iconPath = arg.GetNumber(6)
	//int iconIndex = arg.GetNumber(7)
	//pThis->GetEntity()->wxTaskBarJumpListItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetType)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetType)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetTitle)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetTitle)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetFilePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetFilePath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetFilePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filePath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetFilePath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filePath = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetArguments)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetArguments)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArguments();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetArguments)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arguments", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetArguments)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int arguments = arg.GetNumber(0)
	//pThis->GetEntity()->SetArguments();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetTooltip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetTooltip)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTooltip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetTooltip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetTooltip)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tooltip = arg.GetNumber(0)
	//pThis->GetEntity()->SetTooltip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetIconPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetIconPath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIconPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetIconPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconPath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetIconPath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iconPath = arg.GetNumber(0)
	//pThis->GetEntity()->SetIconPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetIconIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetIconIndex)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIconIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetIconIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetIconIndex)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iconIndex = arg.GetNumber(0)
	//pThis->GetEntity()->SetIconIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, GetCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, GetCategory)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListItem, SetCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "category", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, SetCategory)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int category = arg.GetNumber(0)
	//pThis->GetEntity()->SetCategory();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarJumpListItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarJumpListItem)
{
	Gura_AssignMethod(wx_TaskBarJumpListItem, wxTaskBarJumpListItem);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetType);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetType);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetTitle);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetTitle);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetFilePath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetFilePath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetArguments);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetArguments);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetTooltip);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetTooltip);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetIconPath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetIconPath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetIconIndex);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetIconIndex);
	Gura_AssignMethod(wx_TaskBarJumpListItem, GetCategory);
	Gura_AssignMethod(wx_TaskBarJumpListItem, SetCategory);
}

Gura_ImplementDescendantCreator(wx_TaskBarJumpListItem)
{
	return new Object_wx_TaskBarJumpListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
