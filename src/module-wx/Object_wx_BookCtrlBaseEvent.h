//----------------------------------------------------------------------------
// wxBookCtrlBaseEvent
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BOOKCTRLBASEEVENT_H__
#define __OBJECT_WX_BOOKCTRLBASEEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBookCtrlBaseEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BookCtrlBaseEvent);

//----------------------------------------------------------------------------
// Object declaration for wxBookCtrlBaseEvent
//----------------------------------------------------------------------------
class Object_wx_BookCtrlBaseEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_BookCtrlBaseEvent)
public:
	inline Object_wx_BookCtrlBaseEvent(wxBookCtrlBaseEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_BookCtrlBaseEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BookCtrlBaseEvent(Class *pClass, wxBookCtrlBaseEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BookCtrlBaseEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxBookCtrlBaseEvent *GetEntity() {
		return dynamic_cast<wxBookCtrlBaseEvent *>(_pEntity);
	}
	inline wxBookCtrlBaseEvent *ReleaseEntity() {
		wxBookCtrlBaseEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBookCtrlBaseEvent");
		return true;
	}
};

}}

#endif
