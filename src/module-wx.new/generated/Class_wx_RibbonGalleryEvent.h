//----------------------------------------------------------------------------
// wxRibbonGalleryEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONGALLERYEVENT_H__
#define __CLASS_WX_RIBBONGALLERYEVENT_H__
#include <wx/ribbon/gallery.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonGalleryEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonGalleryEvent);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonGalleryEvent
//----------------------------------------------------------------------------
class Object_wx_RibbonGalleryEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_RibbonGalleryEvent)
public:
	inline Object_wx_RibbonGalleryEvent(wxRibbonGalleryEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_RibbonGalleryEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonGalleryEvent(Class *pClass, wxRibbonGalleryEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonGalleryEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonGalleryEvent *GetEntity() {
		return static_cast<wxRibbonGalleryEvent *>(_pEntity);
	}
	inline wxRibbonGalleryEvent *ReleaseEntity() {
		wxRibbonGalleryEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRibbonGalleryEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
