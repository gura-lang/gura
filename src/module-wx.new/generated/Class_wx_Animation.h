//----------------------------------------------------------------------------
// wxAnimation
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ANIMATION_H__
#define __CLASS_WX_ANIMATION_H__
#include <wx/animate.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAnimation
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Animation);

//----------------------------------------------------------------------------
// Object declaration for wxAnimation
//----------------------------------------------------------------------------
class Object_wx_Animation : public Object {
protected:
	wxAnimation *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Animation)
public:
	inline Object_wx_Animation(wxAnimation *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Animation(Class *pClass, wxAnimation *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Animation();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAnimation *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAnimation *GetEntity() {
		return static_cast<wxAnimation *>(_pEntity);
	}
	inline wxAnimation *ReleaseEntity() {
		wxAnimation *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAnimation");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
