//----------------------------------------------------------------------------
// wxDirDialog
// extracted from dirdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DirDialog: public wxDirDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DirDialog *_pObj;
public:
	inline wx_DirDialog(wxWindow* parent, const wxString& message, const wxString& defaultPath, long style, const wxPoint& pos, const wxSize& size, const wxString& name) : wxDirDialog(parent, message, defaultPath, style, pos, size, name), _pObj(nullptr) {}
	~wx_DirDialog();
	inline void AssocWithGura(Object_wx_DirDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DirDialog::~wx_DirDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DirDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDirDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(DirDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxString message = wxT("Choose a directory");
	if (arg.IsValid(1)) message = wxString::FromUTF8(arg.GetString(1));
	wxString defaultPath = wxT("");
	if (arg.IsValid(2)) defaultPath = wxString::FromUTF8(arg.GetString(2));
	long style = wxDD_DEFAULT_STYLE;
	if (arg.IsValid(3)) style = arg.GetLong(3);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(4)) pos = Object_wx_Point::GetObject(arg, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(5)) size = Object_wx_Size::GetObject(arg, 5)->GetEntity();
	wxString name = wxT("wxDirCtrl");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_DirDialog *pEntity = new wx_DirDialog(parent, message, defaultPath, style, *pos, *size, name);
	Object_wx_DirDialog *pObj = Object_wx_DirDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DirDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_DirDialog, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirDialog, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DirDialog, GetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirDialog, GetMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetMessage();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DirDialog, SetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, SetMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString message = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetMessage(message);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirDialog, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetPath(path);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDirDialog
//----------------------------------------------------------------------------
Object_wx_DirDialog::~Object_wx_DirDialog()
{
}

Object *Object_wx_DirDialog::Clone() const
{
	return nullptr;
}

String Object_wx_DirDialog::ToString(bool exprFlag)
{
	String rtn("<wx.DirDialog:");
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
// Class implementation for wxDirDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirDialog)
{
	Gura_AssignFunction(DirDialog);
	Gura_AssignMethod(wx_DirDialog, GetPath);
	Gura_AssignMethod(wx_DirDialog, GetMessage);
	Gura_AssignMethod(wx_DirDialog, SetMessage);
	Gura_AssignMethod(wx_DirDialog, SetPath);
	Gura_AssignMethod(wx_DirDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_DirDialog)
{
	return new Object_wx_DirDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
