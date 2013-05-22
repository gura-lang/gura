//----------------------------------------------------------------------------
// wxHtmlTagHandler
// extracted from httaghnd.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLTAGHANDLER_H__
#define __OBJECT_WX_HTMLTAGHANDLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlTagHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlTagHandler);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlTagHandler
//----------------------------------------------------------------------------
class Object_wx_HtmlTagHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlTagHandler)
public:
	inline Object_wx_HtmlTagHandler(wxHtmlTagHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlTagHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlTagHandler(Class *pClass, wxHtmlTagHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlTagHandler();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlTagHandler *GetEntity() {
		return dynamic_cast<wxHtmlTagHandler *>(_pEntity);
	}
	inline wxHtmlTagHandler *ReleaseEntity() {
		wxHtmlTagHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlTagHandler");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
