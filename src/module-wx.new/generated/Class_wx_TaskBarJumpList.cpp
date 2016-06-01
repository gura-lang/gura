//----------------------------------------------------------------------------
// wxTaskBarJumpList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarJumpList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarJumpList
//----------------------------------------------------------------------------
Object_wx_TaskBarJumpList::~Object_wx_TaskBarJumpList()
{
}

Object *Object_wx_TaskBarJumpList::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarJumpList::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarJumpList:");
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
Gura_DeclareMethod(wx_TaskBarJumpList, wxTaskBarJumpList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "appID", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpList, wxTaskBarJumpList)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int appID = arg.GetNumber(0)
	//pThis->GetEntity()->wxTaskBarJumpList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, ~wxTaskBarJumpList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpList, ~wxTaskBarJumpList)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxTaskBarJumpList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, ShowRecentCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpList, ShowRecentCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int shown = arg.GetNumber(0)
	//pThis->GetEntity()->ShowRecentCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, HideRecentCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpList, HideRecentCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HideRecentCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, ShowFrequentCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpList, ShowFrequentCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int shown = arg.GetNumber(0)
	//pThis->GetEntity()->ShowFrequentCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, HideFrequentCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpList, HideFrequentCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HideFrequentCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, GetTasks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpList, GetTasks)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTasks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, GetFrequentCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpList, GetFrequentCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFrequentCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, GetRecentCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpList, GetRecentCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRecentCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, GetCustomCategories)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpList, GetCustomCategories)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCustomCategories();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, AddCustomCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "category", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpList, AddCustomCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int category = arg.GetNumber(0)
	//pThis->GetEntity()->AddCustomCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, RemoveCustomCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpList, RemoveCustomCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveCustomCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpList, DeleteCustomCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpList, DeleteCustomCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpList *pThis = Object_wx_TaskBarJumpList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteCustomCategory();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarJumpList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarJumpList)
{
	Gura_AssignMethod(wx_TaskBarJumpList, wxTaskBarJumpList);
	Gura_AssignMethod(wx_TaskBarJumpList, ~wxTaskBarJumpList);
	Gura_AssignMethod(wx_TaskBarJumpList, ShowRecentCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, HideRecentCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, ShowFrequentCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, HideFrequentCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, GetTasks);
	Gura_AssignMethod(wx_TaskBarJumpList, GetFrequentCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, GetRecentCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, GetCustomCategories);
	Gura_AssignMethod(wx_TaskBarJumpList, AddCustomCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, RemoveCustomCategory);
	Gura_AssignMethod(wx_TaskBarJumpList, DeleteCustomCategory);
}

Gura_ImplementDescendantCreator(wx_TaskBarJumpList)
{
	return new Object_wx_TaskBarJumpList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
