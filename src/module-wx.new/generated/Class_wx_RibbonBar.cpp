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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RibbonBar, wxRibbonBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, wxRibbonBar)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, wxRibbonBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, wxRibbonBar_1)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxRibbonBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, Create)
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

Gura_DeclareMethod(wx_RibbonBar, SetTabCtrlMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, SetTabCtrlMargins)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int right = arg.GetNumber(1)
	//pThis->GetEntity()->SetTabCtrlMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, SetArtProvider)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, SetActivePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, SetActivePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, SetActivePage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, SetActivePage_1)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, GetActivePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, GetActivePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActivePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, GetPage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, GetPageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, GetPageCount)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, DismissExpandedPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, DismissExpandedPanel)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DismissExpandedPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, GetPageNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, GetPageNumber)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, DeletePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, DeletePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->DeletePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, ClearPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, ClearPages)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearPages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, IsPageShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, IsPageShown)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->IsPageShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, ShowPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "show_tab", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, ShowPage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int show_tab = arg.GetNumber(1)
	//pThis->GetEntity()->ShowPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, HidePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, HidePage)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->HidePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, IsPageHighlighted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, IsPageHighlighted)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->IsPageHighlighted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, AddPageHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "highlight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, AddPageHighlight)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int highlight = arg.GetNumber(1)
	//pThis->GetEntity()->AddPageHighlight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, RemovePageHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, RemovePageHighlight)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePageHighlight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, ShowPanels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, ShowPanels)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPanels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, ShowPanels_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBar, ShowPanels_1)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPanels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, HidePanels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, HidePanels)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HidePanels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, ArePanelsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, ArePanelsShown)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ArePanelsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, GetDisplayMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, GetDisplayMode)
{
	Object_wx_RibbonBar *pThis = Object_wx_RibbonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonBar, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBar, Realize)
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
	Gura_AssignMethod(wx_RibbonBar, wxRibbonBar);
	Gura_AssignMethod(wx_RibbonBar, wxRibbonBar_1);
	Gura_AssignMethod(wx_RibbonBar, Create);
	Gura_AssignMethod(wx_RibbonBar, SetTabCtrlMargins);
	Gura_AssignMethod(wx_RibbonBar, SetArtProvider);
	Gura_AssignMethod(wx_RibbonBar, SetActivePage);
	Gura_AssignMethod(wx_RibbonBar, SetActivePage_1);
	Gura_AssignMethod(wx_RibbonBar, GetActivePage);
	Gura_AssignMethod(wx_RibbonBar, GetPage);
	Gura_AssignMethod(wx_RibbonBar, GetPageCount);
	Gura_AssignMethod(wx_RibbonBar, DismissExpandedPanel);
	Gura_AssignMethod(wx_RibbonBar, GetPageNumber);
	Gura_AssignMethod(wx_RibbonBar, DeletePage);
	Gura_AssignMethod(wx_RibbonBar, ClearPages);
	Gura_AssignMethod(wx_RibbonBar, IsPageShown);
	Gura_AssignMethod(wx_RibbonBar, ShowPage);
	Gura_AssignMethod(wx_RibbonBar, HidePage);
	Gura_AssignMethod(wx_RibbonBar, IsPageHighlighted);
	Gura_AssignMethod(wx_RibbonBar, AddPageHighlight);
	Gura_AssignMethod(wx_RibbonBar, RemovePageHighlight);
	Gura_AssignMethod(wx_RibbonBar, ShowPanels);
	Gura_AssignMethod(wx_RibbonBar, ShowPanels_1);
	Gura_AssignMethod(wx_RibbonBar, HidePanels);
	Gura_AssignMethod(wx_RibbonBar, ArePanelsShown);
	Gura_AssignMethod(wx_RibbonBar, GetDisplayMode);
	Gura_AssignMethod(wx_RibbonBar, Realize);
}

Gura_ImplementDescendantCreator(wx_RibbonBar)
{
	return new Object_wx_RibbonBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
