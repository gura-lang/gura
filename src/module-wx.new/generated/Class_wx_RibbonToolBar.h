//----------------------------------------------------------------------------
// wxRibbonToolBar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONTOOLBAR_H__
#define __CLASS_WX_RIBBONTOOLBAR_H__
#include <wx/ribbon/toolbar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonToolBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonToolBar);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonToolBar
//----------------------------------------------------------------------------
class Object_wx_RibbonToolBar : public Object_wx_RibbonControl {
public:
	Gura_DeclareObjectAccessor(wx_RibbonToolBar)
public:
	inline Object_wx_RibbonToolBar(wxRibbonToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(Gura_UserClass(wx_RibbonToolBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonToolBar(Class *pClass, wxRibbonToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonToolBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonToolBar *GetEntity() {
		return static_cast<wxRibbonToolBar *>(_pEntity);
	}
	inline wxRibbonToolBar *ReleaseEntity() {
		wxRibbonToolBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRibbonToolBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
