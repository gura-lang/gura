//----------------------------------------------------------------------------
// wxRibbonControl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RIBBONCONTROL_H__
#define __CLASS_WX_RIBBONCONTROL_H__
#include <wx/ribbon/control.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRibbonControl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RibbonControl);

//----------------------------------------------------------------------------
// Object declaration for wxRibbonControl
//----------------------------------------------------------------------------
class Object_wx_RibbonControl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_RibbonControl)
public:
	inline Object_wx_RibbonControl(wxRibbonControl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_RibbonControl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RibbonControl(Class *pClass, wxRibbonControl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RibbonControl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRibbonControl *GetEntity() {
		return static_cast<wxRibbonControl *>(_pEntity);
	}
	inline wxRibbonControl *ReleaseEntity() {
		wxRibbonControl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRibbonControl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
