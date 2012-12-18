//----------------------------------------------------------------------------
// wxMessageDialog
// extracted from msgdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MessageDialog: public wxMessageDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MessageDialog *_pObj;
public:
	inline wx_MessageDialog(wxWindow* parent, const wxString& message, const wxString& caption, long style, const wxPoint& pos) : wxMessageDialog(parent, message, caption, style, pos), _sig(NULL), _pObj(NULL) {}
	~wx_MessageDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MessageDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MessageDialog::~wx_MessageDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MessageDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(MessageDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxString message = wxString::FromUTF8(args.GetString(1));
	wxString caption = wxT("Message box");
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	long style = wxOK | wxCANCEL;
	if (args.IsValid(3)) style = args.GetLong(3);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wx_MessageDialog *pEntity = new wx_MessageDialog(parent, message, caption, style, *pos);
	Object_wx_MessageDialog *pObj = Object_wx_MessageDialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MessageDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_MessageDialog, ShowModal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MessageDialog, ShowModal)
{
	Object_wx_MessageDialog *pSelf = Object_wx_MessageDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMessageDialog
//----------------------------------------------------------------------------
Object_wx_MessageDialog::~Object_wx_MessageDialog()
{
}

Object *Object_wx_MessageDialog::Clone() const
{
	return NULL;
}

String Object_wx_MessageDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MessageDialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MessageDialog::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MessageDialog);
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageDialog)
{
	Gura_AssignMethod(wx_MessageDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_MessageDialog)
{
	return new Object_wx_MessageDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
