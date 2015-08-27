//----------------------------------------------------------------------------
// wxGauge
// extracted from gauge.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Gauge: public wxGauge, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Gauge *_pObj;
public:
	inline wx_Gauge() : wxGauge(), _pObj(nullptr) {}
	inline wx_Gauge(wxWindow* parent, wxWindowID id, int range, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxGauge(parent, id, range, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_Gauge();
	inline void AssocWithGura(Object_wx_Gauge *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Gauge::~wx_Gauge()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Gauge::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGauge
//----------------------------------------------------------------------------
Gura_DeclareFunction(GaugeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Gauge));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GaugeEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Gauge *pEntity = new wx_Gauge();
	Object_wx_Gauge *pObj = Object_wx_Gauge::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Gauge(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(Gauge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Gauge));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Gauge)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	int range = args.GetInt(2);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxGA_HORIZONTAL;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("gauge");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_Gauge *pEntity = new wx_Gauge(parent, id, range, *pos, *size, style, *validator, name);
	Object_wx_Gauge *pObj = Object_wx_Gauge::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Gauge(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_Gauge, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Gauge, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	int range = args.GetInt(2);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxGA_HORIZONTAL;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("gauge");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, range, *pos, *size, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Gauge, GetBezelFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Gauge, GetBezelFace)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetBezelFace();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Gauge, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Gauge, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRange();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Gauge, GetShadowWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Gauge, GetShadowWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetShadowWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Gauge, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Gauge, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Gauge, IsVertical)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Gauge, IsVertical)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsVertical();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Gauge, SetBezelFace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, SetBezelFace)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetBezelFace(width);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int range = args.GetInt(0);
	pThis->GetEntity()->SetRange(range);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, SetShadowWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, SetShadowWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetShadowWidth(width);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pos = args.GetInt(0);
	pThis->GetEntity()->SetValue(pos);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, Pulse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, Pulse)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Pulse();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGauge
//----------------------------------------------------------------------------
Object_wx_Gauge::~Object_wx_Gauge()
{
}

Object *Object_wx_Gauge::Clone() const
{
	return nullptr;
}

String Object_wx_Gauge::ToString(bool exprFlag)
{
	String rtn("<wx.Gauge:");
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
// Class implementation for wxGauge
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Gauge)
{
	Gura_AssignWxStringValue(GaugeNameStr);
	Gura_AssignFunction(GaugeEmpty);
	Gura_AssignFunction(Gauge);
	Gura_AssignMethod(wx_Gauge, Create);
	Gura_AssignMethod(wx_Gauge, GetBezelFace);
	Gura_AssignMethod(wx_Gauge, GetRange);
	Gura_AssignMethod(wx_Gauge, GetShadowWidth);
	Gura_AssignMethod(wx_Gauge, GetValue);
	Gura_AssignMethod(wx_Gauge, IsVertical);
	Gura_AssignMethod(wx_Gauge, SetBezelFace);
	Gura_AssignMethod(wx_Gauge, SetRange);
	Gura_AssignMethod(wx_Gauge, SetShadowWidth);
	Gura_AssignMethod(wx_Gauge, SetValue);
	Gura_AssignMethod(wx_Gauge, Pulse);
}

Gura_ImplementDescendantCreator(wx_Gauge)
{
	return new Object_wx_Gauge((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
