//----------------------------------------------------------------------------
// wxColourPickerCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COLOURPICKERCTRL_H__
#define __CLASS_WX_COLOURPICKERCTRL_H__
#include <wx/clrpicker.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxColourPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ColourPickerCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxColourPickerCtrl
//----------------------------------------------------------------------------
class Object_wx_ColourPickerCtrl : public Object_wx_PickerBase {
public:
	Gura_DeclareObjectAccessor(wx_ColourPickerCtrl)
public:
	inline Object_wx_ColourPickerCtrl(wxColourPickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(Gura_UserClass(wx_ColourPickerCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ColourPickerCtrl(Class *pClass, wxColourPickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ColourPickerCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxColourPickerCtrl *GetEntity() {
		return static_cast<wxColourPickerCtrl *>(_pEntity);
	}
	inline wxColourPickerCtrl *ReleaseEntity() {
		wxColourPickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxColourPickerCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
