//----------------------------------------------------------------------------
// wxProtocol
// extracted from protocol.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PROTOCOL_H__
#define __OBJECT_WX_PROTOCOL_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxProtocol
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Protocol);

//----------------------------------------------------------------------------
// Object declaration for wxProtocol
//----------------------------------------------------------------------------
class Object_wx_Protocol : public Object_wx_SocketClient {
public:
	Gura_DeclareObjectAccessor(wx_Protocol)
public:
	inline Object_wx_Protocol(wxProtocol *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketClient(Gura_UserClass(wx_Protocol), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Protocol(Class *pClass, wxProtocol *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketClient(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Protocol();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxProtocol *GetEntity() {
		return dynamic_cast<wxProtocol *>(_pEntity);
	}
	inline wxProtocol *ReleaseEntity() {
		wxProtocol *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxProtocol");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
