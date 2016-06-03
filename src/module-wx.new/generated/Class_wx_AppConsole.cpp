//----------------------------------------------------------------------------
// wxAppConsole
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAppConsole
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAppConsole
//----------------------------------------------------------------------------
Object_wx_AppConsole::~Object_wx_AppConsole()
{
}

Object *Object_wx_AppConsole::Clone() const
{
	return nullptr;
}

String Object_wx_AppConsole::ToString(bool exprFlag)
{
	String rtn("<wx.AppConsole:");
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
Gura_DeclareMethodAlias(wx_AppConsole, __CreateTraits, "CreateTraits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __CreateTraits)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateTraits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __MainLoop, "MainLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __MainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MainLoop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __ExitMainLoop, "ExitMainLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __ExitMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ExitMainLoop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __FilterEvent, "FilterEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __FilterEvent)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->FilterEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetMainLoop, "GetMainLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainLoop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __HandleEvent, "HandleEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __HandleEvent)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//int func = arg.GetNumber(1)
	//int event = arg.GetNumber(2)
	//pThis->GetEntity()->HandleEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __UsesEventLoop, "UsesEventLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __UsesEventLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UsesEventLoop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __ProcessPendingEvents, "ProcessPendingEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __ProcessPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ProcessPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __DeletePendingEvents, "DeletePendingEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __DeletePendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeletePendingEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __HasPendingEvents, "HasPendingEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __HasPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SuspendProcessingOfPendingEvents, "SuspendProcessingOfPendingEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __SuspendProcessingOfPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SuspendProcessingOfPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __ResumeProcessingOfPendingEvents, "ResumeProcessingOfPendingEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __ResumeProcessingOfPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResumeProcessingOfPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __ScheduleForDestruction, "ScheduleForDestruction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __ScheduleForDestruction)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->ScheduleForDestruction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __IsScheduledForDestruction, "IsScheduledForDestruction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __IsScheduledForDestruction)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->IsScheduledForDestruction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __Yield, "Yield")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onlyIfNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __Yield)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int onlyIfNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->Yield();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SetInstance, "SetInstance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "app", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __SetInstance)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int app = arg.GetNumber(0)
	//pThis->GetEntity()->SetInstance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetInstance, "GetInstance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetInstance)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInstance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __IsMainLoopRunning, "IsMainLoopRunning")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __IsMainLoopRunning)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMainLoopRunning();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnAssertFailure, "OnAssertFailure")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cond", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnAssertFailure)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int line = arg.GetNumber(1)
	//int func = arg.GetNumber(2)
	//int cond = arg.GetNumber(3)
	//int msg = arg.GetNumber(4)
	//pThis->GetEntity()->OnAssertFailure();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnCmdLineError, "OnCmdLineError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnCmdLineError)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnCmdLineError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnCmdLineHelp, "OnCmdLineHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnCmdLineHelp)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnCmdLineHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnCmdLineParsed, "OnCmdLineParsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnCmdLineParsed)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnCmdLineParsed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnEventLoopEnter, "OnEventLoopEnter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnEventLoopEnter)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int loop = arg.GetNumber(0)
	//pThis->GetEntity()->OnEventLoopEnter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnEventLoopExit, "OnEventLoopExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnEventLoopExit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int loop = arg.GetNumber(0)
	//pThis->GetEntity()->OnEventLoopExit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnExit, "OnExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnExit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnFatalException, "OnFatalException")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnFatalException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnFatalException();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnInit, "OnInit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnInit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnInit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnInitCmdLine, "OnInitCmdLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnInitCmdLine)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnInitCmdLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnRun, "OnRun")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnRun)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnRun();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnExceptionInMainLoop, "OnExceptionInMainLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnExceptionInMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExceptionInMainLoop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnUnhandledException, "OnUnhandledException")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnUnhandledException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnUnhandledException();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __StoreCurrentException, "StoreCurrentException")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __StoreCurrentException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StoreCurrentException();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __RethrowStoredException, "RethrowStoredException")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __RethrowStoredException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RethrowStoredException();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetAppDisplayName, "GetAppDisplayName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetAppDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAppDisplayName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetAppName, "GetAppName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetAppName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAppName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetClassName, "GetClassName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetClassName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClassName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetTraits, "GetTraits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetTraits)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTraits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetVendorDisplayName, "GetVendorDisplayName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetVendorDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVendorDisplayName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetVendorName, "GetVendorName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetVendorName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVendorName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SetAppDisplayName, "SetAppDisplayName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __SetAppDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetAppDisplayName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SetAppName, "SetAppName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __SetAppName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetAppName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SetClassName, "SetClassName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __SetClassName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetClassName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SetVendorDisplayName, "SetVendorDisplayName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __SetVendorDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetVendorDisplayName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SetVendorName, "SetVendorName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __SetVendorName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetVendorName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __SetCLocale, "SetCLocale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __SetCLocale)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetCLocale();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAppConsole
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppConsole)
{
	// Class assignment
	Gura_AssignValueEx("AppConsole", Reference());
	// Method assignment
	Gura_AssignMethod(wx_AppConsole, __CreateTraits);
	Gura_AssignMethod(wx_AppConsole, __MainLoop);
	Gura_AssignMethod(wx_AppConsole, __ExitMainLoop);
	Gura_AssignMethod(wx_AppConsole, __FilterEvent);
	Gura_AssignMethod(wx_AppConsole, __GetMainLoop);
	Gura_AssignMethod(wx_AppConsole, __HandleEvent);
	Gura_AssignMethod(wx_AppConsole, __UsesEventLoop);
	Gura_AssignMethod(wx_AppConsole, __ProcessPendingEvents);
	Gura_AssignMethod(wx_AppConsole, __DeletePendingEvents);
	Gura_AssignMethod(wx_AppConsole, __HasPendingEvents);
	Gura_AssignMethod(wx_AppConsole, __SuspendProcessingOfPendingEvents);
	Gura_AssignMethod(wx_AppConsole, __ResumeProcessingOfPendingEvents);
	Gura_AssignMethod(wx_AppConsole, __ScheduleForDestruction);
	Gura_AssignMethod(wx_AppConsole, __IsScheduledForDestruction);
	Gura_AssignMethod(wx_AppConsole, __Yield);
	Gura_AssignMethod(wx_AppConsole, __SetInstance);
	Gura_AssignMethod(wx_AppConsole, __GetInstance);
	Gura_AssignMethod(wx_AppConsole, __IsMainLoopRunning);
	Gura_AssignMethod(wx_AppConsole, __OnAssertFailure);
	Gura_AssignMethod(wx_AppConsole, __OnCmdLineError);
	Gura_AssignMethod(wx_AppConsole, __OnCmdLineHelp);
	Gura_AssignMethod(wx_AppConsole, __OnCmdLineParsed);
	Gura_AssignMethod(wx_AppConsole, __OnEventLoopEnter);
	Gura_AssignMethod(wx_AppConsole, __OnEventLoopExit);
	Gura_AssignMethod(wx_AppConsole, __OnExit);
	Gura_AssignMethod(wx_AppConsole, __OnFatalException);
	Gura_AssignMethod(wx_AppConsole, __OnInit);
	Gura_AssignMethod(wx_AppConsole, __OnInitCmdLine);
	Gura_AssignMethod(wx_AppConsole, __OnRun);
	Gura_AssignMethod(wx_AppConsole, __OnExceptionInMainLoop);
	Gura_AssignMethod(wx_AppConsole, __OnUnhandledException);
	Gura_AssignMethod(wx_AppConsole, __StoreCurrentException);
	Gura_AssignMethod(wx_AppConsole, __RethrowStoredException);
	Gura_AssignMethod(wx_AppConsole, __GetAppDisplayName);
	Gura_AssignMethod(wx_AppConsole, __GetAppName);
	Gura_AssignMethod(wx_AppConsole, __GetClassName);
	Gura_AssignMethod(wx_AppConsole, __GetTraits);
	Gura_AssignMethod(wx_AppConsole, __GetVendorDisplayName);
	Gura_AssignMethod(wx_AppConsole, __GetVendorName);
	Gura_AssignMethod(wx_AppConsole, __SetAppDisplayName);
	Gura_AssignMethod(wx_AppConsole, __SetAppName);
	Gura_AssignMethod(wx_AppConsole, __SetClassName);
	Gura_AssignMethod(wx_AppConsole, __SetVendorDisplayName);
	Gura_AssignMethod(wx_AppConsole, __SetVendorName);
	Gura_AssignMethod(wx_AppConsole, __SetCLocale);
}

Gura_ImplementDescendantCreator(wx_AppConsole)
{
	return new Object_wx_AppConsole((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
