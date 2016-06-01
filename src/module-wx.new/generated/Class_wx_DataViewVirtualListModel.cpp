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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewVirtualListModel, wxDataViewVirtualListModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "initial_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, wxDataViewVirtualListModel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int initial_size = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataViewVirtualListModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int new_size = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, RowAppended)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, RowAppended)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RowAppended();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, RowChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, RowChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, RowDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, RowDeleted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowDeleted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, RowInserted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, RowInserted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//pThis->GetEntity()->RowInserted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, RowPrepended)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, RowPrepended)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RowPrepended();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, RowValueChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, RowValueChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->RowValueChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewVirtualListModel, RowsDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewVirtualListModel, RowsDeleted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewVirtualListModel *pThis = Object_wx_DataViewVirtualListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//pThis->GetEntity()->RowsDeleted();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewVirtualListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewVirtualListModel)
{
	Gura_AssignMethod(wx_DataViewVirtualListModel, wxDataViewVirtualListModel);
	Gura_AssignMethod(wx_DataViewVirtualListModel, GetItem);
	Gura_AssignMethod(wx_DataViewVirtualListModel, Reset);
	Gura_AssignMethod(wx_DataViewVirtualListModel, RowAppended);
	Gura_AssignMethod(wx_DataViewVirtualListModel, RowChanged);
	Gura_AssignMethod(wx_DataViewVirtualListModel, RowDeleted);
	Gura_AssignMethod(wx_DataViewVirtualListModel, RowInserted);
	Gura_AssignMethod(wx_DataViewVirtualListModel, RowPrepended);
	Gura_AssignMethod(wx_DataViewVirtualListModel, RowValueChanged);
	Gura_AssignMethod(wx_DataViewVirtualListModel, RowsDeleted);
}

Gura_ImplementDescendantCreator(wx_DataViewVirtualListModel)
{
	return new Object_wx_DataViewVirtualListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
