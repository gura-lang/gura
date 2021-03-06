//----------------------------------------------------------------------------
// wxCalendarCtrl
// extracted from calctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CalendarCtrl: public wxCalendarCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CalendarCtrl *_pObj;
public:
	inline wx_CalendarCtrl() : wxCalendarCtrl(), _pObj(nullptr) {}
	inline wx_CalendarCtrl(wxWindow* parent, wxWindowID id, const wxDateTime& date, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxCalendarCtrl(parent, id, date, pos, size, style, name), _pObj(nullptr) {}
	~wx_CalendarCtrl();
	inline void AssocWithGura(Object_wx_CalendarCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CalendarCtrl::~wx_CalendarCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CalendarCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(CalendarCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CalendarCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CalendarCtrlEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_CalendarCtrl *pEntity = new wx_CalendarCtrl();
	Object_wx_CalendarCtrl *pObj = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CalendarCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(CalendarCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxDateTime *date = (wxDateTime *)(&wxDefaultDateTime);
	if (arg.IsValid(2)) date = Object_wx_DateTime::GetObject(arg, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxCAL_SHOW_HOLIDAYS;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxCalendarNameStr;
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_CalendarCtrl *pEntity = new wx_CalendarCtrl(parent, id, *date, *pos, *size, style, name);
	Object_wx_CalendarCtrl *pObj = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_CalendarCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_CalendarCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxDateTime *date = (wxDateTime *)(&wxDefaultDateTime);
	if (arg.IsValid(2)) date = Object_wx_DateTime::GetObject(arg, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxCAL_SHOW_HOLIDAYS;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxCalendarNameStr;
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, *date, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetDate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "date", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetDate)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *date = Object_wx_DateTime::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDate(*date);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetDate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetDate)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxDateTime &rtn = pThis->GetEntity()->GetDate();
	return ReturnValue(env, arg, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

#if 0
Gura_DeclareMethod(wx_CalendarCtrl, EnableYearChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableYearChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = true;
	if (arg.IsValid(0)) enable = arg.GetBoolean(0);
	pThis->GetEntity()->EnableYearChange(enable);
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_CalendarCtrl, EnableMonthChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableMonthChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = true;
	if (arg.IsValid(0)) enable = arg.GetBoolean(0);
	pThis->GetEntity()->EnableMonthChange(enable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, EnableHolidayDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "display", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, EnableHolidayDisplay)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool display = true;
	if (arg.IsValid(0)) display = arg.GetBoolean(0);
	pThis->GetEntity()->EnableHolidayDisplay(display);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHeaderColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colFg", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBg", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHeaderColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colFg = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	wxColour *colBg = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetHeaderColours(*colFg, *colBg);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHeaderColourFg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHeaderColourFg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetHeaderColourFg();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHeaderColourBg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHeaderColourBg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetHeaderColourBg();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHighlightColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colFg", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBg", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHighlightColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colFg = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	wxColour *colBg = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetHighlightColours(*colFg, *colBg);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHighlightColourFg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHighlightColourFg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetHighlightColourFg();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHighlightColourBg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHighlightColourBg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetHighlightColourBg();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHolidayColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colFg", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBg", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHolidayColours)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colFg = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	wxColour *colBg = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetHolidayColours(*colFg, *colBg);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHolidayColourFg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHolidayColourFg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetHolidayColourFg();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetHolidayColourBg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetHolidayColourBg)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetHolidayColourBg();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_CalendarCtrl, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, GetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t day = arg.GetSizeT(0);
	wxCalendarDateAttr *rtn = (wxCalendarDateAttr *)pThis->GetEntity()->GetAttr(day);
	return ReturnValue(env, arg, Value(new Object_wx_CalendarDateAttr(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_CalendarCtrl, SetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_CalendarDateAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t day = arg.GetSizeT(0);
	wxCalendarDateAttr *attr = Object_wx_CalendarDateAttr::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetAttr(day, new wxCalendarDateAttr(attr->GetTextColour(),
							attr->GetBackgroundColour(), attr->GetBorderColour(),
							attr->GetFont(), attr->GetBorder()));
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, SetHoliday)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, SetHoliday)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t day = arg.GetSizeT(0);
	pThis->GetEntity()->SetHoliday(day);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, ResetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarCtrl, ResetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t day = arg.GetSizeT(0);
	pThis->GetEntity()->ResetAttr(day);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CalendarCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "date", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "wd", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarCtrl, HitTest)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CalendarCtrl *pThis = Object_wx_CalendarCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pos = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	wxDateTime *date = (wxDateTime *)(nullptr);
	if (arg.IsValid(1)) date = Object_wx_DateTime::GetObject(arg, 1)->GetEntity();
	wxDateTime *wd = (wxDateTime *)(&nullptr);
	if (arg.IsValid(2)) wd = Object_wx_DateTime::GetObject(arg, 2)->GetEntity();
	wxCalendarHitTestResult rtn = pThis->GetEntity()->HitTest(*pos, date, *wd);
	return ReturnValue(env, arg, Value(new Object_wx_CalendarHitTestResult(new wxCalendarHitTestResult(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxCalendarCtrl
//----------------------------------------------------------------------------
Object_wx_CalendarCtrl::~Object_wx_CalendarCtrl()
{
}

Object *Object_wx_CalendarCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_CalendarCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.CalendarCtrl:");
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
// Class implementation for wxCalendarCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarCtrl)
{
	Gura_AssignWxStringValue(CalendarNameStr);
	Gura_AssignFunction(CalendarCtrlEmpty);
	Gura_AssignFunction(CalendarCtrl);
	Gura_AssignMethod(wx_CalendarCtrl, Create);
	Gura_AssignMethod(wx_CalendarCtrl, SetDate);
	Gura_AssignMethod(wx_CalendarCtrl, GetDate);
	//Gura_AssignMethod(wx_CalendarCtrl, EnableYearChange);
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
	return new Object_wx_CalendarCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
