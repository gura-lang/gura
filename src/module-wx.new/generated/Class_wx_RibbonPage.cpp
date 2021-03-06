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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RibbonPage, "RibbonPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonPage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonPage)
{
	//wxRibbonPage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RibbonPage_1, "RibbonPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonPage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonPage_1)
{
	//wxRibbonBar* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxBitmap& icon = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//wxRibbonPage(parent, id, label, icon, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonPage, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxRibbonBar* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxBitmap& icon = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, label, icon, style);
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
	//wxRibbonArtProvider* art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider(art);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __GetIcon, "GetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __GetIcon)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap& _rtn = pThis->GetEntity()->GetIcon();
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
	//pThis->GetEntity()->SetSizeWithScrollButtonAdjustment(x, y, width, height);
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
	//wxRect* rect = arg.GetNumber(0)
	//pThis->GetEntity()->AdjustRectToIncludeScrollButtons(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __DismissExpandedPanel, "DismissExpandedPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __DismissExpandedPanel)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DismissExpandedPanel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __Realize)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __ScrollLines, "ScrollLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __ScrollLines)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lines = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ScrollLines(lines);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __ScrollPixels, "ScrollPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __ScrollPixels)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ScrollPixels(pixels);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __ScrollSections, "ScrollSections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPage, __ScrollSections)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sections = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ScrollSections(sections);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPage, __GetMajorAxis, "GetMajorAxis")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPage, __GetMajorAxis)
{
	Object_wx_RibbonPage *pThis = Object_wx_RibbonPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation _rtn = pThis->GetEntity()->GetMajorAxis();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPage)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonPage);
	Gura_AssignFunction(__RibbonPage_1);
	// Method assignment
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
