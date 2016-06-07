//----------------------------------------------------------------------------
// wxHtmlWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWindow
//----------------------------------------------------------------------------
Object_wx_HtmlWindow::~Object_wx_HtmlWindow()
{
}

Object *Object_wx_HtmlWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWindow:");
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
Gura_DeclareFunctionAlias(__HtmlWindow, "HtmlWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlWindow)
{
	//wxHtmlWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HtmlWindow_1, "HtmlWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxHtmlWindow(parent, id, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlWindow, __AddFilter, "AddFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __AddFilter)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlFilter* filter = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilter(filter);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __AppendToPage, "AppendToPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __AppendToPage)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& source = arg.GetNumber(0)
	//pThis->GetEntity()->AppendToPage(source);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __GetInternalRepresentation, "GetInternalRepresentation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __GetInternalRepresentation)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalRepresentation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __GetOpenedAnchor, "GetOpenedAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __GetOpenedAnchor)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOpenedAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __GetOpenedPage, "GetOpenedPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __GetOpenedPage)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOpenedPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __GetOpenedPageTitle, "GetOpenedPageTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __GetOpenedPageTitle)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOpenedPageTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __GetRelatedFrame, "GetRelatedFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __GetRelatedFrame)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRelatedFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __HistoryBack, "HistoryBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __HistoryBack)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HistoryBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __HistoryCanBack, "HistoryCanBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __HistoryCanBack)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HistoryCanBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __HistoryCanForward, "HistoryCanForward")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __HistoryCanForward)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HistoryCanForward();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __HistoryClear, "HistoryClear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __HistoryClear)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HistoryClear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __HistoryForward, "HistoryForward")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __HistoryForward)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HistoryForward();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __LoadFile)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFileName& filename = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile(filename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __LoadPage, "LoadPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __LoadPage)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//pThis->GetEntity()->LoadPage(location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __OnLinkClicked, "OnLinkClicked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __OnLinkClicked)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlLinkInfo& link = arg.GetNumber(0)
	//pThis->GetEntity()->OnLinkClicked(link);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __OnOpeningURL, "OnOpeningURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "redirect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __OnOpeningURL)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlURLType type = arg.GetNumber(0)
	//const wxString& url = arg.GetNumber(1)
	//wxString* redirect = arg.GetNumber(2)
	//pThis->GetEntity()->OnOpeningURL(type, url, redirect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __OnSetTitle, "OnSetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __OnSetTitle)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//pThis->GetEntity()->OnSetTitle(title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __ReadCustomization, "ReadCustomization")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __ReadCustomization)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConfigBase* cfg = arg.GetNumber(0)
	//wxString path = arg.GetNumber(1)
	//pThis->GetEntity()->ReadCustomization(cfg, path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __SelectAll)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SelectLine, "SelectLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SelectLine)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//pThis->GetEntity()->SelectLine(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SelectWord, "SelectWord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SelectWord)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//pThis->GetEntity()->SelectWord(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SelectionToText, "SelectionToText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __SelectionToText)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectionToText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetBorders, "SetBorders")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetBorders)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorders(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetFonts, "SetFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetFonts)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& normal_face = arg.GetNumber(0)
	//const wxString& fixed_face = arg.GetNumber(1)
	//const int* sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts(normal_face, fixed_face, sizes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetStandardFonts, "SetStandardFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetStandardFonts)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//const wxString& normal_face = arg.GetNumber(1)
	//const wxString& fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts(size, normal_face, fixed_face);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetPage, "SetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetPage)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& source = arg.GetNumber(0)
	//pThis->GetEntity()->SetPage(source);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetRelatedFrame, "SetRelatedFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetRelatedFrame)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFrame* frame = arg.GetNumber(0)
	//const wxString& format = arg.GetNumber(1)
	//pThis->GetEntity()->SetRelatedFrame(frame, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetRelatedStatusBar, "SetRelatedStatusBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetRelatedStatusBar)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->SetRelatedStatusBar(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetRelatedStatusBar_1, "SetRelatedStatusBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "statusbar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetRelatedStatusBar_1)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxStatusBar* statusbar = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->SetRelatedStatusBar(statusbar, index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __ToText, "ToText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __ToText)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __WriteCustomization, "WriteCustomization")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __WriteCustomization)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConfigBase* cfg = arg.GetNumber(0)
	//wxString path = arg.GetNumber(1)
	//pThis->GetEntity()->WriteCustomization(cfg, path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __GetDefaultHTMLCursor, "GetDefaultHTMLCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __GetDefaultHTMLCursor)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//HTMLCursor type = arg.GetNumber(0)
	//pThis->GetEntity()->GetDefaultHTMLCursor(type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __SetDefaultHTMLCursor, "SetDefaultHTMLCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __SetDefaultHTMLCursor)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//HTMLCursor type = arg.GetNumber(0)
	//const wxCursor& cursor = arg.GetNumber(1)
	//pThis->GetEntity()->SetDefaultHTMLCursor(type, cursor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __OnCellClicked, "OnCellClicked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __OnCellClicked)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlCell* cell = arg.GetNumber(0)
	//wxCoord x = arg.GetNumber(1)
	//wxCoord y = arg.GetNumber(2)
	//const wxMouseEvent& event = arg.GetNumber(3)
	//pThis->GetEntity()->OnCellClicked(cell, x, y, event);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __OnCellMouseHover, "OnCellMouseHover")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __OnCellMouseHover)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlCell* cell = arg.GetNumber(0)
	//wxCoord x = arg.GetNumber(1)
	//wxCoord y = arg.GetNumber(2)
	//pThis->GetEntity()->OnCellMouseHover(cell, x, y);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlWindow);
	Gura_AssignFunction(__HtmlWindow_1);
	// Method assignment
	Gura_AssignMethod(wx_HtmlWindow, __AddFilter);
	Gura_AssignMethod(wx_HtmlWindow, __AppendToPage);
	Gura_AssignMethod(wx_HtmlWindow, __GetInternalRepresentation);
	Gura_AssignMethod(wx_HtmlWindow, __GetOpenedAnchor);
	Gura_AssignMethod(wx_HtmlWindow, __GetOpenedPage);
	Gura_AssignMethod(wx_HtmlWindow, __GetOpenedPageTitle);
	Gura_AssignMethod(wx_HtmlWindow, __GetRelatedFrame);
	Gura_AssignMethod(wx_HtmlWindow, __HistoryBack);
	Gura_AssignMethod(wx_HtmlWindow, __HistoryCanBack);
	Gura_AssignMethod(wx_HtmlWindow, __HistoryCanForward);
	Gura_AssignMethod(wx_HtmlWindow, __HistoryClear);
	Gura_AssignMethod(wx_HtmlWindow, __HistoryForward);
	Gura_AssignMethod(wx_HtmlWindow, __LoadFile);
	Gura_AssignMethod(wx_HtmlWindow, __LoadPage);
	Gura_AssignMethod(wx_HtmlWindow, __OnLinkClicked);
	Gura_AssignMethod(wx_HtmlWindow, __OnOpeningURL);
	Gura_AssignMethod(wx_HtmlWindow, __OnSetTitle);
	Gura_AssignMethod(wx_HtmlWindow, __ReadCustomization);
	Gura_AssignMethod(wx_HtmlWindow, __SelectAll);
	Gura_AssignMethod(wx_HtmlWindow, __SelectLine);
	Gura_AssignMethod(wx_HtmlWindow, __SelectWord);
	Gura_AssignMethod(wx_HtmlWindow, __SelectionToText);
	Gura_AssignMethod(wx_HtmlWindow, __SetBorders);
	Gura_AssignMethod(wx_HtmlWindow, __SetFonts);
	Gura_AssignMethod(wx_HtmlWindow, __SetStandardFonts);
	Gura_AssignMethod(wx_HtmlWindow, __SetPage);
	Gura_AssignMethod(wx_HtmlWindow, __SetRelatedFrame);
	Gura_AssignMethod(wx_HtmlWindow, __SetRelatedStatusBar);
	Gura_AssignMethod(wx_HtmlWindow, __SetRelatedStatusBar_1);
	Gura_AssignMethod(wx_HtmlWindow, __ToText);
	Gura_AssignMethod(wx_HtmlWindow, __WriteCustomization);
	Gura_AssignMethod(wx_HtmlWindow, __GetDefaultHTMLCursor);
	Gura_AssignMethod(wx_HtmlWindow, __SetDefaultHTMLCursor);
	Gura_AssignMethod(wx_HtmlWindow, __OnCellClicked);
	Gura_AssignMethod(wx_HtmlWindow, __OnCellMouseHover);
}

Gura_ImplementDescendantCreator(wx_HtmlWindow)
{
	return new Object_wx_HtmlWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
