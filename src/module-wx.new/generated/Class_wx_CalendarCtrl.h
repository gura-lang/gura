//----------------------------------------------------------------------------
// wxCalendarCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CALENDARCTRL_H__
#define __CLASS_WX_CALENDARCTRL_H__
#include <wx/calctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCalendarCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CalendarCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxCalendarCtrl
//----------------------------------------------------------------------------
class Object_wx_CalendarCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_CalendarCtrl)
public:
	inline Object_wx_CalendarCtrl(wxCalendarCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_CalendarCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CalendarCtrl(Class *pClass, wxCalendarCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CalendarCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCalendarCtrl *GetEntity() {
		return static_cast<wxCalendarCtrl *>(_pEntity);
	}
	inline wxCalendarCtrl *ReleaseEntity() {
		wxCalendarCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCalendarCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
