//----------------------------------------------------------------------------
// wxTreeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeEvent
//----------------------------------------------------------------------------
Object_wx_TreeEvent::~Object_wx_TreeEvent()
{
}

Object *Object_wx_TreeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TreeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TreeEvent:");
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
Gura_DeclareFunctionAlias(__TreeEvent, "TreeEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tree", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TreeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TreeEvent)
{
	//int commandType = arg.GetNumber(0)
	//int tree = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//wxTreeEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TreeEvent, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, __GetItem)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeEvent, __GetKeyCode, "GetKeyCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, __GetKeyCode)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKeyCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeEvent, __GetKeyEvent, "GetKeyEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, __GetKeyEvent)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKeyEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeEvent, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, __GetLabel)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeEvent, __GetOldItem, "GetOldItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, __GetOldItem)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOldItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeEvent, __GetPoint, "GetPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, __GetPoint)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeEvent, __IsEditCancelled, "IsEditCancelled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, __IsEditCancelled)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditCancelled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TreeEvent, __SetToolTip, "SetToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeEvent, __SetToolTip)
{
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tooltip = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolTip();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__TreeEvent);
	// Method assignment
	Gura_AssignMethod(wx_TreeEvent, __GetItem);
	Gura_AssignMethod(wx_TreeEvent, __GetKeyCode);
	Gura_AssignMethod(wx_TreeEvent, __GetKeyEvent);
	Gura_AssignMethod(wx_TreeEvent, __GetLabel);
	Gura_AssignMethod(wx_TreeEvent, __GetOldItem);
	Gura_AssignMethod(wx_TreeEvent, __GetPoint);
	Gura_AssignMethod(wx_TreeEvent, __IsEditCancelled);
	Gura_AssignMethod(wx_TreeEvent, __SetToolTip);
}

Gura_ImplementDescendantCreator(wx_TreeEvent)
{
	return new Object_wx_TreeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
