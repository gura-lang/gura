//----------------------------------------------------------------------------
// wxTreeItemId
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemId
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeItemId
//----------------------------------------------------------------------------
Object_wx_TreeItemId::~Object_wx_TreeItemId()
{
}

Object *Object_wx_TreeItemId::Clone() const
{
	return nullptr;
}

String Object_wx_TreeItemId::ToString(bool exprFlag)
{
	String rtn("<wx.TreeItemId:");
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
Gura_DeclareFunctionAlias(__wxTreeItemId, "wxTreeItemId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeItemId));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxTreeItemId)
{
	//wxTreeItemId();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TreeItemId, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemId, __IsOk)
{
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeItemId, __GetID, "GetID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemId, __GetID)
{
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeItemId, __Unset, "Unset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemId, __Unset)
{
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unset();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeItemId
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemId)
{
	// Constructor assignment
	Gura_AssignFunction(__wxTreeItemId);
	// Method assignment
	Gura_AssignMethod(wx_TreeItemId, __IsOk);
	Gura_AssignMethod(wx_TreeItemId, __GetID);
	Gura_AssignMethod(wx_TreeItemId, __Unset);
}

Gura_ImplementDescendantCreator(wx_TreeItemId)
{
	return new Object_wx_TreeItemId((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
