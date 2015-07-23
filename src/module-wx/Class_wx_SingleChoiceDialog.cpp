//----------------------------------------------------------------------------
// wxSingleChoiceDialog
// extracted from sngchdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SingleChoiceDialog: public wxSingleChoiceDialog, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_SingleChoiceDialog *_pObj;
public:
	inline wx_SingleChoiceDialog(wxWindow* parent, const wxString& message, const wxString& caption, const wxArrayString& choices, char** clientData, long style, const wxPoint& pos) : wxSingleChoiceDialog(parent, message, caption, choices, clientData, style, pos), _pSig(nullptr), _pObj(nullptr) {}
	~wx_SingleChoiceDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SingleChoiceDialog *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SingleChoiceDialog::~wx_SingleChoiceDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SingleChoiceDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSingleChoiceDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(SingleChoiceDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SingleChoiceDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SingleChoiceDialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxString message = wxString::FromUTF8(args.GetString(1));
	wxString caption = wxString::FromUTF8(args.GetString(2));
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(3)));
	char **clientData = nullptr;
	long style = wxCHOICEDLG_STYLE;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) pos = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wx_SingleChoiceDialog *pEntity = new wx_SingleChoiceDialog(parent, message, caption, *choices, clientData, style, *pos);
	Object_wx_SingleChoiceDialog *pObj = Object_wx_SingleChoiceDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SingleChoiceDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_SingleChoiceDialog, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, GetSelection)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SingleChoiceDialog, GetSelectionClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, GetSelectionClientData)
{
#if 0
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char rtn = pThis->GetEntity()->GetSelectionClientData();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, GetStringSelection)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetStringSelection();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_SingleChoiceDialog, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, SetSelection)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int selection = args.GetInt(0);
	pThis->GetEntity()->SetSelection(selection);
	return Value::Null;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, ShowModal)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSingleChoiceDialog
//----------------------------------------------------------------------------
Object_wx_SingleChoiceDialog::~Object_wx_SingleChoiceDialog()
{
}

Object *Object_wx_SingleChoiceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_SingleChoiceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.SingleChoiceDialog:");
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
// Class implementation for wxSingleChoiceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SingleChoiceDialog)
{
	Gura_AssignFunction(SingleChoiceDialog);
	Gura_AssignMethod(wx_SingleChoiceDialog, GetSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, GetSelectionClientData);
	Gura_AssignMethod(wx_SingleChoiceDialog, GetStringSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, SetSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_SingleChoiceDialog)
{
	return new Object_wx_SingleChoiceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
