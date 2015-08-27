//----------------------------------------------------------------------------
// wxTCPServer
// extracted from tcpservr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnAcceptConnection);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TCPServer: public wxTCPServer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TCPServer *_pObj;
public:
	inline wx_TCPServer() : wxTCPServer(), _pObj(nullptr) {}
	//virtual wxConnectionBase * OnAcceptConnection(const wxString& topic);
	~wx_TCPServer();
	inline void AssocWithGura(Object_wx_TCPServer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TCPServer::~wx_TCPServer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TCPServer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(TCPServerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPServer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TCPServerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TCPServer *pEntity = new wx_TCPServer();
	Object_wx_TCPServer *pObj = Object_wx_TCPServer::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TCPServer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_TCPServer, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPServer, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString service = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Create(service);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPServer, OnAcceptConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPServer, OnAcceptConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnAcceptConnection(topic);
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxTCPServer
//----------------------------------------------------------------------------
Object_wx_TCPServer::~Object_wx_TCPServer()
{
}

Object *Object_wx_TCPServer::Clone() const
{
	return nullptr;
}

String Object_wx_TCPServer::ToString(bool exprFlag)
{
	String rtn("<wx.TCPServer:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPServer)
{
	Gura_RealizeUserSymbol(OnAcceptConnection);
	Gura_AssignFunction(TCPServerEmpty);
	Gura_AssignMethod(wx_TCPServer, Create);
	Gura_AssignMethod(wx_TCPServer, OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_TCPServer)
{
	return new Object_wx_TCPServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
