//----------------------------------------------------------------------------
// wxDDEConnection
// extracted from ddeconn.tex
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
class wx_DDEConnection: public wxDDEConnection, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DDEConnection *_pObj;
public:
	inline wx_DDEConnection() : wxDDEConnection(), _pObj(nullptr) {}
	//inline wx_DDEConnection(char* buffer, int size) : wxDDEConnection(buffer, size), _pObj(nullptr) {}
	//virtual bool OnAdvise(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual bool OnDisconnect();
	//virtual bool OnExecute(const wxString& topic, char* data, int size, wxIPCFormat format);
	//virtual bool OnPoke(const wxString& topic, const wxString& item, char* data, int size, wxIPCFormat format);
	//virtual char* OnRequest(const wxString& topic, const wxString& item, int * size, wxIPCFormat format);
	//virtual bool OnStartAdvise(const wxString& topic, const wxString& item);
	//virtual bool OnStopAdvise(const wxString& topic, const wxString& item);
	~wx_DDEConnection();
	inline void AssocWithGura(Object_wx_DDEConnection *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DDEConnection::~wx_DDEConnection()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DDEConnection::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEConnection
//----------------------------------------------------------------------------
Gura_DeclareFunction(DDEConnectionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DDEConnectionEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_DDEConnection *pEntity = new wx_DDEConnection();
	Object_wx_DDEConnection *pObj = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DDEConnection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(DDEConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DDEConnection));
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DDEConnection)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char buffer = arg.GetChar(0);
	int size = arg.GetInt(1);
	wx_DDEConnection *pEntity = new wx_DDEConnection(buffer, size);
	Object_wx_DDEConnection *pObj = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DDEConnection(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Advise)
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

Gura_ImplementMethod(wx_DDEConnection, Advise)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(arg.GetString(0));
	char data = arg.GetChar(1);
	int size = -1;
	if (arg.IsValid(2)) size = arg.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (arg.IsValid(3)) format = static_cast<wxIPCFormat>(arg.GetInt(3));
	bool rtn = pThis->GetEntity()->Advise(item, data, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Execute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, Execute)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char data = arg.GetChar(0);
	int size = -1;
	if (arg.IsValid(1)) size = arg.GetInt(1);
	wxIPCFormat format = wxCF_TEXT;
	if (arg.IsValid(2)) format = static_cast<wxIPCFormat>(arg.GetInt(2));
	bool rtn = pThis->GetEntity()->Execute(data, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, Disconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Disconnect();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, OnAdvise)
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

Gura_ImplementMethod(wx_DDEConnection, OnAdvise)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(arg.GetString(0));
	wxString item = wxString::FromUTF8(arg.GetString(1));
	char data = arg.GetChar(2);
	int size = arg.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(arg.GetInt(4));
	bool rtn = pThis->GetEntity()->OnAdvise(topic, item, data, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnDisconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, OnDisconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->OnDisconnect();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, OnExecute)
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

Gura_ImplementMethod(wx_DDEConnection, OnExecute)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(arg.GetString(0));
	char data = arg.GetChar(1);
	int size = arg.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(arg.GetInt(3));
	bool rtn = pThis->GetEntity()->OnExecute(topic, data, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnPoke)
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

Gura_ImplementMethod(wx_DDEConnection, OnPoke)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(arg.GetString(0));
	wxString item = wxString::FromUTF8(arg.GetString(1));
	char data = arg.GetChar(2);
	int size = arg.GetInt(3);
	wxIPCFormat format = static_cast<wxIPCFormat>(arg.GetInt(4));
	bool rtn = pThis->GetEntity()->OnPoke(topic, item, data, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnRequest)
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

Gura_ImplementMethod(wx_DDEConnection, OnRequest)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(arg.GetString(0));
	wxString item = wxString::FromUTF8(arg.GetString(1));
	int size = arg.GetInt(2);
	wxIPCFormat format = static_cast<wxIPCFormat>(arg.GetInt(3));
	char rtn = pThis->GetEntity()->OnRequest(topic, item, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnStartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, OnStartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(arg.GetString(0));
	wxString item = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->OnStartAdvise(topic, item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, OnStopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, OnStopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString topic = wxString::FromUTF8(arg.GetString(0));
	wxString item = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->OnStopAdvise(topic, item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, Poke)
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

Gura_ImplementMethod(wx_DDEConnection, Poke)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(arg.GetString(0));
	char data = arg.GetChar(1);
	int size = -1;
	if (arg.IsValid(2)) size = arg.GetInt(2);
	wxIPCFormat format = wxCF_TEXT;
	if (arg.IsValid(3)) format = static_cast<wxIPCFormat>(arg.GetInt(3));
	bool rtn = pThis->GetEntity()->Poke(item, data, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Request)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, Request)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(arg.GetString(0));
	int size = arg.GetInt(1);
	wxIPCFormat format = wxIPC_TEXT;
	if (arg.IsValid(2)) format = static_cast<wxIPCFormat>(arg.GetInt(2));
	char rtn = pThis->GetEntity()->Request(item, size, format);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, StartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, StartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->StartAdvise(item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DDEConnection, StopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEConnection, StopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString item = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->StopAdvise(item);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDDEConnection
//----------------------------------------------------------------------------
Object_wx_DDEConnection::~Object_wx_DDEConnection()
{
}

Object *Object_wx_DDEConnection::Clone() const
{
	return nullptr;
}

String Object_wx_DDEConnection::ToString(bool exprFlag)
{
	String rtn("<wx.DDEConnection:");
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
// Class implementation for wxDDEConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEConnection)
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
	return new Object_wx_DDEConnection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
