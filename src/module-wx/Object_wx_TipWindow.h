//----------------------------------------------------------------------------
// wxTipWindow
// extracted from tipwin.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TIPWINDOW_H__
#define __OBJECT_WX_TIPWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTipWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TipWindow);

//----------------------------------------------------------------------------
// Object declaration for wxTipWindow
//----------------------------------------------------------------------------
class Object_wx_TipWindow : public Object_wx_PopupTransientWindow {
public:
	Gura_DeclareObjectAccessor(wx_TipWindow)
public:
	inline Object_wx_TipWindow(wxTipWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PopupTransientWindow(Gura_UserClass(wx_TipWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TipWindow(Class *pClass, wxTipWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PopupTransientWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TipWindow();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTipWindow *GetEntity() {
		return dynamic_cast<wxTipWindow *>(_pEntity);
	}
	inline wxTipWindow *ReleaseEntity() {
		wxTipWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTipWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
