//----------------------------------------------------------------------------
// wxHtmlHelpFrame
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AddToolbarButtons);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlHelpFrame: public wxHtmlHelpFrame, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlHelpFrame *_pObj;
public:
	inline wx_HtmlHelpFrame(wxHtmlHelpData* data) : wxHtmlHelpFrame(data), _sig(NULL), _pObj(NULL) {}
	inline wx_HtmlHelpFrame(wxWindow* parent, int wxWindowID, const wxString& title, int style, wxHtmlHelpData* data) : wxHtmlHelpFrame(parent, wxWindowID, title, style, data), _sig(NULL), _pObj(NULL) {}
	//virtual void AddToolbarButtons(wxToolBar * toolBar, int style);
	~wx_HtmlHelpFrame();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlHelpFrame *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlHelpFrame::~wx_HtmlHelpFrame()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlHelpFrame::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlHelpFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpFrame));
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpFrame)
{
	wxHtmlHelpData *data = (wxHtmlHelpData *)(NULL);
	if (args.IsValid(0)) data = Object_wx_HtmlHelpData::GetObject(args, 0)->GetEntity();
	wx_HtmlHelpFrame *pEntity = new wx_HtmlHelpFrame(data);
	Object_wx_HtmlHelpFrame *pObj = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlHelpFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(HtmlHelpFrame_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpFrame));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "wxWindowID", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlHelpFrame_1)
{
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int wxWindowID = args.GetInt(1);
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	int style = wxHF_DEFAULT_STYLE;
	if (args.IsValid(3)) style = args.GetInt(3);
	wxHtmlHelpData *data = (wxHtmlHelpData *)(NULL);
	if (args.IsValid(4)) data = Object_wx_HtmlHelpData::GetObject(args, 4)->GetEntity();
	wx_HtmlHelpFrame *pEntity = new wx_HtmlHelpFrame(parent, wxWindowID, title, style, data);
	Object_wx_HtmlHelpFrame *pObj = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlHelpFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_HtmlHelpFrame, AddToolbarButtons)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "toolBar", VTYPE_wx_ToolBar, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, AddToolbarButtons)
{
	Object_wx_HtmlHelpFrame *pSelf = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxToolBar *toolBar = Object_wx_ToolBar::GetObject(args, 0)->GetEntity();
	int style = args.GetInt(1);
	pSelf->GetEntity()->AddToolbarButtons(toolBar, style);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, Create)
{
	Object_wx_HtmlHelpFrame *pSelf = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	int style = wxHF_DEFAULT_STYLE;
	if (args.IsValid(3)) style = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->Create(parent, id, title, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlHelpFrame, GetController)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, GetController)
{
	Object_wx_HtmlHelpFrame *pSelf = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpController *rtn = (wxHtmlHelpController *)pSelf->GetEntity()->GetController();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlHelpController(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlHelpFrame, ReadCustomization)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, ReadCustomization)
{
#if 0
	Object_wx_HtmlHelpFrame *pSelf = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pSelf->GetEntity()->ReadCustomization(cfg, path);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, SetController)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "contoller", VTYPE_wx_HtmlHelpController, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, SetController)
{
	Object_wx_HtmlHelpFrame *pSelf = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpController *contoller = Object_wx_HtmlHelpController::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetController(contoller);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, SetTitleFormat)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, SetTitleFormat)
{
	Object_wx_HtmlHelpFrame *pSelf = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString format = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetTitleFormat(format);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpFrame, WriteCustomization)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpFrame, WriteCustomization)
{
#if 0
	Object_wx_HtmlHelpFrame *pSelf = Object_wx_HtmlHelpFrame::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pSelf->GetEntity()->WriteCustomization(cfg, path);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Object_wx_HtmlHelpFrame::~Object_wx_HtmlHelpFrame()
{
}

Object *Object_wx_HtmlHelpFrame::Clone() const
{
	return NULL;
}

String Object_wx_HtmlHelpFrame::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlHelpFrame:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlHelpFrame::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(AddToolbarButtons);
	Gura_AssignFunction(HtmlHelpFrame);
	Gura_AssignFunction(HtmlHelpFrame_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpFrame)
{
	Gura_AssignMethod(wx_HtmlHelpFrame, AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpFrame, Create);
	Gura_AssignMethod(wx_HtmlHelpFrame, GetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpFrame, SetController);
	Gura_AssignMethod(wx_HtmlHelpFrame, SetTitleFormat);
	Gura_AssignMethod(wx_HtmlHelpFrame, WriteCustomization);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpFrame)
{
	return new Object_wx_HtmlHelpFrame((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
