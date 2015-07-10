//----------------------------------------------------------------------------
// wxVersionInfo
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VERSIONINFO_H__
#define __CLASS_WX_VERSIONINFO_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVersionInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VersionInfo);

//----------------------------------------------------------------------------
// Object declaration for wxVersionInfo
//----------------------------------------------------------------------------
class Object_wx_VersionInfo : public Object {
protected:
	wxVersionInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_VersionInfo)
public:
	inline Object_wx_VersionInfo(wxVersionInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_VersionInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_VersionInfo(Class *pClass, wxVersionInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_VersionInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxVersionInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxVersionInfo *GetEntity() { return _pEntity; }
	inline wxVersionInfo *ReleaseEntity() {
		wxVersionInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxVersionInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
