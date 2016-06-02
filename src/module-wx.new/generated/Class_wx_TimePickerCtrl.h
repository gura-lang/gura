//----------------------------------------------------------------------------
// wxTimePickerCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TIMEPICKERCTRL_H__
#define __CLASS_WX_TIMEPICKERCTRL_H__
#include <wx/timectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTimePickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TimePickerCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxTimePickerCtrl
//----------------------------------------------------------------------------
class Object_wx_TimePickerCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_TimePickerCtrl)
public:
	inline Object_wx_TimePickerCtrl(wxTimePickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_TimePickerCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TimePickerCtrl(Class *pClass, wxTimePickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TimePickerCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTimePickerCtrl *GetEntity() {
		return static_cast<wxTimePickerCtrl *>(_pEntity);
	}
	inline wxTimePickerCtrl *ReleaseEntity() {
		wxTimePickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTimePickerCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
