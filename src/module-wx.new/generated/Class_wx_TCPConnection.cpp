//----------------------------------------------------------------------------
// wxTCPConnection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPConnection
//----------------------------------------------------------------------------

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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TCPConnection, "TCPConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TCPConnection)
{
	//wxTCPConnection();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TCPConnection_1, "TCPConnection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TCPConnection_1)
{
	//void* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//wxTCPConnection(buffer, size);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TCPConnection, __Advise, "Advise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const void* data = arg.GetNumber(1)
	//size_t size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->Advise(item, data, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Advise_1, "Advise_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const char* data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Advise(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Advise_2, "Advise_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wchar_t* data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Advise(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Advise_3, "Advise_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxString data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Advise(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Disconnect, "Disconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TCPConnection, __Disconnect)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute, "Execute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const void* data = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//wxIPCFormat format = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->Execute(data, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute_1, "Execute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* data = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Execute(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute_2, "Execute_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* data = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Execute(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute_3, "Execute_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString data = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Execute(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnAdvise, "OnAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const void* data = arg.GetNumber(2)
	//size_t size = arg.GetNumber(3)
	//wxIPCFormat format = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->OnAdvise(topic, item, data, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnDisconnect, "OnDisconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TCPConnection, __OnDisconnect)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->OnDisconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnExecute, "OnExecute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnExecute)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const void* data = arg.GetNumber(1)
	//size_t size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->OnExecute(topic, data, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnPoke, "OnPoke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnPoke)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const void* data = arg.GetNumber(2)
	//size_t size = arg.GetNumber(3)
	//wxIPCFormat format = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->OnPoke(topic, item, data, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnRequest, "OnRequest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnRequest)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//size_t* size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//const void* _rtn = pThis->GetEntity()->OnRequest(topic, item, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnStartAdvise, "OnStartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnStartAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->OnStartAdvise(topic, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnStopAdvise, "OnStopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnStopAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->OnStopAdvise(topic, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke, "Poke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const void* data = arg.GetNumber(1)
	//size_t size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->Poke(item, data, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke_1, "Poke_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const char* data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Poke(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke_2, "Poke_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wchar_t* data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Poke(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke_3, "Poke_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxString data = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Poke(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Request, "Request")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Request)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//size_t* size = arg.GetNumber(1)
	//wxIPCFormat format = arg.GetNumber(2)
	//const void* _rtn = pThis->GetEntity()->Request(item, size, format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __StartAdvise, "StartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __StartAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->StartAdvise(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __StopAdvise, "StopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __StopAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->StopAdvise(item);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPConnection)
{
	// Constructor assignment
	Gura_AssignFunction(__TCPConnection);
	Gura_AssignFunction(__TCPConnection_1);
	// Method assignment
	Gura_AssignMethod(wx_TCPConnection, __Advise);
	Gura_AssignMethod(wx_TCPConnection, __Advise_1);
	Gura_AssignMethod(wx_TCPConnection, __Advise_2);
	Gura_AssignMethod(wx_TCPConnection, __Advise_3);
	Gura_AssignMethod(wx_TCPConnection, __Disconnect);
	Gura_AssignMethod(wx_TCPConnection, __Execute);
	Gura_AssignMethod(wx_TCPConnection, __Execute_1);
	Gura_AssignMethod(wx_TCPConnection, __Execute_2);
	Gura_AssignMethod(wx_TCPConnection, __Execute_3);
	Gura_AssignMethod(wx_TCPConnection, __OnAdvise);
	Gura_AssignMethod(wx_TCPConnection, __OnDisconnect);
	Gura_AssignMethod(wx_TCPConnection, __OnExecute);
	Gura_AssignMethod(wx_TCPConnection, __OnPoke);
	Gura_AssignMethod(wx_TCPConnection, __OnRequest);
	Gura_AssignMethod(wx_TCPConnection, __OnStartAdvise);
	Gura_AssignMethod(wx_TCPConnection, __OnStopAdvise);
	Gura_AssignMethod(wx_TCPConnection, __Poke);
	Gura_AssignMethod(wx_TCPConnection, __Poke_1);
	Gura_AssignMethod(wx_TCPConnection, __Poke_2);
	Gura_AssignMethod(wx_TCPConnection, __Poke_3);
	Gura_AssignMethod(wx_TCPConnection, __Request);
	Gura_AssignMethod(wx_TCPConnection, __StartAdvise);
	Gura_AssignMethod(wx_TCPConnection, __StopAdvise);
}

Gura_ImplementDescendantCreator(wx_TCPConnection)
{
	return new Object_wx_TCPConnection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
