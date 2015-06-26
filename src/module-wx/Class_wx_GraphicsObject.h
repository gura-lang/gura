//----------------------------------------------------------------------------
// wxGraphicsObject
// extracted from graphicsobject.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRAPHICSOBJECT_H__
#define __CLASS_WX_GRAPHICSOBJECT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsObject);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsObject
//----------------------------------------------------------------------------
class Object_wx_GraphicsObject : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_GraphicsObject)
public:
	inline Object_wx_GraphicsObject(wxGraphicsObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_GraphicsObject), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GraphicsObject(Class *pClass, wxGraphicsObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GraphicsObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGraphicsObject *GetEntity() {
		return dynamic_cast<wxGraphicsObject *>(_pEntity);
	}
	inline wxGraphicsObject *ReleaseEntity() {
		wxGraphicsObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGraphicsObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
