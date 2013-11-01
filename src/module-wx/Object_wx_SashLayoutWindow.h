//----------------------------------------------------------------------------
// wxSashLayoutWindow
// extracted from sashlayw.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SASHLAYOUTWINDOW_H__
#define __OBJECT_WX_SASHLAYOUTWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SashLayoutWindow);

//----------------------------------------------------------------------------
// Object declaration for wxSashLayoutWindow
//----------------------------------------------------------------------------
class Object_wx_SashLayoutWindow : public Object_wx_SashWindow {
public:
	Gura_DeclareObjectAccessor(wx_SashLayoutWindow)
public:
	inline Object_wx_SashLayoutWindow(wxSashLayoutWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SashWindow(Gura_UserClass(wx_SashLayoutWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SashLayoutWindow(Class *pClass, wxSashLayoutWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SashWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SashLayoutWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSashLayoutWindow *GetEntity() {
		return dynamic_cast<wxSashLayoutWindow *>(_pEntity);
	}
	inline wxSashLayoutWindow *ReleaseEntity() {
		wxSashLayoutWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSashLayoutWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
