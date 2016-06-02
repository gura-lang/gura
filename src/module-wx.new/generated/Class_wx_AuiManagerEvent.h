//----------------------------------------------------------------------------
// wxAuiManagerEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUIMANAGEREVENT_H__
#define __CLASS_WX_AUIMANAGEREVENT_H__
#include <wx/aui/framemanager.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiManagerEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiManagerEvent);

//----------------------------------------------------------------------------
// Object declaration for wxAuiManagerEvent
//----------------------------------------------------------------------------
class Object_wx_AuiManagerEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_AuiManagerEvent)
public:
	inline Object_wx_AuiManagerEvent(wxAuiManagerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_AuiManagerEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AuiManagerEvent(Class *pClass, wxAuiManagerEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AuiManagerEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAuiManagerEvent *GetEntity() {
		return static_cast<wxAuiManagerEvent *>(_pEntity);
	}
	inline wxAuiManagerEvent *ReleaseEntity() {
		wxAuiManagerEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAuiManagerEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
