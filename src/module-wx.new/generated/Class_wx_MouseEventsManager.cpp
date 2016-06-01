//----------------------------------------------------------------------------
// wxMouseEventsManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseEventsManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseEventsManager
//----------------------------------------------------------------------------
Object_wx_MouseEventsManager::~Object_wx_MouseEventsManager()
{
}

Object *Object_wx_MouseEventsManager::Clone() const
{
	return nullptr;
}

String Object_wx_MouseEventsManager::ToString(bool exprFlag)
{
	String rtn("<wx.MouseEventsManager:");
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
Gura_DeclareMethod(wx_MouseEventsManager, wxMouseEventsManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEventsManager, wxMouseEventsManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxMouseEventsManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, wxMouseEventsManager_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, wxMouseEventsManager_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxMouseEventsManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseHitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseHitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->MouseHitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseClicked)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseClicked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseDragBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseDragBegin)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->MouseDragBegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseDragging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseDragging)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->MouseDragging();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseDragEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseDragEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->MouseDragEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseDragCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseDragCancelled)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseDragCancelled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseClickBegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseClickBegin)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseClickBegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEventsManager, MouseClickCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, MouseClickCancelled)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseClickCancelled();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseEventsManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEventsManager)
{
	Gura_AssignMethod(wx_MouseEventsManager, wxMouseEventsManager);
	Gura_AssignMethod(wx_MouseEventsManager, wxMouseEventsManager_1);
	Gura_AssignMethod(wx_MouseEventsManager, Create);
	Gura_AssignMethod(wx_MouseEventsManager, MouseHitTest);
	Gura_AssignMethod(wx_MouseEventsManager, MouseClicked);
	Gura_AssignMethod(wx_MouseEventsManager, MouseDragBegin);
	Gura_AssignMethod(wx_MouseEventsManager, MouseDragging);
	Gura_AssignMethod(wx_MouseEventsManager, MouseDragEnd);
	Gura_AssignMethod(wx_MouseEventsManager, MouseDragCancelled);
	Gura_AssignMethod(wx_MouseEventsManager, MouseClickBegin);
	Gura_AssignMethod(wx_MouseEventsManager, MouseClickCancelled);
}

Gura_ImplementDescendantCreator(wx_MouseEventsManager)
{
	return new Object_wx_MouseEventsManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
