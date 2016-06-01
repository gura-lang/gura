//----------------------------------------------------------------------------
// wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
Object_wx_TaskBarJumpListCategory::~Object_wx_TaskBarJumpListCategory()
{
}

Object *Object_wx_TaskBarJumpListCategory::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarJumpListCategory::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarJumpListCategory:");
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
Gura_DeclareMethod(wx_TaskBarJumpListCategory, wxTaskBarJumpListCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, wxTaskBarJumpListCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//pThis->GetEntity()->wxTaskBarJumpListCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, ~wxTaskBarJumpListCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, ~wxTaskBarJumpListCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxTaskBarJumpListCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, FindItemByPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, FindItemByPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemByPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, Prepend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, Prepend)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarJumpListCategory, GetItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarJumpListCategory, GetItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarJumpListCategory *pThis = Object_wx_TaskBarJumpListCategory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItems();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarJumpListCategory)
{
	Gura_AssignMethod(wx_TaskBarJumpListCategory, wxTaskBarJumpListCategory);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, ~wxTaskBarJumpListCategory);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, Append);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, Delete);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, Remove);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, FindItemByPosition);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, Insert);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, Prepend);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, SetTitle);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, GetTitle);
	Gura_AssignMethod(wx_TaskBarJumpListCategory, GetItems);
}

Gura_ImplementDescendantCreator(wx_TaskBarJumpListCategory)
{
	return new Object_wx_TaskBarJumpListCategory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
