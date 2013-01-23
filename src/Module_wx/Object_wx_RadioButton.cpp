//----------------------------------------------------------------------------
// wxRadioButton
// extracted from radiobut.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RadioButton: public wxRadioButton, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RadioButton *_pObj;
public:
	inline wx_RadioButton() : wxRadioButton(), _sig(NULL), _pObj(NULL) {}
	inline wx_RadioButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxRadioButton(parent, id, label, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_RadioButton();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RadioButton *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RadioButton::~wx_RadioButton()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RadioButton::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRadioButton
//----------------------------------------------------------------------------
Gura_DeclareFunction(RadioButtonEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RadioButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RadioButtonEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_RadioButton *pEntity = new wx_RadioButton();
	Object_wx_RadioButton *pObj = Object_wx_RadioButton::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RadioButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(RadioButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RadioButton));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RadioButton)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("radioButton");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_RadioButton *pEntity = new wx_RadioButton(parent, id, label, *pos, *size, style, *validator, name);
	Object_wx_RadioButton *pObj = Object_wx_RadioButton::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RadioButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RadioButton, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioButton, Create)
{
	Object_wx_RadioButton *pSelf = Object_wx_RadioButton::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("radioButton");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pSelf->GetEntity()->Create(parent, id, label, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioButton, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RadioButton, GetValue)
{
	Object_wx_RadioButton *pSelf = Object_wx_RadioButton::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RadioButton, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RadioButton, SetValue)
{
	Object_wx_RadioButton *pSelf = Object_wx_RadioButton::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool value = args.GetBoolean(0);
	pSelf->GetEntity()->SetValue(value);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRadioButton
//----------------------------------------------------------------------------
Object_wx_RadioButton::~Object_wx_RadioButton()
{
}

Object *Object_wx_RadioButton::Clone() const
{
	return NULL;
}

String Object_wx_RadioButton::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RadioButton:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RadioButton::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignWxStringValue(RadioButtonNameStr);
	Gura_AssignFunction(RadioButtonEmpty);
	Gura_AssignFunction(RadioButton);
}

//----------------------------------------------------------------------------
// Class implementation for wxRadioButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RadioButton)
{
	Gura_AssignMethod(wx_RadioButton, Create);
	Gura_AssignMethod(wx_RadioButton, GetValue);
	Gura_AssignMethod(wx_RadioButton, SetValue);
}

Gura_ImplementDescendantCreator(wx_RadioButton)
{
	return new Object_wx_RadioButton((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
