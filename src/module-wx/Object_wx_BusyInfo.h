//----------------------------------------------------------------------------
// wxBusyInfo
// extracted from busyinfo.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BUSYINFO_H__
#define __OBJECT_WX_BUSYINFO_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBusyInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BusyInfo);

//----------------------------------------------------------------------------
// Object declaration for wxBusyInfo
//----------------------------------------------------------------------------
class Object_wx_BusyInfo : public Object {
protected:
	wxBusyInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_BusyInfo)
public:
	inline Object_wx_BusyInfo(wxBusyInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_BusyInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_BusyInfo(Class *pClass, wxBusyInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_BusyInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxBusyInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxBusyInfo *GetEntity() { return _pEntity; }
	inline wxBusyInfo *ReleaseEntity() {
		wxBusyInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBusyInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
