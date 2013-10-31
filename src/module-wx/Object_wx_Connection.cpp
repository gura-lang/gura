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
	Gura::Signal _sig;
	Object_wx_Connection *_pObj;
public:
	inline wx_Connection() : wxConnection(), _sig(NULL), _pObj(NULL) {}
	//inline wx_Connection(char* buffer, int size) : wxConnection(buffer, size), _sig(NULL), _pObj(NULL) {}
	//virtual bool OnAdvise(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual bool OnDisconnect();
	//virtual bool OnExecute(const wxString& topic, char* data, int size, wxIPCFormat format);
	//virtual bool OnPoke(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual char* OnRequest(const wxString& topic, const wxString& item, int * size, wxIPCFormat format);
	//virtual bool OnStartAdvise(const wxString& topic, const wxString& item);
	//virtual bool OnStopAdvise(const wxString& topic, const wxString& item);
	~wx_Connection();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Connection *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Connection::~wx_Connection()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Connection::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxConnection
//----------------------------------------------------------------------------
Gura_DeclareFunction(ConnectionEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Connection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ConnectionEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Connection *pEntity = new wx_Connection();
	Object_wx_Connection *pObj = Object_wx_Connection::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Connection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Connection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_Connection));
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(Connection)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char buffer = args.GetChar(0);
	int size = args.GetInt(1);
	wx_Connection *pEntity = new wx_Connection(buffer, size);
	Object_wx_Connection *pObj = Object_wx_Connection::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Connection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, Advise)
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

Gura_ImplementMethod(wx_Connection, Advise)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = -1;
	if (args.IsValid(2)) size = args.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(3)) format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Advise(item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, Execute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, Execute)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char data = args.GetChar(0);
	int size = -1;
	if (args.IsValid(1)) size = args.GetInt(1);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(2)) format = static_cast<wxIPCFormat>(args.GetInt(2));
	bool rtn = pThis->GetEntity()->Execute(data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, Disconnect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, Disconnect)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Disconnect();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, OnAdvise)
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

Gura_ImplementMethod(wx_Connection, OnAdvise)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	char data = args.GetChar(2);
	int size = args.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(4));
	bool rtn = pThis->GetEntity()->OnAdvise(topic, item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, OnDisconnect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, OnDisconnect)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->OnDisconnect();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, OnExecute)
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

Gura_ImplementMethod(wx_Connection, OnExecute)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = args.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->OnExecute(topic, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, OnPoke)
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

Gura_ImplementMethod(wx_Connection, OnPoke)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	char data = args.GetChar(2);
	int size = args.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(4));
	bool rtn = pThis->GetEntity()->OnPoke(topic, item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, OnRequest)
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

Gura_ImplementMethod(wx_Connection, OnRequest)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	int size = args.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(args.GetInt(3));
	char rtn = pThis->GetEntity()->OnRequest(topic, item, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, OnStartAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, OnStartAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->OnStartAdvise(topic, item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, OnStopAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, OnStopAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->OnStopAdvise(topic, item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, Poke)
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

Gura_ImplementMethod(wx_Connection, Poke)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	char data = args.GetChar(1);
	int size = -1;
	if (args.IsValid(2)) size = args.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (args.IsValid(3)) format = static_cast<wxIPCFormat>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Poke(item, data, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, Request)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, Request)
{
#if 0
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	int size = args.GetInt(1);
	wxIPCFormat format = wxIPC_TEXT;
	if (args.IsValid(2)) format = static_cast<wxIPCFormat>(args.GetInt(2));
	char rtn = pThis->GetEntity()->Request(item, size, format);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Connection, StartAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, StartAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StartAdvise(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Connection, StopAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Connection, StopAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StopAdvise(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxConnection
//----------------------------------------------------------------------------
Object_wx_Connection::~Object_wx_Connection()
{
}

Object *Object_wx_Connection::Clone() const
{
	return NULL;
}

String Object_wx_Connection::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Connection:");
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
	return new Object_wx_Connection((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
