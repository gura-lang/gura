//----------------------------------------------------------------------------
// wxAnimationCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ANIMATIONCTRL_H__
#define __CLASS_WX_ANIMATIONCTRL_H__
#include <wx/animate.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAnimationCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AnimationCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxAnimationCtrl
//----------------------------------------------------------------------------
class Object_wx_AnimationCtrl : public Object {
protected:
	wxAnimationCtrl *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AnimationCtrl)
public:
	inline Object_wx_AnimationCtrl(wxAnimationCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AnimationCtrl(Class *pClass, wxAnimationCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AnimationCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAnimationCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAnimationCtrl *GetEntity() {
		return static_cast<wxAnimationCtrl *>(_pEntity);
	}
	inline wxAnimationCtrl *ReleaseEntity() {
		wxAnimationCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAnimationCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
