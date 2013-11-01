//----------------------------------------------------------------------------
// wxCriticalSectionLocker
// extracted from crtslock.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CRITICALSECTIONLOCKER_H__
#define __OBJECT_WX_CRITICALSECTIONLOCKER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CriticalSectionLocker);

//----------------------------------------------------------------------------
// Object declaration for wxCriticalSectionLocker
//----------------------------------------------------------------------------
class Object_wx_CriticalSectionLocker : public Object {
protected:
	wxCriticalSectionLocker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CriticalSectionLocker)
public:
	inline Object_wx_CriticalSectionLocker(wxCriticalSectionLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_CriticalSectionLocker)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CriticalSectionLocker(Class *pClass, wxCriticalSectionLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CriticalSectionLocker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCriticalSectionLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxCriticalSectionLocker *GetEntity() { return _pEntity; }
	inline wxCriticalSectionLocker *ReleaseEntity() {
		wxCriticalSectionLocker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCriticalSectionLocker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
