//----------------------------------------------------------------------------
// wxHtmlHelpDialog
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLHELPDIALOG_H__
#define __OBJECT_WX_HTMLHELPDIALOG_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlHelpDialog);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlHelpDialog
//----------------------------------------------------------------------------
class Object_wx_HtmlHelpDialog : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_HtmlHelpDialog)
public:
	inline Object_wx_HtmlHelpDialog(wxHtmlHelpDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_HtmlHelpDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlHelpDialog(Class *pClass, wxHtmlHelpDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlHelpDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlHelpDialog *GetEntity() {
		return dynamic_cast<wxHtmlHelpDialog *>(_pEntity);
	}
	inline wxHtmlHelpDialog *ReleaseEntity() {
		wxHtmlHelpDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlHelpDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
