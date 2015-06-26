//----------------------------------------------------------------------------
// wxJoystickEvent
// extracted from joyevent.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_JOYSTICKEVENT_H__
#define __CLASS_WX_JOYSTICKEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxJoystickEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_JoystickEvent);

//----------------------------------------------------------------------------
// Object declaration for wxJoystickEvent
//----------------------------------------------------------------------------
class Object_wx_JoystickEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_JoystickEvent)
public:
	inline Object_wx_JoystickEvent(wxJoystickEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_JoystickEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_JoystickEvent(Class *pClass, wxJoystickEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_JoystickEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxJoystickEvent *GetEntity() {
		return dynamic_cast<wxJoystickEvent *>(_pEntity);
	}
	inline wxJoystickEvent *ReleaseEntity() {
		wxJoystickEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxJoystickEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
