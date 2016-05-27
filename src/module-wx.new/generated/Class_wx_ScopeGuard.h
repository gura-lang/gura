//----------------------------------------------------------------------------
// wxScopeGuard
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCOPEGUARD_H__
#define __CLASS_WX_SCOPEGUARD_H__
#include <wx/scopeguard.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScopeGuard
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScopeGuard);

//----------------------------------------------------------------------------
// Object declaration for wxScopeGuard
//----------------------------------------------------------------------------
class Object_wx_ScopeGuard : public Object {
protected:
	wxScopeGuard *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ScopeGuard)
public:
	inline Object_wx_ScopeGuard(wxScopeGuard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ScopeGuard(Class *pClass, wxScopeGuard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ScopeGuard();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxScopeGuard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxScopeGuard *GetEntity() {
		return static_cast<wxScopeGuard *>(_pEntity);
	}
	inline wxScopeGuard *ReleaseEntity() {
		wxScopeGuard *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxScopeGuard");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
