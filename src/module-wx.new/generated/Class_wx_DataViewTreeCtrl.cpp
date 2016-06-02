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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewTreeCtrl, wxDataViewTreeCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, wxDataViewTreeCtrl)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewTreeCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, wxDataViewTreeCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, wxDataViewTreeCtrl_1)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//pThis->GetEntity()->wxDataViewTreeCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, AppendContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, AppendContainer)
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

Gura_DeclareMethod(wx_DataViewTreeCtrl, AppendItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, AppendItem)
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

Gura_DeclareMethod(wx_DataViewTreeCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, Create)
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

Gura_DeclareMethod(wx_DataViewTreeCtrl, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, DeleteAllItems)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, DeleteChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, DeleteChildren)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, DeleteItem)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetChildCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetChildCount)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetImageList)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetItemData)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetItemExpandedIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetItemExpandedIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemExpandedIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetItemIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetItemIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetItemText)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetNthChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetNthChild)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->GetNthChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetStore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetStore)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, GetStore_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, GetStore_1)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, InsertContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, InsertContainer)
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

Gura_DeclareMethod(wx_DataViewTreeCtrl, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, InsertItem)
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

Gura_DeclareMethod(wx_DataViewTreeCtrl, IsContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, IsContainer)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, PrependContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, PrependContainer)
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

Gura_DeclareMethod(wx_DataViewTreeCtrl, PrependItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, PrependItem)
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

Gura_DeclareMethod(wx_DataViewTreeCtrl, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imagelist", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, SetImageList)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imagelist = arg.GetNumber(0)
	//pThis->GetEntity()->SetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, SetItemData)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, SetItemExpandedIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, SetItemExpandedIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemExpandedIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, SetItemIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, SetItemIcon)
{
	Object_wx_DataViewTreeCtrl *pThis = Object_wx_DataViewTreeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeCtrl, SetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeCtrl, SetItemText)
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
	Gura_AssignMethod(wx_DataViewTreeCtrl, wxDataViewTreeCtrl);
	Gura_AssignMethod(wx_DataViewTreeCtrl, wxDataViewTreeCtrl_1);
	Gura_AssignMethod(wx_DataViewTreeCtrl, AppendContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, AppendItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, Create);
	Gura_AssignMethod(wx_DataViewTreeCtrl, DeleteAllItems);
	Gura_AssignMethod(wx_DataViewTreeCtrl, DeleteChildren);
	Gura_AssignMethod(wx_DataViewTreeCtrl, DeleteItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetChildCount);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetImageList);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetItemData);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetItemIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetItemText);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetNthChild);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetStore);
	Gura_AssignMethod(wx_DataViewTreeCtrl, GetStore_1);
	Gura_AssignMethod(wx_DataViewTreeCtrl, InsertContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, InsertItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, IsContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, PrependContainer);
	Gura_AssignMethod(wx_DataViewTreeCtrl, PrependItem);
	Gura_AssignMethod(wx_DataViewTreeCtrl, SetImageList);
	Gura_AssignMethod(wx_DataViewTreeCtrl, SetItemData);
	Gura_AssignMethod(wx_DataViewTreeCtrl, SetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, SetItemIcon);
	Gura_AssignMethod(wx_DataViewTreeCtrl, SetItemText);
}

Gura_ImplementDescendantCreator(wx_DataViewTreeCtrl)
{
	return new Object_wx_DataViewTreeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
