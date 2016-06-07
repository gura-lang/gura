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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TaskBarJumpListItem, "TaskBarJumpListItem")
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
	SetClassToConstruct(Gura_UserClass(wx_TaskBarJumpListItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TaskBarJumpListItem)
{
	//wxTaskBarJumpListCategory* parentCategory = arg.GetNumber(0)
	//wxTaskBarJumpListItemType type = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxString& filePath = arg.GetNumber(3)
	//const wxString& arguments = arg.GetNumber(4)
	//const wxString& tooltip = arg.GetNumber(5)
	//const wxString& iconPath = arg.GetNumber(6)
	//int iconIndex = arg.GetNumber(7)
	//wxTaskBarJumpListItem(parentCategory, type, title, filePath, arguments, tooltip, iconPath, iconIndex);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetType)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetType, "SetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetType)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTaskBarJumpListItemType type = arg.GetNumber(0)
	//pThis->GetEntity()->SetType(type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetTitle)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetTitle)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle(title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetFilePath, "GetFilePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetFilePath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilePath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetFilePath, "SetFilePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filePath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetFilePath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filePath = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilePath(filePath);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetArguments, "GetArguments")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetArguments)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArguments();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetArguments, "SetArguments")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arguments", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetArguments)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& arguments = arg.GetNumber(0)
	//pThis->GetEntity()->SetArguments(arguments);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetTooltip, "GetTooltip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetTooltip)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTooltip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetTooltip, "SetTooltip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetTooltip)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& tooltip = arg.GetNumber(0)
	//pThis->GetEntity()->SetTooltip(tooltip);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetIconPath, "GetIconPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetIconPath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIconPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetIconPath, "SetIconPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconPath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetIconPath)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& iconPath = arg.GetNumber(0)
	//pThis->GetEntity()->SetIconPath(iconPath);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetIconIndex, "GetIconIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetIconIndex)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIconIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetIconIndex, "SetIconIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetIconIndex)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iconIndex = arg.GetNumber(0)
	//pThis->GetEntity()->SetIconIndex(iconIndex);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __GetCategory, "GetCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __GetCategory)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCategory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarJumpListItem, __SetCategory, "SetCategory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "category", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListItem, __SetCategory)
{
	Object_wx_TaskBarJumpListItem *pThis = Object_wx_TaskBarJumpListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTaskBarJumpListCategory* category = arg.GetNumber(0)
	//pThis->GetEntity()->SetCategory(category);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarJumpListItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarJumpListItem)
{
	// Constructor assignment
	Gura_AssignFunction(__TaskBarJumpListItem);
	// Method assignment
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetType);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetType);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetTitle);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetTitle);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetFilePath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetFilePath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetArguments);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetArguments);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetTooltip);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetTooltip);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetIconPath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetIconPath);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetIconIndex);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetIconIndex);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __GetCategory);
	Gura_AssignMethod(wx_TaskBarJumpListItem, __SetCategory);
}

Gura_ImplementDescendantCreator(wx_TaskBarJumpListItem)
{
	return new Object_wx_TaskBarJumpListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
