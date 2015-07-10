//----------------------------------------------------------------------------
// wxCalendarEvent
// extracted from calctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CalendarEvent: public wxCalendarEvent, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_CalendarEvent *_pObj;
public:
	~wx_CalendarEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CalendarEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CalendarEvent::~wx_CalendarEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CalendarEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_CalendarEvent, GetWeekDay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CalendarEvent, GetWeekDay)
{
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::WeekDay rtn = pThis->GetEntity()->GetWeekDay();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_CalendarEvent, SetWeekDay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalendarEvent, SetWeekDay)
{
	Object_wx_CalendarEvent *pThis = Object_wx_CalendarEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::WeekDay day = static_cast<wxDateTime::WeekDay>(args.GetInt(0));
	pThis->GetEntity()->SetWeekDay(day);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCalendarEvent
//----------------------------------------------------------------------------
Object_wx_CalendarEvent::~Object_wx_CalendarEvent()
{
}

Object *Object_wx_CalendarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CalendarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CalendarEvent:");
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
// Class implementation for wxCalendarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarEvent)
{
	Gura_AssignMethod(wx_CalendarEvent, GetWeekDay);
	Gura_AssignMethod(wx_CalendarEvent, SetWeekDay);
}

Gura_ImplementDescendantCreator(wx_CalendarEvent)
{
	return new Object_wx_CalendarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
