//----------------------------------------------------------------------------
// wxRibbonButtonBar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONBUTTONBAR_H__
#define __CLASS_WX_RIBBONBUTTONBAR_H__
#include <wx/ribbon/buttonbar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonButtonBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonButtonBar);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonButtonBar
//----------------------------------------------------------------------------
class Object_wx_RibbonButtonBar : public Object_wx_RibbonControl {
public:
	Gura_DeclareObjectAccessor(wx_RibbonButtonBar)
public:
	inline Object_wx_RibbonButtonBar(wxRibbonButtonBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(Gura_UserClass(wx_RibbonButtonBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonButtonBar(Class *pClass, wxRibbonButtonBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonButtonBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonButtonBar *GetEntity() {
		return static_cast<wxRibbonButtonBar *>(_pEntity);
	}
	inline wxRibbonButtonBar *ReleaseEntity() {
		wxRibbonButtonBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRibbonButtonBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
