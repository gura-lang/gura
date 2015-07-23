//----------------------------------------------------------------------------
// wxHtmlHelpWindow
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AddToolbarButtons);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlHelpWindow: public wxHtmlHelpWindow, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_HtmlHelpWindow *_pObj;
public:
	inline wx_HtmlHelpWindow(wxHtmlHelpData* data) : wxHtmlHelpWindow(data), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_HtmlHelpWindow(wxWindow* parent, int wxWindowID, const wxPoint& pos, const wxSize& size, int style, int helpStyle, wxHtmlHelpData* data) : wxHtmlHelpWindow(parent, wxWindowID, pos, size, style, helpStyle, data), _pSig(nullptr), _pObj(nullptr) {}
	//virtual void AddToolbarButtons(wxToolBar * toolBar, int style);
	~wx_HtmlHelpWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlHelpWindow *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlHelpWindow::~wx_HtmlHelpWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlHelpWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlHelpWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpWindow));
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpWindow)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxHtmlHelpData *data = (wxHtmlHelpData *)(nullptr);
	if (args.IsValid(0)) data = Object_wx_HtmlHelpData::GetObject(args, 0)->GetEntity();
	wx_HtmlHelpWindow *pEntity = new wx_HtmlHelpWindow(data);
	Object_wx_HtmlHelpWindow *pObj = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlHelpWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(HtmlHelpWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpWindow));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "wxWindowID", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpWindow_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int wxWindowID = args.GetInt(1);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	int style = wxTAB_TRAVERSAL|wxNO_BORDER;
	if (args.IsValid(4)) style = args.GetInt(4);
	int helpStyle = wxHF_DEFAULT_STYLE;
	if (args.IsValid(5)) helpStyle = args.GetInt(5);
	wxHtmlHelpData *data = (wxHtmlHelpData *)(nullptr);
	if (args.IsValid(6)) data = Object_wx_HtmlHelpData::GetObject(args, 6)->GetEntity();
	wx_HtmlHelpWindow *pEntity = new wx_HtmlHelpWindow(parent, wxWindowID, *pos, *size, style, helpStyle, data);
	Object_wx_HtmlHelpWindow *pObj = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlHelpWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_HtmlHelpWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "helpStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, Create)
{
#if 0
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	int style = wxTAB_TRAVERSAL|wxNO_BORDER;
	if (args.IsValid(4)) style = args.GetInt(4);
	int helpStyle = wxHF_DEFAULT_STYLE;
	if (args.IsValid(5)) helpStyle = args.GetInt(5);
	wxHtmlHelpData *data = (wxHtmlHelpData *)(nullptr);
	if (args.IsValid(6)) data = Object_wx_HtmlHelpData::GetObject(args, 6)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, helpStyle, data);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, CreateContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, CreateContents)
{
#if 0
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CreateContents();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, CreateIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, CreateIndex)
{
#if 0
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CreateIndex();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, CreateSearch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, CreateSearch)
{
#if 0
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CreateSearch();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, Display)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, Display)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString x = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Display(x);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpWindow, Display_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, Display_1)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Display(id);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpWindow, DisplayContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, DisplayContents)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DisplayContents();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpWindow, DisplayIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, DisplayIndex)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DisplayIndex();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpWindow, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, GetData)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpData *rtn = (wxHtmlHelpData *)pThis->GetEntity()->GetData();
	return ReturnValue(env, args, Value(new Object_wx_HtmlHelpData(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlHelpWindow, KeywordSearch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "keyword", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, KeywordSearch)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString keyword = wxString::FromUTF8(args.GetString(0));
	wxHelpSearchMode mode = wxHELP_SEARCH_ALL;
	if (args.IsValid(1)) mode = static_cast<wxHelpSearchMode>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->KeywordSearch(keyword, mode);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpWindow, ReadCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, ReadCustomization)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->ReadCustomization(cfg, path);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, RefreshLists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, RefreshLists)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->RefreshLists();
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, SetTitleFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, SetTitleFormat)
{
#if 0
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString format = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTitleFormat(format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, UseConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "config", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "rootpath", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, UseConfig)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *config = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString rootpath = wxEmptyString;
	if (args.IsValid(1)) rootpath = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->UseConfig(config, rootpath);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, WriteCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, WriteCustomization)
{
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->WriteCustomization(cfg, path);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpWindow, AddToolbarButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolBar", VTYPE_wx_ToolBar, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpWindow, AddToolbarButtons)
{
#if 0
	Object_wx_HtmlHelpWindow *pThis = Object_wx_HtmlHelpWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxToolBar *toolBar = Object_wx_ToolBar::GetObject(args, 0)->GetEntity();
	int style = args.GetInt(1);
	pThis->GetEntity()->AddToolbarButtons(toolBar, style);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpWindow
//----------------------------------------------------------------------------
Object_wx_HtmlHelpWindow::~Object_wx_HtmlHelpWindow()
{
}

Object *Object_wx_HtmlHelpWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpWindow:");
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
// Class implementation for wxHtmlHelpWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpWindow)
{
	Gura_RealizeUserSymbol(AddToolbarButtons);
	Gura_AssignFunction(HtmlHelpWindow);
	Gura_AssignFunction(HtmlHelpWindow_1);
	Gura_AssignMethod(wx_HtmlHelpWindow, Create);
	Gura_AssignMethod(wx_HtmlHelpWindow, CreateContents);
	Gura_AssignMethod(wx_HtmlHelpWindow, CreateIndex);
	Gura_AssignMethod(wx_HtmlHelpWindow, CreateSearch);
	Gura_AssignMethod(wx_HtmlHelpWindow, Display);
	Gura_AssignMethod(wx_HtmlHelpWindow, Display_1);
	Gura_AssignMethod(wx_HtmlHelpWindow, DisplayContents);
	Gura_AssignMethod(wx_HtmlHelpWindow, DisplayIndex);
	Gura_AssignMethod(wx_HtmlHelpWindow, GetData);
	Gura_AssignMethod(wx_HtmlHelpWindow, KeywordSearch);
	Gura_AssignMethod(wx_HtmlHelpWindow, ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpWindow, RefreshLists);
	Gura_AssignMethod(wx_HtmlHelpWindow, SetTitleFormat);
	Gura_AssignMethod(wx_HtmlHelpWindow, UseConfig);
	Gura_AssignMethod(wx_HtmlHelpWindow, WriteCustomization);
	Gura_AssignMethod(wx_HtmlHelpWindow, AddToolbarButtons);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpWindow)
{
	return new Object_wx_HtmlHelpWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
