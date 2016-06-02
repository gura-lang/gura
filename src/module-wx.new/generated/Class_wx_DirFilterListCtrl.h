//----------------------------------------------------------------------------
// wxDirFilterListCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIRFILTERLISTCTRL_H__
#define __CLASS_WX_DIRFILTERLISTCTRL_H__
#include <wx/dirctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDirFilterListCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DirFilterListCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxDirFilterListCtrl
//----------------------------------------------------------------------------
class Object_wx_DirFilterListCtrl : public Object_wx_Choice {
public:
	Gura_DeclareObjectAccessor(wx_DirFilterListCtrl)
public:
	inline Object_wx_DirFilterListCtrl(wxDirFilterListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Choice(Gura_UserClass(wx_DirFilterListCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DirFilterListCtrl(Class *pClass, wxDirFilterListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Choice(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DirFilterListCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDirFilterListCtrl *GetEntity() {
		return static_cast<wxDirFilterListCtrl *>(_pEntity);
	}
	inline wxDirFilterListCtrl *ReleaseEntity() {
		wxDirFilterListCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDirFilterListCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
