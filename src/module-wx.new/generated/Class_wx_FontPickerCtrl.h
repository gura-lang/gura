//----------------------------------------------------------------------------
// wxFontPickerCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FONTPICKERCTRL_H__
#define __CLASS_WX_FONTPICKERCTRL_H__
#include <wx/fontpicker.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontPickerCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxFontPickerCtrl
//----------------------------------------------------------------------------
class Object_wx_FontPickerCtrl : public Object_wx_PickerBase {
public:
	Gura_DeclareObjectAccessor(wx_FontPickerCtrl)
public:
	inline Object_wx_FontPickerCtrl(wxFontPickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(Gura_UserClass(wx_FontPickerCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FontPickerCtrl(Class *pClass, wxFontPickerCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PickerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FontPickerCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFontPickerCtrl *GetEntity() {
		return static_cast<wxFontPickerCtrl *>(_pEntity);
	}
	inline wxFontPickerCtrl *ReleaseEntity() {
		wxFontPickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFontPickerCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
