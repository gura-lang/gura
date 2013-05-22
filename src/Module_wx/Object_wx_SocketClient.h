//----------------------------------------------------------------------------
// wxSocketClient
// extracted from socket.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SOCKETCLIENT_H__
#define __OBJECT_WX_SOCKETCLIENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSocketClient
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SocketClient);

//----------------------------------------------------------------------------
// Object declaration for wxSocketClient
//----------------------------------------------------------------------------
class Object_wx_SocketClient : public Object_wx_SocketBase {
public:
	Gura_DeclareObjectAccessor(wx_SocketClient)
public:
	inline Object_wx_SocketClient(wxSocketClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketBase(Gura_UserClass(wx_SocketClient), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SocketClient(Class *pClass, wxSocketClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SocketClient();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSocketClient *GetEntity() {
		return dynamic_cast<wxSocketClient *>(_pEntity);
	}
	inline wxSocketClient *ReleaseEntity() {
		wxSocketClient *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSocketClient");
		return true;
	}
};

}}

#endif
