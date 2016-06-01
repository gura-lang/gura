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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewIndexListModel, wxDataViewIndexListModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "initial_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, wxDataViewIndexListModel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int initial_size = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataViewIndexListModel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int new_size = arg.GetNumber(0)
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, RowAppended)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, RowAppended)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RowAppended();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, RowChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, RowChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, RowDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, RowDeleted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->RowDeleted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, RowInserted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, RowInserted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//pThis->GetEntity()->RowInserted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, RowPrepended)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, RowPrepended)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RowPrepended();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, RowValueChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, RowValueChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->RowValueChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewIndexListModel, RowsDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewIndexListModel, RowsDeleted)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewIndexListModel *pThis = Object_wx_DataViewIndexListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//pThis->GetEntity()->RowsDeleted();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewIndexListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIndexListModel)
{
	Gura_AssignMethod(wx_DataViewIndexListModel, wxDataViewIndexListModel);
	Gura_AssignMethod(wx_DataViewIndexListModel, GetItem);
	Gura_AssignMethod(wx_DataViewIndexListModel, Reset);
	Gura_AssignMethod(wx_DataViewIndexListModel, RowAppended);
	Gura_AssignMethod(wx_DataViewIndexListModel, RowChanged);
	Gura_AssignMethod(wx_DataViewIndexListModel, RowDeleted);
	Gura_AssignMethod(wx_DataViewIndexListModel, RowInserted);
	Gura_AssignMethod(wx_DataViewIndexListModel, RowPrepended);
	Gura_AssignMethod(wx_DataViewIndexListModel, RowValueChanged);
	Gura_AssignMethod(wx_DataViewIndexListModel, RowsDeleted);
}

Gura_ImplementDescendantCreator(wx_DataViewIndexListModel)
{
	return new Object_wx_DataViewIndexListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
