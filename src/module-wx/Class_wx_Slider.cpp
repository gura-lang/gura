//----------------------------------------------------------------------------
// wxSlider
// extracted from slider.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Slider: public wxSlider, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_Slider *_pObj;
public:
	inline wx_Slider() : wxSlider(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Slider(wxWindow* parent, wxWindowID id, int value, int minValue, int maxValue, const wxPoint& point, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxSlider(parent, id, value, minValue, maxValue, point, size, style, validator, name), _pSig(nullptr), _pObj(nullptr) {}
	~wx_Slider();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Slider *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Slider::~wx_Slider()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Slider::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSlider
//----------------------------------------------------------------------------
Gura_DeclareFunction(SliderEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Slider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SliderEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Slider *pEntity = new wx_Slider();
	Object_wx_Slider *pObj = Object_wx_Slider::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Slider(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Slider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Slider));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Slider)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	int value = args.GetInt(2);
	int minValue = args.GetInt(3);
	int maxValue = args.GetInt(4);
	wxPoint *point = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) point = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(6)) size = Object_wx_Size::GetObject(args, 6)->GetEntity();
	long style = wxSL_HORIZONTAL;
	if (args.IsValid(7)) style = args.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(8)) validator = Object_wx_Validator::GetObject(args, 8)->GetEntity();
	wxString name = wxT("slider");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	wx_Slider *pEntity = new wx_Slider(parent, id, value, minValue, maxValue, *point, *size, style, *validator, name);
	Object_wx_Slider *pObj = Object_wx_Slider::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Slider(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Slider, ClearSel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, ClearSel)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearSel();
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, ClearTicks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Slider, ClearTicks)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearTicks();
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, Create)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	int value = args.GetInt(2);
	int minValue = args.GetInt(3);
	int maxValue = args.GetInt(4);
	wxPoint *point = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) point = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(6)) size = Object_wx_Size::GetObject(args, 6)->GetEntity();
	long style = wxSL_HORIZONTAL;
	if (args.IsValid(7)) style = args.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(8)) validator = Object_wx_Validator::GetObject(args, 8)->GetEntity();
	wxString name = wxT("slider");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	bool rtn = pThis->GetEntity()->Create(parent, id, value, minValue, maxValue, *point, *size, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetLineSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetLineSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLineSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetMax)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetMin)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetPageSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPageSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetSelEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetSelEnd)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelEnd();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetSelStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetSelStart)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelStart();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetThumbLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetThumbLength)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetThumbLength();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetTickFreq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetTickFreq)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTickFreq();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Slider, GetValue)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Slider, SetLineSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "lineSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetLineSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int lineSize = args.GetInt(0);
	pThis->GetEntity()->SetLineSize(lineSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, SetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetPageSize)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pageSize = args.GetInt(0);
	pThis->GetEntity()->SetPageSize(pageSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "minValue", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetRange)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int minValue = args.GetInt(0);
	int maxValue = args.GetInt(1);
	pThis->GetEntity()->SetRange(minValue, maxValue);
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetSelection)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int startPos = args.GetInt(0);
	int endPos = args.GetInt(1);
	pThis->GetEntity()->SetSelection(startPos, endPos);
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, SetThumbLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetThumbLength)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int len = args.GetInt(0);
	pThis->GetEntity()->SetThumbLength(len);
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, SetTick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tickPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetTick)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int tickPos = args.GetInt(0);
	pThis->GetEntity()->SetTick(tickPos);
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, SetTickFreq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetTickFreq)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	int pos = args.GetInt(1);
	pThis->GetEntity()->SetTickFreq(n, pos);
	return Value::Null;
}

Gura_DeclareMethod(wx_Slider, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Slider, SetValue)
{
	Object_wx_Slider *pThis = Object_wx_Slider::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int value = args.GetInt(0);
	pThis->GetEntity()->SetValue(value);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSlider
//----------------------------------------------------------------------------
Object_wx_Slider::~Object_wx_Slider()
{
}

Object *Object_wx_Slider::Clone() const
{
	return nullptr;
}

String Object_wx_Slider::ToString(bool exprFlag)
{
	String rtn("<wx.Slider:");
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
// Class implementation for wxSlider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Slider)
{
	Gura_AssignFunction(SliderEmpty);
	Gura_AssignFunction(Slider);
	Gura_AssignMethod(wx_Slider, ClearSel);
	Gura_AssignMethod(wx_Slider, ClearTicks);
	Gura_AssignMethod(wx_Slider, Create);
	Gura_AssignMethod(wx_Slider, GetLineSize);
	Gura_AssignMethod(wx_Slider, GetMax);
	Gura_AssignMethod(wx_Slider, GetMin);
	Gura_AssignMethod(wx_Slider, GetPageSize);
	Gura_AssignMethod(wx_Slider, GetSelEnd);
	Gura_AssignMethod(wx_Slider, GetSelStart);
	Gura_AssignMethod(wx_Slider, GetThumbLength);
	Gura_AssignMethod(wx_Slider, GetTickFreq);
	Gura_AssignMethod(wx_Slider, GetValue);
	Gura_AssignMethod(wx_Slider, SetLineSize);
	Gura_AssignMethod(wx_Slider, SetPageSize);
	Gura_AssignMethod(wx_Slider, SetRange);
	Gura_AssignMethod(wx_Slider, SetSelection);
	Gura_AssignMethod(wx_Slider, SetThumbLength);
	Gura_AssignMethod(wx_Slider, SetTick);
	Gura_AssignMethod(wx_Slider, SetTickFreq);
	Gura_AssignMethod(wx_Slider, SetValue);
}

Gura_ImplementDescendantCreator(wx_Slider)
{
	return new Object_wx_Slider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
