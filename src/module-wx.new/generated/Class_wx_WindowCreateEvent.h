//----------------------------------------------------------------------------
// wxWindowCreateEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOWCREATEEVENT_H__
#define __CLASS_WX_WINDOWCREATEEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindowCreateEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WindowCreateEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWindowCreateEvent
//----------------------------------------------------------------------------
class Object_wx_WindowCreateEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_WindowCreateEvent)
public:
	inline Object_wx_WindowCreateEvent(wxWindowCreateEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_WindowCreateEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WindowCreateEvent(Class *pClass, wxWindowCreateEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WindowCreateEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWindowCreateEvent *GetEntity() {
		return static_cast<wxWindowCreateEvent *>(_pEntity);
	}
	inline wxWindowCreateEvent *ReleaseEntity() {
		wxWindowCreateEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWindowCreateEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
