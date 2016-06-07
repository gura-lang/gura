//----------------------------------------------------------------------------
// wxDataViewTreeCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewTreeCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewTreeCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewTreeCtrl::~Object_wx_DataViewTreeCtrl()
{
}

Object *Object_wx_DataViewTreeCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewTreeCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewTreeCtrl:");
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
Gura_DeclareFunctionAlias(__DataViewTreeCtrl, "DataViewTreeCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewTreeCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewTreeCtrl)
{
	//wxDataViewTreeCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DataViewTreeCtrl_1, "DataViewTreeCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewTreeCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewTreeCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//wxDataViewTreeCtrl(parent, id, pos, size, style, validator);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __AppendContainer, "AppendContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __AppendContainer)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int expanded = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//pThis->GetEntity()->AppendContainer(parent, text, icon, expanded, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __AppendItem, "AppendItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __AppendItem)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//wxClientData* data = arg.GetNumber(3)
	//pThis->GetEntity()->AppendItem(parent, text, icon, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __Create)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//pThis->GetEntity()->Create(parent, id, pos, size, style, validator);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __DeleteAllItems)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __DeleteChildren, "DeleteChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __DeleteChildren)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChildren(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __DeleteItem)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetChildCount, "GetChildCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetChildCount)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildCount(parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetImageList, "GetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetImageList)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetItemData)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetItemExpandedIcon, "GetItemExpandedIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetItemExpandedIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemExpandedIcon(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetItemIcon, "GetItemIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetItemIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemIcon(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetItemText, "GetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetItemText)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemText(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetNthChild, "GetNthChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetNthChild)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//pThis->GetEntity()->GetNthChild(parent, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetStore, "GetStore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetStore)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __GetStore_1, "GetStore_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __GetStore_1)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __InsertContainer, "InsertContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __InsertContainer)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItem& previous = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int expanded = arg.GetNumber(4)
	//wxClientData* data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertContainer(parent, previous, text, icon, expanded, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __InsertItem)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItem& previous = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//pThis->GetEntity()->InsertItem(parent, previous, text, icon, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __IsContainer, "IsContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __IsContainer)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->IsContainer(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __PrependContainer, "PrependContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __PrependContainer)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int expanded = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//pThis->GetEntity()->PrependContainer(parent, text, icon, expanded, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __PrependItem, "PrependItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __PrependItem)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//wxClientData* data = arg.GetNumber(3)
	//pThis->GetEntity()->PrependItem(parent, text, icon, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __SetImageList, "SetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imagelist", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __SetImageList)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxImageList* imagelist = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageList(imagelist);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __SetItemData)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxClientData* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __SetItemExpandedIcon, "SetItemExpandedIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __SetItemExpandedIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//const wxIcon& icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemExpandedIcon(item, icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __SetItemIcon, "SetItemIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __SetItemIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//const wxIcon& icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemIcon(item, icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeCtrl, __SetItemText, "SetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, __SetItemText)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText(item, text);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewTreeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTreeCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewTreeCtrl);
	Gura_AssignFunction(__DataViewTreeCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_DataViewTreeCtrl, __AppendContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __AppendItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __Create);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __DeleteAllItems);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __DeleteChildren);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __DeleteItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetChildCount);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetImageList);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetItemData);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetItemIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetItemText);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetNthChild);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetStore);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __GetStore_1);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __InsertContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __InsertItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __IsContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __PrependContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __PrependItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __SetImageList);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __SetItemData);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __SetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __SetItemIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, __SetItemText);
}

Gura_ImplementDescendantCreator(wx_DataViewTreeCtrl)
{
	return new Object_wx_DataViewTreeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
