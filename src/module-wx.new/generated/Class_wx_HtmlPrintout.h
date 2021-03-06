//----------------------------------------------------------------------------
// wxHtmlPrintout
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLPRINTOUT_H__
#define __CLASS_WX_HTMLPRINTOUT_H__
#include <wx/html/htmprint.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlPrintout);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlPrintout
//----------------------------------------------------------------------------
class Object_wx_HtmlPrintout : public Object_wx_Printout {
public:
	Gura_DeclareObjectAccessor(wx_HtmlPrintout)
public:
	inline Object_wx_HtmlPrintout(wxHtmlPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Printout(Gura_UserClass(wx_HtmlPrintout), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlPrintout(Class *pClass, wxHtmlPrintout *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Printout(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlPrintout();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlPrintout *GetEntity() {
		return static_cast<wxHtmlPrintout *>(_pEntity);
	}
	inline wxHtmlPrintout *ReleaseEntity() {
		wxHtmlPrintout *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlPrintout");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
