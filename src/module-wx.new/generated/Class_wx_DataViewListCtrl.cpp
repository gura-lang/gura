//----------------------------------------------------------------------------
// wxDataViewListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewListCtrl::~Object_wx_DataViewListCtrl()
{
}

Object *Object_wx_DataViewListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewListCtrl:");
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
Gura_DeclareFunctionAlias(__DataViewListCtrl, "DataViewListCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewListCtrl)
{
	//wxDataViewListCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DataViewListCtrl_1, "DataViewListCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewListCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxValidator& validator = arg.GetNumber(5)
	//wxDataViewListCtrl(parent, id, pos, size, style, validator);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewListCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __Create)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetStore, "GetStore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetStore)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetStore_1, "GetStore_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetStore_1)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __ItemToRow, "ItemToRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __ItemToRow)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->ItemToRow(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __RowToItem, "RowToItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __RowToItem)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowToItem(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetSelectedRow, "GetSelectedRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetSelectedRow)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __SelectRow, "SelectRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __SelectRow)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned row = arg.GetNumber(0)
	//pThis->GetEntity()->SelectRow(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __UnselectRow, "UnselectRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __UnselectRow)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned row = arg.GetNumber(0)
	//pThis->GetEntity()->UnselectRow(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __IsRowSelected, "IsRowSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __IsRowSelected)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned row = arg.GetNumber(0)
	//pThis->GetEntity()->IsRowSelected(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __AppendColumn, "AppendColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __AppendColumn)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewColumn* column = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __AppendColumn_1, "AppendColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __AppendColumn_1)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewColumn* column = arg.GetNumber(0)
	//const wxString& varianttype = arg.GetNumber(1)
	//pThis->GetEntity()->AppendColumn(column, varianttype);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __AppendTextColumn, "AppendTextColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __AppendTextColumn)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//wxAlignment align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendTextColumn(label, mode, width, align, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __AppendToggleColumn, "AppendToggleColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __AppendToggleColumn)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//wxAlignment align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendToggleColumn(label, mode, width, align, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __AppendProgressColumn, "AppendProgressColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __AppendProgressColumn)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//wxAlignment align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendProgressColumn(label, mode, width, align, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __AppendIconTextColumn, "AppendIconTextColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __AppendIconTextColumn)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//wxDataViewCellMode mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//wxAlignment align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendIconTextColumn(label, mode, width, align, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __InsertColumn, "InsertColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __InsertColumn)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int pos = arg.GetNumber(0)
	//wxDataViewColumn* column = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn(pos, column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __InsertColumn_1, "InsertColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __InsertColumn_1)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int pos = arg.GetNumber(0)
	//wxDataViewColumn* column = arg.GetNumber(1)
	//const wxString& varianttype = arg.GetNumber(2)
	//pThis->GetEntity()->InsertColumn(pos, column, varianttype);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __PrependColumn, "PrependColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __PrependColumn)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewColumn* column = arg.GetNumber(0)
	//pThis->GetEntity()->PrependColumn(column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __PrependColumn_1, "PrependColumn_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __PrependColumn_1)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataViewColumn* column = arg.GetNumber(0)
	//const wxString& varianttype = arg.GetNumber(1)
	//pThis->GetEntity()->PrependColumn(column, varianttype);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __AppendItem, "AppendItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __AppendItem)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVector<wxVariant>& values = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//pThis->GetEntity()->AppendItem(values, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __PrependItem, "PrependItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __PrependItem)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVector<wxVariant>& values = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//pThis->GetEntity()->PrependItem(values, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __InsertItem, "InsertItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __InsertItem)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int row = arg.GetNumber(0)
	//const wxVector<wxVariant>& values = arg.GetNumber(1)
	//wxUIntPtr data = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem(row, values, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __DeleteItem, "DeleteItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __DeleteItem)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned row = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem(row);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __DeleteAllItems, "DeleteAllItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __DeleteAllItems)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetItemCount, "GetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetItemCount)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetItemData, "GetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetItemData)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __SetValue)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVariant& value = arg.GetNumber(0)
	//unsigned int row = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue(value, row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetValue)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant& value = arg.GetNumber(0)
	//unsigned int row = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValue(value, row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __SetTextValue, "SetTextValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __SetTextValue)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& value = arg.GetNumber(0)
	//unsigned int row = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetTextValue(value, row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetTextValue, "GetTextValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetTextValue)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int row = arg.GetNumber(0)
	//unsigned int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetTextValue(row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __SetToggleValue, "SetToggleValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __SetToggleValue)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool value = arg.GetNumber(0)
	//unsigned int row = arg.GetNumber(1)
	//unsigned int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetToggleValue(value, row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __GetToggleValue, "GetToggleValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __GetToggleValue)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int row = arg.GetNumber(0)
	//unsigned int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetToggleValue(row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListCtrl, __SetItemData, "SetItemData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, __SetItemData)
{
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDataViewItem& item = arg.GetNumber(0)
	//wxUIntPtr data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData(item, data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewListCtrl);
	Gura_AssignFunction(__DataViewListCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_DataViewListCtrl, __Create);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetStore);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetStore_1);
	Gura_AssignMethod(wx_DataViewListCtrl, __ItemToRow);
	Gura_AssignMethod(wx_DataViewListCtrl, __RowToItem);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetSelectedRow);
	Gura_AssignMethod(wx_DataViewListCtrl, __SelectRow);
	Gura_AssignMethod(wx_DataViewListCtrl, __UnselectRow);
	Gura_AssignMethod(wx_DataViewListCtrl, __IsRowSelected);
	Gura_AssignMethod(wx_DataViewListCtrl, __AppendColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, __AppendColumn_1);
	Gura_AssignMethod(wx_DataViewListCtrl, __AppendTextColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, __AppendToggleColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, __AppendProgressColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, __AppendIconTextColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, __InsertColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, __InsertColumn_1);
	Gura_AssignMethod(wx_DataViewListCtrl, __PrependColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, __PrependColumn_1);
	Gura_AssignMethod(wx_DataViewListCtrl, __AppendItem);
	Gura_AssignMethod(wx_DataViewListCtrl, __PrependItem);
	Gura_AssignMethod(wx_DataViewListCtrl, __InsertItem);
	Gura_AssignMethod(wx_DataViewListCtrl, __DeleteItem);
	Gura_AssignMethod(wx_DataViewListCtrl, __DeleteAllItems);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetItemCount);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetItemData);
	Gura_AssignMethod(wx_DataViewListCtrl, __SetValue);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetValue);
	Gura_AssignMethod(wx_DataViewListCtrl, __SetTextValue);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetTextValue);
	Gura_AssignMethod(wx_DataViewListCtrl, __SetToggleValue);
	Gura_AssignMethod(wx_DataViewListCtrl, __GetToggleValue);
	Gura_AssignMethod(wx_DataViewListCtrl, __SetItemData);
}

Gura_ImplementDescendantCreator(wx_DataViewListCtrl)
{
	return new Object_wx_DataViewListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
