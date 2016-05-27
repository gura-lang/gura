//----------------------------------------------------------------------------
// wxGridEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDEVENT_H__
#define __CLASS_WX_GRIDEVENT_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridEvent);

//----------------------------------------------------------------------------
// Object declaration for wxGridEvent
//----------------------------------------------------------------------------
class Object_wx_GridEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_GridEvent)
public:
	inline Object_wx_GridEvent(wxGridEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_GridEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridEvent(Class *pClass, wxGridEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridEvent *GetEntity() {
		return static_cast<wxGridEvent *>(_pEntity);
	}
	inline wxGridEvent *ReleaseEntity() {
		wxGridEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
