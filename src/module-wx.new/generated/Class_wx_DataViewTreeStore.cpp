//----------------------------------------------------------------------------
// wxDataViewTreeStore
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewTreeStore
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewTreeStore
//----------------------------------------------------------------------------
Object_wx_DataViewTreeStore::~Object_wx_DataViewTreeStore()
{
}

Object *Object_wx_DataViewTreeStore::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewTreeStore::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewTreeStore:");
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
Gura_DeclareMethod(wx_DataViewTreeStore, wxDataViewTreeStore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeStore, wxDataViewTreeStore)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewTreeStore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, AppendContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, AppendContainer)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int expanded = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->AppendContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, AppendItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, AppendItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int data = arg.GetNumber(3)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeStore, DeleteAllItems)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, DeleteChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, DeleteChildren)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, DeleteItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, GetChildCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, GetChildCount)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, GetItemData)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, GetItemExpandedIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, GetItemExpandedIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemExpandedIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, GetItemIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, GetItemIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, GetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, GetItemText)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, GetNthChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, GetNthChild)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->GetNthChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, InsertContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, InsertContainer)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_DataViewTreeStore, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, InsertItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int previous = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, PrependContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, PrependContainer)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int expanded = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->PrependContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, PrependItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, PrependItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int icon = arg.GetNumber(2)
	//int data = arg.GetNumber(3)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, SetItemData)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, SetItemExpandedIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, SetItemExpandedIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemExpandedIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewTreeStore, SetItemIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, SetItemIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemIcon();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewTreeStore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTreeStore)
{
	Gura_AssignMethod(wx_DataViewTreeStore, wxDataViewTreeStore);
	Gura_AssignMethod(wx_DataViewTreeStore, AppendContainer);
	Gura_AssignMethod(wx_DataViewTreeStore, AppendItem);
	Gura_AssignMethod(wx_DataViewTreeStore, DeleteAllItems);
	Gura_AssignMethod(wx_DataViewTreeStore, DeleteChildren);
	Gura_AssignMethod(wx_DataViewTreeStore, DeleteItem);
	Gura_AssignMethod(wx_DataViewTreeStore, GetChildCount);
	Gura_AssignMethod(wx_DataViewTreeStore, GetItemData);
	Gura_AssignMethod(wx_DataViewTreeStore, GetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeStore, GetItemIcon);
	Gura_AssignMethod(wx_DataViewTreeStore, GetItemText);
	Gura_AssignMethod(wx_DataViewTreeStore, GetNthChild);
	Gura_AssignMethod(wx_DataViewTreeStore, InsertContainer);
	Gura_AssignMethod(wx_DataViewTreeStore, InsertItem);
	Gura_AssignMethod(wx_DataViewTreeStore, PrependContainer);
	Gura_AssignMethod(wx_DataViewTreeStore, PrependItem);
	Gura_AssignMethod(wx_DataViewTreeStore, SetItemData);
	Gura_AssignMethod(wx_DataViewTreeStore, SetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeStore, SetItemIcon);
}

Gura_ImplementDescendantCreator(wx_DataViewTreeStore)
{
	return new Object_wx_DataViewTreeStore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
