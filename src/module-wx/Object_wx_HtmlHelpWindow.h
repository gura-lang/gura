//----------------------------------------------------------------------------
// wxHtmlHelpWindow
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLHELPWINDOW_H__
#define __OBJECT_WX_HTMLHELPWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlHelpWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlHelpWindow);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlHelpWindow
//----------------------------------------------------------------------------
class Object_wx_HtmlHelpWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_HtmlHelpWindow)
public:
	inline Object_wx_HtmlHelpWindow(wxHtmlHelpWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_HtmlHelpWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlHelpWindow(Class *pClass, wxHtmlHelpWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlHelpWindow();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlHelpWindow *GetEntity() {
		return dynamic_cast<wxHtmlHelpWindow *>(_pEntity);
	}
	inline wxHtmlHelpWindow *ReleaseEntity() {
		wxHtmlHelpWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlHelpWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
