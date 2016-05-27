//----------------------------------------------------------------------------
// wxSearchCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SEARCHCTRL_H__
#define __CLASS_WX_SEARCHCTRL_H__
#include <wx/srchctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSearchCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SearchCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxSearchCtrl
//----------------------------------------------------------------------------
class Object_wx_SearchCtrl : public Object_wx_TextCtrl {
public:
	Gura_DeclareObjectAccessor(wx_SearchCtrl)
public:
	inline Object_wx_SearchCtrl(wxSearchCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextCtrl(Gura_UserClass(wx_SearchCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SearchCtrl(Class *pClass, wxSearchCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextCtrl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SearchCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSearchCtrl *GetEntity() {
		return static_cast<wxSearchCtrl *>(_pEntity);
	}
	inline wxSearchCtrl *ReleaseEntity() {
		wxSearchCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSearchCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
