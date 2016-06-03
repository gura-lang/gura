//----------------------------------------------------------------------------
// wxDataViewListModel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListModel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListModel
//----------------------------------------------------------------------------
Object_wx_DataViewListModel::~Object_wx_DataViewListModel()
{
}

Object *Object_wx_DataViewListModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewListModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewListModel:");
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
Gura_DeclareMethodAlias(wx_DataViewListModel, __Compare, "Compare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ascending", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, __Compare)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item1 = arg.GetNumber(0)
	//int item2 = arg.GetNumber(1)
	//int column = arg.GetNumber(2)
	//int ascending = arg.GetNumber(3)
	//pThis->GetEntity()->Compare();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListModel, __GetAttrByRow, "GetAttrByRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, __GetAttrByRow)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//pThis->GetEntity()->GetAttrByRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListModel, __IsEnabledByRow, "IsEnabledByRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, __IsEnabledByRow)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->IsEnabledByRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListModel, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewListModel, __GetCount)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListModel, __GetRow, "GetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, __GetRow)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListModel, __GetValueByRow, "GetValueByRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, __GetValueByRow)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetValueByRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewListModel, __SetValueByRow, "SetValueByRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, __SetValueByRow)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->SetValueByRow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListModel)
{
	// Class assignment
	Gura_AssignValueEx("DataViewListModel", Reference());
	// Method assignment
	Gura_AssignMethod(wx_DataViewListModel, __Compare);
	Gura_AssignMethod(wx_DataViewListModel, __GetAttrByRow);
	Gura_AssignMethod(wx_DataViewListModel, __IsEnabledByRow);
	Gura_AssignMethod(wx_DataViewListModel, __GetCount);
	Gura_AssignMethod(wx_DataViewListModel, __GetRow);
	Gura_AssignMethod(wx_DataViewListModel, __GetValueByRow);
	Gura_AssignMethod(wx_DataViewListModel, __SetValueByRow);
}

Gura_ImplementDescendantCreator(wx_DataViewListModel)
{
	return new Object_wx_DataViewListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
