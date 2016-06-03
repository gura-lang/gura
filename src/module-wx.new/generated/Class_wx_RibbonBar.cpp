//----------------------------------------------------------------------------
// wxRibbonBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonBar
//----------------------------------------------------------------------------
Object_wx_RibbonBar::~Object_wx_RibbonBar()
{
}

Object *Object_wx_RibbonBar::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonBar::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonBar:");
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
Gura_DeclareFunctionAlias(__RibbonBar, "RibbonBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonBar)
{
	//wxRibbonBar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RibbonBar_1, "RibbonBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonBar_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//wxRibbonBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonBar, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __Create)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __SetTabCtrlMargins, "SetTabCtrlMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __SetTabCtrlMargins)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int right = arg.GetNumber(1)
	//pThis->GetEntity()->SetTabCtrlMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __SetArtProvider)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __SetActivePage, "SetActivePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __SetActivePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __SetActivePage_1, "SetActivePage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __SetActivePage_1)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetActivePage, "GetActivePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __GetActivePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActivePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __GetPage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetPageCount, "GetPageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __GetPageCount)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __DismissExpandedPanel, "DismissExpandedPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __DismissExpandedPanel)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DismissExpandedPanel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetPageNumber, "GetPageNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __GetPageNumber)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageNumber();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __DeletePage, "DeletePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __DeletePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->DeletePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __ClearPages, "ClearPages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __ClearPages)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearPages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __IsPageShown, "IsPageShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __IsPageShown)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->IsPageShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __ShowPage, "ShowPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show_tab", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __ShowPage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int show_tab = arg.GetNumber(1)
	//pThis->GetEntity()->ShowPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __HidePage, "HidePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __HidePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->HidePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __IsPageHighlighted, "IsPageHighlighted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __IsPageHighlighted)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->IsPageHighlighted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __AddPageHighlight, "AddPageHighlight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "highlight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __AddPageHighlight)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int highlight = arg.GetNumber(1)
	//pThis->GetEntity()->AddPageHighlight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __RemovePageHighlight, "RemovePageHighlight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __RemovePageHighlight)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePageHighlight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __ShowPanels, "ShowPanels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __ShowPanels)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPanels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __ShowPanels_1, "ShowPanels_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __ShowPanels_1)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPanels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __HidePanels, "HidePanels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __HidePanels)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HidePanels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __ArePanelsShown, "ArePanelsShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __ArePanelsShown)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ArePanelsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetDisplayMode, "GetDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __GetDisplayMode)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __Realize)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonBar)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonBar);
	Gura_AssignFunction(__RibbonBar_1);
	// Method assignment
	Gura_AssignMethod(wx_RibbonBar, __Create);
	Gura_AssignMethod(wx_RibbonBar, __SetTabCtrlMargins);
	Gura_AssignMethod(wx_RibbonBar, __SetArtProvider);
	Gura_AssignMethod(wx_RibbonBar, __SetActivePage);
	Gura_AssignMethod(wx_RibbonBar, __SetActivePage_1);
	Gura_AssignMethod(wx_RibbonBar, __GetActivePage);
	Gura_AssignMethod(wx_RibbonBar, __GetPage);
	Gura_AssignMethod(wx_RibbonBar, __GetPageCount);
	Gura_AssignMethod(wx_RibbonBar, __DismissExpandedPanel);
	Gura_AssignMethod(wx_RibbonBar, __GetPageNumber);
	Gura_AssignMethod(wx_RibbonBar, __DeletePage);
	Gura_AssignMethod(wx_RibbonBar, __ClearPages);
	Gura_AssignMethod(wx_RibbonBar, __IsPageShown);
	Gura_AssignMethod(wx_RibbonBar, __ShowPage);
	Gura_AssignMethod(wx_RibbonBar, __HidePage);
	Gura_AssignMethod(wx_RibbonBar, __IsPageHighlighted);
	Gura_AssignMethod(wx_RibbonBar, __AddPageHighlight);
	Gura_AssignMethod(wx_RibbonBar, __RemovePageHighlight);
	Gura_AssignMethod(wx_RibbonBar, __ShowPanels);
	Gura_AssignMethod(wx_RibbonBar, __ShowPanels_1);
	Gura_AssignMethod(wx_RibbonBar, __HidePanels);
	Gura_AssignMethod(wx_RibbonBar, __ArePanelsShown);
	Gura_AssignMethod(wx_RibbonBar, __GetDisplayMode);
	Gura_AssignMethod(wx_RibbonBar, __Realize);
}

Gura_ImplementDescendantCreator(wx_RibbonBar)
{
	return new Object_wx_RibbonBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
