//----------------------------------------------------------------------------
// wxIconizeEvent
// extracted from iconevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ICONIZEEVENT_H__
#define __OBJECT_WX_ICONIZEEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IconizeEvent);

//----------------------------------------------------------------------------
// Object declaration for wxIconizeEvent
//----------------------------------------------------------------------------
class Object_wx_IconizeEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_IconizeEvent)
public:
	inline Object_wx_IconizeEvent(wxIconizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_IconizeEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IconizeEvent(Class *pClass, wxIconizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IconizeEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxIconizeEvent *GetEntity() {
		return dynamic_cast<wxIconizeEvent *>(_pEntity);
	}
	inline wxIconizeEvent *ReleaseEntity() {
		wxIconizeEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxIconizeEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
