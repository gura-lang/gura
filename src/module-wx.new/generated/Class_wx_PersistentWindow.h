//----------------------------------------------------------------------------
// wxPersistentWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PERSISTENTWINDOW_H__
#define __CLASS_WX_PERSISTENTWINDOW_H__
#include <wx/persist/window.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPersistentWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PersistentWindow);

//----------------------------------------------------------------------------
// Object declaration for wxPersistentWindow
//----------------------------------------------------------------------------
class Object_wx_PersistentWindow : public Object_wx_PersistentObject {
public:
	Gura_DeclareObjectAccessor(wx_PersistentWindow)
public:
	inline Object_wx_PersistentWindow(wxPersistentWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentObject(Gura_UserClass(wx_PersistentWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PersistentWindow(Class *pClass, wxPersistentWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PersistentObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PersistentWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPersistentWindow *GetEntity() {
		return static_cast<wxPersistentWindow *>(_pEntity);
	}
	inline wxPersistentWindow *ReleaseEntity() {
		wxPersistentWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPersistentWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
