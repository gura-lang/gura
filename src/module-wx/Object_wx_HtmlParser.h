//----------------------------------------------------------------------------
// wxHtmlParser
// extracted from htparser.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLPARSER_H__
#define __OBJECT_WX_HTMLPARSER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlParser
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlParser);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlParser
//----------------------------------------------------------------------------
class Object_wx_HtmlParser : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlParser)
public:
	inline Object_wx_HtmlParser(wxHtmlParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlParser), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlParser(Class *pClass, wxHtmlParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlParser();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlParser *GetEntity() {
		return dynamic_cast<wxHtmlParser *>(_pEntity);
	}
	inline wxHtmlParser *ReleaseEntity() {
		wxHtmlParser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlParser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
