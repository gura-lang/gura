//----------------------------------------------------------------------------
// wxHtmlWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLWINDOW_H__
#define __CLASS_WX_HTMLWINDOW_H__
#include <wx/html/htmlwin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWindow);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWindow
//----------------------------------------------------------------------------
class Object_wx_HtmlWindow : public Object_wx_HtmlWindowInterface {
public:
	Gura_DeclareObjectAccessor(wx_HtmlWindow)
public:
	inline Object_wx_HtmlWindow(wxHtmlWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlWindowInterface(Gura_UserClass(wx_HtmlWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlWindow(Class *pClass, wxHtmlWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlWindowInterface(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlWindow *GetEntity() {
		return static_cast<wxHtmlWindow *>(_pEntity);
	}
	inline wxHtmlWindow *ReleaseEntity() {
		wxHtmlWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
