//----------------------------------------------------------------------------
// wxCalendarDateAttr
// extracted from calctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CalendarDateAttr: public wxCalendarDateAttr, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CalendarDateAttr *_pObj;
public:
	inline wx_CalendarDateAttr() : wxCalendarDateAttr(), _pObj(nullptr) {}
	inline wx_CalendarDateAttr(const wxColour& colText, const wxColour& colBack, const wxColour& colBorder, const wxFont& font, wxCalendarDateBorder border) : wxCalendarDateAttr(colText, colBack, colBorder, font, border), _pObj(nullptr) {}
	inline wx_CalendarDateAttr(wxCalendarDateBorder border, const wxColour& colBorder) : wxCalendarDateAttr(border, colBorder), _pObj(nullptr) {}
	~wx_CalendarDateAttr();
	inline void AssocWithGura(Object_wx_CalendarDateAttr *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CalendarDateAttr::~wx_CalendarDateAttr()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CalendarDateAttr::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(CalendarDateAttrEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CalendarDateAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarDateAttrEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_CalendarDateAttr *pEntity = new wx_CalendarDateAttr();
	Object_wx_CalendarDateAttr *pObj = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CalendarDateAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(CalendarDateAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CalendarDateAttr));
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "colBorder", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarDateAttr)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxColour *colText = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	wxColour *colBack = (wxColour *)(&wxNullColour);
	if (arg.IsValid(1)) colBack = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	wxColour *colBorder = (wxColour *)(&wxNullColour);
	if (arg.IsValid(2)) colBorder = Object_wx_Colour::GetObject(arg, 2)->GetEntity();
	wxFont *font = (wxFont *)(&wxNullFont);
	if (arg.IsValid(3)) font = Object_wx_Font::GetObject(arg, 3)->GetEntity();
	wxCalendarDateBorder border = wxCAL_BORDER_NONE;
	if (arg.IsValid(4)) border = static_cast<wxCalendarDateBorder>(arg.GetInt(4));
	wx_CalendarDateAttr *pEntity = new wx_CalendarDateAttr(*colText, *colBack, *colBorder, *font, border);
	Object_wx_CalendarDateAttr *pObj = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CalendarDateAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(CalendarDateAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CalendarDateAttr));
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colBorder", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarDateAttr_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxCalendarDateBorder border = static_cast<wxCalendarDateBorder>(arg.GetInt(0));
	wxColour *colBorder = (wxColour *)(&wxNullColour);
	if (arg.IsValid(1)) colBorder = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	wx_CalendarDateAttr *pEntity = new wx_CalendarDateAttr(border, *colBorder);
	Object_wx_CalendarDateAttr *pObj = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CalendarDateAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colText = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colText);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colBack = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colBack);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBorderColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBorderColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *col = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetBorderColour(*col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCalendarDateBorder border = static_cast<wxCalendarDateBorder>(arg.GetInt(0));
	pThis->GetEntity()->SetBorder(border);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetHoliday)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "holiday", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetHoliday)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool holiday = arg.GetBoolean(0);
	pThis->GetEntity()->SetHoliday(holiday);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasTextColour();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBorderColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBorderColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasBorderColour();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasFont();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasBorder();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, IsHoliday)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, IsHoliday)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsHoliday();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBorderColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBorderColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetBorderColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, arg, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCalendarDateBorder rtn = pThis->GetEntity()->GetBorder();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Object_wx_CalendarDateAttr::~Object_wx_CalendarDateAttr()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_CalendarDateAttr::Clone() const
{
	return nullptr;
}

String Object_wx_CalendarDateAttr::ToString(bool exprFlag)
{
	String rtn("<wx.CalendarDateAttr:");
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
// Class implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarDateAttr)
{
	Gura_AssignFunction(CalendarDateAttrEmpty);
	Gura_AssignFunction(CalendarDateAttr);
	Gura_AssignFunction(CalendarDateAttr_1);
	Gura_AssignMethod(wx_CalendarDateAttr, SetTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, SetBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, SetFont);
	Gura_AssignMethod(wx_CalendarDateAttr, SetBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, SetHoliday);
	Gura_AssignMethod(wx_CalendarDateAttr, HasTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, HasBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, HasFont);
	Gura_AssignMethod(wx_CalendarDateAttr, HasBorder);
	Gura_AssignMethod(wx_CalendarDateAttr, IsHoliday);
	Gura_AssignMethod(wx_CalendarDateAttr, GetTextColour);
	Gura_AssignMethod(wx_CalendarDateAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_CalendarDateAttr, GetBorderColour);
	Gura_AssignMethod(wx_CalendarDateAttr, GetFont);
	Gura_AssignMethod(wx_CalendarDateAttr, GetBorder);
}

Gura_ImplementDescendantCreator(wx_CalendarDateAttr)
{
	return new Object_wx_CalendarDateAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
