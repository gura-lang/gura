//----------------------------------------------------------------------------
// wxHelpController
// extracted from helpinst.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Initialize);
Gura_DeclarePrivUserSymbol(Initialize_1);
Gura_DeclarePrivUserSymbol(DisplayBlock);
Gura_DeclarePrivUserSymbol(DisplayContents);
Gura_DeclarePrivUserSymbol(DisplayContextPopup);
Gura_DeclarePrivUserSymbol(DisplaySection);
Gura_DeclarePrivUserSymbol(DisplaySection_1);
Gura_DeclarePrivUserSymbol(DisplayTextPopup);
Gura_DeclarePrivUserSymbol(GetFrameParameters);
Gura_DeclarePrivUserSymbol(GetParentWindow);
Gura_DeclarePrivUserSymbol(KeywordSearch);
Gura_DeclarePrivUserSymbol(LoadFile);
Gura_DeclarePrivUserSymbol(OnQuit);
Gura_DeclarePrivUserSymbol(SetFrameParameters);
Gura_DeclarePrivUserSymbol(SetParentWindow);
Gura_DeclarePrivUserSymbol(SetViewer);
Gura_DeclarePrivUserSymbol(Quit);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HelpController: public wxHelpController, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HelpController *_pObj;
public:
#if defined(__WXMSW__)
	inline wx_HelpController(wxWindow* parentWindow) : wxHelpController(parentWindow), _sig(NULL), _pObj(NULL) {}
#else
	inline wx_HelpController(wxWindow* parentWindow) : wxHelpController(wxHF_DEFAULT_STYLE, parentWindow), _sig(NULL), _pObj(NULL) {}
#endif
	//virtual bool Initialize(const wxString& file);
	//virtual bool Initialize(const wxString& file, int server);
	//virtual bool DisplayBlock(long blockNo);
	//virtual bool DisplayContents();
	//virtual bool DisplayContextPopup(int contextId);
	//virtual bool DisplaySection(const wxString& section);
	//virtual bool DisplaySection(int sectionNo);
	//virtual bool DisplayTextPopup(const wxString& text, const wxPoint& pos);
	//virtual wxFrame * GetFrameParameters(const wxSize * size, const wxPoint * pos, bool * newFrameEachTime);
	//virtual wxWindow* GetParentWindow();
	//virtual bool KeywordSearch(const wxString& keyWord, wxHelpSearchMode mode);
	//virtual bool LoadFile(const wxString& file);
	//virtual bool OnQuit();
	//virtual void SetFrameParameters(const wxString & title, const wxSize & size, const wxPoint & pos, bool newFrameEachTime);
	//virtual void SetParentWindow(wxWindow* parentWindow);
	//virtual void SetViewer(const wxString& viewer, long flags);
	//virtual bool Quit();
	~wx_HelpController();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HelpController *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HelpController::~wx_HelpController()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HelpController::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpController
//----------------------------------------------------------------------------
Gura_DeclareFunction(HelpController)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HelpController));
	DeclareArg(env, "parentWindow", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HelpController)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parentWindow = (wxWindow *)(NULL);
	if (args.IsValid(0)) parentWindow = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wx_HelpController *pEntity = new wx_HelpController(parentWindow);
	Object_wx_HelpController *pObj = Object_wx_HelpController::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HelpController(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HelpController, Initialize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, Initialize)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Initialize(file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, Initialize_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "server", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, Initialize_1)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	int server = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Initialize(file, server);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, DisplayBlock)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "blockNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, DisplayBlock)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long blockNo = args.GetLong(0);
	bool rtn = pThis->GetEntity()->DisplayBlock(blockNo);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, DisplayContents)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, DisplayContents)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DisplayContents();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, DisplayContextPopup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "contextId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, DisplayContextPopup)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int contextId = args.GetInt(0);
	bool rtn = pThis->GetEntity()->DisplayContextPopup(contextId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, DisplaySection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, DisplaySection)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString section = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->DisplaySection(section);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, DisplaySection_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sectionNo", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, DisplaySection_1)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int sectionNo = args.GetInt(0);
	bool rtn = pThis->GetEntity()->DisplaySection(sectionNo);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, DisplayTextPopup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, DisplayTextPopup)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxPoint *pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DisplayTextPopup(text, *pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, GetFrameParameters)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "newFrameEachTime", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, GetFrameParameters)
{
#if 0
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = (wxSize *)(NULL);
	if (args.IsValid(0)) size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wxPoint *pos = (wxPoint *)(NULL);
	if (args.IsValid(1)) pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	bool newFrameEachTime = NULL;
	if (args.IsValid(2)) newFrameEachTime = args.GetBoolean(2);
	wxFrame *rtn = (wxFrame *)pThis->GetEntity()->GetFrameParameters(size, pos, newFrameEachTime);
	return ReturnValue(env, sig, args, Value(new Object_wx_Frame(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpController, GetParentWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, GetParentWindow)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetParentWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HelpController, KeywordSearch)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "keyWord", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, KeywordSearch)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString keyWord = wxString::FromUTF8(args.GetString(0));
	wxHelpSearchMode mode = wxHELP_SEARCH_ALL;
	if (args.IsValid(1)) mode = static_cast<wxHelpSearchMode>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->KeywordSearch(keyWord, mode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, LoadFile)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString file = wxT("");
	if (args.IsValid(0)) file = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->LoadFile(file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HelpController, OnQuit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, OnQuit)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnQuit();
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpController, SetFrameParameters)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "newFrameEachTime", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, SetFrameParameters)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	wxSize *size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	bool newFrameEachTime = false;
	if (args.IsValid(3)) newFrameEachTime = args.GetBoolean(3);
	pThis->GetEntity()->SetFrameParameters(title, *size, *pos, newFrameEachTime);
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpController, SetParentWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parentWindow", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpController, SetParentWindow)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parentWindow = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetParentWindow(parentWindow);
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpController, SetViewer)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "viewer", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpController, SetViewer)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString viewer = wxString::FromUTF8(args.GetString(0));
	long flags = args.GetLong(1);
	pThis->GetEntity()->SetViewer(viewer, flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_HelpController, Quit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HelpController, Quit)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Quit();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxHelpController
//----------------------------------------------------------------------------
Object_wx_HelpController::~Object_wx_HelpController()
{
}

Object *Object_wx_HelpController::Clone() const
{
	return NULL;
}

String Object_wx_HelpController::ToString(bool exprFlag)
{
	String rtn("<wx.HelpController:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpController)
{
	Gura_RealizeUserSymbol(Initialize);
	Gura_RealizeUserSymbol(Initialize_1);
	Gura_RealizeUserSymbol(DisplayBlock);
	Gura_RealizeUserSymbol(DisplayContents);
	Gura_RealizeUserSymbol(DisplayContextPopup);
	Gura_RealizeUserSymbol(DisplaySection);
	Gura_RealizeUserSymbol(DisplaySection_1);
	Gura_RealizeUserSymbol(DisplayTextPopup);
	Gura_RealizeUserSymbol(GetFrameParameters);
	Gura_RealizeUserSymbol(GetParentWindow);
	Gura_RealizeUserSymbol(KeywordSearch);
	Gura_RealizeUserSymbol(LoadFile);
	Gura_RealizeUserSymbol(OnQuit);
	Gura_RealizeUserSymbol(SetFrameParameters);
	Gura_RealizeUserSymbol(SetParentWindow);
	Gura_RealizeUserSymbol(SetViewer);
	Gura_RealizeUserSymbol(Quit);
	Gura_AssignFunction(HelpController);
	Gura_AssignMethod(wx_HelpController, Initialize);
	Gura_AssignMethod(wx_HelpController, Initialize_1);
	Gura_AssignMethod(wx_HelpController, DisplayBlock);
	Gura_AssignMethod(wx_HelpController, DisplayContents);
	Gura_AssignMethod(wx_HelpController, DisplayContextPopup);
	Gura_AssignMethod(wx_HelpController, DisplaySection);
	Gura_AssignMethod(wx_HelpController, DisplaySection_1);
	Gura_AssignMethod(wx_HelpController, DisplayTextPopup);
	Gura_AssignMethod(wx_HelpController, GetFrameParameters);
	Gura_AssignMethod(wx_HelpController, GetParentWindow);
	Gura_AssignMethod(wx_HelpController, KeywordSearch);
	Gura_AssignMethod(wx_HelpController, LoadFile);
	Gura_AssignMethod(wx_HelpController, OnQuit);
	Gura_AssignMethod(wx_HelpController, SetFrameParameters);
	Gura_AssignMethod(wx_HelpController, SetParentWindow);
	Gura_AssignMethod(wx_HelpController, SetViewer);
	Gura_AssignMethod(wx_HelpController, Quit);
}

Gura_ImplementDescendantCreator(wx_HelpController)
{
	return new Object_wx_HelpController((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
