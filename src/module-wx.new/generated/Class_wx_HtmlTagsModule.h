//----------------------------------------------------------------------------
// wxHtmlTagsModule
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLTAGSMODULE_H__
#define __CLASS_WX_HTMLTAGSMODULE_H__
#include <wx/html/winpars.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlTagsModule
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlTagsModule);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlTagsModule
//----------------------------------------------------------------------------
class Object_wx_HtmlTagsModule : public Object_wx_Module {
public:
	Gura_DeclareObjectAccessor(wx_HtmlTagsModule)
public:
	inline Object_wx_HtmlTagsModule(wxHtmlTagsModule *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Module(Gura_UserClass(wx_HtmlTagsModule), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlTagsModule(Class *pClass, wxHtmlTagsModule *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Module(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlTagsModule();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlTagsModule *GetEntity() {
		return static_cast<wxHtmlTagsModule *>(_pEntity);
	}
	inline wxHtmlTagsModule *ReleaseEntity() {
		wxHtmlTagsModule *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHtmlTagsModule");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
