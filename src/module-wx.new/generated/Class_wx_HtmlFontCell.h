//----------------------------------------------------------------------------
// wxHtmlFontCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLFONTCELL_H__
#define __CLASS_WX_HTMLFONTCELL_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlFontCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlFontCell);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlFontCell
//----------------------------------------------------------------------------
class Object_wx_HtmlFontCell : public Object_wx_HtmlCell {
public:
	Gura_DeclareObjectAccessor(wx_HtmlFontCell)
public:
	inline Object_wx_HtmlFontCell(wxHtmlFontCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(Gura_UserClass(wx_HtmlFontCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlFontCell(Class *pClass, wxHtmlFontCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlFontCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlFontCell *GetEntity() {
		return static_cast<wxHtmlFontCell *>(_pEntity);
	}
	inline wxHtmlFontCell *ReleaseEntity() {
		wxHtmlFontCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlFontCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
