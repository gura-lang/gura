//----------------------------------------------------------------------------
// wxHtmlColourCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLCOLOURCELL_H__
#define __CLASS_WX_HTMLCOLOURCELL_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlColourCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlColourCell);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlColourCell
//----------------------------------------------------------------------------
class Object_wx_HtmlColourCell : public Object_wx_HtmlCell {
public:
	Gura_DeclareObjectAccessor(wx_HtmlColourCell)
public:
	inline Object_wx_HtmlColourCell(wxHtmlColourCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(Gura_UserClass(wx_HtmlColourCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlColourCell(Class *pClass, wxHtmlColourCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlColourCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlColourCell *GetEntity() {
		return static_cast<wxHtmlColourCell *>(_pEntity);
	}
	inline wxHtmlColourCell *ReleaseEntity() {
		wxHtmlColourCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlColourCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
