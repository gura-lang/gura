//----------------------------------------------------------------------------
// wxRibbonGallery
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONGALLERY_H__
#define __CLASS_WX_RIBBONGALLERY_H__
#include <wx/ribbon/gallery.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonGallery
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonGallery);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonGallery
//----------------------------------------------------------------------------
class Object_wx_RibbonGallery : public Object_wx_RibbonControl {
public:
	Gura_DeclareObjectAccessor(wx_RibbonGallery)
public:
	inline Object_wx_RibbonGallery(wxRibbonGallery *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(Gura_UserClass(wx_RibbonGallery), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonGallery(Class *pClass, wxRibbonGallery *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonGallery();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonGallery *GetEntity() {
		return static_cast<wxRibbonGallery *>(_pEntity);
	}
	inline wxRibbonGallery *ReleaseEntity() {
		wxRibbonGallery *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRibbonGallery");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
