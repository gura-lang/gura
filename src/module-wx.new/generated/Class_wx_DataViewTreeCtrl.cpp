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
Gura_DeclareFunctionAlias(__wxDataViewTreeCtrl, "wxDataViewTreeCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxDataViewTreeCtrl)
{
	//wxDataViewTreeCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDataViewTreeCtrl_1, "wxDataViewTreeCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDataViewTreeCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//wxDataViewTreeCtrl();
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
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int expanded = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->AppendContainer();
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
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int data = arg.GetNumber(3)
	//pThis->GetEntity()->AppendItem();
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
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
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
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChildren();
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
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
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
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildCount();
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
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
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
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemExpandedIcon();
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
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemIcon();
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
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemText();
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
	//int parent = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->GetNthChild();
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
	//int parent = arg.GetNumber(0)
	//int previous = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int expanded = arg.GetNumber(4)
	//int data = arg.GetNumber(5)
	//pThis->GetEntity()->InsertContainer();
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
	//int parent = arg.GetNumber(0)
	//int previous = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->InsertItem();
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
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsContainer();
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
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int expanded = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->PrependContainer();
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
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int data = arg.GetNumber(3)
	//pThis->GetEntity()->PrependItem();
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
	//int imagelist = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageList();
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
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
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
	//int item = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemExpandedIcon();
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
	//int item = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemIcon();
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
	//int item = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewTreeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTreeCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewTreeCtrl);
	Gura_AssignFunction(__wxDataViewTreeCtrl_1);
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
