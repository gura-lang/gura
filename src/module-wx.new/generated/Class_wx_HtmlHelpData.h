//----------------------------------------------------------------------------
// wxHtmlHelpData
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLHELPDATA_H__
#define __CLASS_WX_HTMLHELPDATA_H__
#include <wx/html/helpdata.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlHelpData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlHelpData);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlHelpData
//----------------------------------------------------------------------------
class Object_wx_HtmlHelpData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlHelpData)
public:
	inline Object_wx_HtmlHelpData(wxHtmlHelpData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlHelpData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlHelpData(Class *pClass, wxHtmlHelpData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlHelpData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlHelpData *GetEntity() {
		return static_cast<wxHtmlHelpData *>(_pEntity);
	}
	inline wxHtmlHelpData *ReleaseEntity() {
		wxHtmlHelpData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlHelpData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
