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
Gura_DeclareMethod(wx_AppConsole, CreateTraits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, CreateTraits)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateTraits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, MainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, MainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MainLoop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, ExitMainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, ExitMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ExitMainLoop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, FilterEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, FilterEvent)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->FilterEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetMainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainLoop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, HandleEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, HandleEvent)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//int func = arg.GetNumber(1)
	//int event = arg.GetNumber(2)
	//pThis->GetEntity()->HandleEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, UsesEventLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, UsesEventLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UsesEventLoop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, ProcessPendingEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, ProcessPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ProcessPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, DeletePendingEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, DeletePendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeletePendingEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, HasPendingEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, HasPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SuspendProcessingOfPendingEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, SuspendProcessingOfPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SuspendProcessingOfPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, ResumeProcessingOfPendingEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, ResumeProcessingOfPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResumeProcessingOfPendingEvents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, ScheduleForDestruction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, ScheduleForDestruction)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->ScheduleForDestruction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, IsScheduledForDestruction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, IsScheduledForDestruction)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int object = arg.GetNumber(0)
	//pThis->GetEntity()->IsScheduledForDestruction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, Yield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onlyIfNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, Yield)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int onlyIfNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->Yield();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SetInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "app", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, SetInstance)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int app = arg.GetNumber(0)
	//pThis->GetEntity()->SetInstance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetInstance)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInstance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, IsMainLoopRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, IsMainLoopRunning)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMainLoopRunning();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnAssertFailure)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cond", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, OnAssertFailure)
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

Gura_DeclareMethod(wx_AppConsole, OnCmdLineError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, OnCmdLineError)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnCmdLineError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnCmdLineHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, OnCmdLineHelp)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnCmdLineHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnCmdLineParsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, OnCmdLineParsed)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnCmdLineParsed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnEventLoopEnter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, OnEventLoopEnter)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int loop = arg.GetNumber(0)
	//pThis->GetEntity()->OnEventLoopEnter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnEventLoopExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, OnEventLoopExit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int loop = arg.GetNumber(0)
	//pThis->GetEntity()->OnEventLoopExit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, OnExit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnFatalException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, OnFatalException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnFatalException();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, OnInit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnInit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnInitCmdLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, OnInitCmdLine)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnInitCmdLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnRun)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, OnRun)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnRun();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnExceptionInMainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, OnExceptionInMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExceptionInMainLoop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, OnUnhandledException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, OnUnhandledException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnUnhandledException();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, StoreCurrentException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, StoreCurrentException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StoreCurrentException();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, RethrowStoredException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, RethrowStoredException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RethrowStoredException();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetAppDisplayName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetAppDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAppDisplayName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetAppName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetAppName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAppName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetClassName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetClassName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClassName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetTraits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetTraits)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTraits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetVendorDisplayName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetVendorDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVendorDisplayName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, GetVendorName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, GetVendorName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVendorName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SetAppDisplayName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, SetAppDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetAppDisplayName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SetAppName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, SetAppName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetAppName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SetClassName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, SetClassName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetClassName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SetVendorDisplayName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, SetVendorDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetVendorDisplayName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SetVendorName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, SetVendorName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetVendorName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppConsole, SetCLocale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, SetCLocale)
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
	Gura_AssignMethod(wx_AppConsole, CreateTraits);
	Gura_AssignMethod(wx_AppConsole, MainLoop);
	Gura_AssignMethod(wx_AppConsole, ExitMainLoop);
	Gura_AssignMethod(wx_AppConsole, FilterEvent);
	Gura_AssignMethod(wx_AppConsole, GetMainLoop);
	Gura_AssignMethod(wx_AppConsole, HandleEvent);
	Gura_AssignMethod(wx_AppConsole, UsesEventLoop);
	Gura_AssignMethod(wx_AppConsole, ProcessPendingEvents);
	Gura_AssignMethod(wx_AppConsole, DeletePendingEvents);
	Gura_AssignMethod(wx_AppConsole, HasPendingEvents);
	Gura_AssignMethod(wx_AppConsole, SuspendProcessingOfPendingEvents);
	Gura_AssignMethod(wx_AppConsole, ResumeProcessingOfPendingEvents);
	Gura_AssignMethod(wx_AppConsole, ScheduleForDestruction);
	Gura_AssignMethod(wx_AppConsole, IsScheduledForDestruction);
	Gura_AssignMethod(wx_AppConsole, Yield);
	Gura_AssignMethod(wx_AppConsole, SetInstance);
	Gura_AssignMethod(wx_AppConsole, GetInstance);
	Gura_AssignMethod(wx_AppConsole, IsMainLoopRunning);
	Gura_AssignMethod(wx_AppConsole, OnAssertFailure);
	Gura_AssignMethod(wx_AppConsole, OnCmdLineError);
	Gura_AssignMethod(wx_AppConsole, OnCmdLineHelp);
	Gura_AssignMethod(wx_AppConsole, OnCmdLineParsed);
	Gura_AssignMethod(wx_AppConsole, OnEventLoopEnter);
	Gura_AssignMethod(wx_AppConsole, OnEventLoopExit);
	Gura_AssignMethod(wx_AppConsole, OnExit);
	Gura_AssignMethod(wx_AppConsole, OnFatalException);
	Gura_AssignMethod(wx_AppConsole, OnInit);
	Gura_AssignMethod(wx_AppConsole, OnInitCmdLine);
	Gura_AssignMethod(wx_AppConsole, OnRun);
	Gura_AssignMethod(wx_AppConsole, OnExceptionInMainLoop);
	Gura_AssignMethod(wx_AppConsole, OnUnhandledException);
	Gura_AssignMethod(wx_AppConsole, StoreCurrentException);
	Gura_AssignMethod(wx_AppConsole, RethrowStoredException);
	Gura_AssignMethod(wx_AppConsole, GetAppDisplayName);
	Gura_AssignMethod(wx_AppConsole, GetAppName);
	Gura_AssignMethod(wx_AppConsole, GetClassName);
	Gura_AssignMethod(wx_AppConsole, GetTraits);
	Gura_AssignMethod(wx_AppConsole, GetVendorDisplayName);
	Gura_AssignMethod(wx_AppConsole, GetVendorName);
	Gura_AssignMethod(wx_AppConsole, SetAppDisplayName);
	Gura_AssignMethod(wx_AppConsole, SetAppName);
	Gura_AssignMethod(wx_AppConsole, SetClassName);
	Gura_AssignMethod(wx_AppConsole, SetVendorDisplayName);
	Gura_AssignMethod(wx_AppConsole, SetVendorName);
	Gura_AssignMethod(wx_AppConsole, SetCLocale);
}

Gura_ImplementDescendantCreator(wx_AppConsole)
{
	return new Object_wx_AppConsole((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
