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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TreeItemId, wxTreeItemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemId, wxTreeItemId)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTreeItemId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeItemId, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemId, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeItemId, GetID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemId, GetID)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeItemId, Unset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeItemId, Unset)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeItemId *pThis = Object_wx_TreeItemId::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Unset();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeItemId
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemId)
{
	Gura_AssignMethod(wx_TreeItemId, wxTreeItemId);
	Gura_AssignMethod(wx_TreeItemId, IsOk);
	Gura_AssignMethod(wx_TreeItemId, GetID);
	Gura_AssignMethod(wx_TreeItemId, Unset);
}

Gura_ImplementDescendantCreator(wx_TreeItemId)
{
	return new Object_wx_TreeItemId((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
