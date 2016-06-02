//----------------------------------------------------------------------------
// wxHeaderCtrlEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HEADERCTRLEVENT_H__
#define __CLASS_WX_HEADERCTRLEVENT_H__
#include <wx/headerctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHeaderCtrlEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HeaderCtrlEvent);

//----------------------------------------------------------------------------
// Object declaration for wxHeaderCtrlEvent
//----------------------------------------------------------------------------
class Object_wx_HeaderCtrlEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_HeaderCtrlEvent)
public:
	inline Object_wx_HeaderCtrlEvent(wxHeaderCtrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_HeaderCtrlEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HeaderCtrlEvent(Class *pClass, wxHeaderCtrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HeaderCtrlEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHeaderCtrlEvent *GetEntity() {
		return static_cast<wxHeaderCtrlEvent *>(_pEntity);
	}
	inline wxHeaderCtrlEvent *ReleaseEntity() {
		wxHeaderCtrlEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHeaderCtrlEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
