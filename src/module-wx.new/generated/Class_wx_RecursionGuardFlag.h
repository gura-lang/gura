//----------------------------------------------------------------------------
// wxRecursionGuardFlag
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RECURSIONGUARDFLAG_H__
#define __CLASS_WX_RECURSIONGUARDFLAG_H__
#include <wx/recguard.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RecursionGuardFlag);

//----------------------------------------------------------------------------
// Object declaration for wxRecursionGuardFlag
//----------------------------------------------------------------------------
class Object_wx_RecursionGuardFlag : public Object {
protected:
	wxRecursionGuardFlag *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RecursionGuardFlag)
public:
	inline Object_wx_RecursionGuardFlag(wxRecursionGuardFlag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RecursionGuardFlag(Class *pClass, wxRecursionGuardFlag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RecursionGuardFlag();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRecursionGuardFlag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRecursionGuardFlag *GetEntity() {
		return static_cast<wxRecursionGuardFlag *>(_pEntity);
	}
	inline wxRecursionGuardFlag *ReleaseEntity() {
		wxRecursionGuardFlag *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRecursionGuardFlag");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
