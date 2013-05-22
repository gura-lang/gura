//----------------------------------------------------------------------------
// wxFontPickerCtrl
// extracted from fontpicker.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FONTPICKERCTRL_H__
#define __OBJECT_WX_FONTPICKERCTRL_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFontPickerCtrl *GetEntity() {
		return dynamic_cast<wxFontPickerCtrl *>(_pEntity);
	}
	inline wxFontPickerCtrl *ReleaseEntity() {
		wxFontPickerCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFontPickerCtrl");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
