//----------------------------------------------------------------------------
// wxSpinButton
// extracted from spinbutt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SpinButton: public wxSpinButton, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SpinButton *_pObj;
public:
	inline wx_SpinButton() : wxSpinButton(), _sig(NULL), _pObj(NULL) {}
	inline wx_SpinButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxSpinButton(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_SpinButton();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SpinButton *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SpinButton::~wx_SpinButton()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SpinButton::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinButton
//----------------------------------------------------------------------------
Gura_DeclareFunction(SpinButtonEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SpinButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SpinButtonEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SpinButton *pEntity = new wx_SpinButton();
	Object_wx_SpinButton *pObj = Object_wx_SpinButton::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SpinButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(SpinButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
		pObj = new Object_wx_SpinButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_SpinButton, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, GetMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinButton, GetMax)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, GetMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinButton, GetMin)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinButton, GetValue)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinButton, SetRange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, SetRange)
{
	Object_wx_SpinButton *pThis = Object_wx_SpinButton::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int min = args.GetInt(0);
	int max = args.GetInt(1);
	pThis->GetEntity()->SetRange(min, max);
	return Value::Null;
}

Gura_DeclareMethod(wx_SpinButton, SetValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinButton, SetValue)
{
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
	return NULL;
}

String Object_wx_SpinButton::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SpinButton:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SpinButton::OnModuleEntry(Environment &env, Signal sig)
{
	//Gura_AssignWxStringValue(SpinButtonNameStr);
	Gura_AssignFunction(SpinButtonEmpty);
	Gura_AssignFunction(SpinButton);
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinButton)
{
	Gura_AssignMethod(wx_SpinButton, Create);
	Gura_AssignMethod(wx_SpinButton, GetMax);
	Gura_AssignMethod(wx_SpinButton, GetMin);
	Gura_AssignMethod(wx_SpinButton, GetValue);
	Gura_AssignMethod(wx_SpinButton, SetRange);
	Gura_AssignMethod(wx_SpinButton, SetValue);
}

Gura_ImplementDescendantCreator(wx_SpinButton)
{
	return new Object_wx_SpinButton((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
