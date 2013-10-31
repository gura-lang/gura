//----------------------------------------------------------------------------
// wxDateTimeHolidayAuthority
// extracted from datetime.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATETIMEHOLIDAYAUTHORITY_H__
#define __OBJECT_WX_DATETIMEHOLIDAYAUTHORITY_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DateTimeHolidayAuthority);

//----------------------------------------------------------------------------
// Object declaration for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
class Object_wx_DateTimeHolidayAuthority : public Object {
protected:
	wxDateTimeHolidayAuthority *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DateTimeHolidayAuthority)
public:
	inline Object_wx_DateTimeHolidayAuthority(wxDateTimeHolidayAuthority *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DateTimeHolidayAuthority)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DateTimeHolidayAuthority(Class *pClass, wxDateTimeHolidayAuthority *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DateTimeHolidayAuthority();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDateTimeHolidayAuthority *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDateTimeHolidayAuthority *GetEntity() { return _pEntity; }
	inline wxDateTimeHolidayAuthority *ReleaseEntity() {
		wxDateTimeHolidayAuthority *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDateTimeHolidayAuthority");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
