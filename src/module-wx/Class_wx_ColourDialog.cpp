//----------------------------------------------------------------------------
// wxColourDialog
// extracted from colordlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ColourDialog: public wxColourDialog, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ColourDialog *_pObj;
public:
	inline wx_ColourDialog(wxWindow* parent, wxColourData* data) : wxColourDialog(parent, data), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ColourDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ColourDialog *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ColourDialog::~wx_ColourDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ColourDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColourDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ColourDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_ColourData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxColourData *data = (wxColourData *)(nullptr);
	if (args.IsValid(1)) data = Object_wx_ColourData::GetObject(args, 1)->GetEntity();
	wx_ColourDialog *pEntity = new wx_ColourDialog(parent, data);
	Object_wx_ColourDialog *pObj = Object_wx_ColourDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ColourDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ColourDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_ColourData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourDialog, Create)
{
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxColourData *data = (wxColourData *)(nullptr);
	if (args.IsValid(1)) data = Object_wx_ColourData::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(parent, data);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ColourDialog, GetColourData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourDialog, GetColourData)
{
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColourData &rtn = pThis->GetEntity()->GetColourData();
	return ReturnValue(env, sig, args, Value(new Object_wx_ColourData(new wxColourData(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourDialog, ShowModal)
{
	Object_wx_ColourDialog *pThis = Object_wx_ColourDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxColourDialog
//----------------------------------------------------------------------------
Object_wx_ColourDialog::~Object_wx_ColourDialog()
{
}

Object *Object_wx_ColourDialog::Clone() const
{
	return nullptr;
}

String Object_wx_ColourDialog::ToString(bool exprFlag)
{
	String rtn("<wx.ColourDialog:");
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
// Class implementation for wxColourDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourDialog)
{
	Gura_AssignFunction(ColourDialog);
	Gura_AssignMethod(wx_ColourDialog, Create);
	Gura_AssignMethod(wx_ColourDialog, GetColourData);
	Gura_AssignMethod(wx_ColourDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_ColourDialog)
{
	return new Object_wx_ColourDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
