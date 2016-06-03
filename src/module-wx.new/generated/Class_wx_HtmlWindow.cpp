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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlWindow, __wxHtmlWindow, "wxHtmlWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, __wxHtmlWindow)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __wxHtmlWindow_1, "wxHtmlWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __wxHtmlWindow_1)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxHtmlWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindow, __AddFilter, "AddFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, __AddFilter)
{
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilter();
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
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->AppendToPage();
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
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile();
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
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->LoadPage();
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
	//int link = arg.GetNumber(0)
	//pThis->GetEntity()->OnLinkClicked();
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
	//int type = arg.GetNumber(0)
	//int url = arg.GetNumber(1)
	//int redirect = arg.GetNumber(2)
	//pThis->GetEntity()->OnOpeningURL();
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
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->OnSetTitle();
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
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->ReadCustomization();
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
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SelectLine();
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
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SelectWord();
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
	//pThis->GetEntity()->SetBorders();
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
	//int normal_face = arg.GetNumber(0)
	//int fixed_face = arg.GetNumber(1)
	//int sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts();
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
	//int normal_face = arg.GetNumber(1)
	//int fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts();
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
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->SetPage();
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
	//int frame = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->SetRelatedFrame();
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
	//pThis->GetEntity()->SetRelatedStatusBar();
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
	//int statusbar = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->SetRelatedStatusBar();
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
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->WriteCustomization();
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
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->GetDefaultHTMLCursor();
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
	//int type = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->SetDefaultHTMLCursor();
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
	//int cell = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int event = arg.GetNumber(3)
	//pThis->GetEntity()->OnCellClicked();
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
	//int cell = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->OnCellMouseHover();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindow)
{
	Gura_AssignMethod(wx_HtmlWindow, __wxHtmlWindow);
	Gura_AssignMethod(wx_HtmlWindow, __wxHtmlWindow_1);
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
