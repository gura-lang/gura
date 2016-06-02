//----------------------------------------------------------------------------
// wxRibbonPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonPage
//----------------------------------------------------------------------------
Object_wx_RibbonPage::~Object_wx_RibbonPage()
{
}

Object *Object_wx_RibbonPage::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonPage::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonPage:");
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
Gura_DeclareMethod(wx_RibbonPage, wxRibbonPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, wxRibbonPage)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, wxRibbonPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, wxRibbonPage_1)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxRibbonPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, Create)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, SetArtProvider)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, GetIcon)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, SetSizeWithScrollButtonAdjustment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, SetSizeWithScrollButtonAdjustment)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->SetSizeWithScrollButtonAdjustment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, AdjustRectToIncludeScrollButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, AdjustRectToIncludeScrollButtons)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->AdjustRectToIncludeScrollButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, DismissExpandedPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, DismissExpandedPanel)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DismissExpandedPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, Realize)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, ScrollLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, ScrollLines)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lines = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, ScrollPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, ScrollPixels)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, ScrollSections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, ScrollSections)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sections = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollSections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPage, GetMajorAxis)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, GetMajorAxis)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMajorAxis();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPage)
{
	Gura_AssignMethod(wx_RibbonPage, wxRibbonPage);
	Gura_AssignMethod(wx_RibbonPage, wxRibbonPage_1);
	Gura_AssignMethod(wx_RibbonPage, Create);
	Gura_AssignMethod(wx_RibbonPage, SetArtProvider);
	Gura_AssignMethod(wx_RibbonPage, GetIcon);
	Gura_AssignMethod(wx_RibbonPage, SetSizeWithScrollButtonAdjustment);
	Gura_AssignMethod(wx_RibbonPage, AdjustRectToIncludeScrollButtons);
	Gura_AssignMethod(wx_RibbonPage, DismissExpandedPanel);
	Gura_AssignMethod(wx_RibbonPage, Realize);
	Gura_AssignMethod(wx_RibbonPage, ScrollLines);
	Gura_AssignMethod(wx_RibbonPage, ScrollPixels);
	Gura_AssignMethod(wx_RibbonPage, ScrollSections);
	Gura_AssignMethod(wx_RibbonPage, GetMajorAxis);
}

Gura_ImplementDescendantCreator(wx_RibbonPage)
{
	return new Object_wx_RibbonPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
