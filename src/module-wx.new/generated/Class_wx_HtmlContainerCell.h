//----------------------------------------------------------------------------
// wxHtmlContainerCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLCONTAINERCELL_H__
#define __CLASS_WX_HTMLCONTAINERCELL_H__
#include <wx/html/htmlcell.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlContainerCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlContainerCell);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlContainerCell
//----------------------------------------------------------------------------
class Object_wx_HtmlContainerCell : public Object_wx_HtmlCell {
public:
	Gura_DeclareObjectAccessor(wx_HtmlContainerCell)
public:
	inline Object_wx_HtmlContainerCell(wxHtmlContainerCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(Gura_UserClass(wx_HtmlContainerCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlContainerCell(Class *pClass, wxHtmlContainerCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlCell(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlContainerCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlContainerCell *GetEntity() {
		return static_cast<wxHtmlContainerCell *>(_pEntity);
	}
	inline wxHtmlContainerCell *ReleaseEntity() {
		wxHtmlContainerCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlContainerCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
