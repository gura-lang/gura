//----------------------------------------------------------------------------
// wxToggleButton
// extracted from tglbtn.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TOGGLEBUTTON_H__
#define __OBJECT_WX_TOGGLEBUTTON_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToggleButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToggleButton);

//----------------------------------------------------------------------------
// Object declaration for wxToggleButton
//----------------------------------------------------------------------------
class Object_wx_ToggleButton : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ToggleButton)
public:
	inline Object_wx_ToggleButton(wxToggleButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ToggleButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ToggleButton(Class *pClass, wxToggleButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ToggleButton();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxToggleButton *GetEntity() {
		return dynamic_cast<wxToggleButton *>(_pEntity);
	}
	inline wxToggleButton *ReleaseEntity() {
		wxToggleButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxToggleButton");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
