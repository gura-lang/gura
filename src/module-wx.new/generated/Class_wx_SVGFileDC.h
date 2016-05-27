//----------------------------------------------------------------------------
// wxSVGFileDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SVGFILEDC_H__
#define __CLASS_WX_SVGFILEDC_H__
#include <wx/dcsvg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSVGFileDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SVGFileDC);

//----------------------------------------------------------------------------
// Object declaration for wxSVGFileDC
//----------------------------------------------------------------------------
class Object_wx_SVGFileDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_SVGFileDC)
public:
	inline Object_wx_SVGFileDC(wxSVGFileDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_SVGFileDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SVGFileDC(Class *pClass, wxSVGFileDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SVGFileDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSVGFileDC *GetEntity() {
		return static_cast<wxSVGFileDC *>(_pEntity);
	}
	inline wxSVGFileDC *ReleaseEntity() {
		wxSVGFileDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSVGFileDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
