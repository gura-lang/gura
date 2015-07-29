//----------------------------------------------------------------------------
// wxSpinButton
// extracted from spinbutt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SpinButton: public wxSpinButton, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SpinButton *_pObj;
public:
	inline wx_SpinButton() : wxSpinButton(), _pObj(nullptr) {}
	inline wx_SpinButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxSpinButton(parent, id, pos, size, style, name), _pObj(nullptr) {}
	~wx_SpinButton();
	inline void AssocWithGura(Object_wx_SpinButton *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SpinButton::~wx_SpinButton()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SpinButton::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinButton
//----------------------------------------------------------------------------
Gura_DeclareFunction(SpinButtonEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SpinButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SpinButtonEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SpinButton *pEntity = new wx_SpinButton();
	Object_wx_SpinButton *pObj = Object_wx_SpinButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SpinButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(SpinButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SpinButton));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SpinButton)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxSP_HORIZONTAL;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("spinButton");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_SpinButton *pEntity = new wx_SpinButton(parent, id, *pos, *size, style, name);
	Object_wx_SpinButton *pObj = Object_wx_SpinButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SpinButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_SpinButton, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinButton, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxSP_HORIZONTAL;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("spinButton");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, GetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinButton, GetMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, GetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinButton, GetMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinButton, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int min = args.GetInt(0);
	int max = args.GetInt(1);
	pThis->GetEntity()->SetRange(min, max);
	return Value::Null;
}

Gura_DeclareMethod(wx_SpinButton, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int value = args.GetInt(0);
	pThis->GetEntity()->SetValue(value);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSpinButton
//----------------------------------------------------------------------------
Object_wx_SpinButton::~Object_wx_SpinButton()
{
}

Object *Object_wx_SpinButton::Clone() const
{
	return nullptr;
}

String Object_wx_SpinButton::ToString(bool exprFlag)
{
	String rtn("<wx.SpinButton:");
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
// Class implementation for wxSpinButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinButton)
{
	//Gura_AssignWxStringValue(SpinButtonNameStr);
	Gura_AssignFunction(SpinButtonEmpty);
	Gura_AssignFunction(SpinButton);
	Gura_AssignMethod(wx_SpinButton, Create);
	Gura_AssignMethod(wx_SpinButton, GetMax);
	Gura_AssignMethod(wx_SpinButton, GetMin);
	Gura_AssignMethod(wx_SpinButton, GetValue);
	Gura_AssignMethod(wx_SpinButton, SetRange);
	Gura_AssignMethod(wx_SpinButton, SetValue);
}

Gura_ImplementDescendantCreator(wx_SpinButton)
{
	return new Object_wx_SpinButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
