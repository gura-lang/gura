//----------------------------------------------------------------------------
// wxDDEConnection
// extracted from ddeconn.tex
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
class wx_DDEConnection: public wxDDEConnection, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DDEConnection *_pObj;
public:
	inline wx_DDEConnection() : wxDDEConnection(), _sig(NULL), _pObj(NULL) {}
	//inline wx_DDEConnection(char* buffer, int size) : wxDDEConnection(buffer, size), _sig(NULL), _pObj(NULL) {}
	//virtual bool OnAdvise(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual bool OnDisconnect();
	//virtual bool OnExecute(const wxString& topic, char* data, int size, wxIPCFormat format);
	//virtual bool OnPoke(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual char* OnRequest(const wxString& topic, const wxString& item, int * size, wxIPCFormat format);
	//virtual bool OnStartAdvise(const wxString& topic, const wxString& item);
	//virtual bool OnStopAdvise(const wxString& topic, const wxString& item);
	~wx_DDEConnection();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DDEConnection *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DDEConnection::~wx_DDEConnection()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DDEConnection::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEConnection
//----------------------------------------------------------------------------
Gura_DeclareFunction(DDEConnectionEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DDEConnectionEmpty)
{
	wx_DDEConnection *pEntity = new wx_DDEConnection();
	Object_wx_DDEConnection *pObj = Object_wx_DDEConnection::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DDEConnection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(DDEConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DDEConnection));
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DDEConnection)
{
#if 0
	char buffer = args.GetChar(0);
	int size = args.GetInt(1);
	wx_DDEConnection *pEntity = new wx_DDEConnection(buffer, size);
	Object_wx_DDEConnection *pObj = Object_wx_DDEConnection::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DDEConnection(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_DDEConnection, Advise)
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

Gura_ImplementMethod(wx_DDEConnection, Advise)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, Execute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, Execute)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, Disconnect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, Disconnect)
{
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Disconnect();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, OnAdvise)
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

Gura_ImplementMethod(wx_DDEConnection, OnAdvise)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, OnDisconnect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, OnDisconnect)
{
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->OnDisconnect();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, OnExecute)
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

Gura_ImplementMethod(wx_DDEConnection, OnExecute)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, OnPoke)
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

Gura_ImplementMethod(wx_DDEConnection, OnPoke)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, OnRequest)
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

Gura_ImplementMethod(wx_DDEConnection, OnRequest)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, OnStartAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, OnStartAdvise)
{
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->OnStartAdvise(topic, item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, OnStopAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, OnStopAdvise)
{
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxString item = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->OnStopAdvise(topic, item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, Poke)
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

Gura_ImplementMethod(wx_DDEConnection, Poke)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, Request)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, Request)
{
#if 0
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
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

Gura_DeclareMethod(wx_DDEConnection, StartAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, StartAdvise)
{
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->StartAdvise(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, StopAdvise)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, StopAdvise)
{
	Object_wx_DDEConnection *pSelf = Object_wx_DDEConnection::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString item = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->StopAdvise(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDDEConnection
//----------------------------------------------------------------------------
Object_wx_DDEConnection::~Object_wx_DDEConnection()
{
}

Object *Object_wx_DDEConnection::Clone() const
{
	return NULL;
}

String Object_wx_DDEConnection::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DDEConnection:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DDEConnection::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnAdvise);
	Gura_RealizeUserSymbol(OnDisconnect);
	Gura_RealizeUserSymbol(OnExecute);
	Gura_RealizeUserSymbol(OnPoke);
	Gura_RealizeUserSymbol(OnRequest);
	Gura_RealizeUserSymbol(OnStartAdvise);
	Gura_RealizeUserSymbol(OnStopAdvise);
	Gura_AssignFunction(DDEConnectionEmpty);
	Gura_AssignFunction(DDEConnection);
}

//----------------------------------------------------------------------------
// Class implementation for wxDDEConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEConnection)
{
	Gura_AssignMethod(wx_DDEConnection, Advise);
	Gura_AssignMethod(wx_DDEConnection, Execute);
	Gura_AssignMethod(wx_DDEConnection, Disconnect);
	Gura_AssignMethod(wx_DDEConnection, OnAdvise);
	Gura_AssignMethod(wx_DDEConnection, OnDisconnect);
	Gura_AssignMethod(wx_DDEConnection, OnExecute);
	Gura_AssignMethod(wx_DDEConnection, OnPoke);
	Gura_AssignMethod(wx_DDEConnection, OnRequest);
	Gura_AssignMethod(wx_DDEConnection, OnStartAdvise);
	Gura_AssignMethod(wx_DDEConnection, OnStopAdvise);
	Gura_AssignMethod(wx_DDEConnection, Poke);
	Gura_AssignMethod(wx_DDEConnection, Request);
	Gura_AssignMethod(wx_DDEConnection, StartAdvise);
	Gura_AssignMethod(wx_DDEConnection, StopAdvise);
}

Gura_ImplementDescendantCreator(wx_DDEConnection)
{
	return new Object_wx_DDEConnection((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
