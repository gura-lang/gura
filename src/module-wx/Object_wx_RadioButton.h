//----------------------------------------------------------------------------
// wxRadioButton
// extracted from radiobut.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RADIOBUTTON_H__
#define __OBJECT_WX_RADIOBUTTON_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRadioButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RadioButton);

//----------------------------------------------------------------------------
// Object declaration for wxRadioButton
//----------------------------------------------------------------------------
class Object_wx_RadioButton : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_RadioButton)
public:
	inline Object_wx_RadioButton(wxRadioButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_RadioButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RadioButton(Class *pClass, wxRadioButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RadioButton();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRadioButton *GetEntity() {
		return dynamic_cast<wxRadioButton *>(_pEntity);
	}
	inline wxRadioButton *ReleaseEntity() {
		wxRadioButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRadioButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
