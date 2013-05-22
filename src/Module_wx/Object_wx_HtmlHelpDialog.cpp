//----------------------------------------------------------------------------
// wxHtmlHelpDialog
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AddToolbarButtons);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlHelpDialog: public wxHtmlHelpDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlHelpDialog *_pObj;
public:
	//inline wx_HtmlHelpDialog(wxHtmlHelpData* data) : wxHtmlHelpDialog(data), _sig(NULL), _pObj(NULL) {}
	//inline wx_HtmlHelpDialog(wxWindow* parent, int wxWindowID, const wxString& title, int style, wxHtmlHelpData* data) : wxHtmlHelpDialog(parent, wxWindowID, title, style, data), _sig(NULL), _pObj(NULL) {}
	//virtual void AddToolbarButtons(wxToolBar * toolBar, int style);
	~wx_HtmlHelpDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlHelpDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlHelpDialog::~wx_HtmlHelpDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlHelpDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlHelpDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpDialog));
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlHelpDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxHtmlHelpData *data = (wxHtmlHelpData *)(NULL);
	if (args.IsValid(0)) data = Object_wx_HtmlHelpData::GetObject(args, 0)->GetEntity();
	wx_HtmlHelpDialog *pEntity = new wx_HtmlHelpDialog(data);
	Object_wx_HtmlHelpDialog *pObj = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlHelpDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(HtmlHelpDialog_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "wxWindowID", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_HtmlHelpData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlHelpDialog_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int wxWindowID = args.GetInt(1);
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	int style = wxHF_DEFAULT_STYLE;
	if (args.IsValid(3)) style = args.GetInt(3);
	wxHtmlHelpData *data = (wxHtmlHelpData *)(NULL);
	if (args.IsValid(4)) data = Object_wx_HtmlHelpData::GetObject(args, 4)->GetEntity();
	wx_HtmlHelpDialog *pEntity = new wx_HtmlHelpDialog(parent, wxWindowID, title, style, data);
	Object_wx_HtmlHelpDialog *pObj = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlHelpDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, AddToolbarButtons)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "toolBar", VTYPE_wx_ToolBar, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlHelpDialog, AddToolbarButtons)
{
#if 0
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxToolBar *toolBar = Object_wx_ToolBar::GetObject(args, 0)->GetEntity();
	int style = args.GetInt(1);
	pThis->GetEntity()->AddToolbarButtons(toolBar, style);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, Create)
{
#if 0
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxEmptyString;
	if (args.IsValid(2)) title = wxString::FromUTF8(args.GetString(2));
	int style = wxHF_DEFAULT_STYLE;
	if (args.IsValid(3)) style = args.GetInt(3);
	bool rtn = pThis->GetEntity()->Create(parent, id, title, style);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, GetController)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, GetController)
{
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpController *rtn = (wxHtmlHelpController *)pThis->GetEntity()->GetController();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlHelpController(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlHelpDialog, ReadCustomization)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlHelpDialog, ReadCustomization)
{
#if 0
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->ReadCustomization(cfg, path);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, SetController)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "contoller", VTYPE_wx_HtmlHelpController, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlHelpDialog, SetController)
{
#if 0
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlHelpController *contoller = Object_wx_HtmlHelpController::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetController(contoller);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, SetTitleFormat)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlHelpDialog, SetTitleFormat)
{
#if 0
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString format = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTitleFormat(format);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, WriteCustomization)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "cfg", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_HtmlHelpDialog, WriteCustomization)
{
#if 0
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *cfg = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxString path = wxEmptyString;
	if (args.IsValid(1)) path = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->WriteCustomization(cfg, path);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Object_wx_HtmlHelpDialog::~Object_wx_HtmlHelpDialog()
{
}

Object *Object_wx_HtmlHelpDialog::Clone() const
{
	return NULL;
}

String Object_wx_HtmlHelpDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlHelpDialog:");
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
// Class implementation for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpDialog)
{
	Gura_RealizeUserSymbol(AddToolbarButtons);
	Gura_AssignFunction(HtmlHelpDialog);
	Gura_AssignFunction(HtmlHelpDialog_1);
	Gura_AssignMethod(wx_HtmlHelpDialog, AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpDialog, Create);
	Gura_AssignMethod(wx_HtmlHelpDialog, GetController);
	Gura_AssignMethod(wx_HtmlHelpDialog, ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpDialog, SetController);
	Gura_AssignMethod(wx_HtmlHelpDialog, SetTitleFormat);
	Gura_AssignMethod(wx_HtmlHelpDialog, WriteCustomization);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpDialog)
{
	return new Object_wx_HtmlHelpDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
