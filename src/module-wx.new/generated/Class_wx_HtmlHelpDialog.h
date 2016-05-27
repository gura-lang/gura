//----------------------------------------------------------------------------
// wxHtmlHelpDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLHELPDIALOG_H__
#define __CLASS_WX_HTMLHELPDIALOG_H__
#include <wx/html/helpdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlHelpDialog);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlHelpDialog
//----------------------------------------------------------------------------
class Object_wx_HtmlHelpDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_HtmlHelpDialog)
public:
	inline Object_wx_HtmlHelpDialog(wxHtmlHelpDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_HtmlHelpDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlHelpDialog(Class *pClass, wxHtmlHelpDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlHelpDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlHelpDialog *GetEntity() {
		return static_cast<wxHtmlHelpDialog *>(_pEntity);
	}
	inline wxHtmlHelpDialog *ReleaseEntity() {
		wxHtmlHelpDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlHelpDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
