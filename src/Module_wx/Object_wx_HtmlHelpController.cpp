//----------------------------------------------------------------------------
// wxHtmlHelpController
// extracted from hthelpct.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(CreateHelpDialog);
Gura_DeclarePrivUserSymbol(CreateHelpFrame);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlHelpController: public wxHtmlHelpController, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlHelpController *_pObj;
public:
	inline wx_HtmlHelpController(int style, wxWindow* parentWindow) : wxHtmlHelpController(style, parentWindow), _sig(NULL), _pObj(NULL) {}
	//virtual wxHtmlHelpDialog* CreateHelpDialog(wxHtmlHelpData * data);
	//virtual wxHtmlHelpFrame* CreateHelpFrame(wxHtmlHelpData * data);
	~wx_HtmlHelpController();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlHelpController *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlHelpController::~wx_HtmlHelpController()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlHelpController::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpController
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlHelpController)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpController));
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parentWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpController)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int style = wxHF_DEFAULT_STYLE;
	if (args.IsValid(0)) style = args.GetInt(0);
	wxWindow *parentWindow = (wxWindow *)(NULL);
	if (args.IsValid(1)) parentWindow = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wx_HtmlHelpController *pEntity = new wx_HtmlHelpController(style, parentWindow);
	Object_wx_HtmlHelpController *pObj = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlHelpController(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HtmlHelpController, AddBook)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bookFile", VTYPE_wx_FileName, OCCUR_Once);
	DeclareArg(env, "showWaitMsg", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, AddBook)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileName *bookFile = Object_wx_FileName::GetObject(args, 0)->GetEntity();
	bool showWaitMsg = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->AddBook(*bookFile, showWaitMsg);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpController, AddBook_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bookUrl", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "showWaitMsg", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, AddBook_1)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString bookUrl = wxString::FromUTF8(args.GetString(0));
	bool showWaitMsg = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->AddBook(bookUrl, showWaitMsg);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpController, CreateHelpDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, CreateHelpDialog)
{
#if 0
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpData *data = Object_wx_HtmlHelpData::GetObject(args, 0)->GetEntity();
	wxHtmlHelpDialog *rtn = (wxHtmlHelpDialog *)pThis->GetEntity()->CreateHelpDialog(data);
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlHelpDialog(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, CreateHelpFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, CreateHelpFrame)
{
#if 0
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpData *data = Object_wx_HtmlHelpData::GetObject(args, 0)->GetEntity();
	wxHtmlHelpFrame *rtn = (wxHtmlHelpFrame *)pThis->GetEntity()->CreateHelpFrame(data);
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlHelpFrame(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, Display)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, Display)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString x = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->Display(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, Display_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, Display_1)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pThis->GetEntity()->Display(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, DisplayContents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, DisplayContents)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisplayContents();
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, DisplayIndex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, DisplayIndex)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisplayIndex();
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, KeywordSearch)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "keyword", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, KeywordSearch)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString keyword = wxString::FromUTF8(args.GetString(0));
	wxHelpSearchMode mode = wxHELP_SEARCH_ALL;
	if (args.IsValid(1)) mode = static_cast<wxHelpSearchMode>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->KeywordSearch(keyword, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpController, ReadCustomization)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, ReadCustomization)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->ReadCustomization(cfg, path);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, SetTempDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, SetTempDir)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTempDir(path);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, SetTitleFormat)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, SetTitleFormat)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString format = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTitleFormat(format);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, UseConfig)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "config", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "rootpath", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, UseConfig)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *config = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString rootpath = wxEmptyString;
	if (args.IsValid(1)) rootpath = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->UseConfig(config, rootpath);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpController, WriteCustomization)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpController, WriteCustomization)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->WriteCustomization(cfg, path);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpController
//----------------------------------------------------------------------------
Object_wx_HtmlHelpController::~Object_wx_HtmlHelpController()
{
}

Object *Object_wx_HtmlHelpController::Clone() const
{
	return NULL;
}

String Object_wx_HtmlHelpController::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlHelpController:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlHelpController::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(CreateHelpDialog);
	Gura_RealizeUserSymbol(CreateHelpFrame);
	Gura_AssignFunction(HtmlHelpController);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpController)
{
	Gura_AssignMethod(wx_HtmlHelpController, AddBook);
	Gura_AssignMethod(wx_HtmlHelpController, AddBook_1);
	Gura_AssignMethod(wx_HtmlHelpController, CreateHelpDialog);
	Gura_AssignMethod(wx_HtmlHelpController, CreateHelpFrame);
	Gura_AssignMethod(wx_HtmlHelpController, Display);
	Gura_AssignMethod(wx_HtmlHelpController, Display_1);
	Gura_AssignMethod(wx_HtmlHelpController, DisplayContents);
	Gura_AssignMethod(wx_HtmlHelpController, DisplayIndex);
	Gura_AssignMethod(wx_HtmlHelpController, KeywordSearch);
	Gura_AssignMethod(wx_HtmlHelpController, ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpController, SetTempDir);
	Gura_AssignMethod(wx_HtmlHelpController, SetTitleFormat);
	Gura_AssignMethod(wx_HtmlHelpController, UseConfig);
	Gura_AssignMethod(wx_HtmlHelpController, WriteCustomization);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpController)
{
	return new Object_wx_HtmlHelpController((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
