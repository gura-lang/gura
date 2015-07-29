//----------------------------------------------------------------------------
// wxPageSetupDialog
// extracted from pagedlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PageSetupDialog: public wxPageSetupDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PageSetupDialog *_pObj;
public:
	inline wx_PageSetupDialog(wxWindow* parent, wxPageSetupDialogData* data) : wxPageSetupDialog(parent, data), _pObj(nullptr) {}
	~wx_PageSetupDialog();
	inline void AssocWithGura(Object_wx_PageSetupDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PageSetupDialog::~wx_PageSetupDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PageSetupDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(PageSetupDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PageSetupDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_PageSetupDialogData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PageSetupDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxPageSetupDialogData *data = (wxPageSetupDialogData *)(nullptr);
	if (args.IsValid(1)) data = Object_wx_PageSetupDialogData::GetObject(args, 1)->GetEntity();
	wx_PageSetupDialog *pEntity = new wx_PageSetupDialog(parent, data);
	Object_wx_PageSetupDialog *pObj = Object_wx_PageSetupDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PageSetupDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_PageSetupDialog, GetPageSetupData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialog, GetPageSetupData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPageSetupDialogData &rtn = pThis->GetEntity()->GetPageSetupData();
	return ReturnValue(env, args, Value(new Object_wx_PageSetupDialogData(new wxPageSetupDialogData(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_PageSetupDialog, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialog, IsOk)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Object_wx_PageSetupDialog::~Object_wx_PageSetupDialog()
{
}

Object *Object_wx_PageSetupDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PageSetupDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PageSetupDialog:");
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
// Class implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupDialog)
{
	Gura_AssignFunction(PageSetupDialog);
	Gura_AssignMethod(wx_PageSetupDialog, GetPageSetupData);
	Gura_AssignMethod(wx_PageSetupDialog, IsOk);
	Gura_AssignMethod(wx_PageSetupDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_PageSetupDialog)
{
	return new Object_wx_PageSetupDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
