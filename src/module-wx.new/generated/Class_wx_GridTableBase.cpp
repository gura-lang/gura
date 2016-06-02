//----------------------------------------------------------------------------
// wxGridTableBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridTableBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridTableBase
//----------------------------------------------------------------------------
Object_wx_GridTableBase::~Object_wx_GridTableBase()
{
}

Object *Object_wx_GridTableBase::Clone() const
{
	return nullptr;
}

String Object_wx_GridTableBase::ToString(bool exprFlag)
{
	String rtn("<wx.GridTableBase:");
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
Gura_DeclareMethod(wx_GridTableBase, wxGridTableBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, wxGridTableBase)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridTableBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetNumberRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, GetNumberRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetNumberCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, GetNumberCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetRowsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, GetRowsCount)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetColsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, GetColsCount)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, IsEmptyCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, IsEmptyCell)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->IsEmptyCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coords", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, IsEmpty)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int coords = arg.GetNumber(0)
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetTypeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetTypeName)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetTypeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, CanGetValueAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, CanGetValueAs)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int typeName = arg.GetNumber(2)
	//pThis->GetEntity()->CanGetValueAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, CanSetValueAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, CanSetValueAs)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int typeName = arg.GetNumber(2)
	//pThis->GetEntity()->CanSetValueAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsLong)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueAsLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsDouble)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueAsDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsBool)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueAsBool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsCustom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsCustom)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int typeName = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueAsCustom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsLong)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueAsLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsDouble)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueAsDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsBool)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueAsBool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsCustom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsCustom)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int typeName = arg.GetNumber(2)
	//int value = arg.GetNumber(3)
	//pThis->GetEntity()->SetValueAsCustom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetView)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//pThis->GetEntity()->SetView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, GetView)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, Clear)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, InsertRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, InsertRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numRows = arg.GetNumber(1)
	//pThis->GetEntity()->InsertRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, AppendRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, AppendRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numRows = arg.GetNumber(0)
	//pThis->GetEntity()->AppendRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, DeleteRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, DeleteRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numRows = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, InsertCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, InsertCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->InsertCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, AppendCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, AppendCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numCols = arg.GetNumber(0)
	//pThis->GetEntity()->AppendCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, DeleteCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, DeleteCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetRowLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetColLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColLabelValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetRowLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetColLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetColLabelValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetAttrProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrProvider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetAttrProvider)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attrProvider = arg.GetNumber(0)
	//pThis->GetEntity()->SetAttrProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetAttrProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, GetAttrProvider)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttrProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int kind = arg.GetNumber(2)
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetRowAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetRowAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetColAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetColAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetColAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, CanHaveAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, CanHaveAttributes)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanHaveAttributes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridTableBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridTableBase)
{
	Gura_AssignMethod(wx_GridTableBase, wxGridTableBase);
	Gura_AssignMethod(wx_GridTableBase, GetNumberRows);
	Gura_AssignMethod(wx_GridTableBase, GetNumberCols);
	Gura_AssignMethod(wx_GridTableBase, GetRowsCount);
	Gura_AssignMethod(wx_GridTableBase, GetColsCount);
	Gura_AssignMethod(wx_GridTableBase, IsEmptyCell);
	Gura_AssignMethod(wx_GridTableBase, IsEmpty);
	Gura_AssignMethod(wx_GridTableBase, GetValue);
	Gura_AssignMethod(wx_GridTableBase, SetValue);
	Gura_AssignMethod(wx_GridTableBase, GetTypeName);
	Gura_AssignMethod(wx_GridTableBase, CanGetValueAs);
	Gura_AssignMethod(wx_GridTableBase, CanSetValueAs);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsLong);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsDouble);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsBool);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsCustom);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsLong);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsDouble);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsBool);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsCustom);
	Gura_AssignMethod(wx_GridTableBase, SetView);
	Gura_AssignMethod(wx_GridTableBase, GetView);
	Gura_AssignMethod(wx_GridTableBase, Clear);
	Gura_AssignMethod(wx_GridTableBase, InsertRows);
	Gura_AssignMethod(wx_GridTableBase, AppendRows);
	Gura_AssignMethod(wx_GridTableBase, DeleteRows);
	Gura_AssignMethod(wx_GridTableBase, InsertCols);
	Gura_AssignMethod(wx_GridTableBase, AppendCols);
	Gura_AssignMethod(wx_GridTableBase, DeleteCols);
	Gura_AssignMethod(wx_GridTableBase, GetRowLabelValue);
	Gura_AssignMethod(wx_GridTableBase, GetColLabelValue);
	Gura_AssignMethod(wx_GridTableBase, SetRowLabelValue);
	Gura_AssignMethod(wx_GridTableBase, SetColLabelValue);
	Gura_AssignMethod(wx_GridTableBase, SetAttrProvider);
	Gura_AssignMethod(wx_GridTableBase, GetAttrProvider);
	Gura_AssignMethod(wx_GridTableBase, GetAttr);
	Gura_AssignMethod(wx_GridTableBase, SetAttr);
	Gura_AssignMethod(wx_GridTableBase, SetRowAttr);
	Gura_AssignMethod(wx_GridTableBase, SetColAttr);
	Gura_AssignMethod(wx_GridTableBase, CanHaveAttributes);
}

Gura_ImplementDescendantCreator(wx_GridTableBase)
{
	return new Object_wx_GridTableBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
