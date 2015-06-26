//----------------------------------------------------------------------------
// wxGraphicsBrush
// extracted from graphicsbrush.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRAPHICSBRUSH_H__
#define __CLASS_WX_GRAPHICSBRUSH_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsBrush
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsBrush);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsBrush
//----------------------------------------------------------------------------
class Object_wx_GraphicsBrush : public Object_wx_GraphicsObject {
public:
	Gura_DeclareObjectAccessor(wx_GraphicsBrush)
public:
	inline Object_wx_GraphicsBrush(wxGraphicsBrush *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(Gura_UserClass(wx_GraphicsBrush), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GraphicsBrush(Class *pClass, wxGraphicsBrush *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GraphicsBrush();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGraphicsBrush *GetEntity() {
		return dynamic_cast<wxGraphicsBrush *>(_pEntity);
	}
	inline wxGraphicsBrush *ReleaseEntity() {
		wxGraphicsBrush *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGraphicsBrush");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
