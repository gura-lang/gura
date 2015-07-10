//----------------------------------------------------------------------------
// wxTCPClient
// extracted from tcpclint.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TCPCLIENT_H__
#define __CLASS_WX_TCPCLIENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTCPClient
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TCPClient);

//----------------------------------------------------------------------------
// Object declaration for wxTCPClient
//----------------------------------------------------------------------------
class Object_wx_TCPClient : public Object_wx_ClientBase {
public:
	Gura_DeclareObjectAccessor(wx_TCPClient)
public:
	inline Object_wx_TCPClient(wxTCPClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientBase(Gura_UserClass(wx_TCPClient), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TCPClient(Class *pClass, wxTCPClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TCPClient();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTCPClient *GetEntity() {
		return dynamic_cast<wxTCPClient *>(_pEntity);
	}
	inline wxTCPClient *ReleaseEntity() {
		wxTCPClient *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTCPClient");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
