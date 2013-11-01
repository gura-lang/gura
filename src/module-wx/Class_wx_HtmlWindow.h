//----------------------------------------------------------------------------
// wxHtmlWindow
// extracted from htwindow.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLWINDOW_H__
#define __OBJECT_WX_HTMLWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWindow);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWindow
//----------------------------------------------------------------------------
class Object_wx_HtmlWindow : public Object_wx_ScrolledWindow {
public:
	Gura_DeclareObjectAccessor(wx_HtmlWindow)
public:
	inline Object_wx_HtmlWindow(wxHtmlWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScrolledWindow(Gura_UserClass(wx_HtmlWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlWindow(Class *pClass, wxHtmlWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScrolledWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlWindow *GetEntity() {
		return dynamic_cast<wxHtmlWindow *>(_pEntity);
	}
	inline wxHtmlWindow *ReleaseEntity() {
		wxHtmlWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
