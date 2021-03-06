//----------------------------------------------------------------------------
// wxScrollEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCROLLEVENT_H__
#define __CLASS_WX_SCROLLEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScrollEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScrollEvent);

//----------------------------------------------------------------------------
// Object declaration for wxScrollEvent
//----------------------------------------------------------------------------
class Object_wx_ScrollEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_ScrollEvent)
public:
	inline Object_wx_ScrollEvent(wxScrollEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_ScrollEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ScrollEvent(Class *pClass, wxScrollEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ScrollEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxScrollEvent *GetEntity() {
		return static_cast<wxScrollEvent *>(_pEntity);
	}
	inline wxScrollEvent *ReleaseEntity() {
		wxScrollEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxScrollEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
