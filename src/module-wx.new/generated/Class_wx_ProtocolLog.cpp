//----------------------------------------------------------------------------
// wxProtocolLog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProtocolLog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProtocolLog
//----------------------------------------------------------------------------
Object_wx_ProtocolLog::~Object_wx_ProtocolLog()
{
}

Object *Object_wx_ProtocolLog::Clone() const
{
	return nullptr;
}

String Object_wx_ProtocolLog::ToString(bool exprFlag)
{
	String rtn("<wx.ProtocolLog:");
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
Gura_DeclareMethodAlias(wx_ProtocolLog, __wxProtocolLog, "wxProtocolLog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "traceMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, __wxProtocolLog)
{
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int traceMask = arg.GetNumber(0)
	//pThis->GetEntity()->wxProtocolLog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ProtocolLog, __LogRequest, "LogRequest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, __LogRequest)
{
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->LogRequest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ProtocolLog, __LogResponse, "LogResponse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, __LogResponse)
{
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->LogResponse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ProtocolLog, __DoLogString, "DoLogString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, __DoLogString)
{
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->DoLogString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProtocolLog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProtocolLog)
{
	Gura_AssignMethod(wx_ProtocolLog, __wxProtocolLog);
	Gura_AssignMethod(wx_ProtocolLog, __LogRequest);
	Gura_AssignMethod(wx_ProtocolLog, __LogResponse);
	Gura_AssignMethod(wx_ProtocolLog, __DoLogString);
}

Gura_ImplementDescendantCreator(wx_ProtocolLog)
{
	return new Object_wx_ProtocolLog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
