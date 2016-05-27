//----------------------------------------------------------------------------
// wxHtmlDCRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLDCRENDERER_H__
#define __CLASS_WX_HTMLDCRENDERER_H__
#include <wx/html/htmprint.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlDCRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlDCRenderer
//----------------------------------------------------------------------------
class Object_wx_HtmlDCRenderer : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_HtmlDCRenderer)
public:
	inline Object_wx_HtmlDCRenderer(wxHtmlDCRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_HtmlDCRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HtmlDCRenderer(Class *pClass, wxHtmlDCRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HtmlDCRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHtmlDCRenderer *GetEntity() {
		return static_cast<wxHtmlDCRenderer *>(_pEntity);
	}
	inline wxHtmlDCRenderer *ReleaseEntity() {
		wxHtmlDCRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlDCRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
