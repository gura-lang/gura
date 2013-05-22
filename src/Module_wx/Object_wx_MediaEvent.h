//----------------------------------------------------------------------------
// wxMediaEvent
// extracted from mediaevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MEDIAEVENT_H__
#define __OBJECT_WX_MEDIAEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMediaEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MediaEvent);

//----------------------------------------------------------------------------
// Object declaration for wxMediaEvent
//----------------------------------------------------------------------------
class Object_wx_MediaEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_MediaEvent)
public:
	inline Object_wx_MediaEvent(wxMediaEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_MediaEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MediaEvent(Class *pClass, wxMediaEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MediaEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMediaEvent *GetEntity() {
		return dynamic_cast<wxMediaEvent *>(_pEntity);
	}
	inline wxMediaEvent *ReleaseEntity() {
		wxMediaEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMediaEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
