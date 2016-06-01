//----------------------------------------------------------------------------
// wxLog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLog
//----------------------------------------------------------------------------
Object_wx_Log::~Object_wx_Log()
{
}

Object *Object_wx_Log::Clone() const
{
	return nullptr;
}

String Object_wx_Log::ToString(bool exprFlag)
{
	String rtn("<wx.Log:");
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
Gura_DeclareMethod(wx_Log, AddTraceMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, AddTraceMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->AddTraceMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, ClearTraceMasks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, ClearTraceMasks)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearTraceMasks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, GetTraceMasks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, GetTraceMasks)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTraceMasks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, IsAllowedTraceMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, IsAllowedTraceMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->IsAllowedTraceMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, RemoveTraceMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, RemoveTraceMask)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveTraceMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, DontCreateOnDemand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, DontCreateOnDemand)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DontCreateOnDemand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, GetActiveTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, GetActiveTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetActiveTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetActiveTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logtarget", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetActiveTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int logtarget = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetThreadActiveTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logger", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetThreadActiveTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int logger = arg.GetNumber(0)
	//pThis->GetEntity()->SetThreadActiveTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, FlushActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, FlushActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FlushActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, Resume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, Resume)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, Suspend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, Suspend)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Suspend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, GetLogLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, GetLogLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLogLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, IsLevelEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "component", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, IsLevelEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//int component = arg.GetNumber(1)
	//pThis->GetEntity()->IsLevelEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetComponentLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "component", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetComponentLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int component = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//pThis->GetEntity()->SetComponentLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetLogLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "logLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetLogLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int logLevel = arg.GetNumber(0)
	//pThis->GetEntity()->SetLogLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, EnableLogging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, EnableLogging)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableLogging();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, IsEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, GetRepetitionCounting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, GetRepetitionCounting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRepetitionCounting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetRepetitionCounting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "repetCounting", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetRepetitionCounting)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int repetCounting = arg.GetNumber(0)
	//pThis->GetEntity()->SetRepetitionCounting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, GetTimestamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, GetTimestamp)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTimestamp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetTimestamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetTimestamp)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetTimestamp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, DisableTimestamp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, DisableTimestamp)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisableTimestamp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, GetVerbose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, GetVerbose)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVerbose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetVerbose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "verbose", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetVerbose)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int verbose = arg.GetNumber(0)
	//pThis->GetEntity()->SetVerbose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, SetFormatter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "formatter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, SetFormatter)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int formatter = arg.GetNumber(0)
	//pThis->GetEntity()->SetFormatter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, Flush)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, LogRecord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, LogRecord)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//int msg = arg.GetNumber(1)
	//int info = arg.GetNumber(2)
	//pThis->GetEntity()->LogRecord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, DoLogRecord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, DoLogRecord)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//int msg = arg.GetNumber(1)
	//int info = arg.GetNumber(2)
	//pThis->GetEntity()->DoLogRecord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, DoLogTextAtLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, DoLogTextAtLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//int msg = arg.GetNumber(1)
	//pThis->GetEntity()->DoLogTextAtLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Log, DoLogText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Log, DoLogText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Log *pThis = Object_wx_Log::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->DoLogText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Log)
{
	Gura_AssignMethod(wx_Log, AddTraceMask);
	Gura_AssignMethod(wx_Log, ClearTraceMasks);
	Gura_AssignMethod(wx_Log, GetTraceMasks);
	Gura_AssignMethod(wx_Log, IsAllowedTraceMask);
	Gura_AssignMethod(wx_Log, RemoveTraceMask);
	Gura_AssignMethod(wx_Log, DontCreateOnDemand);
	Gura_AssignMethod(wx_Log, GetActiveTarget);
	Gura_AssignMethod(wx_Log, SetActiveTarget);
	Gura_AssignMethod(wx_Log, SetThreadActiveTarget);
	Gura_AssignMethod(wx_Log, FlushActive);
	Gura_AssignMethod(wx_Log, Resume);
	Gura_AssignMethod(wx_Log, Suspend);
	Gura_AssignMethod(wx_Log, GetLogLevel);
	Gura_AssignMethod(wx_Log, IsLevelEnabled);
	Gura_AssignMethod(wx_Log, SetComponentLevel);
	Gura_AssignMethod(wx_Log, SetLogLevel);
	Gura_AssignMethod(wx_Log, EnableLogging);
	Gura_AssignMethod(wx_Log, IsEnabled);
	Gura_AssignMethod(wx_Log, GetRepetitionCounting);
	Gura_AssignMethod(wx_Log, SetRepetitionCounting);
	Gura_AssignMethod(wx_Log, GetTimestamp);
	Gura_AssignMethod(wx_Log, SetTimestamp);
	Gura_AssignMethod(wx_Log, DisableTimestamp);
	Gura_AssignMethod(wx_Log, GetVerbose);
	Gura_AssignMethod(wx_Log, SetVerbose);
	Gura_AssignMethod(wx_Log, SetFormatter);
	Gura_AssignMethod(wx_Log, Flush);
	Gura_AssignMethod(wx_Log, LogRecord);
	Gura_AssignMethod(wx_Log, DoLogRecord);
	Gura_AssignMethod(wx_Log, DoLogTextAtLevel);
	Gura_AssignMethod(wx_Log, DoLogText);
}

Gura_ImplementDescendantCreator(wx_Log)
{
	return new Object_wx_Log((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
