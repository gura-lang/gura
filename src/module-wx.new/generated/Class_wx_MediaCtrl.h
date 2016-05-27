//----------------------------------------------------------------------------
// wxMediaCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MEDIACTRL_H__
#define __CLASS_WX_MEDIACTRL_H__
#include <wx/mediactrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMediaCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MediaCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxMediaCtrl
//----------------------------------------------------------------------------
class Object_wx_MediaCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_MediaCtrl)
public:
	inline Object_wx_MediaCtrl(wxMediaCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_MediaCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MediaCtrl(Class *pClass, wxMediaCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MediaCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMediaCtrl *GetEntity() {
		return static_cast<wxMediaCtrl *>(_pEntity);
	}
	inline wxMediaCtrl *ReleaseEntity() {
		wxMediaCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMediaCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
