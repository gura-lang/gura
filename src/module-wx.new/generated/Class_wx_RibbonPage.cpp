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
Gura_DeclareMethodAlias(wx_RibbonPage, __wxRibbonPage, "wxRibbonPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __wxRibbonPage)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __wxRibbonPage_1, "wxRibbonPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __wxRibbonPage_1)
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

Gura_DeclareMethodAlias(wx_RibbonPage, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __Create)
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

Gura_DeclareMethodAlias(wx_RibbonPage, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __SetArtProvider)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __GetIcon, "GetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __GetIcon)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __SetSizeWithScrollButtonAdjustment, "SetSizeWithScrollButtonAdjustment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __SetSizeWithScrollButtonAdjustment)
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

Gura_DeclareMethodAlias(wx_RibbonPage, __AdjustRectToIncludeScrollButtons, "AdjustRectToIncludeScrollButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __AdjustRectToIncludeScrollButtons)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->AdjustRectToIncludeScrollButtons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __DismissExpandedPanel, "DismissExpandedPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __DismissExpandedPanel)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DismissExpandedPanel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __Realize)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __ScrollLines, "ScrollLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __ScrollLines)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lines = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __ScrollPixels, "ScrollPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __ScrollPixels)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollPixels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __ScrollSections, "ScrollSections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __ScrollSections)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sections = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollSections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __GetMajorAxis, "GetMajorAxis")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __GetMajorAxis)
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
	Gura_AssignMethod(wx_RibbonPage, __wxRibbonPage);
	Gura_AssignMethod(wx_RibbonPage, __wxRibbonPage_1);
	Gura_AssignMethod(wx_RibbonPage, __Create);
	Gura_AssignMethod(wx_RibbonPage, __SetArtProvider);
	Gura_AssignMethod(wx_RibbonPage, __GetIcon);
	Gura_AssignMethod(wx_RibbonPage, __SetSizeWithScrollButtonAdjustment);
	Gura_AssignMethod(wx_RibbonPage, __AdjustRectToIncludeScrollButtons);
	Gura_AssignMethod(wx_RibbonPage, __DismissExpandedPanel);
	Gura_AssignMethod(wx_RibbonPage, __Realize);
	Gura_AssignMethod(wx_RibbonPage, __ScrollLines);
	Gura_AssignMethod(wx_RibbonPage, __ScrollPixels);
	Gura_AssignMethod(wx_RibbonPage, __ScrollSections);
	Gura_AssignMethod(wx_RibbonPage, __GetMajorAxis);
}

Gura_ImplementDescendantCreator(wx_RibbonPage)
{
	return new Object_wx_RibbonPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
