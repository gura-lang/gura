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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SpinCtrl *pEntity = new wx_SpinCtrl();
	Object_wx_SpinCtrl *pObj = Object_wx_SpinCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SpinCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxSP_ARROW_KEYS;
	if (args.IsValid(5)) style = args.GetLong(5);
	int min = 0;
	if (args.IsValid(6)) min = args.GetInt(6);
	int max = 100;
	if (args.IsValid(7)) max = args.GetInt(7);
	int initial = 0;
	if (args.IsValid(8)) initial = args.GetInt(8);
	wxString name = _T("wxSpinCtrl");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	wx_SpinCtrl *pEntity = new wx_SpinCtrl(parent, id, value, *pos, *size, style, min, max, initial, name);
	Object_wx_SpinCtrl *pObj = Object_wx_SpinCtrl::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SpinCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
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
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = -1;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxEmptyString;
	if (args.IsValid(2)) value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxSP_ARROW_KEYS;
	if (args.IsValid(5)) style = args.GetLong(5);
	int min = 0;
	if (args.IsValid(6)) min = args.GetInt(6);
	int max = 100;
	if (args.IsValid(7)) max = args.GetInt(7);
	int initial = 0;
	if (args.IsValid(8)) initial = args.GetInt(8);
	wxString name = _T("wxSpinCtrl");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	bool rtn = pThis->GetEntity()->Create(parent, id, value, *pos, *size, style, min, max, initial, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetValue)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetValue(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_SpinCtrl, SetValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetValue_1)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int value = args.GetInt(0);
	pThis->GetEntity()->SetValue(value);
	return Value::Null;
}

Gura_DeclareMethod(wx_SpinCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinCtrl, GetValue)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinCtrl, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minVal", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetRange)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int minVal = args.GetInt(0);
	int maxVal = args.GetInt(1);
	pThis->GetEntity()->SetRange(minVal, maxVal);
	return Value::Null;
}

Gura_DeclareMethod(wx_SpinCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinCtrl, SetSelection)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long from = args.GetLong(0);
	long to = args.GetLong(1);
	pThis->GetEntity()->SetSelection(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_SpinCtrl, GetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinCtrl, GetMin)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SpinCtrl, GetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SpinCtrl, GetMax)
{
	Object_wx_SpinCtrl *pThis = Object_wx_SpinCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMax();
	return ReturnValue(env, args, Value(rtn));
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
