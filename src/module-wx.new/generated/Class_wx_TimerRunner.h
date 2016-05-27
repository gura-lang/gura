//----------------------------------------------------------------------------
// wxTimerRunner
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TIMERRUNNER_H__
#define __CLASS_WX_TIMERRUNNER_H__
#include <wx/timer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTimerRunner
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TimerRunner);

//----------------------------------------------------------------------------
// Object declaration for wxTimerRunner
//----------------------------------------------------------------------------
class Object_wx_TimerRunner : public Object {
protected:
	wxTimerRunner *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TimerRunner)
public:
	inline Object_wx_TimerRunner(wxTimerRunner *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TimerRunner(Class *pClass, wxTimerRunner *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TimerRunner();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTimerRunner *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTimerRunner *GetEntity() {
		return static_cast<wxTimerRunner *>(_pEntity);
	}
	inline wxTimerRunner *ReleaseEntity() {
		wxTimerRunner *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTimerRunner");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
