//----------------------------------------------------------------------------
// wxPropertyGridPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridPage
//----------------------------------------------------------------------------
Object_wx_PropertyGridPage::~Object_wx_PropertyGridPage()
{
}

Object *Object_wx_PropertyGridPage::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridPage::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridPage:");
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
Gura_DeclareMethod(wx_PropertyGridPage, wxPropertyGridPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, wxPropertyGridPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPropertyGridPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, ~wxPropertyGridPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, ~wxPropertyGridPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPropertyGridPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, FitColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, FitColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FitColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, GetIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, GetIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, GetRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, GetRoot)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, GetSplitterPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridPage, GetSplitterPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, GetToolId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, GetToolId)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, IsHandlingAllEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, IsHandlingAllEvents)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsHandlingAllEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, OnShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, OnShow)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnShow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, RefreshProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridPage, RefreshProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridPage, SetSplitterPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "splitterPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridPage, SetSplitterPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int splitterPos = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridPage)
{
	Gura_AssignMethod(wx_PropertyGridPage, wxPropertyGridPage);
	Gura_AssignMethod(wx_PropertyGridPage, ~wxPropertyGridPage);
	Gura_AssignMethod(wx_PropertyGridPage, Clear);
	Gura_AssignMethod(wx_PropertyGridPage, FitColumns);
	Gura_AssignMethod(wx_PropertyGridPage, GetIndex);
	Gura_AssignMethod(wx_PropertyGridPage, GetRoot);
	Gura_AssignMethod(wx_PropertyGridPage, GetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridPage, GetToolId);
	Gura_AssignMethod(wx_PropertyGridPage, Init);
	Gura_AssignMethod(wx_PropertyGridPage, IsHandlingAllEvents);
	Gura_AssignMethod(wx_PropertyGridPage, OnShow);
	Gura_AssignMethod(wx_PropertyGridPage, RefreshProperty);
	Gura_AssignMethod(wx_PropertyGridPage, SetSplitterPosition);
}

Gura_ImplementDescendantCreator(wx_PropertyGridPage)
{
	return new Object_wx_PropertyGridPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
