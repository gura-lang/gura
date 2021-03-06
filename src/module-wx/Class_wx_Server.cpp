//----------------------------------------------------------------------------
// wxServer
// extracted from ipcservr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnAcceptConnection);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Server: public wxServer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Server *_pObj;
public:
	inline wx_Server() : wxServer(), _pObj(nullptr) {}
	//virtual wxConnectionBase * OnAcceptConnection(const wxString& topic);
	~wx_Server();
	inline void AssocWithGura(Object_wx_Server *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Server::~wx_Server()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Server::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(ServerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Server));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ServerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Server *pEntity = new wx_Server();
	Object_wx_Server *pObj = Object_wx_Server::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Server(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Server, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Server, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Server *pThis = Object_wx_Server::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString service = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Create(service);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Server, OnAcceptConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Server, OnAcceptConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Server *pThis = Object_wx_Server::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(arg.GetString(0));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnAcceptConnection(topic);
	return ReturnValue(env, arg, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxServer
//----------------------------------------------------------------------------
Object_wx_Server::~Object_wx_Server()
{
}

Object *Object_wx_Server::Clone() const
{
	return nullptr;
}

String Object_wx_Server::ToString(bool exprFlag)
{
	String rtn("<wx.Server:");
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
// Class implementation for wxServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Server)
{
	Gura_RealizeUserSymbol(OnAcceptConnection);
	Gura_AssignFunction(ServerEmpty);
	Gura_AssignMethod(wx_Server, Create);
	Gura_AssignMethod(wx_Server, OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_Server)
{
	return new Object_wx_Server((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
