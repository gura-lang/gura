//----------------------------------------------------------------------------
// wxMouseCaptureChangedEvent
// extracted from mcaptevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MOUSECAPTURECHANGEDEVENT_H__
#define __OBJECT_WX_MOUSECAPTURECHANGEDEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MouseCaptureChangedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxMouseCaptureChangedEvent
//----------------------------------------------------------------------------
class Object_wx_MouseCaptureChangedEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_MouseCaptureChangedEvent)
public:
	inline Object_wx_MouseCaptureChangedEvent(wxMouseCaptureChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_MouseCaptureChangedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MouseCaptureChangedEvent(Class *pClass, wxMouseCaptureChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MouseCaptureChangedEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMouseCaptureChangedEvent *GetEntity() {
		return dynamic_cast<wxMouseCaptureChangedEvent *>(_pEntity);
	}
	inline wxMouseCaptureChangedEvent *ReleaseEntity() {
		wxMouseCaptureChangedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMouseCaptureChangedEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
