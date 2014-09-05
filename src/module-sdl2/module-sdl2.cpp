//=============================================================================
// Gura module: sdl2
//=============================================================================
#include "stdafx.h"

#undef CreateWindow

#define RealizeClass(className) \
Gura_RealizeUserClassExWithoutPrepare(##className, #className, env.LookupClass(VTYPE_object))

#define PrepareClass(className) \
Gura_UserClass(className)->Prepare(env)

#define Gura_AssignValueSDL(name) Gura_AssignValue(name, Value(SDL_##name))

Gura_BeginModuleBody(sdl2)

//-----------------------------------------------------------------------------
// Basics - Initialization and Shutdown
//-----------------------------------------------------------------------------
// sdl2.Init()
Gura_DeclareFunction(Init)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Init)
{
	//::SDL_Init();
	SetError_NotImpFunction(sig, "Init");
	return Value::Null;
}

// sdl2.InitSubSystem()
Gura_DeclareFunction(InitSubSystem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(InitSubSystem)
{
	//::SDL_InitSubSystem();
	SetError_NotImpFunction(sig, "InitSubSystem");
	return Value::Null;
}

// sdl2.Quit()
Gura_DeclareFunction(Quit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Quit)
{
	//::SDL_Quit();
	SetError_NotImpFunction(sig, "Quit");
	return Value::Null;
}

// sdl2.QuitSubSystem()
Gura_DeclareFunction(QuitSubSystem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(QuitSubSystem)
{
	//::SDL_QuitSubSystem();
	SetError_NotImpFunction(sig, "QuitSubSystem");
	return Value::Null;
}

// sdl2.SetMainReady()
Gura_DeclareFunction(SetMainReady)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetMainReady)
{
	//::SDL_SetMainReady();
	SetError_NotImpFunction(sig, "SetMainReady");
	return Value::Null;
}

// sdl2.WasInit()
Gura_DeclareFunction(WasInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WasInit)
{
	//::SDL_WasInit();
	SetError_NotImpFunction(sig, "WasInit");
	return Value::Null;
}

// sdl2.AddHintCallback()
Gura_DeclareFunction(AddHintCallback)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AddHintCallback)
{
	//::SDL_AddHintCallback();
	SetError_NotImpFunction(sig, "AddHintCallback");
	return Value::Null;
}

// sdl2.ClearHints()
Gura_DeclareFunction(ClearHints)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ClearHints)
{
	//::SDL_ClearHints();
	SetError_NotImpFunction(sig, "ClearHints");
	return Value::Null;
}

// sdl2.DelhintCallback()
Gura_DeclareFunction(DelhintCallback)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DelhintCallback)
{
	//::SDL_DelhintCallback();
	SetError_NotImpFunction(sig, "DelhintCallback");
	return Value::Null;
}

// sdl2.GetHint()
Gura_DeclareFunction(GetHint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetHint)
{
	//::SDL_GetHint();
	SetError_NotImpFunction(sig, "GetHint");
	return Value::Null;
}

// sdl2.SetHint()
Gura_DeclareFunction(SetHint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetHint)
{
	//::SDL_SetHint();
	SetError_NotImpFunction(sig, "SetHint");
	return Value::Null;
}

// sdl2.SetHintWithPriority()
Gura_DeclareFunction(SetHintWithPriority)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetHintWithPriority)
{
	//::SDL_SetHintWithPriority();
	SetError_NotImpFunction(sig, "SetHintWithPriority");
	return Value::Null;
}

// sdl2.ClearError()
Gura_DeclareFunction(ClearError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ClearError)
{
	//::SDL_ClearError();
	SetError_NotImpFunction(sig, "ClearError");
	return Value::Null;
}

// sdl2.GetError()
Gura_DeclareFunction(GetError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetError)
{
	//::SDL_GetError();
	SetError_NotImpFunction(sig, "GetError");
	return Value::Null;
}

// sdl2.SetError()
Gura_DeclareFunction(SetError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetError)
{
	//::SDL_SetError();
	SetError_NotImpFunction(sig, "SetError");
	return Value::Null;
}

// sdl2.Log()
Gura_DeclareFunction(Log)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Log)
{
	//::SDL_Log();
	SetError_NotImpFunction(sig, "Log");
	return Value::Null;
}

// sdl2.LogCritical()
Gura_DeclareFunction(LogCritical)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogCritical)
{
	//::SDL_LogCritical();
	SetError_NotImpFunction(sig, "LogCritical");
	return Value::Null;
}

// sdl2.LogDebug()
Gura_DeclareFunction(LogDebug)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogDebug)
{
	//::SDL_LogDebug();
	SetError_NotImpFunction(sig, "LogDebug");
	return Value::Null;
}

// sdl2.LogError()
Gura_DeclareFunction(LogError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogError)
{
	//::SDL_LogError();
	SetError_NotImpFunction(sig, "LogError");
	return Value::Null;
}

// sdl2.LogGetOutputFunction()
Gura_DeclareFunction(LogGetOutputFunction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogGetOutputFunction)
{
	//::SDL_LogGetOutputFunction();
	SetError_NotImpFunction(sig, "LogGetOutputFunction");
	return Value::Null;
}

// sdl2.LogGetPriority()
Gura_DeclareFunction(LogGetPriority)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogGetPriority)
{
	//::SDL_LogGetPriority();
	SetError_NotImpFunction(sig, "LogGetPriority");
	return Value::Null;
}

// sdl2.LogInfo()
Gura_DeclareFunction(LogInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogInfo)
{
	//::SDL_LogInfo();
	SetError_NotImpFunction(sig, "LogInfo");
	return Value::Null;
}

// sdl2.LogMessage()
Gura_DeclareFunction(LogMessage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogMessage)
{
	//::SDL_LogMessage();
	SetError_NotImpFunction(sig, "LogMessage");
	return Value::Null;
}

// sdl2.LogMessageV()
Gura_DeclareFunction(LogMessageV)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogMessageV)
{
	//::SDL_LogMessageV();
	SetError_NotImpFunction(sig, "LogMessageV");
	return Value::Null;
}

// sdl2.LogResetPriorities()
Gura_DeclareFunction(LogResetPriorities)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogResetPriorities)
{
	//::SDL_LogResetPriorities();
	SetError_NotImpFunction(sig, "LogResetPriorities");
	return Value::Null;
}

// sdl2.LogSetAllPriority()
Gura_DeclareFunction(LogSetAllPriority)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogSetAllPriority)
{
	//::SDL_LogSetAllPriority();
	SetError_NotImpFunction(sig, "LogSetAllPriority");
	return Value::Null;
}

// sdl2.LogSetOutputFunction()
Gura_DeclareFunction(LogSetOutputFunction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogSetOutputFunction)
{
	//::SDL_LogSetOutputFunction();
	SetError_NotImpFunction(sig, "LogSetOutputFunction");
	return Value::Null;
}

// sdl2.LogSetPriority()
Gura_DeclareFunction(LogSetPriority)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogSetPriority)
{
	//::SDL_LogSetPriority();
	SetError_NotImpFunction(sig, "LogSetPriority");
	return Value::Null;
}

// sdl2.LogVerbose()
Gura_DeclareFunction(LogVerbose)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogVerbose)
{
	//::SDL_LogVerbose();
	SetError_NotImpFunction(sig, "LogVerbose");
	return Value::Null;
}

// sdl2.LogWarn()
Gura_DeclareFunction(LogWarn)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogWarn)
{
	//::SDL_LogWarn();
	SetError_NotImpFunction(sig, "LogWarn");
	return Value::Null;
}

// sdl2.GetAssertionHandler()
Gura_DeclareFunction(GetAssertionHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAssertionHandler)
{
	//::SDL_GetAssertionHandler();
	SetError_NotImpFunction(sig, "GetAssertionHandler");
	return Value::Null;
}

// sdl2.GetAssertionReport()
Gura_DeclareFunction(GetAssertionReport)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAssertionReport)
{
	//::SDL_GetAssertionReport();
	SetError_NotImpFunction(sig, "GetAssertionReport");
	return Value::Null;
}

// sdl2.GetDefaultAssertionHandler()
Gura_DeclareFunction(GetDefaultAssertionHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDefaultAssertionHandler)
{
	//::SDL_GetDefaultAssertionHandler();
	SetError_NotImpFunction(sig, "GetDefaultAssertionHandler");
	return Value::Null;
}

// sdl2.ResetAssertionReport()
Gura_DeclareFunction(ResetAssertionReport)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ResetAssertionReport)
{
	//::SDL_ResetAssertionReport();
	SetError_NotImpFunction(sig, "ResetAssertionReport");
	return Value::Null;
}

// sdl2.SetAssertionHandler()
Gura_DeclareFunction(SetAssertionHandler)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetAssertionHandler)
{
	//::SDL_SetAssertionHandler();
	SetError_NotImpFunction(sig, "SetAssertionHandler");
	return Value::Null;
}

// sdl2.TriggerBreakpoint()
Gura_DeclareFunction(TriggerBreakpoint)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(TriggerBreakpoint)
{
	//::SDL_TriggerBreakpoint();
	SetError_NotImpFunction(sig, "TriggerBreakpoint");
	return Value::Null;
}

// sdl2.assert()
Gura_DeclareFunction(assert)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(assert)
{
	//::SDL_assert();
	SetError_NotImpFunction(sig, "assert");
	return Value::Null;
}

// sdl2.assert_paranoid()
Gura_DeclareFunction(assert_paranoid)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(assert_paranoid)
{
	//::SDL_assert_paranoid();
	SetError_NotImpFunction(sig, "assert_paranoid");
	return Value::Null;
}

// sdl2.assert_release()
Gura_DeclareFunction(assert_release)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(assert_release)
{
	//::SDL_assert_release();
	SetError_NotImpFunction(sig, "assert_release");
	return Value::Null;
}

// sdl2.GetRevision()
Gura_DeclareFunction(GetRevision)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRevision)
{
	//::SDL_GetRevision();
	SetError_NotImpFunction(sig, "GetRevision");
	return Value::Null;
}

// sdl2.GetRevisionNumber()
Gura_DeclareFunction(GetRevisionNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRevisionNumber)
{
	//::SDL_GetRevisionNumber();
	SetError_NotImpFunction(sig, "GetRevisionNumber");
	return Value::Null;
}

// sdl2.GetVersion()
Gura_DeclareFunction(GetVersion)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetVersion)
{
	//::SDL_GetVersion();
	SetError_NotImpFunction(sig, "GetVersion");
	return Value::Null;
}

// sdl2.CreateWindow()
Gura_DeclareFunction(CreateWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateWindow)
{
	//::SDL_CreateWindow();
	SetError_NotImpFunction(sig, "CreateWindow");
	return Value::Null;
}

// sdl2.CreateWindowAndRenderer()
Gura_DeclareFunction(CreateWindowAndRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateWindowAndRenderer)
{
	//::SDL_CreateWindowAndRenderer();
	SetError_NotImpFunction(sig, "CreateWindowAndRenderer");
	return Value::Null;
}

// sdl2.CreateWindowFrom()
Gura_DeclareFunction(CreateWindowFrom)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateWindowFrom)
{
	//::SDL_CreateWindowFrom();
	SetError_NotImpFunction(sig, "CreateWindowFrom");
	return Value::Null;
}

// sdl2.DisableScreenSaver()
Gura_DeclareFunction(DisableScreenSaver)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DisableScreenSaver)
{
	//::SDL_DisableScreenSaver();
	SetError_NotImpFunction(sig, "DisableScreenSaver");
	return Value::Null;
}

// sdl2.EnableScreenSaver()
Gura_DeclareFunction(EnableScreenSaver)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(EnableScreenSaver)
{
	//::SDL_EnableScreenSaver();
	SetError_NotImpFunction(sig, "EnableScreenSaver");
	return Value::Null;
}

// sdl2.GL_ExtensionSupported()
Gura_DeclareFunction(GL_ExtensionSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_ExtensionSupported)
{
	//::SDL_GL_ExtensionSupported();
	SetError_NotImpFunction(sig, "GL_ExtensionSupported");
	return Value::Null;
}

// sdl2.GL_GetAttribute()
Gura_DeclareFunction(GL_GetAttribute)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetAttribute)
{
	//::SDL_GL_GetAttribute();
	SetError_NotImpFunction(sig, "GL_GetAttribute");
	return Value::Null;
}

// sdl2.GL_GetCurrentContext()
Gura_DeclareFunction(GL_GetCurrentContext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetCurrentContext)
{
	//::SDL_GL_GetCurrentContext();
	SetError_NotImpFunction(sig, "GL_GetCurrentContext");
	return Value::Null;
}

// sdl2.GL_GetCurrentWindow()
Gura_DeclareFunction(GL_GetCurrentWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetCurrentWindow)
{
	//::SDL_GL_GetCurrentWindow();
	SetError_NotImpFunction(sig, "GL_GetCurrentWindow");
	return Value::Null;
}

// sdl2.GL_GetDrawableSize()
Gura_DeclareFunction(GL_GetDrawableSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetDrawableSize)
{
	//::SDL_GL_GetDrawableSize();
	SetError_NotImpFunction(sig, "GL_GetDrawableSize");
	return Value::Null;
}

// sdl2.GL_GetProcAddress()
Gura_DeclareFunction(GL_GetProcAddress)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetProcAddress)
{
	//::SDL_GL_GetProcAddress();
	SetError_NotImpFunction(sig, "GL_GetProcAddress");
	return Value::Null;
}

// sdl2.GL_GetSwapInterval()
Gura_DeclareFunction(GL_GetSwapInterval)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetSwapInterval)
{
	//::SDL_GL_GetSwapInterval();
	SetError_NotImpFunction(sig, "GL_GetSwapInterval");
	return Value::Null;
}

// sdl2.GL_LoadLibrary()
Gura_DeclareFunction(GL_LoadLibrary)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_LoadLibrary)
{
	//::SDL_GL_LoadLibrary();
	SetError_NotImpFunction(sig, "GL_LoadLibrary");
	return Value::Null;
}

// sdl2.GL_ResetAttributes()
Gura_DeclareFunction(GL_ResetAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_ResetAttributes)
{
	//::SDL_GL_ResetAttributes();
	SetError_NotImpFunction(sig, "GL_ResetAttributes");
	return Value::Null;
}

// sdl2.GL_SetAttribute()
Gura_DeclareFunction(GL_SetAttribute)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_SetAttribute)
{
	//::SDL_GL_SetAttribute();
	SetError_NotImpFunction(sig, "GL_SetAttribute");
	return Value::Null;
}

// sdl2.GL_SetSwapInterval()
Gura_DeclareFunction(GL_SetSwapInterval)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_SetSwapInterval)
{
	//::SDL_GL_SetSwapInterval();
	SetError_NotImpFunction(sig, "GL_SetSwapInterval");
	return Value::Null;
}

// sdl2.GL_UnloadLibrary()
Gura_DeclareFunction(GL_UnloadLibrary)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_UnloadLibrary)
{
	//::SDL_GL_UnloadLibrary();
	SetError_NotImpFunction(sig, "GL_UnloadLibrary");
	return Value::Null;
}

// sdl2.GetClosestDisplayMode()
Gura_DeclareFunction(GetClosestDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetClosestDisplayMode)
{
	//::SDL_GetClosestDisplayMode();
	SetError_NotImpFunction(sig, "GetClosestDisplayMode");
	return Value::Null;
}

// sdl2.GetCurrentDisplayMode()
Gura_DeclareFunction(GetCurrentDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCurrentDisplayMode)
{
	//::SDL_GetCurrentDisplayMode();
	SetError_NotImpFunction(sig, "GetCurrentDisplayMode");
	return Value::Null;
}

// sdl2.GetCurrentVideoDriver()
Gura_DeclareFunction(GetCurrentVideoDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCurrentVideoDriver)
{
	//::SDL_GetCurrentVideoDriver();
	SetError_NotImpFunction(sig, "GetCurrentVideoDriver");
	return Value::Null;
}

// sdl2.GetDesktopDisplayMode()
Gura_DeclareFunction(GetDesktopDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDesktopDisplayMode)
{
	//::SDL_GetDesktopDisplayMode();
	SetError_NotImpFunction(sig, "GetDesktopDisplayMode");
	return Value::Null;
}

// sdl2.GetDisplayBounds()
Gura_DeclareFunction(GetDisplayBounds)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDisplayBounds)
{
	//::SDL_GetDisplayBounds();
	SetError_NotImpFunction(sig, "GetDisplayBounds");
	return Value::Null;
}

// sdl2.GetDisplayMode()
Gura_DeclareFunction(GetDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDisplayMode)
{
	//::SDL_GetDisplayMode();
	SetError_NotImpFunction(sig, "GetDisplayMode");
	return Value::Null;
}

// sdl2.GetDisplayName()
Gura_DeclareFunction(GetDisplayName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDisplayName)
{
	//::SDL_GetDisplayName();
	SetError_NotImpFunction(sig, "GetDisplayName");
	return Value::Null;
}

// sdl2.GetNumDisplayModes()
Gura_DeclareFunction(GetNumDisplayModes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumDisplayModes)
{
	//::SDL_GetNumDisplayModes();
	SetError_NotImpFunction(sig, "GetNumDisplayModes");
	return Value::Null;
}

// sdl2.GetNumVideoDisplays()
Gura_DeclareFunction(GetNumVideoDisplays)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumVideoDisplays)
{
	//::SDL_GetNumVideoDisplays();
	SetError_NotImpFunction(sig, "GetNumVideoDisplays");
	return Value::Null;
}

// sdl2.GetNumVideoDrivers()
Gura_DeclareFunction(GetNumVideoDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumVideoDrivers)
{
	//::SDL_GetNumVideoDrivers();
	SetError_NotImpFunction(sig, "GetNumVideoDrivers");
	return Value::Null;
}

// sdl2.GetVideoDriver()
Gura_DeclareFunction(GetVideoDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetVideoDriver)
{
	//::SDL_GetVideoDriver();
	SetError_NotImpFunction(sig, "GetVideoDriver");
	return Value::Null;
}

// sdl2.GetWindowFromID()
Gura_DeclareFunction(GetWindowFromID)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowFromID)
{
	//::SDL_GetWindowFromID();
	SetError_NotImpFunction(sig, "GetWindowFromID");
	return Value::Null;
}

// sdl2.IsScreenSaverEnabled()
Gura_DeclareFunction(IsScreenSaverEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(IsScreenSaverEnabled)
{
	//::SDL_IsScreenSaverEnabled();
	SetError_NotImpFunction(sig, "IsScreenSaverEnabled");
	return Value::Null;
}

// sdl2.ShowSimpleMessageBox()
Gura_DeclareFunction(ShowSimpleMessageBox)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ShowSimpleMessageBox)
{
	//::SDL_ShowSimpleMessageBox();
	SetError_NotImpFunction(sig, "ShowSimpleMessageBox");
	return Value::Null;
}

// sdl2.VideoInit()
Gura_DeclareFunction(VideoInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(VideoInit)
{
	//::SDL_VideoInit();
	SetError_NotImpFunction(sig, "VideoInit");
	return Value::Null;
}

// sdl2.VideoQuit()
Gura_DeclareFunction(VideoQuit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(VideoQuit)
{
	//::SDL_VideoQuit();
	SetError_NotImpFunction(sig, "VideoQuit");
	return Value::Null;
}

// sdl2.GetNumRenderDrivers()
Gura_DeclareFunction(GetNumRenderDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumRenderDrivers)
{
	//::SDL_GetNumRenderDrivers();
	SetError_NotImpFunction(sig, "GetNumRenderDrivers");
	return Value::Null;
}

// sdl2.GetRenderDriverInfo()
Gura_DeclareFunction(GetRenderDriverInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderDriverInfo)
{
	//::SDL_GetRenderDriverInfo();
	SetError_NotImpFunction(sig, "GetRenderDriverInfo");
	return Value::Null;
}

// sdl2.AllocFormat()
Gura_DeclareFunction(AllocFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AllocFormat)
{
	//::SDL_AllocFormat();
	SetError_NotImpFunction(sig, "AllocFormat");
	return Value::Null;
}

// sdl2.AllocPalette()
Gura_DeclareFunction(AllocPalette)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AllocPalette)
{
	//::SDL_AllocPalette();
	SetError_NotImpFunction(sig, "AllocPalette");
	return Value::Null;
}

// sdl2.CalculateGammaRamp()
Gura_DeclareFunction(CalculateGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CalculateGammaRamp)
{
	//::SDL_CalculateGammaRamp();
	SetError_NotImpFunction(sig, "CalculateGammaRamp");
	return Value::Null;
}

// sdl2.GetPixelFormatName()
Gura_DeclareFunction(GetPixelFormatName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetPixelFormatName)
{
	//::SDL_GetPixelFormatName();
	SetError_NotImpFunction(sig, "GetPixelFormatName");
	return Value::Null;
}

// sdl2.MasksToPixelFormatEnum()
Gura_DeclareFunction(MasksToPixelFormatEnum)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MasksToPixelFormatEnum)
{
	//::SDL_MasksToPixelFormatEnum();
	SetError_NotImpFunction(sig, "MasksToPixelFormatEnum");
	return Value::Null;
}

// sdl2.PixelFormatEnumToMasks()
Gura_DeclareFunction(PixelFormatEnumToMasks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PixelFormatEnumToMasks)
{
	//::SDL_PixelFormatEnumToMasks();
	SetError_NotImpFunction(sig, "PixelFormatEnumToMasks");
	return Value::Null;
}

// sdl2.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
	::SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = ::SDL_CreateWindow("Hey",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	::SDL_Renderer *renderer = ::SDL_CreateRenderer(window, -1, 0);
	SDL_Event ev;
	for (;;) {
		::SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		::SDL_RenderClear(renderer);
		while (::SDL_PollEvent(&ev)) {
			if (ev.type == SDL_QUIT) return 0;
		}
		::SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		::SDL_RenderDrawLine(renderer, 10, 10, 400, 400);
		::SDL_RenderPresent(renderer);
	}
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

Gura_ModuleEntry()
{
	// class realization
	RealizeClass(Window);
	RealizeClass(Renderer);
	RealizeClass(Texture);
	RealizeClass(Event);
	RealizeClass(Point);
	RealizeClass(Rect);
	RealizeClass(Color);
	RealizeClass(Palette);
	RealizeClass(PixelFormat);
	RealizeClass(Keysym);
	RealizeClass(Cursor);
	RealizeClass(Joystick);
	RealizeClass(GameController);
	RealizeClass(AudioCVT);
	RealizeClass(AudioSpec);
	RealizeClass(RendererInfo);
	RealizeClass(DisplayMode);
	RealizeClass(GLContext);
	RealizeClass(Haptic);
	// class preparation
	PrepareClass(Window);
	PrepareClass(Renderer);
	PrepareClass(Texture);
	PrepareClass(Event);
	PrepareClass(Point);
	PrepareClass(Rect);
	PrepareClass(Color);
	PrepareClass(Palette);
	PrepareClass(PixelFormat);
	PrepareClass(Keysym);
	PrepareClass(Cursor);
	PrepareClass(Joystick);
	PrepareClass(GameController);
	PrepareClass(AudioCVT);
	PrepareClass(AudioSpec);
	PrepareClass(RendererInfo);
	PrepareClass(DisplayMode);
	PrepareClass(GLContext);
	PrepareClass(Haptic);
	AssignValues(env);
	AssignFunctions(env);
	Gura_AssignFunction(test);
	return true;
}

void AssignValues(Environment &env)
{
	// Basics - Initialization and Shutdown
	// Basics - Configuration Variables
	// Basics - Error Handling
	// Basics - Log Handling
	// Basics - Assertions
	// Basics - Querying SDL Version
	Gura_AssignValueSDL(COMPILEDVERSION);
	//Gura_AssignValueSDL(REVISION);
	//Gura_AssignValueSDL(VERSION);
	//Gura_AssignValueSDL(VERSIONNUM);
	//Gura_AssignValueSDL(VERSION_ATLEAST);
	// Video - Display and Window Management
	Gura_AssignValueSDL(BLENDMODE_NONE);
	Gura_AssignValueSDL(BLENDMODE_BLEND);
	Gura_AssignValueSDL(BLENDMODE_ADD);
	Gura_AssignValueSDL(BLENDMODE_MOD);
	Gura_AssignValueSDL(GL_RED_SIZE);
	Gura_AssignValueSDL(GL_GREEN_SIZE);
	Gura_AssignValueSDL(GL_BLUE_SIZE);
	Gura_AssignValueSDL(GL_ALPHA_SIZE);
	Gura_AssignValueSDL(GL_BUFFER_SIZE);
	Gura_AssignValueSDL(GL_DOUBLEBUFFER);
	Gura_AssignValueSDL(GL_DEPTH_SIZE);
	Gura_AssignValueSDL(GL_STENCIL_SIZE);
	Gura_AssignValueSDL(GL_ACCUM_RED_SIZE);
	Gura_AssignValueSDL(GL_ACCUM_GREEN_SIZE);
	Gura_AssignValueSDL(GL_ACCUM_BLUE_SIZE);
	Gura_AssignValueSDL(GL_ACCUM_ALPHA_SIZE);
	Gura_AssignValueSDL(GL_STEREO);
	Gura_AssignValueSDL(GL_MULTISAMPLEBUFFERS);
	Gura_AssignValueSDL(GL_MULTISAMPLESAMPLES);
	Gura_AssignValueSDL(GL_ACCELERATED_VISUAL);
	Gura_AssignValueSDL(GL_RETAINED_BACKING);			// not used (deprecated)
	Gura_AssignValueSDL(GL_CONTEXT_MAJOR_VERSION);
	Gura_AssignValueSDL(GL_CONTEXT_MINOR_VERSION);
	Gura_AssignValueSDL(GL_CONTEXT_FLAGS);
	Gura_AssignValueSDL(GL_CONTEXT_PROFILE_MASK);
	Gura_AssignValueSDL(GL_SHARE_WITH_CURRENT_CONTEXT);
	Gura_AssignValueSDL(GL_FRAMEBUFFER_SRGB_CAPABLE);
	Gura_AssignValueSDL(GL_CONTEXT_EGL);				// not used (deprecated)
	Gura_AssignValueSDL(GL_CONTEXT_DEBUG_FLAG);
	Gura_AssignValueSDL(GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	Gura_AssignValueSDL(GL_CONTEXT_ROBUST_ACCESS_FLAG);
	Gura_AssignValueSDL(GL_CONTEXT_RESET_ISOLATION_FLAG);
	Gura_AssignValueSDL(GL_CONTEXT_PROFILE_CORE);
	Gura_AssignValueSDL(GL_CONTEXT_PROFILE_COMPATIBILITY);
	Gura_AssignValueSDL(GL_CONTEXT_PROFILE_ES);
	/* Draft
	Gura_AssignValueSDL(HITTEST_NORMAL);
	Gura_AssignValueSDL(HITTEST_DRAGGABLE);
	Gura_AssignValueSDL(HITTEST_RESIZE_TOPLEFT);
	Gura_AssignValueSDL(HITTEST_RESIZE_TOP);
	Gura_AssignValueSDL(HITTEST_RESIZE_TOPRIGHT);
	Gura_AssignValueSDL(HITTEST_RESIZE_RIGHT);
	Gura_AssignValueSDL(HITTEST_RESIZE_BOTTOMRIGHT);
	Gura_AssignValueSDL(HITTEST_RESIZE_BOTTOM);
	Gura_AssignValueSDL(HITTEST_RESIZE_BOTTOMLEFT);
	Gura_AssignValueSDL(HITTEST_RESIZE_LEFT);
	*/
	Gura_AssignValueSDL(WINDOWEVENT_NONE);				// (never used)
	Gura_AssignValueSDL(WINDOWEVENT_SHOWN);
	Gura_AssignValueSDL(WINDOWEVENT_HIDDEN);
	Gura_AssignValueSDL(WINDOWEVENT_EXPOSED);
	Gura_AssignValueSDL(WINDOWEVENT_MOVED);
	Gura_AssignValueSDL(WINDOWEVENT_RESIZED);
	Gura_AssignValueSDL(WINDOWEVENT_SIZE_CHANGED);
	Gura_AssignValueSDL(WINDOWEVENT_MINIMIZED);
	Gura_AssignValueSDL(WINDOWEVENT_MAXIMIZED);
	Gura_AssignValueSDL(WINDOWEVENT_RESTORED);
	Gura_AssignValueSDL(WINDOWEVENT_ENTER);
	Gura_AssignValueSDL(WINDOWEVENT_LEAVE);
	Gura_AssignValueSDL(WINDOWEVENT_FOCUS_GAINED);
	Gura_AssignValueSDL(WINDOWEVENT_FOCUS_LOST);
	Gura_AssignValueSDL(WINDOWEVENT_CLOSE);
	Gura_AssignValueSDL(WINDOW_FULLSCREEN);
	Gura_AssignValueSDL(WINDOW_FULLSCREEN_DESKTOP);
	Gura_AssignValueSDL(WINDOW_OPENGL);
	Gura_AssignValueSDL(WINDOW_SHOWN);
	Gura_AssignValueSDL(WINDOW_HIDDEN);
	Gura_AssignValueSDL(WINDOW_BORDERLESS);
	Gura_AssignValueSDL(WINDOW_RESIZABLE);
	Gura_AssignValueSDL(WINDOW_MINIMIZED);
	Gura_AssignValueSDL(WINDOW_MAXIMIZED);
	Gura_AssignValueSDL(WINDOW_INPUT_GRABBED);
	Gura_AssignValueSDL(WINDOW_INPUT_FOCUS);
	Gura_AssignValueSDL(WINDOW_MOUSE_FOCUS);
	Gura_AssignValueSDL(WINDOW_FOREIGN);
	Gura_AssignValueSDL(WINDOW_ALLOW_HIGHDPI);		// >= SDL 2.0.1
	//Gura_AssignValueSDL(WINDOW_MOUSE_CAPTURE);	// >= SDL 2.0.4
	// Video - 2D Accelerated Rendering
	Gura_AssignValueSDL(RENDERER_SOFTWARE);
	Gura_AssignValueSDL(RENDERER_ACCELERATED);
	Gura_AssignValueSDL(RENDERER_PRESENTVSYNC);
	Gura_AssignValueSDL(RENDERER_TARGETTEXTURE);
	Gura_AssignValueSDL(FLIP_NONE);
	Gura_AssignValueSDL(FLIP_HORIZONTAL);
	Gura_AssignValueSDL(FLIP_VERTICAL);
	Gura_AssignValueSDL(TEXTUREACCESS_STATIC);
	Gura_AssignValueSDL(TEXTUREACCESS_STREAMING);
	Gura_AssignValueSDL(TEXTUREACCESS_TARGET);
	Gura_AssignValueSDL(TEXTUREMODULATE_NONE);
	Gura_AssignValueSDL(TEXTUREMODULATE_COLOR);
	Gura_AssignValueSDL(TEXTUREMODULATE_ALPHA);
	// Video - Pixel Formats and Conversion Routines
	Gura_AssignValueSDL(PIXELFORMAT_UNKNOWN);
	Gura_AssignValueSDL(PIXELFORMAT_INDEX1LSB);
	Gura_AssignValueSDL(PIXELFORMAT_INDEX1MSB);
	Gura_AssignValueSDL(PIXELFORMAT_INDEX4LSB);
	Gura_AssignValueSDL(PIXELFORMAT_INDEX4MSB);
	Gura_AssignValueSDL(PIXELFORMAT_INDEX8);
	Gura_AssignValueSDL(PIXELFORMAT_RGB332);
	Gura_AssignValueSDL(PIXELFORMAT_RGB444);
	Gura_AssignValueSDL(PIXELFORMAT_RGB555);
	Gura_AssignValueSDL(PIXELFORMAT_BGR555);
	Gura_AssignValueSDL(PIXELFORMAT_ARGB4444);
	Gura_AssignValueSDL(PIXELFORMAT_RGBA4444);
	Gura_AssignValueSDL(PIXELFORMAT_ABGR4444);
	Gura_AssignValueSDL(PIXELFORMAT_BGRA4444);
	Gura_AssignValueSDL(PIXELFORMAT_ARGB1555);
	Gura_AssignValueSDL(PIXELFORMAT_RGBA5551);
	Gura_AssignValueSDL(PIXELFORMAT_ABGR1555);
	Gura_AssignValueSDL(PIXELFORMAT_BGRA5551);
	Gura_AssignValueSDL(PIXELFORMAT_RGB565);
	Gura_AssignValueSDL(PIXELFORMAT_BGR565);
	Gura_AssignValueSDL(PIXELFORMAT_RGB24);
	Gura_AssignValueSDL(PIXELFORMAT_BGR24);
	Gura_AssignValueSDL(PIXELFORMAT_RGB888);
	Gura_AssignValueSDL(PIXELFORMAT_RGBX8888);
	Gura_AssignValueSDL(PIXELFORMAT_BGR888);
	Gura_AssignValueSDL(PIXELFORMAT_BGRX8888);
	Gura_AssignValueSDL(PIXELFORMAT_ARGB8888);
	Gura_AssignValueSDL(PIXELFORMAT_RGBA8888);
	Gura_AssignValueSDL(PIXELFORMAT_ABGR8888);
	Gura_AssignValueSDL(PIXELFORMAT_BGRA8888);
	Gura_AssignValueSDL(PIXELFORMAT_ARGB2101010);
	Gura_AssignValueSDL(PIXELFORMAT_YV12);
	Gura_AssignValueSDL(PIXELFORMAT_IYUV);
	Gura_AssignValueSDL(PIXELFORMAT_YUY2);
	Gura_AssignValueSDL(PIXELFORMAT_UYVY);
	Gura_AssignValueSDL(PIXELFORMAT_YVYU);
	// Video - Rectangle Functions
	// Video - Surface Creation and Simple Drawing
	// Video - Platform-specific Window Management
	/*
	Gura_AssignValueSDL(SYSWM_UNKNOWN);
	Gura_AssignValueSDL(SYSWM_WINDOWS);
	Gura_AssignValueSDL(SYSWM_X11);
	Gura_AssignValueSDL(SYSWM_DIRECTFB);
	Gura_AssignValueSDL(SYSWM_COCOA);
	Gura_AssignValueSDL(SYSWM_UIKIT);
	Gura_AssignValueSDL(SYSWM_WAYLAND);
	Gura_AssignValueSDL(SYSWM_MIR);
	Gura_AssignValueSDL(SYSWM_WINRT);
	Gura_AssignValueSDL(SYSWM_ANDROID);
	*/
	// Video - Clipboard Handling
	// Input Events - Event Handling
	Gura_AssignValueSDL(FIRSTEVENT);			// (unused)
	Gura_AssignValueSDL(QUIT);
	Gura_AssignValueSDL(APP_TERMINATING);
	Gura_AssignValueSDL(APP_LOWMEMORY);
	Gura_AssignValueSDL(APP_WILLENTERBACKGROUND);
	Gura_AssignValueSDL(APP_DIDENTERBACKGROUND);
	Gura_AssignValueSDL(APP_WILLENTERFOREGROUND);
	Gura_AssignValueSDL(APP_DIDENTERFOREGROUND);
	Gura_AssignValueSDL(WINDOWEVENT);
	Gura_AssignValueSDL(SYSWMEVENT);
	Gura_AssignValueSDL(KEYDOWN);
	Gura_AssignValueSDL(KEYUP);
	Gura_AssignValueSDL(TEXTEDITING);
	Gura_AssignValueSDL(TEXTINPUT);
	Gura_AssignValueSDL(MOUSEMOTION);
	Gura_AssignValueSDL(MOUSEBUTTONDOWN);
	Gura_AssignValueSDL(MOUSEBUTTONUP);
	Gura_AssignValueSDL(MOUSEWHEEL);
	Gura_AssignValueSDL(JOYAXISMOTION);
	Gura_AssignValueSDL(JOYBALLMOTION);
	Gura_AssignValueSDL(JOYHATMOTION);
	Gura_AssignValueSDL(JOYBUTTONDOWN);
	Gura_AssignValueSDL(JOYBUTTONUP);
	Gura_AssignValueSDL(JOYDEVICEADDED);
	Gura_AssignValueSDL(JOYDEVICEREMOVED);
	Gura_AssignValueSDL(CONTROLLERAXISMOTION);
	Gura_AssignValueSDL(CONTROLLERBUTTONDOWN);
	Gura_AssignValueSDL(CONTROLLERBUTTONUP);
	Gura_AssignValueSDL(CONTROLLERDEVICEADDED);
	Gura_AssignValueSDL(CONTROLLERDEVICEREMOVED);
	Gura_AssignValueSDL(CONTROLLERDEVICEREMAPPED);
	Gura_AssignValueSDL(FINGERDOWN);
	Gura_AssignValueSDL(FINGERUP);
	Gura_AssignValueSDL(FINGERMOTION);
	Gura_AssignValueSDL(DOLLARGESTURE);
	Gura_AssignValueSDL(MULTIGESTURE);
	Gura_AssignValueSDL(CLIPBOARDUPDATE);
	Gura_AssignValueSDL(DROPFILE);
	Gura_AssignValueSDL(RENDER_TARGETS_RESET);
	//Gura_AssignValueSDL(RENDER_DEVICE_RESET);		// >= SDL 2.0.4
	Gura_AssignValueSDL(USEREVENT);
	Gura_AssignValueSDL(LASTEVENT);
	// Input Events - Keyboard Support
	// Input Events - Mouse Support
	// Input Events - Joystick Support
	// Input Events - Game Controller Support
	// Force Feedback - Force Feedback Support
	// Audio - Audio Device Management, Playing and Recording
	// Threads - Thread Management
	// Threads - Thread Synchronization Primitives
	// Threads - Atomic Operations
	// Timers - Timer Support
	// File Abstraction - Filesystem Paths
	// File Abstraction - File I/O Abstraction
	// Shared Object Support - Shared Object Loading and Function Lookup
	// Platform and CPU Information - Platform Detection
	// Platform and CPU Information - CPU Feature Detection
	// Platform and CPU Information - Byte Order and Byte Swapping
	// Platform and CPU Information - Bit Manipulation
	// Power Management - Power Management Status
	// Additional - Platform-specific functionality
	// Additional - Other
}

void AssignFunctions(Environment &env)
{
	Gura_AssignFunction(Init);
	Gura_AssignFunction(InitSubSystem);
	Gura_AssignFunction(Quit);
	Gura_AssignFunction(QuitSubSystem);
	Gura_AssignFunction(SetMainReady);
	Gura_AssignFunction(WasInit);
	Gura_AssignFunction(AddHintCallback);
	Gura_AssignFunction(ClearHints);
	Gura_AssignFunction(DelhintCallback);
	Gura_AssignFunction(GetHint);
	Gura_AssignFunction(SetHint);
	Gura_AssignFunction(SetHintWithPriority);
	Gura_AssignFunction(ClearError);
	Gura_AssignFunction(GetError);
	Gura_AssignFunction(SetError);
	Gura_AssignFunction(Log);
	Gura_AssignFunction(LogCritical);
	Gura_AssignFunction(LogDebug);
	Gura_AssignFunction(LogError);
	Gura_AssignFunction(LogGetOutputFunction);
	Gura_AssignFunction(LogGetPriority);
	Gura_AssignFunction(LogInfo);
	Gura_AssignFunction(LogMessage);
	Gura_AssignFunction(LogMessageV);
	Gura_AssignFunction(LogResetPriorities);
	Gura_AssignFunction(LogSetAllPriority);
	Gura_AssignFunction(LogSetOutputFunction);
	Gura_AssignFunction(LogSetPriority);
	Gura_AssignFunction(LogVerbose);
	Gura_AssignFunction(LogWarn);
	Gura_AssignFunction(GetAssertionHandler);
	Gura_AssignFunction(GetAssertionReport);
	Gura_AssignFunction(GetDefaultAssertionHandler);
	Gura_AssignFunction(ResetAssertionReport);
	Gura_AssignFunction(SetAssertionHandler);
	Gura_AssignFunction(TriggerBreakpoint);
	Gura_AssignFunction(assert);
	Gura_AssignFunction(assert_paranoid);
	Gura_AssignFunction(assert_release);
	Gura_AssignFunction(GetRevision);
	Gura_AssignFunction(GetRevisionNumber);
	Gura_AssignFunction(GetVersion);
	Gura_AssignFunction(CreateWindow);
	Gura_AssignFunction(CreateWindowAndRenderer);
	Gura_AssignFunction(CreateWindowFrom);
	Gura_AssignFunction(DisableScreenSaver);
	Gura_AssignFunction(EnableScreenSaver);
	Gura_AssignFunction(GL_ExtensionSupported);
	Gura_AssignFunction(GL_GetAttribute);
	Gura_AssignFunction(GL_GetCurrentContext);
	Gura_AssignFunction(GL_GetCurrentWindow);
	Gura_AssignFunction(GL_GetDrawableSize);
	Gura_AssignFunction(GL_GetProcAddress);
	Gura_AssignFunction(GL_GetSwapInterval);
	Gura_AssignFunction(GL_LoadLibrary);
	Gura_AssignFunction(GL_ResetAttributes);
	Gura_AssignFunction(GL_SetAttribute);
	Gura_AssignFunction(GL_SetSwapInterval);
	Gura_AssignFunction(GL_UnloadLibrary);
	Gura_AssignFunction(GetClosestDisplayMode);
	Gura_AssignFunction(GetCurrentDisplayMode);
	Gura_AssignFunction(GetCurrentVideoDriver);
	Gura_AssignFunction(GetDesktopDisplayMode);
	Gura_AssignFunction(GetDisplayBounds);
	Gura_AssignFunction(GetDisplayMode);
	Gura_AssignFunction(GetDisplayName);
	Gura_AssignFunction(GetNumDisplayModes);
	Gura_AssignFunction(GetNumVideoDisplays);
	Gura_AssignFunction(GetNumVideoDrivers);
	Gura_AssignFunction(GetVideoDriver);
	Gura_AssignFunction(GetWindowFromID);
	Gura_AssignFunction(IsScreenSaverEnabled);
	Gura_AssignFunction(ShowSimpleMessageBox);
	Gura_AssignFunction(VideoInit);
	Gura_AssignFunction(VideoQuit);
	Gura_AssignFunction(GetNumRenderDrivers);
	Gura_AssignFunction(GetRenderDriverInfo);
	Gura_AssignFunction(AllocFormat);
	Gura_AssignFunction(AllocPalette);
	Gura_AssignFunction(CalculateGammaRamp);
	Gura_AssignFunction(GetPixelFormatName);
	Gura_AssignFunction(MasksToPixelFormatEnum);
	Gura_AssignFunction(PixelFormatEnumToMasks);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_SDL(Signal &sig)
{
	sig.SetError(ERR_RuntimeError, "%s", ::SDL_GetError());
}

void SetError_NotImpFunction(Signal &sig, const char *funcName)
{
	sig.SetError(ERR_RuntimeError, "not implemented function %s", funcName);
}

void SetError_NotImpMethod(Signal &sig, const char *className, const char *methodName)
{
	sig.SetError(ERR_RuntimeError, "not implemented method %s#methodName", className, methodName);
}

Gura_EndModuleBody(sdl2, sdl2)

Gura_RegisterModule(sdl2)
