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
Gura_DeclareMethod(wx_HtmlWindow, wxHtmlWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, wxHtmlWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, wxHtmlWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, wxHtmlWindow_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxHtmlWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, AddFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, AddFilter)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, AppendToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, AppendToPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->AppendToPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, GetInternalRepresentation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, GetInternalRepresentation)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInternalRepresentation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, GetOpenedAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, GetOpenedAnchor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOpenedAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, GetOpenedPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, GetOpenedPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOpenedPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, GetOpenedPageTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, GetOpenedPageTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOpenedPageTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, GetRelatedFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, GetRelatedFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRelatedFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryBack)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HistoryBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryCanBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryCanBack)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HistoryCanBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryCanForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryCanForward)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HistoryCanForward();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryClear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryClear)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HistoryClear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryForward)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HistoryForward();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, LoadPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, LoadPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->LoadPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, OnLinkClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnLinkClicked)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int link = arg.GetNumber(0)
	//pThis->GetEntity()->OnLinkClicked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, OnOpeningURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "redirect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnOpeningURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int url = arg.GetNumber(1)
	//int redirect = arg.GetNumber(2)
	//pThis->GetEntity()->OnOpeningURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, OnSetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnSetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->OnSetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, ReadCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, ReadCustomization)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->ReadCustomization();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, SelectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SelectLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SelectLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SelectLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SelectWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SelectWord)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SelectWord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SelectionToText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, SelectionToText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SelectionToText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetBorders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetBorders)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorders();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetFonts)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int normal_face = arg.GetNumber(0)
	//int fixed_face = arg.GetNumber(1)
	//int sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetStandardFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetStandardFonts)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int normal_face = arg.GetNumber(1)
	//int fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->SetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetRelatedFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetRelatedFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->SetRelatedFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetRelatedStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetRelatedStatusBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->SetRelatedStatusBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetRelatedStatusBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "statusbar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetRelatedStatusBar_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int statusbar = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->SetRelatedStatusBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, ToText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindow, ToText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, WriteCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, WriteCustomization)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->WriteCustomization();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, GetDefaultHTMLCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, GetDefaultHTMLCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->GetDefaultHTMLCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetDefaultHTMLCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetDefaultHTMLCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->SetDefaultHTMLCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, OnCellClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnCellClicked)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int event = arg.GetNumber(3)
	//pThis->GetEntity()->OnCellClicked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, OnCellMouseHover)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnCellMouseHover)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_HtmlWindow, wxHtmlWindow);
	Gura_AssignMethod(wx_HtmlWindow, wxHtmlWindow_1);
	Gura_AssignMethod(wx_HtmlWindow, AddFilter);
	Gura_AssignMethod(wx_HtmlWindow, AppendToPage);
	Gura_AssignMethod(wx_HtmlWindow, GetInternalRepresentation);
	Gura_AssignMethod(wx_HtmlWindow, GetOpenedAnchor);
	Gura_AssignMethod(wx_HtmlWindow, GetOpenedPage);
	Gura_AssignMethod(wx_HtmlWindow, GetOpenedPageTitle);
	Gura_AssignMethod(wx_HtmlWindow, GetRelatedFrame);
	Gura_AssignMethod(wx_HtmlWindow, HistoryBack);
	Gura_AssignMethod(wx_HtmlWindow, HistoryCanBack);
	Gura_AssignMethod(wx_HtmlWindow, HistoryCanForward);
	Gura_AssignMethod(wx_HtmlWindow, HistoryClear);
	Gura_AssignMethod(wx_HtmlWindow, HistoryForward);
	Gura_AssignMethod(wx_HtmlWindow, LoadFile);
	Gura_AssignMethod(wx_HtmlWindow, LoadPage);
	Gura_AssignMethod(wx_HtmlWindow, OnLinkClicked);
	Gura_AssignMethod(wx_HtmlWindow, OnOpeningURL);
	Gura_AssignMethod(wx_HtmlWindow, OnSetTitle);
	Gura_AssignMethod(wx_HtmlWindow, ReadCustomization);
	Gura_AssignMethod(wx_HtmlWindow, SelectAll);
	Gura_AssignMethod(wx_HtmlWindow, SelectLine);
	Gura_AssignMethod(wx_HtmlWindow, SelectWord);
	Gura_AssignMethod(wx_HtmlWindow, SelectionToText);
	Gura_AssignMethod(wx_HtmlWindow, SetBorders);
	Gura_AssignMethod(wx_HtmlWindow, SetFonts);
	Gura_AssignMethod(wx_HtmlWindow, SetStandardFonts);
	Gura_AssignMethod(wx_HtmlWindow, SetPage);
	Gura_AssignMethod(wx_HtmlWindow, SetRelatedFrame);
	Gura_AssignMethod(wx_HtmlWindow, SetRelatedStatusBar);
	Gura_AssignMethod(wx_HtmlWindow, SetRelatedStatusBar_1);
	Gura_AssignMethod(wx_HtmlWindow, ToText);
	Gura_AssignMethod(wx_HtmlWindow, WriteCustomization);
	Gura_AssignMethod(wx_HtmlWindow, GetDefaultHTMLCursor);
	Gura_AssignMethod(wx_HtmlWindow, SetDefaultHTMLCursor);
	Gura_AssignMethod(wx_HtmlWindow, OnCellClicked);
	Gura_AssignMethod(wx_HtmlWindow, OnCellMouseHover);
}

Gura_ImplementDescendantCreator(wx_HtmlWindow)
{
	return new Object_wx_HtmlWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
