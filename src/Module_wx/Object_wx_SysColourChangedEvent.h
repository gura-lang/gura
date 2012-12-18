//----------------------------------------------------------------------------
// wxSysColourChangedEvent
// extracted from sysclevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SYSCOLOURCHANGEDEVENT_H__
#define __OBJECT_WX_SYSCOLOURCHANGEDEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SysColourChangedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSysColourChangedEvent
//----------------------------------------------------------------------------
class Object_wx_SysColourChangedEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_SysColourChangedEvent)
public:
	inline Object_wx_SysColourChangedEvent(wxSysColourChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_SysColourChangedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SysColourChangedEvent(Class *pClass, wxSysColourChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SysColourChangedEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSysColourChangedEvent *GetEntity() {
		return dynamic_cast<wxSysColourChangedEvent *>(_pEntity);
	}
	inline wxSysColourChangedEvent *ReleaseEntity() {
		wxSysColourChangedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSysColourChangedEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
