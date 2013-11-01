//----------------------------------------------------------------------------
// wxSpinButton
// extracted from spinbutt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SPINBUTTON_H__
#define __OBJECT_WX_SPINBUTTON_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSpinButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SpinButton);

//----------------------------------------------------------------------------
// Object declaration for wxSpinButton
//----------------------------------------------------------------------------
class Object_wx_SpinButton : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_SpinButton)
public:
	inline Object_wx_SpinButton(wxSpinButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_SpinButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SpinButton(Class *pClass, wxSpinButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SpinButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSpinButton *GetEntity() {
		return dynamic_cast<wxSpinButton *>(_pEntity);
	}
	inline wxSpinButton *ReleaseEntity() {
		wxSpinButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSpinButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
