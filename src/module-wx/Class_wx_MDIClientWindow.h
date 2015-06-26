//----------------------------------------------------------------------------
// wxMDIClientWindow
// extracted from mdi.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MDICLIENTWINDOW_H__
#define __CLASS_WX_MDICLIENTWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMDIClientWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MDIClientWindow);

//----------------------------------------------------------------------------
// Object declaration for wxMDIClientWindow
//----------------------------------------------------------------------------
class Object_wx_MDIClientWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_MDIClientWindow)
public:
	inline Object_wx_MDIClientWindow(wxMDIClientWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_MDIClientWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MDIClientWindow(Class *pClass, wxMDIClientWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MDIClientWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMDIClientWindow *GetEntity() {
		return dynamic_cast<wxMDIClientWindow *>(_pEntity);
	}
	inline wxMDIClientWindow *ReleaseEntity() {
		wxMDIClientWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMDIClientWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
