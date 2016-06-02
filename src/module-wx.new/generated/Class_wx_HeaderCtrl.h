//----------------------------------------------------------------------------
// wxHeaderCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HEADERCTRL_H__
#define __CLASS_WX_HEADERCTRL_H__
#include <wx/headerctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHeaderCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HeaderCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxHeaderCtrl
//----------------------------------------------------------------------------
class Object_wx_HeaderCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_HeaderCtrl)
public:
	inline Object_wx_HeaderCtrl(wxHeaderCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_HeaderCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HeaderCtrl(Class *pClass, wxHeaderCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HeaderCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHeaderCtrl *GetEntity() {
		return static_cast<wxHeaderCtrl *>(_pEntity);
	}
	inline wxHeaderCtrl *ReleaseEntity() {
		wxHeaderCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHeaderCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
