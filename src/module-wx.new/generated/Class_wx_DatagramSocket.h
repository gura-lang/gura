//----------------------------------------------------------------------------
// wxDatagramSocket
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAGRAMSOCKET_H__
#define __CLASS_WX_DATAGRAMSOCKET_H__
#include <wx/socket.h>

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxDatagramSocket *GetEntity() {
		return static_cast<wxDatagramSocket *>(_pEntity);
	}
	inline wxDatagramSocket *ReleaseEntity() {
		wxDatagramSocket *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDatagramSocket");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
