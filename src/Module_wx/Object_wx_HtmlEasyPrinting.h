//----------------------------------------------------------------------------
// wxHtmlEasyPrinting
// extracted from hteasypr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLEASYPRINTING_H__
#define __OBJECT_WX_HTMLEASYPRINTING_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlEasyPrinting);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
class Object_wx_HtmlEasyPrinting : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlEasyPrinting)
public:
	inline Object_wx_HtmlEasyPrinting(wxHtmlEasyPrinting *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlEasyPrinting), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlEasyPrinting(Class *pClass, wxHtmlEasyPrinting *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlEasyPrinting();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlEasyPrinting *GetEntity() {
		return dynamic_cast<wxHtmlEasyPrinting *>(_pEntity);
	}
	inline wxHtmlEasyPrinting *ReleaseEntity() {
		wxHtmlEasyPrinting *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlEasyPrinting");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
