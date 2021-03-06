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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DataViewTreeStore, "DataViewTreeStore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewTreeStore));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewTreeStore)
{
	//wxDataViewTreeStore();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewTreeStore, __AppendContainer, "AppendContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __AppendContainer)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//const wxIcon& icon = arg.GetNumber(2)
	//const wxIcon& expanded = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//wxDataViewItem _rtn = pThis->GetEntity()->AppendContainer(parent, text, icon, expanded, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __AppendItem, "AppendItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __AppendItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//const wxIcon& icon = arg.GetNumber(2)
	//wxClientData* data = arg.GetNumber(3)
	//wxDataViewItem _rtn = pThis->GetEntity()->AppendItem(parent, text, icon, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __DeleteAllItems)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __DeleteChildren, "DeleteChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __DeleteChildren)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChildren(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __DeleteItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __GetChildCount, "GetChildCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __GetChildCount)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetChildCount(parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __GetItemData)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxClientData* _rtn = pThis->GetEntity()->GetItemData(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __GetItemExpandedIcon, "GetItemExpandedIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __GetItemExpandedIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//const wxIcon& _rtn = pThis->GetEntity()->GetItemExpandedIcon(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __GetItemIcon, "GetItemIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __GetItemIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//const wxIcon& _rtn = pThis->GetEntity()->GetItemIcon(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __GetItemText, "GetItemText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __GetItemText)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetItemText(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __GetNthChild, "GetNthChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __GetNthChild)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//wxDataViewItem _rtn = pThis->GetEntity()->GetNthChild(parent, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __InsertContainer, "InsertContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __InsertContainer)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItem& previous = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//const wxIcon& icon = arg.GetNumber(3)
	//const wxIcon& expanded = arg.GetNumber(4)
	//wxClientData* data = arg.GetNumber(5)
	//wxDataViewItem _rtn = pThis->GetEntity()->InsertContainer(parent, previous, text, icon, expanded, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "previous", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __InsertItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxDataViewItem& previous = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//const wxIcon& icon = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//wxDataViewItem _rtn = pThis->GetEntity()->InsertItem(parent, previous, text, icon, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __PrependContainer, "PrependContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __PrependContainer)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//const wxIcon& icon = arg.GetNumber(2)
	//const wxIcon& expanded = arg.GetNumber(3)
	//wxClientData* data = arg.GetNumber(4)
	//wxDataViewItem _rtn = pThis->GetEntity()->PrependContainer(parent, text, icon, expanded, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __PrependItem, "PrependItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __PrependItem)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& parent = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//const wxIcon& icon = arg.GetNumber(2)
	//wxClientData* data = arg.GetNumber(3)
	//wxDataViewItem _rtn = pThis->GetEntity()->PrependItem(parent, text, icon, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __SetItemData)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxClientData* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __SetItemExpandedIcon, "SetItemExpandedIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __SetItemExpandedIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//const wxIcon& icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemExpandedIcon(item, icon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewTreeStore, __SetItemIcon, "SetItemIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewTreeStore, __SetItemIcon)
{
	Object_wx_DataViewTreeStore *pThis = Object_wx_DataViewTreeStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//const wxIcon& icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemIcon(item, icon);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewTreeStore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTreeStore)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewTreeStore);
	// Method assignment
	Gura_AssignMethod(wx_DataViewTreeStore, __AppendContainer);
	Gura_AssignMethod(wx_DataViewTreeStore, __AppendItem);
	Gura_AssignMethod(wx_DataViewTreeStore, __DeleteAllItems);
	Gura_AssignMethod(wx_DataViewTreeStore, __DeleteChildren);
	Gura_AssignMethod(wx_DataViewTreeStore, __DeleteItem);
	Gura_AssignMethod(wx_DataViewTreeStore, __GetChildCount);
	Gura_AssignMethod(wx_DataViewTreeStore, __GetItemData);
	Gura_AssignMethod(wx_DataViewTreeStore, __GetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeStore, __GetItemIcon);
	Gura_AssignMethod(wx_DataViewTreeStore, __GetItemText);
	Gura_AssignMethod(wx_DataViewTreeStore, __GetNthChild);
	Gura_AssignMethod(wx_DataViewTreeStore, __InsertContainer);
	Gura_AssignMethod(wx_DataViewTreeStore, __InsertItem);
	Gura_AssignMethod(wx_DataViewTreeStore, __PrependContainer);
	Gura_AssignMethod(wx_DataViewTreeStore, __PrependItem);
	Gura_AssignMethod(wx_DataViewTreeStore, __SetItemData);
	Gura_AssignMethod(wx_DataViewTreeStore, __SetItemExpandedIcon);
	Gura_AssignMethod(wx_DataViewTreeStore, __SetItemIcon);
}

Gura_ImplementDescendantCreator(wx_DataViewTreeStore)
{
	return new Object_wx_DataViewTreeStore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
