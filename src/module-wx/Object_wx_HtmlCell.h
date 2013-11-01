//----------------------------------------------------------------------------
// wxHtmlCell
// extracted from htcell.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLCELL_H__
#define __OBJECT_WX_HTMLCELL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlCell);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlCell
//----------------------------------------------------------------------------
class Object_wx_HtmlCell : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlCell)
public:
	inline Object_wx_HtmlCell(wxHtmlCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlCell(Class *pClass, wxHtmlCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlCell *GetEntity() {
		return dynamic_cast<wxHtmlCell *>(_pEntity);
	}
	inline wxHtmlCell *ReleaseEntity() {
		wxHtmlCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
