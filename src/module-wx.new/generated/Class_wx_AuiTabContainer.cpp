//----------------------------------------------------------------------------
// wxAuiTabContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiTabContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiTabContainer
//----------------------------------------------------------------------------
Object_wx_AuiTabContainer::~Object_wx_AuiTabContainer()
{
}

Object *Object_wx_AuiTabContainer::Clone() const
{
	return nullptr;
}

String Object_wx_AuiTabContainer::ToString(bool exprFlag)
{
	String rtn("<wx.AuiTabContainer:");
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
Gura_DeclareFunctionAlias(__AuiTabContainer, "AuiTabContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiTabContainer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiTabContainer)
{
	//wxAuiTabContainer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetArtProvider)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiTabArt* art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider(art);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetArtProvider, "GetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetArtProvider)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetFlags)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetFlags)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __AddPage, "AddPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __AddPage)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//const wxAuiNotebookPage& info = arg.GetNumber(1)
	//pThis->GetEntity()->AddPage(page, info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __InsertPage, "InsertPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __InsertPage)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//const wxAuiNotebookPage& info = arg.GetNumber(1)
	//size_t idx = arg.GetNumber(2)
	//pThis->GetEntity()->InsertPage(page, info, idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __MovePage, "MovePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __MovePage)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//size_t newIdx = arg.GetNumber(1)
	//pThis->GetEntity()->MovePage(page, newIdx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __RemovePage, "RemovePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __RemovePage)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetActivePage, "SetActivePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetActivePage)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetActivePage_1, "SetActivePage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetActivePage_1)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetNoneActive, "SetNoneActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetNoneActive)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetNoneActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetActivePage, "GetActivePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetActivePage)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActivePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __TabHitTest, "TabHitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __TabHitTest)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//wxWindow** hit = arg.GetNumber(2)
	//pThis->GetEntity()->TabHitTest(x, y, hit);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __ButtonHitTest, "ButtonHitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __ButtonHitTest)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//wxAuiTabContainerButton** hit = arg.GetNumber(2)
	//pThis->GetEntity()->ButtonHitTest(x, y, hit);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetWindowFromIdx, "GetWindowFromIdx")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetWindowFromIdx)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetWindowFromIdx(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetIdxFromWindow, "GetIdxFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetIdxFromWindow)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//pThis->GetEntity()->GetIdxFromWindow(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetPageCount, "GetPageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetPageCount)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetPage)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetPage_1, "GetPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetPage_1)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetPages, "GetPages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetPages)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetNormalFont, "SetNormalFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normalFont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetNormalFont)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& normalFont = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont(normalFont);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetSelectedFont, "SetSelectedFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selectedFont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetSelectedFont)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& selectedFont = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont(selectedFont);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetMeasuringFont, "SetMeasuringFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "measuringFont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetMeasuringFont)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& measuringFont = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont(measuringFont);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetColour)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetActiveColour, "SetActiveColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetActiveColour)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __DoShowHide, "DoShowHide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __DoShowHide)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoShowHide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetRect, "SetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetRect)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __RemoveButton, "RemoveButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __RemoveButton)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveButton(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __AddButton, "AddButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normalBitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "disabledBitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __AddButton)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//const wxBitmap& normalBitmap = arg.GetNumber(2)
	//const wxBitmap& disabledBitmap = arg.GetNumber(3)
	//pThis->GetEntity()->AddButton(id, location, normalBitmap, disabledBitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __GetTabOffset, "GetTabOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, __GetTabOffset)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTabOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __SetTabOffset, "SetTabOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __SetTabOffset)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t offset = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabOffset(offset);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __IsTabVisible, "IsTabVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tabOffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __IsTabVisible)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabPage = arg.GetNumber(0)
	//int tabOffset = arg.GetNumber(1)
	//wxDC* dc = arg.GetNumber(2)
	//wxWindow* wnd = arg.GetNumber(3)
	//pThis->GetEntity()->IsTabVisible(tabPage, tabOffset, dc, wnd);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __MakeTabVisible, "MakeTabVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __MakeTabVisible)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabPage = arg.GetNumber(0)
	//wxWindow* win = arg.GetNumber(1)
	//pThis->GetEntity()->MakeTabVisible(tabPage, win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabContainer, __Render, "Render")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, __Render)
{
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC* dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//pThis->GetEntity()->Render(dc, wnd);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiTabContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiTabContainer)
{
	// Constructor assignment
	Gura_AssignFunction(__AuiTabContainer);
	// Method assignment
	Gura_AssignMethod(wx_AuiTabContainer, __SetArtProvider);
	Gura_AssignMethod(wx_AuiTabContainer, __GetArtProvider);
	Gura_AssignMethod(wx_AuiTabContainer, __SetFlags);
	Gura_AssignMethod(wx_AuiTabContainer, __GetFlags);
	Gura_AssignMethod(wx_AuiTabContainer, __AddPage);
	Gura_AssignMethod(wx_AuiTabContainer, __InsertPage);
	Gura_AssignMethod(wx_AuiTabContainer, __MovePage);
	Gura_AssignMethod(wx_AuiTabContainer, __RemovePage);
	Gura_AssignMethod(wx_AuiTabContainer, __SetActivePage);
	Gura_AssignMethod(wx_AuiTabContainer, __SetActivePage_1);
	Gura_AssignMethod(wx_AuiTabContainer, __SetNoneActive);
	Gura_AssignMethod(wx_AuiTabContainer, __GetActivePage);
	Gura_AssignMethod(wx_AuiTabContainer, __TabHitTest);
	Gura_AssignMethod(wx_AuiTabContainer, __ButtonHitTest);
	Gura_AssignMethod(wx_AuiTabContainer, __GetWindowFromIdx);
	Gura_AssignMethod(wx_AuiTabContainer, __GetIdxFromWindow);
	Gura_AssignMethod(wx_AuiTabContainer, __GetPageCount);
	Gura_AssignMethod(wx_AuiTabContainer, __GetPage);
	Gura_AssignMethod(wx_AuiTabContainer, __GetPage_1);
	Gura_AssignMethod(wx_AuiTabContainer, __GetPages);
	Gura_AssignMethod(wx_AuiTabContainer, __SetNormalFont);
	Gura_AssignMethod(wx_AuiTabContainer, __SetSelectedFont);
	Gura_AssignMethod(wx_AuiTabContainer, __SetMeasuringFont);
	Gura_AssignMethod(wx_AuiTabContainer, __SetColour);
	Gura_AssignMethod(wx_AuiTabContainer, __SetActiveColour);
	Gura_AssignMethod(wx_AuiTabContainer, __DoShowHide);
	Gura_AssignMethod(wx_AuiTabContainer, __SetRect);
	Gura_AssignMethod(wx_AuiTabContainer, __RemoveButton);
	Gura_AssignMethod(wx_AuiTabContainer, __AddButton);
	Gura_AssignMethod(wx_AuiTabContainer, __GetTabOffset);
	Gura_AssignMethod(wx_AuiTabContainer, __SetTabOffset);
	Gura_AssignMethod(wx_AuiTabContainer, __IsTabVisible);
	Gura_AssignMethod(wx_AuiTabContainer, __MakeTabVisible);
	Gura_AssignMethod(wx_AuiTabContainer, __Render);
}

Gura_ImplementDescendantCreator(wx_AuiTabContainer)
{
	return new Object_wx_AuiTabContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
