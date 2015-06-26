//----------------------------------------------------------------------------
// wxArchiveNotifier
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ARCHIVENOTIFIER_H__
#define __CLASS_WX_ARCHIVENOTIFIER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArchiveNotifier
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArchiveNotifier);

//----------------------------------------------------------------------------
// Object declaration for wxArchiveNotifier
//----------------------------------------------------------------------------
class Object_wx_ArchiveNotifier : public Object {
protected:
	wxArchiveNotifier *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ArchiveNotifier)
public:
	inline Object_wx_ArchiveNotifier(wxArchiveNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ArchiveNotifier)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ArchiveNotifier(Class *pClass, wxArchiveNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ArchiveNotifier();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxArchiveNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxArchiveNotifier *GetEntity() { return _pEntity; }
	inline wxArchiveNotifier *ReleaseEntity() {
		wxArchiveNotifier *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxArchiveNotifier");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
