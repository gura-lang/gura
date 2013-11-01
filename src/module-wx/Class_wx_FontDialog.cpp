//----------------------------------------------------------------------------
// wxFontDialog
// extracted from fontdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontDialog: public wxFontDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FontDialog *_pObj;
public:
	inline wx_FontDialog() : wxFontDialog(), _sig(NULL), _pObj(NULL) {}
	inline wx_FontDialog(wxWindow* parent) : wxFontDialog(parent), _sig(NULL), _pObj(NULL) {}
	inline wx_FontDialog(wxWindow* parent, const wxFontData& data) : wxFontDialog(parent, data), _sig(NULL), _pObj(NULL) {}
	~wx_FontDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FontDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontDialog::~wx_FontDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FontDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontDialogEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontDialogEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FontDialog *pEntity = new wx_FontDialog();
	Object_wx_FontDialog *pObj = Object_wx_FontDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FontDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(FontDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FontDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FontData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wx_FontDialog *pEntity = NULL;
	if (args.IsValid(1)) {
		wxFontData *data = Object_wx_FontData::GetObject(args, 1)->GetEntity();
		pEntity = new wx_FontDialog(parent, *data);
	} else {
		pEntity = new wx_FontDialog(parent);
	}
	Object_wx_FontDialog *pObj = Object_wx_FontDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FontDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FontDialog, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FontData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontDialog, Create)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	bool rtn = false;
	if (args.IsValid(1)) {
		wxFontData *data = Object_wx_FontData::GetObject(args, 1)->GetEntity();
		rtn = pThis->GetEntity()->Create(parent, *data);
	} else {
		rtn = pThis->GetEntity()->Create(parent);
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontDialog, GetFontData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontDialog, GetFontData)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFontData &rtn = pThis->GetEntity()->GetFontData();
	return ReturnValue(env, sig, args, Value(new Object_wx_FontData(new wxFontData(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontDialog, ShowModal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontDialog, ShowModal)
{
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFontDialog
//----------------------------------------------------------------------------
Object_wx_FontDialog::~Object_wx_FontDialog()
{
}

Object *Object_wx_FontDialog::Clone() const
{
	return NULL;
}

String Object_wx_FontDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FontDialog:");
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
// Class implementation for wxFontDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontDialog)
{
	Gura_AssignFunction(FontDialogEmpty);
	Gura_AssignFunction(FontDialog);
	Gura_AssignMethod(wx_FontDialog, Create);
	Gura_AssignMethod(wx_FontDialog, GetFontData);
	Gura_AssignMethod(wx_FontDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_FontDialog)
{
	return new Object_wx_FontDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
