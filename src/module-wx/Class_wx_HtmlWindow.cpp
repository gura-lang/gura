//----------------------------------------------------------------------------
// wxHtmlWindow
// extracted from htwindow.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(LoadFile);
Gura_DeclarePrivUserSymbol(LoadPage);
Gura_DeclarePrivUserSymbol(OnCellClicked);
Gura_DeclarePrivUserSymbol(OnCellMouseHover);
Gura_DeclarePrivUserSymbol(OnLinkClicked);
Gura_DeclarePrivUserSymbol(OnOpeningURL);
Gura_DeclarePrivUserSymbol(OnSetTitle);
Gura_DeclarePrivUserSymbol(ReadCustomization);
Gura_DeclarePrivUserSymbol(WriteCustomization);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlWindow: public wxHtmlWindow, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_HtmlWindow> _pObj;
public:
	inline wx_HtmlWindow() : wxHtmlWindow(), _pObj(nullptr) {}
	inline wx_HtmlWindow(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxHtmlWindow(parent, id, pos, size, style, name), _pObj(nullptr) {}
	//virtual bool LoadFile(const wxFileName& filename);
	//virtual bool LoadPage(const wxString& location);
	virtual bool OnCellClicked(wxHtmlCell *cell, wxCoord x, wxCoord y, const wxMouseEvent& event);
	virtual void OnCellMouseHover(wxHtmlCell *cell, wxCoord x, wxCoord y);
	virtual void OnLinkClicked(const wxHtmlLinkInfo& link);
	virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType type, const wxString& url, wxString * redirect);
	virtual void OnSetTitle(const wxString& title);
	//virtual void ReadCustomization(wxConfigBase *cfg, wxString path);
	//virtual void WriteCustomization(wxConfigBase *cfg, wxString path);
	~wx_HtmlWindow();
	inline void AssocWithGura(Object_wx_HtmlWindow *pObj) {
		_pObj.reset(Object_wx_HtmlWindow::Reference(pObj));
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
public:
	// reveal private or protected member functions to public
	bool _OnCellClicked(wxHtmlCell *cell, wxCoord x, wxCoord y, const wxMouseEvent& event) {
		return wxHtmlWindow::OnCellClicked(cell, x, y, event);
	}
	void _OnCellMouseHover(wxHtmlCell *cell, wxCoord x, wxCoord y) {
		wxHtmlWindow::OnCellMouseHover(cell, x, y);
	}
	void _OnLinkClicked(const wxHtmlLinkInfo& link) {
		wxHtmlWindow::OnLinkClicked(link);
	}
	wxHtmlOpeningStatus _OnOpeningURL(wxHtmlURLType type, const wxString& url, wxString * redirect) {
		return wxHtmlWindow::OnOpeningURL(type, url, redirect);
	}
	void _OnSetTitle(const wxString& title) {
		wxHtmlWindow::OnSetTitle(title);
	}
};

wx_HtmlWindow::~wx_HtmlWindow()
{
}

void wx_HtmlWindow::GuraObjectDeleted()
{
}

bool wx_HtmlWindow::OnCellClicked(wxHtmlCell *cell, wxCoord x, wxCoord y, const wxMouseEvent& event)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnCellClicked);
	if (pFunc == nullptr) return wxHtmlWindow::OnCellClicked(cell, x, y, event);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(4);
	valList.push_back(Value(new Object_wx_HtmlCell(cell, nullptr, OwnerFalse)));
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	valList.push_back(Value(new Object_wx_MouseEvent(const_cast<wxMouseEvent *>(&event), nullptr, OwnerTrue)));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

void wx_HtmlWindow::OnCellMouseHover(wxHtmlCell *cell, wxCoord x, wxCoord y)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnCellMouseHover);
	if (pFunc == nullptr) {
		wxHtmlWindow::OnCellMouseHover(cell, x, y);
		return;
	}
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(new Object_wx_HtmlCell(cell, nullptr, OwnerFalse)));
	valList.push_back(Value(x));
	valList.push_back(Value(y));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	CheckMethodResult(_pObj->GetSignal());
}

void wx_HtmlWindow::OnLinkClicked(const wxHtmlLinkInfo& link)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnLinkClicked);
	if (pFunc == nullptr) {
		wxHtmlWindow::OnLinkClicked(link);
		return;
	}
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(new Object_wx_HtmlLinkInfo(const_cast<wxHtmlLinkInfo *>(&link), nullptr, OwnerTrue)));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	CheckMethodResult(_pObj->GetSignal());
}

wxHtmlOpeningStatus wx_HtmlWindow::OnOpeningURL(wxHtmlURLType type, const wxString& url, wxString * redirect)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnOpeningURL);
	if (pFunc == nullptr) return wxHtmlWindow::OnOpeningURL(type, url, redirect);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(type));
	valList.push_back(Value(url.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_list)) return wxHTML_OPEN;
	const ValueList &valListRtn = rtn.GetList();
	if (valListRtn.size() != 2) {
		_pObj->GetSignal().SetError(ERR_ValueError, "a list of two elements is expected");
		return wxHTML_OPEN;
	}
	if (!valListRtn[0].Is_number() || valListRtn[1].Is_string()) {
		_pObj->GetSignal().SetError(ERR_ValueError, "unexpected result type");
		return wxHTML_OPEN;
	}
	*redirect = wxString::FromUTF8(valListRtn[1].GetString());
	return static_cast<wxHtmlOpeningStatus>(valListRtn[0].GetInt());
}

void wx_HtmlWindow::OnSetTitle(const wxString& title)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnSetTitle);
	if (pFunc == nullptr) {
		wxHtmlWindow::OnSetTitle(title);
		return;
	}
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(title.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	CheckMethodResult(_pObj->GetSignal());
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlWindowEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlWindowEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_HtmlWindow *pEntity = new wx_HtmlWindow();
	Object_wx_HtmlWindow *pObj = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(HtmlWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlWindow)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = -1;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxHW_DEFAULT_STYLE;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxT("htmlWindow");
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	wx_HtmlWindow *pEntity = new wx_HtmlWindow(parent, id, *pos, *size, style, name);
	Object_wx_HtmlWindow *pObj = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareClassMethod(wx_HtmlWindow, AddFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filter", VTYPE_wx_HtmlFilter, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_HtmlWindow, AddFilter)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxHtmlFilter *filter = Object_wx_HtmlFilter::GetObject(arg, 0)->GetEntity();
	wxHtmlWindow::AddFilter(filter);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, AppendToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "source", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, AppendToPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString source = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->AppendToPage(source);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, GetInternalRepresentation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, GetInternalRepresentation)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pThis->GetEntity()->GetInternalRepresentation();
	return ReturnValue(env, arg, Value(new Object_wx_HtmlContainerCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWindow, GetOpenedAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, GetOpenedAnchor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetOpenedAnchor();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWindow, GetOpenedPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, GetOpenedPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetOpenedPage();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWindow, GetOpenedPageTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, GetOpenedPageTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetOpenedPageTitle();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWindow, GetRelatedFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, GetRelatedFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame *rtn = (wxFrame *)pThis->GetEntity()->GetRelatedFrame();
	return ReturnValue(env, arg, Value(new Object_wx_Frame(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryBack)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HistoryBack();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryCanBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryCanBack)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HistoryCanBack();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryCanForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryCanForward)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HistoryCanForward();
	return ReturnValue(env, arg, Value(rtn));
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
	pThis->GetEntity()->HistoryClear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, HistoryForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, HistoryForward)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HistoryForward();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_wx_FileName, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileName *filename = Object_wx_FileName::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->LoadFile(*filename);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, LoadPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, LoadPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->LoadPage(location);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, OnCellClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cell", VTYPE_wx_HtmlCell, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_MouseEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, OnCellClicked)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlCell *cell = Object_wx_HtmlCell::GetObject(arg, 0)->GetEntity();
	wxCoord x = static_cast<wxCoord>(arg.GetInt(1));
	wxCoord y = static_cast<wxCoord>(arg.GetInt(2));
	wxMouseEvent *event = Object_wx_MouseEvent::GetObject(arg, 3)->GetEntity();
	bool rtn = ((wx_HtmlWindow *)pThis->GetEntity())->_OnCellClicked(cell, x, y, *event);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, OnCellMouseHover)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cell", VTYPE_wx_HtmlCell, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnCellMouseHover)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlCell *cell = Object_wx_HtmlCell::GetObject(arg, 0)->GetEntity();
	wxCoord x = static_cast<wxCoord>(arg.GetInt(1));
	wxCoord y = static_cast<wxCoord>(arg.GetInt(2));
	((wx_HtmlWindow *)pThis->GetEntity())->_OnCellMouseHover(cell, x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, OnLinkClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "link", VTYPE_wx_HtmlLinkInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnLinkClicked)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlLinkInfo *link = Object_wx_HtmlLinkInfo::GetObject(arg, 0)->GetEntity();
	((wx_HtmlWindow *)pThis->GetEntity())->_OnLinkClicked(*link);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, OnOpeningURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, OnOpeningURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlURLType type = static_cast<wxHtmlURLType>(arg.GetInt(0));
	wxString url = wxString::FromUTF8(arg.GetString(1));
	wxString redirect;
	wxHtmlOpeningStatus rtn = ((wx_HtmlWindow *)pThis->GetEntity())->_OnOpeningURL(type, url, &redirect);
	return ReturnValue(env, arg, Value::CreateList(env,
							Value(rtn), Value(redirect.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWindow, OnSetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, OnSetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString title = wxString::FromUTF8(arg.GetString(0));
	((wx_HtmlWindow *)pThis->GetEntity())->_OnSetTitle(title);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, ReadCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, ReadCustomization)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(arg, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (arg.IsValid(1)) path = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->ReadCustomization(cfg, path);
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
	pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SelectionToText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, SelectionToText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->SelectionToText();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWindow, SelectLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SelectLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pos = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SelectLine(*pos);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SelectWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SelectWord)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pos = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SelectWord(*pos);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetBorders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetBorders)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int b = arg.GetInt(0);
	pThis->GetEntity()->SetBorders(b);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "normal_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fixed_face", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "sizes", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
}

Gura_ImplementMethod(wx_HtmlWindow, SetFonts)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString normal_face = wxString::FromUTF8(arg.GetString(0));
	wxString fixed_face = wxString::FromUTF8(arg.GetString(1));
	int *sizes = nullptr;
	int sizesBuff[7] = { 0, 0, 0, 0, 0, 0, 0 };
	if (arg.IsValid(2)) {
		if (arg.GetList(2).size() != 7) {
			sig.SetError(ERR_ValueError, "sizes must contain seven numbers");
			return Value::Nil;
		}
		size_t i = 0;
		foreach_const (ValueList, pValue, arg.GetList(2)) {
			const Value &value = *pValue;
			sizes[i++] = value.GetInt();
		}
		sizes = sizesBuff;
	}
	pThis->GetEntity()->SetFonts(normal_face, fixed_face, sizes);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "source", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, SetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString source = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->SetPage(source);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlWindow, SetRelatedFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetRelatedFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame *frame = Object_wx_Frame::GetObject(arg, 0)->GetEntity();
	wxString format = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetRelatedFrame(frame, format);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, SetRelatedStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindow, SetRelatedStatusBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int bar = arg.GetInt(0);
	pThis->GetEntity()->SetRelatedStatusBar(bar);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindow, ToText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, ToText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->ToText();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlWindow, WriteCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlWindow, WriteCustomization)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindow *pThis = Object_wx_HtmlWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(arg, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (arg.IsValid(1)) path = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->WriteCustomization(cfg, path);
	return Value::Nil;
}

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
// Class implementation for wxHtmlWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindow)
{
	Gura_RealizeUserSymbol(LoadFile);
	Gura_RealizeUserSymbol(LoadPage);
	Gura_RealizeUserSymbol(OnCellClicked);
	Gura_RealizeUserSymbol(OnCellMouseHover);
	Gura_RealizeUserSymbol(OnLinkClicked);
	Gura_RealizeUserSymbol(OnOpeningURL);
	Gura_RealizeUserSymbol(OnSetTitle);
	Gura_RealizeUserSymbol(ReadCustomization);
	Gura_RealizeUserSymbol(WriteCustomization);
	Gura_AssignFunction(HtmlWindowEmpty);
	Gura_AssignFunction(HtmlWindow);
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
	Gura_AssignMethod(wx_HtmlWindow, OnCellClicked);
	Gura_AssignMethod(wx_HtmlWindow, OnCellMouseHover);
	Gura_AssignMethod(wx_HtmlWindow, OnLinkClicked);
	Gura_AssignMethod(wx_HtmlWindow, OnOpeningURL);
	Gura_AssignMethod(wx_HtmlWindow, OnSetTitle);
	Gura_AssignMethod(wx_HtmlWindow, ReadCustomization);
	Gura_AssignMethod(wx_HtmlWindow, SelectAll);
	Gura_AssignMethod(wx_HtmlWindow, SelectionToText);
	Gura_AssignMethod(wx_HtmlWindow, SelectLine);
	Gura_AssignMethod(wx_HtmlWindow, SelectWord);
	Gura_AssignMethod(wx_HtmlWindow, SetBorders);
	Gura_AssignMethod(wx_HtmlWindow, SetFonts);
	Gura_AssignMethod(wx_HtmlWindow, SetPage);
	Gura_AssignMethod(wx_HtmlWindow, SetRelatedFrame);
	Gura_AssignMethod(wx_HtmlWindow, SetRelatedStatusBar);
	Gura_AssignMethod(wx_HtmlWindow, ToText);
	Gura_AssignMethod(wx_HtmlWindow, WriteCustomization);
}

Gura_ImplementDescendantCreator(wx_HtmlWindow)
{
	return new Object_wx_HtmlWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
