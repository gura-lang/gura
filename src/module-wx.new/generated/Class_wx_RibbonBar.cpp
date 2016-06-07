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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//wxRibbonBar(parent, id, pos, size, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonBar, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style);
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
	//pThis->GetEntity()->SetTabCtrlMargins(left, right);
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
	//wxRibbonArtProvider* art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider(art);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __SetActivePage, "SetActivePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __SetActivePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetActivePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __SetActivePage_1, "SetActivePage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __SetActivePage_1)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonPage* page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetActivePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetActivePage, "GetActivePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __GetActivePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetActivePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __GetPage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//wxRibbonPage* _rtn = pThis->GetEntity()->GetPage(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetPageCount, "GetPageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __GetPageCount)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __DismissExpandedPanel, "DismissExpandedPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __DismissExpandedPanel)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DismissExpandedPanel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetPageNumber, "GetPageNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __GetPageNumber)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonPage* page = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetPageNumber(page);
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
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->DeletePage(n);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __IsPageShown)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsPageShown(page);
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
	//size_t page = arg.GetNumber(0)
	//bool show_tab = arg.GetNumber(1)
	//pThis->GetEntity()->ShowPage(page, show_tab);
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
	//size_t page = arg.GetNumber(0)
	//pThis->GetEntity()->HidePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __IsPageHighlighted, "IsPageHighlighted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, __IsPageHighlighted)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsPageHighlighted(page);
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
	//size_t page = arg.GetNumber(0)
	//bool highlight = arg.GetNumber(1)
	//pThis->GetEntity()->AddPageHighlight(page, highlight);
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
	//size_t page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePageHighlight(page);
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
	//wxRibbonDisplayMode mode = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPanels(mode);
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
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPanels(show);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __ArePanelsShown)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->ArePanelsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __GetDisplayMode, "GetDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __GetDisplayMode)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonDisplayMode _rtn = pThis->GetEntity()->GetDisplayMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBar, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, __Realize)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Realize();
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
