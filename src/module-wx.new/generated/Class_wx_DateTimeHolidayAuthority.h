//----------------------------------------------------------------------------
// wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATETIMEHOLIDAYAUTHORITY_H__
#define __CLASS_WX_DATETIMEHOLIDAYAUTHORITY_H__
#include <wx/datetime.h>

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
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DateTimeHolidayAuthority(Class *pClass, wxDateTimeHolidayAuthority *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DateTimeHolidayAuthority();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDateTimeHolidayAuthority *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDateTimeHolidayAuthority *GetEntity() {
		return static_cast<wxDateTimeHolidayAuthority *>(_pEntity);
	}
	inline wxDateTimeHolidayAuthority *ReleaseEntity() {
		wxDateTimeHolidayAuthority *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDateTimeHolidayAuthority");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
