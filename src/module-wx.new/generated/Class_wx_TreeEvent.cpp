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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TreeEvent, wxTreeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tree", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeEvent, wxTreeEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int tree = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->wxTreeEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, GetKeyCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetKeyCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, GetKeyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, GetKeyEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetKeyEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, GetOldItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, GetOldItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOldItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, GetPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, GetPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, IsEditCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeEvent, IsEditCancelled)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEditCancelled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TreeEvent, SetToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeEvent, SetToolTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TreeEvent *pThis = Object_wx_TreeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tooltip = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolTip();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeEvent)
{
	Gura_AssignMethod(wx_TreeEvent, wxTreeEvent);
	Gura_AssignMethod(wx_TreeEvent, GetItem);
	Gura_AssignMethod(wx_TreeEvent, GetKeyCode);
	Gura_AssignMethod(wx_TreeEvent, GetKeyEvent);
	Gura_AssignMethod(wx_TreeEvent, GetLabel);
	Gura_AssignMethod(wx_TreeEvent, GetOldItem);
	Gura_AssignMethod(wx_TreeEvent, GetPoint);
	Gura_AssignMethod(wx_TreeEvent, IsEditCancelled);
	Gura_AssignMethod(wx_TreeEvent, SetToolTip);
}

Gura_ImplementDescendantCreator(wx_TreeEvent)
{
	return new Object_wx_TreeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
