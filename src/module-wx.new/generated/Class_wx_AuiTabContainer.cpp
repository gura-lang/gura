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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AuiTabContainer, wxAuiTabContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, wxAuiTabContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAuiTabContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, ~wxAuiTabContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, ~wxAuiTabContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAuiTabContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, AddPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, AddPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int info = arg.GetNumber(1)
	//pThis->GetEntity()->AddPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, InsertPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int info = arg.GetNumber(1)
	//int idx = arg.GetNumber(2)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, MovePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, MovePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int newIdx = arg.GetNumber(1)
	//pThis->GetEntity()->MovePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, RemovePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, RemovePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetActivePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetActivePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetActivePage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetActivePage_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetActivePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetNoneActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetNoneActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetNoneActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetActivePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetActivePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetActivePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, TabHitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, TabHitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int hit = arg.GetNumber(2)
	//pThis->GetEntity()->TabHitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, ButtonHitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hit", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, ButtonHitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int hit = arg.GetNumber(2)
	//pThis->GetEntity()->ButtonHitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetWindowFromIdx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetWindowFromIdx)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetWindowFromIdx();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetIdxFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetIdxFromWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetIdxFromWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetPageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetPageCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetPage_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetPages)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normalFont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetNormalFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int normalFont = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selectedFont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int selectedFont = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetMeasuringFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "measuringFont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetMeasuringFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int measuringFont = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetActiveColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetActiveColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, DoShowHide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, DoShowHide)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DoShowHide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, RemoveButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, RemoveButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, AddButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normalBitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "disabledBitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, AddButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//int normalBitmap = arg.GetNumber(2)
	//int disabledBitmap = arg.GetNumber(3)
	//pThis->GetEntity()->AddButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, GetTabOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabContainer, GetTabOffset)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTabOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, SetTabOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, SetTabOffset)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int offset = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, IsTabVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tabOffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, IsTabVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tabPage = arg.GetNumber(0)
	//int tabOffset = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int wnd = arg.GetNumber(3)
	//pThis->GetEntity()->IsTabVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, MakeTabVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, MakeTabVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tabPage = arg.GetNumber(0)
	//int win = arg.GetNumber(1)
	//pThis->GetEntity()->MakeTabVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabContainer, Render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabContainer, Render)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabContainer *pThis = Object_wx_AuiTabContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//pThis->GetEntity()->Render();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiTabContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiTabContainer)
{
	Gura_AssignMethod(wx_AuiTabContainer, wxAuiTabContainer);
	Gura_AssignMethod(wx_AuiTabContainer, ~wxAuiTabContainer);
	Gura_AssignMethod(wx_AuiTabContainer, SetArtProvider);
	Gura_AssignMethod(wx_AuiTabContainer, GetArtProvider);
	Gura_AssignMethod(wx_AuiTabContainer, SetFlags);
	Gura_AssignMethod(wx_AuiTabContainer, GetFlags);
	Gura_AssignMethod(wx_AuiTabContainer, AddPage);
	Gura_AssignMethod(wx_AuiTabContainer, InsertPage);
	Gura_AssignMethod(wx_AuiTabContainer, MovePage);
	Gura_AssignMethod(wx_AuiTabContainer, RemovePage);
	Gura_AssignMethod(wx_AuiTabContainer, SetActivePage);
	Gura_AssignMethod(wx_AuiTabContainer, SetActivePage_1);
	Gura_AssignMethod(wx_AuiTabContainer, SetNoneActive);
	Gura_AssignMethod(wx_AuiTabContainer, GetActivePage);
	Gura_AssignMethod(wx_AuiTabContainer, TabHitTest);
	Gura_AssignMethod(wx_AuiTabContainer, ButtonHitTest);
	Gura_AssignMethod(wx_AuiTabContainer, GetWindowFromIdx);
	Gura_AssignMethod(wx_AuiTabContainer, GetIdxFromWindow);
	Gura_AssignMethod(wx_AuiTabContainer, GetPageCount);
	Gura_AssignMethod(wx_AuiTabContainer, GetPage);
	Gura_AssignMethod(wx_AuiTabContainer, GetPage_1);
	Gura_AssignMethod(wx_AuiTabContainer, GetPages);
	Gura_AssignMethod(wx_AuiTabContainer, SetNormalFont);
	Gura_AssignMethod(wx_AuiTabContainer, SetSelectedFont);
	Gura_AssignMethod(wx_AuiTabContainer, SetMeasuringFont);
	Gura_AssignMethod(wx_AuiTabContainer, SetColour);
	Gura_AssignMethod(wx_AuiTabContainer, SetActiveColour);
	Gura_AssignMethod(wx_AuiTabContainer, DoShowHide);
	Gura_AssignMethod(wx_AuiTabContainer, SetRect);
	Gura_AssignMethod(wx_AuiTabContainer, RemoveButton);
	Gura_AssignMethod(wx_AuiTabContainer, AddButton);
	Gura_AssignMethod(wx_AuiTabContainer, GetTabOffset);
	Gura_AssignMethod(wx_AuiTabContainer, SetTabOffset);
	Gura_AssignMethod(wx_AuiTabContainer, IsTabVisible);
	Gura_AssignMethod(wx_AuiTabContainer, MakeTabVisible);
	Gura_AssignMethod(wx_AuiTabContainer, Render);
}

Gura_ImplementDescendantCreator(wx_AuiTabContainer)
{
	return new Object_wx_AuiTabContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
