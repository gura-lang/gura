//----------------------------------------------------------------------------
// wxMultiChoiceDialog
// extracted from mltchdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MultiChoiceDialog: public wxMultiChoiceDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MultiChoiceDialog *_pObj;
public:
	//inline wx_MultiChoiceDialog(wxWindow* parent, const wxString& message, const wxString& caption, int n, const wxString* choices, long style, const wxPoint& pos) : wxMultiChoiceDialog(parent, message, caption, n, choices, style, pos), _pObj(nullptr) {}
	inline wx_MultiChoiceDialog(wxWindow* parent, const wxString& message, const wxString& caption, const wxArrayString& choices, long style, const wxPoint& pos) : wxMultiChoiceDialog(parent, message, caption, choices, style, pos), _pObj(nullptr) {}
	~wx_MultiChoiceDialog();
	inline void AssocWithGura(Object_wx_MultiChoiceDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MultiChoiceDialog::~wx_MultiChoiceDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MultiChoiceDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(MultiChoiceDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_MultiChoiceDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(MultiChoiceDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxString message = wxString::FromUTF8(arg.GetString(1));
	wxString caption = wxString::FromUTF8(arg.GetString(2));
	int n = arg.GetInt(3);
	wxString choices = wxString::FromUTF8(arg.GetString(4));
	long style = wxCHOICEDLG_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(6)) pos = Object_wx_Point::GetObject(arg, 6)->GetEntity();
	wx_MultiChoiceDialog *pEntity = new wx_MultiChoiceDialog(parent, message, caption, n, choices, style, *pos);
	Object_wx_MultiChoiceDialog *pObj = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MultiChoiceDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(MultiChoiceDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MultiChoiceDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MultiChoiceDialog_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxString message = wxString::FromUTF8(arg.GetString(1));
	wxString caption = wxString::FromUTF8(arg.GetString(2));
	std::unique_ptr<wxArrayString> choices(CreateArrayString(arg.GetList(3)));
	long style = wxCHOICEDLG_STYLE;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(5)) pos = Object_wx_Point::GetObject(arg, 5)->GetEntity();
	wx_MultiChoiceDialog *pEntity = new wx_MultiChoiceDialog(parent, message, caption, *choices, style, *pos);
	Object_wx_MultiChoiceDialog *pObj = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MultiChoiceDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_MultiChoiceDialog, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, GetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayInt rtn = pThis->GetEntity()->GetSelections();
	return ReturnValue(env, arg, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_MultiChoiceDialog, SetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "selections", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, SetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayInt> selections(CreateArrayInt(arg.GetList(0)));
	pThis->GetEntity()->SetSelections(*selections);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MultiChoiceDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Object_wx_MultiChoiceDialog::~Object_wx_MultiChoiceDialog()
{
}

Object *Object_wx_MultiChoiceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_MultiChoiceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.MultiChoiceDialog:");
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
// Class implementation for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MultiChoiceDialog)
{
	Gura_AssignFunction(MultiChoiceDialog);
	Gura_AssignFunction(MultiChoiceDialog_1);
	Gura_AssignMethod(wx_MultiChoiceDialog, GetSelections);
	Gura_AssignMethod(wx_MultiChoiceDialog, SetSelections);
	Gura_AssignMethod(wx_MultiChoiceDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_MultiChoiceDialog)
{
	return new Object_wx_MultiChoiceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
