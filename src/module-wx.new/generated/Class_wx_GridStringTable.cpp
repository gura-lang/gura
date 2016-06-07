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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridStringTable, "GridStringTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridStringTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridStringTable)
{
	//wxGridStringTable();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridStringTable_1, "GridStringTable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridStringTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridStringTable_1)
{
	//int numRows = arg.GetNumber(0)
	//int numCols = arg.GetNumber(1)
	//wxGridStringTable(numRows, numCols);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	//pThis->GetEntity()->GetValue(row, col);
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
	//const wxString& value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue(row, col, value);
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
	//size_t pos = arg.GetNumber(0)
	//size_t numRows = arg.GetNumber(1)
	//pThis->GetEntity()->InsertRows(pos, numRows);
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
	//size_t numRows = arg.GetNumber(0)
	//pThis->GetEntity()->AppendRows(numRows);
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
	//size_t pos = arg.GetNumber(0)
	//size_t numRows = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRows(pos, numRows);
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
	//size_t pos = arg.GetNumber(0)
	//size_t numCols = arg.GetNumber(1)
	//pThis->GetEntity()->InsertCols(pos, numCols);
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
	//size_t numCols = arg.GetNumber(0)
	//pThis->GetEntity()->AppendCols(numCols);
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
	//size_t pos = arg.GetNumber(0)
	//size_t numCols = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteCols(pos, numCols);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __SetRowLabelValue, "SetRowLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __SetRowLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//const wxString& _arg1 = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowLabelValue(row, _arg1);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridStringTable, __SetColLabelValue, "SetColLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridStringTable, __SetColLabelValue)
{
	Object_wx_GridStringTable *pThis = Object_wx_GridStringTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//const wxString& _arg1 = arg.GetNumber(1)
	//pThis->GetEntity()->SetColLabelValue(col, _arg1);
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
	//pThis->GetEntity()->GetRowLabelValue(row);
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
	//pThis->GetEntity()->GetColLabelValue(col);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridStringTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridStringTable)
{
	// Constructor assignment
	Gura_AssignFunction(__GridStringTable);
	Gura_AssignFunction(__GridStringTable_1);
	// Method assignment
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
