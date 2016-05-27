//----------------------------------------------------------------------------
// wxAuiToolBar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUITOOLBAR_H__
#define __CLASS_WX_AUITOOLBAR_H__
#include <wx/aui/auibar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiToolBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiToolBar);

//----------------------------------------------------------------------------
// Object declaration for wxAuiToolBar
//----------------------------------------------------------------------------
class Object_wx_AuiToolBar : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_AuiToolBar)
public:
	inline Object_wx_AuiToolBar(wxAuiToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_AuiToolBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiToolBar(Class *pClass, wxAuiToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiToolBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiToolBar *GetEntity() {
		return static_cast<wxAuiToolBar *>(_pEntity);
	}
	inline wxAuiToolBar *ReleaseEntity() {
		wxAuiToolBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiToolBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
