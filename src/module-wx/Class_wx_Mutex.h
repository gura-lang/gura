//----------------------------------------------------------------------------
// wxMutex
// extracted from mutex.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MUTEX_H__
#define __CLASS_WX_MUTEX_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMutex
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Mutex);

//----------------------------------------------------------------------------
// Object declaration for wxMutex
//----------------------------------------------------------------------------
class Object_wx_Mutex : public Object {
protected:
	wxMutex *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Mutex)
public:
	inline Object_wx_Mutex(wxMutex *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Mutex)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Mutex(Class *pClass, wxMutex *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Mutex();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxMutex *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxMutex *GetEntity() { return _pEntity; }
	inline wxMutex *ReleaseEntity() {
		wxMutex *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMutex");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
