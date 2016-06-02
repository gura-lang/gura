//----------------------------------------------------------------------------
// wxBitmapToggleButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BITMAPTOGGLEBUTTON_H__
#define __CLASS_WX_BITMAPTOGGLEBUTTON_H__
#include <wx/tglbtn.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBitmapToggleButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BitmapToggleButton);

//----------------------------------------------------------------------------
// Object declaration for wxBitmapToggleButton
//----------------------------------------------------------------------------
class Object_wx_BitmapToggleButton : public Object_wx_ToggleButton {
public:
	Gura_DeclareObjectAccessor(wx_BitmapToggleButton)
public:
	inline Object_wx_BitmapToggleButton(wxBitmapToggleButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ToggleButton(Gura_UserClass(wx_BitmapToggleButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BitmapToggleButton(Class *pClass, wxBitmapToggleButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ToggleButton(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BitmapToggleButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBitmapToggleButton *GetEntity() {
		return static_cast<wxBitmapToggleButton *>(_pEntity);
	}
	inline wxBitmapToggleButton *ReleaseEntity() {
		wxBitmapToggleButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxBitmapToggleButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
