//----------------------------------------------------------------------------
// wxPopupTransientWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POPUPTRANSIENTWINDOW_H__
#define __CLASS_WX_POPUPTRANSIENTWINDOW_H__
#include <wx/popupwin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPopupTransientWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PopupTransientWindow);

//----------------------------------------------------------------------------
// Object declaration for wxPopupTransientWindow
//----------------------------------------------------------------------------
class Object_wx_PopupTransientWindow : public Object_wx_PopupWindow {
public:
	Gura_DeclareObjectAccessor(wx_PopupTransientWindow)
public:
	inline Object_wx_PopupTransientWindow(wxPopupTransientWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PopupWindow(Gura_UserClass(wx_PopupTransientWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PopupTransientWindow(Class *pClass, wxPopupTransientWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PopupWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PopupTransientWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPopupTransientWindow *GetEntity() {
		return static_cast<wxPopupTransientWindow *>(_pEntity);
	}
	inline wxPopupTransientWindow *ReleaseEntity() {
		wxPopupTransientWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPopupTransientWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
