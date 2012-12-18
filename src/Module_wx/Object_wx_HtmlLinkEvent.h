//----------------------------------------------------------------------------
// wxHtmlLinkEvent
// extracted from htwindow.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLLINKEVENT_H__
#define __OBJECT_WX_HTMLLINKEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlLinkEvent);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlLinkEvent
//----------------------------------------------------------------------------
class Object_wx_HtmlLinkEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_HtmlLinkEvent)
public:
	inline Object_wx_HtmlLinkEvent(wxHtmlLinkEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_HtmlLinkEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlLinkEvent(Class *pClass, wxHtmlLinkEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlLinkEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlLinkEvent *GetEntity() {
		return dynamic_cast<wxHtmlLinkEvent *>(_pEntity);
	}
	inline wxHtmlLinkEvent *ReleaseEntity() {
		wxHtmlLinkEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlLinkEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
