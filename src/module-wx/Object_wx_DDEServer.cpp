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
	Gura::Signal _sig;
	Object_wx_DDEServer *_pObj;
public:
	inline wx_DDEServer() : wxDDEServer(), _sig(NULL), _pObj(NULL) {}
	//virtual wxConnectionBase * OnAcceptConnection(const wxString& topic);
	~wx_DDEServer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DDEServer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DDEServer::~wx_DDEServer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DDEServer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(DDEServerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEServer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DDEServerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DDEServer *pEntity = new wx_DDEServer();
	Object_wx_DDEServer *pObj = Object_wx_DDEServer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DDEServer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DDEServer, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEServer, Create)
{
	Object_wx_DDEServer *pThis = Object_wx_DDEServer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString service = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Create(service);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DDEServer, OnAcceptConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEServer, OnAcceptConnection)
{
	Object_wx_DDEServer *pThis = Object_wx_DDEServer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnAcceptConnection(topic);
	return ReturnValue(env, sig, args, Value(new Object_wx_ConnectionBase(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDDEServer
//----------------------------------------------------------------------------
Object_wx_DDEServer::~Object_wx_DDEServer()
{
}

Object *Object_wx_DDEServer::Clone() const
{
	return NULL;
}

String Object_wx_DDEServer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DDEServer:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_DDEServer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
