//----------------------------------------------------------------------------
// wxAnimationCtrl
// extracted from animatctrl.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ANIMATIONCTRL_H__
#define __CLASS_WX_ANIMATIONCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAnimationCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AnimationCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxAnimationCtrl
//----------------------------------------------------------------------------
class Object_wx_AnimationCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_AnimationCtrl)
public:
	inline Object_wx_AnimationCtrl(wxAnimationCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_AnimationCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AnimationCtrl(Class *pClass, wxAnimationCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AnimationCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAnimationCtrl *GetEntity() {
		return dynamic_cast<wxAnimationCtrl *>(_pEntity);
	}
	inline wxAnimationCtrl *ReleaseEntity() {
		wxAnimationCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAnimationCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
