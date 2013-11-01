//----------------------------------------------------------------------------
// wxCalendarDateAttr
// extracted from calctrl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CALENDARDATEATTR_H__
#define __OBJECT_WX_CALENDARDATEATTR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CalendarDateAttr);

//----------------------------------------------------------------------------
// Object declaration for wxCalendarDateAttr
//----------------------------------------------------------------------------
class Object_wx_CalendarDateAttr : public Object {
protected:
	wxCalendarDateAttr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CalendarDateAttr)
public:
	inline Object_wx_CalendarDateAttr(wxCalendarDateAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_CalendarDateAttr)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CalendarDateAttr(Class *pClass, wxCalendarDateAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CalendarDateAttr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCalendarDateAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxCalendarDateAttr *GetEntity() { return _pEntity; }
	inline wxCalendarDateAttr *ReleaseEntity() {
		wxCalendarDateAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCalendarDateAttr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
