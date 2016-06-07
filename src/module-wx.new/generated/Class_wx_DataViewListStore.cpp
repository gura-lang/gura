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
Gura_DeclareFunctionAlias(__DataViewListStore, "DataViewListStore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewListStore));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewListStore)
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
	//const wxString& varianttype = arg.GetNumber(0)
	//pThis->GetEntity()->PrependColumn(varianttype);
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
	//unsigned int pos = arg.GetNumber(0)
	//const wxString& varianttype = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn(pos, varianttype);
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
	//const wxString& varianttype = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn(varianttype);
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
	//const wxVector<wxVariant>& values = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//pThis->GetEntity()->AppendItem(values, data);
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
	//const wxVector<wxVariant>& values = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//pThis->GetEntity()->PrependItem(values, data);
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
	//unsigned int row = arg.GetNumber(0)
	//const wxVector<wxVariant>& values = arg.GetNumber(1)
	//wxUIntPtr data = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem(row, values, data);
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
	//unsigned pos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem(pos);
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
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData(item);
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
	//unsigned int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnType(col);
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
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData(item, data);
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
	//wxVariant& value = arg.GetNumber(0)
	//unsigned int row = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueByRow(value, row, col);
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
	//const wxVariant& value = arg.GetNumber(0)
	//unsigned int row = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueByRow(value, row, col);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewListStore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListStore)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewListStore);
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
