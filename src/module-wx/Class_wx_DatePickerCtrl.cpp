//----------------------------------------------------------------------------
// wxDatePickerCtrl
// extracted from datectrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DatePickerCtrl: public wxDatePickerCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DatePickerCtrl *_pObj;
public:
	inline wx_DatePickerCtrl(wxWindow * parent, wxWindowID id, const wxDateTime& dt, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxDatePickerCtrl(parent, id, dt, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_DatePickerCtrl();
	inline void AssocWithGura(Object_wx_DatePickerCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DatePickerCtrl::~wx_DatePickerCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DatePickerCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDatePickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(DatePickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DatePickerCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DatePickerCtrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxDateTime *dt = (wxDateTime *)(&wxDefaultDateTime);
	if (arg.IsValid(2)) dt = Object_wx_DateTime::GetObject(arg, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDP_DEFAULT | wxDP_SHOWCENTURY;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(6)) validator = Object_wx_Validator::GetObject(arg, 6)->GetEntity();
	wxString name = wxT("datectrl");
	if (arg.IsValid(7)) name = wxString::FromUTF8(arg.GetString(7));
	wx_DatePickerCtrl *pEntity = new wx_DatePickerCtrl(parent, id, *dt, *pos, *size, style, *validator, name);
	Object_wx_DatePickerCtrl *pObj = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DatePickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_DatePickerCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DatePickerCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxDateTime *dt = (wxDateTime *)(&wxDefaultDateTime);
	if (arg.IsValid(2)) dt = Object_wx_DateTime::GetObject(arg, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDP_DEFAULT | wxDP_SHOWCENTURY;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(6)) validator = Object_wx_Validator::GetObject(arg, 6)->GetEntity();
	wxString name = wxT("datectrl");
	if (arg.IsValid(7)) name = wxString::FromUTF8(arg.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, *dt, *pos, *size, style, *validator, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DatePickerCtrl, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dt1", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "*dt2", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DatePickerCtrl, GetRange)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dt1 = Object_wx_DateTime::GetObject(arg, 0)->GetEntity();
	wxDateTime **dt2 = Object_wx_DateTime::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetRange(dt1, **dt2);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DatePickerCtrl, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, arg, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DatePickerCtrl, SetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_DatePickerCtrl, SetFormat)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString format = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetFormat(format);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt1", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "dt2", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dt1 = Object_wx_DateTime::GetObject(arg, 0)->GetEntity();
	wxDateTime *dt2 = Object_wx_DateTime::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetRange(*dt1, *dt2);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatePickerCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatePickerCtrl, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_DatePickerCtrl *pThis = Object_wx_DatePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dt = Object_wx_DateTime::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetValue(*dt);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDatePickerCtrl
//----------------------------------------------------------------------------
Object_wx_DatePickerCtrl::~Object_wx_DatePickerCtrl()
{
}

Object *Object_wx_DatePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DatePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DatePickerCtrl:");
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
// Class implementation for wxDatePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DatePickerCtrl)
{
	Gura_AssignFunction(DatePickerCtrl);
	Gura_AssignMethod(wx_DatePickerCtrl, Create);
	Gura_AssignMethod(wx_DatePickerCtrl, GetRange);
	Gura_AssignMethod(wx_DatePickerCtrl, GetValue);
	Gura_AssignMethod(wx_DatePickerCtrl, SetFormat);
	Gura_AssignMethod(wx_DatePickerCtrl, SetRange);
	Gura_AssignMethod(wx_DatePickerCtrl, SetValue);
}

Gura_ImplementDescendantCreator(wx_DatePickerCtrl)
{
	return new Object_wx_DatePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
