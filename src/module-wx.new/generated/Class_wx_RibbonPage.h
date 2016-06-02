//----------------------------------------------------------------------------
// wxRibbonPage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONPAGE_H__
#define __CLASS_WX_RIBBONPAGE_H__
#include <wx/ribbon/page.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonPage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonPage);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonPage
//----------------------------------------------------------------------------
class Object_wx_RibbonPage : public Object_wx_RibbonControl {
public:
	Gura_DeclareObjectAccessor(wx_RibbonPage)
public:
	inline Object_wx_RibbonPage(wxRibbonPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(Gura_UserClass(wx_RibbonPage), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonPage(Class *pClass, wxRibbonPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonPage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonPage *GetEntity() {
		return static_cast<wxRibbonPage *>(_pEntity);
	}
	inline wxRibbonPage *ReleaseEntity() {
		wxRibbonPage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRibbonPage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
