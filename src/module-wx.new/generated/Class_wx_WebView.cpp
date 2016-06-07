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
Gura_DeclareMethodAlias(wx_WebView, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __Create)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& url = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, url, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __New, "New")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "backend", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __New)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& backend = arg.GetNumber(0)
	//wxWebView* _rtn = pThis->GetEntity()->New(backend);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __New_1, "New_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "backend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __New_1)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& url = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//const wxString& backend = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxWebView* _rtn = pThis->GetEntity()->New(parent, id, url, pos, size, backend, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __RegisterFactory, "RegisterFactory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "backend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "factory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __RegisterFactory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& backend = arg.GetNumber(0)
	//wxSharedPtr<wxWebViewFactory> factory = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterFactory(backend, factory);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetCurrentTitle, "GetCurrentTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetCurrentTitle)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetCurrentTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetCurrentURL, "GetCurrentURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetCurrentURL)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetCurrentURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetNativeBackend, "GetNativeBackend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetNativeBackend)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* _rtn = pThis->GetEntity()->GetNativeBackend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetPageSource, "GetPageSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetPageSource)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetPageSource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetPageText, "GetPageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetPageText)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetPageText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __IsBusy, "IsBusy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __IsBusy)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsBusy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __IsEditable, "IsEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __IsEditable)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __LoadURL, "LoadURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __LoadURL)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url = arg.GetNumber(0)
	//pThis->GetEntity()->LoadURL(url);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Print, "Print")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __Print)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Print();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __RegisterHandler, "RegisterHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __RegisterHandler)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSharedPtr<wxWebViewHandler> handler = arg.GetNumber(0)
	//pThis->GetEntity()->RegisterHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Reload, "Reload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __Reload)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWebViewReloadFlags flags = arg.GetNumber(0)
	//pThis->GetEntity()->Reload(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __RunScript, "RunScript")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "javascript", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __RunScript)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& javascript = arg.GetNumber(0)
	//pThis->GetEntity()->RunScript(javascript);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __SetEditable, "SetEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __SetEditable)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __SetPage, "SetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseUrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __SetPage)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& html = arg.GetNumber(0)
	//const wxString& baseUrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetPage(html, baseUrl);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __SetPage_1, "SetPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseUrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __SetPage_1)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream& html = arg.GetNumber(0)
	//wxString baseUrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetPage(html, baseUrl);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Stop, "Stop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __Stop)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanCopy, "CanCopy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __CanCopy)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanCopy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanCut, "CanCut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __CanCut)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanCut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanPaste, "CanPaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __CanPaste)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __Copy)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Cut, "Cut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __Cut)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Paste, "Paste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __Paste)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __EnableContextMenu, "EnableContextMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __EnableContextMenu)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableContextMenu(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __IsContextMenuEnabled, "IsContextMenuEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __IsContextMenuEnabled)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsContextMenuEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanGoBack, "CanGoBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __CanGoBack)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanGoBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanGoForward, "CanGoForward")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __CanGoForward)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanGoForward();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __ClearHistory, "ClearHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __ClearHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __EnableHistory, "EnableHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __EnableHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableHistory(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetBackwardHistory, "GetBackwardHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetBackwardHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVector<wxSharedPtr<wxWebViewHistoryItem> > _rtn = pThis->GetEntity()->GetBackwardHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetForwardHistory, "GetForwardHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetForwardHistory)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVector<wxSharedPtr<wxWebViewHistoryItem> > _rtn = pThis->GetEntity()->GetForwardHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GoBack, "GoBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GoBack)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GoBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GoForward, "GoForward")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GoForward)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GoForward();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __LoadHistoryItem, "LoadHistoryItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __LoadHistoryItem)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSharedPtr<wxWebViewHistoryItem> item = arg.GetNumber(0)
	//pThis->GetEntity()->LoadHistoryItem(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __ClearSelection, "ClearSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __ClearSelection)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __DeleteSelection, "DeleteSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __DeleteSelection)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetSelectedSource, "GetSelectedSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetSelectedSource)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetSelectedSource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetSelectedText, "GetSelectedText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetSelectedText)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetSelectedText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __HasSelection, "HasSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __HasSelection)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __SelectAll)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanRedo, "CanRedo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __CanRedo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanUndo, "CanUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __CanUndo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Redo, "Redo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __Redo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __Undo)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __Find, "Find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __Find)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxWebViewFindFlags flags = arg.GetNumber(1)
	//long _rtn = pThis->GetEntity()->Find(text, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __CanSetZoomType, "CanSetZoomType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __CanSetZoomType)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWebViewZoomType type = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CanSetZoomType(type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetZoom, "GetZoom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetZoom)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWebViewZoom _rtn = pThis->GetEntity()->GetZoom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __GetZoomType, "GetZoomType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WebView, __GetZoomType)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWebViewZoomType _rtn = pThis->GetEntity()->GetZoomType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __SetZoom, "SetZoom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "zoom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __SetZoom)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWebViewZoom zoom = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoom(zoom);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebView, __SetZoomType, "SetZoomType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "zoomType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebView, __SetZoomType)
{
	Object_wx_WebView *pThis = Object_wx_WebView::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWebViewZoomType zoomType = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoomType(zoomType);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebView)
{
	// Class assignment
	Gura_AssignValueEx("WebView", Reference());
	// Method assignment
	Gura_AssignMethod(wx_WebView, __Create);
	Gura_AssignMethod(wx_WebView, __New);
	Gura_AssignMethod(wx_WebView, __New_1);
	Gura_AssignMethod(wx_WebView, __RegisterFactory);
	Gura_AssignMethod(wx_WebView, __GetCurrentTitle);
	Gura_AssignMethod(wx_WebView, __GetCurrentURL);
	Gura_AssignMethod(wx_WebView, __GetNativeBackend);
	Gura_AssignMethod(wx_WebView, __GetPageSource);
	Gura_AssignMethod(wx_WebView, __GetPageText);
	Gura_AssignMethod(wx_WebView, __IsBusy);
	Gura_AssignMethod(wx_WebView, __IsEditable);
	Gura_AssignMethod(wx_WebView, __LoadURL);
	Gura_AssignMethod(wx_WebView, __Print);
	Gura_AssignMethod(wx_WebView, __RegisterHandler);
	Gura_AssignMethod(wx_WebView, __Reload);
	Gura_AssignMethod(wx_WebView, __RunScript);
	Gura_AssignMethod(wx_WebView, __SetEditable);
	Gura_AssignMethod(wx_WebView, __SetPage);
	Gura_AssignMethod(wx_WebView, __SetPage_1);
	Gura_AssignMethod(wx_WebView, __Stop);
	Gura_AssignMethod(wx_WebView, __CanCopy);
	Gura_AssignMethod(wx_WebView, __CanCut);
	Gura_AssignMethod(wx_WebView, __CanPaste);
	Gura_AssignMethod(wx_WebView, __Copy);
	Gura_AssignMethod(wx_WebView, __Cut);
	Gura_AssignMethod(wx_WebView, __Paste);
	Gura_AssignMethod(wx_WebView, __EnableContextMenu);
	Gura_AssignMethod(wx_WebView, __IsContextMenuEnabled);
	Gura_AssignMethod(wx_WebView, __CanGoBack);
	Gura_AssignMethod(wx_WebView, __CanGoForward);
	Gura_AssignMethod(wx_WebView, __ClearHistory);
	Gura_AssignMethod(wx_WebView, __EnableHistory);
	Gura_AssignMethod(wx_WebView, __GetBackwardHistory);
	Gura_AssignMethod(wx_WebView, __GetForwardHistory);
	Gura_AssignMethod(wx_WebView, __GoBack);
	Gura_AssignMethod(wx_WebView, __GoForward);
	Gura_AssignMethod(wx_WebView, __LoadHistoryItem);
	Gura_AssignMethod(wx_WebView, __ClearSelection);
	Gura_AssignMethod(wx_WebView, __DeleteSelection);
	Gura_AssignMethod(wx_WebView, __GetSelectedSource);
	Gura_AssignMethod(wx_WebView, __GetSelectedText);
	Gura_AssignMethod(wx_WebView, __HasSelection);
	Gura_AssignMethod(wx_WebView, __SelectAll);
	Gura_AssignMethod(wx_WebView, __CanRedo);
	Gura_AssignMethod(wx_WebView, __CanUndo);
	Gura_AssignMethod(wx_WebView, __Redo);
	Gura_AssignMethod(wx_WebView, __Undo);
	Gura_AssignMethod(wx_WebView, __Find);
	Gura_AssignMethod(wx_WebView, __CanSetZoomType);
	Gura_AssignMethod(wx_WebView, __GetZoom);
	Gura_AssignMethod(wx_WebView, __GetZoomType);
	Gura_AssignMethod(wx_WebView, __SetZoom);
	Gura_AssignMethod(wx_WebView, __SetZoomType);
}

Gura_ImplementDescendantCreator(wx_WebView)
{
	return new Object_wx_WebView((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
