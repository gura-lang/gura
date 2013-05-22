//----------------------------------------------------------------------------
// wxCheckBox
// extracted from checkbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CHECKBOX_H__
#define __OBJECT_WX_CHECKBOX_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCheckBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CheckBox);

//----------------------------------------------------------------------------
// Object declaration for wxCheckBox
//----------------------------------------------------------------------------
class Object_wx_CheckBox : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_CheckBox)
public:
	inline Object_wx_CheckBox(wxCheckBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_CheckBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CheckBox(Class *pClass, wxCheckBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CheckBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxCheckBox *GetEntity() {
		return dynamic_cast<wxCheckBox *>(_pEntity);
	}
	inline wxCheckBox *ReleaseEntity() {
		wxCheckBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCheckBox");
		return true;
	}
};

}}

#endif
