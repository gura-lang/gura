//----------------------------------------------------------------------------
// wxTCPConnection
// extracted from tcpconn.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	//Gura::Signal *_pSig;
	Object_wx_TCPConnection *_pObj;
public:
	inline wx_TCPConnection() : wxTCPConnection(), _pObj(nullptr) {}
	//inline wx_TCPConnection(char* buffer, int size) : wxTCPConnection(buffer, size), _pObj(nullptr) {}
	//virtual bool OnAdvise(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual bool OnDisconnect();
	//virtual bool OnExecute(const wxString& topic, char* data, int size, wxIPCFormat format);
	//virtual bool OnPoke(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual char* OnRequest(const wxString& topic, const wxString& item, int * size, wxIPCFormat format);
	//virtual bool OnStartAdvise(const wxString& topic, const wxString& item);
	//virtual bool OnStopAdvise(const wxString& topic, const wxString& item);
	~wx_TCPConnection();
	inline void AssocWithGura(Object_wx_TCPConnection *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TCPConnection::~wx_TCPConnection()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TCPConnection::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPConnection
//----------------------------------------------------------------------------
Gura_DeclareFunction(TCPConnectionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TCPConnectionEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TCPConnection *pEntity = new wx_TCPConnection();
	Object_wx_TCPConnection *pObj = Object_wx_TCPConnection::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TCPConnection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(TCPConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TCPConnection)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char buffer = args.GetChar(0);
	int size = args.GetInt(1);
	wx_TCPConnection *pEntity = new wx_TCPConnection(buffer, size);
	Object_wx_TCPConnection *pObj = Object_wx_TCPConnection::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TCPConnection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Advise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = -1;
	if (args.IsValid(2)) size = args.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(3)) format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Advise(item, data, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Execute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Execute)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char data = args.GetChar(0);
	int size = -1;
	if (args.IsValid(1)) size = args.GetInt(1);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(2)) format = static_cast<wxIPCFormat>(args.GetInt(2));
	bool rtn = pThis->GetEntity()->Execute(data, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Disconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Disconnect();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, OnAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	char data = args.GetChar(2);
	int size = args.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(4));
	bool rtn = pThis->GetEntity()->OnAdvise(topic, item, data, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnDisconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnDisconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->OnDisconnect();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, OnExecute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = args.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->OnExecute(topic, data, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnPoke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	char data = args.GetChar(2);
	int size = args.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(4));
	bool rtn = pThis->GetEntity()->OnPoke(topic, item, data, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnRequest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	int size = args.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(3));
	char rtn = pThis->GetEntity()->OnRequest(topic, item, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnStartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnStartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->OnStartAdvise(topic, item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, OnStopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, OnStopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->OnStopAdvise(topic, item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, Poke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = -1;
	if (args.IsValid(2)) size = args.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(3)) format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Poke(item, data, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Request)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, Request)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	int size = args.GetInt(1);
	wxIPCFormat format = wxIPC_TEXT;
	if (args.IsValid(2)) format = static_cast<wxIPCFormat>(args.GetInt(2));
	char rtn = pThis->GetEntity()->Request(item, size, format);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, StartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, StartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StartAdvise(item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPConnection, StopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPConnection, StopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StopAdvise(item);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTCPConnection
//----------------------------------------------------------------------------
Object_wx_TCPConnection::~Object_wx_TCPConnection()
{
}

Object *Object_wx_TCPConnection::Clone() const
{
	return nullptr;
}

String Object_wx_TCPConnection::ToString(bool exprFlag)
{
	String rtn("<wx.TCPConnection:");
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
// Class implementation for wxTCPConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPConnection)
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
	return new Object_wx_TCPConnection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
