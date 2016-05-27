//----------------------------------------------------------------------------
// wxTimerEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TIMEREVENT_H__
#define __CLASS_WX_TIMEREVENT_H__
#include <wx/timer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTimerEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TimerEvent);

//----------------------------------------------------------------------------
// Object declaration for wxTimerEvent
//----------------------------------------------------------------------------
class Object_wx_TimerEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_TimerEvent)
public:
	inline Object_wx_TimerEvent(wxTimerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_TimerEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TimerEvent(Class *pClass, wxTimerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TimerEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTimerEvent *GetEntity() {
		return static_cast<wxTimerEvent *>(_pEntity);
	}
	inline wxTimerEvent *ReleaseEntity() {
		wxTimerEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTimerEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
