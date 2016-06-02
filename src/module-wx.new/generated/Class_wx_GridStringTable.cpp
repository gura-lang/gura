//----------------------------------------------------------------------------
// wxGridStringTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridStringTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridStringTable
//----------------------------------------------------------------------------
Object_wx_GridStringTable::~Object_wx_GridStringTable()
{
}

Object *Object_wx_GridStringTable::Clone() const
{
	return nullptr;
}

String Object_wx_GridStringTable::ToString(bool exprFlag)
{
	String rtn("<wx.GridStringTable:");
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
Gura_DeclareMethod(wx_GridStringTable, wxGridStringTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, wxGridStringTable)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridStringTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, wxGridStringTable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, wxGridStringTable_1)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numRows = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->wxGridStringTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, GetNumberRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, GetNumberRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, GetNumberCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, GetNumberCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, GetValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, SetValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, Clear)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, InsertRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, InsertRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numRows = arg.GetNumber(1)
	//pThis->GetEntity()->InsertRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, AppendRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, AppendRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numRows = arg.GetNumber(0)
	//pThis->GetEntity()->AppendRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, DeleteRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, DeleteRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numRows = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, InsertCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, InsertCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->InsertCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, AppendCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, AppendCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numCols = arg.GetNumber(0)
	//pThis->GetEntity()->AppendCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, DeleteCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, DeleteCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, SetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, SetRowLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, SetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, SetColLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColLabelValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, GetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, GetRowLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridStringTable, GetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, GetColLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColLabelValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridStringTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridStringTable)
{
	Gura_AssignMethod(wx_GridStringTable, wxGridStringTable);
	Gura_AssignMethod(wx_GridStringTable, wxGridStringTable_1);
	Gura_AssignMethod(wx_GridStringTable, GetNumberRows);
	Gura_AssignMethod(wx_GridStringTable, GetNumberCols);
	Gura_AssignMethod(wx_GridStringTable, GetValue);
	Gura_AssignMethod(wx_GridStringTable, SetValue);
	Gura_AssignMethod(wx_GridStringTable, Clear);
	Gura_AssignMethod(wx_GridStringTable, InsertRows);
	Gura_AssignMethod(wx_GridStringTable, AppendRows);
	Gura_AssignMethod(wx_GridStringTable, DeleteRows);
	Gura_AssignMethod(wx_GridStringTable, InsertCols);
	Gura_AssignMethod(wx_GridStringTable, AppendCols);
	Gura_AssignMethod(wx_GridStringTable, DeleteCols);
	Gura_AssignMethod(wx_GridStringTable, SetRowLabelValue);
	Gura_AssignMethod(wx_GridStringTable, SetColLabelValue);
	Gura_AssignMethod(wx_GridStringTable, GetRowLabelValue);
	Gura_AssignMethod(wx_GridStringTable, GetColLabelValue);
}

Gura_ImplementDescendantCreator(wx_GridStringTable)
{
	return new Object_wx_GridStringTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
