//----------------------------------------------------------------------------
// wxScrollWinEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCROLLWINEVENT_H__
#define __CLASS_WX_SCROLLWINEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScrollWinEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScrollWinEvent);

//----------------------------------------------------------------------------
// Object declaration for wxScrollWinEvent
//----------------------------------------------------------------------------
class Object_wx_ScrollWinEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_ScrollWinEvent)
public:
	inline Object_wx_ScrollWinEvent(wxScrollWinEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_ScrollWinEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ScrollWinEvent(Class *pClass, wxScrollWinEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ScrollWinEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxScrollWinEvent *GetEntity() {
		return static_cast<wxScrollWinEvent *>(_pEntity);
	}
	inline wxScrollWinEvent *ReleaseEntity() {
		wxScrollWinEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxScrollWinEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
