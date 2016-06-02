//----------------------------------------------------------------------------
// wxBitmapComboBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BITMAPCOMBOBOX_H__
#define __CLASS_WX_BITMAPCOMBOBOX_H__
#include <wx/bmpcbox.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBitmapComboBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BitmapComboBox);

//----------------------------------------------------------------------------
// Object declaration for wxBitmapComboBox
//----------------------------------------------------------------------------
class Object_wx_BitmapComboBox : public Object_wx_ComboBox {
public:
	Gura_DeclareObjectAccessor(wx_BitmapComboBox)
public:
	inline Object_wx_BitmapComboBox(wxBitmapComboBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ComboBox(Gura_UserClass(wx_BitmapComboBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BitmapComboBox(Class *pClass, wxBitmapComboBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ComboBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BitmapComboBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBitmapComboBox *GetEntity() {
		return static_cast<wxBitmapComboBox *>(_pEntity);
	}
	inline wxBitmapComboBox *ReleaseEntity() {
		wxBitmapComboBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxBitmapComboBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
