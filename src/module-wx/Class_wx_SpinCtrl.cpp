//----------------------------------------------------------------------------
// wxSpinCtrl
// extracted from spinctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SpinCtrl: public wxSpinCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SpinCtrl *_pObj;
public:
	inline wx_SpinCtrl() : wxSpinCtrl(), _pObj(nullptr) {}
	inline wx_SpinCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, long style, int min, int max, int initial, const wxString& name) : wxSpinCtrl(parent, id, value, pos, size, style, min, max, initial, name), _pObj(nullptr) {}
	~wx_SpinCtrl();
	inline void AssocWithGura(Object_wx_SpinCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SpinCtrl::~wx_SpinCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SpinCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(SpinCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SpinCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SpinCtrlEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SpinCtrl *pEntity = new wx_SpinCtrl();
	Object_wx_SpinCtrl *pObj = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SpinCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(SpinCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SpinCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "min", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "max", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "initial", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SpinCtrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = -1;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString value = wxEmptyString;
	if (arg.IsValid(2)) value = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxSP_ARROW_KEYS;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	int min = 0;
	if (arg.IsValid(6)) min = arg.GetInt(6);
	int max = 100;
	if (arg.IsValid(7)) max = arg.GetInt(7);
	int initial = 0;
	if (arg.IsValid(8)) initial = arg.GetInt(8);
	wxString name = _T("wxSpinCtrl");
	if (arg.IsValid(9)) name = wxString::FromUTF8(arg.GetString(9));
	wx_SpinCtrl *pEntity = new wx_SpinCtrl(parent, id, value, *pos, *size, style, min, max, initial, name);
	Object_wx_SpinCtrl *pObj = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SpinCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_SpinCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "min", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "max", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "initial", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = -1;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString value = wxEmptyString;
	if (arg.IsValid(2)) value = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxSP_ARROW_KEYS;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	int min = 0;
	if (arg.IsValid(6)) min = arg.GetInt(6);
	int max = 100;
	if (arg.IsValid(7)) max = arg.GetInt(7);
	int initial = 0;
	if (arg.IsValid(8)) initial = arg.GetInt(8);
	wxString name = _T("wxSpinCtrl");
	if (arg.IsValid(9)) name = wxString::FromUTF8(arg.GetString(9));
	bool rtn = pThis->GetEntity()->Create(parent, id, value, *pos, *size, style, min, max, initial, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SpinCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetValue(text);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, SetValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetValue_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int value = arg.GetInt(0);
	pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinCtrl, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SpinCtrl, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minVal", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int minVal = arg.GetInt(0);
	int maxVal = arg.GetInt(1);
	pThis->GetEntity()->SetRange(minVal, maxVal);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long from = arg.GetLong(0);
	long to = arg.GetLong(1);
	pThis->GetEntity()->SetSelection(from, to);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinCtrl, GetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinCtrl, GetMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMin();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SpinCtrl, GetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinCtrl, GetMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMax();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSpinCtrl
//----------------------------------------------------------------------------
Object_wx_SpinCtrl::~Object_wx_SpinCtrl()
{
}

Object *Object_wx_SpinCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_SpinCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.SpinCtrl:");
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
// Class implementation for wxSpinCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinCtrl)
{
	//Gura_AssignWxStringValue(SpinCtrlNameStr);
	Gura_AssignFunction(SpinCtrlEmpty);
	Gura_AssignFunction(SpinCtrl);
	Gura_AssignMethod(wx_SpinCtrl, Create);
	Gura_AssignMethod(wx_SpinCtrl, SetValue);
	Gura_AssignMethod(wx_SpinCtrl, SetValue_1);
	Gura_AssignMethod(wx_SpinCtrl, GetValue);
	Gura_AssignMethod(wx_SpinCtrl, SetRange);
	Gura_AssignMethod(wx_SpinCtrl, SetSelection);
	Gura_AssignMethod(wx_SpinCtrl, GetMin);
	Gura_AssignMethod(wx_SpinCtrl, GetMax);
}

Gura_ImplementDescendantCreator(wx_SpinCtrl)
{
	return new Object_wx_SpinCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
