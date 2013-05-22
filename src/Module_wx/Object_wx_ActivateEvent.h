//----------------------------------------------------------------------------
// wxActivateEvent
// extracted from activevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ACTIVATEEVENT_H__
#define __OBJECT_WX_ACTIVATEEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxActivateEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ActivateEvent);

//----------------------------------------------------------------------------
// Object declaration for wxActivateEvent
//----------------------------------------------------------------------------
class Object_wx_ActivateEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_ActivateEvent)
public:
	inline Object_wx_ActivateEvent(wxActivateEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_ActivateEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ActivateEvent(Class *pClass, wxActivateEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ActivateEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxActivateEvent *GetEntity() {
		return dynamic_cast<wxActivateEvent *>(_pEntity);
	}
	inline wxActivateEvent *ReleaseEntity() {
		wxActivateEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxActivateEvent");
		return true;
	}
};

}}

#endif
