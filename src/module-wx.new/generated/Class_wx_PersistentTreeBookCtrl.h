//----------------------------------------------------------------------------
// wxPersistentTreeBookCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PERSISTENTTREEBOOKCTRL_H__
#define __CLASS_WX_PERSISTENTTREEBOOKCTRL_H__
#include <wx/persist/treebook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPersistentTreeBookCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PersistentTreeBookCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxPersistentTreeBookCtrl
//----------------------------------------------------------------------------
class Object_wx_PersistentTreeBookCtrl : public Object_wx_PersistentBookCtrl {
public:
	Gura_DeclareObjectAccessor(wx_PersistentTreeBookCtrl)
public:
	inline Object_wx_PersistentTreeBookCtrl(wxPersistentTreeBookCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentBookCtrl(Gura_UserClass(wx_PersistentTreeBookCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PersistentTreeBookCtrl(Class *pClass, wxPersistentTreeBookCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentBookCtrl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PersistentTreeBookCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPersistentTreeBookCtrl *GetEntity() {
		return static_cast<wxPersistentTreeBookCtrl *>(_pEntity);
	}
	inline wxPersistentTreeBookCtrl *ReleaseEntity() {
		wxPersistentTreeBookCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPersistentTreeBookCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
