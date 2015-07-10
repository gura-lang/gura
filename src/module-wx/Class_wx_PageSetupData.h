//----------------------------------------------------------------------------
// wxPageSetupData
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PAGESETUPDATA_H__
#define __CLASS_WX_PAGESETUPDATA_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPageSetupData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PageSetupData);

//----------------------------------------------------------------------------
// Object declaration for wxPageSetupData
//----------------------------------------------------------------------------
class Object_wx_PageSetupData : public Object {
protected:
	wxPageSetupData *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PageSetupData)
public:
	inline Object_wx_PageSetupData(wxPageSetupData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_PageSetupData)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PageSetupData(Class *pClass, wxPageSetupData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PageSetupData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPageSetupData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPageSetupData *GetEntity() { return _pEntity; }
	inline wxPageSetupData *ReleaseEntity() {
		wxPageSetupData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPageSetupData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
