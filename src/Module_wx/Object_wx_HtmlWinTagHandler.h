//----------------------------------------------------------------------------
// wxHtmlWinTagHandler
// extracted from htwinhnd.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLWINTAGHANDLER_H__
#define __OBJECT_WX_HTMLWINTAGHANDLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWinTagHandler);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
class Object_wx_HtmlWinTagHandler : public Object_wx_HtmlTagHandler {
public:
	Gura_DeclareObjectAccessor(wx_HtmlWinTagHandler)
public:
	inline Object_wx_HtmlWinTagHandler(wxHtmlWinTagHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlTagHandler(Gura_UserClass(wx_HtmlWinTagHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlWinTagHandler(Class *pClass, wxHtmlWinTagHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlTagHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlWinTagHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlWinTagHandler *GetEntity() {
		return dynamic_cast<wxHtmlWinTagHandler *>(_pEntity);
	}
	inline wxHtmlWinTagHandler *ReleaseEntity() {
		wxHtmlWinTagHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlWinTagHandler");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
