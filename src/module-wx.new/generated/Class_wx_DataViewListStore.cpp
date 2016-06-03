//----------------------------------------------------------------------------
// wxDataViewListStore
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListStore
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListStore
//----------------------------------------------------------------------------
Object_wx_DataViewListStore::~Object_wx_DataViewListStore()
{
}

Object *Object_wx_DataViewListStore::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewListStore::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewListStore:");
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
Gura_DeclareFunctionAlias(__wxDataViewListStore, "wxDataViewListStore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxDataViewListStore)
{
	//wxDataViewListStore();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewListStore, __PrependColumn, "PrependColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __PrependColumn)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//pThis->GetEntity()->PrependColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __InsertColumn, "InsertColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __InsertColumn)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int varianttype = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __AppendColumn, "AppendColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __AppendColumn)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __AppendItem, "AppendItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __AppendItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int values = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __PrependItem, "PrependItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __PrependItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int values = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __InsertItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __DeleteItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListStore, __DeleteAllItems)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __GetItemCount, "GetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListStore, __GetItemCount)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __GetItemData)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListStore, __GetColumnCount)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __GetColumnType, "GetColumnType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __GetColumnType)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __SetItemData)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __GetValueByRow, "GetValueByRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __GetValueByRow)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueByRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListStore, __SetValueByRow, "SetValueByRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, __SetValueByRow)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueByRow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewListStore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListStore)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewListStore);
	// Method assignment
	Gura_AssignMethod(wx_DataViewListStore, __PrependColumn);
	Gura_AssignMethod(wx_DataViewListStore, __InsertColumn);
	Gura_AssignMethod(wx_DataViewListStore, __AppendColumn);
	Gura_AssignMethod(wx_DataViewListStore, __AppendItem);
	Gura_AssignMethod(wx_DataViewListStore, __PrependItem);
	Gura_AssignMethod(wx_DataViewListStore, __InsertItem);
	Gura_AssignMethod(wx_DataViewListStore, __DeleteItem);
	Gura_AssignMethod(wx_DataViewListStore, __DeleteAllItems);
	Gura_AssignMethod(wx_DataViewListStore, __GetItemCount);
	Gura_AssignMethod(wx_DataViewListStore, __GetItemData);
	Gura_AssignMethod(wx_DataViewListStore, __GetColumnCount);
	Gura_AssignMethod(wx_DataViewListStore, __GetColumnType);
	Gura_AssignMethod(wx_DataViewListStore, __SetItemData);
	Gura_AssignMethod(wx_DataViewListStore, __GetValueByRow);
	Gura_AssignMethod(wx_DataViewListStore, __SetValueByRow);
}

Gura_ImplementDescendantCreator(wx_DataViewListStore)
{
	return new Object_wx_DataViewListStore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
