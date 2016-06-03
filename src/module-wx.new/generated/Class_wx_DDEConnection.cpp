//----------------------------------------------------------------------------
// wxDDEConnection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEConnection
//----------------------------------------------------------------------------

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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DDEConnection, "DDEConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DDEConnection)
{
	//wxDDEConnection();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DDEConnection_1, "DDEConnection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DDEConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DDEConnection_1)
{
	//void* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//wxDDEConnection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DDEConnection, __Advise, "Advise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Advise)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const void* data = arg.GetNumber(1)
	//size_t size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Advise_1, "Advise_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Advise_1)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const char* data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Advise_2, "Advise_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Advise_2)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wchar_t* data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Advise_3, "Advise_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Advise_3)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxString data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Disconnect, "Disconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEConnection, __Disconnect)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Execute, "Execute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Execute)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const void* data = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//wxIPCFormat format = arg.GetNumber(2)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Execute_1, "Execute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Execute_1)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Execute_2, "Execute_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Execute_2)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Execute_3, "Execute_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Execute_3)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __OnAdvise, "OnAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __OnAdvise)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const void* data = arg.GetNumber(2)
	//size_t size = arg.GetNumber(3)
	//wxIPCFormat format = arg.GetNumber(4)
	//pThis->GetEntity()->OnAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __OnDisconnect, "OnDisconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEConnection, __OnDisconnect)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnDisconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __OnExecute, "OnExecute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __OnExecute)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const void* data = arg.GetNumber(1)
	//size_t size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//pThis->GetEntity()->OnExecute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __OnPoke, "OnPoke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __OnPoke)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//const void* data = arg.GetNumber(2)
	//size_t size = arg.GetNumber(3)
	//wxIPCFormat format = arg.GetNumber(4)
	//pThis->GetEntity()->OnPoke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __OnRequest, "OnRequest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __OnRequest)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//size_t* size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//pThis->GetEntity()->OnRequest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __OnStartAdvise, "OnStartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __OnStartAdvise)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStartAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __OnStopAdvise, "OnStopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __OnStopAdvise)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//const wxString& item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStopAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Poke, "Poke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Poke)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const void* data = arg.GetNumber(1)
	//size_t size = arg.GetNumber(2)
	//wxIPCFormat format = arg.GetNumber(3)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Poke_1, "Poke_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Poke_1)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const char* data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Poke_2, "Poke_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Poke_2)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wchar_t* data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Poke_3, "Poke_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Poke_3)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//const wxString data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __Request, "Request")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __Request)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//size_t* size = arg.GetNumber(1)
	//wxIPCFormat format = arg.GetNumber(2)
	//pThis->GetEntity()->Request();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __StartAdvise, "StartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __StartAdvise)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//pThis->GetEntity()->StartAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEConnection, __StopAdvise, "StopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, __StopAdvise)
{
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//pThis->GetEntity()->StopAdvise();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDDEConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEConnection)
{
	// Constructor assignment
	Gura_AssignFunction(__DDEConnection);
	Gura_AssignFunction(__DDEConnection_1);
	// Method assignment
	Gura_AssignMethod(wx_DDEConnection, __Advise);
	Gura_AssignMethod(wx_DDEConnection, __Advise_1);
	Gura_AssignMethod(wx_DDEConnection, __Advise_2);
	Gura_AssignMethod(wx_DDEConnection, __Advise_3);
	Gura_AssignMethod(wx_DDEConnection, __Disconnect);
	Gura_AssignMethod(wx_DDEConnection, __Execute);
	Gura_AssignMethod(wx_DDEConnection, __Execute_1);
	Gura_AssignMethod(wx_DDEConnection, __Execute_2);
	Gura_AssignMethod(wx_DDEConnection, __Execute_3);
	Gura_AssignMethod(wx_DDEConnection, __OnAdvise);
	Gura_AssignMethod(wx_DDEConnection, __OnDisconnect);
	Gura_AssignMethod(wx_DDEConnection, __OnExecute);
	Gura_AssignMethod(wx_DDEConnection, __OnPoke);
	Gura_AssignMethod(wx_DDEConnection, __OnRequest);
	Gura_AssignMethod(wx_DDEConnection, __OnStartAdvise);
	Gura_AssignMethod(wx_DDEConnection, __OnStopAdvise);
	Gura_AssignMethod(wx_DDEConnection, __Poke);
	Gura_AssignMethod(wx_DDEConnection, __Poke_1);
	Gura_AssignMethod(wx_DDEConnection, __Poke_2);
	Gura_AssignMethod(wx_DDEConnection, __Poke_3);
	Gura_AssignMethod(wx_DDEConnection, __Request);
	Gura_AssignMethod(wx_DDEConnection, __StartAdvise);
	Gura_AssignMethod(wx_DDEConnection, __StopAdvise);
}

Gura_ImplementDescendantCreator(wx_DDEConnection)
{
	return new Object_wx_DDEConnection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
