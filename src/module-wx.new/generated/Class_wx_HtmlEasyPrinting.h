//----------------------------------------------------------------------------
// wxHtmlEasyPrinting
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLEASYPRINTING_H__
#define __CLASS_WX_HTMLEASYPRINTING_H__
#include <wx/html/htmprint.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlEasyPrinting);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
class Object_wx_HtmlEasyPrinting : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlEasyPrinting)
public:
	inline Object_wx_HtmlEasyPrinting(wxHtmlEasyPrinting *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlEasyPrinting), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlEasyPrinting(Class *pClass, wxHtmlEasyPrinting *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlEasyPrinting();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlEasyPrinting *GetEntity() {
		return static_cast<wxHtmlEasyPrinting *>(_pEntity);
	}
	inline wxHtmlEasyPrinting *ReleaseEntity() {
		wxHtmlEasyPrinting *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlEasyPrinting");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
