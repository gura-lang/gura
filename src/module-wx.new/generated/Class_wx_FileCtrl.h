//----------------------------------------------------------------------------
// wxFileCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILECTRL_H__
#define __CLASS_WX_FILECTRL_H__
#include <wx/filectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxFileCtrl
//----------------------------------------------------------------------------
class Object_wx_FileCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_FileCtrl)
public:
	inline Object_wx_FileCtrl(wxFileCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_FileCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileCtrl(Class *pClass, wxFileCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileCtrl *GetEntity() {
		return static_cast<wxFileCtrl *>(_pEntity);
	}
	inline wxFileCtrl *ReleaseEntity() {
		wxFileCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFileCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
