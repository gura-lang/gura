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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewListStore, wxDataViewListStore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListStore, wxDataViewListStore)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewListStore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, PrependColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, PrependColumn)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//pThis->GetEntity()->PrependColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, InsertColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, InsertColumn)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int varianttype = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, AppendColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, AppendColumn)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int varianttype = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, AppendItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, AppendItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int values = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, PrependItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, PrependItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int values = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, InsertItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, DeleteItem)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListStore, DeleteAllItems)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, GetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListStore, GetItemCount)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, GetItemData)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListStore, GetColumnCount)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, GetColumnType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, GetColumnType)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, SetItemData)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, GetValueByRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, GetValueByRow)
{
	Object_wx_DataViewListStore *pThis = Object_wx_DataViewListStore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueByRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListStore, SetValueByRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListStore, SetValueByRow)
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
	Gura_AssignMethod(wx_DataViewListStore, wxDataViewListStore);
	Gura_AssignMethod(wx_DataViewListStore, PrependColumn);
	Gura_AssignMethod(wx_DataViewListStore, InsertColumn);
	Gura_AssignMethod(wx_DataViewListStore, AppendColumn);
	Gura_AssignMethod(wx_DataViewListStore, AppendItem);
	Gura_AssignMethod(wx_DataViewListStore, PrependItem);
	Gura_AssignMethod(wx_DataViewListStore, InsertItem);
	Gura_AssignMethod(wx_DataViewListStore, DeleteItem);
	Gura_AssignMethod(wx_DataViewListStore, DeleteAllItems);
	Gura_AssignMethod(wx_DataViewListStore, GetItemCount);
	Gura_AssignMethod(wx_DataViewListStore, GetItemData);
	Gura_AssignMethod(wx_DataViewListStore, GetColumnCount);
	Gura_AssignMethod(wx_DataViewListStore, GetColumnType);
	Gura_AssignMethod(wx_DataViewListStore, SetItemData);
	Gura_AssignMethod(wx_DataViewListStore, GetValueByRow);
	Gura_AssignMethod(wx_DataViewListStore, SetValueByRow);
}

Gura_ImplementDescendantCreator(wx_DataViewListStore)
{
	return new Object_wx_DataViewListStore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
