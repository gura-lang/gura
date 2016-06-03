//----------------------------------------------------------------------------
// wxDataViewIndexListModel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewIndexListModel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewIndexListModel
//----------------------------------------------------------------------------
Object_wx_DataViewIndexListModel::~Object_wx_DataViewIndexListModel()
{
}

Object *Object_wx_DataViewIndexListModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewIndexListModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewIndexListModel:");
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
Gura_DeclareFunctionAlias(__wxDataViewIndexListModel, "wxDataViewIndexListModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "initial_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDataViewIndexListModel)
{
	//int initial_size = arg.GetNumber(0)
	//wxDataViewIndexListModel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __GetItem)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __Reset)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_size = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __RowAppended, "RowAppended")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __RowAppended)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowAppended();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __RowChanged, "RowChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __RowChanged)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __RowDeleted, "RowDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __RowDeleted)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowDeleted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __RowInserted, "RowInserted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __RowInserted)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//pThis->GetEntity()->RowInserted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __RowPrepended, "RowPrepended")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __RowPrepended)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowPrepended();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __RowValueChanged, "RowValueChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __RowValueChanged)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->RowValueChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewIndexListModel, __RowsDeleted, "RowsDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, __RowsDeleted)
{
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//pThis->GetEntity()->RowsDeleted();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewIndexListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIndexListModel)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewIndexListModel);
	// Method assignment
	Gura_AssignMethod(wx_DataViewIndexListModel, __GetItem);
	Gura_AssignMethod(wx_DataViewIndexListModel, __Reset);
	Gura_AssignMethod(wx_DataViewIndexListModel, __RowAppended);
	Gura_AssignMethod(wx_DataViewIndexListModel, __RowChanged);
	Gura_AssignMethod(wx_DataViewIndexListModel, __RowDeleted);
	Gura_AssignMethod(wx_DataViewIndexListModel, __RowInserted);
	Gura_AssignMethod(wx_DataViewIndexListModel, __RowPrepended);
	Gura_AssignMethod(wx_DataViewIndexListModel, __RowValueChanged);
	Gura_AssignMethod(wx_DataViewIndexListModel, __RowsDeleted);
}

Gura_ImplementDescendantCreator(wx_DataViewIndexListModel)
{
	return new Object_wx_DataViewIndexListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
