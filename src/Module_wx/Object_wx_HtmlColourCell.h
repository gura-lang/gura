//----------------------------------------------------------------------------
// wxHtmlColourCell
// extracted from htcolor.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLCOLOURCELL_H__
#define __OBJECT_WX_HTMLCOLOURCELL_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlColourCell *GetEntity() {
		return dynamic_cast<wxHtmlColourCell *>(_pEntity);
	}
	inline wxHtmlColourCell *ReleaseEntity() {
		wxHtmlColourCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlColourCell");
		return true;
	}
};

}}

#endif
