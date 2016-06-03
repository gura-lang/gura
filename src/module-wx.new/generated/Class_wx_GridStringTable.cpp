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
Gura_DeclareMethodAlias(wx_GridStringTable, __wxGridStringTable, "wxGridStringTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, __wxGridStringTable)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridStringTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __wxGridStringTable_1, "wxGridStringTable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __wxGridStringTable_1)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numRows = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->wxGridStringTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __GetNumberRows, "GetNumberRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, __GetNumberRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __GetNumberCols, "GetNumberCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, __GetNumberCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __GetValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __SetValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridStringTable, __Clear)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __InsertRows, "InsertRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __InsertRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numRows = arg.GetNumber(1)
	//pThis->GetEntity()->InsertRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __AppendRows, "AppendRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __AppendRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numRows = arg.GetNumber(0)
	//pThis->GetEntity()->AppendRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __DeleteRows, "DeleteRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __DeleteRows)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numRows = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __InsertCols, "InsertCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __InsertCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->InsertCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __AppendCols, "AppendCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __AppendCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numCols = arg.GetNumber(0)
	//pThis->GetEntity()->AppendCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __DeleteCols, "DeleteCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __DeleteCols)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __SetRowLabelValue, "SetRowLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __SetRowLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __SetColLabelValue, "SetColLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __SetColLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColLabelValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __GetRowLabelValue, "GetRowLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __GetRowLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __GetColLabelValue, "GetColLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __GetColLabelValue)
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
	Gura_AssignMethod(wx_GridStringTable, __wxGridStringTable);
	Gura_AssignMethod(wx_GridStringTable, __wxGridStringTable_1);
	Gura_AssignMethod(wx_GridStringTable, __GetNumberRows);
	Gura_AssignMethod(wx_GridStringTable, __GetNumberCols);
	Gura_AssignMethod(wx_GridStringTable, __GetValue);
	Gura_AssignMethod(wx_GridStringTable, __SetValue);
	Gura_AssignMethod(wx_GridStringTable, __Clear);
	Gura_AssignMethod(wx_GridStringTable, __InsertRows);
	Gura_AssignMethod(wx_GridStringTable, __AppendRows);
	Gura_AssignMethod(wx_GridStringTable, __DeleteRows);
	Gura_AssignMethod(wx_GridStringTable, __InsertCols);
	Gura_AssignMethod(wx_GridStringTable, __AppendCols);
	Gura_AssignMethod(wx_GridStringTable, __DeleteCols);
	Gura_AssignMethod(wx_GridStringTable, __SetRowLabelValue);
	Gura_AssignMethod(wx_GridStringTable, __SetColLabelValue);
	Gura_AssignMethod(wx_GridStringTable, __GetRowLabelValue);
	Gura_AssignMethod(wx_GridStringTable, __GetColLabelValue);
}

Gura_ImplementDescendantCreator(wx_GridStringTable)
{
	return new Object_wx_GridStringTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
