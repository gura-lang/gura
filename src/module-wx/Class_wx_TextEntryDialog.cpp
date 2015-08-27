//----------------------------------------------------------------------------
// wxTextEntryDialog
// extracted from textdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextEntryDialog: public wxTextEntryDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextEntryDialog *_pObj;
public:
	inline wx_TextEntryDialog(wxWindow* parent, const wxString& message, const wxString& caption, const wxString& defaultValue, long style, const wxPoint& pos) : wxTextEntryDialog(parent, message, caption, defaultValue, style, pos), _pObj(nullptr) {}
	~wx_TextEntryDialog();
	inline void AssocWithGura(Object_wx_TextEntryDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextEntryDialog::~wx_TextEntryDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextEntryDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextEntryDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextEntryDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
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
	Object_wx_TextEntryDialog *pObj = Object_wx_TextEntryDialog::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextEntryDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_TextEntryDialog, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextEntryDialog, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextEntryDialog, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString value = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextEntryDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTextEntryDialog
//----------------------------------------------------------------------------
Object_wx_TextEntryDialog::~Object_wx_TextEntryDialog()
{
}

Object *Object_wx_TextEntryDialog::Clone() const
{
	return nullptr;
}

String Object_wx_TextEntryDialog::ToString(bool exprFlag)
{
	String rtn("<wx.TextEntryDialog:");
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
	return new Object_wx_TextEntryDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
