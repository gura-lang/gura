//----------------------------------------------------------------------------
// wxDateTimeWorkDays
// extracted from datetime.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATETIMEWORKDAYS_H__
#define __OBJECT_WX_DATETIMEWORKDAYS_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDateTimeWorkDays
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DateTimeWorkDays);

//----------------------------------------------------------------------------
// Object declaration for wxDateTimeWorkDays
//----------------------------------------------------------------------------
class Object_wx_DateTimeWorkDays : public Object {
protected:
	wxDateTimeWorkDays *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DateTimeWorkDays)
public:
	inline Object_wx_DateTimeWorkDays(wxDateTimeWorkDays *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DateTimeWorkDays)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DateTimeWorkDays(Class *pClass, wxDateTimeWorkDays *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DateTimeWorkDays();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDateTimeWorkDays *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDateTimeWorkDays *GetEntity() { return _pEntity; }
	inline wxDateTimeWorkDays *ReleaseEntity() {
		wxDateTimeWorkDays *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDateTimeWorkDays");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
