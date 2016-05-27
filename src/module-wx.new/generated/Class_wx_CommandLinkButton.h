//----------------------------------------------------------------------------
// wxCommandLinkButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COMMANDLINKBUTTON_H__
#define __CLASS_WX_COMMANDLINKBUTTON_H__
#include <wx/commandlinkbutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCommandLinkButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CommandLinkButton);

//----------------------------------------------------------------------------
// Object declaration for wxCommandLinkButton
//----------------------------------------------------------------------------
class Object_wx_CommandLinkButton : public Object_wx_Button {
public:
	Gura_DeclareObjectAccessor(wx_CommandLinkButton)
public:
	inline Object_wx_CommandLinkButton(wxCommandLinkButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Button(Gura_UserClass(wx_CommandLinkButton), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CommandLinkButton(Class *pClass, wxCommandLinkButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Button(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CommandLinkButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCommandLinkButton *GetEntity() {
		return static_cast<wxCommandLinkButton *>(_pEntity);
	}
	inline wxCommandLinkButton *ReleaseEntity() {
		wxCommandLinkButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxCommandLinkButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
