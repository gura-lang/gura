//----------------------------------------------------------------------------
// wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBKITSTATECHANGEDEVENT_H__
#define __CLASS_WX_WEBKITSTATECHANGEDEVENT_H__
#include <wx/html/webkit.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebKitStateChangedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
class Object_wx_WebKitStateChangedEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_WebKitStateChangedEvent)
public:
	inline Object_wx_WebKitStateChangedEvent(wxWebKitStateChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_WebKitStateChangedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebKitStateChangedEvent(Class *pClass, wxWebKitStateChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebKitStateChangedEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebKitStateChangedEvent *GetEntity() {
		return static_cast<wxWebKitStateChangedEvent *>(_pEntity);
	}
	inline wxWebKitStateChangedEvent *ReleaseEntity() {
		wxWebKitStateChangedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWebKitStateChangedEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
