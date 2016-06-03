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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PropertyGridPage, "PropertyGridPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PropertyGridPage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PropertyGridPage)
{
	//wxPropertyGridPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PropertyGridPage, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __Clear)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __FitColumns, "FitColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __FitColumns)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FitColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __GetIndex, "GetIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __GetIndex)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __GetRoot, "GetRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __GetRoot)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __GetSplitterPosition, "GetSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridPage, __GetSplitterPosition)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __GetToolId, "GetToolId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __GetToolId)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __Init)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __IsHandlingAllEvents, "IsHandlingAllEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __IsHandlingAllEvents)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsHandlingAllEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __OnShow, "OnShow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridPage, __OnShow)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnShow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __RefreshProperty, "RefreshProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridPage, __RefreshProperty)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* p = arg.GetNumber(0)
	//pThis->GetEntity()->RefreshProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridPage, __SetSplitterPosition, "SetSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "splitterPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridPage, __SetSplitterPosition)
{
	Object_wx_PropertyGridPage *pThis = Object_wx_PropertyGridPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	// Constructor assignment
	Gura_AssignFunction(__PropertyGridPage);
	// Method assignment
	Gura_AssignMethod(wx_PropertyGridPage, __Clear);
	Gura_AssignMethod(wx_PropertyGridPage, __FitColumns);
	Gura_AssignMethod(wx_PropertyGridPage, __GetIndex);
	Gura_AssignMethod(wx_PropertyGridPage, __GetRoot);
	Gura_AssignMethod(wx_PropertyGridPage, __GetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridPage, __GetToolId);
	Gura_AssignMethod(wx_PropertyGridPage, __Init);
	Gura_AssignMethod(wx_PropertyGridPage, __IsHandlingAllEvents);
	Gura_AssignMethod(wx_PropertyGridPage, __OnShow);
	Gura_AssignMethod(wx_PropertyGridPage, __RefreshProperty);
	Gura_AssignMethod(wx_PropertyGridPage, __SetSplitterPosition);
}

Gura_ImplementDescendantCreator(wx_PropertyGridPage)
{
	return new Object_wx_PropertyGridPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
