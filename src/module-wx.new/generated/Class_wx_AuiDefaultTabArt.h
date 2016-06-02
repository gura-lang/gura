//----------------------------------------------------------------------------
// wxAuiDefaultTabArt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUIDEFAULTTABART_H__
#define __CLASS_WX_AUIDEFAULTTABART_H__
#include <wx/aui/auibook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiDefaultTabArt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiDefaultTabArt);

//----------------------------------------------------------------------------
// Object declaration for wxAuiDefaultTabArt
//----------------------------------------------------------------------------
class Object_wx_AuiDefaultTabArt : public Object_wx_AuiTabArt {
public:
	Gura_DeclareObjectAccessor(wx_AuiDefaultTabArt)
public:
	inline Object_wx_AuiDefaultTabArt(wxAuiDefaultTabArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AuiTabArt(Gura_UserClass(wx_AuiDefaultTabArt), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiDefaultTabArt(Class *pClass, wxAuiDefaultTabArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AuiTabArt(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiDefaultTabArt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiDefaultTabArt *GetEntity() {
		return static_cast<wxAuiDefaultTabArt *>(_pEntity);
	}
	inline wxAuiDefaultTabArt *ReleaseEntity() {
		wxAuiDefaultTabArt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAuiDefaultTabArt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
