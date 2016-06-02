//----------------------------------------------------------------------------
// wxDisplayChangedEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DISPLAYCHANGEDEVENT_H__
#define __CLASS_WX_DISPLAYCHANGEDEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDisplayChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DisplayChangedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxDisplayChangedEvent
//----------------------------------------------------------------------------
class Object_wx_DisplayChangedEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_DisplayChangedEvent)
public:
	inline Object_wx_DisplayChangedEvent(wxDisplayChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_DisplayChangedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DisplayChangedEvent(Class *pClass, wxDisplayChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DisplayChangedEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDisplayChangedEvent *GetEntity() {
		return static_cast<wxDisplayChangedEvent *>(_pEntity);
	}
	inline wxDisplayChangedEvent *ReleaseEntity() {
		wxDisplayChangedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDisplayChangedEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
