//----------------------------------------------------------------------------
// wxTCPServer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TCPSERVER_H__
#define __CLASS_WX_TCPSERVER_H__
#include <wx/sckipc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTCPServer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TCPServer);

//----------------------------------------------------------------------------
// Object declaration for wxTCPServer
//----------------------------------------------------------------------------
class Object_wx_TCPServer : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_TCPServer)
public:
	inline Object_wx_TCPServer(wxTCPServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_TCPServer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TCPServer(Class *pClass, wxTCPServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TCPServer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTCPServer *GetEntity() {
		return static_cast<wxTCPServer *>(_pEntity);
	}
	inline wxTCPServer *ReleaseEntity() {
		wxTCPServer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTCPServer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
