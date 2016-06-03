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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridTableBase, "GridTableBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridTableBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridTableBase)
{
	//wxGridTableBase();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridTableBase, __GetNumberRows, "GetNumberRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __GetNumberRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetNumberCols, "GetNumberCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __GetNumberCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetRowsCount, "GetRowsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __GetRowsCount)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetColsCount, "GetColsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __GetColsCount)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __IsEmptyCell, "IsEmptyCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __IsEmptyCell)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->IsEmptyCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "coords", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __IsEmpty)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGridCellCoords& coords = arg.GetNumber(0)
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetTypeName, "GetTypeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetTypeName)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetTypeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __CanGetValueAs, "CanGetValueAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __CanGetValueAs)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//const wxString& typeName = arg.GetNumber(2)
	//pThis->GetEntity()->CanGetValueAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __CanSetValueAs, "CanSetValueAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __CanSetValueAs)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//const wxString& typeName = arg.GetNumber(2)
	//pThis->GetEntity()->CanSetValueAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetValueAsLong, "GetValueAsLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetValueAsLong)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueAsLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetValueAsDouble, "GetValueAsDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetValueAsDouble)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueAsDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetValueAsBool, "GetValueAsBool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetValueAsBool)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetValueAsBool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetValueAsCustom, "GetValueAsCustom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetValueAsCustom)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//const wxString& typeName = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueAsCustom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetValueAsLong, "SetValueAsLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetValueAsLong)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//long value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueAsLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetValueAsDouble, "SetValueAsDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetValueAsDouble)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//double value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueAsDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetValueAsBool, "SetValueAsBool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetValueAsBool)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//bool value = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueAsBool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetValueAsCustom, "SetValueAsCustom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "typeName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetValueAsCustom)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//const wxString& typeName = arg.GetNumber(2)
	//void* value = arg.GetNumber(3)
	//pThis->GetEntity()->SetValueAsCustom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetView, "SetView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetView)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGrid* grid = arg.GetNumber(0)
	//pThis->GetEntity()->SetView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetView, "GetView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __GetView)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __Clear)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __InsertRows, "InsertRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __InsertRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//size_t numRows = arg.GetNumber(1)
	//pThis->GetEntity()->InsertRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __AppendRows, "AppendRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __AppendRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t numRows = arg.GetNumber(0)
	//pThis->GetEntity()->AppendRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __DeleteRows, "DeleteRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __DeleteRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//size_t numRows = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __InsertCols, "InsertCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __InsertCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//size_t numCols = arg.GetNumber(1)
	//pThis->GetEntity()->InsertCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __AppendCols, "AppendCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __AppendCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t numCols = arg.GetNumber(0)
	//pThis->GetEntity()->AppendCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __DeleteCols, "DeleteCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __DeleteCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//size_t numCols = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetRowLabelValue, "GetRowLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetRowLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetColLabelValue, "GetColLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetColLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetColLabelValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetRowLabelValue, "SetRowLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetRowLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowLabelValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetColLabelValue, "SetColLabelValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetColLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//pThis->GetEntity()->SetColLabelValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetAttrProvider, "SetAttrProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrProvider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetAttrProvider)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridCellAttrProvider* attrProvider = arg.GetNumber(0)
	//pThis->GetEntity()->SetAttrProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetAttrProvider, "GetAttrProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __GetAttrProvider)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttrProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __GetAttr, "GetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __GetAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//wxGridCellAttr::wxAttrKind kind = arg.GetNumber(2)
	//pThis->GetEntity()->GetAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetAttr, "SetAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridCellAttr* attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetRowAttr, "SetRowAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetRowAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridCellAttr* attr = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//pThis->GetEntity()->SetRowAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __SetColAttr, "SetColAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, __SetColAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridCellAttr* attr = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetColAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableBase, __CanHaveAttributes, "CanHaveAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, __CanHaveAttributes)
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
	// Constructor assignment
	Gura_AssignFunction(__GridTableBase);
	// Method assignment
	Gura_AssignMethod(wx_GridTableBase, __GetNumberRows);
	Gura_AssignMethod(wx_GridTableBase, __GetNumberCols);
	Gura_AssignMethod(wx_GridTableBase, __GetRowsCount);
	Gura_AssignMethod(wx_GridTableBase, __GetColsCount);
	Gura_AssignMethod(wx_GridTableBase, __IsEmptyCell);
	Gura_AssignMethod(wx_GridTableBase, __IsEmpty);
	Gura_AssignMethod(wx_GridTableBase, __GetValue);
	Gura_AssignMethod(wx_GridTableBase, __SetValue);
	Gura_AssignMethod(wx_GridTableBase, __GetTypeName);
	Gura_AssignMethod(wx_GridTableBase, __CanGetValueAs);
	Gura_AssignMethod(wx_GridTableBase, __CanSetValueAs);
	Gura_AssignMethod(wx_GridTableBase, __GetValueAsLong);
	Gura_AssignMethod(wx_GridTableBase, __GetValueAsDouble);
	Gura_AssignMethod(wx_GridTableBase, __GetValueAsBool);
	Gura_AssignMethod(wx_GridTableBase, __GetValueAsCustom);
	Gura_AssignMethod(wx_GridTableBase, __SetValueAsLong);
	Gura_AssignMethod(wx_GridTableBase, __SetValueAsDouble);
	Gura_AssignMethod(wx_GridTableBase, __SetValueAsBool);
	Gura_AssignMethod(wx_GridTableBase, __SetValueAsCustom);
	Gura_AssignMethod(wx_GridTableBase, __SetView);
	Gura_AssignMethod(wx_GridTableBase, __GetView);
	Gura_AssignMethod(wx_GridTableBase, __Clear);
	Gura_AssignMethod(wx_GridTableBase, __InsertRows);
	Gura_AssignMethod(wx_GridTableBase, __AppendRows);
	Gura_AssignMethod(wx_GridTableBase, __DeleteRows);
	Gura_AssignMethod(wx_GridTableBase, __InsertCols);
	Gura_AssignMethod(wx_GridTableBase, __AppendCols);
	Gura_AssignMethod(wx_GridTableBase, __DeleteCols);
	Gura_AssignMethod(wx_GridTableBase, __GetRowLabelValue);
	Gura_AssignMethod(wx_GridTableBase, __GetColLabelValue);
	Gura_AssignMethod(wx_GridTableBase, __SetRowLabelValue);
	Gura_AssignMethod(wx_GridTableBase, __SetColLabelValue);
	Gura_AssignMethod(wx_GridTableBase, __SetAttrProvider);
	Gura_AssignMethod(wx_GridTableBase, __GetAttrProvider);
	Gura_AssignMethod(wx_GridTableBase, __GetAttr);
	Gura_AssignMethod(wx_GridTableBase, __SetAttr);
	Gura_AssignMethod(wx_GridTableBase, __SetRowAttr);
	Gura_AssignMethod(wx_GridTableBase, __SetColAttr);
	Gura_AssignMethod(wx_GridTableBase, __CanHaveAttributes);
}

Gura_ImplementDescendantCreator(wx_GridTableBase)
{
	return new Object_wx_GridTableBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
