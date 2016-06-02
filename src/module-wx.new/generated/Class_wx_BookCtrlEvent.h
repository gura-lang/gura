//----------------------------------------------------------------------------
// wxBookCtrlEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BOOKCTRLEVENT_H__
#define __CLASS_WX_BOOKCTRLEVENT_H__
#include <wx/bookctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBookCtrlEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BookCtrlEvent);

//----------------------------------------------------------------------------
// Object declaration for wxBookCtrlEvent
//----------------------------------------------------------------------------
class Object_wx_BookCtrlEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_BookCtrlEvent)
public:
	inline Object_wx_BookCtrlEvent(wxBookCtrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_BookCtrlEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BookCtrlEvent(Class *pClass, wxBookCtrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BookCtrlEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBookCtrlEvent *GetEntity() {
		return static_cast<wxBookCtrlEvent *>(_pEntity);
	}
	inline wxBookCtrlEvent *ReleaseEntity() {
		wxBookCtrlEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxBookCtrlEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
