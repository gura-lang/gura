//----------------------------------------------------------------------------
// wxSysColourChangedEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SYSCOLOURCHANGEDEVENT_H__
#define __CLASS_WX_SYSCOLOURCHANGEDEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SysColourChangedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSysColourChangedEvent
//----------------------------------------------------------------------------
class Object_wx_SysColourChangedEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_SysColourChangedEvent)
public:
	inline Object_wx_SysColourChangedEvent(wxSysColourChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_SysColourChangedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SysColourChangedEvent(Class *pClass, wxSysColourChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SysColourChangedEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSysColourChangedEvent *GetEntity() {
		return static_cast<wxSysColourChangedEvent *>(_pEntity);
	}
	inline wxSysColourChangedEvent *ReleaseEntity() {
		wxSysColourChangedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSysColourChangedEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
