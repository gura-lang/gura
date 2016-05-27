//----------------------------------------------------------------------------
// wxGraphicsPen
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRAPHICSPEN_H__
#define __CLASS_WX_GRAPHICSPEN_H__
#include <wx/graphics.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsPen
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsPen);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsPen
//----------------------------------------------------------------------------
class Object_wx_GraphicsPen : public Object_wx_GraphicsObject {
public:
	Gura_DeclareObjectAccessor(wx_GraphicsPen)
public:
	inline Object_wx_GraphicsPen(wxGraphicsPen *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(Gura_UserClass(wx_GraphicsPen), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GraphicsPen(Class *pClass, wxGraphicsPen *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GraphicsPen();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGraphicsPen *GetEntity() {
		return static_cast<wxGraphicsPen *>(_pEntity);
	}
	inline wxGraphicsPen *ReleaseEntity() {
		wxGraphicsPen *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGraphicsPen");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
