//----------------------------------------------------------------------------
// wxTreeListEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListEvent
//----------------------------------------------------------------------------
Object_wx_TreeListEvent::~Object_wx_TreeListEvent()
{
}

Object *Object_wx_TreeListEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListEvent:");
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
Gura_DeclareFunctionAlias(__TreeListEvent, "TreeListEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeListEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TreeListEvent)
{
	//wxTreeListEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TreeListEvent, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListEvent, __GetItem)
{
	Object_wx_TreeListEvent *pThis = Object_wx_TreeListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListEvent, __GetOldCheckedState, "GetOldCheckedState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListEvent, __GetOldCheckedState)
{
	Object_wx_TreeListEvent *pThis = Object_wx_TreeListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOldCheckedState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeListEvent, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeListEvent, __GetColumn)
{
	Object_wx_TreeListEvent *pThis = Object_wx_TreeListEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeListEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__TreeListEvent);
	// Method assignment
	Gura_AssignMethod(wx_TreeListEvent, __GetItem);
	Gura_AssignMethod(wx_TreeListEvent, __GetOldCheckedState);
	Gura_AssignMethod(wx_TreeListEvent, __GetColumn);
}

Gura_ImplementDescendantCreator(wx_TreeListEvent)
{
	return new Object_wx_TreeListEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
