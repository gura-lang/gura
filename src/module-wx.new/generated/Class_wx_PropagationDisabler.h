//----------------------------------------------------------------------------
// wxPropagationDisabler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPAGATIONDISABLER_H__
#define __CLASS_WX_PROPAGATIONDISABLER_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropagationDisabler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropagationDisabler);

//----------------------------------------------------------------------------
// Object declaration for wxPropagationDisabler
//----------------------------------------------------------------------------
class Object_wx_PropagationDisabler : public Object {
protected:
	wxPropagationDisabler *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PropagationDisabler)
public:
	inline Object_wx_PropagationDisabler(wxPropagationDisabler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PropagationDisabler(Class *pClass, wxPropagationDisabler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PropagationDisabler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPropagationDisabler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPropagationDisabler *GetEntity() {
		return static_cast<wxPropagationDisabler *>(_pEntity);
	}
	inline wxPropagationDisabler *ReleaseEntity() {
		wxPropagationDisabler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPropagationDisabler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
