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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __CreateTraits)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAppTraits* _rtn = pThis->GetEntity()->CreateTraits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __MainLoop, "MainLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __MainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->MainLoop();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __FilterEvent)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEvent& event = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->FilterEvent(event);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetMainLoop, "GetMainLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEventLoopBase* _rtn = pThis->GetEntity()->GetMainLoop();
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
	//wxEvtHandler* handler = arg.GetNumber(0)
	//wxEventFunction func = arg.GetNumber(1)
	//wxEvent& event = arg.GetNumber(2)
	//pThis->GetEntity()->HandleEvent(handler, func, event);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __UsesEventLoop, "UsesEventLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __UsesEventLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->UsesEventLoop();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __HasPendingEvents)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasPendingEvents();
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
	//wxObject* object = arg.GetNumber(0)
	//pThis->GetEntity()->ScheduleForDestruction(object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __IsScheduledForDestruction, "IsScheduledForDestruction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __IsScheduledForDestruction)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObject* object = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsScheduledForDestruction(object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __Yield, "Yield")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "onlyIfNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __Yield)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool onlyIfNeeded = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Yield(onlyIfNeeded);
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
	//wxAppConsole* app = arg.GetNumber(0)
	//pThis->GetEntity()->SetInstance(app);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetInstance, "GetInstance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetInstance)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAppConsole* _rtn = pThis->GetEntity()->GetInstance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __IsMainLoopRunning, "IsMainLoopRunning")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __IsMainLoopRunning)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsMainLoopRunning();
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
	//const wxChar* file = arg.GetNumber(0)
	//int line = arg.GetNumber(1)
	//const wxChar* func = arg.GetNumber(2)
	//const wxChar* cond = arg.GetNumber(3)
	//const wxChar* msg = arg.GetNumber(4)
	//pThis->GetEntity()->OnAssertFailure(file, line, func, cond, msg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnCmdLineError, "OnCmdLineError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnCmdLineError)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCmdLineParser& parser = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->OnCmdLineError(parser);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnCmdLineHelp, "OnCmdLineHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnCmdLineHelp)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCmdLineParser& parser = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->OnCmdLineHelp(parser);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnCmdLineParsed, "OnCmdLineParsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parser", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppConsole, __OnCmdLineParsed)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCmdLineParser& parser = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->OnCmdLineParsed(parser);
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
	//wxEventLoopBase* loop = arg.GetNumber(0)
	//pThis->GetEntity()->OnEventLoopEnter(loop);
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
	//wxEventLoopBase* loop = arg.GetNumber(0)
	//pThis->GetEntity()->OnEventLoopExit(loop);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnExit, "OnExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnExit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->OnExit();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnInit)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->OnInit();
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
	//wxCmdLineParser& parser = arg.GetNumber(0)
	//pThis->GetEntity()->OnInitCmdLine(parser);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnRun, "OnRun")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnRun)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->OnRun();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __OnExceptionInMainLoop, "OnExceptionInMainLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __OnExceptionInMainLoop)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->OnExceptionInMainLoop();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __StoreCurrentException)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->StoreCurrentException();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetAppDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetAppDisplayName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetAppName, "GetAppName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetAppName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetAppName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetClassName, "GetClassName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetClassName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetClassName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetTraits, "GetTraits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetTraits)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAppTraits* _rtn = pThis->GetEntity()->GetTraits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetVendorDisplayName, "GetVendorDisplayName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetVendorDisplayName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetVendorDisplayName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppConsole, __GetVendorName, "GetVendorName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AppConsole, __GetVendorName)
{
	Object_wx_AppConsole *pThis = Object_wx_AppConsole::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetVendorName();
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
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetAppDisplayName(name);
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
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetAppName(name);
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
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetClassName(name);
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
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetVendorDisplayName(name);
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
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetVendorName(name);
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
