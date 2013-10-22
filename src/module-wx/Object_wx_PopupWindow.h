//----------------------------------------------------------------------------
// wxPopupWindow
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_POPUPWINDOW_H__
#define __OBJECT_WX_POPUPWINDOW_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPopupWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PopupWindow);

//----------------------------------------------------------------------------
// Object declaration for wxPopupWindow
//----------------------------------------------------------------------------
class Object_wx_PopupWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_PopupWindow)
public:
	inline Object_wx_PopupWindow(wxPopupWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_PopupWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PopupWindow(Class *pClass, wxPopupWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PopupWindow();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPopupWindow *GetEntity() {
		return dynamic_cast<wxPopupWindow *>(_pEntity);
	}
	inline wxPopupWindow *ReleaseEntity() {
		wxPopupWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPopupWindow");
		return true;
	}
};

}}

#endif
