//----------------------------------------------------------------------------
// wxCheckBox
// extracted from checkbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CheckBox: public wxCheckBox, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CheckBox *_pObj;
public:
	inline wx_CheckBox() : wxCheckBox(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_CheckBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxValidator& val, const wxString& name) : wxCheckBox(parent, id, label, pos, size, style, val, name), _sig(nullptr), _pObj(nullptr) {}
	~wx_CheckBox();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CheckBox *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CheckBox::~wx_CheckBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CheckBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCheckBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(CheckBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CheckBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CheckBoxEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_CheckBox *pEntity = new wx_CheckBox();
	Object_wx_CheckBox *pObj = Object_wx_CheckBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CheckBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(CheckBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CheckBox));
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

Gura_ImplementFunction(CheckBox)
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
	wxValidator *val = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) val = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("checkBox");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_CheckBox *pEntity = new wx_CheckBox(parent, id, label, *pos, *size, style, *val, name);
	Object_wx_CheckBox *pObj = Object_wx_CheckBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CheckBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CheckBox, Create)
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

Gura_ImplementMethod(wx_CheckBox, Create)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
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
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CheckBox, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CheckBox, GetValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CheckBox, Get3StateValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CheckBox, Get3StateValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCheckBoxState rtn = pThis->GetEntity()->Get3StateValue();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CheckBox, Is3rdStateAllowedForUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CheckBox, Is3rdStateAllowedForUser)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Is3rdStateAllowedForUser();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CheckBox, Is3State)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CheckBox, Is3State)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Is3State();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CheckBox, IsChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CheckBox, IsChecked)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsChecked();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CheckBox, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "state", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckBox, SetValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool state = args.GetBoolean(0);
	pThis->GetEntity()->SetValue(state);
	return Value::Null;
}

Gura_DeclareMethod(wx_CheckBox, Set3StateValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CheckBox, Set3StateValue)
{
	Object_wx_CheckBox *pThis = Object_wx_CheckBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCheckBoxState state = static_cast<wxCheckBoxState>(args.GetInt(0));
	pThis->GetEntity()->Set3StateValue(state);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCheckBox
//----------------------------------------------------------------------------
Object_wx_CheckBox::~Object_wx_CheckBox()
{
}

Object *Object_wx_CheckBox::Clone() const
{
	return nullptr;
}

String Object_wx_CheckBox::ToString(bool exprFlag)
{
	String rtn("<wx.CheckBox:");
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
// Class implementation for wxCheckBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CheckBox)
{
	Gura_AssignWxStringValue(CheckBoxNameStr);
	Gura_AssignFunction(CheckBoxEmpty);
	Gura_AssignFunction(CheckBox);
	Gura_AssignMethod(wx_CheckBox, Create);
	Gura_AssignMethod(wx_CheckBox, GetValue);
	Gura_AssignMethod(wx_CheckBox, Get3StateValue);
	Gura_AssignMethod(wx_CheckBox, Is3rdStateAllowedForUser);
	Gura_AssignMethod(wx_CheckBox, Is3State);
	Gura_AssignMethod(wx_CheckBox, IsChecked);
	Gura_AssignMethod(wx_CheckBox, SetValue);
	Gura_AssignMethod(wx_CheckBox, Set3StateValue);
}

Gura_ImplementDescendantCreator(wx_CheckBox)
{
	return new Object_wx_CheckBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
