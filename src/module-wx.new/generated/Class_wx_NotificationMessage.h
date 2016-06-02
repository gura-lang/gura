//----------------------------------------------------------------------------
// wxNotificationMessage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NOTIFICATIONMESSAGE_H__
#define __CLASS_WX_NOTIFICATIONMESSAGE_H__
#include <wx/notifmsg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNotificationMessage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NotificationMessage);

//----------------------------------------------------------------------------
// Object declaration for wxNotificationMessage
//----------------------------------------------------------------------------
class Object_wx_NotificationMessage : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_NotificationMessage)
public:
	inline Object_wx_NotificationMessage(wxNotificationMessage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_NotificationMessage), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NotificationMessage(Class *pClass, wxNotificationMessage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NotificationMessage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxNotificationMessage *GetEntity() {
		return static_cast<wxNotificationMessage *>(_pEntity);
	}
	inline wxNotificationMessage *ReleaseEntity() {
		wxNotificationMessage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxNotificationMessage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
