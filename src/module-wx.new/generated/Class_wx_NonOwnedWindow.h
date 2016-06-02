//----------------------------------------------------------------------------
// wxNonOwnedWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NONOWNEDWINDOW_H__
#define __CLASS_WX_NONOWNEDWINDOW_H__
#include <wx/nonownedwnd.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNonOwnedWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NonOwnedWindow);

//----------------------------------------------------------------------------
// Object declaration for wxNonOwnedWindow
//----------------------------------------------------------------------------
class Object_wx_NonOwnedWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_NonOwnedWindow)
public:
	inline Object_wx_NonOwnedWindow(wxNonOwnedWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_NonOwnedWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NonOwnedWindow(Class *pClass, wxNonOwnedWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NonOwnedWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxNonOwnedWindow *GetEntity() {
		return static_cast<wxNonOwnedWindow *>(_pEntity);
	}
	inline wxNonOwnedWindow *ReleaseEntity() {
		wxNonOwnedWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxNonOwnedWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
