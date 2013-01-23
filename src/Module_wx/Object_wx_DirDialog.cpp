//----------------------------------------------------------------------------
// wxDirDialog
// extracted from dirdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DirDialog: public wxDirDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DirDialog *_pObj;
public:
	inline wx_DirDialog(wxWindow* parent, const wxString& message, const wxString& defaultPath, long style, const wxPoint& pos, const wxSize& size, const wxString& name) : wxDirDialog(parent, message, defaultPath, style, pos, size, name), _sig(NULL), _pObj(NULL) {}
	~wx_DirDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DirDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DirDialog::~wx_DirDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DirDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDirDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(DirDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DirDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaultPath", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxString message = wxT("Choose a directory");
	if (args.IsValid(1)) message = wxString::FromUTF8(args.GetString(1));
	wxString defaultPath = wxT("");
	if (args.IsValid(2)) defaultPath = wxString::FromUTF8(args.GetString(2));
	long style = wxDD_DEFAULT_STYLE;
	if (args.IsValid(3)) style = args.GetLong(3);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) size = Object_wx_Size::GetObject(args, 5)->GetEntity();
	wxString name = wxT("wxDirCtrl");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_DirDialog *pEntity = new wx_DirDialog(parent, message, defaultPath, style, *pos, *size, name);
	Object_wx_DirDialog *pObj = Object_wx_DirDialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DirDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_DirDialog, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirDialog, GetPath)
{
	Object_wx_DirDialog *pSelf = Object_wx_DirDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DirDialog, GetMessage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirDialog, GetMessage)
{
	Object_wx_DirDialog *pSelf = Object_wx_DirDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetMessage();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DirDialog, SetMessage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, SetMessage)
{
	Object_wx_DirDialog *pSelf = Object_wx_DirDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetMessage(message);
	return Value::Null;
}

Gura_DeclareMethod(wx_DirDialog, SetPath)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, SetPath)
{
	Object_wx_DirDialog *pSelf = Object_wx_DirDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetPath(path);
	return Value::Null;
}

Gura_DeclareMethod(wx_DirDialog, ShowModal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirDialog, ShowModal)
{
	Object_wx_DirDialog *pSelf = Object_wx_DirDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDirDialog
//----------------------------------------------------------------------------
Object_wx_DirDialog::~Object_wx_DirDialog()
{
}

Object *Object_wx_DirDialog::Clone() const
{
	return NULL;
}

String Object_wx_DirDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DirDialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DirDialog::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DirDialog);
}

//----------------------------------------------------------------------------
// Class implementation for wxDirDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirDialog)
{
	Gura_AssignMethod(wx_DirDialog, GetPath);
	Gura_AssignMethod(wx_DirDialog, GetMessage);
	Gura_AssignMethod(wx_DirDialog, SetMessage);
	Gura_AssignMethod(wx_DirDialog, SetPath);
	Gura_AssignMethod(wx_DirDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_DirDialog)
{
	return new Object_wx_DirDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
