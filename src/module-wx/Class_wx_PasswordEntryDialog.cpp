//----------------------------------------------------------------------------
// wxPasswordEntryDialog
// extracted from passdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PasswordEntryDialog: public wxPasswordEntryDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PasswordEntryDialog *_pObj;
public:
	inline wx_PasswordEntryDialog(wxWindow* parent, const wxString& message, const wxString& caption, const wxString& defaultValue, long style, const wxPoint& pos) : wxPasswordEntryDialog(parent, message, caption, defaultValue, style, pos), _pObj(nullptr) {}
	~wx_PasswordEntryDialog();
	inline void AssocWithGura(Object_wx_PasswordEntryDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PasswordEntryDialog::~wx_PasswordEntryDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PasswordEntryDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(PasswordEntryDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PasswordEntryDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaultValue", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PasswordEntryDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxString message = wxString::FromUTF8(args.GetString(1));
	wxString caption = wxT("Enter password");
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	wxString defaultValue = wxT("");
	if (args.IsValid(3)) defaultValue = wxString::FromUTF8(args.GetString(3));
	long style = wxOK | wxCANCEL | wxCENTRE;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) pos = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wx_PasswordEntryDialog *pEntity = new wx_PasswordEntryDialog(parent, message, caption, defaultValue, style, *pos);
	Object_wx_PasswordEntryDialog *pObj = Object_wx_PasswordEntryDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PasswordEntryDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Object_wx_PasswordEntryDialog::~Object_wx_PasswordEntryDialog()
{
}

Object *Object_wx_PasswordEntryDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PasswordEntryDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PasswordEntryDialog:");
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
// Class implementation for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PasswordEntryDialog)
{
	Gura_AssignFunction(PasswordEntryDialog);
}

Gura_ImplementDescendantCreator(wx_PasswordEntryDialog)
{
	return new Object_wx_PasswordEntryDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
