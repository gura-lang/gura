//----------------------------------------------------------------------------
// wxHtmlWinParser
// extracted from htwinprs.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLWINPARSER_H__
#define __CLASS_WX_HTMLWINPARSER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWinParser
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWinParser);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWinParser
//----------------------------------------------------------------------------
class Object_wx_HtmlWinParser : public Object_wx_HtmlParser {
public:
	Gura_DeclareObjectAccessor(wx_HtmlWinParser)
public:
	inline Object_wx_HtmlWinParser(wxHtmlWinParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlParser(Gura_UserClass(wx_HtmlWinParser), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlWinParser(Class *pClass, wxHtmlWinParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlParser(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlWinParser();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlWinParser *GetEntity() {
		return dynamic_cast<wxHtmlWinParser *>(_pEntity);
	}
	inline wxHtmlWinParser *ReleaseEntity() {
		wxHtmlWinParser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlWinParser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
