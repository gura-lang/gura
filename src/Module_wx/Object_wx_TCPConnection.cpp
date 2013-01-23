//----------------------------------------------------------------------------
// wxTCPConnection
// extracted from tcpconn.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnAdvise);
Gura_DeclarePrivUserSymbol(OnDisconnect);
Gura_DeclarePrivUserSymbol(OnExecute);
Gura_DeclarePrivUserSymbol(OnPoke);
Gura_DeclarePrivUserSymbol(OnRequest);
Gura_DeclarePrivUserSymbol(OnStartAdvise);
Gura_DeclarePrivUserSymbol(OnStopAdvise);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TCPConnection: public wxTCPConnection, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TCPConnection *_pObj;
public:
	inline wx_TCPConnection() : wxTCPConnection(), _sig(NULL), _pObj(NULL) {}
	//inline wx_TCPConnection(char* buffer, int size) : wxTCPConnection(buffer, size), _sig(NULL), _pObj(NULL) {}
	//virtual bool OnAdvise(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual bool OnDisconnect();
	//virtual bool OnExecute(const wxString& topic, char* data, int size, wxIPCFormat format);
	//virtual bool OnPoke(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual char* OnRequest(const wxString& topic, const wxString& item, int * size, wxIPCFormat format);
	//virtual bool OnStartAdvise(const wxString& topic, const wxString& item);
	//virtual bool OnStopAdvise(const wxString& topic, const wxString& item);
	~wx_TCPConnection();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TCPConnection *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TCPConnection::~wx_TCPConnection()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TCPConnection::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPConnection
//----------------------------------------------------------------------------
Gura_DeclareFunction(TCPConnectionEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TCPConnectionEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TCPConnection *pEntity = new wx_TCPConnection();
	Object_wx_TCPConnection *pObj = Object_wx_TCPConnection::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TCPConnection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(TCPConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TCPConnection)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char buffer = args.GetChar(0);
	int size = args.GetInt(1);
	wx_TCPConnection *pEntity = new wx_TCPConnection(buffer, size);
	Object_wx_TCPConnection *pObj = Object_wx_TCPConnection::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TCPConnection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, Advise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Advise)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = -1;
	if (args.IsValid(2)) size = args.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(3)) format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pSelf->GetEntity()->Advise(item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, Execute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Execute)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char data = args.GetChar(0);
	int size = -1;
	if (args.IsValid(1)) size = args.GetInt(1);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(2)) format = static_cast<wxIPCFormat>(args.GetInt(2));
	bool rtn = pSelf->GetEntity()->Execute(data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, Disconnect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Disconnect)
{
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Disconnect();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, OnAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnAdvise)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	char data = args.GetChar(2);
	int size = args.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(4));
	bool rtn = pSelf->GetEntity()->OnAdvise(topic, item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, OnDisconnect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnDisconnect)
{
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->OnDisconnect();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, OnExecute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnExecute)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = args.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pSelf->GetEntity()->OnExecute(topic, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, OnPoke)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnPoke)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	char data = args.GetChar(2);
	int size = args.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(4));
	bool rtn = pSelf->GetEntity()->OnPoke(topic, item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, OnRequest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnRequest)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	int size = args.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(3));
	char rtn = pSelf->GetEntity()->OnRequest(topic, item, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, OnStartAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnStartAdvise)
{
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->OnStartAdvise(topic, item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, OnStopAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnStopAdvise)
{
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->OnStopAdvise(topic, item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, Poke)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Poke)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = -1;
	if (args.IsValid(2)) size = args.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(3)) format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pSelf->GetEntity()->Poke(item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, Request)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Request)
{
#if 0
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	int size = args.GetInt(1);
	wxIPCFormat format = wxIPC_TEXT;
	if (args.IsValid(2)) format = static_cast<wxIPCFormat>(args.GetInt(2));
	char rtn = pSelf->GetEntity()->Request(item, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TCPConnection, StartAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, StartAdvise)
{
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->StartAdvise(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, StopAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, StopAdvise)
{
	Object_wx_TCPConnection *pSelf = Object_wx_TCPConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->StopAdvise(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTCPConnection
//----------------------------------------------------------------------------
Object_wx_TCPConnection::~Object_wx_TCPConnection()
{
}

Object *Object_wx_TCPConnection::Clone() const
{
	return NULL;
}

String Object_wx_TCPConnection::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TCPConnection:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TCPConnection::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnAdvise);
	Gura_RealizeUserSymbol(OnDisconnect);
	Gura_RealizeUserSymbol(OnExecute);
	Gura_RealizeUserSymbol(OnPoke);
	Gura_RealizeUserSymbol(OnRequest);
	Gura_RealizeUserSymbol(OnStartAdvise);
	Gura_RealizeUserSymbol(OnStopAdvise);
	Gura_AssignFunction(TCPConnectionEmpty);
	Gura_AssignFunction(TCPConnection);
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPConnection)
{
	Gura_AssignMethod(wx_TCPConnection, Advise);
	Gura_AssignMethod(wx_TCPConnection, Execute);
	Gura_AssignMethod(wx_TCPConnection, Disconnect);
	Gura_AssignMethod(wx_TCPConnection, OnAdvise);
	Gura_AssignMethod(wx_TCPConnection, OnDisconnect);
	Gura_AssignMethod(wx_TCPConnection, OnExecute);
	Gura_AssignMethod(wx_TCPConnection, OnPoke);
	Gura_AssignMethod(wx_TCPConnection, OnRequest);
	Gura_AssignMethod(wx_TCPConnection, OnStartAdvise);
	Gura_AssignMethod(wx_TCPConnection, OnStopAdvise);
	Gura_AssignMethod(wx_TCPConnection, Poke);
	Gura_AssignMethod(wx_TCPConnection, Request);
	Gura_AssignMethod(wx_TCPConnection, StartAdvise);
	Gura_AssignMethod(wx_TCPConnection, StopAdvise);
}

Gura_ImplementDescendantCreator(wx_TCPConnection)
{
	return new Object_wx_TCPConnection((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
