//----------------------------------------------------------------------------
// wxSpinCtrl
// extracted from spinctrl.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SPINCTRL_H__
#define __CLASS_WX_SPINCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSpinCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SpinCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxSpinCtrl
//----------------------------------------------------------------------------
class Object_wx_SpinCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_SpinCtrl)
public:
	inline Object_wx_SpinCtrl(wxSpinCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_SpinCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SpinCtrl(Class *pClass, wxSpinCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SpinCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSpinCtrl *GetEntity() {
		return dynamic_cast<wxSpinCtrl *>(_pEntity);
	}
	inline wxSpinCtrl *ReleaseEntity() {
		wxSpinCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSpinCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
