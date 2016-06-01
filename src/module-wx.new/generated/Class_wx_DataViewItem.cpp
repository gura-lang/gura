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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataViewItem, wxDataViewItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItem, wxDataViewItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItem *pThis = Object_wx_DataViewItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItem, wxDataViewItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItem, wxDataViewItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItem *pThis = Object_wx_DataViewItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataViewItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItem, wxDataViewItem_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItem, wxDataViewItem_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItem *pThis = Object_wx_DataViewItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataViewItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItem, GetID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItem, GetID)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItem *pThis = Object_wx_DataViewItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewItem, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItem, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewItem *pThis = Object_wx_DataViewItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewItem)
{
	Gura_AssignMethod(wx_DataViewItem, wxDataViewItem);
	Gura_AssignMethod(wx_DataViewItem, wxDataViewItem_1);
	Gura_AssignMethod(wx_DataViewItem, wxDataViewItem_2);
	Gura_AssignMethod(wx_DataViewItem, GetID);
	Gura_AssignMethod(wx_DataViewItem, IsOk);
}

Gura_ImplementDescendantCreator(wx_DataViewItem)
{
	return new Object_wx_DataViewItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
