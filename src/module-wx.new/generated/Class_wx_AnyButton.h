//----------------------------------------------------------------------------
// wxAnyButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ANYBUTTON_H__
#define __CLASS_WX_ANYBUTTON_H__
#include <wx/anybutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAnyButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AnyButton);

//----------------------------------------------------------------------------
// Object declaration for wxAnyButton
//----------------------------------------------------------------------------
class Object_wx_AnyButton : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_AnyButton)
public:
	inline Object_wx_AnyButton(wxAnyButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_AnyButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AnyButton(Class *pClass, wxAnyButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AnyButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAnyButton *GetEntity() {
		return static_cast<wxAnyButton *>(_pEntity);
	}
	inline wxAnyButton *ReleaseEntity() {
		wxAnyButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAnyButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
