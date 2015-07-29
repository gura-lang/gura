//----------------------------------------------------------------------------
// wxToggleButton
// extracted from tglbtn.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToggleButton: public wxToggleButton, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ToggleButton *_pObj;
public:
	inline wx_ToggleButton() : wxToggleButton(), _pObj(nullptr) {}
	inline wx_ToggleButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxValidator& val, const wxString& name) : wxToggleButton(parent, id, label, pos, size, style, val, name), _pObj(nullptr) {}
	~wx_ToggleButton();
	inline void AssocWithGura(Object_wx_ToggleButton *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToggleButton::~wx_ToggleButton()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ToggleButton::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToggleButton
//----------------------------------------------------------------------------
Gura_DeclareFunction(ToggleButtonEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ToggleButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ToggleButtonEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ToggleButton *pEntity = new wx_ToggleButton();
	Object_wx_ToggleButton *pObj = Object_wx_ToggleButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ToggleButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(ToggleButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ToggleButton));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "val", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ToggleButton)
{
	Signal &sig = env.GetSignal();
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
	wxValidator *val = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) val = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("checkBox");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_ToggleButton *pEntity = new wx_ToggleButton(parent, id, label, *pos, *size, style, *val, name);
	Object_wx_ToggleButton *pObj = Object_wx_ToggleButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ToggleButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ToggleButton, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "val", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToggleButton, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToggleButton *pThis = Object_wx_ToggleButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString label = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *val = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) val = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("checkBox");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, *pos, *size, style, *val, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToggleButton, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToggleButton, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToggleButton *pThis = Object_wx_ToggleButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ToggleButton, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "state", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToggleButton, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToggleButton *pThis = Object_wx_ToggleButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool state = args.GetBoolean(0);
	pThis->GetEntity()->SetValue(state);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxToggleButton
//----------------------------------------------------------------------------
Object_wx_ToggleButton::~Object_wx_ToggleButton()
{
}

Object *Object_wx_ToggleButton::Clone() const
{
	return nullptr;
}

String Object_wx_ToggleButton::ToString(bool exprFlag)
{
	String rtn("<wx.ToggleButton:");
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
// Class implementation for wxToggleButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToggleButton)
{
	Gura_AssignFunction(ToggleButtonEmpty);
	Gura_AssignFunction(ToggleButton);
	Gura_AssignMethod(wx_ToggleButton, Create);
	Gura_AssignMethod(wx_ToggleButton, GetValue);
	Gura_AssignMethod(wx_ToggleButton, SetValue);
}

Gura_ImplementDescendantCreator(wx_ToggleButton)
{
	return new Object_wx_ToggleButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
