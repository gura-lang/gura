//----------------------------------------------------------------------------
// wxSocketEvent
// extracted from socket.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SOCKETEVENT_H__
#define __OBJECT_WX_SOCKETEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSocketEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SocketEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSocketEvent
//----------------------------------------------------------------------------
class Object_wx_SocketEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_SocketEvent)
public:
	inline Object_wx_SocketEvent(wxSocketEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_SocketEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SocketEvent(Class *pClass, wxSocketEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SocketEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSocketEvent *GetEntity() {
		return dynamic_cast<wxSocketEvent *>(_pEntity);
	}
	inline wxSocketEvent *ReleaseEntity() {
		wxSocketEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSocketEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
