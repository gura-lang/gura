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
Gura_DeclareMethod(wx_Protocol, Abort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, Abort)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Abort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, GetContentType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, GetContentType)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, GetError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, GetError)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, GetInputStream)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, Reconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, Reconnect)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, SetPassword)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "user", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, SetPassword)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int user = arg.GetNumber(0)
	//pThis->GetEntity()->SetPassword();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, SetUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "user", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, SetUser)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int user = arg.GetNumber(0)
	//pThis->GetEntity()->SetUser();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, SetDefaultTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "Value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, SetDefaultTimeout)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int Value = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, SetLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "log", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, SetLog)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int log = arg.GetNumber(0)
	//pThis->GetEntity()->SetLog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, GetLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, GetLog)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, DetachLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Protocol, DetachLog)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachLog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, LogRequest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, LogRequest)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->LogRequest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Protocol, LogResponse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, LogResponse)
{
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->LogResponse();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProtocol
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Protocol)
{
	Gura_AssignMethod(wx_Protocol, Abort);
	Gura_AssignMethod(wx_Protocol, GetContentType);
	Gura_AssignMethod(wx_Protocol, GetError);
	Gura_AssignMethod(wx_Protocol, GetInputStream);
	Gura_AssignMethod(wx_Protocol, Reconnect);
	Gura_AssignMethod(wx_Protocol, SetPassword);
	Gura_AssignMethod(wx_Protocol, SetUser);
	Gura_AssignMethod(wx_Protocol, SetDefaultTimeout);
	Gura_AssignMethod(wx_Protocol, SetLog);
	Gura_AssignMethod(wx_Protocol, GetLog);
	Gura_AssignMethod(wx_Protocol, DetachLog);
	Gura_AssignMethod(wx_Protocol, LogRequest);
	Gura_AssignMethod(wx_Protocol, LogResponse);
}

Gura_ImplementDescendantCreator(wx_Protocol)
{
	return new Object_wx_Protocol((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
