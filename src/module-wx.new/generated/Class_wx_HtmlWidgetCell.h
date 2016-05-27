//----------------------------------------------------------------------------
// wxHtmlWidgetCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLWIDGETCELL_H__
#define __CLASS_WX_HTMLWIDGETCELL_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWidgetCell);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWidgetCell
//----------------------------------------------------------------------------
class Object_wx_HtmlWidgetCell : public Object_wx_HtmlCell {
public:
	Gura_DeclareObjectAccessor(wx_HtmlWidgetCell)
public:
	inline Object_wx_HtmlWidgetCell(wxHtmlWidgetCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(Gura_UserClass(wx_HtmlWidgetCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlWidgetCell(Class *pClass, wxHtmlWidgetCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlWidgetCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlWidgetCell *GetEntity() {
		return static_cast<wxHtmlWidgetCell *>(_pEntity);
	}
	inline wxHtmlWidgetCell *ReleaseEntity() {
		wxHtmlWidgetCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlWidgetCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
