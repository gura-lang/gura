//----------------------------------------------------------------------------
// wxProgressDialog
// extracted from progdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Update);
Gura_DeclarePrivUserSymbol(Pulse);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ProgressDialog: public wxProgressDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ProgressDialog *_pObj;
public:
	inline wx_ProgressDialog(const wxString& title, const wxString& message, int maximum, wxWindow * parent, int style) : wxProgressDialog(title, message, maximum, parent, style), _sig(NULL), _pObj(NULL) {}
	//virtual bool Update(int value, const wxString& newmsg, bool * skip);
	//virtual bool Pulse(const wxString& newmsg, bool * skip);
	~wx_ProgressDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ProgressDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ProgressDialog::~wx_ProgressDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ProgressDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxProgressDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(ProgressDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ProgressDialog));
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "maximum", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ProgressDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	wxString message = wxString::FromUTF8(args.GetString(1));
	int maximum = 100;
	if (args.IsValid(2)) maximum = args.GetInt(2);
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int style = wxPD_AUTO_HIDE | wxPD_APP_MODAL;
	if (args.IsValid(4)) style = args.GetInt(4);
	wx_ProgressDialog *pEntity = new wx_ProgressDialog(title, message, maximum, parent, style);
	Object_wx_ProgressDialog *pObj = Object_wx_ProgressDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ProgressDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ProgressDialog, Resume)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ProgressDialog, Resume)
{
	Object_wx_ProgressDialog *pThis = Object_wx_ProgressDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Resume();
	return Value::Null;
}

Gura_DeclareMethod(wx_ProgressDialog, Update)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "newmsg", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProgressDialog, Update)
{
	Object_wx_ProgressDialog *pThis = Object_wx_ProgressDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int value = args.GetInt(0);
	wxString newmsg = wxT("");
	if (args.IsValid(1)) newmsg = wxString::FromUTF8(args.GetString(1));
	bool skip = false;
	bool rtn = pThis->GetEntity()->Update(value, newmsg, &skip);
	return ReturnValue(env, sig, args, Value::CreateList(env, rtn, skip));
}

Gura_DeclareMethod(wx_ProgressDialog, Pulse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "newmsg", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProgressDialog, Pulse)
{
	Object_wx_ProgressDialog *pThis = Object_wx_ProgressDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString newmsg = wxT("");
	if (args.IsValid(0)) newmsg = wxString::FromUTF8(args.GetString(0));
	bool skip = false;
	bool rtn = pThis->GetEntity()->Pulse(newmsg, &skip);
	return ReturnValue(env, sig, args, Value::CreateList(env, rtn, skip));
}

//----------------------------------------------------------------------------
// Object implementation for wxProgressDialog
//----------------------------------------------------------------------------
Object_wx_ProgressDialog::~Object_wx_ProgressDialog()
{
}

Object *Object_wx_ProgressDialog::Clone() const
{
	return NULL;
}

String Object_wx_ProgressDialog::ToString(bool exprFlag)
{
	String rtn("<wx.ProgressDialog:");
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
// Class implementation for wxProgressDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProgressDialog)
{
	Gura_RealizeUserSymbol(Update);
	Gura_RealizeUserSymbol(Pulse);
	Gura_AssignFunction(ProgressDialog);
	Gura_AssignMethod(wx_ProgressDialog, Resume);
	Gura_AssignMethod(wx_ProgressDialog, Update);
	Gura_AssignMethod(wx_ProgressDialog, Pulse);
}

Gura_ImplementDescendantCreator(wx_ProgressDialog)
{
	return new Object_wx_ProgressDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
