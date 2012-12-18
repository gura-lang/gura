//----------------------------------------------------------------------------
// wxMutexLocker
// extracted from mutexlck.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MUTEXLOCKER_H__
#define __OBJECT_WX_MUTEXLOCKER_H__

Gura_BeginModule(wx)

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
				Object(Gura_UserClass(wx_MutexLocker)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MutexLocker(Class *pClass, wxMutexLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MutexLocker();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxMutexLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxMutexLocker *GetEntity() { return _pEntity; }
	inline wxMutexLocker *ReleaseEntity() {
		wxMutexLocker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMutexLocker");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
