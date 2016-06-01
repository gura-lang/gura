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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewListCtrl, wxDataViewListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, wxDataViewListCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, wxDataViewListCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, wxDataViewListCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//pThis->GetEntity()->wxDataViewListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, ~wxDataViewListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, ~wxDataViewListCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDataViewListCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int validator = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetStore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetStore)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetStore_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetStore_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, ItemToRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, ItemToRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ItemToRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, RowToItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, RowToItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowToItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetSelectedRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetSelectedRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, SelectRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, SelectRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SelectRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, UnselectRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, UnselectRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->UnselectRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, IsRowSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, IsRowSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->IsRowSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, AppendColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, AppendColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, AppendColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, AppendColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//int varianttype = arg.GetNumber(1)
	//pThis->GetEntity()->AppendColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, AppendTextColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, AppendTextColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, AppendToggleColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, AppendToggleColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendToggleColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, AppendProgressColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, AppendProgressColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendProgressColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, AppendIconTextColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, AppendIconTextColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int align = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->AppendIconTextColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, InsertColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, InsertColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, InsertColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, InsertColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//int varianttype = arg.GetNumber(2)
	//pThis->GetEntity()->InsertColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, PrependColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, PrependColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->PrependColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, PrependColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "varianttype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, PrependColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//int varianttype = arg.GetNumber(1)
	//pThis->GetEntity()->PrependColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, AppendItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, AppendItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int values = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->AppendItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, PrependItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, PrependItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int values = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->PrependItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "values", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, InsertItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int values = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//pThis->GetEntity()->InsertItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, DeleteItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, DeleteAllItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, SetTextValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, SetTextValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetTextValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetTextValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetTextValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetTextValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, SetToggleValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, SetToggleValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetToggleValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, GetToggleValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, GetToggleValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetToggleValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewListCtrl, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListCtrl, SetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewListCtrl *pThis = Object_wx_DataViewListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListCtrl)
{
	Gura_AssignMethod(wx_DataViewListCtrl, wxDataViewListCtrl);
	Gura_AssignMethod(wx_DataViewListCtrl, wxDataViewListCtrl_1);
	Gura_AssignMethod(wx_DataViewListCtrl, ~wxDataViewListCtrl);
	Gura_AssignMethod(wx_DataViewListCtrl, Create);
	Gura_AssignMethod(wx_DataViewListCtrl, GetStore);
	Gura_AssignMethod(wx_DataViewListCtrl, GetStore_1);
	Gura_AssignMethod(wx_DataViewListCtrl, ItemToRow);
	Gura_AssignMethod(wx_DataViewListCtrl, RowToItem);
	Gura_AssignMethod(wx_DataViewListCtrl, GetSelectedRow);
	Gura_AssignMethod(wx_DataViewListCtrl, SelectRow);
	Gura_AssignMethod(wx_DataViewListCtrl, UnselectRow);
	Gura_AssignMethod(wx_DataViewListCtrl, IsRowSelected);
	Gura_AssignMethod(wx_DataViewListCtrl, AppendColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, AppendColumn_1);
	Gura_AssignMethod(wx_DataViewListCtrl, AppendTextColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, AppendToggleColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, AppendProgressColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, AppendIconTextColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, InsertColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, InsertColumn_1);
	Gura_AssignMethod(wx_DataViewListCtrl, PrependColumn);
	Gura_AssignMethod(wx_DataViewListCtrl, PrependColumn_1);
	Gura_AssignMethod(wx_DataViewListCtrl, AppendItem);
	Gura_AssignMethod(wx_DataViewListCtrl, PrependItem);
	Gura_AssignMethod(wx_DataViewListCtrl, InsertItem);
	Gura_AssignMethod(wx_DataViewListCtrl, DeleteItem);
	Gura_AssignMethod(wx_DataViewListCtrl, DeleteAllItems);
	Gura_AssignMethod(wx_DataViewListCtrl, GetItemCount);
	Gura_AssignMethod(wx_DataViewListCtrl, GetItemData);
	Gura_AssignMethod(wx_DataViewListCtrl, SetValue);
	Gura_AssignMethod(wx_DataViewListCtrl, GetValue);
	Gura_AssignMethod(wx_DataViewListCtrl, SetTextValue);
	Gura_AssignMethod(wx_DataViewListCtrl, GetTextValue);
	Gura_AssignMethod(wx_DataViewListCtrl, SetToggleValue);
	Gura_AssignMethod(wx_DataViewListCtrl, GetToggleValue);
	Gura_AssignMethod(wx_DataViewListCtrl, SetItemData);
}

Gura_ImplementDescendantCreator(wx_DataViewListCtrl)
{
	return new Object_wx_DataViewListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
