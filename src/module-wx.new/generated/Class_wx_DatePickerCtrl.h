//----------------------------------------------------------------------------
// wxDatePickerCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATEPICKERCTRL_H__
#define __CLASS_WX_DATEPICKERCTRL_H__
#include <wx/datectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDatePickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DatePickerCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxDatePickerCtrl
//----------------------------------------------------------------------------
class Object_wx_DatePickerCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_DatePickerCtrl)
public:
	inline Object_wx_DatePickerCtrl(wxDatePickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_DatePickerCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DatePickerCtrl(Class *pClass, wxDatePickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DatePickerCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDatePickerCtrl *GetEntity() {
		return static_cast<wxDatePickerCtrl *>(_pEntity);
	}
	inline wxDatePickerCtrl *ReleaseEntity() {
		wxDatePickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDatePickerCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
