//----------------------------------------------------------------------------
// wxGraphicsContext
// extracted from graphicscontext.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRAPHICSCONTEXT_H__
#define __CLASS_WX_GRAPHICSCONTEXT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsContext
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsContext);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsContext
//----------------------------------------------------------------------------
class Object_wx_GraphicsContext : public Object_wx_GraphicsObject {
public:
	Gura_DeclareObjectAccessor(wx_GraphicsContext)
public:
	inline Object_wx_GraphicsContext(wxGraphicsContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(Gura_UserClass(wx_GraphicsContext), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GraphicsContext(Class *pClass, wxGraphicsContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GraphicsObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GraphicsContext();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGraphicsContext *GetEntity() {
		return dynamic_cast<wxGraphicsContext *>(_pEntity);
	}
	inline wxGraphicsContext *ReleaseEntity() {
		wxGraphicsContext *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGraphicsContext");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
