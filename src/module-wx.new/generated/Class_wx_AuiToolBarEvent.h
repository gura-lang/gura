//----------------------------------------------------------------------------
// wxAuiToolBarEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUITOOLBAREVENT_H__
#define __CLASS_WX_AUITOOLBAREVENT_H__
#include <wx/aui/auibar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiToolBarEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiToolBarEvent);

//----------------------------------------------------------------------------
// Object declaration for wxAuiToolBarEvent
//----------------------------------------------------------------------------
class Object_wx_AuiToolBarEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_AuiToolBarEvent)
public:
	inline Object_wx_AuiToolBarEvent(wxAuiToolBarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_AuiToolBarEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiToolBarEvent(Class *pClass, wxAuiToolBarEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiToolBarEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiToolBarEvent *GetEntity() {
		return static_cast<wxAuiToolBarEvent *>(_pEntity);
	}
	inline wxAuiToolBarEvent *ReleaseEntity() {
		wxAuiToolBarEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAuiToolBarEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
