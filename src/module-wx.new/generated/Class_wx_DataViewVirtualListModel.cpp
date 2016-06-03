//----------------------------------------------------------------------------
// wxDataViewVirtualListModel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewVirtualListModel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewVirtualListModel
//----------------------------------------------------------------------------
Object_wx_DataViewVirtualListModel::~Object_wx_DataViewVirtualListModel()
{
}

Object *Object_wx_DataViewVirtualListModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewVirtualListModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewVirtualListModel:");
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
Gura_DeclareFunctionAlias(__DataViewVirtualListModel, "DataViewVirtualListModel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "initial_size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataViewVirtualListModel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewVirtualListModel)
{
	//unsigned int initial_size = arg.GetNumber(0)
	//wxDataViewVirtualListModel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __GetItem)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __Reset)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int new_size = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __RowAppended, "RowAppended")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __RowAppended)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowAppended();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __RowChanged, "RowChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __RowChanged)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __RowDeleted, "RowDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __RowDeleted)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowDeleted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __RowInserted, "RowInserted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __RowInserted)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int before = arg.GetNumber(0)
	//pThis->GetEntity()->RowInserted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __RowPrepended, "RowPrepended")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __RowPrepended)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RowPrepended();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __RowValueChanged, "RowValueChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __RowValueChanged)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int row = arg.GetNumber(0)
	//unsigned int col = arg.GetNumber(1)
	//pThis->GetEntity()->RowValueChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewVirtualListModel, __RowsDeleted, "RowsDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, __RowsDeleted)
{
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayInt& rows = arg.GetNumber(0)
	//pThis->GetEntity()->RowsDeleted();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewVirtualListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewVirtualListModel)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewVirtualListModel);
	// Method assignment
	Gura_AssignMethod(wx_DataViewVirtualListModel, __GetItem);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __Reset);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __RowAppended);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __RowChanged);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __RowDeleted);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __RowInserted);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __RowPrepended);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __RowValueChanged);
	Gura_AssignMethod(wx_DataViewVirtualListModel, __RowsDeleted);
}

Gura_ImplementDescendantCreator(wx_DataViewVirtualListModel)
{
	return new Object_wx_DataViewVirtualListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
