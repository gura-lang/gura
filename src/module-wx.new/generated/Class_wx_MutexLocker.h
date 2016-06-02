//----------------------------------------------------------------------------
// wxMutexLocker
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MUTEXLOCKER_H__
#define __CLASS_WX_MUTEXLOCKER_H__
#include <wx/thread.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMutexLocker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MutexLocker);

//----------------------------------------------------------------------------
// Object declaration for wxMutexLocker
//----------------------------------------------------------------------------
class Object_wx_MutexLocker : public Object {
protected:
	wxMutexLocker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MutexLocker)
public:
	inline Object_wx_MutexLocker(wxMutexLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MutexLocker(Class *pClass, wxMutexLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MutexLocker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxMutexLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxMutexLocker *GetEntity() {
		return static_cast<wxMutexLocker *>(_pEntity);
	}
	inline wxMutexLocker *ReleaseEntity() {
		wxMutexLocker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMutexLocker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
