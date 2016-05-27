//----------------------------------------------------------------------------
// wxRibbonPanelEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONPANELEVENT_H__
#define __CLASS_WX_RIBBONPANELEVENT_H__
#include <wx/ribbon/panel.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonPanelEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonPanelEvent);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonPanelEvent
//----------------------------------------------------------------------------
class Object_wx_RibbonPanelEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_RibbonPanelEvent)
public:
	inline Object_wx_RibbonPanelEvent(wxRibbonPanelEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_RibbonPanelEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonPanelEvent(Class *pClass, wxRibbonPanelEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonPanelEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonPanelEvent *GetEntity() {
		return static_cast<wxRibbonPanelEvent *>(_pEntity);
	}
	inline wxRibbonPanelEvent *ReleaseEntity() {
		wxRibbonPanelEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRibbonPanelEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
