//----------------------------------------------------------------------------
// wxAnimation
// extracted from animation.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ANIMATION_H__
#define __OBJECT_WX_ANIMATION_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAnimation
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Animation);

//----------------------------------------------------------------------------
// Object declaration for wxAnimation
//----------------------------------------------------------------------------
class Object_wx_Animation : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Animation)
public:
	inline Object_wx_Animation(wxAnimation *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Animation), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Animation(Class *pClass, wxAnimation *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Animation();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxAnimation *GetEntity() {
		return dynamic_cast<wxAnimation *>(_pEntity);
	}
	inline wxAnimation *ReleaseEntity() {
		wxAnimation *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAnimation");
		return true;
	}
};

}}

#endif
