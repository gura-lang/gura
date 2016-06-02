//----------------------------------------------------------------------------
// wxHtmlWinParser
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLWINPARSER_H__
#define __CLASS_WX_HTMLWINPARSER_H__
#include <wx/html/winpars.h>

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
		return static_cast<wxHtmlWinParser *>(_pEntity);
	}
	inline wxHtmlWinParser *ReleaseEntity() {
		wxHtmlWinParser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlWinParser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
