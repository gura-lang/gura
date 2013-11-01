//----------------------------------------------------------------------------
// wxCalendarEvent
// extracted from calctrl.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CALENDAREVENT_H__
#define __CLASS_WX_CALENDAREVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCalendarEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CalendarEvent);

//----------------------------------------------------------------------------
// Object declaration for wxCalendarEvent
//----------------------------------------------------------------------------
class Object_wx_CalendarEvent : public Object_wx_DateEvent {
public:
	Gura_DeclareObjectAccessor(wx_CalendarEvent)
public:
	inline Object_wx_CalendarEvent(wxCalendarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DateEvent(Gura_UserClass(wx_CalendarEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CalendarEvent(Class *pClass, wxCalendarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DateEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CalendarEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCalendarEvent *GetEntity() {
		return dynamic_cast<wxCalendarEvent *>(_pEntity);
	}
	inline wxCalendarEvent *ReleaseEntity() {
		wxCalendarEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCalendarEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
