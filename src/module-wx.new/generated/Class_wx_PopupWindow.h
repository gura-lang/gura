//----------------------------------------------------------------------------
// wxPopupWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POPUPWINDOW_H__
#define __CLASS_WX_POPUPWINDOW_H__
#include <wx/popupwin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPopupWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PopupWindow);

//----------------------------------------------------------------------------
// Object declaration for wxPopupWindow
//----------------------------------------------------------------------------
class Object_wx_PopupWindow : public Object_wx_NonOwnedWindow {
public:
	Gura_DeclareObjectAccessor(wx_PopupWindow)
public:
	inline Object_wx_PopupWindow(wxPopupWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NonOwnedWindow(Gura_UserClass(wx_PopupWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PopupWindow(Class *pClass, wxPopupWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NonOwnedWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PopupWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPopupWindow *GetEntity() {
		return static_cast<wxPopupWindow *>(_pEntity);
	}
	inline wxPopupWindow *ReleaseEntity() {
		wxPopupWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPopupWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
