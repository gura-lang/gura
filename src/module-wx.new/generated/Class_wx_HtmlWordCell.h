//----------------------------------------------------------------------------
// wxHtmlWordCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLWORDCELL_H__
#define __CLASS_WX_HTMLWORDCELL_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWordCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWordCell);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWordCell
//----------------------------------------------------------------------------
class Object_wx_HtmlWordCell : public Object_wx_HtmlCell {
public:
	Gura_DeclareObjectAccessor(wx_HtmlWordCell)
public:
	inline Object_wx_HtmlWordCell(wxHtmlWordCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(Gura_UserClass(wx_HtmlWordCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlWordCell(Class *pClass, wxHtmlWordCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlWordCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlWordCell *GetEntity() {
		return static_cast<wxHtmlWordCell *>(_pEntity);
	}
	inline wxHtmlWordCell *ReleaseEntity() {
		wxHtmlWordCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlWordCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
