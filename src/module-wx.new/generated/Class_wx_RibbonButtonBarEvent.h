//----------------------------------------------------------------------------
// wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONBUTTONBAREVENT_H__
#define __CLASS_WX_RIBBONBUTTONBAREVENT_H__
#include <wx/ribbon/buttonbar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonButtonBarEvent);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
class Object_wx_RibbonButtonBarEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_RibbonButtonBarEvent)
public:
	inline Object_wx_RibbonButtonBarEvent(wxRibbonButtonBarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_RibbonButtonBarEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonButtonBarEvent(Class *pClass, wxRibbonButtonBarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonButtonBarEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonButtonBarEvent *GetEntity() {
		return static_cast<wxRibbonButtonBarEvent *>(_pEntity);
	}
	inline wxRibbonButtonBarEvent *ReleaseEntity() {
		wxRibbonButtonBarEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRibbonButtonBarEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
