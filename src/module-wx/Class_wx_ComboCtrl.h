//----------------------------------------------------------------------------
// wxComboCtrl
// extracted from comboctrl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_COMBOCTRL_H__
#define __OBJECT_WX_COMBOCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxComboCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ComboCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxComboCtrl
//----------------------------------------------------------------------------
class Object_wx_ComboCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ComboCtrl)
public:
	inline Object_wx_ComboCtrl(wxComboCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ComboCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ComboCtrl(Class *pClass, wxComboCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ComboCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxComboCtrl *GetEntity() {
		return dynamic_cast<wxComboCtrl *>(_pEntity);
	}
	inline wxComboCtrl *ReleaseEntity() {
		wxComboCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxComboCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
