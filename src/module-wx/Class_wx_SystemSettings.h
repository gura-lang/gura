//----------------------------------------------------------------------------
// wxSystemSettings
// extracted from settings.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SYSTEMSETTINGS_H__
#define __CLASS_WX_SYSTEMSETTINGS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSystemSettings
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SystemSettings);

//----------------------------------------------------------------------------
// Object declaration for wxSystemSettings
//----------------------------------------------------------------------------
class Object_wx_SystemSettings : public Object {
protected:
	wxSystemSettings *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SystemSettings)
public:
	inline Object_wx_SystemSettings(wxSystemSettings *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_SystemSettings)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SystemSettings(Class *pClass, wxSystemSettings *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SystemSettings();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSystemSettings *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxSystemSettings *GetEntity() { return _pEntity; }
	inline wxSystemSettings *ReleaseEntity() {
		wxSystemSettings *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSystemSettings");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
