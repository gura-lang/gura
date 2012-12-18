//----------------------------------------------------------------------------
// wxGridEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDEVENT_H__
#define __OBJECT_WX_GRIDEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridEvent);

//----------------------------------------------------------------------------
// Object declaration for wxGridEvent
//----------------------------------------------------------------------------
class Object_wx_GridEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_GridEvent)
public:
	inline Object_wx_GridEvent(wxGridEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_GridEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridEvent(Class *pClass, wxGridEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridEvent *GetEntity() {
		return dynamic_cast<wxGridEvent *>(_pEntity);
	}
	inline wxGridEvent *ReleaseEntity() {
		wxGridEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
