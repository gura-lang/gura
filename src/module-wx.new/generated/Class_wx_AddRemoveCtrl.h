//----------------------------------------------------------------------------
// wxAddRemoveCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ADDREMOVECTRL_H__
#define __CLASS_WX_ADDREMOVECTRL_H__
#include <wx/addremovectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AddRemoveCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxAddRemoveCtrl
//----------------------------------------------------------------------------
class Object_wx_AddRemoveCtrl : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_AddRemoveCtrl)
public:
	inline Object_wx_AddRemoveCtrl(wxAddRemoveCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_AddRemoveCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AddRemoveCtrl(Class *pClass, wxAddRemoveCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AddRemoveCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAddRemoveCtrl *GetEntity() {
		return static_cast<wxAddRemoveCtrl *>(_pEntity);
	}
	inline wxAddRemoveCtrl *ReleaseEntity() {
		wxAddRemoveCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAddRemoveCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
