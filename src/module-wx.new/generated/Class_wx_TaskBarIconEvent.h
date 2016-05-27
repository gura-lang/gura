//----------------------------------------------------------------------------
// wxTaskBarIconEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TASKBARICONEVENT_H__
#define __CLASS_WX_TASKBARICONEVENT_H__
#include <wx/taskbar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTaskBarIconEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TaskBarIconEvent);

//----------------------------------------------------------------------------
// Object declaration for wxTaskBarIconEvent
//----------------------------------------------------------------------------
class Object_wx_TaskBarIconEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_TaskBarIconEvent)
public:
	inline Object_wx_TaskBarIconEvent(wxTaskBarIconEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_TaskBarIconEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TaskBarIconEvent(Class *pClass, wxTaskBarIconEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TaskBarIconEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTaskBarIconEvent *GetEntity() {
		return static_cast<wxTaskBarIconEvent *>(_pEntity);
	}
	inline wxTaskBarIconEvent *ReleaseEntity() {
		wxTaskBarIconEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTaskBarIconEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
