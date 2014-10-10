#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

// sdl2.Init
Gura_DeclareFunction(Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Init)
{
	Uint32 flags = args.GetULong(0);
	int _rtn = SDL_Init(flags);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.InitSubSystem
Gura_DeclareFunction(InitSubSystem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(InitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	int _rtn = SDL_InitSubSystem(flags);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.Quit
Gura_DeclareFunction(Quit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Quit)
{
	SDL_Quit();
	return Value::Null;
}

// sdl2.QuitSubSystem
Gura_DeclareFunction(QuitSubSystem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(QuitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	SDL_QuitSubSystem(flags);
	return Value::Null;
}

// sdl2.SetMainReady
Gura_DeclareFunction(SetMainReady)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetMainReady)
{
	SDL_SetMainReady();
	return Value::Null;
}

// sdl2.WasInit
Gura_DeclareFunction(WasInit)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WasInit)
{
	Uint32 flags = args.GetULong(0);
	Uint32 _rtn = SDL_WasInit(flags);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.AddHintCallback
Gura_DeclareFunction(AddHintCallback)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AddHintCallback)
{
#if 0
	SDL_AddHintCallback();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AddHintCallback");
	return Value::Null;
}

// sdl2.ClearHints
Gura_DeclareFunction(ClearHints)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ClearHints)
{
#if 0
	SDL_ClearHints();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ClearHints");
	return Value::Null;
}

// sdl2.DelhintCallback
Gura_DeclareFunction(DelhintCallback)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DelhintCallback)
{
#if 0
	SDL_DelhintCallback();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DelhintCallback");
	return Value::Null;
}

// sdl2.GetHint
Gura_DeclareFunction(GetHint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetHint)
{
#if 0
	SDL_GetHint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetHint");
	return Value::Null;
}

// sdl2.SetHint
Gura_DeclareFunction(SetHint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetHint)
{
#if 0
	SDL_SetHint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetHint");
	return Value::Null;
}

// sdl2.SetHintWithPriority
Gura_DeclareFunction(SetHintWithPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetHintWithPriority)
{
#if 0
	SDL_SetHintWithPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetHintWithPriority");
	return Value::Null;
}

// sdl2.ClearError
Gura_DeclareFunction(ClearError)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ClearError)
{
	SDL_ClearError();
	return Value::Null;
}

// sdl2.GetError
Gura_DeclareFunction(GetError)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetError)
{
	const char *_rtn = SDL_GetError();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.SetError
Gura_DeclareFunction(SetError)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetError)
{
#if 0
	SDL_SetError();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetError");
	return Value::Null;
}

// sdl2.Log
Gura_DeclareFunction(Log)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Log)
{
#if 0
	SDL_Log();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Log");
	return Value::Null;
}

// sdl2.LogCritical
Gura_DeclareFunction(LogCritical)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogCritical)
{
#if 0
	SDL_LogCritical();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogCritical");
	return Value::Null;
}

// sdl2.LogDebug
Gura_DeclareFunction(LogDebug)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogDebug)
{
#if 0
	SDL_LogDebug();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogDebug");
	return Value::Null;
}

// sdl2.LogError
Gura_DeclareFunction(LogError)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogError)
{
#if 0
	SDL_LogError();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogError");
	return Value::Null;
}

// sdl2.LogGetOutputFunction
Gura_DeclareFunction(LogGetOutputFunction)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogGetOutputFunction)
{
#if 0
	SDL_LogGetOutputFunction();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogGetOutputFunction");
	return Value::Null;
}

// sdl2.LogGetPriority
Gura_DeclareFunction(LogGetPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogGetPriority)
{
#if 0
	SDL_LogGetPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogGetPriority");
	return Value::Null;
}

// sdl2.LogInfo
Gura_DeclareFunction(LogInfo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogInfo)
{
#if 0
	SDL_LogInfo();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogInfo");
	return Value::Null;
}

// sdl2.LogMessage
Gura_DeclareFunction(LogMessage)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogMessage)
{
#if 0
	SDL_LogMessage();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogMessage");
	return Value::Null;
}

// sdl2.LogMessageV
Gura_DeclareFunction(LogMessageV)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogMessageV)
{
#if 0
	SDL_LogMessageV();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogMessageV");
	return Value::Null;
}

// sdl2.LogResetPriorities
Gura_DeclareFunction(LogResetPriorities)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogResetPriorities)
{
#if 0
	SDL_LogResetPriorities();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogResetPriorities");
	return Value::Null;
}

// sdl2.LogSetAllPriority
Gura_DeclareFunction(LogSetAllPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogSetAllPriority)
{
#if 0
	SDL_LogSetAllPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogSetAllPriority");
	return Value::Null;
}

// sdl2.LogSetOutputFunction
Gura_DeclareFunction(LogSetOutputFunction)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogSetOutputFunction)
{
#if 0
	SDL_LogSetOutputFunction();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogSetOutputFunction");
	return Value::Null;
}

// sdl2.LogSetPriority
Gura_DeclareFunction(LogSetPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogSetPriority)
{
#if 0
	SDL_LogSetPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogSetPriority");
	return Value::Null;
}

// sdl2.LogVerbose
Gura_DeclareFunction(LogVerbose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogVerbose)
{
#if 0
	SDL_LogVerbose();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogVerbose");
	return Value::Null;
}

// sdl2.LogWarn
Gura_DeclareFunction(LogWarn)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LogWarn)
{
#if 0
	SDL_LogWarn();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogWarn");
	return Value::Null;
}

// sdl2.GetAssertionHandler
Gura_DeclareFunction(GetAssertionHandler)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAssertionHandler)
{
#if 0
	SDL_GetAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetAssertionHandler");
	return Value::Null;
}

// sdl2.GetAssertionReport
Gura_DeclareFunction(GetAssertionReport)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAssertionReport)
{
#if 0
	SDL_GetAssertionReport();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetAssertionReport");
	return Value::Null;
}

// sdl2.GetDefaultAssertionHandler
Gura_DeclareFunction(GetDefaultAssertionHandler)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDefaultAssertionHandler)
{
#if 0
	SDL_GetDefaultAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetDefaultAssertionHandler");
	return Value::Null;
}

// sdl2.ResetAssertionReport
Gura_DeclareFunction(ResetAssertionReport)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ResetAssertionReport)
{
#if 0
	SDL_ResetAssertionReport();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ResetAssertionReport");
	return Value::Null;
}

// sdl2.SetAssertionHandler
Gura_DeclareFunction(SetAssertionHandler)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetAssertionHandler)
{
#if 0
	SDL_SetAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetAssertionHandler");
	return Value::Null;
}

// sdl2.TriggerBreakpoint
Gura_DeclareFunction(TriggerBreakpoint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(TriggerBreakpoint)
{
#if 0
	SDL_TriggerBreakpoint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TriggerBreakpoint");
	return Value::Null;
}

// sdl2.assert
Gura_DeclareFunction(assert)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(assert)
{
#if 0
	SDL_assert();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "assert");
	return Value::Null;
}

// sdl2.assert_paranoid
Gura_DeclareFunction(assert_paranoid)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(assert_paranoid)
{
#if 0
	SDL_assert_paranoid();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "assert_paranoid");
	return Value::Null;
}

// sdl2.assert_release
Gura_DeclareFunction(assert_release)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(assert_release)
{
#if 0
	SDL_assert_release();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "assert_release");
	return Value::Null;
}

// sdl2.GetRevision
Gura_DeclareFunction(GetRevision)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRevision)
{
	const char *_rtn = SDL_GetRevision();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetRevisionNumber
Gura_DeclareFunction(GetRevisionNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRevisionNumber)
{
	int _rtn = SDL_GetRevisionNumber();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetVersion
Gura_DeclareFunction(GetVersion)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetVersion)
{
	SDL_version ver;
	SDL_GetVersion(&ver);
	return ReturnValue(env, sig, args, Value::CreateList(env,
					Value(ver.major), Value(ver.minor), Value(ver.patch)));
}

// sdl2.VERSION
Gura_DeclareFunction(VERSION)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(VERSION)
{
	SDL_version ver;
	SDL_VERSION(&ver);
	return ReturnValue(env, sig, args, Value::CreateList(env,
					Value(ver.major), Value(ver.minor), Value(ver.patch)));
}

// sdl2.VERSION_ATLEAST
Gura_DeclareFunction(VERSION_ATLEAST)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "X", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(VERSION_ATLEAST)
{
	int X = args.GetInt(0);
	int Y = args.GetInt(1);
	int Z = args.GetInt(2);
	bool _rtn = SDL_VERSION_ATLEAST(X, Y, Z);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateWindow
Gura_DeclareFunction(CreateWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateWindow)
{
	const char *title = args.GetString(0);
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int w = args.GetInt(3);
	int h = args.GetInt(4);
	Uint32 flags = args.GetULong(5);
	SDL_Window *_rtn = SDL_CreateWindow(title, x, y, w, h, flags);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Window(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateWindowAndRenderer
Gura_DeclareFunction(CreateWindowAndRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "window_flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateWindowAndRenderer)
{
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	Uint32 window_flags = args.GetULong(2);
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	int _rtn = SDL_CreateWindowAndRenderer(width, height, window_flags, &window, &renderer);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value::CreateList(env,
			Value(new Object_Window(window)), Value(new Object_Renderer(renderer))));
}

// sdl2.CreateWindowFrom
Gura_DeclareFunction(CreateWindowFrom)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateWindowFrom)
{
#if 0
	SDL_CreateWindowFrom();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateWindowFrom");
	return Value::Null;
}

// sdl2.DestroyWindow
Gura_DeclareFunction(DestroyWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DestroyWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_DestroyWindow(window);
	return Value::Null;
}

// sdl2.DisableScreenSaver
Gura_DeclareFunction(DisableScreenSaver)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DisableScreenSaver)
{
	SDL_DisableScreenSaver();
	return Value::Null;
}

// sdl2.EnableScreenSaver
Gura_DeclareFunction(EnableScreenSaver)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(EnableScreenSaver)
{
	SDL_EnableScreenSaver();
	return Value::Null;
}

// sdl2.GL_CreateContext
Gura_DeclareFunction(GL_CreateContext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_CreateContext)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_GLContext _rtn = SDL_GL_CreateContext(window);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_GLContext(_rtn)));
}

// sdl2.GL_DeleteContext
Gura_DeclareFunction(GL_DeleteContext)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "context", VTYPE_GLContext, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_DeleteContext)
{
	SDL_GLContext context = Object_GLContext::GetObject(args, 0)->GetEntity();
	SDL_GL_DeleteContext(context);
	return Value::Null;
}

// sdl2.GL_ExtensionSupported
Gura_DeclareFunction(GL_ExtensionSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_ExtensionSupported)
{
	const char *extension = args.GetString(0);
	SDL_bool _rtn = SDL_GL_ExtensionSupported(extension);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GL_GetAttribute
Gura_DeclareFunction(GL_GetAttribute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "attr", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetAttribute)
{
	SDL_GLattr attr = static_cast<SDL_GLattr>(args.GetInt(0));
	int value = 0;
	int _rtn = SDL_GL_GetAttribute(attr, &value);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(value));
}

// sdl2.GL_GetCurrentContext
Gura_DeclareFunction(GL_GetCurrentContext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetCurrentContext)
{
	SDL_GLContext _rtn = SDL_GL_GetCurrentContext();
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_GLContext(_rtn)));
}

// sdl2.GL_GetCurrentWindow
Gura_DeclareFunction(GL_GetCurrentWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetCurrentWindow)
{
	SDL_Window *_rtn = SDL_GL_GetCurrentWindow();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Window(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GL_GetDrawableSize
Gura_DeclareFunction(GL_GetDrawableSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetDrawableSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GL_GetDrawableSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GL_GetProcAddress
Gura_DeclareFunction(GL_GetProcAddress)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetProcAddress)
{
#if 0
	SDL_GL_GetProcAddress();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GL_GetProcAddress");
	return Value::Null;
}

// sdl2.GL_GetSwapInterval
Gura_DeclareFunction(GL_GetSwapInterval)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetSwapInterval)
{
	int _rtn = SDL_GL_GetSwapInterval();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.GL_LoadLibrary
Gura_DeclareFunction(GL_LoadLibrary)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_LoadLibrary)
{
	const char *path = args.GetString(0);
	int _rtn = SDL_GL_LoadLibrary(path);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.GL_MakeCurrent
Gura_DeclareFunction(GL_MakeCurrent)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "context", VTYPE_GLContext, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_MakeCurrent)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_GLContext context = Object_GLContext::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_GL_MakeCurrent(window, context);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.GL_ResetAttributes
Gura_DeclareFunction(GL_ResetAttributes)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_ResetAttributes)
{
	SDL_GL_ResetAttributes();
	return Value::Null;
}

// sdl2.GL_SetAttribute
Gura_DeclareFunction(GL_SetAttribute)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "attr", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_SetAttribute)
{
	SDL_GLattr attr = static_cast<SDL_GLattr>(args.GetInt(0));
	int value = args.GetInt(1);
	int _rtn = SDL_GL_SetAttribute(attr, value);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.GL_SetSwapInterval
Gura_DeclareFunction(GL_SetSwapInterval)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "interval", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_SetSwapInterval)
{
	int interval = args.GetInt(0);
	int _rtn = SDL_GL_SetSwapInterval(interval);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.GL_SwapWindow
Gura_DeclareFunction(GL_SwapWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_SwapWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_GL_SwapWindow(window);
	return Value::Null;
}

// sdl2.GL_UnloadLibrary
Gura_DeclareFunction(GL_UnloadLibrary)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_UnloadLibrary)
{
	SDL_GL_UnloadLibrary();
	return Value::Null;
}

// sdl2.GetClosestDisplayMode
Gura_DeclareFunction(GetClosestDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetClosestDisplayMode)
{
	int displayIndex = args.GetInt(0);
	const SDL_DisplayMode *mode = Object_DisplayMode::GetObject(args, 1)->GetEntity();
	SDL_DisplayMode closest;
	SDL_DisplayMode* _rtn = SDL_GetClosestDisplayMode(displayIndex, mode, &closest);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_DisplayMode(closest)));
}

// sdl2.GetCurrentDisplayMode
Gura_DeclareFunction(GetCurrentDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCurrentDisplayMode)
{
	int displayIndex = args.GetInt(0);
	SDL_DisplayMode mode;
	int _rtn = SDL_GetCurrentDisplayMode(displayIndex, &mode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_DisplayMode(mode)));
}

// sdl2.GetCurrentVideoDriver
Gura_DeclareFunction(GetCurrentVideoDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCurrentVideoDriver)
{
	const char *_rtn = SDL_GetCurrentVideoDriver();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetDesktopDisplayMode
Gura_DeclareFunction(GetDesktopDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDesktopDisplayMode)
{
	int displayIndex = args.GetInt(0);
	SDL_DisplayMode mode;
	int _rtn = SDL_GetDesktopDisplayMode(displayIndex, &mode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_DisplayMode(mode)));
}

// sdl2.GetDisplayBounds
Gura_DeclareFunction(GetDisplayBounds)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDisplayBounds)
{
	int displayIndex = args.GetInt(0);
	SDL_Rect rect;
	int _rtn = SDL_GetDisplayBounds(displayIndex, &rect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.GetDisplayMode
Gura_DeclareFunction(GetDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "modeIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDisplayMode)
{
	int displayIndex = args.GetInt(0);
	int modeIndex = args.GetInt(1);
	SDL_DisplayMode mode;
	int _rtn = SDL_GetDisplayMode(displayIndex, modeIndex, &mode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_DisplayMode(mode)));
}

// sdl2.GetDisplayName
Gura_DeclareFunction(GetDisplayName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dipslayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDisplayName)
{
	int dipslayIndex = args.GetInt(0);
	const char *_rtn = SDL_GetDisplayName(dipslayIndex);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetNumDisplayModes
Gura_DeclareFunction(GetNumDisplayModes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumDisplayModes)
{
	int displayIndex = args.GetInt(0);
	int _rtn = SDL_GetNumDisplayModes(displayIndex);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetNumVideoDisplays
Gura_DeclareFunction(GetNumVideoDisplays)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumVideoDisplays)
{
	int _rtn = SDL_GetNumVideoDisplays();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetNumVideoDrivers
Gura_DeclareFunction(GetNumVideoDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumVideoDrivers)
{
	int _rtn = SDL_GetNumVideoDrivers();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetVideoDriver
Gura_DeclareFunction(GetVideoDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetVideoDriver)
{
	int index = args.GetInt(0);
	const char *_rtn = SDL_GetVideoDriver(index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowBrightness
Gura_DeclareFunction(GetWindowBrightness)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowBrightness)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	float _rtn = SDL_GetWindowBrightness(window);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowData
Gura_DeclareFunction(GetWindowData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowData)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *name = args.GetString(1);
	SDL_GetWindowData(window, name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetWindowData");
	return Value::Null;
}

// sdl2.GetWindowDisplayIndex
Gura_DeclareFunction(GetWindowDisplayIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowDisplayIndex)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_GetWindowDisplayIndex(window);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetWindowDisplayMode
Gura_DeclareFunction(GetWindowDisplayMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowDisplayMode)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_DisplayMode *mode = Object_DisplayMode::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_GetWindowDisplayMode(window, mode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.GetWindowFlags
Gura_DeclareFunction(GetWindowFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowFlags)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowFlags(window);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowFromID
Gura_DeclareFunction(GetWindowFromID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowFromID)
{
	Uint32 id = args.GetULong(0);
	SDL_Window *_rtn = SDL_GetWindowFromID(id);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Window(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowGammaRamp
Gura_DeclareFunction(GetWindowGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowGammaRamp)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint16 red = 0;
	Uint16 green = 0;
	Uint16 blue = 0;
	int _rtn = SDL_GetWindowGammaRamp(window, &red, &green, &blue);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value::CreateList(env,
								Value(red), Value(green), Value(blue)));
}

// sdl2.GetWindowGrab
Gura_DeclareFunction(GetWindowGrab)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowGrab)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_GetWindowGrab(window);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowID
Gura_DeclareFunction(GetWindowID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowID)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowID(window);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowMaximumSize
Gura_DeclareFunction(GetWindowMaximumSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowMaximumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowMaximumSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GetWindowMinimumSize
Gura_DeclareFunction(GetWindowMinimumSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowMinimumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowMinimumSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GetWindowPixelFormat
Gura_DeclareFunction(GetWindowPixelFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowPixelFormat)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowPixelFormat(window);
	if (_rtn == SDL_PIXELFORMAT_UNKNOWN) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetWindowPosition
Gura_DeclareFunction(GetWindowPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowPosition)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = 0;
	int y = 0;
	SDL_GetWindowPosition(window, &x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(x), Value(y)));
}

// sdl2.GetWindowSize
Gura_DeclareFunction(GetWindowSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GetWindowSurface
Gura_DeclareFunction(GetWindowSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowSurface)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_Surface *_rtn = SDL_GetWindowSurface(window);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Surface(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowTitle
Gura_DeclareFunction(GetWindowTitle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowTitle)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GetWindowTitle(window);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetWindowWMInfo
Gura_DeclareFunction(GetWindowWMInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetWindowWMInfo)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_SysWMinfo info;
	SDL_bool _rtn = SDL_GetWindowWMInfo(window, &info);
	if (_rtn != SDL_TRUE) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_SysWMinfo(info)));
#endif
	SetError_NotImpFunction(sig, "GetWindowWMInfo");
	return Value::Null;
}

// sdl2.HideWindow
Gura_DeclareFunction(HideWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HideWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_HideWindow(window);
	return Value::Null;
}

// sdl2.IsScreenSaverEnabled
Gura_DeclareFunction(IsScreenSaverEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(IsScreenSaverEnabled)
{
	SDL_bool _rtn = SDL_IsScreenSaverEnabled();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.MaximizeWindow
Gura_DeclareFunction(MaximizeWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MaximizeWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_MaximizeWindow(window);
	return Value::Null;
}

// sdl2.MinimizeWindow
Gura_DeclareFunction(MinimizeWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MinimizeWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_MinimizeWindow(window);
	return Value::Null;
}

// sdl2.RaiseWindow
Gura_DeclareFunction(RaiseWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RaiseWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_RaiseWindow(window);
	return Value::Null;
}

// sdl2.RestoreWindow
Gura_DeclareFunction(RestoreWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RestoreWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_RestoreWindow(window);
	return Value::Null;
}

// sdl2.SetWindowBordered
Gura_DeclareFunction(SetWindowBordered)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bordered", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowBordered)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool bordered = (args.GetBoolean(1)? SDL_TRUE : SDL_FALSE);
	SDL_SetWindowBordered(window, bordered);
	return Value::Null;
}

// sdl2.SetWindowBrightness
Gura_DeclareFunction(SetWindowBrightness)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowBrightness)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	float brightness = args.GetFloat(1);
	int _rtn = SDL_SetWindowBrightness(window, brightness);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetWindowData
Gura_DeclareFunction(SetWindowData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowData)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *name = args.GetString(1);
	void *userdata = NULL;
	SDL_SetWindowData(window, name, userdata);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetWindowData");
	return Value::Null;
}

// sdl2.SetWindowDisplayMode
Gura_DeclareFunction(SetWindowDisplayMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowDisplayMode)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const SDL_DisplayMode *mode = Object_DisplayMode::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_SetWindowDisplayMode(window, mode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetWindowFullscreen
Gura_DeclareFunction(SetWindowFullscreen)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowFullscreen)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 flags = args.GetULong(1);
	int _rtn = SDL_SetWindowFullscreen(window, flags);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetWindowGammaRamp
Gura_DeclareFunction(SetWindowGammaRamp)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowGammaRamp)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	CArray<Uint16> red(args.GetList(1));
	CArray<Uint16> green(args.GetList(2));
	CArray<Uint16> blue(args.GetList(3));
	if (red.GetSize() != 256 || green.GetSize() != 256 || blue.GetSize() != 256) {
		sig.SetError(ERR_ValueError, "red, green and blue must have 256 elements");
		return Value::Null;
	}
	int _rtn = SDL_SetWindowGammaRamp(window, red, green, blue);
	if (_rtn != SDL_TRUE) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetWindowGrab
Gura_DeclareFunction(SetWindowGrab)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "grabbed", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowGrab)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool grabbed = (args.GetBoolean(1)? SDL_TRUE : SDL_FALSE);
	SDL_SetWindowGrab(window, grabbed);
	return Value::Null;
}

// sdl2.SetWindowHitTest
Gura_DeclareFunction(SetWindowHitTest)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowHitTest)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_HitTest callback = NULL;
	void *callback_data = NULL;
	int _rtn = SDL_SetWindowHitTest(window, callback, callback_data);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetWindowHitTest");
	return Value::Null;
}

// sdl2.SetWindowIcon
Gura_DeclareFunction(SetWindowIcon)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "icon", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowIcon)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_Surface *icon = Object_Surface::GetObject(args, 1)->GetEntity();
	SDL_SetWindowIcon(window, icon);
	return Value::Null;
}

// sdl2.SetWindowMaximumSize
Gura_DeclareFunction(SetWindowMaximumSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "max_w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "max_h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowMaximumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int max_w = args.GetInt(1);
	int max_h = args.GetInt(2);
	SDL_SetWindowMaximumSize(window, max_w, max_h);
	return Value::Null;
}

// sdl2.SetWindowMinimumSize
Gura_DeclareFunction(SetWindowMinimumSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "min_w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "min_h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowMinimumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int min_w = args.GetInt(1);
	int min_h = args.GetInt(2);
	SDL_SetWindowMinimumSize(window, min_w, min_h);
	return Value::Null;
}

// sdl2.SetWindowPosition
Gura_DeclareFunction(SetWindowPosition)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowPosition)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	SDL_SetWindowPosition(window, x, y);
	return Value::Null;
}

// sdl2.SetWindowSize
Gura_DeclareFunction(SetWindowSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = args.GetInt(1);
	int h = args.GetInt(2);
	SDL_SetWindowSize(window, w, h);
	return Value::Null;
}

// sdl2.SetWindowTitle
Gura_DeclareFunction(SetWindowTitle)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetWindowTitle)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *title = args.GetString(1);
	SDL_SetWindowTitle(window, title);
	return Value::Null;
}

// sdl2.ShowMessageBox
Gura_DeclareFunction(ShowMessageBox)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ShowMessageBox)
{
#if 0
	const SDL_MessageBoxData *messageboxdata = NULL;
	int *buttonid = NULL;
	int _rtn = SDL_ShowMessageBox(messageboxdata, buttonid);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ShowMessageBox");
	return Value::Null;
}

// sdl2.ShowSimpleMessageBox
Gura_DeclareFunction(ShowSimpleMessageBox)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ShowSimpleMessageBox)
{
	Uint32 flags = args.GetULong(0);
	const char *title = args.GetString(1);
	const char *message = args.GetString(2);
	SDL_Window *window = Object_Window::GetObject(args, 3)->GetEntity();
	int _rtn = SDL_ShowSimpleMessageBox(flags, title, message, window);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.ShowWindow
Gura_DeclareFunction(ShowWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ShowWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_ShowWindow(window);
	return Value::Null;
}

// sdl2.UpdateWindowSurface
Gura_DeclareFunction(UpdateWindowSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UpdateWindowSurface)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_UpdateWindowSurface(window);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.UpdateWindowSurfaceRects
Gura_DeclareFunction(UpdateWindowSurfaceRects)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UpdateWindowSurfaceRects)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int numrects = static_cast<int>(rects.GetSize());
	int _rtn = SDL_UpdateWindowSurfaceRects(window, rects, numrects);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.VideoInit
Gura_DeclareFunction(VideoInit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "driver_name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(VideoInit)
{
	const char *driver_name = args.GetString(0);
	int _rtn = SDL_VideoInit(driver_name);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.VideoQuit
Gura_DeclareFunction(VideoQuit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(VideoQuit)
{
	SDL_VideoQuit();
	return Value::Null;
}

// sdl2.CreateRenderer
Gura_DeclareFunction(CreateRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateRenderer)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int index = args.GetInt(1);
	Uint32 flags = args.GetULong(2);
	SDL_Renderer *_rtn = SDL_CreateRenderer(window, index, flags);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Renderer(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateSoftwareRenderer
Gura_DeclareFunction(CreateSoftwareRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateSoftwareRenderer)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Renderer *_rtn = SDL_CreateSoftwareRenderer(surface);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Renderer(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateTexture
Gura_DeclareFunction(CreateTexture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "access", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateTexture)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	Uint32 format = args.GetULong(1);
	int access = args.GetInt(2);
	int w = args.GetInt(3);
	int h = args.GetInt(4);
	SDL_Texture *_rtn = SDL_CreateTexture(renderer, format, access, w, h);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Texture(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateTextureFromSurface
Gura_DeclareFunction(CreateTextureFromSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateTextureFromSurface)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Surface *surface = Object_Surface::GetObject(args, 1)->GetEntity();
	SDL_Texture *_rtn = SDL_CreateTextureFromSurface(renderer, surface);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Texture(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.DestroyRenderer
Gura_DeclareFunction(DestroyRenderer)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DestroyRenderer)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_DestroyRenderer(renderer);
	return Value::Null;
}

// sdl2.DestroyTexture
Gura_DeclareFunction(DestroyTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DestroyTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_DestroyTexture(texture);
	return Value::Null;
}

// sdl2.GL_BindTexture
Gura_DeclareFunction(GL_BindTexture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_BindTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	float texw = 0;
	float texh = 0;
	SDL_GL_BindTexture(texture, &texw, &texh);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(texw), Value(texh)));
}

// sdl2.GL_UnbindTexture
Gura_DeclareFunction(GL_UnbindTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_UnbindTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_GL_UnbindTexture(texture);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.GetNumRenderDrivers
Gura_DeclareFunction(GetNumRenderDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumRenderDrivers)
{
	int _rtn = SDL_GetNumRenderDrivers();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetRenderDrawBlendMode
Gura_DeclareFunction(GetRenderDrawBlendMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderDrawBlendMode)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
	int _rtn = SDL_GetRenderDrawBlendMode(renderer, &blendMode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(blendMode));
}

// sdl2.GetRenderDrawColor
Gura_DeclareFunction(GetRenderDrawColor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderDrawColor)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	Uint8 a = 0;
	int _rtn = SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value::CreateList(env,
								Value(r), Value(g), Value(b), Value(a)));
}

// sdl2.GetRenderDriverInfo
Gura_DeclareFunction(GetRenderDriverInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderDriverInfo)
{
	int index = args.GetInt(0);
	SDL_RendererInfo info;
	int _rtn = SDL_GetRenderDriverInfo(index, &info);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_RendererInfo(info)));
}

// sdl2.GetRenderTarget
Gura_DeclareFunction(GetRenderTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderTarget)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Texture *_rtn = SDL_GetRenderTarget(renderer);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Texture(_rtn));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetRenderer
Gura_DeclareFunction(GetRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderer)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_Renderer *_rtn = SDL_GetRenderer(window);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Renderer(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetRendererInfo
Gura_DeclareFunction(GetRendererInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRendererInfo)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_RendererInfo info;
	int _rtn = SDL_GetRendererInfo(renderer, &info);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_RendererInfo(info)));
}

// sdl2.GetRenderOutputSize
Gura_DeclareFunction(GetRenderOutputSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderOutputSize)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	int _rtn = SDL_GetRendererOutputSize(renderer, &w, &h);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GetTextureAlphaMod
Gura_DeclareFunction(GetTextureAlphaMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetTextureAlphaMod)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	Uint8 alpha = 0;
	int _rtn = SDL_GetTextureAlphaMod(texture, &alpha);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(alpha));
}

// sdl2.GetTextureBlendMode
Gura_DeclareFunction(GetTextureBlendMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetTextureBlendMode)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
	int _rtn = SDL_GetTextureBlendMode(texture, &blendMode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(blendMode));
}

// sdl2.GetTextureColorMod
Gura_DeclareFunction(GetTextureColorMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetTextureColorMod)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	int _rtn = SDL_GetTextureColorMod(texture, &r, &g, &b);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value::CreateList(env,
											Value(r), Value(g), Value(b)));
}

// sdl2.LockTexture
Gura_DeclareFunction(LockTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LockTexture)
{
#if 0
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = Object_Rect::GetObject(args, 1)->GetEntity();
	void **pixels = NULL;
	int *pitch = NULL;
	int _rtn = SDL_LockTexture(texture, rect, pixels, pitch);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LockTexture");
	return Value::Null;
}

// sdl2.QueryTexture
Gura_DeclareFunction(QueryTexture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(QueryTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	Uint32 format = 0;
	int access = 0;
	int w = 0;
	int h = 0;
	int _rtn = SDL_QueryTexture(texture, &format, &access, &w, &h);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value::CreateList(env,
							Value(format), Value(access), Value(w), Value(h)));
}

// sdl2.RenderClear
Gura_DeclareFunction(RenderClear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderClear)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_RenderClear(renderer);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderCopy
Gura_DeclareFunction(RenderCopy)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderCopy)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Texture *texture = Object_Texture::GetObject(args, 1)->GetEntity();
	const SDL_Rect *srcrect = args.IsValid(2)? Object_Rect::GetObject(args, 2)->GetEntity() : NULL;
	const SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int _rtn = SDL_RenderCopy(renderer, texture, srcrect, dstrect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderCopyEx
Gura_DeclareFunction(RenderCopyEx)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "center", VTYPE_Point, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "flip", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderCopyEx)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Texture *texture = Object_Texture::GetObject(args, 1)->GetEntity();
	const SDL_Rect *srcrect = args.IsValid(2)? Object_Rect::GetObject(args, 2)->GetEntity() : NULL;
	const SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	double angle = args.GetDouble(4);
	const SDL_Point *center = args.IsValid(5)? Object_Point::GetObject(args, 5)->GetEntity() : NULL;
	SDL_RendererFlip flip = static_cast<SDL_RendererFlip>(args.GetInt(6));
	int _rtn = SDL_RenderCopyEx(renderer, texture, srcrect, dstrect, angle, center, flip);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderDrawLine
Gura_DeclareFunction(RenderDrawLine)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderDrawLine)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int x1 = args.GetInt(1);
	int y1 = args.GetInt(2);
	int x2 = args.GetInt(3);
	int y2 = args.GetInt(4);
	int _rtn = SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderDrawLines
Gura_DeclareFunction(RenderDrawLines)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderDrawLines)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Point> points(CreateCArray<SDL_Point, Object_Point>(args.GetList(1)));
	int count = static_cast<int>(points.GetSize());
	int _rtn = SDL_RenderDrawLines(renderer, points, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderDrawPoint
Gura_DeclareFunction(RenderDrawPoint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderDrawPoint)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int _rtn = SDL_RenderDrawPoint(renderer, x, y);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderDrawPoints
Gura_DeclareFunction(RenderDrawPoints)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderDrawPoints)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Point> points(CreateCArray<SDL_Point, Object_Point>(args.GetList(1)));
	int count = static_cast<int>(points.GetSize());
	int _rtn = SDL_RenderDrawPoints(renderer, points, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderDrawRect
Gura_DeclareFunction(RenderDrawRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderDrawRect)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int _rtn = SDL_RenderDrawRect(renderer, rect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderDrawRects
Gura_DeclareFunction(RenderDrawRects)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderDrawRects)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int count = static_cast<int>(rects.GetSize());
	int _rtn = SDL_RenderDrawRects(renderer, rects, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderFillRect
Gura_DeclareFunction(RenderFillRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderFillRect)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int _rtn = SDL_RenderFillRect(renderer, rect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderFillRects
Gura_DeclareFunction(RenderFillRects)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderFillRects)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int count = static_cast<int>(rects.GetSize());
	int _rtn = SDL_RenderFillRects(renderer, rects, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderGetClipRect
Gura_DeclareFunction(RenderGetClipRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderGetClipRect)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_RenderGetClipRect(renderer, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.RenderGetLogicalSize
Gura_DeclareFunction(RenderGetLogicalSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderGetLogicalSize)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_RenderGetLogicalSize(renderer, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.RenderGetScale
Gura_DeclareFunction(RenderGetScale)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderGetScale)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	float scaleX = 0;
	float scaleY = 0;
	SDL_RenderGetScale(renderer, &scaleX, &scaleY);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(scaleX), Value(scaleY)));
}

// sdl2.RenderGetViewport
Gura_DeclareFunction(RenderGetViewport)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderGetViewport)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_RenderGetViewport(renderer, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.RenderIsClipEnabled
Gura_DeclareFunction(RenderIsClipEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderIsClipEnabled)
{
#if 0
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RenderIsClipEnabled(renderer);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "RenderIsClipEnabled");
	return Value::Null;
}

// sdl2.RenderPresent
Gura_DeclareFunction(RenderPresent)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderPresent)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_RenderPresent(renderer);
	return Value::Null;
}

// sdl2.RenderReadPixels
Gura_DeclareFunction(RenderReadPixels)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderReadPixels)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	Uint32 format = SDL_PIXELFORMAT_UNKNOWN;
	Image::Format fmtImage = Image::FORMAT_None;
	const Symbol *pSymbol = args.GetSymbol(2);
	if (pSymbol->IsIdentical(Gura_Symbol(rgb))) {
		format = SDL_PIXELFORMAT_BGR888;
		fmtImage = Image::FORMAT_RGB;
	} else if (pSymbol->IsIdentical(Gura_Symbol(rgba))) {
		format = SDL_PIXELFORMAT_BGRA8888;
		fmtImage = Image::FORMAT_RGBA;
	} else {
		sig.SetError(ERR_ValueError, "format must be `rgb or `rgba");
		return Value::Null;
	}
	AutoPtr<Image> pImage(new Image(fmtImage));
	if (!pImage->AllocBuffer(sig, rect->w, rect->h, 0x00)) return Value::Null;
	void *pixels = pImage->GetBuffer();
	int pitch = pImage->GetBytesPerLine();
	int _rtn = SDL_RenderReadPixels(renderer, rect, format, pixels, pitch);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// sdl2.RenderSetClipRect
Gura_DeclareFunction(RenderSetClipRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderSetClipRect)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int _rtn = SDL_RenderSetClipRect(renderer, rect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderSetLogicalSize
Gura_DeclareFunction(RenderSetLogicalSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderSetLogicalSize)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int w = args.GetInt(1);
	int h = args.GetInt(2);
	int _rtn = SDL_RenderSetLogicalSize(renderer, w, h);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderSetScale
Gura_DeclareFunction(RenderSetScale)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "scaleX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "scaleY", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderSetScale)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	float scaleX = args.GetFloat(1);
	float scaleY = args.GetFloat(2);
	int _rtn = SDL_RenderSetScale(renderer, scaleX, scaleY);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderSetViewport
Gura_DeclareFunction(RenderSetViewport)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderSetViewport)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int _rtn = SDL_RenderSetViewport(renderer, rect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.RenderTargetSupported
Gura_DeclareFunction(RenderTargetSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderTargetSupported)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RenderTargetSupported(renderer);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.SetRenderDrawBlendMode
Gura_DeclareFunction(SetRenderDrawBlendMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetRenderDrawBlendMode)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = static_cast<SDL_BlendMode>(args.GetInt(1));
	SDL_SetRenderDrawBlendMode(renderer, blendMode);
	return Value::Null;
}

// sdl2.SetRenderDrawColor
Gura_DeclareFunction(SetRenderDrawColor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "a", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetRenderDrawColor)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint8 a = args.GetUChar(4);
	int _rtn = SDL_SetRenderDrawColor(renderer, r, g, b, a);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetRenderTarget
Gura_DeclareFunction(SetRenderTarget)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetRenderTarget)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Texture *texture = args.IsValid(1)? Object_Texture::GetObject(args, 1)->GetEntity() : NULL;
	int _rtn = SDL_SetRenderTarget(renderer, texture);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetTextureAlphaMod
Gura_DeclareFunction(SetTextureAlphaMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetTextureAlphaMod)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	Uint8 alpha = args.GetUChar(1);
	int _rtn = SDL_SetTextureAlphaMod(texture, alpha);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetTextureBlendMode
Gura_DeclareFunction(SetTextureBlendMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetTextureBlendMode)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = static_cast<SDL_BlendMode>(args.GetInt(1));
	int _rtn = SDL_SetTextureBlendMode(texture, blendMode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetTextureColorMod
Gura_DeclareFunction(SetTextureColorMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetTextureColorMod)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	int _rtn = SDL_SetTextureColorMod(texture, r, g, b);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.UnlockTexture
Gura_DeclareFunction(UnlockTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UnlockTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_UnlockTexture(texture);
	return Value::Null;
}

// sdl2.UpdateTexture
Gura_DeclareFunction(UpdateTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "pitch", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UpdateTexture)
{
#if 0
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	const void *pixels = NULL;
	int pitch = args.GetInt(3);
	int _rtn = SDL_UpdateTexture(texture, rect, pixels, pitch);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "UpdateTexture");
	return Value::Null;
}

// sdl2.UpdateYUVTexture
Gura_DeclareFunction(UpdateYUVTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "Yplane", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Ypitch", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Uplane", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Upitch", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Vplane", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Vpitch", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UpdateYUVTexture)
{
#if 0
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	const Uint8 *Yplane = args.GetList(2);
	int Ypitch = args.GetInt(3);
	const Uint8 *Uplane = args.GetList(4);
	int Upitch = args.GetInt(5);
	const Uint8 *Vplane = args.GetList(6);
	int Vpitch = args.GetInt(7);
	int _rtn = SDL_UpdateYUVTexture(texture, rect, Yplane, Ypitch, Uplane, Upitch, Vplane, Vpitch);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "UpdateYUVTexture");
	return Value::Null;
}

// sdl2.AllocFormat
Gura_DeclareFunction(AllocFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel_format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AllocFormat)
{
	Uint32 pixel_format = args.GetULong(0);
	SDL_PixelFormat *_rtn = SDL_AllocFormat(pixel_format);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_PixelFormat(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.AllocPalette
Gura_DeclareFunction(AllocPalette)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "ncolors", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AllocPalette)
{
	int ncolors = args.GetInt(0);
	SDL_Palette *_rtn = SDL_AllocPalette(ncolors);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Palette(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CalculateGammaRamp
Gura_DeclareFunction(CalculateGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamma", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CalculateGammaRamp)
{
	float gamma = args.GetFloat(0);
	Uint16 ramp[256];
	SDL_CalculateGammaRamp(gamma, ramp);
	return ReturnValue(env, sig, args, Value::CreateList(env, ramp, ArraySizeOf(ramp)));
}

// sdl2.FreeFormat
Gura_DeclareFunction(FreeFormat)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FreeFormat)
{
	SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	SDL_FreeFormat(format);
	return Value::Null;
}

// sdl2.FreePalette
Gura_DeclareFunction(FreePalette)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FreePalette)
{
	SDL_Palette *palette = Object_Palette::GetObject(args, 0)->GetEntity();
	SDL_FreePalette(palette);
	return Value::Null;
}

// sdl2.GetPixelFormatName
Gura_DeclareFunction(GetPixelFormatName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetPixelFormatName)
{
	Uint32 format = args.GetULong(0);
	const char *_rtn = SDL_GetPixelFormatName(format);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetRGB
Gura_DeclareFunction(GetRGB)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRGB)
{
	Uint32 pixel = args.GetULong(0);
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 1)->GetEntity();
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	SDL_GetRGB(pixel, format, &r, &g, &b);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(r), Value(g), Value(b)));
}

// sdl2.GetRGBA
Gura_DeclareFunction(GetRGBA)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRGBA)
{
	Uint32 pixel = args.GetULong(0);
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 1)->GetEntity();
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	Uint8 a = 0;
	SDL_GetRGBA(pixel, format, &r, &g, &b, &a);
	return ReturnValue(env, sig, args,
			Value::CreateList(env, Value(r), Value(g), Value(b), Value(a)));
}

// sdl2.MapRGB
Gura_DeclareFunction(MapRGB)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MapRGB)
{
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint32 _rtn = SDL_MapRGB(format, r, g, b);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.MapRGBA
Gura_DeclareFunction(MapRGBA)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "a", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MapRGBA)
{
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint8 a = args.GetUChar(4);
	Uint32 _rtn = SDL_MapRGBA(format, r, g, b, a);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.MasksToPixelFormatEnum
Gura_DeclareFunction(MasksToPixelFormatEnum)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "bpp", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Rmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Gmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Bmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Amask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MasksToPixelFormatEnum)
{
	int bpp = args.GetInt(0);
	Uint32 Rmask = args.GetULong(1);
	Uint32 Gmask = args.GetULong(2);
	Uint32 Bmask = args.GetULong(3);
	Uint32 Amask = args.GetULong(4);
	Uint32 _rtn = SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.PixelFormatEnumToMasks
Gura_DeclareFunction(PixelFormatEnumToMasks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PixelFormatEnumToMasks)
{
	Uint32 format = args.GetULong(0);
	int bpp = 0;
	Uint32 Rmask = 0;
	Uint32 Gmask = 0;
	Uint32 Bmask = 0;
	Uint32 Amask = 0;
	SDL_bool _rtn = SDL_PixelFormatEnumToMasks(format, &bpp, &Rmask, &Gmask, &Bmask, &Amask);
	if (_rtn != SDL_TRUE) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args,
			Value::CreateList(env, Value(bpp), Value(Rmask), Value(Gmask), Value(Bmask), Value(Amask)));
}

// sdl2.SetPaletteColors
Gura_DeclareFunction(SetPaletteColors)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	DeclareArg(env, "colors", VTYPE_Color, OCCUR_Once, FLAG_List);
	DeclareArg(env, "firstcolor", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ncolors", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetPaletteColors)
{
	SDL_Palette *palette = Object_Palette::GetObject(args, 0)->GetEntity();
	int firstcolor = args.GetInt(2);
	int ncolors = args.GetInt(3);
	CArray<SDL_Color> colors(CreateCArray<SDL_Color, Object_Color>(args.GetList(1)));
	int nmax = static_cast<int>(colors.GetSize());
	if (firstcolor + ncolors > nmax) {
		sig.SetError(ERR_IndexError, "out of range");
		return Value::Null;
	}
	int _rtn = SDL_SetPaletteColors(palette, colors, firstcolor, ncolors);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetPixelFormatPalette
Gura_DeclareFunction(SetPixelFormatPalette)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetPixelFormatPalette)
{
	SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	SDL_Palette *palette = Object_Palette::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_SetPixelFormatPalette(format, palette);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.EnclosePoints
Gura_DeclareFunction(EnclosePoints)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "clip", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(EnclosePoints)
{
	const SDL_Rect *clip = Object_Rect::GetObject(args, 1)->GetEntity();
	CArray<SDL_Point> points(CreateCArray<SDL_Point, Object_Point>(args.GetList(0)));
	int count = static_cast<int>(points.GetSize());
	SDL_Rect result;
	SDL_bool _rtn = SDL_EnclosePoints(points, count, clip, &result);
	Value _rtnVal;
	if (_rtn == SDL_TRUE) {
		_rtnVal = Value(new Object_Rect(result));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasIntersection
Gura_DeclareFunction(HasIntersection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasIntersection)
{
	const SDL_Rect *A = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *B = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_HasIntersection(A, B);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.IntersectRect
Gura_DeclareFunction(IntersectRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(IntersectRect)
{
	const SDL_Rect *A = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *B = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_Rect result;
	SDL_bool _rtn = SDL_IntersectRect(A, B, &result);
	Value _rtnVal;
	if (_rtn == SDL_TRUE) {
		_rtnVal = Value(new Object_Rect(result));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.IntersectRectAndLine
Gura_DeclareFunction(IntersectRectAndLine)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "X1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "X2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(IntersectRectAndLine)
{
#if 0
	const SDL_Rect *rect = Object_Rect::GetObject(args, 0)->GetEntity();
	int X1 = args.GetInt(1);
	int Y1 = args.GetInt(2);
	int X2 = args.GetInt(3);
	int Y2 = args.GetInt(4);
	SDL_bool _rtn = SDL_IntersectRectAndLine(rect, X1, Y1, X2, Y2);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "IntersectRectAndLine");
	return Value::Null;
}

// sdl2.PointInRect
Gura_DeclareFunction(PointInRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "p", VTYPE_Point, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PointInRect)
{
#if 0
	const SDL_Point *p = Object_Point::GetObject(args, 0)->GetEntity();
	const SDL_Rect *r = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_PointInRect(p, r);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "PointInRect");
	return Value::Null;
}

// sdl2.RectEmpty
Gura_DeclareFunction(RectEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "r", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RectEmpty)
{
	const SDL_Rect *r = Object_Rect::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RectEmpty(r);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.RectEquals
Gura_DeclareFunction(RectEquals)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "a", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RectEquals)
{
	const SDL_Rect *a = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *b = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_RectEquals(a, b);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.UnionRect
Gura_DeclareFunction(UnionRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UnionRect)
{
	const SDL_Rect *A = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *B = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_Rect result;
	SDL_UnionRect(A, B, &result);
	Value _rtnVal = Value(new Object_Rect(result));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.BlitScaled
Gura_DeclareFunction(BlitScaled)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(BlitScaled)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = Object_Surface::GetObject(args, 2)->GetEntity();
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int _rtn = SDL_BlitScaled(src, srcrect, dst, dstrect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.BlitSurface
Gura_DeclareFunction(BlitSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(BlitSurface)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = Object_Surface::GetObject(args, 2)->GetEntity();
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int _rtn = SDL_BlitSurface(src, srcrect, dst, dstrect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.ConvertPixels
Gura_DeclareFunction(ConvertPixels)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ConvertPixels)
{
#if 0
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	Uint32 src_format = args.GetULong(2);
	const void *src = NULL;
	int src_pitch = NULL;
	Uint32 dst_format = args.GetULong(5);
	void *dst = NULL;
	int dst_pitch = NULL;
	int _rtn = SDL_ConvertPixels(width, height, src_format, src, src_pitch, dst_format, dst, dst_pitch);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ConvertPixels");
	return Value::Null;
}

// sdl2.ConvertSurface
Gura_DeclareFunction(ConvertSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "fmt", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ConvertSurface)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_PixelFormat *fmt = Object_PixelFormat::GetObject(args, 1)->GetEntity();
	Uint32 flags = args.GetULong(2);
	SDL_Surface *_rtn = SDL_ConvertSurface(src, fmt, flags);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Surface(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.ConvertSurfaceFormat
Gura_DeclareFunction(ConvertSurfaceFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pixel_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ConvertSurfaceFormat)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint32 pixel_format = args.GetULong(1);
	Uint32 flags = args.GetULong(2);
	SDL_Surface *_rtn = SDL_ConvertSurfaceFormat(src, pixel_format, flags);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Surface(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateRGBSurface
Gura_DeclareFunction(CreateRGBSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Rmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Gmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Bmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Amask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateRGBSurface)
{
	Uint32 flags = args.GetULong(0);
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	int depth = args.GetInt(3);
	Uint32 Rmask = args.GetULong(4);
	Uint32 Gmask = args.GetULong(5);
	Uint32 Bmask = args.GetULong(6);
	Uint32 Amask = args.GetULong(7);
	SDL_Surface *_rtn = SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask, Bmask, Amask);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Surface(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateRGBSurfaceFrom
Gura_DeclareFunction(CreateRGBSurfaceFrom)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixels", VTYPE_binary, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pitch", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Rmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Gmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Bmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Amask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateRGBSurfaceFrom)
{
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	int depth = args.GetInt(3);
	int pitch = args.GetInt(4);
	Uint32 Rmask = args.GetULong(5);
	Uint32 Gmask = args.GetULong(6);
	Uint32 Bmask = args.GetULong(7);
	Uint32 Amask = args.GetULong(8);
	Binary &binary = Object_binary::GetObject(args, 0)->GetBinary();
	if (binary.size() < static_cast<size_t>(height * pitch)) {
		sig.SetError(ERR_ValueError, "pixels doesn not contain enough data");
		return Value::Null;
	}
	void *pixels = const_cast<char *>(binary.data());
	SDL_Surface *_rtn = SDL_CreateRGBSurfaceFrom(pixels, width, height,
								depth, pitch, Rmask, Gmask, Bmask, Amask);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.CreateRGBSurfaceFromImage
Gura_DeclareFunction(CreateRGBSurfaceFromImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "image", VTYPE_image, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateRGBSurfaceFromImage)
{
	Image *pImage = Object_image::GetObject(args, 0)->GetImage();
	Object_Surface *pObjSurface = Object_Surface::CreateSurfaceFromImage(sig, pImage);
	if (pObjSurface == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

// sdl2.FillRect
Gura_DeclareFunction(FillRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "color", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FillRect)
{
	SDL_Surface *dst = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	Uint32 color = args.GetULong(2);
	int _rtn = SDL_FillRect(dst, rect, color);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.FillRects
Gura_DeclareFunction(FillRects)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	DeclareArg(env, "color", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FillRects)
{
	SDL_Surface *dst = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint32 color = args.GetULong(2);
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int count = static_cast<int>(rects.GetSize());
	int _rtn = SDL_FillRects(dst, rects, count, color);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.FreeSurface
Gura_DeclareFunction(FreeSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FreeSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_FreeSurface(surface);
	return Value::Null;
}

// sdl2.GetClipRect
Gura_DeclareFunction(GetClipRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetClipRect)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_GetClipRect(surface, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.GetColorKey
Gura_DeclareFunction(GetColorKey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetColorKey)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint32 key = 0;
	int _rtn = SDL_GetColorKey(surface, &key);
	Value _rtnVal;
	if (_rtn >= 0) {
		_rtnVal = Value(key);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetSurfaceAlphaMod
Gura_DeclareFunction(GetSurfaceAlphaMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetSurfaceAlphaMod)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint8 alpha = 0;
	int _rtn = SDL_GetSurfaceAlphaMod(surface, &alpha);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(alpha));
}

// sdl2.GetSurfaceBlendMode
Gura_DeclareFunction(GetSurfaceBlendMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetSurfaceBlendMode)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
	int _rtn = SDL_GetSurfaceBlendMode(surface, &blendMode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(blendMode));
}

// sdl2.GetSurfaceColorMod
Gura_DeclareFunction(GetSurfaceColorMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetSurfaceColorMod)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	int _rtn = SDL_GetSurfaceColorMod(surface, &r, &g, &b);
	return ReturnValue(env, sig, args,
			Value::CreateList(env, Value(r), Value(g), Value(b)));
}

// sdl2.LoadBMP
Gura_DeclareFunction(LoadBMP)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadBMP)
{
	Stream &_stream = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> src(CreateRWopsStream(&_stream, &sig));
	SDL_Surface *_rtn = SDL_LoadBMP_RW(src.get(), 0);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.LoadBMP_RW
Gura_DeclareFunction(LoadBMP_RW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadBMP_RW)
{
#if 0
	SDL_LoadBMP_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LoadBMP_RW");
	return Value::Null;
}

// sdl2.LockSurface
Gura_DeclareFunction(LockSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LockSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_LockSurface(surface);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.LowerBlit
Gura_DeclareFunction(LowerBlit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LowerBlit)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = Object_Surface::GetObject(args, 2)->GetEntity();
	SDL_Rect *dstrect = Object_Rect::GetObject(args, 3)->GetEntity();
	int _rtn = SDL_LowerBlit(src, srcrect, dst, dstrect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.LowerBlitScaled
Gura_DeclareFunction(LowerBlitScaled)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LowerBlitScaled)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Rect *srcrect = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_Surface *dst = Object_Surface::GetObject(args, 2)->GetEntity();
	SDL_Rect *dstrect = Object_Rect::GetObject(args, 3)->GetEntity();
	int _rtn = SDL_LowerBlitScaled(src, srcrect, dst, dstrect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.MUSTLOCK
Gura_DeclareFunction(MUSTLOCK)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MUSTLOCK)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	bool _rtn = SDL_MUSTLOCK(surface);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.SaveBMP
Gura_DeclareFunction(SaveBMP)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveBMP)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Stream &_stream = Object_stream::GetObject(args, 1)->GetStream();
	std::auto_ptr<SDL_RWops> context(CreateRWopsStream(&_stream, &sig));
	int _rtn = SDL_SaveBMP_RW(surface, context.get(), 0);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.SaveBMP_RW
Gura_DeclareFunction(SaveBMP_RW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveBMP_RW)
{
#if 0
	SDL_SaveBMP_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SaveBMP_RW");
	return Value::Null;
}

// sdl2.SetClipRect
Gura_DeclareFunction(SetClipRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetClipRect)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_bool _rtn = SDL_SetClipRect(surface, rect);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.SetColorKey
Gura_DeclareFunction(SetColorKey)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetColorKey)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	int flag = args.GetInt(1);
	Uint32 key = args.GetULong(2);
	int _rtn = SDL_SetColorKey(surface, flag, key);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetSurfaceAlphaMod
Gura_DeclareFunction(SetSurfaceAlphaMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetSurfaceAlphaMod)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint8 alpha = args.GetUChar(1);
	int _rtn = SDL_SetSurfaceAlphaMod(surface, alpha);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetSurfaceBlendMode
Gura_DeclareFunction(SetSurfaceBlendMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetSurfaceBlendMode)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = static_cast<SDL_BlendMode>(args.GetInt(1));
	int _rtn = SDL_SetSurfaceBlendMode(surface, blendMode);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetSurfaceColorMod
Gura_DeclareFunction(SetSurfaceColorMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetSurfaceColorMod)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	int _rtn = SDL_SetSurfaceColorMod(surface, r, g, b);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetSurfacePalette
Gura_DeclareFunction(SetSurfacePalette)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetSurfacePalette)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Palette *palette = Object_Palette::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_SetSurfacePalette(surface, palette);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetSurfaceRLE
Gura_DeclareFunction(SetSurfaceRLE)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetSurfaceRLE)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	int flag = args.GetInt(1);
	int _rtn = SDL_SetSurfaceRLE(surface, flag);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.UnlockSurface
Gura_DeclareFunction(UnlockSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UnlockSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_UnlockSurface(surface);
	return Value::Null;
}

// sdl2.GetClipboardText
Gura_DeclareFunction(GetClipboardText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetClipboardText)
{
	char *_rtn = SDL_GetClipboardText();
	Value _rtnVal(_rtn);
	SDL_free(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasClipboardText
Gura_DeclareFunction(HasClipboardText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasClipboardText)
{
	SDL_bool _rtn = SDL_HasClipboardText();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.SetClipboardText
Gura_DeclareFunction(SetClipboardText)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetClipboardText)
{
	const char *text = args.GetString(0);
	int _rtn = SDL_SetClipboardText(text);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.AddEventWatch
Gura_DeclareFunction(AddEventWatch)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AddEventWatch)
{
#if 0
	SDL_AddEventWatch();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AddEventWatch");
	return Value::Null;
}

// sdl2.DelEventWatch
Gura_DeclareFunction(DelEventWatch)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DelEventWatch)
{
#if 0
	SDL_DelEventWatch();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DelEventWatch");
	return Value::Null;
}

// sdl2.EventState
Gura_DeclareFunction(EventState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(EventState)
{
	Uint32 type = args.GetULong(0);
	int state = args.GetInt(1);
	Uint8 _rtn = SDL_EventState(type, state);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.FilterEvents
Gura_DeclareFunction(FilterEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FilterEvents)
{
#if 0
	SDL_FilterEvents();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "FilterEvents");
	return Value::Null;
}

// sdl2.FlushEvent
Gura_DeclareFunction(FlushEvent)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FlushEvent)
{
	Uint32 type = args.GetULong(0);
	SDL_FlushEvent(type);
	return Value::Null;
}

// sdl2.FlushEvents
Gura_DeclareFunction(FlushEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FlushEvents)
{
	Uint32 minType = args.GetULong(0);
	Uint32 maxType = args.GetULong(1);
	SDL_FlushEvents(minType, maxType);
	return Value::Null;
}

// sdl2.GetEventFilter
Gura_DeclareFunction(GetEventFilter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetEventFilter)
{
#if 0
	SDL_GetEventFilter();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetEventFilter");
	return Value::Null;
}

// sdl2.GetNumTouchDevices
Gura_DeclareFunction(GetNumTouchDevices)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumTouchDevices)
{
	int _rtn = SDL_GetNumTouchDevices();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetNumTouchFingers
Gura_DeclareFunction(GetNumTouchFingers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumTouchFingers)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	int _rtn = SDL_GetNumTouchFingers(touchId);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetTouchDevice
Gura_DeclareFunction(GetTouchDevice)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetTouchDevice)
{
	int index = args.GetInt(0);
	SDL_TouchID _rtn = SDL_GetTouchDevice(index);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetTouchFinger
Gura_DeclareFunction(GetTouchFinger)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetTouchFinger)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	int index = args.GetInt(1);
	SDL_Finger *_rtn = SDL_GetTouchFinger(touchId, index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Finger(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasEvent
Gura_DeclareFunction(HasEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasEvent)
{
	Uint32 type = args.GetULong(0);
	SDL_bool _rtn = SDL_HasEvent(type);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasEvents
Gura_DeclareFunction(HasEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasEvents)
{
	Uint32 minType = args.GetULong(0);
	Uint32 maxType = args.GetULong(1);
	SDL_bool _rtn = SDL_HasEvents(minType, maxType);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.LoadDollarTemplates
Gura_DeclareFunction(LoadDollarTemplates)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadDollarTemplates)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	Stream &_stream = Object_stream::GetObject(args, 1)->GetStream();
	std::auto_ptr<SDL_RWops> src(CreateRWopsStream(&_stream, &sig));
	int _rtn = SDL_LoadDollarTemplates(touchId, src.get());
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.AddEvents
Gura_DeclareFunction(AddEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "events", VTYPE_Event, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AddEvents)
{
	CArray<SDL_Event> events(CreateCArray<SDL_Event, Object_Event>(args.GetList(0)));
	int numevents = static_cast<int>(events.GetSize());
	int _rtn = SDL_PeepEvents(events, numevents, SDL_ADDEVENT, 0, 0);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.PeekEvents
Gura_DeclareFunction(PeekEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PeekEvents)
{
	int numevents = args.GetInt(0);
	Uint32 minType = args.GetULong(1);
	Uint32 maxType = args.GetULong(2);
	CArray<SDL_Event> events(numevents);
	int _rtn = SDL_PeepEvents(events, numevents, SDL_PEEKEVENT, minType, maxType);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	Value _rtnVal;
	ValueList &_valList = _rtnVal.InitAsList(env, _rtn);
	for (int i = 0; i < _rtn; i++) {
		_valList.push_back(Value(new Object_Event(events[i])));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetEvents
Gura_DeclareFunction(GetEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetEvents)
{
	int numevents = args.GetInt(0);
	Uint32 minType = args.GetULong(1);
	Uint32 maxType = args.GetULong(2);
	CArray<SDL_Event> events(numevents);
	int _rtn = SDL_PeepEvents(events, numevents, SDL_GETEVENT, minType, maxType);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	Value _rtnVal;
	ValueList &_valList = _rtnVal.InitAsList(env, _rtn);
	for (int i = 0; i < _rtn; i++) {
		_valList.push_back(Value(new Object_Event(events[i])));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.PollEvent
Gura_DeclareFunction(PollEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PollEvent)
{
	SDL_Event event;
	int _rtn = SDL_PollEvent(&event);
	if (_rtn == 0) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_Event(event)));
}

// sdl2.PumpEvents
Gura_DeclareFunction(PumpEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PumpEvents)
{
	SDL_PumpEvents();
	return Value::Null;
}

// sdl2.PushEvent
Gura_DeclareFunction(PushEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "event", VTYPE_Event, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PushEvent)
{
	SDL_Event *event = Object_Event::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_PushEvent(event);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.QuitRequested
Gura_DeclareFunction(QuitRequested)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(QuitRequested)
{
	bool _rtn = SDL_QuitRequested();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.RecordGesture
Gura_DeclareFunction(RecordGesture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RecordGesture)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	int _rtn = SDL_RecordGesture(touchId);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.RegisterEvents
Gura_DeclareFunction(RegisterEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RegisterEvents)
{
	int numevents = args.GetInt(0);
	Uint32 _rtn = SDL_RegisterEvents(numevents);
	Value _rtnVal;
	if (_rtn != (Uint32)-1) {
		_rtnVal = Value(_rtn);
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.SaveAllDollarTemplates
Gura_DeclareFunction(SaveAllDollarTemplates)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveAllDollarTemplates)
{
	Stream &_stream = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> dst(CreateRWopsStream(&_stream, &sig));
	int _rtn = SDL_SaveAllDollarTemplates(dst.get());
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.SaveDollarTemplate
Gura_DeclareFunction(SaveDollarTemplate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "gestureId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveDollarTemplate)
{
	SDL_GestureID gestureId = static_cast<SDL_GestureID>(args.GetInt(0));
	Stream &_stream = Object_stream::GetObject(args, 1)->GetStream();
	std::auto_ptr<SDL_RWops> dst(CreateRWopsStream(&_stream, &sig));
	int _rtn = SDL_SaveDollarTemplate(gestureId, dst.get());
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SetEventFilter
Gura_DeclareFunction(SetEventFilter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetEventFilter)
{
#if 0
	SDL_SetEventFilter();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetEventFilter");
	return Value::Null;
}

// sdl2.WaitEvent
Gura_DeclareFunction(WaitEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WaitEvent)
{
	SDL_Event event;
	int _rtn = SDL_WaitEvent(&event);
	if (_rtn == 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Event(event)));
}

// sdl2.WaitEventTimeout
Gura_DeclareFunction(WaitEventTimeout)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WaitEventTimeout)
{
	int timeout = args.GetInt(0);
	SDL_Event event;
	int _rtn = SDL_WaitEventTimeout(&event, timeout);
	Value _rtnVal;
	if (_rtn > 0) {
		_rtnVal = Value(new Object_Event(event));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetKeyFromName
Gura_DeclareFunction(GetKeyFromName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetKeyFromName)
{
	const char *name = args.GetString(0);
	SDL_Keycode _rtn = SDL_GetKeyFromName(name);
	if (_rtn == SDLK_UNKNOWN) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetKeyFromScancode
Gura_DeclareFunction(GetKeyFromScancode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetKeyFromScancode)
{
	SDL_Scancode scancode = static_cast<SDL_Scancode>(args.GetInt(0));
	SDL_Keycode _rtn = SDL_GetKeyFromScancode(scancode);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetKeyName
Gura_DeclareFunction(GetKeyName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetKeyName)
{
	SDL_Keycode key = static_cast<SDL_Keycode>(args.GetInt(0));
	const char *_rtn = SDL_GetKeyName(key);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetKeyboardFocus
Gura_DeclareFunction(GetKeyboardFocus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetKeyboardFocus)
{
	SDL_Window *_rtn = SDL_GetKeyboardFocus();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Window(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetKeyboardState
Gura_DeclareFunction(GetKeyboardState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetKeyboardState)
{
	int numkeys = 0;
	const Uint8 *_rtn = SDL_GetKeyboardState(&numkeys);
	return ReturnValue(env, sig, args, Value::CreateList(env, _rtn, numkeys));
}

// sdl2.GetModState
Gura_DeclareFunction(GetModState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetModState)
{
	SDL_Keymod _rtn = SDL_GetModState();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetScancodeFromKey
Gura_DeclareFunction(GetScancodeFromKey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetScancodeFromKey)
{
	SDL_Keycode key = static_cast<SDL_Keycode>(args.GetInt(0));
	SDL_Scancode _rtn = SDL_GetScancodeFromKey(key);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetScancodeFromName
Gura_DeclareFunction(GetScancodeFromName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetScancodeFromName)
{
	const char *name = args.GetString(0);
	SDL_Scancode _rtn = SDL_GetScancodeFromName(name);
	if (_rtn == SDL_SCANCODE_UNKNOWN) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetScancodeName
Gura_DeclareFunction(GetScancodeName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetScancodeName)
{
	SDL_Scancode scancode = static_cast<SDL_Scancode>(args.GetInt(0));
	const char *_rtn = SDL_GetScancodeName(scancode);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasScreenKeyboardSupport
Gura_DeclareFunction(HasScreenKeyboardSupport)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasScreenKeyboardSupport)
{
	SDL_bool _rtn = SDL_HasScreenKeyboardSupport();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.IsScreenKeyboardShown
Gura_DeclareFunction(IsScreenKeyboardShown)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(IsScreenKeyboardShown)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_IsScreenKeyboardShown(window);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.IsTextInputActive
Gura_DeclareFunction(IsTextInputActive)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(IsTextInputActive)
{
	SDL_bool _rtn = SDL_IsTextInputActive();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.SetModState
Gura_DeclareFunction(SetModState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "modstate", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetModState)
{
	SDL_Keymod modstate = static_cast<SDL_Keymod>(args.GetInt(0));
	SDL_SetModState(modstate);
	return Value::Null;
}

// sdl2.SetTextInputRect
Gura_DeclareFunction(SetTextInputRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetTextInputRect)
{
	SDL_Rect *rect = args.IsValid(0)? Object_Rect::GetObject(args, 0)->GetEntity() : NULL;
	SDL_SetTextInputRect(rect);
	return Value::Null;
}

// sdl2.StartTextInput
Gura_DeclareFunction(StartTextInput)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(StartTextInput)
{
	SDL_StartTextInput();
	return Value::Null;
}

// sdl2.StopTextInput
Gura_DeclareFunction(StopTextInput)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(StopTextInput)
{
	SDL_StopTextInput();
	return Value::Null;
}

// sdl2.CaptureMouse
Gura_DeclareFunction(CaptureMouse)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "enalbed", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CaptureMouse)
{
#if 0
	SDL_bool enalbed = (args.GetBoolean(0)? SDL_TRUE : SDL_FALSE);
	int _rtn = SDL_CaptureMouse(enalbed);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CaptureMouse");
	return Value::Null;
}

// sdl2.CreateColorCursor
Gura_DeclareFunction(CreateColorCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateColorCursor)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	int hot_x = args.GetInt(1);
	int hot_y = args.GetInt(2);
	SDL_Cursor *_rtn = SDL_CreateColorCursor(surface, hot_x, hot_y);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, false));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateCursor
Gura_DeclareFunction(CreateCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_binary, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mask", VTYPE_binary, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateCursor)
{
	int w = args.GetInt(2);
	int h = args.GetInt(3);
	int hot_x = args.GetInt(4);
	int hot_y = args.GetInt(5);
	const Binary &_data = Object_binary::GetObject(args, 0)->GetBinary();
	const Binary &_mask = Object_binary::GetObject(args, 1)->GetBinary();
	size_t bytesLeast = int((w + 7) / 8) * h;
	if (_data.size() < bytesLeast) {
		sig.SetError(ERR_ValueError, "data has insufficient content");
		return Value::Null;
	}
	if (_mask.size() < bytesLeast) {
		sig.SetError(ERR_ValueError, "mask has insufficient content");
		return Value::Null;
	}
	const Uint8 *data = reinterpret_cast<const Uint8 *>(_data.data());
	const Uint8 *mask = reinterpret_cast<const Uint8 *>(_mask.data());
	SDL_Cursor *_rtn = SDL_CreateCursor(data, mask, w, h, hot_x, hot_y);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(_rtn, true)));
}

// sdl2.CreateSystemCursor
Gura_DeclareFunction(CreateSystemCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateSystemCursor)
{
	SDL_SystemCursor id = static_cast<SDL_SystemCursor>(args.GetInt(0));
	SDL_Cursor *_rtn = SDL_CreateSystemCursor(id);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, false));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.FreeCursor
Gura_DeclareFunction(FreeCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FreeCursor)
{
	SDL_Cursor *cursor = Object_Cursor::GetObject(args, 0)->GetEntity();
	SDL_FreeCursor(cursor);
	return Value::Null;
}

// sdl2.GetCursor
Gura_DeclareFunction(GetCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCursor)
{
	SDL_Cursor *_rtn = SDL_GetCursor();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, false));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetDefaultCursor
Gura_DeclareFunction(GetDefaultCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetDefaultCursor)
{
	SDL_Cursor *_rtn = SDL_GetDefaultCursor();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, false));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetGlobalMouseState
Gura_DeclareFunction(GetGlobalMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetGlobalMouseState)
{
#if 0
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetGlobalMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
#endif
	SetError_NotImpFunction(sig, "GetGlobalMouseState");
	return Value::Null;
}

// sdl2.GetMouseFocus
Gura_DeclareFunction(GetMouseFocus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetMouseFocus)
{
	SDL_Window *_rtn = SDL_GetMouseFocus();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Window(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetMouseState
Gura_DeclareFunction(GetMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetMouseState)
{
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
}

// sdl2.GetRelativeMouseMode
Gura_DeclareFunction(GetRelativeMouseMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRelativeMouseMode)
{
	SDL_bool _rtn = SDL_GetRelativeMouseMode();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetRelativeMouseState
Gura_DeclareFunction(GetRelativeMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRelativeMouseState)
{
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetRelativeMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
}

// sdl2.SetCursor
Gura_DeclareFunction(SetCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetCursor)
{
	SDL_Cursor *cursor = Object_Cursor::GetObject(args, 0)->GetEntity();
	SDL_SetCursor(cursor);
	return Value::Null;
}

// sdl2.SetRelativeMouseMode
Gura_DeclareFunction(SetRelativeMouseMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "enabled", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetRelativeMouseMode)
{
	SDL_bool enabled = (args.GetBoolean(0)? SDL_TRUE : SDL_FALSE);
	int _rtn = SDL_SetRelativeMouseMode(enabled);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.ShowCursor
Gura_DeclareFunction(ShowCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "toggle", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ShowCursor)
{
	int toggle = args.GetInt(0);
	int _rtn = SDL_ShowCursor(toggle);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.WarpMouseGlobal
Gura_DeclareFunction(WarpMouseGlobal)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WarpMouseGlobal)
{
#if 0
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	SDL_WarpMouseGlobal(x, y);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WarpMouseGlobal");
	return Value::Null;
}

// sdl2.WarpMouseInWindow
Gura_DeclareFunction(WarpMouseInWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WarpMouseInWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	SDL_WarpMouseInWindow(window, x, y);
	return Value::Null;
}

// sdl2.JoystickClose
Gura_DeclareFunction(JoystickClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickClose)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickClose(joystick);
	return Value::Null;
}

// sdl2.JoystickEventState
Gura_DeclareFunction(JoystickEventState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickEventState)
{
	int state = args.GetInt(0);
	int _rtn = SDL_JoystickEventState(state);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.JoystickGetAttached
Gura_DeclareFunction(JoystickGetAttached)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetAttached)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_JoystickGetAttached(joystick);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetAxis
Gura_DeclareFunction(JoystickGetAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetAxis)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int axis = args.GetInt(1);
	Sint16 _rtn = SDL_JoystickGetAxis(joystick, axis);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetBall
Gura_DeclareFunction(JoystickGetBall)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ball", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetBall)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int ball = args.GetInt(1);
	int dx = 0;
	int dy = 0;
	int _rtn = SDL_JoystickGetBall(joystick, ball, &dx, &dy);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(dx), Value(dy)));
}

// sdl2.JoystickGetButton
Gura_DeclareFunction(JoystickGetButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetButton)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int button = args.GetInt(1);
	Uint8 _rtn = SDL_JoystickGetButton(joystick, button);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.JoystickGetDeviceGUID
Gura_DeclareFunction(JoystickGetDeviceGUID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetDeviceGUID)
{
	int device_index = args.GetInt(0);
	SDL_JoystickGUID _rtn = SDL_JoystickGetDeviceGUID(device_index);
	Value _rtnVal = Value(new Object_JoystickGUID(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetGUID
Gura_DeclareFunction(JoystickGetGUID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetGUID)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickGUID _rtn = SDL_JoystickGetGUID(joystick);
	Value _rtnVal = Value(new Object_JoystickGUID(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetGUIDFromString
Gura_DeclareFunction(JoystickGetGUIDFromString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchGUID", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetGUIDFromString)
{
	const char *pchGUID = args.GetString(0);
	SDL_JoystickGUID _rtn = SDL_JoystickGetGUIDFromString(pchGUID);
	Value _rtnVal = Value(new Object_JoystickGUID(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetGUIDString
Gura_DeclareFunction(JoystickGetGUIDString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "guid", VTYPE_JoystickGUID, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetGUIDString)
{
	SDL_JoystickGUID guid = *Object_JoystickGUID::GetObject(args, 0)->GetEntity();
	char szGUID[64];
	int cbGUID = sizeof(szGUID);
	SDL_JoystickGetGUIDString(guid, szGUID, cbGUID);
	return ReturnValue(env, sig, args, Value(szGUID));
}

// sdl2.JoystickGetHat
Gura_DeclareFunction(JoystickGetHat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hat", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetHat)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int hat = args.GetInt(1);
	Uint8 _rtn = SDL_JoystickGetHat(joystick, hat);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickInstanceID
Gura_DeclareFunction(JoystickInstanceID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickInstanceID)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickID _rtn = SDL_JoystickInstanceID(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.JoystickName
Gura_DeclareFunction(JoystickName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickName)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_JoystickName(joystick);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickNameForIndex
Gura_DeclareFunction(JoystickNameForIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickNameForIndex)
{
	int device_index = args.GetInt(0);
	const char *_rtn = SDL_JoystickNameForIndex(device_index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickNumAxes
Gura_DeclareFunction(JoystickNumAxes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickNumAxes)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumAxes(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.JoystickNumBalls
Gura_DeclareFunction(JoystickNumBalls)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickNumBalls)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumBalls(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.JoystickNumButtons
Gura_DeclareFunction(JoystickNumButtons)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickNumButtons)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumButtons(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.JoystickNumHats
Gura_DeclareFunction(JoystickNumHats)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickNumHats)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumHats(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.JoystickOpen
Gura_DeclareFunction(JoystickOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickOpen)
{
	int device_index = args.GetInt(0);
	SDL_Joystick *_rtn = SDL_JoystickOpen(device_index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Joystick(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickUpdate
Gura_DeclareFunction(JoystickUpdate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickUpdate)
{
	SDL_JoystickUpdate();
	return Value::Null;
}

// sdl2.NumJoysticks
Gura_DeclareFunction(NumJoysticks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(NumJoysticks)
{
	int _rtn = SDL_NumJoysticks();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GameControllerAddMapping
Gura_DeclareFunction(GameControllerAddMapping)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "mappingString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerAddMapping)
{
	const char *mappingString = args.GetString(0);
	int _rtn = SDL_GameControllerAddMapping(mappingString);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.GameControllerAddMappingsFromFile
Gura_DeclareFunction(GameControllerAddMappingsFromFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerAddMappingsFromFile)
{
	Stream &_stream = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> file(CreateRWopsStream(&_stream, &sig));
	int _rtn = SDL_GameControllerAddMappingsFromRW(file.get(), 0);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GameControllerAddMappingsFromRW
Gura_DeclareFunction(GameControllerAddMappingsFromRW)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "rw", VTYPE_nil, OCCUR_Once, FLAG_None);
	DeclareArg(env, "freerw", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerAddMappingsFromRW)
{
#if 0
	SDL_RWops *rw = NULL;
	int freerw = args.GetInt(1);
	int _rtn = SDL_GameControllerAddMappingsFromRW(rw, freerw);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "GameControllerAddMappingsFromRW");
	return Value::Null;
}

// sdl2.GameControllerClose
Gura_DeclareFunction(GameControllerClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerClose)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerClose(gamecontroller);
	return Value::Null;
}

// sdl2.GameControllerEventState
Gura_DeclareFunction(GameControllerEventState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerEventState)
{
	int state = args.GetInt(0);
	int _rtn = SDL_GameControllerEventState(state);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetAttached
Gura_DeclareFunction(GameControllerGetAttached)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetAttached)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_GameControllerGetAttached(gamecontroller);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetAxis
Gura_DeclareFunction(GameControllerGetAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetAxis)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	Sint16 _rtn = SDL_GameControllerGetAxis(gamecontroller, axis);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetAxisFromString
Gura_DeclareFunction(GameControllerGetAxisFromString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetAxisFromString)
{
	const char *pchString = args.GetString(0);
	SDL_GameControllerAxis _rtn = SDL_GameControllerGetAxisFromString(pchString);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetBindForAxis
Gura_DeclareFunction(GameControllerGetBindForAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetBindForAxis)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	SDL_GameControllerButtonBind _rtn = SDL_GameControllerGetBindForAxis(gamecontroller, axis);
	Value _rtnVal = Value(new Object_GameControllerButtonBind(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetBindForButton
Gura_DeclareFunction(GameControllerGetBindForButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetBindForButton)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(1));
	SDL_GameControllerButtonBind _rtn = SDL_GameControllerGetBindForButton(gamecontroller, button);
	Value _rtnVal = Value(new Object_GameControllerButtonBind(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetButton
Gura_DeclareFunction(GameControllerGetButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetButton)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(1));
	Uint8 _rtn = SDL_GameControllerGetButton(gamecontroller, button);
	if (_rtn == 0 && *SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.GameControllerGetButtonFromString
Gura_DeclareFunction(GameControllerGetButtonFromString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetButtonFromString)
{
	const char *pchString = args.GetString(0);
	SDL_GameControllerButton _rtn = SDL_GameControllerGetButtonFromString(pchString);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetJoystick
Gura_DeclareFunction(GameControllerGetJoystick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetJoystick)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_Joystick *_rtn = SDL_GameControllerGetJoystick(gamecontroller);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Joystick(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetStringForAxis
Gura_DeclareFunction(GameControllerGetStringForAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetStringForAxis)
{
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(0));
	const char *_rtn = SDL_GameControllerGetStringForAxis(axis);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetStringForButton
Gura_DeclareFunction(GameControllerGetStringForButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerGetStringForButton)
{
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(0));
	const char *_rtn = SDL_GameControllerGetStringForButton(button);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerMapping
Gura_DeclareFunction(GameControllerMapping)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerMapping)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GameControllerMapping(gamecontroller);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerMappingForGUID
Gura_DeclareFunction(GameControllerMappingForGUID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "guid", VTYPE_JoystickGUID, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerMappingForGUID)
{
	SDL_JoystickGUID guid = *Object_JoystickGUID::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GameControllerMappingForGUID(guid);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerName
Gura_DeclareFunction(GameControllerName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerName)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GameControllerName(gamecontroller);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerNameForIndex
Gura_DeclareFunction(GameControllerNameForIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerNameForIndex)
{
	int joystick_index = args.GetInt(0);
	const char *_rtn = SDL_GameControllerNameForIndex(joystick_index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerOpen
Gura_DeclareFunction(GameControllerOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerOpen)
{
	int joystick_index = args.GetInt(0);
	SDL_GameController *_rtn = SDL_GameControllerOpen(joystick_index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_GameController(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerUpdate
Gura_DeclareFunction(GameControllerUpdate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerUpdate)
{
	SDL_GameControllerUpdate();
	return Value::Null;
}

// sdl2.IsGameController
Gura_DeclareFunction(IsGameController)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(IsGameController)
{
	int joystick_index = args.GetInt(0);
	SDL_bool _rtn = SDL_IsGameController(joystick_index);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HapticClose
Gura_DeclareFunction(HapticClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticClose)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	SDL_HapticClose(haptic);
	return Value::Null;
}

// sdl2.HapticDestroyEffect
Gura_DeclareFunction(HapticDestroyEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticDestroyEffect)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int effect = args.GetInt(1);
	SDL_HapticDestroyEffect(haptic, effect);
	return Value::Null;
}

// sdl2.HapticEffectSupported
Gura_DeclareFunction(HapticEffectSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticEffectSupported)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	SDL_HapticEffect *effect = Object_HapticEffect::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_HapticEffectSupported(haptic, effect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.HapticGetEffectStatus
Gura_DeclareFunction(HapticGetEffectStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticGetEffectStatus)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int effect = args.GetInt(1);
	int _rtn = SDL_HapticGetEffectStatus(haptic, effect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.HapticIndex
Gura_DeclareFunction(HapticIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticIndex)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticIndex(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.HapticName
Gura_DeclareFunction(HapticName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticName)
{
	int device_index = args.GetInt(0);
	const char *_rtn = SDL_HapticName(device_index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HapticNewEffect
Gura_DeclareFunction(HapticNewEffect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticNewEffect)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	SDL_HapticEffect *effect = Object_HapticEffect::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_HapticNewEffect(haptic, effect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.HapticNumAxes
Gura_DeclareFunction(HapticNumAxes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticNumAxes)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticNumAxes(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.HapticNumEffects
Gura_DeclareFunction(HapticNumEffects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticNumEffects)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticNumEffects(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.HapticNumEffectsPlaying
Gura_DeclareFunction(HapticNumEffectsPlaying)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticNumEffectsPlaying)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticNumEffectsPlaying(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.HapticOpen
Gura_DeclareFunction(HapticOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticOpen)
{
	int device_index = args.GetInt(0);
	SDL_Haptic *_rtn = SDL_HapticOpen(device_index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Haptic(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HapticOpenFromJoystick
Gura_DeclareFunction(HapticOpenFromJoystick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticOpenFromJoystick)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_Haptic *_rtn = SDL_HapticOpenFromJoystick(joystick);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Haptic(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HapticOpenFromMouse
Gura_DeclareFunction(HapticOpenFromMouse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticOpenFromMouse)
{
	SDL_Haptic *_rtn = SDL_HapticOpenFromMouse();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Haptic(_rtn));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HapticOpened
Gura_DeclareFunction(HapticOpened)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticOpened)
{
	int device_index = args.GetInt(0);
	int _rtn = SDL_HapticOpened(device_index);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.HapticPause
Gura_DeclareFunction(HapticPause)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticPause)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticPause(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticQuery
Gura_DeclareFunction(HapticQuery)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticQuery)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	unsigned int _rtn = SDL_HapticQuery(haptic);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HapticRumbleInit
Gura_DeclareFunction(HapticRumbleInit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticRumbleInit)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticRumbleInit(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticRumblePlay
Gura_DeclareFunction(HapticRumblePlay)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticRumblePlay)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	float strength = args.GetFloat(1);
	Uint32 length = args.GetULong(2);
	int _rtn = SDL_HapticRumblePlay(haptic, strength, length);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticRumbleStop
Gura_DeclareFunction(HapticRumbleStop)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticRumbleStop)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticRumbleStop(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticRumbleSupported
Gura_DeclareFunction(HapticRumbleSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticRumbleSupported)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticRumbleSupported(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.HapticRunEffect
Gura_DeclareFunction(HapticRunEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iterations", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticRunEffect)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int effect = args.GetInt(1);
	Uint32 iterations = args.GetULong(2);
	int _rtn = SDL_HapticRunEffect(haptic, effect, iterations);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticSetAutocenter
Gura_DeclareFunction(HapticSetAutocenter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "autocenter", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticSetAutocenter)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int autocenter = args.GetInt(1);
	int _rtn = SDL_HapticSetAutocenter(haptic, autocenter);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticSetGain
Gura_DeclareFunction(HapticSetGain)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "gain", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticSetGain)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int gain = args.GetInt(1);
	int _rtn = SDL_HapticSetGain(haptic, gain);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticStopAll
Gura_DeclareFunction(HapticStopAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticStopAll)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticStopAll(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticStopEffect
Gura_DeclareFunction(HapticStopEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticStopEffect)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int effect = args.GetInt(1);
	int _rtn = SDL_HapticStopEffect(haptic, effect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticUnpause
Gura_DeclareFunction(HapticUnpause)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticUnpause)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticUnpause(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.HapticUpdateEffect
Gura_DeclareFunction(HapticUpdateEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HapticUpdateEffect)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int effect = args.GetInt(1);
	SDL_HapticEffect *data = Object_HapticEffect::GetObject(args, 2)->GetEntity();
	int _rtn = SDL_HapticUpdateEffect(haptic, effect, data);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.JoystickIsHaptic
Gura_DeclareFunction(JoystickIsHaptic)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickIsHaptic)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickIsHaptic(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.MouseIsHaptic
Gura_DeclareFunction(MouseIsHaptic)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MouseIsHaptic)
{
	int _rtn = SDL_MouseIsHaptic();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.NumHaptics
Gura_DeclareFunction(NumHaptics)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(NumHaptics)
{
	int _rtn = SDL_NumHaptics();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.AudioInit
Gura_DeclareFunction(AudioInit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "driver_name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AudioInit)
{
	const char *driver_name = args.GetString(0);
	int _rtn = SDL_AudioInit(driver_name);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.AudioQuit
Gura_DeclareFunction(AudioQuit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AudioQuit)
{
	SDL_AudioQuit();
	return Value::Null;
}

// sdl2.BuildAudioCVT
Gura_DeclareFunction(BuildAudioCVT)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "cvt", VTYPE_AudioCVT, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_channels", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_rate", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_channels", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_rate", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(BuildAudioCVT)
{
	SDL_AudioCVT *cvt = Object_AudioCVT::GetObject(args, 0)->GetEntity();
	SDL_AudioFormat src_format = static_cast<SDL_AudioFormat>(args.GetInt(1));
	Uint8 src_channels = args.GetUChar(2);
	int src_rate = args.GetInt(3);
	SDL_AudioFormat dst_format = static_cast<SDL_AudioFormat>(args.GetInt(4));
	Uint8 dst_channels = args.GetUChar(5);
	int dst_rate = args.GetInt(6);
	int _rtn = SDL_BuildAudioCVT(cvt, src_format, src_channels, src_rate, dst_format, dst_channels, dst_rate);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.ClearQueuedAudio
Gura_DeclareFunction(ClearQueuedAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ClearQueuedAudio)
{
#if 0
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_ClearQueuedAudio(dev);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ClearQueuedAudio");
	return Value::Null;
}

// sdl2.CloseAudio
Gura_DeclareFunction(CloseAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CloseAudio)
{
	SDL_CloseAudio();
	return Value::Null;
}

// sdl2.CloseAudioDevice
Gura_DeclareFunction(CloseAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CloseAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_CloseAudioDevice(dev);
	return Value::Null;
}

// sdl2.ConvertAudio
Gura_DeclareFunction(ConvertAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cvt", VTYPE_AudioCVT, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ConvertAudio)
{
	SDL_AudioCVT *cvt = Object_AudioCVT::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_ConvertAudio(cvt);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.FreeWAV
Gura_DeclareFunction(FreeWAV)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "wav", VTYPE_Wav, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FreeWAV)
{
	Object_Wav *pObj = Object_Wav::GetObject(args, 0);
	Uint8 *buffer = pObj->GetBuffer();
	SDL_FreeWAV(buffer);
}

// sdl2.GetAudioDeviceName
Gura_DeclareFunction(GetAudioDeviceName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAudioDeviceName)
{
	int index = args.GetInt(0);
	int iscapture = args.GetInt(1);
	const char *_rtn = SDL_GetAudioDeviceName(index, iscapture);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetAudioDeviceStatus
Gura_DeclareFunction(GetAudioDeviceStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAudioDeviceStatus)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_AudioStatus _rtn = SDL_GetAudioDeviceStatus(dev);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetAudioDriver
Gura_DeclareFunction(GetAudioDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAudioDriver)
{
	int index = args.GetInt(0);
	const char *_rtn = SDL_GetAudioDriver(index);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetAudioStatus
Gura_DeclareFunction(GetAudioStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetAudioStatus)
{
	SDL_AudioStatus _rtn = SDL_GetAudioStatus();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetCurrentAudioDriver
Gura_DeclareFunction(GetCurrentAudioDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCurrentAudioDriver)
{
	const char *_rtn = SDL_GetCurrentAudioDriver();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetNumAudioDevices
Gura_DeclareFunction(GetNumAudioDevices)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumAudioDevices)
{
	int iscapture = args.GetInt(0);
	int _rtn = SDL_GetNumAudioDevices(iscapture);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetNumAudioDrivers
Gura_DeclareFunction(GetNumAudioDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetNumAudioDrivers)
{
	int _rtn = SDL_GetNumAudioDrivers();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetQueuedAudioSize
Gura_DeclareFunction(GetQueuedAudioSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetQueuedAudioSize)
{
#if 0
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	Uint32 _rtn = SDL_GetQueuedAudioSize(dev);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "GetQueuedAudioSize");
	return Value::Null;
}

// sdl2.LoadWAV
Gura_DeclareFunction(LoadWAV)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadWAV)
{
	Stream &_stream = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> file(CreateRWopsStream(&_stream, &sig));
	SDL_AudioSpec spec;
	Uint8 *audio_buf = NULL;
	Uint32 audio_len = 0;
	SDL_AudioSpec *_rtn = SDL_LoadWAV_RW(file.get(), 0, &spec, &audio_buf, &audio_len);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Wav(spec, audio_buf, audio_len)));
}

// sdl2.LoadWAV_RW
Gura_DeclareFunction(LoadWAV_RW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadWAV_RW)
{
#if 0
	SDL_LoadWAV_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LoadWAV_RW");
	return Value::Null;
}

// sdl2.LockAudio
Gura_DeclareFunction(LockAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LockAudio)
{
	SDL_LockAudio();
	return Value::Null;
}

// sdl2.LockAudioDevice
Gura_DeclareFunction(LockAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LockAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_LockAudioDevice(dev);
	return Value::Null;
}

// sdl2.MixAudio
Gura_DeclareFunction(MixAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "volume", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MixAudio)
{
#if 0
	Uint8 *dst = NULL;
	const Uint8 *src = NULL;
	Uint32 len = NULL;
	int volume = args.GetInt(3);
	SDL_MixAudio(dst, src, len, volume);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "MixAudio");
	return Value::Null;
}

// sdl2.MixAudioFormat
Gura_DeclareFunction(MixAudioFormat)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "volume", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MixAudioFormat)
{
#if 0
	Uint8 *dst = NULL;
	const Uint8 *src = NULL;
	SDL_AudioFormat format = static_cast<SDL_AudioFormat>(args.GetInt(2));
	Uint32 len = NULL;
	int volume = args.GetInt(4);
	SDL_MixAudioFormat(dst, src, format, len, volume);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "MixAudioFormat");
	return Value::Null;
}

// sdl2.OpenAudio
Gura_DeclareFunction(OpenAudio)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "desired", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(OpenAudio)
{
	SDL_AudioSpec *desired = Object_AudioSpec::GetObject(args, 0)->GetEntity();
	SDL_AudioSpec obtained;
	int _rtn = SDL_OpenAudio(desired, &obtained);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_AudioSpec(obtained)));
}

// sdl2.OpenAudioDevice
Gura_DeclareFunction(OpenAudioDevice)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "desired", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	DeclareArg(env, "allowed_changes", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(OpenAudioDevice)
{
#if 0
	const char *device = args.GetString(0);
	int iscapture = args.GetInt(1);
	const SDL_AudioSpec *desired = Object_AudioSpec::GetObject(args, 2)->GetEntity();
	SDL_AudioSpec *obtained = NULL;
	int allowed_changes = args.GetInt(4);
	SDL_AudioDeviceID _rtn = SDL_OpenAudioDevice(device, iscapture, desired, obtained, allowed_changes);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "OpenAudioDevice");
	return Value::Null;
}

// sdl2.PauseAudio
Gura_DeclareFunction(PauseAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PauseAudio)
{
	int pause_on = args.GetInt(0);
	SDL_PauseAudio(pause_on);
	return Value::Null;
}

// sdl2.PauseAudioDevice
Gura_DeclareFunction(PauseAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PauseAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	int pause_on = args.GetInt(1);
	SDL_PauseAudioDevice(dev, pause_on);
	return Value::Null;
}

// sdl2.QueueAudio
Gura_DeclareFunction(QueueAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(QueueAudio)
{
#if 0
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	const void *data = NULL;
	Uint32 len = NULL;
	int _rtn = SDL_QueueAudio(dev, data, len);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "QueueAudio");
	return Value::Null;
}

// sdl2.UnlockAudio
Gura_DeclareFunction(UnlockAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UnlockAudio)
{
	SDL_UnlockAudio();
	return Value::Null;
}

// sdl2.UnlockAudioDevice
Gura_DeclareFunction(UnlockAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UnlockAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_UnlockAudioDevice(dev);
	return Value::Null;
}

// sdl2.AUDIO_BITSIZE
Gura_DeclareFunction(AUDIO_BITSIZE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AUDIO_BITSIZE)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_BITSIZE(x);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.AUDIO_ISFLOAT
Gura_DeclareFunction(AUDIO_ISFLOAT)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AUDIO_ISFLOAT)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISFLOAT(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.AUDIO_ISBIGENDIAN
Gura_DeclareFunction(AUDIO_ISBIGENDIAN)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AUDIO_ISBIGENDIAN)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISBIGENDIAN(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.AUDIO_ISSIGNED
Gura_DeclareFunction(AUDIO_ISSIGNED)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AUDIO_ISSIGNED)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISSIGNED(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.AUDIO_ISINT
Gura_DeclareFunction(AUDIO_ISINT)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AUDIO_ISINT)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISINT(x);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.AUDIO_ISLITTLEENDIAN
Gura_DeclareFunction(AUDIO_ISLITTLEENDIAN)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AUDIO_ISLITTLEENDIAN)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISLITTLEENDIAN(x);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.AUDIO_ISUNSIGNED
Gura_DeclareFunction(AUDIO_ISUNSIGNED)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AUDIO_ISUNSIGNED)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISUNSIGNED(x);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateThread
Gura_DeclareFunction(CreateThread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateThread)
{
#if 0
	SDL_CreateThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateThread");
	return Value::Null;
}

// sdl2.DetachThread
Gura_DeclareFunction(DetachThread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DetachThread)
{
#if 0
	SDL_DetachThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DetachThread");
	return Value::Null;
}

// sdl2.GetThreadID
Gura_DeclareFunction(GetThreadID)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetThreadID)
{
#if 0
	SDL_GetThreadID();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetThreadID");
	return Value::Null;
}

// sdl2.GetThreadName
Gura_DeclareFunction(GetThreadName)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetThreadName)
{
#if 0
	SDL_GetThreadName();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetThreadName");
	return Value::Null;
}

// sdl2.GetThreadPriority
Gura_DeclareFunction(GetThreadPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetThreadPriority)
{
#if 0
	SDL_GetThreadPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetThreadPriority");
	return Value::Null;
}

// sdl2.TLSCreate
Gura_DeclareFunction(TLSCreate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(TLSCreate)
{
#if 0
	SDL_TLSCreate();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TLSCreate");
	return Value::Null;
}

// sdl2.TLSGet
Gura_DeclareFunction(TLSGet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(TLSGet)
{
#if 0
	SDL_TLSGet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TLSGet");
	return Value::Null;
}

// sdl2.TLSSet
Gura_DeclareFunction(TLSSet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(TLSSet)
{
#if 0
	SDL_TLSSet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TLSSet");
	return Value::Null;
}

// sdl2.ThreadID
Gura_DeclareFunction(ThreadID)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ThreadID)
{
#if 0
	SDL_ThreadID();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ThreadID");
	return Value::Null;
}

// sdl2.WaitThread
Gura_DeclareFunction(WaitThread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WaitThread)
{
#if 0
	SDL_WaitThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WaitThread");
	return Value::Null;
}

// sdl2.CondBroadcast
Gura_DeclareFunction(CondBroadcast)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CondBroadcast)
{
#if 0
	SDL_CondBroadcast();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondBroadcast");
	return Value::Null;
}

// sdl2.CondSignal
Gura_DeclareFunction(CondSignal)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CondSignal)
{
#if 0
	SDL_CondSignal();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondSignal");
	return Value::Null;
}

// sdl2.CondWait
Gura_DeclareFunction(CondWait)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CondWait)
{
#if 0
	SDL_CondWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondWait");
	return Value::Null;
}

// sdl2.CondWaitTimeout
Gura_DeclareFunction(CondWaitTimeout)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CondWaitTimeout)
{
#if 0
	SDL_CondWaitTimeout();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondWaitTimeout");
	return Value::Null;
}

// sdl2.CreateCond
Gura_DeclareFunction(CreateCond)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateCond)
{
#if 0
	SDL_CreateCond();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateCond");
	return Value::Null;
}

// sdl2.CreateMutex
Gura_DeclareFunction(CreateMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateMutex)
{
#if 0
	SDL_CreateMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateMutex");
	return Value::Null;
}

// sdl2.CreateSemaphore
Gura_DeclareFunction(CreateSemaphore)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateSemaphore)
{
#if 0
	SDL_CreateSemaphore();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateSemaphore");
	return Value::Null;
}

// sdl2.DestroyCond
Gura_DeclareFunction(DestroyCond)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DestroyCond)
{
#if 0
	SDL_DestroyCond();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DestroyCond");
	return Value::Null;
}

// sdl2.DestroyMutex
Gura_DeclareFunction(DestroyMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DestroyMutex)
{
#if 0
	SDL_DestroyMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DestroyMutex");
	return Value::Null;
}

// sdl2.DestroySemaphore
Gura_DeclareFunction(DestroySemaphore)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DestroySemaphore)
{
#if 0
	SDL_DestroySemaphore();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DestroySemaphore");
	return Value::Null;
}

// sdl2.LockMutex
Gura_DeclareFunction(LockMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LockMutex)
{
#if 0
	SDL_LockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LockMutex");
	return Value::Null;
}

// sdl2.SemPost
Gura_DeclareFunction(SemPost)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SemPost)
{
#if 0
	SDL_SemPost();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemPost");
	return Value::Null;
}

// sdl2.SemTryWait
Gura_DeclareFunction(SemTryWait)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SemTryWait)
{
#if 0
	SDL_SemTryWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemTryWait");
	return Value::Null;
}

// sdl2.SemValue
Gura_DeclareFunction(SemValue)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SemValue)
{
#if 0
	SDL_SemValue();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemValue");
	return Value::Null;
}

// sdl2.SemWait
Gura_DeclareFunction(SemWait)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SemWait)
{
#if 0
	SDL_SemWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemWait");
	return Value::Null;
}

// sdl2.SemWaitTimeout
Gura_DeclareFunction(SemWaitTimeout)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SemWaitTimeout)
{
#if 0
	SDL_SemWaitTimeout();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemWaitTimeout");
	return Value::Null;
}

// sdl2.TryLockMutex
Gura_DeclareFunction(TryLockMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(TryLockMutex)
{
#if 0
	SDL_TryLockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TryLockMutex");
	return Value::Null;
}

// sdl2.UnlockMutex
Gura_DeclareFunction(UnlockMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UnlockMutex)
{
#if 0
	SDL_UnlockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "UnlockMutex");
	return Value::Null;
}

// sdl2.AtomicAdd
Gura_DeclareFunction(AtomicAdd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicAdd)
{
#if 0
	SDL_AtomicAdd();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicAdd");
	return Value::Null;
}

// sdl2.AtomicCAS
Gura_DeclareFunction(AtomicCAS)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicCAS)
{
#if 0
	SDL_AtomicCAS();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicCAS");
	return Value::Null;
}

// sdl2.AtomicCASPtr
Gura_DeclareFunction(AtomicCASPtr)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicCASPtr)
{
#if 0
	SDL_AtomicCASPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicCASPtr");
	return Value::Null;
}

// sdl2.AtomicDecRef
Gura_DeclareFunction(AtomicDecRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicDecRef)
{
#if 0
	SDL_AtomicDecRef();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicDecRef");
	return Value::Null;
}

// sdl2.AtomicGet
Gura_DeclareFunction(AtomicGet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicGet)
{
#if 0
	SDL_AtomicGet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicGet");
	return Value::Null;
}

// sdl2.AtomicGetPtr
Gura_DeclareFunction(AtomicGetPtr)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicGetPtr)
{
#if 0
	SDL_AtomicGetPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicGetPtr");
	return Value::Null;
}

// sdl2.AtomicIncRef
Gura_DeclareFunction(AtomicIncRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicIncRef)
{
#if 0
	SDL_AtomicIncRef();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicIncRef");
	return Value::Null;
}

// sdl2.AtomicLock
Gura_DeclareFunction(AtomicLock)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicLock)
{
#if 0
	SDL_AtomicLock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicLock");
	return Value::Null;
}

// sdl2.AtomicSet
Gura_DeclareFunction(AtomicSet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicSet)
{
#if 0
	SDL_AtomicSet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicSet");
	return Value::Null;
}

// sdl2.AtomicSetPtr
Gura_DeclareFunction(AtomicSetPtr)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicSetPtr)
{
#if 0
	SDL_AtomicSetPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicSetPtr");
	return Value::Null;
}

// sdl2.AtomicTryLock
Gura_DeclareFunction(AtomicTryLock)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicTryLock)
{
#if 0
	SDL_AtomicTryLock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicTryLock");
	return Value::Null;
}

// sdl2.AtomicUnlock
Gura_DeclareFunction(AtomicUnlock)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AtomicUnlock)
{
#if 0
	SDL_AtomicUnlock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicUnlock");
	return Value::Null;
}

// sdl2.CompilerBarrier
Gura_DeclareFunction(CompilerBarrier)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CompilerBarrier)
{
#if 0
	SDL_CompilerBarrier();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CompilerBarrier");
	return Value::Null;
}

// sdl2.AddTimer
Gura_DeclareFunction(AddTimer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "interval", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AddTimer)
{
#if 0
	Uint32 interval = args.GetULong(0);
	SDL_TimerCallback callback = NULL;
	void *param = NULL;
	SDL_TimerID _rtn = SDL_AddTimer(interval, callback, param);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "AddTimer");
	return Value::Null;
}

// sdl2.Delay
Gura_DeclareFunction(Delay)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "ms", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Delay)
{
	Uint32 ms = args.GetULong(0);
	SDL_Delay(ms);
	return Value::Null;
}

// sdl2.GetPerformanceCounter
Gura_DeclareFunction(GetPerformanceCounter)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetPerformanceCounter)
{
	Uint64 _rtn = SDL_GetPerformanceCounter();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetPerformanceFrequency
Gura_DeclareFunction(GetPerformanceFrequency)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetPerformanceFrequency)
{
	Uint64 _rtn = SDL_GetPerformanceFrequency();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetTicks
Gura_DeclareFunction(GetTicks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetTicks)
{
	Uint32 _rtn = SDL_GetTicks();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.RemoveTimer
Gura_DeclareFunction(RemoveTimer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RemoveTimer)
{
	SDL_TimerID id = static_cast<SDL_TimerID>(args.GetInt(0));
	SDL_bool _rtn = SDL_RemoveTimer(id);
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.TICKS_PASSED
Gura_DeclareFunction(TICKS_PASSED)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(TICKS_PASSED)
{
	Uint32 A = args.GetULong(0);
	Uint32 B = args.GetULong(1);
	bool _rtn = SDL_TICKS_PASSED(A, B);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetBasePath
Gura_DeclareFunction(GetBasePath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetBasePath)
{
#if 0
	char *_rtn = SDL_GetBasePath();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "GetBasePath");
	return Value::Null;
}

// sdl2.GetPrefPath
Gura_DeclareFunction(GetPrefPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "org", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "app", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetPrefPath)
{
#if 0
	const char *org = args.GetString(0);
	const char *app = args.GetString(1);
	char *_rtn = SDL_GetPrefPath(org, app);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "GetPrefPath");
	return Value::Null;
}

// sdl2.AllocRW
Gura_DeclareFunction(AllocRW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AllocRW)
{
#if 0
	SDL_AllocRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AllocRW");
	return Value::Null;
}

// sdl2.FreeRW
Gura_DeclareFunction(FreeRW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FreeRW)
{
#if 0
	SDL_FreeRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "FreeRW");
	return Value::Null;
}

// sdl2.RWFromConstMem
Gura_DeclareFunction(RWFromConstMem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWFromConstMem)
{
#if 0
	SDL_RWFromConstMem();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromConstMem");
	return Value::Null;
}

// sdl2.RWFromFP
Gura_DeclareFunction(RWFromFP)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWFromFP)
{
#if 0
	SDL_RWFromFP();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromFP");
	return Value::Null;
}

// sdl2.RWFromFile
Gura_DeclareFunction(RWFromFile)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWFromFile)
{
#if 0
	SDL_RWFromFile();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromFile");
	return Value::Null;
}

// sdl2.RWFromMem
Gura_DeclareFunction(RWFromMem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWFromMem)
{
#if 0
	SDL_RWFromMem();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromMem");
	return Value::Null;
}

// sdl2.RWclose
Gura_DeclareFunction(RWclose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWclose)
{
#if 0
	SDL_RWclose();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWclose");
	return Value::Null;
}

// sdl2.RWread
Gura_DeclareFunction(RWread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWread)
{
#if 0
	SDL_RWread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWread");
	return Value::Null;
}

// sdl2.RWseek
Gura_DeclareFunction(RWseek)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWseek)
{
#if 0
	SDL_RWseek();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWseek");
	return Value::Null;
}

// sdl2.RWtell
Gura_DeclareFunction(RWtell)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWtell)
{
#if 0
	SDL_RWtell();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWtell");
	return Value::Null;
}

// sdl2.RWwrite
Gura_DeclareFunction(RWwrite)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RWwrite)
{
#if 0
	SDL_RWwrite();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWwrite");
	return Value::Null;
}

// sdl2.ReadBE16
Gura_DeclareFunction(ReadBE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ReadBE16)
{
#if 0
	SDL_ReadBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadBE16");
	return Value::Null;
}

// sdl2.ReadBE32
Gura_DeclareFunction(ReadBE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ReadBE32)
{
#if 0
	SDL_ReadBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadBE32");
	return Value::Null;
}

// sdl2.ReadBE64
Gura_DeclareFunction(ReadBE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ReadBE64)
{
#if 0
	SDL_ReadBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadBE64");
	return Value::Null;
}

// sdl2.ReadLE16
Gura_DeclareFunction(ReadLE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ReadLE16)
{
#if 0
	SDL_ReadLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadLE16");
	return Value::Null;
}

// sdl2.ReadLE32
Gura_DeclareFunction(ReadLE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ReadLE32)
{
#if 0
	SDL_ReadLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadLE32");
	return Value::Null;
}

// sdl2.ReadLE64
Gura_DeclareFunction(ReadLE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(ReadLE64)
{
#if 0
	SDL_ReadLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadLE64");
	return Value::Null;
}

// sdl2.WriteBE16
Gura_DeclareFunction(WriteBE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WriteBE16)
{
#if 0
	SDL_WriteBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteBE16");
	return Value::Null;
}

// sdl2.WriteBE32
Gura_DeclareFunction(WriteBE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WriteBE32)
{
#if 0
	SDL_WriteBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteBE32");
	return Value::Null;
}

// sdl2.WriteBE64
Gura_DeclareFunction(WriteBE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WriteBE64)
{
#if 0
	SDL_WriteBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteBE64");
	return Value::Null;
}

// sdl2.WriteLE16
Gura_DeclareFunction(WriteLE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WriteLE16)
{
#if 0
	SDL_WriteLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteLE16");
	return Value::Null;
}

// sdl2.WriteLE32
Gura_DeclareFunction(WriteLE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WriteLE32)
{
#if 0
	SDL_WriteLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteLE32");
	return Value::Null;
}

// sdl2.WriteLE64
Gura_DeclareFunction(WriteLE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WriteLE64)
{
#if 0
	SDL_WriteLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteLE64");
	return Value::Null;
}

// sdl2.GetPlatform
Gura_DeclareFunction(GetPlatform)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetPlatform)
{
	const char *_rtn = SDL_GetPlatform();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetCPUCacheLineSize
Gura_DeclareFunction(GetCPUCacheLineSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCPUCacheLineSize)
{
	int _rtn = SDL_GetCPUCacheLineSize();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetCPUCount
Gura_DeclareFunction(GetCPUCount)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetCPUCount)
{
	int _rtn = SDL_GetCPUCount();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetSystemRAM
Gura_DeclareFunction(GetSystemRAM)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetSystemRAM)
{
	int _rtn = SDL_GetSystemRAM();
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.Has3DNow
Gura_DeclareFunction(Has3DNow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Has3DNow)
{
	SDL_bool _rtn = SDL_Has3DNow();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasAVX
Gura_DeclareFunction(HasAVX)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasAVX)
{
	SDL_bool _rtn = SDL_HasAVX();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasAVX2
Gura_DeclareFunction(HasAVX2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasAVX2)
{
#if 0
	SDL_bool _rtn = SDL_HasAVX2();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "HasAVX2");
	return Value::Null;
}

// sdl2.HasAltiVec
Gura_DeclareFunction(HasAltiVec)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasAltiVec)
{
	SDL_bool _rtn = SDL_HasAltiVec();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasMMX
Gura_DeclareFunction(HasMMX)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasMMX)
{
	SDL_bool _rtn = SDL_HasMMX();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasRDTSC
Gura_DeclareFunction(HasRDTSC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasRDTSC)
{
	SDL_bool _rtn = SDL_HasRDTSC();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasSSE
Gura_DeclareFunction(HasSSE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasSSE)
{
	SDL_bool _rtn = SDL_HasSSE();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasSSE2
Gura_DeclareFunction(HasSSE2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasSSE2)
{
	SDL_bool _rtn = SDL_HasSSE2();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasSSE3
Gura_DeclareFunction(HasSSE3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasSSE3)
{
	SDL_bool _rtn = SDL_HasSSE3();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasSSE41
Gura_DeclareFunction(HasSSE41)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasSSE41)
{
	SDL_bool _rtn = SDL_HasSSE41();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasSSE42
Gura_DeclareFunction(HasSSE42)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(HasSSE42)
{
	SDL_bool _rtn = SDL_HasSSE42();
	Value _rtnVal = Value(_rtn != SDL_FALSE);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.Swap16
Gura_DeclareFunction(Swap16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Swap16)
{
#if 0
	SDL_Swap16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Swap16");
	return Value::Null;
}

// sdl2.Swap32
Gura_DeclareFunction(Swap32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Swap32)
{
#if 0
	SDL_Swap32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Swap32");
	return Value::Null;
}

// sdl2.Swap64
Gura_DeclareFunction(Swap64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Swap64)
{
#if 0
	SDL_Swap64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Swap64");
	return Value::Null;
}

// sdl2.SwapBE16
Gura_DeclareFunction(SwapBE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapBE16)
{
#if 0
	SDL_SwapBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapBE16");
	return Value::Null;
}

// sdl2.SwapBE32
Gura_DeclareFunction(SwapBE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapBE32)
{
#if 0
	SDL_SwapBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapBE32");
	return Value::Null;
}

// sdl2.SwapBE64
Gura_DeclareFunction(SwapBE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapBE64)
{
#if 0
	SDL_SwapBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapBE64");
	return Value::Null;
}

// sdl2.SwapFloat
Gura_DeclareFunction(SwapFloat)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapFloat)
{
#if 0
	SDL_SwapFloat();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapFloat");
	return Value::Null;
}

// sdl2.SwapFloatBE
Gura_DeclareFunction(SwapFloatBE)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapFloatBE)
{
#if 0
	SDL_SwapFloatBE();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapFloatBE");
	return Value::Null;
}

// sdl2.SwapFloatLE
Gura_DeclareFunction(SwapFloatLE)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapFloatLE)
{
#if 0
	SDL_SwapFloatLE();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapFloatLE");
	return Value::Null;
}

// sdl2.SwapLE16
Gura_DeclareFunction(SwapLE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapLE16)
{
#if 0
	SDL_SwapLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapLE16");
	return Value::Null;
}

// sdl2.SwapLE32
Gura_DeclareFunction(SwapLE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapLE32)
{
#if 0
	SDL_SwapLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapLE32");
	return Value::Null;
}

// sdl2.SwapLE64
Gura_DeclareFunction(SwapLE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SwapLE64)
{
#if 0
	SDL_SwapLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapLE64");
	return Value::Null;
}

// sdl2.MostSignificantBitIndex32
Gura_DeclareFunction(MostSignificantBitIndex32)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(MostSignificantBitIndex32)
{
#if 0
	Uint32 x = args.GetULong(0);
	int _rtn = SDL_MostSignificantBitIndex32(x);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
#endif
	SetError_NotImpFunction(sig, "MostSignificantBitIndex32");
	return Value::Null;
}

// sdl2.GetPowerInfo
Gura_DeclareFunction(GetPowerInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetPowerInfo)
{
	int secs = 0;
	int pct = 0;
	SDL_PowerState _rtn = SDL_GetPowerInfo(&secs, &pct);
	return ReturnValue(env, sig, args, Value::CreateList(env,
									Value(_rtn), Value(secs), Value(pct)));
}

// sdl2.AndroidGetActivity
Gura_DeclareFunction(AndroidGetActivity)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AndroidGetActivity)
{
#if 0
	SDL_AndroidGetActivity();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetActivity");
	return Value::Null;
}

// sdl2.AndroidGetExternalStoragePath
Gura_DeclareFunction(AndroidGetExternalStoragePath)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AndroidGetExternalStoragePath)
{
#if 0
	SDL_AndroidGetExternalStoragePath();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetExternalStoragePath");
	return Value::Null;
}

// sdl2.AndroidGetExternalStorageState
Gura_DeclareFunction(AndroidGetExternalStorageState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AndroidGetExternalStorageState)
{
#if 0
	SDL_AndroidGetExternalStorageState();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetExternalStorageState");
	return Value::Null;
}

// sdl2.AndroidGetInternalStoragePath
Gura_DeclareFunction(AndroidGetInternalStoragePath)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AndroidGetInternalStoragePath)
{
#if 0
	SDL_AndroidGetInternalStoragePath();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetInternalStoragePath");
	return Value::Null;
}

// sdl2.AndroidGetJNIEnv
Gura_DeclareFunction(AndroidGetJNIEnv)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(AndroidGetJNIEnv)
{
#if 0
	SDL_AndroidGetJNIEnv();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetJNIEnv");
	return Value::Null;
}

// sdl2.acos
Gura_DeclareFunction(acos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(acos)
{
	double x = args.GetDouble(0);
	double _rtn = SDL_acos(x);
	Value _rtnVal = Value(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}


// sdl2.test()
Gura_DeclareFunction(test)
{
}

Gura_ImplementFunction(test)
{
	return Value::Null;
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
		Gura_AssignFunction(VERSION);
		Gura_AssignFunction(VERSION_ATLEAST);
		Gura_AssignFunction(CreateWindow);
		Gura_AssignFunction(CreateWindowAndRenderer);
		Gura_AssignFunction(CreateWindowFrom);
		Gura_AssignFunction(DestroyWindow);
		Gura_AssignFunction(DisableScreenSaver);
		Gura_AssignFunction(EnableScreenSaver);
		Gura_AssignFunction(GL_CreateContext);
		Gura_AssignFunction(GL_DeleteContext);
		Gura_AssignFunction(GL_ExtensionSupported);
		Gura_AssignFunction(GL_GetAttribute);
		Gura_AssignFunction(GL_GetCurrentContext);
		Gura_AssignFunction(GL_GetCurrentWindow);
		Gura_AssignFunction(GL_GetDrawableSize);
		Gura_AssignFunction(GL_GetProcAddress);
		Gura_AssignFunction(GL_GetSwapInterval);
		Gura_AssignFunction(GL_LoadLibrary);
		Gura_AssignFunction(GL_MakeCurrent);
		Gura_AssignFunction(GL_ResetAttributes);
		Gura_AssignFunction(GL_SetAttribute);
		Gura_AssignFunction(GL_SetSwapInterval);
		Gura_AssignFunction(GL_SwapWindow);
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
		Gura_AssignFunction(GetWindowBrightness);
		Gura_AssignFunction(GetWindowData);
		Gura_AssignFunction(GetWindowDisplayIndex);
		Gura_AssignFunction(GetWindowDisplayMode);
		Gura_AssignFunction(GetWindowFlags);
		Gura_AssignFunction(GetWindowFromID);
		Gura_AssignFunction(GetWindowGammaRamp);
		Gura_AssignFunction(GetWindowGrab);
		Gura_AssignFunction(GetWindowID);
		Gura_AssignFunction(GetWindowMaximumSize);
		Gura_AssignFunction(GetWindowMinimumSize);
		Gura_AssignFunction(GetWindowPixelFormat);
		Gura_AssignFunction(GetWindowPosition);
		Gura_AssignFunction(GetWindowSize);
		Gura_AssignFunction(GetWindowSurface);
		Gura_AssignFunction(GetWindowTitle);
		Gura_AssignFunction(GetWindowWMInfo);
		Gura_AssignFunction(HideWindow);
		Gura_AssignFunction(IsScreenSaverEnabled);
		Gura_AssignFunction(MaximizeWindow);
		Gura_AssignFunction(MinimizeWindow);
		Gura_AssignFunction(RaiseWindow);
		Gura_AssignFunction(RestoreWindow);
		Gura_AssignFunction(SetWindowBordered);
		Gura_AssignFunction(SetWindowBrightness);
		Gura_AssignFunction(SetWindowData);
		Gura_AssignFunction(SetWindowDisplayMode);
		Gura_AssignFunction(SetWindowFullscreen);
		Gura_AssignFunction(SetWindowGammaRamp);
		Gura_AssignFunction(SetWindowGrab);
		Gura_AssignFunction(SetWindowHitTest);
		Gura_AssignFunction(SetWindowIcon);
		Gura_AssignFunction(SetWindowMaximumSize);
		Gura_AssignFunction(SetWindowMinimumSize);
		Gura_AssignFunction(SetWindowPosition);
		Gura_AssignFunction(SetWindowSize);
		Gura_AssignFunction(SetWindowTitle);
		Gura_AssignFunction(ShowMessageBox);
		Gura_AssignFunction(ShowSimpleMessageBox);
		Gura_AssignFunction(ShowWindow);
		Gura_AssignFunction(UpdateWindowSurface);
		Gura_AssignFunction(UpdateWindowSurfaceRects);
		Gura_AssignFunction(VideoInit);
		Gura_AssignFunction(VideoQuit);
		Gura_AssignFunction(CreateRenderer);
		Gura_AssignFunction(CreateSoftwareRenderer);
		Gura_AssignFunction(CreateTexture);
		Gura_AssignFunction(CreateTextureFromSurface);
		Gura_AssignFunction(DestroyRenderer);
		Gura_AssignFunction(DestroyTexture);
		Gura_AssignFunction(GL_BindTexture);
		Gura_AssignFunction(GL_UnbindTexture);
		Gura_AssignFunction(GetNumRenderDrivers);
		Gura_AssignFunction(GetRenderDrawBlendMode);
		Gura_AssignFunction(GetRenderDrawColor);
		Gura_AssignFunction(GetRenderDriverInfo);
		Gura_AssignFunction(GetRenderTarget);
		Gura_AssignFunction(GetRenderer);
		Gura_AssignFunction(GetRendererInfo);
		Gura_AssignFunction(GetRenderOutputSize);
		Gura_AssignFunction(GetTextureAlphaMod);
		Gura_AssignFunction(GetTextureBlendMode);
		Gura_AssignFunction(GetTextureColorMod);
		Gura_AssignFunction(LockTexture);
		Gura_AssignFunction(QueryTexture);
		Gura_AssignFunction(RenderClear);
		Gura_AssignFunction(RenderCopy);
		Gura_AssignFunction(RenderCopyEx);
		Gura_AssignFunction(RenderDrawLine);
		Gura_AssignFunction(RenderDrawLines);
		Gura_AssignFunction(RenderDrawPoint);
		Gura_AssignFunction(RenderDrawPoints);
		Gura_AssignFunction(RenderDrawRect);
		Gura_AssignFunction(RenderDrawRects);
		Gura_AssignFunction(RenderFillRect);
		Gura_AssignFunction(RenderFillRects);
		Gura_AssignFunction(RenderGetClipRect);
		Gura_AssignFunction(RenderGetLogicalSize);
		Gura_AssignFunction(RenderGetScale);
		Gura_AssignFunction(RenderGetViewport);
		Gura_AssignFunction(RenderIsClipEnabled);
		Gura_AssignFunction(RenderPresent);
		Gura_AssignFunction(RenderReadPixels);
		Gura_AssignFunction(RenderSetClipRect);
		Gura_AssignFunction(RenderSetLogicalSize);
		Gura_AssignFunction(RenderSetScale);
		Gura_AssignFunction(RenderSetViewport);
		Gura_AssignFunction(RenderTargetSupported);
		Gura_AssignFunction(SetRenderDrawBlendMode);
		Gura_AssignFunction(SetRenderDrawColor);
		Gura_AssignFunction(SetRenderTarget);
		Gura_AssignFunction(SetTextureAlphaMod);
		Gura_AssignFunction(SetTextureBlendMode);
		Gura_AssignFunction(SetTextureColorMod);
		Gura_AssignFunction(UnlockTexture);
		Gura_AssignFunction(UpdateTexture);
		Gura_AssignFunction(UpdateYUVTexture);
		Gura_AssignFunction(AllocFormat);
		Gura_AssignFunction(AllocPalette);
		Gura_AssignFunction(CalculateGammaRamp);
		Gura_AssignFunction(FreeFormat);
		Gura_AssignFunction(FreePalette);
		Gura_AssignFunction(GetPixelFormatName);
		Gura_AssignFunction(GetRGB);
		Gura_AssignFunction(GetRGBA);
		Gura_AssignFunction(MapRGB);
		Gura_AssignFunction(MapRGBA);
		Gura_AssignFunction(MasksToPixelFormatEnum);
		Gura_AssignFunction(PixelFormatEnumToMasks);
		Gura_AssignFunction(SetPaletteColors);
		Gura_AssignFunction(SetPixelFormatPalette);
		Gura_AssignFunction(EnclosePoints);
		Gura_AssignFunction(HasIntersection);
		Gura_AssignFunction(IntersectRect);
		Gura_AssignFunction(IntersectRectAndLine);
		Gura_AssignFunction(PointInRect);
		Gura_AssignFunction(RectEmpty);
		Gura_AssignFunction(RectEquals);
		Gura_AssignFunction(UnionRect);
		Gura_AssignFunction(BlitScaled);
		Gura_AssignFunction(BlitSurface);
		Gura_AssignFunction(ConvertPixels);
		Gura_AssignFunction(ConvertSurface);
		Gura_AssignFunction(ConvertSurfaceFormat);
		Gura_AssignFunction(CreateRGBSurface);
		Gura_AssignFunction(CreateRGBSurfaceFrom);
		Gura_AssignFunction(CreateRGBSurfaceFromImage);
		Gura_AssignFunction(FillRect);
		Gura_AssignFunction(FillRects);
		Gura_AssignFunction(FreeSurface);
		Gura_AssignFunction(GetClipRect);
		Gura_AssignFunction(GetColorKey);
		Gura_AssignFunction(GetSurfaceAlphaMod);
		Gura_AssignFunction(GetSurfaceBlendMode);
		Gura_AssignFunction(GetSurfaceColorMod);
		Gura_AssignFunction(LoadBMP);
		Gura_AssignFunction(LoadBMP_RW);
		Gura_AssignFunction(LockSurface);
		Gura_AssignFunction(LowerBlit);
		Gura_AssignFunction(LowerBlitScaled);
		Gura_AssignFunction(MUSTLOCK);
		Gura_AssignFunction(SaveBMP);
		Gura_AssignFunction(SaveBMP_RW);
		Gura_AssignFunction(SetClipRect);
		Gura_AssignFunction(SetColorKey);
		Gura_AssignFunction(SetSurfaceAlphaMod);
		Gura_AssignFunction(SetSurfaceBlendMode);
		Gura_AssignFunction(SetSurfaceColorMod);
		Gura_AssignFunction(SetSurfacePalette);
		Gura_AssignFunction(SetSurfaceRLE);
		Gura_AssignFunction(UnlockSurface);
		Gura_AssignFunction(GetClipboardText);
		Gura_AssignFunction(HasClipboardText);
		Gura_AssignFunction(SetClipboardText);
		Gura_AssignFunction(AddEventWatch);
		Gura_AssignFunction(DelEventWatch);
		Gura_AssignFunction(EventState);
		Gura_AssignFunction(FilterEvents);
		Gura_AssignFunction(FlushEvent);
		Gura_AssignFunction(FlushEvents);
		Gura_AssignFunction(GetEventFilter);
		Gura_AssignFunction(GetNumTouchDevices);
		Gura_AssignFunction(GetNumTouchFingers);
		Gura_AssignFunction(GetTouchDevice);
		Gura_AssignFunction(GetTouchFinger);
		Gura_AssignFunction(HasEvent);
		Gura_AssignFunction(HasEvents);
		Gura_AssignFunction(LoadDollarTemplates);
		Gura_AssignFunction(AddEvents);
		Gura_AssignFunction(PeekEvents);
		Gura_AssignFunction(GetEvents);
		Gura_AssignFunction(PollEvent);
		Gura_AssignFunction(PumpEvents);
		Gura_AssignFunction(PushEvent);
		Gura_AssignFunction(QuitRequested);
		Gura_AssignFunction(RecordGesture);
		Gura_AssignFunction(RegisterEvents);
		Gura_AssignFunction(SaveAllDollarTemplates);
		Gura_AssignFunction(SaveDollarTemplate);
		Gura_AssignFunction(SetEventFilter);
		Gura_AssignFunction(WaitEvent);
		Gura_AssignFunction(WaitEventTimeout);
		Gura_AssignFunction(GetKeyFromName);
		Gura_AssignFunction(GetKeyFromScancode);
		Gura_AssignFunction(GetKeyName);
		Gura_AssignFunction(GetKeyboardFocus);
		Gura_AssignFunction(GetKeyboardState);
		Gura_AssignFunction(GetModState);
		Gura_AssignFunction(GetScancodeFromKey);
		Gura_AssignFunction(GetScancodeFromName);
		Gura_AssignFunction(GetScancodeName);
		Gura_AssignFunction(HasScreenKeyboardSupport);
		Gura_AssignFunction(IsScreenKeyboardShown);
		Gura_AssignFunction(IsTextInputActive);
		Gura_AssignFunction(SetModState);
		Gura_AssignFunction(SetTextInputRect);
		Gura_AssignFunction(StartTextInput);
		Gura_AssignFunction(StopTextInput);
		Gura_AssignFunction(CaptureMouse);
		Gura_AssignFunction(CreateColorCursor);
		Gura_AssignFunction(CreateCursor);
		Gura_AssignFunction(CreateSystemCursor);
		Gura_AssignFunction(FreeCursor);
		Gura_AssignFunction(GetCursor);
		Gura_AssignFunction(GetDefaultCursor);
		Gura_AssignFunction(GetGlobalMouseState);
		Gura_AssignFunction(GetMouseFocus);
		Gura_AssignFunction(GetMouseState);
		Gura_AssignFunction(GetRelativeMouseMode);
		Gura_AssignFunction(GetRelativeMouseState);
		Gura_AssignFunction(SetCursor);
		Gura_AssignFunction(SetRelativeMouseMode);
		Gura_AssignFunction(ShowCursor);
		Gura_AssignFunction(WarpMouseGlobal);
		Gura_AssignFunction(WarpMouseInWindow);
		Gura_AssignFunction(JoystickClose);
		Gura_AssignFunction(JoystickEventState);
		Gura_AssignFunction(JoystickGetAttached);
		Gura_AssignFunction(JoystickGetAxis);
		Gura_AssignFunction(JoystickGetBall);
		Gura_AssignFunction(JoystickGetButton);
		Gura_AssignFunction(JoystickGetDeviceGUID);
		Gura_AssignFunction(JoystickGetGUID);
		Gura_AssignFunction(JoystickGetGUIDFromString);
		Gura_AssignFunction(JoystickGetGUIDString);
		Gura_AssignFunction(JoystickGetHat);
		Gura_AssignFunction(JoystickInstanceID);
		Gura_AssignFunction(JoystickName);
		Gura_AssignFunction(JoystickNameForIndex);
		Gura_AssignFunction(JoystickNumAxes);
		Gura_AssignFunction(JoystickNumBalls);
		Gura_AssignFunction(JoystickNumButtons);
		Gura_AssignFunction(JoystickNumHats);
		Gura_AssignFunction(JoystickOpen);
		Gura_AssignFunction(JoystickUpdate);
		Gura_AssignFunction(NumJoysticks);
		Gura_AssignFunction(GameControllerAddMapping);
		Gura_AssignFunction(GameControllerAddMappingsFromFile);
		Gura_AssignFunction(GameControllerAddMappingsFromRW);
		Gura_AssignFunction(GameControllerClose);
		Gura_AssignFunction(GameControllerEventState);
		Gura_AssignFunction(GameControllerGetAttached);
		Gura_AssignFunction(GameControllerGetAxis);
		Gura_AssignFunction(GameControllerGetAxisFromString);
		Gura_AssignFunction(GameControllerGetBindForAxis);
		Gura_AssignFunction(GameControllerGetBindForButton);
		Gura_AssignFunction(GameControllerGetButton);
		Gura_AssignFunction(GameControllerGetButtonFromString);
		Gura_AssignFunction(GameControllerGetJoystick);
		Gura_AssignFunction(GameControllerGetStringForAxis);
		Gura_AssignFunction(GameControllerGetStringForButton);
		Gura_AssignFunction(GameControllerMapping);
		Gura_AssignFunction(GameControllerMappingForGUID);
		Gura_AssignFunction(GameControllerName);
		Gura_AssignFunction(GameControllerNameForIndex);
		Gura_AssignFunction(GameControllerOpen);
		Gura_AssignFunction(GameControllerUpdate);
		Gura_AssignFunction(IsGameController);
		Gura_AssignFunction(HapticClose);
		Gura_AssignFunction(HapticDestroyEffect);
		Gura_AssignFunction(HapticEffectSupported);
		Gura_AssignFunction(HapticGetEffectStatus);
		Gura_AssignFunction(HapticIndex);
		Gura_AssignFunction(HapticName);
		Gura_AssignFunction(HapticNewEffect);
		Gura_AssignFunction(HapticNumAxes);
		Gura_AssignFunction(HapticNumEffects);
		Gura_AssignFunction(HapticNumEffectsPlaying);
		Gura_AssignFunction(HapticOpen);
		Gura_AssignFunction(HapticOpenFromJoystick);
		Gura_AssignFunction(HapticOpenFromMouse);
		Gura_AssignFunction(HapticOpened);
		Gura_AssignFunction(HapticPause);
		Gura_AssignFunction(HapticQuery);
		Gura_AssignFunction(HapticRumbleInit);
		Gura_AssignFunction(HapticRumblePlay);
		Gura_AssignFunction(HapticRumbleStop);
		Gura_AssignFunction(HapticRumbleSupported);
		Gura_AssignFunction(HapticRunEffect);
		Gura_AssignFunction(HapticSetAutocenter);
		Gura_AssignFunction(HapticSetGain);
		Gura_AssignFunction(HapticStopAll);
		Gura_AssignFunction(HapticStopEffect);
		Gura_AssignFunction(HapticUnpause);
		Gura_AssignFunction(HapticUpdateEffect);
		Gura_AssignFunction(JoystickIsHaptic);
		Gura_AssignFunction(MouseIsHaptic);
		Gura_AssignFunction(NumHaptics);
		Gura_AssignFunction(AudioInit);
		Gura_AssignFunction(AudioQuit);
		Gura_AssignFunction(BuildAudioCVT);
		Gura_AssignFunction(ClearQueuedAudio);
		Gura_AssignFunction(CloseAudio);
		Gura_AssignFunction(CloseAudioDevice);
		Gura_AssignFunction(ConvertAudio);
		Gura_AssignFunction(FreeWAV);
		Gura_AssignFunction(GetAudioDeviceName);
		Gura_AssignFunction(GetAudioDeviceStatus);
		Gura_AssignFunction(GetAudioDriver);
		Gura_AssignFunction(GetAudioStatus);
		Gura_AssignFunction(GetCurrentAudioDriver);
		Gura_AssignFunction(GetNumAudioDevices);
		Gura_AssignFunction(GetNumAudioDrivers);
		Gura_AssignFunction(GetQueuedAudioSize);
		Gura_AssignFunction(LoadWAV);
		Gura_AssignFunction(LoadWAV_RW);
		Gura_AssignFunction(LockAudio);
		Gura_AssignFunction(LockAudioDevice);
		Gura_AssignFunction(MixAudio);
		Gura_AssignFunction(MixAudioFormat);
		Gura_AssignFunction(OpenAudio);
		Gura_AssignFunction(OpenAudioDevice);
		Gura_AssignFunction(PauseAudio);
		Gura_AssignFunction(PauseAudioDevice);
		Gura_AssignFunction(QueueAudio);
		Gura_AssignFunction(UnlockAudio);
		Gura_AssignFunction(UnlockAudioDevice);
		Gura_AssignFunction(AUDIO_BITSIZE);
		Gura_AssignFunction(AUDIO_ISFLOAT);
		Gura_AssignFunction(AUDIO_ISBIGENDIAN);
		Gura_AssignFunction(AUDIO_ISSIGNED);
		Gura_AssignFunction(AUDIO_ISINT);
		Gura_AssignFunction(AUDIO_ISLITTLEENDIAN);
		Gura_AssignFunction(AUDIO_ISUNSIGNED);
		Gura_AssignFunction(CreateThread);
		Gura_AssignFunction(DetachThread);
		Gura_AssignFunction(GetThreadID);
		Gura_AssignFunction(GetThreadName);
		Gura_AssignFunction(GetThreadPriority);
		Gura_AssignFunction(TLSCreate);
		Gura_AssignFunction(TLSGet);
		Gura_AssignFunction(TLSSet);
		Gura_AssignFunction(ThreadID);
		Gura_AssignFunction(WaitThread);
		Gura_AssignFunction(CondBroadcast);
		Gura_AssignFunction(CondSignal);
		Gura_AssignFunction(CondWait);
		Gura_AssignFunction(CondWaitTimeout);
		Gura_AssignFunction(CreateCond);
		Gura_AssignFunction(CreateMutex);
		Gura_AssignFunction(CreateSemaphore);
		Gura_AssignFunction(DestroyCond);
		Gura_AssignFunction(DestroyMutex);
		Gura_AssignFunction(DestroySemaphore);
		Gura_AssignFunction(LockMutex);
		Gura_AssignFunction(SemPost);
		Gura_AssignFunction(SemTryWait);
		Gura_AssignFunction(SemValue);
		Gura_AssignFunction(SemWait);
		Gura_AssignFunction(SemWaitTimeout);
		Gura_AssignFunction(TryLockMutex);
		Gura_AssignFunction(UnlockMutex);
		Gura_AssignFunction(AtomicAdd);
		Gura_AssignFunction(AtomicCAS);
		Gura_AssignFunction(AtomicCASPtr);
		Gura_AssignFunction(AtomicDecRef);
		Gura_AssignFunction(AtomicGet);
		Gura_AssignFunction(AtomicGetPtr);
		Gura_AssignFunction(AtomicIncRef);
		Gura_AssignFunction(AtomicLock);
		Gura_AssignFunction(AtomicSet);
		Gura_AssignFunction(AtomicSetPtr);
		Gura_AssignFunction(AtomicTryLock);
		Gura_AssignFunction(AtomicUnlock);
		Gura_AssignFunction(CompilerBarrier);
		Gura_AssignFunction(AddTimer);
		Gura_AssignFunction(Delay);
		Gura_AssignFunction(GetPerformanceCounter);
		Gura_AssignFunction(GetPerformanceFrequency);
		Gura_AssignFunction(GetTicks);
		Gura_AssignFunction(RemoveTimer);
		Gura_AssignFunction(TICKS_PASSED);
		Gura_AssignFunction(GetBasePath);
		Gura_AssignFunction(GetPrefPath);
		Gura_AssignFunction(AllocRW);
		Gura_AssignFunction(FreeRW);
		Gura_AssignFunction(RWFromConstMem);
		Gura_AssignFunction(RWFromFP);
		Gura_AssignFunction(RWFromFile);
		Gura_AssignFunction(RWFromMem);
		Gura_AssignFunction(RWclose);
		Gura_AssignFunction(RWread);
		Gura_AssignFunction(RWseek);
		Gura_AssignFunction(RWtell);
		Gura_AssignFunction(RWwrite);
		Gura_AssignFunction(ReadBE16);
		Gura_AssignFunction(ReadBE32);
		Gura_AssignFunction(ReadBE64);
		Gura_AssignFunction(ReadLE16);
		Gura_AssignFunction(ReadLE32);
		Gura_AssignFunction(ReadLE64);
		Gura_AssignFunction(WriteBE16);
		Gura_AssignFunction(WriteBE32);
		Gura_AssignFunction(WriteBE64);
		Gura_AssignFunction(WriteLE16);
		Gura_AssignFunction(WriteLE32);
		Gura_AssignFunction(WriteLE64);
		Gura_AssignFunction(GetPlatform);
		Gura_AssignFunction(GetCPUCacheLineSize);
		Gura_AssignFunction(GetCPUCount);
		Gura_AssignFunction(GetSystemRAM);
		Gura_AssignFunction(Has3DNow);
		Gura_AssignFunction(HasAVX);
		Gura_AssignFunction(HasAVX2);
		Gura_AssignFunction(HasAltiVec);
		Gura_AssignFunction(HasMMX);
		Gura_AssignFunction(HasRDTSC);
		Gura_AssignFunction(HasSSE);
		Gura_AssignFunction(HasSSE2);
		Gura_AssignFunction(HasSSE3);
		Gura_AssignFunction(HasSSE41);
		Gura_AssignFunction(HasSSE42);
		Gura_AssignFunction(Swap16);
		Gura_AssignFunction(Swap32);
		Gura_AssignFunction(Swap64);
		Gura_AssignFunction(SwapBE16);
		Gura_AssignFunction(SwapBE32);
		Gura_AssignFunction(SwapBE64);
		Gura_AssignFunction(SwapFloat);
		Gura_AssignFunction(SwapFloatBE);
		Gura_AssignFunction(SwapFloatLE);
		Gura_AssignFunction(SwapLE16);
		Gura_AssignFunction(SwapLE32);
		Gura_AssignFunction(SwapLE64);
		Gura_AssignFunction(MostSignificantBitIndex32);
		Gura_AssignFunction(GetPowerInfo);
		Gura_AssignFunction(AndroidGetActivity);
		Gura_AssignFunction(AndroidGetExternalStoragePath);
		Gura_AssignFunction(AndroidGetExternalStorageState);
		Gura_AssignFunction(AndroidGetInternalStoragePath);
		Gura_AssignFunction(AndroidGetJNIEnv);
		Gura_AssignFunction(acos);
	Gura_AssignFunction(test);
}

Gura_EndModuleScope(sdl2)
