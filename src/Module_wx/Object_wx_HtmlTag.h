//----------------------------------------------------------------------------
// wxHtmlTag
// extracted from httag.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLTAG_H__
#define __OBJECT_WX_HTMLTAG_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlTag
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlTag);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlTag
//----------------------------------------------------------------------------
class Object_wx_HtmlTag : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlTag)
public:
	inline Object_wx_HtmlTag(wxHtmlTag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlTag), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlTag(Class *pClass, wxHtmlTag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlTag();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlTag *GetEntity() {
		return dynamic_cast<wxHtmlTag *>(_pEntity);
	}
	inline wxHtmlTag *ReleaseEntity() {
		wxHtmlTag *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlTag");
		return true;
	}
};

}}

#endif
