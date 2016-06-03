//----------------------------------------------------------------------------
// wxDataViewItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewItem
//----------------------------------------------------------------------------
Object_wx_DataViewItem::~Object_wx_DataViewItem()
{
}

Object *Object_wx_DataViewItem::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewItem::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewItem:");
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
Gura_DeclareFunctionAlias(__wxDataViewItem, "wxDataViewItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxDataViewItem)
{
	//wxDataViewItem();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDataViewItem_1, "wxDataViewItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDataViewItem_1)
{
	//int item = arg.GetNumber(0)
	//wxDataViewItem();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDataViewItem_2, "wxDataViewItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDataViewItem_2)
{
	//int id = arg.GetNumber(0)
	//wxDataViewItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewItem, __GetID, "GetID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItem, __GetID)
{
	Object_wx_DataViewItem *pThis = Object_wx_DataViewItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItem, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItem, __IsOk)
{
	Object_wx_DataViewItem *pThis = Object_wx_DataViewItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewItem)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewItem);
	Gura_AssignFunction(__wxDataViewItem_1);
	Gura_AssignFunction(__wxDataViewItem_2);
	// Method assignment
	Gura_AssignMethod(wx_DataViewItem, __GetID);
	Gura_AssignMethod(wx_DataViewItem, __IsOk);
}

Gura_ImplementDescendantCreator(wx_DataViewItem)
{
	return new Object_wx_DataViewItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
