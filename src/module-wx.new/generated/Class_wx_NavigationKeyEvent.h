//----------------------------------------------------------------------------
// wxNavigationKeyEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NAVIGATIONKEYEVENT_H__
#define __CLASS_WX_NAVIGATIONKEYEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNavigationKeyEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NavigationKeyEvent);

//----------------------------------------------------------------------------
// Object declaration for wxNavigationKeyEvent
//----------------------------------------------------------------------------
class Object_wx_NavigationKeyEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_NavigationKeyEvent)
public:
	inline Object_wx_NavigationKeyEvent(wxNavigationKeyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_NavigationKeyEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NavigationKeyEvent(Class *pClass, wxNavigationKeyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NavigationKeyEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxNavigationKeyEvent *GetEntity() {
		return static_cast<wxNavigationKeyEvent *>(_pEntity);
	}
	inline wxNavigationKeyEvent *ReleaseEntity() {
		wxNavigationKeyEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxNavigationKeyEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
