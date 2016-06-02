//----------------------------------------------------------------------------
// wxNotifyEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NOTIFYEVENT_H__
#define __CLASS_WX_NOTIFYEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNotifyEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NotifyEvent);

//----------------------------------------------------------------------------
// Object declaration for wxNotifyEvent
//----------------------------------------------------------------------------
class Object_wx_NotifyEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_NotifyEvent)
public:
	inline Object_wx_NotifyEvent(wxNotifyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_NotifyEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NotifyEvent(Class *pClass, wxNotifyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NotifyEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxNotifyEvent *GetEntity() {
		return static_cast<wxNotifyEvent *>(_pEntity);
	}
	inline wxNotifyEvent *ReleaseEntity() {
		wxNotifyEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxNotifyEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
