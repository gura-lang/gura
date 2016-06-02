//----------------------------------------------------------------------------
// wxRibbonBar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONBAR_H__
#define __CLASS_WX_RIBBONBAR_H__
#include <wx/ribbon/bar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonBar);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonBar
//----------------------------------------------------------------------------
class Object_wx_RibbonBar : public Object_wx_RibbonControl {
public:
	Gura_DeclareObjectAccessor(wx_RibbonBar)
public:
	inline Object_wx_RibbonBar(wxRibbonBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(Gura_UserClass(wx_RibbonBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonBar(Class *pClass, wxRibbonBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonBar *GetEntity() {
		return static_cast<wxRibbonBar *>(_pEntity);
	}
	inline wxRibbonBar *ReleaseEntity() {
		wxRibbonBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRibbonBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
