//----------------------------------------------------------------------------
// wxDatagramSocket
// extracted from dgramsocket.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAGRAMSOCKET_H__
#define __OBJECT_WX_DATAGRAMSOCKET_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDatagramSocket
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DatagramSocket);

//----------------------------------------------------------------------------
// Object declaration for wxDatagramSocket
//----------------------------------------------------------------------------
class Object_wx_DatagramSocket : public Object_wx_SocketBase {
public:
	Gura_DeclareObjectAccessor(wx_DatagramSocket)
public:
	inline Object_wx_DatagramSocket(wxDatagramSocket *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketBase(Gura_UserClass(wx_DatagramSocket), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DatagramSocket(Class *pClass, wxDatagramSocket *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DatagramSocket();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDatagramSocket *GetEntity() {
		return dynamic_cast<wxDatagramSocket *>(_pEntity);
	}
	inline wxDatagramSocket *ReleaseEntity() {
		wxDatagramSocket *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDatagramSocket");
		return true;
	}
};

}}

#endif
