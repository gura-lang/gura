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
	//Gura::Signal *_pSig;
	Object_wx_ProgressDialog *_pObj;
public:
	inline wx_ProgressDialog(const wxString& title, const wxString& message, int maximum, wxWindow * parent, int style) : wxProgressDialog(title, message, maximum, parent, style), _pObj(nullptr) {}
	//virtual bool Update(int value, const wxString& newmsg, bool * skip);
	//virtual bool Pulse(const wxString& newmsg, bool * skip);
	~wx_ProgressDialog();
	inline void AssocWithGura(Object_wx_ProgressDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ProgressDialog::~wx_ProgressDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ProgressDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxProgressDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(ProgressDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString title = wxString::FromUTF8(args.GetString(0));
	wxString message = wxString::FromUTF8(args.GetString(1));
	int maximum = 100;
	if (args.IsValid(2)) maximum = args.GetInt(2);
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int style = wxPD_AUTO_HIDE | wxPD_APP_MODAL;
	if (args.IsValid(4)) style = args.GetInt(4);
	wx_ProgressDialog *pEntity = new wx_ProgressDialog(title, message, maximum, parent, style);
	Object_wx_ProgressDialog *pObj = Object_wx_ProgressDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ProgressDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ProgressDialog, Resume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ProgressDialog, Resume)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProgressDialog *pThis = Object_wx_ProgressDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ProgressDialog, Update)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "newmsg", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProgressDialog, Update)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProgressDialog *pThis = Object_wx_ProgressDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int value = args.GetInt(0);
	wxString newmsg = wxT("");
	if (args.IsValid(1)) newmsg = wxString::FromUTF8(args.GetString(1));
	bool skip = false;
	bool rtn = pThis->GetEntity()->Update(value, newmsg, &skip);
	return ReturnValue(env, args, Value::CreateList(env, rtn, skip));
}

Gura_DeclareMethod(wx_ProgressDialog, Pulse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "newmsg", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ProgressDialog, Pulse)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProgressDialog *pThis = Object_wx_ProgressDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString newmsg = wxT("");
	if (args.IsValid(0)) newmsg = wxString::FromUTF8(args.GetString(0));
	bool skip = false;
	bool rtn = pThis->GetEntity()->Pulse(newmsg, &skip);
	return ReturnValue(env, args, Value::CreateList(env, rtn, skip));
}

//----------------------------------------------------------------------------
// Object implementation for wxProgressDialog
//----------------------------------------------------------------------------
Object_wx_ProgressDialog::~Object_wx_ProgressDialog()
{
}

Object *Object_wx_ProgressDialog::Clone() const
{
	return nullptr;
}

String Object_wx_ProgressDialog::ToString(bool exprFlag)
{
	String rtn("<wx.ProgressDialog:");
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
	return new Object_wx_ProgressDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
