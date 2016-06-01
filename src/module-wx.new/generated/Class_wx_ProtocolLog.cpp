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
Gura_DeclareMethod(wx_ProtocolLog, wxProtocolLog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "traceMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, wxProtocolLog)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int traceMask = arg.GetNumber(0)
	//pThis->GetEntity()->wxProtocolLog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ProtocolLog, LogRequest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, LogRequest)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->LogRequest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ProtocolLog, LogResponse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, LogResponse)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->LogResponse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ProtocolLog, DoLogString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ProtocolLog, DoLogString)
{
	Signal &sig = env.GetSignal();
	Object_wx_ProtocolLog *pThis = Object_wx_ProtocolLog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->DoLogString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxProtocolLog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProtocolLog)
{
	Gura_AssignMethod(wx_ProtocolLog, wxProtocolLog);
	Gura_AssignMethod(wx_ProtocolLog, LogRequest);
	Gura_AssignMethod(wx_ProtocolLog, LogResponse);
	Gura_AssignMethod(wx_ProtocolLog, DoLogString);
}

Gura_ImplementDescendantCreator(wx_ProtocolLog)
{
	return new Object_wx_ProtocolLog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
