//----------------------------------------------------------------------------
// wxMessageDialog
// extracted from msgdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MessageDialog: public wxMessageDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MessageDialog *_pObj;
public:
	inline wx_MessageDialog(wxWindow* parent, const wxString& message, const wxString& caption, long style, const wxPoint& pos) : wxMessageDialog(parent, message, caption, style, pos), _pObj(nullptr) {}
	~wx_MessageDialog();
	inline void AssocWithGura(Object_wx_MessageDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MessageDialog::~wx_MessageDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MessageDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(MessageDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MessageDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MessageDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxString message = wxString::FromUTF8(args.GetString(1));
	wxString caption = wxT("Message box");
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	long style = wxOK | wxCENTRE;
	if (args.IsValid(3)) style = args.GetLong(3);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wx_MessageDialog *pEntity = new wx_MessageDialog(parent, message, caption, style, *pos);
	Object_wx_MessageDialog *pObj = Object_wx_MessageDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MessageDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_MessageDialog, SetExtendedMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "extendedMessage", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageDialog, SetExtendedMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString extendedMessage = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetExtendedMessage(extendedMessage);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageDialog, SetHelpLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "help", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, SetHelpLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString help = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetHelpLabel(help);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, SetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageDialog, SetMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString message = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetMessage(message);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageDialog, SetOKCancelLabels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "ok", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "cancel", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, SetOKCancelLabels)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString ok = wxString::FromUTF8(args.GetString(0));
	wxString cancel = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetOKCancelLabels(ok, cancel);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, SetOKLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "ok", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, SetOKLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString ok = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->SetOKLabel(ok);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, SetYesNoCancelLabels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "yes", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "no", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "cancel", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, SetYesNoCancelLabels)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString yes = wxString::FromUTF8(args.GetString(0));
	wxString no = wxString::FromUTF8(args.GetString(1));
	wxString cancel = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->SetYesNoCancelLabels(yes, no, cancel);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, SetYesNoLabels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "yes", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "no", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, SetYesNoLabels)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString yes = wxString::FromUTF8(args.GetString(0));
	wxString no = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetYesNoLabels(yes, no);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, GetCaption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetCaption)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetCaption();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetMessage();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetExtendedMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetExtendedMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetExtendedMessage();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetMessageDialogStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetMessageDialogStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetMessageDialogStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, HasCustomLabels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, HasCustomLabels)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasCustomLabels();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MessageDialog, GetYesLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetYesLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetYesLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetNoLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetNoLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNoLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetOKLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetOKLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetOKLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetCancelLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetCancelLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetCancelLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetHelpLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetHelpLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetHelpLabel();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_MessageDialog, GetEffectiveIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, GetEffectiveIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_MessageDialog *pThis = Object_wx_MessageDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetEffectiveIcon();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMessageDialog
//----------------------------------------------------------------------------
Object_wx_MessageDialog::~Object_wx_MessageDialog()
{
}

Object *Object_wx_MessageDialog::Clone() const
{
	return nullptr;
}

String Object_wx_MessageDialog::ToString(bool exprFlag)
{
	String rtn("<wx.MessageDialog:");
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
// Class implementation for wxMessageDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageDialog)
{
	Gura_AssignFunction(MessageDialog);
	Gura_AssignMethod(wx_MessageDialog, SetExtendedMessage);
	Gura_AssignMethod(wx_MessageDialog, SetHelpLabel);
	Gura_AssignMethod(wx_MessageDialog, SetMessage);
	Gura_AssignMethod(wx_MessageDialog, SetOKCancelLabels);
	Gura_AssignMethod(wx_MessageDialog, SetOKLabel);
	Gura_AssignMethod(wx_MessageDialog, SetYesNoCancelLabels);
	Gura_AssignMethod(wx_MessageDialog, SetYesNoLabels);
	Gura_AssignMethod(wx_MessageDialog, ShowModal);
	Gura_AssignMethod(wx_MessageDialog, GetCaption);
	Gura_AssignMethod(wx_MessageDialog, GetMessage);
	Gura_AssignMethod(wx_MessageDialog, GetExtendedMessage);
	Gura_AssignMethod(wx_MessageDialog, GetMessageDialogStyle);
	Gura_AssignMethod(wx_MessageDialog, HasCustomLabels);
	Gura_AssignMethod(wx_MessageDialog, GetYesLabel);
	Gura_AssignMethod(wx_MessageDialog, GetNoLabel);
	Gura_AssignMethod(wx_MessageDialog, GetOKLabel);
	Gura_AssignMethod(wx_MessageDialog, GetCancelLabel);
	Gura_AssignMethod(wx_MessageDialog, GetHelpLabel);
	Gura_AssignMethod(wx_MessageDialog, GetEffectiveIcon);
}

Gura_ImplementDescendantCreator(wx_MessageDialog)
{
	return new Object_wx_MessageDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
