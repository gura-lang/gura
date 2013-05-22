//----------------------------------------------------------------------------
// wxHtmlContainerCell
// extracted from htcontnr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLCONTAINERCELL_H__
#define __OBJECT_WX_HTMLCONTAINERCELL_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlContainerCell *GetEntity() {
		return dynamic_cast<wxHtmlContainerCell *>(_pEntity);
	}
	inline wxHtmlContainerCell *ReleaseEntity() {
		wxHtmlContainerCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlContainerCell");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
