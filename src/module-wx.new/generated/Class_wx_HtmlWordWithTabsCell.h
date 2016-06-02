//----------------------------------------------------------------------------
// wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLWORDWITHTABSCELL_H__
#define __CLASS_WX_HTMLWORDWITHTABSCELL_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWordWithTabsCell);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
class Object_wx_HtmlWordWithTabsCell : public Object_wx_HtmlWordCell {
public:
	Gura_DeclareObjectAccessor(wx_HtmlWordWithTabsCell)
public:
	inline Object_wx_HtmlWordWithTabsCell(wxHtmlWordWithTabsCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlWordCell(Gura_UserClass(wx_HtmlWordWithTabsCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlWordWithTabsCell(Class *pClass, wxHtmlWordWithTabsCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlWordCell(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlWordWithTabsCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlWordWithTabsCell *GetEntity() {
		return static_cast<wxHtmlWordWithTabsCell *>(_pEntity);
	}
	inline wxHtmlWordWithTabsCell *ReleaseEntity() {
		wxHtmlWordWithTabsCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlWordWithTabsCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
