//----------------------------------------------------------------------------
// wxTCPConnection
// extracted from tcpconn.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TCPCONNECTION_H__
#define __OBJECT_WX_TCPCONNECTION_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTCPConnection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TCPConnection);

//----------------------------------------------------------------------------
// Object declaration for wxTCPConnection
//----------------------------------------------------------------------------
class Object_wx_TCPConnection : public Object_wx_ConnectionBase {
public:
	Gura_DeclareObjectAccessor(wx_TCPConnection)
public:
	inline Object_wx_TCPConnection(wxTCPConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConnectionBase(Gura_UserClass(wx_TCPConnection), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TCPConnection(Class *pClass, wxTCPConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConnectionBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TCPConnection();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTCPConnection *GetEntity() {
		return dynamic_cast<wxTCPConnection *>(_pEntity);
	}
	inline wxTCPConnection *ReleaseEntity() {
		wxTCPConnection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTCPConnection");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
