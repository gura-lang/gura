//----------------------------------------------------------------------------
// wxTextEntryDialog
// extracted from textdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextEntryDialog: public wxTextEntryDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TextEntryDialog *_pObj;
public:
	inline wx_TextEntryDialog(wxWindow* parent, const wxString& message, const wxString& caption, const wxString& defaultValue, long style, const wxPoint& pos) : wxTextEntryDialog(parent, message, caption, defaultValue, style, pos), _sig(NULL), _pObj(NULL) {}
	~wx_TextEntryDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextEntryDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextEntryDialog::~wx_TextEntryDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TextEntryDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextEntryDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextEntryDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextEntryDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaultValue", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextEntryDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxString message = wxString::FromUTF8(args.GetString(1));
	wxString caption = wxT("Please enter text");
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	wxString defaultValue = wxT("");
	if (args.IsValid(3)) defaultValue = wxString::FromUTF8(args.GetString(3));
	long style = wxOK | wxCANCEL | wxCENTRE;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) pos = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wx_TextEntryDialog *pEntity = new wx_TextEntryDialog(parent, message, caption, defaultValue, style, *pos);
	Object_wx_TextEntryDialog *pObj = Object_wx_TextEntryDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextEntryDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextEntryDialog, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextEntryDialog, GetValue)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextEntryDialog, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, SetValue)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextEntryDialog, ShowModal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextEntryDialog, ShowModal)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTextEntryDialog
//----------------------------------------------------------------------------
Object_wx_TextEntryDialog::~Object_wx_TextEntryDialog()
{
}

Object *Object_wx_TextEntryDialog::Clone() const
{
	return NULL;
}

String Object_wx_TextEntryDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TextEntryDialog:");
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
// Class implementation for wxTextEntryDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextEntryDialog)
{
	Gura_AssignFunction(TextEntryDialog);
	Gura_AssignMethod(wx_TextEntryDialog, GetValue);
	Gura_AssignMethod(wx_TextEntryDialog, SetValue);
	Gura_AssignMethod(wx_TextEntryDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_TextEntryDialog)
{
	return new Object_wx_TextEntryDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
