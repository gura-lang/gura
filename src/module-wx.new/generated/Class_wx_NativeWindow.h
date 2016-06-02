//----------------------------------------------------------------------------
// wxNativeWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NATIVEWINDOW_H__
#define __CLASS_WX_NATIVEWINDOW_H__
#include <wx/nativewin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNativeWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NativeWindow);

//----------------------------------------------------------------------------
// Object declaration for wxNativeWindow
//----------------------------------------------------------------------------
class Object_wx_NativeWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_NativeWindow)
public:
	inline Object_wx_NativeWindow(wxNativeWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_NativeWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NativeWindow(Class *pClass, wxNativeWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NativeWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxNativeWindow *GetEntity() {
		return static_cast<wxNativeWindow *>(_pEntity);
	}
	inline wxNativeWindow *ReleaseEntity() {
		wxNativeWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxNativeWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
