//----------------------------------------------------------------------------
// wxRibbonArtProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonArtProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonArtProvider
//----------------------------------------------------------------------------
Object_wx_RibbonArtProvider::~Object_wx_RibbonArtProvider()
{
}

Object *Object_wx_RibbonArtProvider::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonArtProvider::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonArtProvider:");
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
Gura_DeclareFunctionAlias(__RibbonArtProvider, "RibbonArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonArtProvider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonArtProvider)
{
	//wxRibbonArtProvider();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonArtProvider, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __Clone)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonArtProvider* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __SetFlags)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetFlags)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetMetric, "GetMetric")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetMetric)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetMetric(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __SetMetric, "SetMetric")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "new_val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __SetMetric)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int new_val = arg.GetNumber(1)
	//pThis->GetEntity()->SetMetric(id, new_val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __SetFont)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxFont& font = arg.GetNumber(1)
	//pThis->GetEntity()->SetFont(id, font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetFont)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxFont _rtn = pThis->GetEntity()->GetFont(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetColour)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxColour _rtn = pThis->GetEntity()->GetColour(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __SetColour)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxColor& colour = arg.GetNumber(1)
	//pThis->GetEntity()->SetColour(id, colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetColor, "GetColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetColor)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxColour _rtn = pThis->GetEntity()->GetColor(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __SetColor, "SetColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "color", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __SetColor)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxColour& color = arg.GetNumber(1)
	//pThis->GetEntity()->SetColor(id, color);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetColourScheme, "GetColourScheme")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "secondary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tertiary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetColourScheme)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour* primary = arg.GetNumber(0)
	//wxColour* secondary = arg.GetNumber(1)
	//wxColour* tertiary = arg.GetNumber(2)
	//pThis->GetEntity()->GetColourScheme(primary, secondary, tertiary);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __SetColourScheme, "SetColourScheme")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "secondary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tertiary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __SetColourScheme)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& primary = arg.GetNumber(0)
	//const wxColour& secondary = arg.GetNumber(1)
	//const wxColour& tertiary = arg.GetNumber(2)
	//pThis->GetEntity()->SetColourScheme(primary, secondary, tertiary);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawTabCtrlBackground, "DrawTabCtrlBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawTabCtrlBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawTabCtrlBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawTab, "DrawTab")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tab", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawTab)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRibbonPageTabInfo& tab = arg.GetNumber(2)
	//pThis->GetEntity()->DrawTab(dc, wnd, tab);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawTabSeparator, "DrawTabSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visibility", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawTabSeparator)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//double visibility = arg.GetNumber(3)
	//pThis->GetEntity()->DrawTabSeparator(dc, wnd, rect, visibility);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawPageBackground, "DrawPageBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawPageBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPageBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawScrollButton, "DrawScrollButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawScrollButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//long style = arg.GetNumber(3)
	//pThis->GetEntity()->DrawScrollButton(dc, wnd, rect, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawPanelBackground, "DrawPanelBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawPanelBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRibbonPanel* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPanelBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawGalleryBackground, "DrawGalleryBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawGalleryBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRibbonGallery* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawGalleryBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawGalleryItemBackground, "DrawGalleryItemBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawGalleryItemBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRibbonGallery* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//wxRibbonGalleryItem* item = arg.GetNumber(3)
	//pThis->GetEntity()->DrawGalleryItemBackground(dc, wnd, rect, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawMinimisedPanel, "DrawMinimisedPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawMinimisedPanel)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRibbonPanel* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//wxBitmap& bitmap = arg.GetNumber(3)
	//pThis->GetEntity()->DrawMinimisedPanel(dc, wnd, rect, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawButtonBarBackground, "DrawButtonBarBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawButtonBarBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawButtonBarBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawButtonBarButton, "DrawButtonBarButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_large", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_small", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawButtonBarButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//wxRibbonButtonBarButtonKind kind = arg.GetNumber(3)
	//long state = arg.GetNumber(4)
	//const wxString& label = arg.GetNumber(5)
	//const wxBitmap& bitmap_large = arg.GetNumber(6)
	//const wxBitmap& bitmap_small = arg.GetNumber(7)
	//pThis->GetEntity()->DrawButtonBarButton(dc, wnd, rect, kind, state, label, bitmap_large, bitmap_small);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawToolBarBackground, "DrawToolBarBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawToolBarBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawToolBarBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawToolGroupBackground, "DrawToolGroupBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawToolGroupBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawToolGroupBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawTool, "DrawTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawTool)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//const wxBitmap& bitmap = arg.GetNumber(3)
	//wxRibbonButtonKind kind = arg.GetNumber(4)
	//long state = arg.GetNumber(5)
	//pThis->GetEntity()->DrawTool(dc, wnd, rect, bitmap, kind, state);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawToggleButton, "DrawToggleButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawToggleButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRibbonBar* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//wxRibbonDisplayMode mode = arg.GetNumber(3)
	//pThis->GetEntity()->DrawToggleButton(dc, wnd, rect, mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __DrawHelpButton, "DrawHelpButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __DrawHelpButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRibbonBar* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawHelpButton(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetBarTabWidth, "GetBarTabWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ideal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "small_begin_need_separator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "small_must_have_separator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minimum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetBarTabWidth)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxBitmap& bitmap = arg.GetNumber(3)
	//int* ideal = arg.GetNumber(4)
	//int* small_begin_need_separator = arg.GetNumber(5)
	//int* small_must_have_separator = arg.GetNumber(6)
	//int* minimum = arg.GetNumber(7)
	//pThis->GetEntity()->GetBarTabWidth(dc, wnd, label, bitmap, ideal, small_begin_need_separator, small_must_have_separator, minimum);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetTabCtrlHeight, "GetTabCtrlHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetTabCtrlHeight)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRibbonPageTabInfoArray& pages = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->GetTabCtrlHeight(dc, wnd, pages);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetScrollButtonMinimumSize, "GetScrollButtonMinimumSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetScrollButtonMinimumSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//long style = arg.GetNumber(2)
	//wxSize _rtn = pThis->GetEntity()->GetScrollButtonMinimumSize(dc, wnd, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetPanelSize, "GetPanelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetPanelSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRibbonPanel* wnd = arg.GetNumber(1)
	//wxSize client_size = arg.GetNumber(2)
	//wxPoint* client_offset = arg.GetNumber(3)
	//wxSize _rtn = pThis->GetEntity()->GetPanelSize(dc, wnd, client_size, client_offset);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetPanelClientSize, "GetPanelClientSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetPanelClientSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRibbonPanel* wnd = arg.GetNumber(1)
	//wxSize size = arg.GetNumber(2)
	//wxPoint* client_offset = arg.GetNumber(3)
	//wxSize _rtn = pThis->GetEntity()->GetPanelClientSize(dc, wnd, size, client_offset);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetPanelExtButtonArea, "GetPanelExtButtonArea")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetPanelExtButtonArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRibbonPanel* wnd = arg.GetNumber(1)
	//wxRect rect = arg.GetNumber(2)
	//wxRect _rtn = pThis->GetEntity()->GetPanelExtButtonArea(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetGallerySize, "GetGallerySize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetGallerySize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRibbonGallery* wnd = arg.GetNumber(1)
	//wxSize client_size = arg.GetNumber(2)
	//wxSize _rtn = pThis->GetEntity()->GetGallerySize(dc, wnd, client_size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetGalleryClientSize, "GetGalleryClientSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_offset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scroll_up_button", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scroll_down_button", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "extension_button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetGalleryClientSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRibbonGallery* wnd = arg.GetNumber(1)
	//wxSize size = arg.GetNumber(2)
	//wxPoint* client_offset = arg.GetNumber(3)
	//wxRect* scroll_up_button = arg.GetNumber(4)
	//wxRect* scroll_down_button = arg.GetNumber(5)
	//wxRect* extension_button = arg.GetNumber(6)
	//wxSize _rtn = pThis->GetEntity()->GetGalleryClientSize(dc, wnd, size, client_offset, scroll_up_button, scroll_down_button, extension_button);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetPageBackgroundRedrawArea, "GetPageBackgroundRedrawArea")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page_old_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page_new_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetPageBackgroundRedrawArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRibbonPage* wnd = arg.GetNumber(1)
	//wxSize page_old_size = arg.GetNumber(2)
	//wxSize page_new_size = arg.GetNumber(3)
	//wxRect _rtn = pThis->GetEntity()->GetPageBackgroundRedrawArea(dc, wnd, page_old_size, page_new_size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetButtonBarButtonSize, "GetButtonBarButtonSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_size_large", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_size_small", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normal_region", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dropdown_region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetButtonBarButtonSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//wxRibbonButtonBarButtonKind kind = arg.GetNumber(2)
	//wxRibbonButtonBarButtonState size = arg.GetNumber(3)
	//const wxString& label = arg.GetNumber(4)
	//wxSize bitmap_size_large = arg.GetNumber(5)
	//wxSize bitmap_size_small = arg.GetNumber(6)
	//wxSize* button_size = arg.GetNumber(7)
	//wxRect* normal_region = arg.GetNumber(8)
	//wxRect* dropdown_region = arg.GetNumber(9)
	//bool _rtn = pThis->GetEntity()->GetButtonBarButtonSize(dc, wnd, kind, size, label, bitmap_size_large, bitmap_size_small, button_size, normal_region, dropdown_region);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetMinimisedPanelMinimumSize, "GetMinimisedPanelMinimumSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desired_bitmap_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded_panel_direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetMinimisedPanelMinimumSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRibbonPanel* wnd = arg.GetNumber(1)
	//wxSize* desired_bitmap_size = arg.GetNumber(2)
	//wxDirection* expanded_panel_direction = arg.GetNumber(3)
	//wxSize _rtn = pThis->GetEntity()->GetMinimisedPanelMinimumSize(dc, wnd, desired_bitmap_size, expanded_panel_direction);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetToolSize, "GetToolSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "is_first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "is_last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dropdown_region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetToolSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//wxSize bitmap_size = arg.GetNumber(2)
	//wxRibbonButtonKind kind = arg.GetNumber(3)
	//bool is_first = arg.GetNumber(4)
	//bool is_last = arg.GetNumber(5)
	//wxRect* dropdown_region = arg.GetNumber(6)
	//wxSize _rtn = pThis->GetEntity()->GetToolSize(dc, wnd, bitmap_size, kind, is_first, is_last, dropdown_region);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetBarToggleButtonArea, "GetBarToggleButtonArea")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetBarToggleButtonArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//wxRect _rtn = pThis->GetEntity()->GetBarToggleButtonArea(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonArtProvider, __GetRibbonHelpButtonArea, "GetRibbonHelpButtonArea")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, __GetRibbonHelpButtonArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//wxRect _rtn = pThis->GetEntity()->GetRibbonHelpButtonArea(rect);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonArtProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonArtProvider)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonArtProvider);
	// Method assignment
	Gura_AssignMethod(wx_RibbonArtProvider, __Clone);
	Gura_AssignMethod(wx_RibbonArtProvider, __SetFlags);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetFlags);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetMetric);
	Gura_AssignMethod(wx_RibbonArtProvider, __SetMetric);
	Gura_AssignMethod(wx_RibbonArtProvider, __SetFont);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetFont);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetColour);
	Gura_AssignMethod(wx_RibbonArtProvider, __SetColour);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetColor);
	Gura_AssignMethod(wx_RibbonArtProvider, __SetColor);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetColourScheme);
	Gura_AssignMethod(wx_RibbonArtProvider, __SetColourScheme);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawTabCtrlBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawTab);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawTabSeparator);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawPageBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawScrollButton);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawPanelBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawGalleryBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawGalleryItemBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawMinimisedPanel);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawButtonBarBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawButtonBarButton);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawToolBarBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawToolGroupBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawTool);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawToggleButton);
	Gura_AssignMethod(wx_RibbonArtProvider, __DrawHelpButton);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetBarTabWidth);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetTabCtrlHeight);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetScrollButtonMinimumSize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetPanelSize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetPanelClientSize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetPanelExtButtonArea);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetGallerySize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetGalleryClientSize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetPageBackgroundRedrawArea);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetButtonBarButtonSize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetMinimisedPanelMinimumSize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetToolSize);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetBarToggleButtonArea);
	Gura_AssignMethod(wx_RibbonArtProvider, __GetRibbonHelpButtonArea);
}

Gura_ImplementDescendantCreator(wx_RibbonArtProvider)
{
	return new Object_wx_RibbonArtProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
