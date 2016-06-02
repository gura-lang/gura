//----------------------------------------------------------------------------
// wxWebView
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebView
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebView
//----------------------------------------------------------------------------
Object_wx_WebView::~Object_wx_WebView()
{
}

Object *Object_wx_WebView::Clone() const
{
	return nullptr;
}

String Object_wx_WebView::ToString(bool exprFlag)
{
	String rtn("<wx.WebView:");
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
Gura_DeclareMethod(wx_WebView, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, Create)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int url = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, New)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "backend", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, New)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int backend = arg.GetNumber(0)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, New_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "backend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, New_1)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int url = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int backend = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, RegisterFactory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "backend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "factory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, RegisterFactory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int backend = arg.GetNumber(0)
	//int factory = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterFactory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetCurrentTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetCurrentTitle)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetCurrentURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetCurrentURL)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetNativeBackend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetNativeBackend)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNativeBackend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetPageSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetPageSource)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetPageText)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, IsBusy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, IsBusy)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsBusy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, IsEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, IsEditable)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, LoadURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, LoadURL)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->LoadURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, Print)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Print();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, RegisterHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, RegisterHandler)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->RegisterHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Reload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, Reload)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Reload();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, RunScript)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "javascript", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, RunScript)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int javascript = arg.GetNumber(0)
	//pThis->GetEntity()->RunScript();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, SetEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, SetEditable)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, SetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseUrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, SetPage)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int html = arg.GetNumber(0)
	//int baseUrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, SetPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseUrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, SetPage_1)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int html = arg.GetNumber(0)
	//int baseUrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, Stop)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, CanCopy)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCopy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, CanCut)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, CanPaste)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, Copy)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, Cut)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, Paste)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, EnableContextMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, EnableContextMenu)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableContextMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, IsContextMenuEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, IsContextMenuEnabled)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsContextMenuEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanGoBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, CanGoBack)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanGoBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanGoForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, CanGoForward)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanGoForward();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, ClearHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, ClearHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, EnableHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, EnableHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetBackwardHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetBackwardHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackwardHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetForwardHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetForwardHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetForwardHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GoBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GoBack)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GoBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GoForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GoForward)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GoForward();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, LoadHistoryItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, LoadHistoryItem)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->LoadHistoryItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, ClearSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, ClearSelection)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, DeleteSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, DeleteSelection)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetSelectedSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetSelectedSource)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetSelectedText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetSelectedText)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, HasSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, HasSelection)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, SelectAll)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, CanRedo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, CanUndo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Redo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, Redo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, Undo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, Find)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, CanSetZoomType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, CanSetZoomType)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->CanSetZoomType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetZoom)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetZoom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, GetZoomType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, GetZoomType)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetZoomType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, SetZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "zoom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, SetZoom)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int zoom = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebView, SetZoomType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "zoomType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, SetZoomType)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int zoomType = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoomType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebView)
{
	Gura_AssignMethod(wx_WebView, Create);
	Gura_AssignMethod(wx_WebView, New);
	Gura_AssignMethod(wx_WebView, New_1);
	Gura_AssignMethod(wx_WebView, RegisterFactory);
	Gura_AssignMethod(wx_WebView, GetCurrentTitle);
	Gura_AssignMethod(wx_WebView, GetCurrentURL);
	Gura_AssignMethod(wx_WebView, GetNativeBackend);
	Gura_AssignMethod(wx_WebView, GetPageSource);
	Gura_AssignMethod(wx_WebView, GetPageText);
	Gura_AssignMethod(wx_WebView, IsBusy);
	Gura_AssignMethod(wx_WebView, IsEditable);
	Gura_AssignMethod(wx_WebView, LoadURL);
	Gura_AssignMethod(wx_WebView, Print);
	Gura_AssignMethod(wx_WebView, RegisterHandler);
	Gura_AssignMethod(wx_WebView, Reload);
	Gura_AssignMethod(wx_WebView, RunScript);
	Gura_AssignMethod(wx_WebView, SetEditable);
	Gura_AssignMethod(wx_WebView, SetPage);
	Gura_AssignMethod(wx_WebView, SetPage_1);
	Gura_AssignMethod(wx_WebView, Stop);
	Gura_AssignMethod(wx_WebView, CanCopy);
	Gura_AssignMethod(wx_WebView, CanCut);
	Gura_AssignMethod(wx_WebView, CanPaste);
	Gura_AssignMethod(wx_WebView, Copy);
	Gura_AssignMethod(wx_WebView, Cut);
	Gura_AssignMethod(wx_WebView, Paste);
	Gura_AssignMethod(wx_WebView, EnableContextMenu);
	Gura_AssignMethod(wx_WebView, IsContextMenuEnabled);
	Gura_AssignMethod(wx_WebView, CanGoBack);
	Gura_AssignMethod(wx_WebView, CanGoForward);
	Gura_AssignMethod(wx_WebView, ClearHistory);
	Gura_AssignMethod(wx_WebView, EnableHistory);
	Gura_AssignMethod(wx_WebView, GetBackwardHistory);
	Gura_AssignMethod(wx_WebView, GetForwardHistory);
	Gura_AssignMethod(wx_WebView, GoBack);
	Gura_AssignMethod(wx_WebView, GoForward);
	Gura_AssignMethod(wx_WebView, LoadHistoryItem);
	Gura_AssignMethod(wx_WebView, ClearSelection);
	Gura_AssignMethod(wx_WebView, DeleteSelection);
	Gura_AssignMethod(wx_WebView, GetSelectedSource);
	Gura_AssignMethod(wx_WebView, GetSelectedText);
	Gura_AssignMethod(wx_WebView, HasSelection);
	Gura_AssignMethod(wx_WebView, SelectAll);
	Gura_AssignMethod(wx_WebView, CanRedo);
	Gura_AssignMethod(wx_WebView, CanUndo);
	Gura_AssignMethod(wx_WebView, Redo);
	Gura_AssignMethod(wx_WebView, Undo);
	Gura_AssignMethod(wx_WebView, Find);
	Gura_AssignMethod(wx_WebView, CanSetZoomType);
	Gura_AssignMethod(wx_WebView, GetZoom);
	Gura_AssignMethod(wx_WebView, GetZoomType);
	Gura_AssignMethod(wx_WebView, SetZoom);
	Gura_AssignMethod(wx_WebView, SetZoomType);
}

Gura_ImplementDescendantCreator(wx_WebView)
{
	return new Object_wx_WebView((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
