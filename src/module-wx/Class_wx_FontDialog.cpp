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
	//Gura::Signal *_pSig;
	Object_wx_FontDialog *_pObj;
public:
	inline wx_FontDialog() : wxFontDialog(), _pObj(nullptr) {}
	inline wx_FontDialog(wxWindow* parent) : wxFontDialog(parent), _pObj(nullptr) {}
	inline wx_FontDialog(wxWindow* parent, const wxFontData& data) : wxFontDialog(parent, data), _pObj(nullptr) {}
	~wx_FontDialog();
	inline void AssocWithGura(Object_wx_FontDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontDialog::~wx_FontDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FontDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontDialogEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontDialogEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_FontDialog *pEntity = new wx_FontDialog();
	Object_wx_FontDialog *pObj = Object_wx_FontDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FontDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(FontDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FontDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FontData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wx_FontDialog *pEntity = nullptr;
	if (arg.IsValid(1)) {
		wxFontData *data = Object_wx_FontData::GetObject(arg, 1)->GetEntity();
		pEntity = new wx_FontDialog(parent, *data);
	} else {
		pEntity = new wx_FontDialog(parent);
	}
	Object_wx_FontDialog *pObj = Object_wx_FontDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FontDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_FontDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FontData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	bool rtn = false;
	if (arg.IsValid(1)) {
		wxFontData *data = Object_wx_FontData::GetObject(arg, 1)->GetEntity();
		rtn = pThis->GetEntity()->Create(parent, *data);
	} else {
		rtn = pThis->GetEntity()->Create(parent);
	}
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FontDialog, GetFontData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontDialog, GetFontData)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxFontData &rtn = pThis->GetEntity()->GetFontData();
	return ReturnValue(env, arg, Value(new Object_wx_FontData(new wxFontData(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontDialog *pThis = Object_wx_FontDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFontDialog
//----------------------------------------------------------------------------
Object_wx_FontDialog::~Object_wx_FontDialog()
{
}

Object *Object_wx_FontDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FontDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FontDialog:");
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
	return new Object_wx_FontDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
