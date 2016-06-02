//----------------------------------------------------------------------------
// wxPowerEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POWEREVENT_H__
#define __CLASS_WX_POWEREVENT_H__
#include <wx/power.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPowerEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PowerEvent);

//----------------------------------------------------------------------------
// Object declaration for wxPowerEvent
//----------------------------------------------------------------------------
class Object_wx_PowerEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_PowerEvent)
public:
	inline Object_wx_PowerEvent(wxPowerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_PowerEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PowerEvent(Class *pClass, wxPowerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PowerEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPowerEvent *GetEntity() {
		return static_cast<wxPowerEvent *>(_pEntity);
	}
	inline wxPowerEvent *ReleaseEntity() {
		wxPowerEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPowerEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
