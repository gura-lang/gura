//----------------------------------------------------------------------------
// wxDropTarget
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDropTarget
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDropTarget
//----------------------------------------------------------------------------
Object_wx_DropTarget::~Object_wx_DropTarget()
{
}

Object *Object_wx_DropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_DropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.DropTarget:");
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
Gura_DeclareMethod(wx_DropTarget, wxDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, wxDropTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxDropTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, ~wxDropTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, ~wxDropTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDropTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, OnData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defResult", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, OnData)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int defResult = arg.GetNumber(2)
	//pThis->GetEntity()->OnData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, OnDragOver)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defResult", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, OnDragOver)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int defResult = arg.GetNumber(2)
	//pThis->GetEntity()->OnDragOver();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, OnDrop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, OnDrop)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->OnDrop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, OnEnter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defResult", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, OnEnter)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int defResult = arg.GetNumber(2)
	//pThis->GetEntity()->OnEnter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, OnLeave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, OnLeave)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnLeave();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, GetDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, GetDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, SetDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, SetDataObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, SetDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, SetDefaultAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropTarget, GetDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, GetDefaultAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultAction();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropTarget)
{
	Gura_AssignMethod(wx_DropTarget, wxDropTarget);
	Gura_AssignMethod(wx_DropTarget, ~wxDropTarget);
	Gura_AssignMethod(wx_DropTarget, GetData);
	Gura_AssignMethod(wx_DropTarget, OnData);
	Gura_AssignMethod(wx_DropTarget, OnDragOver);
	Gura_AssignMethod(wx_DropTarget, OnDrop);
	Gura_AssignMethod(wx_DropTarget, OnEnter);
	Gura_AssignMethod(wx_DropTarget, OnLeave);
	Gura_AssignMethod(wx_DropTarget, GetDataObject);
	Gura_AssignMethod(wx_DropTarget, SetDataObject);
	Gura_AssignMethod(wx_DropTarget, SetDefaultAction);
	Gura_AssignMethod(wx_DropTarget, GetDefaultAction);
}

Gura_ImplementDescendantCreator(wx_DropTarget)
{
	return new Object_wx_DropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
