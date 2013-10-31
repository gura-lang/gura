//----------------------------------------------------------------------------
// wxSplitterWindow
// extracted from splitter.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SPLITTERWINDOW_H__
#define __OBJECT_WX_SPLITTERWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSplitterWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SplitterWindow);

//----------------------------------------------------------------------------
// Object declaration for wxSplitterWindow
//----------------------------------------------------------------------------
class Object_wx_SplitterWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_SplitterWindow)
public:
	inline Object_wx_SplitterWindow(wxSplitterWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_SplitterWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SplitterWindow(Class *pClass, wxSplitterWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SplitterWindow();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSplitterWindow *GetEntity() {
		return dynamic_cast<wxSplitterWindow *>(_pEntity);
	}
	inline wxSplitterWindow *ReleaseEntity() {
		wxSplitterWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSplitterWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
