//----------------------------------------------------------------------------
// wxNotifyEvent
// extracted from notifevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_NOTIFYEVENT_H__
#define __OBJECT_WX_NOTIFYEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNotifyEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NotifyEvent);

//----------------------------------------------------------------------------
// Object declaration for wxNotifyEvent
//----------------------------------------------------------------------------
class Object_wx_NotifyEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_NotifyEvent)
public:
	inline Object_wx_NotifyEvent(wxNotifyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_NotifyEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NotifyEvent(Class *pClass, wxNotifyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NotifyEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxNotifyEvent *GetEntity() {
		return dynamic_cast<wxNotifyEvent *>(_pEntity);
	}
	inline wxNotifyEvent *ReleaseEntity() {
		wxNotifyEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxNotifyEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
