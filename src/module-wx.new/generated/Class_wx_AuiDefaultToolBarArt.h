//----------------------------------------------------------------------------
// wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUIDEFAULTTOOLBARART_H__
#define __CLASS_WX_AUIDEFAULTTOOLBARART_H__
#include <wx/aui/auibar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiDefaultToolBarArt);

//----------------------------------------------------------------------------
// Object declaration for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
class Object_wx_AuiDefaultToolBarArt : public Object_wx_AuiToolBarArt {
public:
	Gura_DeclareObjectAccessor(wx_AuiDefaultToolBarArt)
public:
	inline Object_wx_AuiDefaultToolBarArt(wxAuiDefaultToolBarArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AuiToolBarArt(Gura_UserClass(wx_AuiDefaultToolBarArt), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiDefaultToolBarArt(Class *pClass, wxAuiDefaultToolBarArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AuiToolBarArt(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiDefaultToolBarArt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiDefaultToolBarArt *GetEntity() {
		return static_cast<wxAuiDefaultToolBarArt *>(_pEntity);
	}
	inline wxAuiDefaultToolBarArt *ReleaseEntity() {
		wxAuiDefaultToolBarArt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiDefaultToolBarArt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
