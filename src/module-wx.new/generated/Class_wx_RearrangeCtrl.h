//----------------------------------------------------------------------------
// wxRearrangeCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REARRANGECTRL_H__
#define __CLASS_WX_REARRANGECTRL_H__
#include <wx/rearrangectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRearrangeCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RearrangeCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxRearrangeCtrl
//----------------------------------------------------------------------------
class Object_wx_RearrangeCtrl : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_RearrangeCtrl)
public:
	inline Object_wx_RearrangeCtrl(wxRearrangeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_RearrangeCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RearrangeCtrl(Class *pClass, wxRearrangeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RearrangeCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRearrangeCtrl *GetEntity() {
		return static_cast<wxRearrangeCtrl *>(_pEntity);
	}
	inline wxRearrangeCtrl *ReleaseEntity() {
		wxRearrangeCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRearrangeCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
