//----------------------------------------------------------------------------
// wxPrintDialog
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrintDialog: public wxPrintDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PrintDialog *_pObj;
public:
	inline wx_PrintDialog(wxWindow* parent, wxPrintDialogData* data) : wxPrintDialog(parent, data), _pObj(nullptr) {}
	~wx_PrintDialog();
	inline void AssocWithGura(Object_wx_PrintDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrintDialog::~wx_PrintDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PrintDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrintDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_PrintDialogData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxPrintDialogData *data = (wxPrintDialogData *)(nullptr);
	if (arg.IsValid(1)) data = Object_wx_PrintDialogData::GetObject(arg, 1)->GetEntity();
	wx_PrintDialog *pEntity = new wx_PrintDialog(parent, data);
	Object_wx_PrintDialog *pObj = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_PrintDialog, GetPrintDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialog, GetPrintDialogData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintDialogData &rtn = pThis->GetEntity()->GetPrintDialogData();
	return ReturnValue(env, arg, Value(new Object_wx_PrintDialogData(new wxPrintDialogData(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_PrintDialog, GetPrintDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialog, GetPrintDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *rtn = (wxDC *)pThis->GetEntity()->GetPrintDC();
	return ReturnValue(env, arg, Value(new Object_wx_DC(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPrintDialog
//----------------------------------------------------------------------------
Object_wx_PrintDialog::~Object_wx_PrintDialog()
{
}

Object *Object_wx_PrintDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PrintDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PrintDialog:");
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
// Class implementation for wxPrintDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialog)
{
	Gura_AssignFunction(PrintDialog);
	Gura_AssignMethod(wx_PrintDialog, GetPrintDialogData);
	Gura_AssignMethod(wx_PrintDialog, GetPrintDC);
	Gura_AssignMethod(wx_PrintDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_PrintDialog)
{
	return new Object_wx_PrintDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
