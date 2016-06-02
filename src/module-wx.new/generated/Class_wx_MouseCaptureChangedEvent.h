//----------------------------------------------------------------------------
// wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MOUSECAPTURECHANGEDEVENT_H__
#define __CLASS_WX_MOUSECAPTURECHANGEDEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MouseCaptureChangedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
class Object_wx_MouseCaptureChangedEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_MouseCaptureChangedEvent)
public:
	inline Object_wx_MouseCaptureChangedEvent(wxMouseCaptureChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_MouseCaptureChangedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MouseCaptureChangedEvent(Class *pClass, wxMouseCaptureChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MouseCaptureChangedEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMouseCaptureChangedEvent *GetEntity() {
		return static_cast<wxMouseCaptureChangedEvent *>(_pEntity);
	}
	inline wxMouseCaptureChangedEvent *ReleaseEntity() {
		wxMouseCaptureChangedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMouseCaptureChangedEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
