//----------------------------------------------------------------------------
// wxStopWatch
// extracted from stopwtch.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STOPWATCH_H__
#define __OBJECT_WX_STOPWATCH_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStopWatch
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StopWatch);

//----------------------------------------------------------------------------
// Object declaration for wxStopWatch
//----------------------------------------------------------------------------
class Object_wx_StopWatch : public Object {
protected:
	wxStopWatch *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StopWatch)
public:
	inline Object_wx_StopWatch(wxStopWatch *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StopWatch)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StopWatch(Class *pClass, wxStopWatch *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StopWatch();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxStopWatch *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxStopWatch *GetEntity() { return _pEntity; }
	inline wxStopWatch *ReleaseEntity() {
		wxStopWatch *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStopWatch");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
