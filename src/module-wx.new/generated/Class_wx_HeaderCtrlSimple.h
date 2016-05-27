//----------------------------------------------------------------------------
// wxHeaderCtrlSimple
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HEADERCTRLSIMPLE_H__
#define __CLASS_WX_HEADERCTRLSIMPLE_H__
#include <wx/headerctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHeaderCtrlSimple
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HeaderCtrlSimple);

//----------------------------------------------------------------------------
// Object declaration for wxHeaderCtrlSimple
//----------------------------------------------------------------------------
class Object_wx_HeaderCtrlSimple : public Object_wx_HeaderCtrl {
public:
	Gura_DeclareObjectAccessor(wx_HeaderCtrlSimple)
public:
	inline Object_wx_HeaderCtrlSimple(wxHeaderCtrlSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HeaderCtrl(Gura_UserClass(wx_HeaderCtrlSimple), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HeaderCtrlSimple(Class *pClass, wxHeaderCtrlSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HeaderCtrl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HeaderCtrlSimple();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHeaderCtrlSimple *GetEntity() {
		return static_cast<wxHeaderCtrlSimple *>(_pEntity);
	}
	inline wxHeaderCtrlSimple *ReleaseEntity() {
		wxHeaderCtrlSimple *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHeaderCtrlSimple");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
