//----------------------------------------------------------------------------
// wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SVGBITMAPEMBEDHANDLER_H__
#define __CLASS_WX_SVGBITMAPEMBEDHANDLER_H__
#include <wx/dcsvg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SVGBitmapEmbedHandler);

//----------------------------------------------------------------------------
// Object declaration for wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------
class Object_wx_SVGBitmapEmbedHandler : public Object_wx_SVGBitmapHandler {
public:
	Gura_DeclareObjectAccessor(wx_SVGBitmapEmbedHandler)
public:
	inline Object_wx_SVGBitmapEmbedHandler(wxSVGBitmapEmbedHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SVGBitmapHandler(Gura_UserClass(wx_SVGBitmapEmbedHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SVGBitmapEmbedHandler(Class *pClass, wxSVGBitmapEmbedHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SVGBitmapHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SVGBitmapEmbedHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSVGBitmapEmbedHandler *GetEntity() {
		return static_cast<wxSVGBitmapEmbedHandler *>(_pEntity);
	}
	inline wxSVGBitmapEmbedHandler *ReleaseEntity() {
		wxSVGBitmapEmbedHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSVGBitmapEmbedHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
