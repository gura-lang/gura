//----------------------------------------------------------------------------
// wxSocketServer
// extracted from socksrv.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SOCKETSERVER_H__
#define __CLASS_WX_SOCKETSERVER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSocketServer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SocketServer);

//----------------------------------------------------------------------------
// Object declaration for wxSocketServer
//----------------------------------------------------------------------------
class Object_wx_SocketServer : public Object_wx_SocketBase {
public:
	Gura_DeclareObjectAccessor(wx_SocketServer)
public:
	inline Object_wx_SocketServer(wxSocketServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketBase(Gura_UserClass(wx_SocketServer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SocketServer(Class *pClass, wxSocketServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SocketBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SocketServer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSocketServer *GetEntity() {
		return dynamic_cast<wxSocketServer *>(_pEntity);
	}
	inline wxSocketServer *ReleaseEntity() {
		wxSocketServer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSocketServer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
