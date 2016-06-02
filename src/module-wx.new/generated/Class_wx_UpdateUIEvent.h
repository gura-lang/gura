//----------------------------------------------------------------------------
// wxUpdateUIEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_UPDATEUIEVENT_H__
#define __CLASS_WX_UPDATEUIEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_UpdateUIEvent);

//----------------------------------------------------------------------------
// Object declaration for wxUpdateUIEvent
//----------------------------------------------------------------------------
class Object_wx_UpdateUIEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_UpdateUIEvent)
public:
	inline Object_wx_UpdateUIEvent(wxUpdateUIEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_UpdateUIEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_UpdateUIEvent(Class *pClass, wxUpdateUIEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_UpdateUIEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxUpdateUIEvent *GetEntity() {
		return static_cast<wxUpdateUIEvent *>(_pEntity);
	}
	inline wxUpdateUIEvent *ReleaseEntity() {
		wxUpdateUIEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxUpdateUIEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
