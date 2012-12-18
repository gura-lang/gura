//----------------------------------------------------------------------------
// wxHtmlHelpController
// extracted from hthelpct.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLHELPCONTROLLER_H__
#define __OBJECT_WX_HTMLHELPCONTROLLER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlHelpController
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlHelpController);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlHelpController
//----------------------------------------------------------------------------
class Object_wx_HtmlHelpController : public Object_wx_HelpControllerBase {
public:
	Gura_DeclareObjectAccessor(wx_HtmlHelpController)
public:
	inline Object_wx_HtmlHelpController(wxHtmlHelpController *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HelpControllerBase(Gura_UserClass(wx_HtmlHelpController), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlHelpController(Class *pClass, wxHtmlHelpController *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HelpControllerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlHelpController();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHtmlHelpController *GetEntity() {
		return dynamic_cast<wxHtmlHelpController *>(_pEntity);
	}
	inline wxHtmlHelpController *ReleaseEntity() {
		wxHtmlHelpController *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlHelpController");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
