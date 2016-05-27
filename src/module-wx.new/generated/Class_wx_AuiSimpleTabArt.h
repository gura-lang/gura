//----------------------------------------------------------------------------
// wxAuiSimpleTabArt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUISIMPLETABART_H__
#define __CLASS_WX_AUISIMPLETABART_H__
#include <wx/aui/auibook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiSimpleTabArt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiSimpleTabArt);

//----------------------------------------------------------------------------
// Object declaration for wxAuiSimpleTabArt
//----------------------------------------------------------------------------
class Object_wx_AuiSimpleTabArt : public Object_wx_AuiTabArt {
public:
	Gura_DeclareObjectAccessor(wx_AuiSimpleTabArt)
public:
	inline Object_wx_AuiSimpleTabArt(wxAuiSimpleTabArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AuiTabArt(Gura_UserClass(wx_AuiSimpleTabArt), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiSimpleTabArt(Class *pClass, wxAuiSimpleTabArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AuiTabArt(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiSimpleTabArt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiSimpleTabArt *GetEntity() {
		return static_cast<wxAuiSimpleTabArt *>(_pEntity);
	}
	inline wxAuiSimpleTabArt *ReleaseEntity() {
		wxAuiSimpleTabArt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiSimpleTabArt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
