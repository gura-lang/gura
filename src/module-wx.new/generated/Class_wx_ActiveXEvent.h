//----------------------------------------------------------------------------
// wxActiveXEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ACTIVEXEVENT_H__
#define __CLASS_WX_ACTIVEXEVENT_H__
#include <wx/msw/ole/activex.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxActiveXEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ActiveXEvent);

//----------------------------------------------------------------------------
// Object declaration for wxActiveXEvent
//----------------------------------------------------------------------------
class Object_wx_ActiveXEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_ActiveXEvent)
public:
	inline Object_wx_ActiveXEvent(wxActiveXEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_ActiveXEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ActiveXEvent(Class *pClass, wxActiveXEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ActiveXEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxActiveXEvent *GetEntity() {
		return static_cast<wxActiveXEvent *>(_pEntity);
	}
	inline wxActiveXEvent *ReleaseEntity() {
		wxActiveXEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxActiveXEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
