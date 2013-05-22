//----------------------------------------------------------------------------
// wxCalendarDateAttr
// extracted from calctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CalendarDateAttr: public wxCalendarDateAttr, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CalendarDateAttr *_pObj;
public:
	inline wx_CalendarDateAttr() : wxCalendarDateAttr(), _sig(NULL), _pObj(NULL) {}
	inline wx_CalendarDateAttr(const wxColour& colText, const wxColour& colBack, const wxColour& colBorder, const wxFont& font, wxCalendarDateBorder border) : wxCalendarDateAttr(colText, colBack, colBorder, font, border), _sig(NULL), _pObj(NULL) {}
	inline wx_CalendarDateAttr(wxCalendarDateBorder border, const wxColour& colBorder) : wxCalendarDateAttr(border, colBorder), _sig(NULL), _pObj(NULL) {}
	~wx_CalendarDateAttr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CalendarDateAttr *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CalendarDateAttr::~wx_CalendarDateAttr()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CalendarDateAttr::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(CalendarDateAttrEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CalendarDateAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarDateAttrEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_CalendarDateAttr *pEntity = new wx_CalendarDateAttr();
	Object_wx_CalendarDateAttr *pObj = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CalendarDateAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(CalendarDateAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBack = (wxColour *)(&wxNullColour);
	if (args.IsValid(1)) colBack = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour *colBorder = (wxColour *)(&wxNullColour);
	if (args.IsValid(2)) colBorder = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxFont *font = (wxFont *)(&wxNullFont);
	if (args.IsValid(3)) font = Object_wx_Font::GetObject(args, 3)->GetEntity();
	wxCalendarDateBorder border = wxCAL_BORDER_NONE;
	if (args.IsValid(4)) border = static_cast<wxCalendarDateBorder>(args.GetInt(4));
	wx_CalendarDateAttr *pEntity = new wx_CalendarDateAttr(*colText, *colBack, *colBorder, *font, border);
	Object_wx_CalendarDateAttr *pObj = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CalendarDateAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(CalendarDateAttr_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CalendarDateAttr));
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colBorder", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarDateAttr_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxCalendarDateBorder border = static_cast<wxCalendarDateBorder>(args.GetInt(0));
	wxColour *colBorder = (wxColour *)(&wxNullColour);
	if (args.IsValid(1)) colBorder = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wx_CalendarDateAttr *pEntity = new wx_CalendarDateAttr(border, *colBorder);
	Object_wx_CalendarDateAttr *pObj = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CalendarDateAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetTextColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colText);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBackgroundColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colBack = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colBack);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBorderColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBorderColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *col = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBorderColour(*col);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetFont)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetBorder)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetBorder)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCalendarDateBorder border = static_cast<wxCalendarDateBorder>(args.GetInt(0));
	pThis->GetEntity()->SetBorder(border);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarDateAttr, SetHoliday)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "holiday", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarDateAttr, SetHoliday)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool holiday = args.GetBoolean(0);
	pThis->GetEntity()->SetHoliday(holiday);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasTextColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBackgroundColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBorderColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBorderColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBorderColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasFont)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, HasBorder)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, HasBorder)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBorder();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, IsHoliday)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, IsHoliday)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsHoliday();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetTextColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBackgroundColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBorderColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBorderColour)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetBorderColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetFont)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarDateAttr, GetBorder)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarDateAttr, GetBorder)
{
	Object_wx_CalendarDateAttr *pThis = Object_wx_CalendarDateAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCalendarDateBorder rtn = pThis->GetEntity()->GetBorder();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Object_wx_CalendarDateAttr::~Object_wx_CalendarDateAttr()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_CalendarDateAttr::Clone() const
{
	return NULL;
}

String Object_wx_CalendarDateAttr::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CalendarDateAttr:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_CalendarDateAttr::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(CalendarDateAttrEmpty);
	Gura_AssignFunction(CalendarDateAttr);
	Gura_AssignFunction(CalendarDateAttr_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarDateAttr)
{
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
	return new Object_wx_CalendarDateAttr((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
