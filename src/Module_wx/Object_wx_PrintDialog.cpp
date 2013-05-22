//----------------------------------------------------------------------------
// wxPrintDialog
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrintDialog: public wxPrintDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PrintDialog *_pObj;
public:
	inline wx_PrintDialog(wxWindow* parent, wxPrintDialogData* data) : wxPrintDialog(parent, data), _sig(NULL), _pObj(NULL) {}
	~wx_PrintDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PrintDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrintDialog::~wx_PrintDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PrintDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrintDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_PrintDialogData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxPrintDialogData *data = (wxPrintDialogData *)(NULL);
	if (args.IsValid(1)) data = Object_wx_PrintDialogData::GetObject(args, 1)->GetEntity();
	wx_PrintDialog *pEntity = new wx_PrintDialog(parent, data);
	Object_wx_PrintDialog *pObj = Object_wx_PrintDialog::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PrintDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PrintDialog, GetPrintDialogData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialog, GetPrintDialogData)
{
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintDialogData &rtn = pThis->GetEntity()->GetPrintDialogData();
	return ReturnValue(env, sig, args, Value(new Object_wx_PrintDialogData(new wxPrintDialogData(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_PrintDialog, GetPrintDC)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialog, GetPrintDC)
{
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *rtn = (wxDC *)pThis->GetEntity()->GetPrintDC();
	return ReturnValue(env, sig, args, Value(new Object_wx_DC(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintDialog, ShowModal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialog, ShowModal)
{
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPrintDialog
//----------------------------------------------------------------------------
Object_wx_PrintDialog::~Object_wx_PrintDialog()
{
}

Object *Object_wx_PrintDialog::Clone() const
{
	return NULL;
}

String Object_wx_PrintDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PrintDialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PrintDialog::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(PrintDialog);
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialog)
{
	Gura_AssignMethod(wx_PrintDialog, GetPrintDialogData);
	Gura_AssignMethod(wx_PrintDialog, GetPrintDC);
	Gura_AssignMethod(wx_PrintDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_PrintDialog)
{
	return new Object_wx_PrintDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
