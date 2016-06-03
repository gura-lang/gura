//----------------------------------------------------------------------------
// wxTreeListItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListItem
//----------------------------------------------------------------------------
Object_wx_TreeListItem::~Object_wx_TreeListItem()
{
}

Object *Object_wx_TreeListItem::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListItem::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListItem:");
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
Gura_DeclareFunctionAlias(__TreeListItem, "TreeListItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeListItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TreeListItem)
{
	//wxTreeListItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TreeListItem, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListItem, __IsOk)
{
	Object_wx_TreeListItem *pThis = Object_wx_TreeListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeListItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListItem)
{
	// Constructor assignment
	Gura_AssignFunction(__TreeListItem);
	// Method assignment
	Gura_AssignMethod(wx_TreeListItem, __IsOk);
}

Gura_ImplementDescendantCreator(wx_TreeListItem)
{
	return new Object_wx_TreeListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
