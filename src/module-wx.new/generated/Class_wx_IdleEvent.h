//----------------------------------------------------------------------------
// wxIdleEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_IDLEEVENT_H__
#define __CLASS_WX_IDLEEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIdleEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IdleEvent);

//----------------------------------------------------------------------------
// Object declaration for wxIdleEvent
//----------------------------------------------------------------------------
class Object_wx_IdleEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_IdleEvent)
public:
	inline Object_wx_IdleEvent(wxIdleEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_IdleEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IdleEvent(Class *pClass, wxIdleEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IdleEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxIdleEvent *GetEntity() {
		return static_cast<wxIdleEvent *>(_pEntity);
	}
	inline wxIdleEvent *ReleaseEntity() {
		wxIdleEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxIdleEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
