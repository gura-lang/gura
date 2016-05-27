//----------------------------------------------------------------------------
// wxGraphicsBitmap
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRAPHICSBITMAP_H__
#define __CLASS_WX_GRAPHICSBITMAP_H__
#include <wx/graphics.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsBitmap
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsBitmap);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsBitmap
//----------------------------------------------------------------------------
class Object_wx_GraphicsBitmap : public Object_wx_GraphicsObject {
public:
	Gura_DeclareObjectAccessor(wx_GraphicsBitmap)
public:
	inline Object_wx_GraphicsBitmap(wxGraphicsBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(Gura_UserClass(wx_GraphicsBitmap), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GraphicsBitmap(Class *pClass, wxGraphicsBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GraphicsBitmap();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGraphicsBitmap *GetEntity() {
		return static_cast<wxGraphicsBitmap *>(_pEntity);
	}
	inline wxGraphicsBitmap *ReleaseEntity() {
		wxGraphicsBitmap *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGraphicsBitmap");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
