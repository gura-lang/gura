//----------------------------------------------------------------------------
// wxRibbonBarEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONBAREVENT_H__
#define __CLASS_WX_RIBBONBAREVENT_H__
#include <wx/ribbon/bar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonBarEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonBarEvent);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonBarEvent
//----------------------------------------------------------------------------
class Object_wx_RibbonBarEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_RibbonBarEvent)
public:
	inline Object_wx_RibbonBarEvent(wxRibbonBarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_RibbonBarEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonBarEvent(Class *pClass, wxRibbonBarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonBarEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonBarEvent *GetEntity() {
		return static_cast<wxRibbonBarEvent *>(_pEntity);
	}
	inline wxRibbonBarEvent *ReleaseEntity() {
		wxRibbonBarEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRibbonBarEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
