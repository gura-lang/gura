//----------------------------------------------------------------------------
// wxSVGBitmapFileHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SVGBITMAPFILEHANDLER_H__
#define __CLASS_WX_SVGBITMAPFILEHANDLER_H__
#include <wx/dcsvg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSVGBitmapFileHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SVGBitmapFileHandler);

//----------------------------------------------------------------------------
// Object declaration for wxSVGBitmapFileHandler
//----------------------------------------------------------------------------
class Object_wx_SVGBitmapFileHandler : public Object_wx_SVGBitmapHandler {
public:
	Gura_DeclareObjectAccessor(wx_SVGBitmapFileHandler)
public:
	inline Object_wx_SVGBitmapFileHandler(wxSVGBitmapFileHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SVGBitmapHandler(Gura_UserClass(wx_SVGBitmapFileHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SVGBitmapFileHandler(Class *pClass, wxSVGBitmapFileHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SVGBitmapHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SVGBitmapFileHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSVGBitmapFileHandler *GetEntity() {
		return static_cast<wxSVGBitmapFileHandler *>(_pEntity);
	}
	inline wxSVGBitmapFileHandler *ReleaseEntity() {
		wxSVGBitmapFileHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSVGBitmapFileHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
