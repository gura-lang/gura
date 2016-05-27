//----------------------------------------------------------------------------
// wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COLLAPSIBLEHEADERCTRL_H__
#define __CLASS_WX_COLLAPSIBLEHEADERCTRL_H__
#include <wx/collheaderctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CollapsibleHeaderCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
class Object_wx_CollapsibleHeaderCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_CollapsibleHeaderCtrl)
public:
	inline Object_wx_CollapsibleHeaderCtrl(wxCollapsibleHeaderCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_CollapsibleHeaderCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CollapsibleHeaderCtrl(Class *pClass, wxCollapsibleHeaderCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CollapsibleHeaderCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCollapsibleHeaderCtrl *GetEntity() {
		return static_cast<wxCollapsibleHeaderCtrl *>(_pEntity);
	}
	inline wxCollapsibleHeaderCtrl *ReleaseEntity() {
		wxCollapsibleHeaderCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxCollapsibleHeaderCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
