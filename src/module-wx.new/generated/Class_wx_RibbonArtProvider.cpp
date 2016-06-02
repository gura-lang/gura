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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RibbonArtProvider, wxRibbonArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonArtProvider, wxRibbonArtProvider)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonArtProvider, Clone)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, SetFlags)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetFlags)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetMetric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetMetric)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetMetric();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, SetMetric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "new_val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, SetMetric)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int new_val = arg.GetNumber(1)
	//pThis->GetEntity()->SetMetric();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, SetFont)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int font = arg.GetNumber(1)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetFont)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetColour)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, SetColour)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int colour = arg.GetNumber(1)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetColor)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetColor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, SetColor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "color", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, SetColor)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int color = arg.GetNumber(1)
	//pThis->GetEntity()->SetColor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetColourScheme)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "secondary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tertiary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetColourScheme)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int primary = arg.GetNumber(0)
	//int secondary = arg.GetNumber(1)
	//int tertiary = arg.GetNumber(2)
	//pThis->GetEntity()->GetColourScheme();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, SetColourScheme)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "secondary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tertiary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, SetColourScheme)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int primary = arg.GetNumber(0)
	//int secondary = arg.GetNumber(1)
	//int tertiary = arg.GetNumber(2)
	//pThis->GetEntity()->SetColourScheme();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawTabCtrlBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawTabCtrlBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawTabCtrlBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawTab)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tab", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawTab)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int tab = arg.GetNumber(2)
	//pThis->GetEntity()->DrawTab();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawTabSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visibility", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawTabSeparator)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int visibility = arg.GetNumber(3)
	//pThis->GetEntity()->DrawTabSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawPageBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawPageBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPageBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawScrollButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawScrollButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->DrawScrollButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawPanelBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawPanelBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPanelBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawGalleryBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawGalleryBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawGalleryBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawGalleryItemBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawGalleryItemBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//pThis->GetEntity()->DrawGalleryItemBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawMinimisedPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawMinimisedPanel)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//pThis->GetEntity()->DrawMinimisedPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawButtonBarBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawButtonBarBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawButtonBarBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawButtonBarButton)
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

Gura_ImplementMethod(wx_RibbonArtProvider, DrawButtonBarButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int kind = arg.GetNumber(3)
	//int state = arg.GetNumber(4)
	//int label = arg.GetNumber(5)
	//int bitmap_large = arg.GetNumber(6)
	//int bitmap_small = arg.GetNumber(7)
	//pThis->GetEntity()->DrawButtonBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawToolBarBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawToolBarBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawToolBarBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawToolGroupBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawToolGroupBackground)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawToolGroupBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawTool)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//int state = arg.GetNumber(5)
	//pThis->GetEntity()->DrawTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawToggleButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawToggleButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int mode = arg.GetNumber(3)
	//pThis->GetEntity()->DrawToggleButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, DrawHelpButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, DrawHelpButton)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawHelpButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetBarTabWidth)
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

Gura_ImplementMethod(wx_RibbonArtProvider, GetBarTabWidth)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int ideal = arg.GetNumber(4)
	//int small_begin_need_separator = arg.GetNumber(5)
	//int small_must_have_separator = arg.GetNumber(6)
	//int minimum = arg.GetNumber(7)
	//pThis->GetEntity()->GetBarTabWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetTabCtrlHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetTabCtrlHeight)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int pages = arg.GetNumber(2)
	//pThis->GetEntity()->GetTabCtrlHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetScrollButtonMinimumSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetScrollButtonMinimumSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->GetScrollButtonMinimumSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetPanelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetPanelSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int client_size = arg.GetNumber(2)
	//int client_offset = arg.GetNumber(3)
	//pThis->GetEntity()->GetPanelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetPanelClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_offset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetPanelClientSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int client_offset = arg.GetNumber(3)
	//pThis->GetEntity()->GetPanelClientSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetPanelExtButtonArea)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetPanelExtButtonArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->GetPanelExtButtonArea();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetGallerySize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetGallerySize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int client_size = arg.GetNumber(2)
	//pThis->GetEntity()->GetGallerySize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetGalleryClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_offset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scroll_up_button", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "scroll_down_button", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "extension_button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetGalleryClientSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int client_offset = arg.GetNumber(3)
	//int scroll_up_button = arg.GetNumber(4)
	//int scroll_down_button = arg.GetNumber(5)
	//int extension_button = arg.GetNumber(6)
	//pThis->GetEntity()->GetGalleryClientSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetPageBackgroundRedrawArea)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page_old_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page_new_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetPageBackgroundRedrawArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int page_old_size = arg.GetNumber(2)
	//int page_new_size = arg.GetNumber(3)
	//pThis->GetEntity()->GetPageBackgroundRedrawArea();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetButtonBarButtonSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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

Gura_ImplementMethod(wx_RibbonArtProvider, GetButtonBarButtonSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int kind = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int label = arg.GetNumber(4)
	//int bitmap_size_large = arg.GetNumber(5)
	//int bitmap_size_small = arg.GetNumber(6)
	//int button_size = arg.GetNumber(7)
	//int normal_region = arg.GetNumber(8)
	//int dropdown_region = arg.GetNumber(9)
	//pThis->GetEntity()->GetButtonBarButtonSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetMinimisedPanelMinimumSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "desired_bitmap_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded_panel_direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetMinimisedPanelMinimumSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int desired_bitmap_size = arg.GetNumber(2)
	//int expanded_panel_direction = arg.GetNumber(3)
	//pThis->GetEntity()->GetMinimisedPanelMinimumSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetToolSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "is_first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "is_last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dropdown_region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetToolSize)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int bitmap_size = arg.GetNumber(2)
	//int kind = arg.GetNumber(3)
	//int is_first = arg.GetNumber(4)
	//int is_last = arg.GetNumber(5)
	//int dropdown_region = arg.GetNumber(6)
	//pThis->GetEntity()->GetToolSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetBarToggleButtonArea)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetBarToggleButtonArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetBarToggleButtonArea();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonArtProvider, GetRibbonHelpButtonArea)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonArtProvider, GetRibbonHelpButtonArea)
{
	Object_wx_RibbonArtProvider *pThis = Object_wx_RibbonArtProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetRibbonHelpButtonArea();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonArtProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonArtProvider)
{
	Gura_AssignMethod(wx_RibbonArtProvider, wxRibbonArtProvider);
	Gura_AssignMethod(wx_RibbonArtProvider, Clone);
	Gura_AssignMethod(wx_RibbonArtProvider, SetFlags);
	Gura_AssignMethod(wx_RibbonArtProvider, GetFlags);
	Gura_AssignMethod(wx_RibbonArtProvider, GetMetric);
	Gura_AssignMethod(wx_RibbonArtProvider, SetMetric);
	Gura_AssignMethod(wx_RibbonArtProvider, SetFont);
	Gura_AssignMethod(wx_RibbonArtProvider, GetFont);
	Gura_AssignMethod(wx_RibbonArtProvider, GetColour);
	Gura_AssignMethod(wx_RibbonArtProvider, SetColour);
	Gura_AssignMethod(wx_RibbonArtProvider, GetColor);
	Gura_AssignMethod(wx_RibbonArtProvider, SetColor);
	Gura_AssignMethod(wx_RibbonArtProvider, GetColourScheme);
	Gura_AssignMethod(wx_RibbonArtProvider, SetColourScheme);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawTabCtrlBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawTab);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawTabSeparator);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawPageBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawScrollButton);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawPanelBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawGalleryBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawGalleryItemBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawMinimisedPanel);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawButtonBarBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawButtonBarButton);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawToolBarBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawToolGroupBackground);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawTool);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawToggleButton);
	Gura_AssignMethod(wx_RibbonArtProvider, DrawHelpButton);
	Gura_AssignMethod(wx_RibbonArtProvider, GetBarTabWidth);
	Gura_AssignMethod(wx_RibbonArtProvider, GetTabCtrlHeight);
	Gura_AssignMethod(wx_RibbonArtProvider, GetScrollButtonMinimumSize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetPanelSize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetPanelClientSize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetPanelExtButtonArea);
	Gura_AssignMethod(wx_RibbonArtProvider, GetGallerySize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetGalleryClientSize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetPageBackgroundRedrawArea);
	Gura_AssignMethod(wx_RibbonArtProvider, GetButtonBarButtonSize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetMinimisedPanelMinimumSize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetToolSize);
	Gura_AssignMethod(wx_RibbonArtProvider, GetBarToggleButtonArea);
	Gura_AssignMethod(wx_RibbonArtProvider, GetRibbonHelpButtonArea);
}

Gura_ImplementDescendantCreator(wx_RibbonArtProvider)
{
	return new Object_wx_RibbonArtProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
