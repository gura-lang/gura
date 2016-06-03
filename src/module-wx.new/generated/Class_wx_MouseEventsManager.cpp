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
Gura_DeclareMethodAlias(wx_MouseEventsManager, __wxMouseEventsManager, "wxMouseEventsManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEventsManager, __wxMouseEventsManager)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMouseEventsManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __wxMouseEventsManager_1, "wxMouseEventsManager_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __wxMouseEventsManager_1)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxMouseEventsManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __Create)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseHitTest, "MouseHitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseHitTest)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->MouseHitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseClicked, "MouseClicked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseClicked)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseClicked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseDragBegin, "MouseDragBegin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseDragBegin)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->MouseDragBegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseDragging, "MouseDragging")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseDragging)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->MouseDragging();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseDragEnd, "MouseDragEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseDragEnd)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->MouseDragEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseDragCancelled, "MouseDragCancelled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseDragCancelled)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseDragCancelled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseClickBegin, "MouseClickBegin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseClickBegin)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseClickBegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEventsManager, __MouseClickCancelled, "MouseClickCancelled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEventsManager, __MouseClickCancelled)
{
	Object_wx_MouseEventsManager *pThis = Object_wx_MouseEventsManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->MouseClickCancelled();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseEventsManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEventsManager)
{
	Gura_AssignMethod(wx_MouseEventsManager, __wxMouseEventsManager);
	Gura_AssignMethod(wx_MouseEventsManager, __wxMouseEventsManager_1);
	Gura_AssignMethod(wx_MouseEventsManager, __Create);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseHitTest);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseClicked);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseDragBegin);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseDragging);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseDragEnd);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseDragCancelled);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseClickBegin);
	Gura_AssignMethod(wx_MouseEventsManager, __MouseClickCancelled);
}

Gura_ImplementDescendantCreator(wx_MouseEventsManager)
{
	return new Object_wx_MouseEventsManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
