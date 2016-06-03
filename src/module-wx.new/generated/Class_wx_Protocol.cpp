//----------------------------------------------------------------------------
// wxProtocol
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProtocol
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProtocol
//----------------------------------------------------------------------------
Object_wx_Protocol::~Object_wx_Protocol()
{
}

Object *Object_wx_Protocol::Clone() const
{
	return nullptr;
}

String Object_wx_Protocol::ToString(bool exprFlag)
{
	String rtn("<wx.Protocol:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Protocol, __Abort, "Abort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, __Abort)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Abort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __GetContentType, "GetContentType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, __GetContentType)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __GetError, "GetError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, __GetError)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __GetInputStream, "GetInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, __GetInputStream)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __Reconnect, "Reconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, __Reconnect)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __SetPassword, "SetPassword")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "user", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, __SetPassword)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& user = arg.GetNumber(0)
	//pThis->GetEntity()->SetPassword();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __SetUser, "SetUser")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "user", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, __SetUser)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& user = arg.GetNumber(0)
	//pThis->GetEntity()->SetUser();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __SetDefaultTimeout, "SetDefaultTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "Value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, __SetDefaultTimeout)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 Value = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultTimeout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __SetLog, "SetLog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "log", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, __SetLog)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxProtocolLog* log = arg.GetNumber(0)
	//pThis->GetEntity()->SetLog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __GetLog, "GetLog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, __GetLog)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __DetachLog, "DetachLog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, __DetachLog)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachLog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __LogRequest, "LogRequest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, __LogRequest)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->LogRequest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Protocol, __LogResponse, "LogResponse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, __LogResponse)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->LogResponse();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProtocol
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Protocol)
{
	// Class assignment
	Gura_AssignValueEx("Protocol", Reference());
	// Method assignment
	Gura_AssignMethod(wx_Protocol, __Abort);
	Gura_AssignMethod(wx_Protocol, __GetContentType);
	Gura_AssignMethod(wx_Protocol, __GetError);
	Gura_AssignMethod(wx_Protocol, __GetInputStream);
	Gura_AssignMethod(wx_Protocol, __Reconnect);
	Gura_AssignMethod(wx_Protocol, __SetPassword);
	Gura_AssignMethod(wx_Protocol, __SetUser);
	Gura_AssignMethod(wx_Protocol, __SetDefaultTimeout);
	Gura_AssignMethod(wx_Protocol, __SetLog);
	Gura_AssignMethod(wx_Protocol, __GetLog);
	Gura_AssignMethod(wx_Protocol, __DetachLog);
	Gura_AssignMethod(wx_Protocol, __LogRequest);
	Gura_AssignMethod(wx_Protocol, __LogResponse);
}

Gura_ImplementDescendantCreator(wx_Protocol)
{
	return new Object_wx_Protocol((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
