//----------------------------------------------------------------------------
// wxConnection
// extracted from ipcconn.tex
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
class wx_Connection: public wxConnection, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Connection *_pObj;
public:
	inline wx_Connection() : wxConnection(), _pObj(nullptr) {}
	//inline wx_Connection(char* buffer, int size) : wxConnection(buffer, size), _pObj(nullptr) {}
	//virtual bool OnAdvise(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual bool OnDisconnect();
	//virtual bool OnExecute(const wxString& topic, char* data, int size, wxIPCFormat format);
	//virtual bool OnPoke(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual char* OnRequest(const wxString& topic, const wxString& item, int * size, wxIPCFormat format);
	//virtual bool OnStartAdvise(const wxString& topic, const wxString& item);
	//virtual bool OnStopAdvise(const wxString& topic, const wxString& item);
	~wx_Connection();
	inline void AssocWithGura(Object_wx_Connection *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Connection::~wx_Connection()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Connection::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxConnection
//----------------------------------------------------------------------------
Gura_DeclareFunction(ConnectionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Connection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ConnectionEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Connection *pEntity = new wx_Connection();
	Object_wx_Connection *pObj = Object_wx_Connection::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Connection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(Connection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Connection));
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Connection)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char buffer = args.GetChar(0);
	int size = args.GetInt(1);
	wx_Connection *pEntity = new wx_Connection(buffer, size);
	Object_wx_Connection *pObj = Object_wx_Connection::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Connection(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_Connection, Advise)
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

Gura_ImplementMethod(wx_Connection, Advise)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, Execute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, Execute)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, Disconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Disconnect();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, OnAdvise)
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

Gura_ImplementMethod(wx_Connection, OnAdvise)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, OnDisconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, OnDisconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->OnDisconnect();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, OnExecute)
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

Gura_ImplementMethod(wx_Connection, OnExecute)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, OnPoke)
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

Gura_ImplementMethod(wx_Connection, OnPoke)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, OnRequest)
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

Gura_ImplementMethod(wx_Connection, OnRequest)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, OnStartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, OnStartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->OnStartAdvise(topic, item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, OnStopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, OnStopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->OnStopAdvise(topic, item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, Poke)
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

Gura_ImplementMethod(wx_Connection, Poke)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, Request)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, Request)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
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

Gura_DeclareMethod(wx_Connection, StartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, StartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StartAdvise(item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, StopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, StopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StopAdvise(item);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxConnection
//----------------------------------------------------------------------------
Object_wx_Connection::~Object_wx_Connection()
{
}

Object *Object_wx_Connection::Clone() const
{
	return nullptr;
}

String Object_wx_Connection::ToString(bool exprFlag)
{
	String rtn("<wx.Connection:");
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
// Class implementation for wxConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Connection)
{
	Gura_RealizeUserSymbol(OnAdvise);
	Gura_RealizeUserSymbol(OnDisconnect);
	Gura_RealizeUserSymbol(OnExecute);
	Gura_RealizeUserSymbol(OnPoke);
	Gura_RealizeUserSymbol(OnRequest);
	Gura_RealizeUserSymbol(OnStartAdvise);
	Gura_RealizeUserSymbol(OnStopAdvise);
	Gura_AssignFunction(ConnectionEmpty);
	Gura_AssignFunction(Connection);
	Gura_AssignMethod(wx_Connection, Advise);
	Gura_AssignMethod(wx_Connection, Execute);
	Gura_AssignMethod(wx_Connection, Disconnect);
	Gura_AssignMethod(wx_Connection, OnAdvise);
	Gura_AssignMethod(wx_Connection, OnDisconnect);
	Gura_AssignMethod(wx_Connection, OnExecute);
	Gura_AssignMethod(wx_Connection, OnPoke);
	Gura_AssignMethod(wx_Connection, OnRequest);
	Gura_AssignMethod(wx_Connection, OnStartAdvise);
	Gura_AssignMethod(wx_Connection, OnStopAdvise);
	Gura_AssignMethod(wx_Connection, Poke);
	Gura_AssignMethod(wx_Connection, Request);
	Gura_AssignMethod(wx_Connection, StartAdvise);
	Gura_AssignMethod(wx_Connection, StopAdvise);
}

Gura_ImplementDescendantCreator(wx_Connection)
{
	return new Object_wx_Connection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
