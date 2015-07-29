//----------------------------------------------------------------------------
// wxDDEServer
// extracted from ddeservr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnAcceptConnection);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DDEServer: public wxDDEServer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DDEServer *_pObj;
public:
	inline wx_DDEServer() : wxDDEServer(), _pObj(nullptr) {}
	//virtual wxConnectionBase * OnAcceptConnection(const wxString& topic);
	~wx_DDEServer();
	inline void AssocWithGura(Object_wx_DDEServer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DDEServer::~wx_DDEServer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DDEServer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DDEServerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEServer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DDEServerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DDEServer *pEntity = new wx_DDEServer();
	Object_wx_DDEServer *pObj = Object_wx_DDEServer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DDEServer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DDEServer, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEServer, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEServer *pThis = Object_wx_DDEServer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString service = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Create(service);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DDEServer, OnAcceptConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEServer, OnAcceptConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEServer *pThis = Object_wx_DDEServer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnAcceptConnection(topic);
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDDEServer
//----------------------------------------------------------------------------
Object_wx_DDEServer::~Object_wx_DDEServer()
{
}

Object *Object_wx_DDEServer::Clone() const
{
	return nullptr;
}

String Object_wx_DDEServer::ToString(bool exprFlag)
{
	String rtn("<wx.DDEServer:");
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
// Class implementation for wxDDEServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEServer)
{
	Gura_RealizeUserSymbol(OnAcceptConnection);
	Gura_AssignFunction(DDEServerEmpty);
	Gura_AssignMethod(wx_DDEServer, Create);
	Gura_AssignMethod(wx_DDEServer, OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_DDEServer)
{
	return new Object_wx_DDEServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
