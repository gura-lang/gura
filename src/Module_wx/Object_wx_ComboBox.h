//----------------------------------------------------------------------------
// wxComboBox
// extracted from combobox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_COMBOBOX_H__
#define __OBJECT_WX_COMBOBOX_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxComboBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ComboBox);

//----------------------------------------------------------------------------
// Object declaration for wxComboBox
//----------------------------------------------------------------------------
class Object_wx_ComboBox : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ComboBox)
public:
	inline Object_wx_ComboBox(wxComboBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ComboBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ComboBox(Class *pClass, wxComboBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ComboBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxComboBox *GetEntity() {
		return dynamic_cast<wxComboBox *>(_pEntity);
	}
	inline wxComboBox *ReleaseEntity() {
		wxComboBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxComboBox");
		return true;
	}
};

}}

#endif
