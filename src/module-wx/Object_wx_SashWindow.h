//----------------------------------------------------------------------------
// wxSashWindow
// extracted from sashwin.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SASHWINDOW_H__
#define __OBJECT_WX_SASHWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSashWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SashWindow);

//----------------------------------------------------------------------------
// Object declaration for wxSashWindow
//----------------------------------------------------------------------------
class Object_wx_SashWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_SashWindow)
public:
	inline Object_wx_SashWindow(wxSashWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_SashWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SashWindow(Class *pClass, wxSashWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SashWindow();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSashWindow *GetEntity() {
		return dynamic_cast<wxSashWindow *>(_pEntity);
	}
	inline wxSashWindow *ReleaseEntity() {
		wxSashWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSashWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
