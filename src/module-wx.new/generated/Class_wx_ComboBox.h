//----------------------------------------------------------------------------
// wxComboBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COMBOBOX_H__
#define __CLASS_WX_COMBOBOX_H__
#include <wx/combobox.h>

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxComboBox *GetEntity() {
		return static_cast<wxComboBox *>(_pEntity);
	}
	inline wxComboBox *ReleaseEntity() {
		wxComboBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxComboBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
