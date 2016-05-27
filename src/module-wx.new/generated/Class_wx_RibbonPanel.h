//----------------------------------------------------------------------------
// wxRibbonPanel
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONPANEL_H__
#define __CLASS_WX_RIBBONPANEL_H__
#include <wx/ribbon/panel.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonPanel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonPanel);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonPanel
//----------------------------------------------------------------------------
class Object_wx_RibbonPanel : public Object_wx_RibbonControl {
public:
	Gura_DeclareObjectAccessor(wx_RibbonPanel)
public:
	inline Object_wx_RibbonPanel(wxRibbonPanel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(Gura_UserClass(wx_RibbonPanel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonPanel(Class *pClass, wxRibbonPanel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RibbonControl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonPanel();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonPanel *GetEntity() {
		return static_cast<wxRibbonPanel *>(_pEntity);
	}
	inline wxRibbonPanel *ReleaseEntity() {
		wxRibbonPanel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRibbonPanel");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
