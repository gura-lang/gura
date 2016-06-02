//----------------------------------------------------------------------------
// wxTimer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TIMER_H__
#define __CLASS_WX_TIMER_H__
#include <wx/timer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTimer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Timer);

//----------------------------------------------------------------------------
// Object declaration for wxTimer
//----------------------------------------------------------------------------
class Object_wx_Timer : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_Timer)
public:
	inline Object_wx_Timer(wxTimer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_Timer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Timer(Class *pClass, wxTimer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Timer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTimer *GetEntity() {
		return static_cast<wxTimer *>(_pEntity);
	}
	inline wxTimer *ReleaseEntity() {
		wxTimer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTimer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
