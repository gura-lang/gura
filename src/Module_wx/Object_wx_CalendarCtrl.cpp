//----------------------------------------------------------------------------
// wxCalendarCtrl
// extracted from calctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CalendarCtrl: public wxCalendarCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CalendarCtrl *_pObj;
public:
	inline wx_CalendarCtrl() : wxCalendarCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_CalendarCtrl(wxWindow* parent, wxWindowID id, const wxDateTime& date, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxCalendarCtrl(parent, id, date, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_CalendarCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CalendarCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CalendarCtrl::~wx_CalendarCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CalendarCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(CalendarCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CalendarCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_CalendarCtrl *pEntity = new wx_CalendarCtrl();
	Object_wx_CalendarCtrl *pObj = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CalendarCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(CalendarCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CalendarCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "date", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxDateTime *date = (wxDateTime *)(&wxDefaultDateTime);
	if (args.IsValid(2)) date = Object_wx_DateTime::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxCAL_SHOW_HOLIDAYS;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxCalendarNameStr;
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_CalendarCtrl *pEntity = new wx_CalendarCtrl(parent, id, *date, *pos, *size, style, name);
	Object_wx_CalendarCtrl *pObj = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CalendarCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_CalendarCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "date", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, Create)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxDateTime *date = (wxDateTime *)(&wxDefaultDateTime);
	if (args.IsValid(2)) date = Object_wx_DateTime::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxCAL_SHOW_HOLIDAYS;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxCalendarNameStr;
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, *date, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetDate)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "date", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetDate)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *date = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDate(*date);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetDate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetDate)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxDateTime &rtn = pThis->GetEntity()->GetDate();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, EnableYearChange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableYearChange)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableYearChange(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, EnableMonthChange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableMonthChange)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableMonthChange(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, EnableHolidayDisplay)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "display", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableHolidayDisplay)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool display = true;
	if (args.IsValid(0)) display = args.GetBoolean(0);
	pThis->GetEntity()->EnableHolidayDisplay(display);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHeaderColours)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colFg", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBg", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHeaderColours)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colFg = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBg = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetHeaderColours(*colFg, *colBg);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHeaderColourFg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHeaderColourFg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetHeaderColourFg();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHeaderColourBg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHeaderColourBg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetHeaderColourBg();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHighlightColours)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colFg", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBg", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHighlightColours)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colFg = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBg = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetHighlightColours(*colFg, *colBg);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHighlightColourFg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHighlightColourFg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetHighlightColourFg();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHighlightColourBg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHighlightColourBg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetHighlightColourBg();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHolidayColours)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colFg", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBg", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHolidayColours)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colFg = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBg = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetHolidayColours(*colFg, *colBg);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHolidayColourFg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHolidayColourFg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetHolidayColourFg();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHolidayColourBg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHolidayColourBg)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetHolidayColourBg();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetAttr)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t day = args.GetSizeT(0);
	wxCalendarDateAttr *rtn = (wxCalendarDateAttr *)pThis->GetEntity()->GetAttr(day);
	return ReturnValue(env, sig, args, Value(new Object_wx_CalendarDateAttr(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetAttr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_CalendarDateAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetAttr)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t day = args.GetSizeT(0);
	wxCalendarDateAttr *attr = Object_wx_CalendarDateAttr::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetAttr(day, new wxCalendarDateAttr(attr->GetTextColour(),
							attr->GetBackgroundColour(), attr->GetBorderColour(),
							attr->GetFont(), attr->GetBorder()));
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHoliday)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHoliday)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t day = args.GetSizeT(0);
	pThis->GetEntity()->SetHoliday(day);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, ResetAttr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, ResetAttr)
{
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t day = args.GetSizeT(0);
	pThis->GetEntity()->ResetAttr(day);
	return Value::Null;
}

Gura_DeclareMethod(wx_CalendarCtrl, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "date", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "wd", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, HitTest)
{
#if 0
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pos = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxDateTime *date = (wxDateTime *)(NULL);
	if (args.IsValid(1)) date = Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	wxDateTime *wd = (wxDateTime *)(&NULL);
	if (args.IsValid(2)) wd = Object_wx_DateTime::GetObject(args, 2)->GetEntity();
	wxCalendarHitTestResult rtn = pThis->GetEntity()->HitTest(*pos, date, *wd);
	return ReturnValue(env, sig, args, Value(new Object_wx_CalendarHitTestResult(new wxCalendarHitTestResult(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCalendarCtrl
//----------------------------------------------------------------------------
Object_wx_CalendarCtrl::~Object_wx_CalendarCtrl()
{
}

Object *Object_wx_CalendarCtrl::Clone() const
{
	return NULL;
}

String Object_wx_CalendarCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CalendarCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_CalendarCtrl::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignWxStringValue(CalendarNameStr);
	Gura_AssignFunction(CalendarCtrlEmpty);
	Gura_AssignFunction(CalendarCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxCalendarCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarCtrl)
{
	Gura_AssignMethod(wx_CalendarCtrl, Create);
	Gura_AssignMethod(wx_CalendarCtrl, SetDate);
	Gura_AssignMethod(wx_CalendarCtrl, GetDate);
	Gura_AssignMethod(wx_CalendarCtrl, EnableYearChange);
	Gura_AssignMethod(wx_CalendarCtrl, EnableMonthChange);
	Gura_AssignMethod(wx_CalendarCtrl, EnableHolidayDisplay);
	Gura_AssignMethod(wx_CalendarCtrl, SetHeaderColours);
	Gura_AssignMethod(wx_CalendarCtrl, GetHeaderColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHeaderColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, SetHighlightColours);
	Gura_AssignMethod(wx_CalendarCtrl, GetHighlightColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHighlightColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, SetHolidayColours);
	Gura_AssignMethod(wx_CalendarCtrl, GetHolidayColourFg);
	Gura_AssignMethod(wx_CalendarCtrl, GetHolidayColourBg);
	Gura_AssignMethod(wx_CalendarCtrl, GetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, SetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, SetHoliday);
	Gura_AssignMethod(wx_CalendarCtrl, ResetAttr);
	Gura_AssignMethod(wx_CalendarCtrl, HitTest);
}

Gura_ImplementDescendantCreator(wx_CalendarCtrl)
{
	return new Object_wx_CalendarCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
