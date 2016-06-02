//----------------------------------------------------------------------------
// wxPersistentBookCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PERSISTENTBOOKCTRL_H__
#define __CLASS_WX_PERSISTENTBOOKCTRL_H__
#include <wx/persist/bookctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPersistentBookCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PersistentBookCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxPersistentBookCtrl
//----------------------------------------------------------------------------
class Object_wx_PersistentBookCtrl : public Object_wx_PersistentWindow {
public:
	Gura_DeclareObjectAccessor(wx_PersistentBookCtrl)
public:
	inline Object_wx_PersistentBookCtrl(wxPersistentBookCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentWindow(Gura_UserClass(wx_PersistentBookCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PersistentBookCtrl(Class *pClass, wxPersistentBookCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PersistentBookCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPersistentBookCtrl *GetEntity() {
		return static_cast<wxPersistentBookCtrl *>(_pEntity);
	}
	inline wxPersistentBookCtrl *ReleaseEntity() {
		wxPersistentBookCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPersistentBookCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
