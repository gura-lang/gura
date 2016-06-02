//----------------------------------------------------------------------------
// wxGridUpdateLocker
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDUPDATELOCKER_H__
#define __CLASS_WX_GRIDUPDATELOCKER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridUpdateLocker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridUpdateLocker);

//----------------------------------------------------------------------------
// Object declaration for wxGridUpdateLocker
//----------------------------------------------------------------------------
class Object_wx_GridUpdateLocker : public Object {
protected:
	wxGridUpdateLocker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GridUpdateLocker)
public:
	inline Object_wx_GridUpdateLocker(wxGridUpdateLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GridUpdateLocker(Class *pClass, wxGridUpdateLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GridUpdateLocker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGridUpdateLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGridUpdateLocker *GetEntity() {
		return static_cast<wxGridUpdateLocker *>(_pEntity);
	}
	inline wxGridUpdateLocker *ReleaseEntity() {
		wxGridUpdateLocker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridUpdateLocker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
