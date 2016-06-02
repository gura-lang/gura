//----------------------------------------------------------------------------
// wxTreeItemData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeItemData
//----------------------------------------------------------------------------
Object_wx_TreeItemData::~Object_wx_TreeItemData()
{
}

Object *Object_wx_TreeItemData::Clone() const
{
	return nullptr;
}

String Object_wx_TreeItemData::ToString(bool exprFlag)
{
	String rtn("<wx.TreeItemData:");
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
Gura_DeclareMethod(wx_TreeItemData, wxTreeItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemData, wxTreeItemData)
{
	Object_wx_TreeItemData *pThis = Object_wx_TreeItemData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTreeItemData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeItemData, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemData, GetId)
{
	Object_wx_TreeItemData *pThis = Object_wx_TreeItemData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeItemData, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeItemData, SetId)
{
	Object_wx_TreeItemData *pThis = Object_wx_TreeItemData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeItemData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemData)
{
	Gura_AssignMethod(wx_TreeItemData, wxTreeItemData);
	Gura_AssignMethod(wx_TreeItemData, GetId);
	Gura_AssignMethod(wx_TreeItemData, SetId);
}

Gura_ImplementDescendantCreator(wx_TreeItemData)
{
	return new Object_wx_TreeItemData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
