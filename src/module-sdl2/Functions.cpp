#include "stdafx.h"

#undef CreateWindow
#undef CreateMutex
#undef CreateSemaphore

Gura_BeginModuleScope(sdl2)

// sdl2.sdl_Init
Gura_DeclareFunction(sdl_Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Init)
{
	Uint32 flags = args.GetULong(0);
	int _rtn = SDL_Init(flags);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_InitSubSystem
Gura_DeclareFunction(sdl_InitSubSystem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_InitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	int _rtn = SDL_InitSubSystem(flags);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_Quit
Gura_DeclareFunction(sdl_Quit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Quit)
{
	SDL_Quit();
	return Value::Null;
}

// sdl2.sdl_QuitSubSystem
Gura_DeclareFunction(sdl_QuitSubSystem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_QuitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	SDL_QuitSubSystem(flags);
	return Value::Null;
}

// sdl2.sdl_SetMainReady
Gura_DeclareFunction(sdl_SetMainReady)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetMainReady)
{
	SDL_SetMainReady();
	return Value::Null;
}

// sdl2.sdl_WasInit
Gura_DeclareFunction(sdl_WasInit)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WasInit)
{
	Uint32 flags = args.GetULong(0);
	Uint32 _rtn = SDL_WasInit(flags);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_AddHintCallback
Gura_DeclareFunction(sdl_AddHintCallback)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AddHintCallback)
{
#if 0
	SDL_AddHintCallback();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AddHintCallback");
	return Value::Null;
}

// sdl2.sdl_ClearHints
Gura_DeclareFunction(sdl_ClearHints)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ClearHints)
{
#if 0
	SDL_ClearHints();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ClearHints");
	return Value::Null;
}

// sdl2.sdl_DelhintCallback
Gura_DeclareFunction(sdl_DelhintCallback)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DelhintCallback)
{
#if 0
	SDL_DelhintCallback();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_DelhintCallback");
	return Value::Null;
}

// sdl2.sdl_GetHint
Gura_DeclareFunction(sdl_GetHint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetHint)
{
#if 0
	SDL_GetHint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetHint");
	return Value::Null;
}

// sdl2.sdl_SetHint
Gura_DeclareFunction(sdl_SetHint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetHint)
{
#if 0
	SDL_SetHint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SetHint");
	return Value::Null;
}

// sdl2.sdl_SetHintWithPriority
Gura_DeclareFunction(sdl_SetHintWithPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetHintWithPriority)
{
#if 0
	SDL_SetHintWithPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SetHintWithPriority");
	return Value::Null;
}

// sdl2.sdl_ClearError
Gura_DeclareFunction(sdl_ClearError)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ClearError)
{
	SDL_ClearError();
	return Value::Null;
}

// sdl2.sdl_GetError
Gura_DeclareFunction(sdl_GetError)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetError)
{
	const char *_rtn = SDL_GetError();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_SetError
Gura_DeclareFunction(sdl_SetError)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetError)
{
#if 0
	SDL_SetError();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SetError");
	return Value::Null;
}

// sdl2.sdl_Log
Gura_DeclareFunction(sdl_Log)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Log)
{
#if 0
	SDL_Log();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_Log");
	return Value::Null;
}

// sdl2.sdl_LogCritical
Gura_DeclareFunction(sdl_LogCritical)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogCritical)
{
#if 0
	SDL_LogCritical();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogCritical");
	return Value::Null;
}

// sdl2.sdl_LogDebug
Gura_DeclareFunction(sdl_LogDebug)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogDebug)
{
#if 0
	SDL_LogDebug();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogDebug");
	return Value::Null;
}

// sdl2.sdl_LogError
Gura_DeclareFunction(sdl_LogError)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogError)
{
#if 0
	SDL_LogError();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogError");
	return Value::Null;
}

// sdl2.sdl_LogGetOutputFunction
Gura_DeclareFunction(sdl_LogGetOutputFunction)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogGetOutputFunction)
{
#if 0
	SDL_LogGetOutputFunction();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogGetOutputFunction");
	return Value::Null;
}

// sdl2.sdl_LogGetPriority
Gura_DeclareFunction(sdl_LogGetPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogGetPriority)
{
#if 0
	SDL_LogGetPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogGetPriority");
	return Value::Null;
}

// sdl2.sdl_LogInfo
Gura_DeclareFunction(sdl_LogInfo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogInfo)
{
#if 0
	SDL_LogInfo();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogInfo");
	return Value::Null;
}

// sdl2.sdl_LogMessage
Gura_DeclareFunction(sdl_LogMessage)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogMessage)
{
#if 0
	SDL_LogMessage();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogMessage");
	return Value::Null;
}

// sdl2.sdl_LogMessageV
Gura_DeclareFunction(sdl_LogMessageV)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogMessageV)
{
#if 0
	SDL_LogMessageV();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogMessageV");
	return Value::Null;
}

// sdl2.sdl_LogResetPriorities
Gura_DeclareFunction(sdl_LogResetPriorities)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogResetPriorities)
{
#if 0
	SDL_LogResetPriorities();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogResetPriorities");
	return Value::Null;
}

// sdl2.sdl_LogSetAllPriority
Gura_DeclareFunction(sdl_LogSetAllPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogSetAllPriority)
{
#if 0
	SDL_LogSetAllPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogSetAllPriority");
	return Value::Null;
}

// sdl2.sdl_LogSetOutputFunction
Gura_DeclareFunction(sdl_LogSetOutputFunction)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogSetOutputFunction)
{
#if 0
	SDL_LogSetOutputFunction();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogSetOutputFunction");
	return Value::Null;
}

// sdl2.sdl_LogSetPriority
Gura_DeclareFunction(sdl_LogSetPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogSetPriority)
{
#if 0
	SDL_LogSetPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogSetPriority");
	return Value::Null;
}

// sdl2.sdl_LogVerbose
Gura_DeclareFunction(sdl_LogVerbose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogVerbose)
{
#if 0
	SDL_LogVerbose();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogVerbose");
	return Value::Null;
}

// sdl2.sdl_LogWarn
Gura_DeclareFunction(sdl_LogWarn)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LogWarn)
{
#if 0
	SDL_LogWarn();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LogWarn");
	return Value::Null;
}

// sdl2.sdl_GetAssertionHandler
Gura_DeclareFunction(sdl_GetAssertionHandler)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetAssertionHandler)
{
#if 0
	SDL_GetAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetAssertionHandler");
	return Value::Null;
}

// sdl2.sdl_GetAssertionReport
Gura_DeclareFunction(sdl_GetAssertionReport)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetAssertionReport)
{
#if 0
	SDL_GetAssertionReport();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetAssertionReport");
	return Value::Null;
}

// sdl2.sdl_GetDefaultAssertionHandler
Gura_DeclareFunction(sdl_GetDefaultAssertionHandler)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetDefaultAssertionHandler)
{
#if 0
	SDL_GetDefaultAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetDefaultAssertionHandler");
	return Value::Null;
}

// sdl2.sdl_ResetAssertionReport
Gura_DeclareFunction(sdl_ResetAssertionReport)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ResetAssertionReport)
{
#if 0
	SDL_ResetAssertionReport();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ResetAssertionReport");
	return Value::Null;
}

// sdl2.sdl_SetAssertionHandler
Gura_DeclareFunction(sdl_SetAssertionHandler)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetAssertionHandler)
{
#if 0
	SDL_SetAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SetAssertionHandler");
	return Value::Null;
}

// sdl2.sdl_TriggerBreakpoint
Gura_DeclareFunction(sdl_TriggerBreakpoint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_TriggerBreakpoint)
{
#if 0
	SDL_TriggerBreakpoint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_TriggerBreakpoint");
	return Value::Null;
}

// sdl2.sdl_assert
Gura_DeclareFunction(sdl_assert)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_assert)
{
#if 0
	SDL_assert();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_assert");
	return Value::Null;
}

// sdl2.sdl_assert_paranoid
Gura_DeclareFunction(sdl_assert_paranoid)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_assert_paranoid)
{
#if 0
	SDL_assert_paranoid();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_assert_paranoid");
	return Value::Null;
}

// sdl2.sdl_assert_release
Gura_DeclareFunction(sdl_assert_release)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_assert_release)
{
#if 0
	SDL_assert_release();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_assert_release");
	return Value::Null;
}

// sdl2.sdl_GetRevision
Gura_DeclareFunction(sdl_GetRevision)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRevision)
{
	const char *_rtn = SDL_GetRevision();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetRevisionNumber
Gura_DeclareFunction(sdl_GetRevisionNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRevisionNumber)
{
	int _rtn = SDL_GetRevisionNumber();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetVersion
Gura_DeclareFunction(sdl_GetVersion)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetVersion)
{
	SDL_version ver;
	SDL_GetVersion(&ver);
	return ReturnValue(env, sig, args, Value::CreateList(env,
					Value(ver.major), Value(ver.minor), Value(ver.patch)));
}

// sdl2.sdl_VERSION
Gura_DeclareFunction(sdl_VERSION)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_VERSION)
{
	SDL_version ver;
	SDL_VERSION(&ver);
	return ReturnValue(env, sig, args, Value::CreateList(env,
					Value(ver.major), Value(ver.minor), Value(ver.patch)));
}

// sdl2.sdl_VERSION_ATLEAST
Gura_DeclareFunction(sdl_VERSION_ATLEAST)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "X", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_VERSION_ATLEAST)
{
	int X = args.GetInt(0);
	int Y = args.GetInt(1);
	int Z = args.GetInt(2);
	bool _rtn = SDL_VERSION_ATLEAST(X, Y, Z);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_CreateWindow
Gura_DeclareFunction(sdl_CreateWindow)
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

Gura_ImplementFunction(sdl_CreateWindow)
{
	const char *title = args.GetString(0);
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int w = args.GetInt(3);
	int h = args.GetInt(4);
	Uint32 flags = args.GetULong(5);
	SDL_Window *_rtn = SDL_CreateWindow(title, x, y, w, h, flags);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(_rtn)));
}

// sdl2.sdl_CreateWindowAndRenderer
Gura_DeclareFunction(sdl_CreateWindowAndRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "window_flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateWindowAndRenderer)
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

// sdl2.sdl_CreateWindowFrom
Gura_DeclareFunction(sdl_CreateWindowFrom)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateWindowFrom)
{
#if 0
	SDL_CreateWindowFrom();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CreateWindowFrom");
	return Value::Null;
}

// sdl2.sdl_DestroyWindow
Gura_DeclareFunction(sdl_DestroyWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DestroyWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_DestroyWindow(window);
	return Value::Null;
}

// sdl2.sdl_DisableScreenSaver
Gura_DeclareFunction(sdl_DisableScreenSaver)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DisableScreenSaver)
{
	SDL_DisableScreenSaver();
	return Value::Null;
}

// sdl2.sdl_EnableScreenSaver
Gura_DeclareFunction(sdl_EnableScreenSaver)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_EnableScreenSaver)
{
	SDL_EnableScreenSaver();
	return Value::Null;
}

// sdl2.sdl_GL_CreateContext
Gura_DeclareFunction(sdl_GL_CreateContext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_CreateContext)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_GLContext _rtn = SDL_GL_CreateContext(window);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_GLContext(_rtn)));
}

// sdl2.sdl_GL_DeleteContext
Gura_DeclareFunction(sdl_GL_DeleteContext)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "context", VTYPE_GLContext, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_DeleteContext)
{
	SDL_GLContext context = Object_GLContext::GetObject(args, 0)->GetEntity();
	SDL_GL_DeleteContext(context);
	return Value::Null;
}

// sdl2.sdl_GL_ExtensionSupported
Gura_DeclareFunction(sdl_GL_ExtensionSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_ExtensionSupported)
{
	const char *extension = args.GetString(0);
	SDL_bool _rtn = SDL_GL_ExtensionSupported(extension);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_GL_GetAttribute
Gura_DeclareFunction(sdl_GL_GetAttribute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "attr", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_GetAttribute)
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

// sdl2.sdl_GL_GetCurrentContext
Gura_DeclareFunction(sdl_GL_GetCurrentContext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_GetCurrentContext)
{
	SDL_GLContext _rtn = SDL_GL_GetCurrentContext();
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_GLContext(_rtn)));
}

// sdl2.sdl_GL_GetCurrentWindow
Gura_DeclareFunction(sdl_GL_GetCurrentWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_GetCurrentWindow)
{
	SDL_Window *_rtn = SDL_GL_GetCurrentWindow();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(_rtn)));
}

// sdl2.sdl_GL_GetDrawableSize
Gura_DeclareFunction(sdl_GL_GetDrawableSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_GetDrawableSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GL_GetDrawableSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.sdl_GL_GetProcAddress
Gura_DeclareFunction(sdl_GL_GetProcAddress)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_GetProcAddress)
{
#if 0
	SDL_GL_GetProcAddress();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GL_GetProcAddress");
	return Value::Null;
}

// sdl2.sdl_GL_GetSwapInterval
Gura_DeclareFunction(sdl_GL_GetSwapInterval)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_GetSwapInterval)
{
	int _rtn = SDL_GL_GetSwapInterval();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_GL_LoadLibrary
Gura_DeclareFunction(sdl_GL_LoadLibrary)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_LoadLibrary)
{
	const char *path = args.GetString(0);
	int _rtn = SDL_GL_LoadLibrary(path);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_GL_MakeCurrent
Gura_DeclareFunction(sdl_GL_MakeCurrent)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "context", VTYPE_GLContext, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_MakeCurrent)
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

// sdl2.sdl_GL_ResetAttributes
Gura_DeclareFunction(sdl_GL_ResetAttributes)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_ResetAttributes)
{
	SDL_GL_ResetAttributes();
	return Value::Null;
}

// sdl2.sdl_GL_SetAttribute
Gura_DeclareFunction(sdl_GL_SetAttribute)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "attr", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_SetAttribute)
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

// sdl2.sdl_GL_SetSwapInterval
Gura_DeclareFunction(sdl_GL_SetSwapInterval)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "interval", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_SetSwapInterval)
{
	int interval = args.GetInt(0);
	int _rtn = SDL_GL_SetSwapInterval(interval);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_GL_SwapWindow
Gura_DeclareFunction(sdl_GL_SwapWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_SwapWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_GL_SwapWindow(window);
	return Value::Null;
}

// sdl2.sdl_GL_UnloadLibrary
Gura_DeclareFunction(sdl_GL_UnloadLibrary)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_UnloadLibrary)
{
	SDL_GL_UnloadLibrary();
	return Value::Null;
}

// sdl2.sdl_GetClosestDisplayMode
Gura_DeclareFunction(sdl_GetClosestDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetClosestDisplayMode)
{
	int displayIndex = args.GetInt(0);
	const SDL_DisplayMode *mode = Object_DisplayMode::GetObject(args, 1)->GetEntity();
	SDL_DisplayMode closest;
	SDL_DisplayMode *_rtn = SDL_GetClosestDisplayMode(displayIndex, mode, &closest);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_DisplayMode(closest)));
}

// sdl2.sdl_GetCurrentDisplayMode
Gura_DeclareFunction(sdl_GetCurrentDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetCurrentDisplayMode)
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

// sdl2.sdl_GetCurrentVideoDriver
Gura_DeclareFunction(sdl_GetCurrentVideoDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetCurrentVideoDriver)
{
	const char *_rtn = SDL_GetCurrentVideoDriver();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetDesktopDisplayMode
Gura_DeclareFunction(sdl_GetDesktopDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetDesktopDisplayMode)
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

// sdl2.sdl_GetDisplayBounds
Gura_DeclareFunction(sdl_GetDisplayBounds)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetDisplayBounds)
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

// sdl2.sdl_GetDisplayMode
Gura_DeclareFunction(sdl_GetDisplayMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "modeIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetDisplayMode)
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

// sdl2.sdl_GetDisplayName
Gura_DeclareFunction(sdl_GetDisplayName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dipslayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetDisplayName)
{
	int dipslayIndex = args.GetInt(0);
	const char *_rtn = SDL_GetDisplayName(dipslayIndex);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetNumDisplayModes
Gura_DeclareFunction(sdl_GetNumDisplayModes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumDisplayModes)
{
	int displayIndex = args.GetInt(0);
	int _rtn = SDL_GetNumDisplayModes(displayIndex);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetNumVideoDisplays
Gura_DeclareFunction(sdl_GetNumVideoDisplays)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumVideoDisplays)
{
	int _rtn = SDL_GetNumVideoDisplays();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetNumVideoDrivers
Gura_DeclareFunction(sdl_GetNumVideoDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumVideoDrivers)
{
	int _rtn = SDL_GetNumVideoDrivers();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetVideoDriver
Gura_DeclareFunction(sdl_GetVideoDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetVideoDriver)
{
	int index = args.GetInt(0);
	const char *_rtn = SDL_GetVideoDriver(index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetWindowBrightness
Gura_DeclareFunction(sdl_GetWindowBrightness)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowBrightness)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	float _rtn = SDL_GetWindowBrightness(window);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetWindowData
Gura_DeclareFunction(sdl_GetWindowData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowData)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *name = args.GetString(1);
	SDL_GetWindowData(window, name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetWindowData");
	return Value::Null;
}

// sdl2.sdl_GetWindowDisplayIndex
Gura_DeclareFunction(sdl_GetWindowDisplayIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowDisplayIndex)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_GetWindowDisplayIndex(window);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetWindowDisplayMode
Gura_DeclareFunction(sdl_GetWindowDisplayMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowDisplayMode)
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

// sdl2.sdl_GetWindowFlags
Gura_DeclareFunction(sdl_GetWindowFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowFlags)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowFlags(window);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetWindowFromID
Gura_DeclareFunction(sdl_GetWindowFromID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowFromID)
{
	Uint32 id = args.GetULong(0);
	SDL_Window *_rtn = SDL_GetWindowFromID(id);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(_rtn)));
}

// sdl2.sdl_GetWindowGammaRamp
Gura_DeclareFunction(sdl_GetWindowGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowGammaRamp)
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

// sdl2.sdl_GetWindowGrab
Gura_DeclareFunction(sdl_GetWindowGrab)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowGrab)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_GetWindowGrab(window);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_GetWindowID
Gura_DeclareFunction(sdl_GetWindowID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowID)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowID(window);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetWindowMaximumSize
Gura_DeclareFunction(sdl_GetWindowMaximumSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowMaximumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowMaximumSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.sdl_GetWindowMinimumSize
Gura_DeclareFunction(sdl_GetWindowMinimumSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowMinimumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowMinimumSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.sdl_GetWindowPixelFormat
Gura_DeclareFunction(sdl_GetWindowPixelFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowPixelFormat)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowPixelFormat(window);
	if (_rtn == SDL_PIXELFORMAT_UNKNOWN) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetWindowPosition
Gura_DeclareFunction(sdl_GetWindowPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowPosition)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = 0;
	int y = 0;
	SDL_GetWindowPosition(window, &x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(x), Value(y)));
}

// sdl2.sdl_GetWindowSize
Gura_DeclareFunction(sdl_GetWindowSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.sdl_GetWindowSurface
Gura_DeclareFunction(sdl_GetWindowSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowSurface)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_Surface *_rtn = SDL_GetWindowSurface(window);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.sdl_GetWindowTitle
Gura_DeclareFunction(sdl_GetWindowTitle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowTitle)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GetWindowTitle(window);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetWindowWMInfo
Gura_DeclareFunction(sdl_GetWindowWMInfo)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetWindowWMInfo)
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
	SetError_NotImpFunction(sig, "sdl_GetWindowWMInfo");
	return Value::Null;
}

// sdl2.sdl_HideWindow
Gura_DeclareFunction(sdl_HideWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HideWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_HideWindow(window);
	return Value::Null;
}

// sdl2.sdl_IsScreenSaverEnabled
Gura_DeclareFunction(sdl_IsScreenSaverEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_IsScreenSaverEnabled)
{
	SDL_bool _rtn = SDL_IsScreenSaverEnabled();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_MaximizeWindow
Gura_DeclareFunction(sdl_MaximizeWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_MaximizeWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_MaximizeWindow(window);
	return Value::Null;
}

// sdl2.sdl_MinimizeWindow
Gura_DeclareFunction(sdl_MinimizeWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_MinimizeWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_MinimizeWindow(window);
	return Value::Null;
}

// sdl2.sdl_RaiseWindow
Gura_DeclareFunction(sdl_RaiseWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RaiseWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_RaiseWindow(window);
	return Value::Null;
}

// sdl2.sdl_RestoreWindow
Gura_DeclareFunction(sdl_RestoreWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RestoreWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_RestoreWindow(window);
	return Value::Null;
}

// sdl2.sdl_SetWindowBordered
Gura_DeclareFunction(sdl_SetWindowBordered)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bordered", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowBordered)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool bordered = (args.GetBoolean(1)? SDL_TRUE : SDL_FALSE);
	SDL_SetWindowBordered(window, bordered);
	return Value::Null;
}

// sdl2.sdl_SetWindowBrightness
Gura_DeclareFunction(sdl_SetWindowBrightness)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowBrightness)
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

// sdl2.sdl_SetWindowData
Gura_DeclareFunction(sdl_SetWindowData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowData)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *name = args.GetString(1);
	SDL_SetWindowData(window, name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SetWindowData");
	return Value::Null;
}

// sdl2.sdl_SetWindowDisplayMode
Gura_DeclareFunction(sdl_SetWindowDisplayMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowDisplayMode)
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

// sdl2.sdl_SetWindowFullscreen
Gura_DeclareFunction(sdl_SetWindowFullscreen)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowFullscreen)
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

// sdl2.sdl_SetWindowGammaRamp
Gura_DeclareFunction(sdl_SetWindowGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowGammaRamp)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	CArray<Uint16> red = args.GetList(1);
	CArray<Uint16> green = args.GetList(2);
	CArray<Uint16> blue = args.GetList(3);
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

// sdl2.sdl_SetWindowGrab
Gura_DeclareFunction(sdl_SetWindowGrab)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "grabbed", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowGrab)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool grabbed = (args.GetBoolean(1)? SDL_TRUE : SDL_FALSE);
	SDL_SetWindowGrab(window, grabbed);
	return Value::Null;
}

// sdl2.sdl_SetWindowHitTest
Gura_DeclareFunction(sdl_SetWindowHitTest)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowHitTest)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_SetWindowHitTest(window);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SetWindowHitTest");
	return Value::Null;
}

// sdl2.sdl_SetWindowIcon
Gura_DeclareFunction(sdl_SetWindowIcon)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "icon", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowIcon)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_Surface *icon = Object_Surface::GetObject(args, 1)->GetEntity();
	SDL_SetWindowIcon(window, icon);
	return Value::Null;
}

// sdl2.sdl_SetWindowMaximumSize
Gura_DeclareFunction(sdl_SetWindowMaximumSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "max_w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "max_h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowMaximumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int max_w = args.GetInt(1);
	int max_h = args.GetInt(2);
	SDL_SetWindowMaximumSize(window, max_w, max_h);
	return Value::Null;
}

// sdl2.sdl_SetWindowMinimumSize
Gura_DeclareFunction(sdl_SetWindowMinimumSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "min_w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "min_h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowMinimumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int min_w = args.GetInt(1);
	int min_h = args.GetInt(2);
	SDL_SetWindowMinimumSize(window, min_w, min_h);
	return Value::Null;
}

// sdl2.sdl_SetWindowPosition
Gura_DeclareFunction(sdl_SetWindowPosition)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowPosition)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	SDL_SetWindowPosition(window, x, y);
	return Value::Null;
}

// sdl2.sdl_SetWindowSize
Gura_DeclareFunction(sdl_SetWindowSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = args.GetInt(1);
	int h = args.GetInt(2);
	SDL_SetWindowSize(window, w, h);
	return Value::Null;
}

// sdl2.sdl_SetWindowTitle
Gura_DeclareFunction(sdl_SetWindowTitle)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetWindowTitle)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *title = args.GetString(1);
	SDL_SetWindowTitle(window, title);
	return Value::Null;
}

// sdl2.sdl_ShowMessageBox
Gura_DeclareFunction(sdl_ShowMessageBox)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ShowMessageBox)
{
#if 0
	int _rtn = SDL_ShowMessageBox();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ShowMessageBox");
	return Value::Null;
}

// sdl2.sdl_ShowSimpleMessageBox
Gura_DeclareFunction(sdl_ShowSimpleMessageBox)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ShowSimpleMessageBox)
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

// sdl2.sdl_ShowWindow
Gura_DeclareFunction(sdl_ShowWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ShowWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_ShowWindow(window);
	return Value::Null;
}

// sdl2.sdl_UpdateWindowSurface
Gura_DeclareFunction(sdl_UpdateWindowSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UpdateWindowSurface)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_UpdateWindowSurface(window);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_UpdateWindowSurfaceRects
Gura_DeclareFunction(sdl_UpdateWindowSurfaceRects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UpdateWindowSurfaceRects)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	CArray<SDL_Rect> rects = CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1));
	int numrects = static_cast<int>(rects.GetSize());
	int _rtn = SDL_UpdateWindowSurfaceRects(window, rects, numrects);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_VideoInit
Gura_DeclareFunction(sdl_VideoInit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "driver_name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_VideoInit)
{
	const char *driver_name = args.GetString(0);
	int _rtn = SDL_VideoInit(driver_name);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_VideoQuit
Gura_DeclareFunction(sdl_VideoQuit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_VideoQuit)
{
	SDL_VideoQuit();
	return Value::Null;
}

// sdl2.sdl_CreateRenderer
Gura_DeclareFunction(sdl_CreateRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateRenderer)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int index = args.GetInt(1);
	Uint32 flags = args.GetULong(2);
	SDL_Renderer *_rtn = SDL_CreateRenderer(window, index, flags);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Renderer(_rtn)));
}

// sdl2.sdl_CreateSoftwareRenderer
Gura_DeclareFunction(sdl_CreateSoftwareRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateSoftwareRenderer)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Renderer *_rtn = SDL_CreateSoftwareRenderer(surface);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Renderer(_rtn)));
}

// sdl2.sdl_CreateTexture
Gura_DeclareFunction(sdl_CreateTexture)
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

Gura_ImplementFunction(sdl_CreateTexture)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	Uint32 format = args.GetULong(1);
	int access = args.GetInt(2);
	int w = args.GetInt(3);
	int h = args.GetInt(4);
	SDL_Texture *_rtn = SDL_CreateTexture(renderer, format, access, w, h);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Texture(_rtn)));
}

// sdl2.sdl_CreateTextureFromSurface
Gura_DeclareFunction(sdl_CreateTextureFromSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateTextureFromSurface)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Surface *surface = Object_Surface::GetObject(args, 1)->GetEntity();
	SDL_Texture *_rtn = SDL_CreateTextureFromSurface(renderer, surface);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Texture(_rtn)));
}

// sdl2.sdl_DestroyRenderer
Gura_DeclareFunction(sdl_DestroyRenderer)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DestroyRenderer)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_DestroyRenderer(renderer);
	return Value::Null;
}

// sdl2.sdl_DestroyTexture
Gura_DeclareFunction(sdl_DestroyTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DestroyTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_DestroyTexture(texture);
	return Value::Null;
}

// sdl2.sdl_GL_BindTexture
Gura_DeclareFunction(sdl_GL_BindTexture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_BindTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	float texw = 0;
	float texh = 0;
	SDL_GL_BindTexture(texture, &texw, &texh);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(texw), Value(texh)));
}

// sdl2.sdl_GL_UnbindTexture
Gura_DeclareFunction(sdl_GL_UnbindTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GL_UnbindTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_GL_UnbindTexture(texture);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_GetNumRenderDrivers
Gura_DeclareFunction(sdl_GetNumRenderDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumRenderDrivers)
{
	int _rtn = SDL_GetNumRenderDrivers();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetRenderDrawBlendMode
Gura_DeclareFunction(sdl_GetRenderDrawBlendMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRenderDrawBlendMode)
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

// sdl2.sdl_GetRenderDrawColor
Gura_DeclareFunction(sdl_GetRenderDrawColor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRenderDrawColor)
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

// sdl2.sdl_GetRenderDriverInfo
Gura_DeclareFunction(sdl_GetRenderDriverInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRenderDriverInfo)
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

// sdl2.sdl_GetRenderTarget
Gura_DeclareFunction(sdl_GetRenderTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRenderTarget)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Texture *_rtn = SDL_GetRenderTarget(renderer);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Texture(_rtn));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.sdl_GetRenderer
Gura_DeclareFunction(sdl_GetRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRenderer)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_Renderer *_rtn = SDL_GetRenderer(window);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Renderer(_rtn)));
}

// sdl2.sdl_GetRendererInfo
Gura_DeclareFunction(sdl_GetRendererInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRendererInfo)
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

// sdl2.sdl_GetRenderOutputSize
Gura_DeclareFunction(sdl_GetRenderOutputSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRenderOutputSize)
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

// sdl2.sdl_GetTextureAlphaMod
Gura_DeclareFunction(sdl_GetTextureAlphaMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetTextureAlphaMod)
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

// sdl2.sdl_GetTextureBlendMode
Gura_DeclareFunction(sdl_GetTextureBlendMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetTextureBlendMode)
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

// sdl2.sdl_GetTextureColorMod
Gura_DeclareFunction(sdl_GetTextureColorMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetTextureColorMod)
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

// sdl2.sdl_LockTexture
Gura_DeclareFunction(sdl_LockTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LockTexture)
{
#if 0
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = Object_Rect::GetObject(args, 1)->GetEntity();
	int _rtn = SDL_LockTexture(texture, rect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LockTexture");
	return Value::Null;
}

// sdl2.sdl_QueryTexture
Gura_DeclareFunction(sdl_QueryTexture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_QueryTexture)
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

// sdl2.sdl_RenderClear
Gura_DeclareFunction(sdl_RenderClear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderClear)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_RenderClear(renderer);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_RenderCopy
Gura_DeclareFunction(sdl_RenderCopy)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderCopy)
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

// sdl2.sdl_RenderCopyEx
Gura_DeclareFunction(sdl_RenderCopyEx)
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

Gura_ImplementFunction(sdl_RenderCopyEx)
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

// sdl2.sdl_RenderDrawLine
Gura_DeclareFunction(sdl_RenderDrawLine)
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

Gura_ImplementFunction(sdl_RenderDrawLine)
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

// sdl2.sdl_RenderDrawLines
Gura_DeclareFunction(sdl_RenderDrawLines)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderDrawLines)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Point> points = CreateCArray<SDL_Point, Object_Point>(args.GetList(1));
	int count = static_cast<int>(points.GetSize());
	int _rtn = SDL_RenderDrawLines(renderer, points, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_RenderDrawPoint
Gura_DeclareFunction(sdl_RenderDrawPoint)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderDrawPoint)
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

// sdl2.sdl_RenderDrawPoints
Gura_DeclareFunction(sdl_RenderDrawPoints)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderDrawPoints)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Point> points = CreateCArray<SDL_Point, Object_Point>(args.GetList(1));
	int count = static_cast<int>(points.GetSize());
	int _rtn = SDL_RenderDrawPoints(renderer, points, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_RenderDrawRect
Gura_DeclareFunction(sdl_RenderDrawRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderDrawRect)
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

// sdl2.sdl_RenderDrawRects
Gura_DeclareFunction(sdl_RenderDrawRects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderDrawRects)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Rect> rects = CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1));
	int count = static_cast<int>(rects.GetSize());
	int _rtn = SDL_RenderDrawRects(renderer, rects, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_RenderFillRect
Gura_DeclareFunction(sdl_RenderFillRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderFillRect)
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

// sdl2.sdl_RenderFillRects
Gura_DeclareFunction(sdl_RenderFillRects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderFillRects)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	CArray<SDL_Rect> rects = CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1));
	int count = static_cast<int>(rects.GetSize());
	int _rtn = SDL_RenderFillRects(renderer, rects, count);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_RenderGetClipRect
Gura_DeclareFunction(sdl_RenderGetClipRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderGetClipRect)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_RenderGetClipRect(renderer, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.sdl_RenderGetLogicalSize
Gura_DeclareFunction(sdl_RenderGetLogicalSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderGetLogicalSize)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_RenderGetLogicalSize(renderer, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.sdl_RenderGetScale
Gura_DeclareFunction(sdl_RenderGetScale)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderGetScale)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	float scaleX = 0;
	float scaleY = 0;
	SDL_RenderGetScale(renderer, &scaleX, &scaleY);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(scaleX), Value(scaleY)));
}

// sdl2.sdl_RenderGetViewport
Gura_DeclareFunction(sdl_RenderGetViewport)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderGetViewport)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_RenderGetViewport(renderer, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.sdl_RenderIsClipEnabled
Gura_DeclareFunction(sdl_RenderIsClipEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderIsClipEnabled)
{
#if 0
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RenderIsClipEnabled(renderer);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "sdl_RenderIsClipEnabled");
	return Value::Null;
}

// sdl2.sdl_RenderPresent
Gura_DeclareFunction(sdl_RenderPresent)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderPresent)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_RenderPresent(renderer);
	return Value::Null;
}

// sdl2.sdl_RenderReadPixels
Gura_DeclareFunction(sdl_RenderReadPixels)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderReadPixels)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	const Symbol *format = args.GetSymbol(2);
	Uint32 _format = SDL_PIXELFORMAT_UNKNOWN;
	Image::Format fmtImage = Image::FORMAT_None;
	if (format->IsIdentical(Gura_Symbol(rgb))) {
		_format = SDL_PIXELFORMAT_BGR888;
		fmtImage = Image::FORMAT_RGB;
	} else if (format->IsIdentical(Gura_Symbol(rgba))) {
		_format = SDL_PIXELFORMAT_BGRA8888;
		fmtImage = Image::FORMAT_RGBA;
	} else {
		sig.SetError(ERR_ValueError, "format must be `rgb or `rgba");
		return Value::Null;
	}
	AutoPtr<Image> pImage(new Image(fmtImage));
	if (!pImage->AllocBuffer(sig, rect->w, rect->h, 0x00)) return Value::Null;
	void *pixels = pImage->GetBuffer();
	int pitch = pImage->GetBytesPerLine();
	int _rtn = SDL_RenderReadPixels(renderer, rect, _format, pixels, pitch);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_image(env, pImage.release())));
}

// sdl2.sdl_RenderSetClipRect
Gura_DeclareFunction(sdl_RenderSetClipRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderSetClipRect)
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

// sdl2.sdl_RenderSetLogicalSize
Gura_DeclareFunction(sdl_RenderSetLogicalSize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderSetLogicalSize)
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

// sdl2.sdl_RenderSetScale
Gura_DeclareFunction(sdl_RenderSetScale)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "scaleX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "scaleY", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderSetScale)
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

// sdl2.sdl_RenderSetViewport
Gura_DeclareFunction(sdl_RenderSetViewport)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderSetViewport)
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

// sdl2.sdl_RenderTargetSupported
Gura_DeclareFunction(sdl_RenderTargetSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RenderTargetSupported)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RenderTargetSupported(renderer);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_SetRenderDrawBlendMode
Gura_DeclareFunction(sdl_SetRenderDrawBlendMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetRenderDrawBlendMode)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = static_cast<SDL_BlendMode>(args.GetInt(1));
	SDL_SetRenderDrawBlendMode(renderer, blendMode);
	return Value::Null;
}

// sdl2.sdl_SetRenderDrawColor
Gura_DeclareFunction(sdl_SetRenderDrawColor)
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

Gura_ImplementFunction(sdl_SetRenderDrawColor)
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

// sdl2.sdl_SetRenderTarget
Gura_DeclareFunction(sdl_SetRenderTarget)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetRenderTarget)
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

// sdl2.sdl_SetTextureAlphaMod
Gura_DeclareFunction(sdl_SetTextureAlphaMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetTextureAlphaMod)
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

// sdl2.sdl_SetTextureBlendMode
Gura_DeclareFunction(sdl_SetTextureBlendMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetTextureBlendMode)
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

// sdl2.sdl_SetTextureColorMod
Gura_DeclareFunction(sdl_SetTextureColorMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetTextureColorMod)
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

// sdl2.sdl_UnlockTexture
Gura_DeclareFunction(sdl_UnlockTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UnlockTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_UnlockTexture(texture);
	return Value::Null;
}

// sdl2.sdl_UpdateTexture
Gura_DeclareFunction(sdl_UpdateTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "pitch", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UpdateTexture)
{
#if 0
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int pitch = args.GetInt(2);
	int _rtn = SDL_UpdateTexture(texture, rect, pitch);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_UpdateTexture");
	return Value::Null;
}

// sdl2.sdl_UpdateYUVTexture
Gura_DeclareFunction(sdl_UpdateYUVTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UpdateYUVTexture)
{
#if 0
	SDL_UpdateYUVTexture();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_UpdateYUVTexture");
	return Value::Null;
}

// sdl2.sdl_AllocFormat
Gura_DeclareFunction(sdl_AllocFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel_format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AllocFormat)
{
	Uint32 pixel_format = args.GetULong(0);
	SDL_PixelFormat *_rtn = SDL_AllocFormat(pixel_format);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_PixelFormat(_rtn)));
}

// sdl2.sdl_AllocPalette
Gura_DeclareFunction(sdl_AllocPalette)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "ncolors", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AllocPalette)
{
	int ncolors = args.GetInt(0);
	SDL_Palette *_rtn = SDL_AllocPalette(ncolors);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Palette(_rtn)));
}

// sdl2.sdl_CalculateGammaRamp
Gura_DeclareFunction(sdl_CalculateGammaRamp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamma", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CalculateGammaRamp)
{
	float gamma = args.GetFloat(0);
	Uint16 ramp[256];
	SDL_CalculateGammaRamp(gamma, ramp);
	return ReturnValue(env, sig, args, Value::CreateList(env, ramp, ArraySizeOf(ramp)));
}

// sdl2.sdl_FreeFormat
Gura_DeclareFunction(sdl_FreeFormat)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FreeFormat)
{
	SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	SDL_FreeFormat(format);
	return Value::Null;
}

// sdl2.sdl_FreePalette
Gura_DeclareFunction(sdl_FreePalette)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FreePalette)
{
	SDL_Palette *palette = Object_Palette::GetObject(args, 0)->GetEntity();
	SDL_FreePalette(palette);
	return Value::Null;
}

// sdl2.sdl_GetPixelFormatName
Gura_DeclareFunction(sdl_GetPixelFormatName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetPixelFormatName)
{
	Uint32 format = args.GetULong(0);
	const char *_rtn = SDL_GetPixelFormatName(format);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetRGB
Gura_DeclareFunction(sdl_GetRGB)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRGB)
{
	Uint32 pixel = args.GetULong(0);
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 1)->GetEntity();
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	SDL_GetRGB(pixel, format, &r, &g, &b);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(r), Value(g), Value(b)));
}

// sdl2.sdl_GetRGBA
Gura_DeclareFunction(sdl_GetRGBA)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRGBA)
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

// sdl2.sdl_MapRGB
Gura_DeclareFunction(sdl_MapRGB)
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

Gura_ImplementFunction(sdl_MapRGB)
{
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint32 _rtn = SDL_MapRGB(format, r, g, b);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_MapRGBA
Gura_DeclareFunction(sdl_MapRGBA)
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

Gura_ImplementFunction(sdl_MapRGBA)
{
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint8 a = args.GetUChar(4);
	Uint32 _rtn = SDL_MapRGBA(format, r, g, b, a);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_MasksToPixelFormatEnum
Gura_DeclareFunction(sdl_MasksToPixelFormatEnum)
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

Gura_ImplementFunction(sdl_MasksToPixelFormatEnum)
{
	int bpp = args.GetInt(0);
	Uint32 Rmask = args.GetULong(1);
	Uint32 Gmask = args.GetULong(2);
	Uint32 Bmask = args.GetULong(3);
	Uint32 Amask = args.GetULong(4);
	Uint32 _rtn = SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_PixelFormatEnumToMasks
Gura_DeclareFunction(sdl_PixelFormatEnumToMasks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PixelFormatEnumToMasks)
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

// sdl2.sdl_SetPaletteColors
Gura_DeclareFunction(sdl_SetPaletteColors)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	DeclareArg(env, "colors", VTYPE_Color, OCCUR_Once, FLAG_List);
	DeclareArg(env, "firstcolor", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ncolors", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetPaletteColors)
{
	SDL_Palette *palette = Object_Palette::GetObject(args, 0)->GetEntity();
	CArray<SDL_Color> colors = CreateCArray<SDL_Color, Object_Color>(args.GetList(1));
	int firstcolor = args.GetInt(2);
	int ncolors = args.GetInt(3);
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

// sdl2.sdl_SetPixelFormatPalette
Gura_DeclareFunction(sdl_SetPixelFormatPalette)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetPixelFormatPalette)
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

// sdl2.sdl_EnclosePoints
Gura_DeclareFunction(sdl_EnclosePoints)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "clip", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_EnclosePoints)
{
	CArray<SDL_Point> points = CreateCArray<SDL_Point, Object_Point>(args.GetList(0));
	const SDL_Rect *clip = Object_Rect::GetObject(args, 1)->GetEntity();
	int count = static_cast<int>(points.GetSize());
	SDL_Rect result;
	SDL_bool _rtn = SDL_EnclosePoints(points, count, clip, &result);
	Value _rtnVal;
	if (_rtn == SDL_TRUE) {
		_rtnVal = Value(new Object_Rect(result));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.sdl_HasIntersection
Gura_DeclareFunction(sdl_HasIntersection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasIntersection)
{
	const SDL_Rect *A = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *B = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_HasIntersection(A, B);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_IntersectRect
Gura_DeclareFunction(sdl_IntersectRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_IntersectRect)
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

// sdl2.sdl_IntersectRectAndLine
Gura_DeclareFunction(sdl_IntersectRectAndLine)
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

Gura_ImplementFunction(sdl_IntersectRectAndLine)
{
#if 0
	const SDL_Rect *rect = Object_Rect::GetObject(args, 0)->GetEntity();
	int X1 = args.GetInt(1);
	int Y1 = args.GetInt(2);
	int X2 = args.GetInt(3);
	int Y2 = args.GetInt(4);
	SDL_bool _rtn = SDL_IntersectRectAndLine(rect, X1, Y1, X2, Y2);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "sdl_IntersectRectAndLine");
	return Value::Null;
}

// sdl2.sdl_PointInRect
Gura_DeclareFunction(sdl_PointInRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "p", VTYPE_Point, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PointInRect)
{
#if 0
	const SDL_Point *p = Object_Point::GetObject(args, 0)->GetEntity();
	const SDL_Rect *r = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_PointInRect(p, r);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "sdl_PointInRect");
	return Value::Null;
}

// sdl2.sdl_RectEmpty
Gura_DeclareFunction(sdl_RectEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "r", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RectEmpty)
{
	const SDL_Rect *r = Object_Rect::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RectEmpty(r);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_RectEquals
Gura_DeclareFunction(sdl_RectEquals)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "a", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RectEquals)
{
	const SDL_Rect *a = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *b = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_RectEquals(a, b);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_UnionRect
Gura_DeclareFunction(sdl_UnionRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UnionRect)
{
	const SDL_Rect *A = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *B = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_Rect result;
	SDL_UnionRect(A, B, &result);
	Value _rtnVal = Value(new Object_Rect(result));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.sdl_BlitScaled
Gura_DeclareFunction(sdl_BlitScaled)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_BlitScaled)
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

// sdl2.sdl_BlitSurface
Gura_DeclareFunction(sdl_BlitSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_BlitSurface)
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

// sdl2.sdl_ConvertPixels
Gura_DeclareFunction(sdl_ConvertPixels)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ConvertPixels)
{
#if 0
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	Uint32 src_format = args.GetULong(2);
	Uint32 dst_format = args.GetULong(3);
	int _rtn = SDL_ConvertPixels(width, height, src_format, dst_format);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ConvertPixels");
	return Value::Null;
}

// sdl2.sdl_ConvertSurface
Gura_DeclareFunction(sdl_ConvertSurface)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "fmt", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ConvertSurface)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_PixelFormat *fmt = Object_PixelFormat::GetObject(args, 1)->GetEntity();
	Uint32 flags = args.GetULong(2);
	SDL_Surface *_rtn = SDL_ConvertSurface(src, fmt, flags);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.sdl_ConvertSurfaceFormat
Gura_DeclareFunction(sdl_ConvertSurfaceFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pixel_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ConvertSurfaceFormat)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint32 pixel_format = args.GetULong(1);
	Uint32 flags = args.GetULong(2);
	SDL_Surface *_rtn = SDL_ConvertSurfaceFormat(src, pixel_format, flags);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.sdl_CreateRGBSurface
Gura_DeclareFunction(sdl_CreateRGBSurface)
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

Gura_ImplementFunction(sdl_CreateRGBSurface)
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
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.sdl_CreateRGBSurfaceFrom
Gura_DeclareFunction(sdl_CreateRGBSurfaceFrom)
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

Gura_ImplementFunction(sdl_CreateRGBSurfaceFrom)
{
	const Binary &pixels = Object_binary::GetObject(args, 0)->GetBinary();
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	int depth = args.GetInt(3);
	int pitch = args.GetInt(4);
	Uint32 Rmask = args.GetULong(5);
	Uint32 Gmask = args.GetULong(6);
	Uint32 Bmask = args.GetULong(7);
	Uint32 Amask = args.GetULong(8);
	if (pixels.size() < static_cast<size_t>(height * pitch)) {
		sig.SetError(ERR_ValueError, "pixels doesn not contain enough data");
		return Value::Null;
	}
	void *_pixels = const_cast<char *>(pixels.data());
	SDL_Surface *_rtn = SDL_CreateRGBSurfaceFrom(_pixels, width, height,
								depth, pitch, Rmask, Gmask, Bmask, Amask);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.sdl_CreateRGBSurfaceFromImage
Gura_DeclareFunction(sdl_CreateRGBSurfaceFromImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "image", VTYPE_image, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateRGBSurfaceFromImage)
{
	Image *image = Object_image::GetObject(args, 0)->GetImage();
	Object_Surface *pObjSurface = Object_Surface::CreateSurfaceFromImage(sig, image);
	if (pObjSurface == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

// sdl2.sdl_FillRect
Gura_DeclareFunction(sdl_FillRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "color", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FillRect)
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

// sdl2.sdl_FillRects
Gura_DeclareFunction(sdl_FillRects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	DeclareArg(env, "color", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FillRects)
{
	SDL_Surface *dst = Object_Surface::GetObject(args, 0)->GetEntity();
	CArray<SDL_Rect> rects = CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1));
	Uint32 color = args.GetULong(2);
	int count = static_cast<int>(rects.GetSize());
	int _rtn = SDL_FillRects(dst, rects, count, color);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_FreeSurface
Gura_DeclareFunction(sdl_FreeSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FreeSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_FreeSurface(surface);
	return Value::Null;
}

// sdl2.sdl_GetClipRect
Gura_DeclareFunction(sdl_GetClipRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetClipRect)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_GetClipRect(surface, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.sdl_GetColorKey
Gura_DeclareFunction(sdl_GetColorKey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetColorKey)
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

// sdl2.sdl_GetSurfaceAlphaMod
Gura_DeclareFunction(sdl_GetSurfaceAlphaMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetSurfaceAlphaMod)
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

// sdl2.sdl_GetSurfaceBlendMode
Gura_DeclareFunction(sdl_GetSurfaceBlendMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetSurfaceBlendMode)
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

// sdl2.sdl_GetSurfaceColorMod
Gura_DeclareFunction(sdl_GetSurfaceColorMod)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetSurfaceColorMod)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	int _rtn = SDL_GetSurfaceColorMod(surface, &r, &g, &b);
	return ReturnValue(env, sig, args,
			Value::CreateList(env, Value(r), Value(g), Value(b)));
}

// sdl2.sdl_LoadBMP
Gura_DeclareFunction(sdl_LoadBMP)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LoadBMP)
{
	Stream &src = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> _src(CreateRWopsStream(&src, &sig));
	SDL_Surface *_rtn = SDL_LoadBMP_RW(_src.get(), 0);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(_rtn)));
}

// sdl2.sdl_LoadBMP_RW
Gura_DeclareFunction(sdl_LoadBMP_RW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LoadBMP_RW)
{
#if 0
	SDL_LoadBMP_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LoadBMP_RW");
	return Value::Null;
}

// sdl2.sdl_LockSurface
Gura_DeclareFunction(sdl_LockSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LockSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_LockSurface(surface);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_LowerBlit
Gura_DeclareFunction(sdl_LowerBlit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LowerBlit)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = Object_Surface::GetObject(args, 2)->GetEntity();
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int _rtn = SDL_LowerBlit(src, srcrect, dst, dstrect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_LowerBlitScaled
Gura_DeclareFunction(sdl_LowerBlitScaled)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LowerBlitScaled)
{
	SDL_Surface *src = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = Object_Surface::GetObject(args, 2)->GetEntity();
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int _rtn = SDL_LowerBlitScaled(src, srcrect, dst, dstrect);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_MUSTLOCK
Gura_DeclareFunction(sdl_MUSTLOCK)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_MUSTLOCK)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	bool _rtn = SDL_MUSTLOCK(surface);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_SaveBMP
Gura_DeclareFunction(sdl_SaveBMP)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SaveBMP)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	Stream &dst = Object_stream::GetObject(args, 1)->GetStream();
	std::auto_ptr<SDL_RWops> context(CreateRWopsStream(&dst, &sig));
	int _rtn = SDL_SaveBMP_RW(surface, context.get(), 0);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_SaveBMP_RW
Gura_DeclareFunction(sdl_SaveBMP_RW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SaveBMP_RW)
{
#if 0
	SDL_SaveBMP_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SaveBMP_RW");
	return Value::Null;
}

// sdl2.sdl_SetClipRect
Gura_DeclareFunction(sdl_SetClipRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetClipRect)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_SetClipRect(surface, rect);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_SetColorKey
Gura_DeclareFunction(sdl_SetColorKey)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetColorKey)
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

// sdl2.sdl_SetSurfaceAlphaMod
Gura_DeclareFunction(sdl_SetSurfaceAlphaMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetSurfaceAlphaMod)
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

// sdl2.sdl_SetSurfaceBlendMode
Gura_DeclareFunction(sdl_SetSurfaceBlendMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetSurfaceBlendMode)
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

// sdl2.sdl_SetSurfaceColorMod
Gura_DeclareFunction(sdl_SetSurfaceColorMod)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetSurfaceColorMod)
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

// sdl2.sdl_SetSurfacePalette
Gura_DeclareFunction(sdl_SetSurfacePalette)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetSurfacePalette)
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

// sdl2.sdl_SetSurfaceRLE
Gura_DeclareFunction(sdl_SetSurfaceRLE)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetSurfaceRLE)
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

// sdl2.sdl_UnlockSurface
Gura_DeclareFunction(sdl_UnlockSurface)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UnlockSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_UnlockSurface(surface);
	return Value::Null;
}

// sdl2.sdl_GetClipboardText
Gura_DeclareFunction(sdl_GetClipboardText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetClipboardText)
{
	char *_rtn = SDL_GetClipboardText();
	Value _rtnVal(_rtn);
	SDL_free(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.sdl_HasClipboardText
Gura_DeclareFunction(sdl_HasClipboardText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasClipboardText)
{
	SDL_bool _rtn = SDL_HasClipboardText();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_SetClipboardText
Gura_DeclareFunction(sdl_SetClipboardText)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetClipboardText)
{
	const char *text = args.GetString(0);
	int _rtn = SDL_SetClipboardText(text);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_AddEventWatch
Gura_DeclareFunction(sdl_AddEventWatch)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AddEventWatch)
{
#if 0
	SDL_AddEventWatch();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AddEventWatch");
	return Value::Null;
}

// sdl2.sdl_DelEventWatch
Gura_DeclareFunction(sdl_DelEventWatch)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DelEventWatch)
{
#if 0
	SDL_DelEventWatch();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_DelEventWatch");
	return Value::Null;
}

// sdl2.sdl_EventState
Gura_DeclareFunction(sdl_EventState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_EventState)
{
	Uint32 type = args.GetULong(0);
	int state = args.GetInt(1);
	Uint8 _rtn = SDL_EventState(type, state);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_FilterEvents
Gura_DeclareFunction(sdl_FilterEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FilterEvents)
{
#if 0
	SDL_FilterEvents();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_FilterEvents");
	return Value::Null;
}

// sdl2.sdl_FlushEvent
Gura_DeclareFunction(sdl_FlushEvent)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FlushEvent)
{
	Uint32 type = args.GetULong(0);
	SDL_FlushEvent(type);
	return Value::Null;
}

// sdl2.sdl_FlushEvents
Gura_DeclareFunction(sdl_FlushEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FlushEvents)
{
	Uint32 minType = args.GetULong(0);
	Uint32 maxType = args.GetULong(1);
	SDL_FlushEvents(minType, maxType);
	return Value::Null;
}

// sdl2.sdl_GetEventFilter
Gura_DeclareFunction(sdl_GetEventFilter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetEventFilter)
{
#if 0
	SDL_GetEventFilter();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetEventFilter");
	return Value::Null;
}

// sdl2.sdl_GetNumTouchDevices
Gura_DeclareFunction(sdl_GetNumTouchDevices)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumTouchDevices)
{
	int _rtn = SDL_GetNumTouchDevices();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetNumTouchFingers
Gura_DeclareFunction(sdl_GetNumTouchFingers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumTouchFingers)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	int _rtn = SDL_GetNumTouchFingers(touchId);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetTouchDevice
Gura_DeclareFunction(sdl_GetTouchDevice)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetTouchDevice)
{
	int index = args.GetInt(0);
	SDL_TouchID _rtn = SDL_GetTouchDevice(index);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetTouchFinger
Gura_DeclareFunction(sdl_GetTouchFinger)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetTouchFinger)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	int index = args.GetInt(1);
	SDL_Finger *_rtn = SDL_GetTouchFinger(touchId, index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Finger(_rtn)));
}

// sdl2.sdl_HasEvent
Gura_DeclareFunction(sdl_HasEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasEvent)
{
	Uint32 type = args.GetULong(0);
	SDL_bool _rtn = SDL_HasEvent(type);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasEvents
Gura_DeclareFunction(sdl_HasEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasEvents)
{
	Uint32 minType = args.GetULong(0);
	Uint32 maxType = args.GetULong(1);
	SDL_bool _rtn = SDL_HasEvents(minType, maxType);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_LoadDollarTemplates
Gura_DeclareFunction(sdl_LoadDollarTemplates)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LoadDollarTemplates)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	Stream &src = Object_stream::GetObject(args, 1)->GetStream();
	std::auto_ptr<SDL_RWops> _src(CreateRWopsStream(&src, &sig));
	int _rtn = SDL_LoadDollarTemplates(touchId, _src.get());
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_AddEvents
Gura_DeclareFunction(sdl_AddEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "events", VTYPE_Event, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AddEvents)
{
	CArray<SDL_Event> events = CreateCArray<SDL_Event, Object_Event>(args.GetList(0));
	int numevents = static_cast<int>(events.GetSize());
	int _rtn = SDL_PeepEvents(events, numevents, SDL_ADDEVENT, 0, 0);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_PeekEvents
Gura_DeclareFunction(sdl_PeekEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PeekEvents)
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

// sdl2.sdl_GetEvents
Gura_DeclareFunction(sdl_GetEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetEvents)
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

// sdl2.sdl_PollEvent
Gura_DeclareFunction(sdl_PollEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PollEvent)
{
	SDL_Event event;
	int _rtn = SDL_PollEvent(&event);
	if (_rtn == 0) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_Event(event)));
}

// sdl2.sdl_PumpEvents
Gura_DeclareFunction(sdl_PumpEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PumpEvents)
{
	SDL_PumpEvents();
	return Value::Null;
}

// sdl2.sdl_PushEvent
Gura_DeclareFunction(sdl_PushEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "event", VTYPE_Event, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PushEvent)
{
	SDL_Event *event = Object_Event::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_PushEvent(event);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_QuitRequested
Gura_DeclareFunction(sdl_QuitRequested)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_QuitRequested)
{
	bool _rtn = SDL_QuitRequested();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_RecordGesture
Gura_DeclareFunction(sdl_RecordGesture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RecordGesture)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	int _rtn = SDL_RecordGesture(touchId);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_RegisterEvents
Gura_DeclareFunction(sdl_RegisterEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RegisterEvents)
{
	int numevents = args.GetInt(0);
	Uint32 _rtn = SDL_RegisterEvents(numevents);
	Value _rtnVal;
	if (_rtn != (Uint32)-1) {
		_rtnVal = Value(_rtn);
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.sdl_SaveAllDollarTemplates
Gura_DeclareFunction(sdl_SaveAllDollarTemplates)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SaveAllDollarTemplates)
{
	Stream &dst = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> _dst(CreateRWopsStream(&dst, &sig));
	int _rtn = SDL_SaveAllDollarTemplates(_dst.get());
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_SaveDollarTemplate
Gura_DeclareFunction(sdl_SaveDollarTemplate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gestureId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SaveDollarTemplate)
{
	SDL_GestureID gestureId = static_cast<SDL_GestureID>(args.GetInt(0));
	Stream &dst = Object_stream::GetObject(args, 1)->GetStream();
	std::auto_ptr<SDL_RWops> _dst(CreateRWopsStream(&dst, &sig));
	int _rtn = SDL_SaveDollarTemplate(gestureId, _dst.get());
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_SetEventFilter
Gura_DeclareFunction(sdl_SetEventFilter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetEventFilter)
{
#if 0
	SDL_SetEventFilter();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SetEventFilter");
	return Value::Null;
}

// sdl2.sdl_WaitEvent
Gura_DeclareFunction(sdl_WaitEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WaitEvent)
{
	SDL_Event event;
	int _rtn = SDL_WaitEvent(&event);
	if (_rtn == 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Event(event)));
}

// sdl2.sdl_WaitEventTimeout
Gura_DeclareFunction(sdl_WaitEventTimeout)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WaitEventTimeout)
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

// sdl2.sdl_CheckKeyboardState
Gura_DeclareFunction(sdl_CheckKeyboardState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CheckKeyboardState)
{
	SDL_Scancode scancode = static_cast<SDL_Scancode>(args.GetInt(0));
	int numkeys = 0;
	const Uint8 *_keystate = SDL_GetKeyboardState(&numkeys);
	bool _rtn = (0 <= scancode && scancode < numkeys && _keystate[scancode] != 0);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetKeyFromName
Gura_DeclareFunction(sdl_GetKeyFromName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetKeyFromName)
{
	const char *name = args.GetString(0);
	SDL_Keycode _rtn = SDL_GetKeyFromName(name);
	if (_rtn == SDLK_UNKNOWN) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetKeyFromScancode
Gura_DeclareFunction(sdl_GetKeyFromScancode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetKeyFromScancode)
{
	SDL_Scancode scancode = static_cast<SDL_Scancode>(args.GetInt(0));
	SDL_Keycode _rtn = SDL_GetKeyFromScancode(scancode);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetKeyName
Gura_DeclareFunction(sdl_GetKeyName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetKeyName)
{
	SDL_Keycode key = static_cast<SDL_Keycode>(args.GetInt(0));
	const char *_rtn = SDL_GetKeyName(key);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetKeyboardFocus
Gura_DeclareFunction(sdl_GetKeyboardFocus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetKeyboardFocus)
{
	SDL_Window *_rtn = SDL_GetKeyboardFocus();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(_rtn)));
}

// sdl2.sdl_GetKeyboardState
Gura_DeclareFunction(sdl_GetKeyboardState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetKeyboardState)
{
	int numkeys = 0;
	const Uint8 *_keystate = SDL_GetKeyboardState(&numkeys);
	Value _rtnVal;
	ValueList &_valList = _rtnVal.InitAsList(env, numkeys);
	for (int i = 0; i < numkeys; i++) {
		_valList.push_back(Value(_keystate[i] != 0));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.sdl_GetModState
Gura_DeclareFunction(sdl_GetModState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetModState)
{
	SDL_Keymod _rtn = SDL_GetModState();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetScancodeFromKey
Gura_DeclareFunction(sdl_GetScancodeFromKey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetScancodeFromKey)
{
	SDL_Keycode key = static_cast<SDL_Keycode>(args.GetInt(0));
	SDL_Scancode _rtn = SDL_GetScancodeFromKey(key);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetScancodeFromName
Gura_DeclareFunction(sdl_GetScancodeFromName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetScancodeFromName)
{
	const char *name = args.GetString(0);
	SDL_Scancode _rtn = SDL_GetScancodeFromName(name);
	if (_rtn == SDL_SCANCODE_UNKNOWN) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetScancodeName
Gura_DeclareFunction(sdl_GetScancodeName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetScancodeName)
{
	SDL_Scancode scancode = static_cast<SDL_Scancode>(args.GetInt(0));
	const char *_rtn = SDL_GetScancodeName(scancode);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_HasScreenKeyboardSupport
Gura_DeclareFunction(sdl_HasScreenKeyboardSupport)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasScreenKeyboardSupport)
{
	SDL_bool _rtn = SDL_HasScreenKeyboardSupport();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_IsScreenKeyboardShown
Gura_DeclareFunction(sdl_IsScreenKeyboardShown)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_IsScreenKeyboardShown)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_IsScreenKeyboardShown(window);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_IsTextInputActive
Gura_DeclareFunction(sdl_IsTextInputActive)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_IsTextInputActive)
{
	SDL_bool _rtn = SDL_IsTextInputActive();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_SetModState
Gura_DeclareFunction(sdl_SetModState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "modstate", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetModState)
{
	SDL_Keymod modstate = static_cast<SDL_Keymod>(args.GetInt(0));
	SDL_SetModState(modstate);
	return Value::Null;
}

// sdl2.sdl_SetTextInputRect
Gura_DeclareFunction(sdl_SetTextInputRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetTextInputRect)
{
	SDL_Rect *rect = Object_Rect::GetObject(args, 0)->GetEntity();
	SDL_SetTextInputRect(rect);
	return Value::Null;
}

// sdl2.sdl_StartTextInput
Gura_DeclareFunction(sdl_StartTextInput)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_StartTextInput)
{
	SDL_StartTextInput();
	return Value::Null;
}

// sdl2.sdl_StopTextInput
Gura_DeclareFunction(sdl_StopTextInput)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_StopTextInput)
{
	SDL_StopTextInput();
	return Value::Null;
}

// sdl2.sdl_CaptureMouse
Gura_DeclareFunction(sdl_CaptureMouse)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "enalbed", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CaptureMouse)
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
	SetError_NotImpFunction(sig, "sdl_CaptureMouse");
	return Value::Null;
}

// sdl2.sdl_CreateColorCursor
Gura_DeclareFunction(sdl_CreateColorCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateColorCursor)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	int hot_x = args.GetInt(1);
	int hot_y = args.GetInt(2);
	SDL_Cursor *_rtn = SDL_CreateColorCursor(surface, hot_x, hot_y);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(_rtn, true)));
}

// sdl2.sdl_CreateCursor
Gura_DeclareFunction(sdl_CreateCursor)
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

Gura_ImplementFunction(sdl_CreateCursor)
{
	const Binary &data = Object_binary::GetObject(args, 0)->GetBinary();
	const Binary &mask = Object_binary::GetObject(args, 1)->GetBinary();
	int w = args.GetInt(2);
	int h = args.GetInt(3);
	int hot_x = args.GetInt(4);
	int hot_y = args.GetInt(5);
	size_t bytesLeast = int((w + 7) / 8) * h;
	if (data.size() < bytesLeast) {
		sig.SetError(ERR_ValueError, "data has insufficient content");
		return Value::Null;
	}
	if (mask.size() < bytesLeast) {
		sig.SetError(ERR_ValueError, "mask has insufficient content");
		return Value::Null;
	}
	const Uint8 *_data = reinterpret_cast<const Uint8 *>(data.data());
	const Uint8 *_mask = reinterpret_cast<const Uint8 *>(mask.data());
	SDL_Cursor *_rtn = SDL_CreateCursor(_data, _mask, w, h, hot_x, hot_y);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(_rtn, true)));
}

// sdl2.sdl_CreateSystemCursor
Gura_DeclareFunction(sdl_CreateSystemCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateSystemCursor)
{
	SDL_SystemCursor id = static_cast<SDL_SystemCursor>(args.GetInt(0));
	SDL_Cursor *_rtn = SDL_CreateSystemCursor(id);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(_rtn, true)));
}

// sdl2.sdl_FreeCursor
Gura_DeclareFunction(sdl_FreeCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FreeCursor)
{
	SDL_Cursor *cursor = Object_Cursor::GetObject(args, 0)->GetEntity();
	SDL_FreeCursor(cursor);
	return Value::Null;
}

// sdl2.sdl_GetCursor
Gura_DeclareFunction(sdl_GetCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetCursor)
{
	SDL_Cursor *_rtn = SDL_GetCursor();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, false));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.sdl_GetDefaultCursor
Gura_DeclareFunction(sdl_GetDefaultCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetDefaultCursor)
{
	SDL_Cursor *_rtn = SDL_GetDefaultCursor();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(_rtn, true)));
}

// sdl2.sdl_GetGlobalMouseState
Gura_DeclareFunction(sdl_GetGlobalMouseState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetGlobalMouseState)
{
#if 0
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetGlobalMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
#endif
	SetError_NotImpFunction(sig, "sdl_GetGlobalMouseState");
	return Value::Null;
}

// sdl2.sdl_GetMouseFocus
Gura_DeclareFunction(sdl_GetMouseFocus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetMouseFocus)
{
	SDL_Window *_rtn = SDL_GetMouseFocus();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(_rtn)));
}

// sdl2.sdl_GetMouseState
Gura_DeclareFunction(sdl_GetMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetMouseState)
{
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
}

// sdl2.sdl_GetRelativeMouseMode
Gura_DeclareFunction(sdl_GetRelativeMouseMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRelativeMouseMode)
{
	SDL_bool _rtn = SDL_GetRelativeMouseMode();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_GetRelativeMouseState
Gura_DeclareFunction(sdl_GetRelativeMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetRelativeMouseState)
{
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetRelativeMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
}

// sdl2.sdl_SetCursor
Gura_DeclareFunction(sdl_SetCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetCursor)
{
	SDL_Cursor *cursor = Object_Cursor::GetObject(args, 0)->GetEntity();
	SDL_SetCursor(cursor);
	return Value::Null;
}

// sdl2.sdl_SetRelativeMouseMode
Gura_DeclareFunction(sdl_SetRelativeMouseMode)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "enabled", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SetRelativeMouseMode)
{
	SDL_bool enabled = (args.GetBoolean(0)? SDL_TRUE : SDL_FALSE);
	int _rtn = SDL_SetRelativeMouseMode(enabled);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_ShowCursor
Gura_DeclareFunction(sdl_ShowCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "toggle", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ShowCursor)
{
	int toggle = args.GetInt(0);
	int _rtn = SDL_ShowCursor(toggle);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_WarpMouseGlobal
Gura_DeclareFunction(sdl_WarpMouseGlobal)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WarpMouseGlobal)
{
#if 0
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	SDL_WarpMouseGlobal(x, y);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WarpMouseGlobal");
	return Value::Null;
}

// sdl2.sdl_WarpMouseInWindow
Gura_DeclareFunction(sdl_WarpMouseInWindow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WarpMouseInWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	SDL_WarpMouseInWindow(window, x, y);
	return Value::Null;
}

// sdl2.sdl_JoystickClose
Gura_DeclareFunction(sdl_JoystickClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickClose)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickClose(joystick);
	return Value::Null;
}

// sdl2.sdl_JoystickEventState
Gura_DeclareFunction(sdl_JoystickEventState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickEventState)
{
	int state = args.GetInt(0);
	int _rtn = SDL_JoystickEventState(state);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_JoystickGetAttached
Gura_DeclareFunction(sdl_JoystickGetAttached)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetAttached)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_JoystickGetAttached(joystick);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_JoystickGetAxis
Gura_DeclareFunction(sdl_JoystickGetAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetAxis)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int axis = args.GetInt(1);
	Sint16 _rtn = SDL_JoystickGetAxis(joystick, axis);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickGetBall
Gura_DeclareFunction(sdl_JoystickGetBall)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ball", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetBall)
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

// sdl2.sdl_JoystickGetButton
Gura_DeclareFunction(sdl_JoystickGetButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetButton)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int button = args.GetInt(1);
	Uint8 _rtn = SDL_JoystickGetButton(joystick, button);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_JoystickGetDeviceGUID
Gura_DeclareFunction(sdl_JoystickGetDeviceGUID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetDeviceGUID)
{
	int device_index = args.GetInt(0);
	SDL_JoystickGUID _rtn = SDL_JoystickGetDeviceGUID(device_index);
	return ReturnValue(env, sig, args, Value(new Object_JoystickGUID(_rtn)));
}

// sdl2.sdl_JoystickGetGUID
Gura_DeclareFunction(sdl_JoystickGetGUID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetGUID)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickGUID _rtn = SDL_JoystickGetGUID(joystick);
	return ReturnValue(env, sig, args, Value(new Object_JoystickGUID(_rtn)));
}

// sdl2.sdl_JoystickGetGUIDFromString
Gura_DeclareFunction(sdl_JoystickGetGUIDFromString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchGUID", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetGUIDFromString)
{
	const char *pchGUID = args.GetString(0);
	SDL_JoystickGUID _rtn = SDL_JoystickGetGUIDFromString(pchGUID);
	return ReturnValue(env, sig, args, Value(new Object_JoystickGUID(_rtn)));
}

// sdl2.sdl_JoystickGetGUIDString
Gura_DeclareFunction(sdl_JoystickGetGUIDString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "guid", VTYPE_JoystickGUID, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetGUIDString)
{
	SDL_JoystickGUID guid = Object_JoystickGUID::GetObject(args, 0)->GetEntity();
	char szGUID[64];
	int cbGUID = sizeof(szGUID);
	SDL_JoystickGetGUIDString(guid, szGUID, cbGUID);
	return ReturnValue(env, sig, args, Value(szGUID));
}

// sdl2.sdl_JoystickGetHat
Gura_DeclareFunction(sdl_JoystickGetHat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hat", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickGetHat)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int hat = args.GetInt(1);
	Uint8 _rtn = SDL_JoystickGetHat(joystick, hat);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickInstanceID
Gura_DeclareFunction(sdl_JoystickInstanceID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickInstanceID)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickID _rtn = SDL_JoystickInstanceID(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickName
Gura_DeclareFunction(sdl_JoystickName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickName)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_JoystickName(joystick);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickNameForIndex
Gura_DeclareFunction(sdl_JoystickNameForIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickNameForIndex)
{
	int device_index = args.GetInt(0);
	const char *_rtn = SDL_JoystickNameForIndex(device_index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickNumAxes
Gura_DeclareFunction(sdl_JoystickNumAxes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickNumAxes)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumAxes(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickNumBalls
Gura_DeclareFunction(sdl_JoystickNumBalls)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickNumBalls)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumBalls(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickNumButtons
Gura_DeclareFunction(sdl_JoystickNumButtons)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickNumButtons)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumButtons(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickNumHats
Gura_DeclareFunction(sdl_JoystickNumHats)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickNumHats)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickNumHats(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_JoystickOpen
Gura_DeclareFunction(sdl_JoystickOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickOpen)
{
	int device_index = args.GetInt(0);
	SDL_Joystick *_rtn = SDL_JoystickOpen(device_index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Joystick(_rtn)));
}

// sdl2.sdl_JoystickUpdate
Gura_DeclareFunction(sdl_JoystickUpdate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickUpdate)
{
	SDL_JoystickUpdate();
	return Value::Null;
}

// sdl2.sdl_NumJoysticks
Gura_DeclareFunction(sdl_NumJoysticks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_NumJoysticks)
{
	int _rtn = SDL_NumJoysticks();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerAddMapping
Gura_DeclareFunction(sdl_GameControllerAddMapping)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "mappingString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerAddMapping)
{
	const char *mappingString = args.GetString(0);
	int _rtn = SDL_GameControllerAddMapping(mappingString);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_GameControllerAddMappingsFromFile
Gura_DeclareFunction(sdl_GameControllerAddMappingsFromFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerAddMappingsFromFile)
{
	Stream &file = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> _file(CreateRWopsStream(&file, &sig));
	int _rtn = SDL_GameControllerAddMappingsFromRW(_file.get(), 0);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerAddMappingsFromRW
Gura_DeclareFunction(sdl_GameControllerAddMappingsFromRW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerAddMappingsFromRW)
{
#if 0
	SDL_GameControllerAddMappingsFromRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GameControllerAddMappingsFromRW");
	return Value::Null;
}

// sdl2.sdl_GameControllerClose
Gura_DeclareFunction(sdl_GameControllerClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerClose)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerClose(gamecontroller);
	return Value::Null;
}

// sdl2.sdl_GameControllerEventState
Gura_DeclareFunction(sdl_GameControllerEventState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerEventState)
{
	int state = args.GetInt(0);
	int _rtn = SDL_GameControllerEventState(state);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerGetAttached
Gura_DeclareFunction(sdl_GameControllerGetAttached)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetAttached)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_GameControllerGetAttached(gamecontroller);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_GameControllerGetAxis
Gura_DeclareFunction(sdl_GameControllerGetAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetAxis)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	Sint16 _rtn = SDL_GameControllerGetAxis(gamecontroller, axis);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerGetAxisFromString
Gura_DeclareFunction(sdl_GameControllerGetAxisFromString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetAxisFromString)
{
	const char *pchString = args.GetString(0);
	SDL_GameControllerAxis _rtn = SDL_GameControllerGetAxisFromString(pchString);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerGetBindForAxis
Gura_DeclareFunction(sdl_GameControllerGetBindForAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetBindForAxis)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	SDL_GameControllerButtonBind _rtn = SDL_GameControllerGetBindForAxis(gamecontroller, axis);
	return ReturnValue(env, sig, args, Value(new Object_GameControllerButtonBind(_rtn)));
}

// sdl2.sdl_GameControllerGetBindForButton
Gura_DeclareFunction(sdl_GameControllerGetBindForButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetBindForButton)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(1));
	SDL_GameControllerButtonBind _rtn = SDL_GameControllerGetBindForButton(gamecontroller, button);
	return ReturnValue(env, sig, args, Value(new Object_GameControllerButtonBind(_rtn)));
}

// sdl2.sdl_GameControllerGetButton
Gura_DeclareFunction(sdl_GameControllerGetButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetButton)
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

// sdl2.sdl_GameControllerGetButtonFromString
Gura_DeclareFunction(sdl_GameControllerGetButtonFromString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetButtonFromString)
{
	const char *pchString = args.GetString(0);
	SDL_GameControllerButton _rtn = SDL_GameControllerGetButtonFromString(pchString);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerGetJoystick
Gura_DeclareFunction(sdl_GameControllerGetJoystick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetJoystick)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_Joystick *_rtn = SDL_GameControllerGetJoystick(gamecontroller);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Joystick(_rtn)));
}

// sdl2.sdl_GameControllerGetStringForAxis
Gura_DeclareFunction(sdl_GameControllerGetStringForAxis)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetStringForAxis)
{
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(0));
	const char *_rtn = SDL_GameControllerGetStringForAxis(axis);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerGetStringForButton
Gura_DeclareFunction(sdl_GameControllerGetStringForButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerGetStringForButton)
{
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(0));
	const char *_rtn = SDL_GameControllerGetStringForButton(button);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerMapping
Gura_DeclareFunction(sdl_GameControllerMapping)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerMapping)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GameControllerMapping(gamecontroller);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerMappingForGUID
Gura_DeclareFunction(sdl_GameControllerMappingForGUID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "guid", VTYPE_JoystickGUID, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerMappingForGUID)
{
	SDL_JoystickGUID guid = Object_JoystickGUID::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GameControllerMappingForGUID(guid);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerName
Gura_DeclareFunction(sdl_GameControllerName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerName)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	const char *_rtn = SDL_GameControllerName(gamecontroller);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerNameForIndex
Gura_DeclareFunction(sdl_GameControllerNameForIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerNameForIndex)
{
	int joystick_index = args.GetInt(0);
	const char *_rtn = SDL_GameControllerNameForIndex(joystick_index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GameControllerOpen
Gura_DeclareFunction(sdl_GameControllerOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerOpen)
{
	int joystick_index = args.GetInt(0);
	SDL_GameController *_rtn = SDL_GameControllerOpen(joystick_index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_GameController(_rtn)));
}

// sdl2.sdl_GameControllerUpdate
Gura_DeclareFunction(sdl_GameControllerUpdate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GameControllerUpdate)
{
	SDL_GameControllerUpdate();
	return Value::Null;
}

// sdl2.sdl_IsGameController
Gura_DeclareFunction(sdl_IsGameController)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_IsGameController)
{
	int joystick_index = args.GetInt(0);
	SDL_bool _rtn = SDL_IsGameController(joystick_index);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HapticClose
Gura_DeclareFunction(sdl_HapticClose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticClose)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	SDL_HapticClose(haptic);
	return Value::Null;
}

// sdl2.sdl_HapticDestroyEffect
Gura_DeclareFunction(sdl_HapticDestroyEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticDestroyEffect)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int effect = args.GetInt(1);
	SDL_HapticDestroyEffect(haptic, effect);
	return Value::Null;
}

// sdl2.sdl_HapticEffectSupported
Gura_DeclareFunction(sdl_HapticEffectSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticEffectSupported)
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

// sdl2.sdl_HapticGetEffectStatus
Gura_DeclareFunction(sdl_HapticGetEffectStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticGetEffectStatus)
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

// sdl2.sdl_HapticIndex
Gura_DeclareFunction(sdl_HapticIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticIndex)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticIndex(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_HapticName
Gura_DeclareFunction(sdl_HapticName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticName)
{
	int device_index = args.GetInt(0);
	const char *_rtn = SDL_HapticName(device_index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_HapticNewEffect
Gura_DeclareFunction(sdl_HapticNewEffect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticNewEffect)
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

// sdl2.sdl_HapticNumAxes
Gura_DeclareFunction(sdl_HapticNumAxes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticNumAxes)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticNumAxes(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_HapticNumEffects
Gura_DeclareFunction(sdl_HapticNumEffects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticNumEffects)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticNumEffects(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_HapticNumEffectsPlaying
Gura_DeclareFunction(sdl_HapticNumEffectsPlaying)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticNumEffectsPlaying)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticNumEffectsPlaying(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_HapticOpen
Gura_DeclareFunction(sdl_HapticOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticOpen)
{
	int device_index = args.GetInt(0);
	SDL_Haptic *_rtn = SDL_HapticOpen(device_index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Haptic(_rtn)));
}

// sdl2.sdl_HapticOpenFromJoystick
Gura_DeclareFunction(sdl_HapticOpenFromJoystick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticOpenFromJoystick)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_Haptic *_rtn = SDL_HapticOpenFromJoystick(joystick);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Haptic(_rtn)));
}

// sdl2.sdl_HapticOpenFromMouse
Gura_DeclareFunction(sdl_HapticOpenFromMouse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticOpenFromMouse)
{
	SDL_Haptic *_rtn = SDL_HapticOpenFromMouse();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(new Object_Haptic(_rtn)));
}

// sdl2.sdl_HapticOpened
Gura_DeclareFunction(sdl_HapticOpened)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticOpened)
{
	int device_index = args.GetInt(0);
	int _rtn = SDL_HapticOpened(device_index);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_HapticPause
Gura_DeclareFunction(sdl_HapticPause)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticPause)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticPause(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_HapticQuery
Gura_DeclareFunction(sdl_HapticQuery)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticQuery)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	unsigned int _rtn = SDL_HapticQuery(haptic);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_HapticRumbleInit
Gura_DeclareFunction(sdl_HapticRumbleInit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticRumbleInit)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticRumbleInit(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_HapticRumblePlay
Gura_DeclareFunction(sdl_HapticRumblePlay)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticRumblePlay)
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

// sdl2.sdl_HapticRumbleStop
Gura_DeclareFunction(sdl_HapticRumbleStop)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticRumbleStop)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticRumbleStop(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_HapticRumbleSupported
Gura_DeclareFunction(sdl_HapticRumbleSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticRumbleSupported)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticRumbleSupported(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_HapticRunEffect
Gura_DeclareFunction(sdl_HapticRunEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iterations", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticRunEffect)
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

// sdl2.sdl_HapticSetAutocenter
Gura_DeclareFunction(sdl_HapticSetAutocenter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "autocenter", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticSetAutocenter)
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

// sdl2.sdl_HapticSetGain
Gura_DeclareFunction(sdl_HapticSetGain)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "gain", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticSetGain)
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

// sdl2.sdl_HapticStopAll
Gura_DeclareFunction(sdl_HapticStopAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticStopAll)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticStopAll(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_HapticStopEffect
Gura_DeclareFunction(sdl_HapticStopEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticStopEffect)
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

// sdl2.sdl_HapticUnpause
Gura_DeclareFunction(sdl_HapticUnpause)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticUnpause)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_HapticUnpause(haptic);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_HapticUpdateEffect
Gura_DeclareFunction(sdl_HapticUpdateEffect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HapticUpdateEffect)
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

// sdl2.sdl_JoystickIsHaptic
Gura_DeclareFunction(sdl_JoystickIsHaptic)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_JoystickIsHaptic)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_JoystickIsHaptic(joystick);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_MouseIsHaptic
Gura_DeclareFunction(sdl_MouseIsHaptic)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_MouseIsHaptic)
{
	int _rtn = SDL_MouseIsHaptic();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_NumHaptics
Gura_DeclareFunction(sdl_NumHaptics)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_NumHaptics)
{
	int _rtn = SDL_NumHaptics();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_AudioInit
Gura_DeclareFunction(sdl_AudioInit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "driver_name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AudioInit)
{
	const char *driver_name = args.GetString(0);
	int _rtn = SDL_AudioInit(driver_name);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_AudioQuit
Gura_DeclareFunction(sdl_AudioQuit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AudioQuit)
{
	SDL_AudioQuit();
	return Value::Null;
}

// sdl2.sdl_BuildAudioCVT
Gura_DeclareFunction(sdl_BuildAudioCVT)
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

Gura_ImplementFunction(sdl_BuildAudioCVT)
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

// sdl2.sdl_ClearQueuedAudio
Gura_DeclareFunction(sdl_ClearQueuedAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ClearQueuedAudio)
{
#if 0
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_ClearQueuedAudio(dev);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ClearQueuedAudio");
	return Value::Null;
}

// sdl2.sdl_CloseAudio
Gura_DeclareFunction(sdl_CloseAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CloseAudio)
{
	SDL_CloseAudio();
	return Value::Null;
}

// sdl2.sdl_CloseAudioDevice
Gura_DeclareFunction(sdl_CloseAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CloseAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_CloseAudioDevice(dev);
	return Value::Null;
}

// sdl2.sdl_ConvertAudio
Gura_DeclareFunction(sdl_ConvertAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cvt", VTYPE_AudioCVT, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ConvertAudio)
{
	SDL_AudioCVT *cvt = Object_AudioCVT::GetObject(args, 0)->GetEntity();
	int _rtn = SDL_ConvertAudio(cvt);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.sdl_FreeWAV
Gura_DeclareFunction(sdl_FreeWAV)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "wav", VTYPE_Wav, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FreeWAV)
{
	Object_Wav *wav = Object_Wav::GetObject(args, 0);
	Object_Wav *pObj = Object_Wav::GetObject(args, 0);
	Uint8 *buffer = pObj->GetBuffer();
	SDL_FreeWAV(buffer);
	return Value::Null;
}

// sdl2.sdl_GetAudioDeviceName
Gura_DeclareFunction(sdl_GetAudioDeviceName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetAudioDeviceName)
{
	int index = args.GetInt(0);
	int iscapture = args.GetInt(1);
	const char *_rtn = SDL_GetAudioDeviceName(index, iscapture);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetAudioDeviceStatus
Gura_DeclareFunction(sdl_GetAudioDeviceStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetAudioDeviceStatus)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_AudioStatus _rtn = SDL_GetAudioDeviceStatus(dev);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetAudioDriver
Gura_DeclareFunction(sdl_GetAudioDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetAudioDriver)
{
	int index = args.GetInt(0);
	const char *_rtn = SDL_GetAudioDriver(index);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetAudioStatus
Gura_DeclareFunction(sdl_GetAudioStatus)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetAudioStatus)
{
	SDL_AudioStatus _rtn = SDL_GetAudioStatus();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetCurrentAudioDriver
Gura_DeclareFunction(sdl_GetCurrentAudioDriver)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetCurrentAudioDriver)
{
	const char *_rtn = SDL_GetCurrentAudioDriver();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetNumAudioDevices
Gura_DeclareFunction(sdl_GetNumAudioDevices)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumAudioDevices)
{
	int iscapture = args.GetInt(0);
	int _rtn = SDL_GetNumAudioDevices(iscapture);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetNumAudioDrivers
Gura_DeclareFunction(sdl_GetNumAudioDrivers)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetNumAudioDrivers)
{
	int _rtn = SDL_GetNumAudioDrivers();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetQueuedAudioSize
Gura_DeclareFunction(sdl_GetQueuedAudioSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetQueuedAudioSize)
{
#if 0
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	Uint32 _rtn = SDL_GetQueuedAudioSize(dev);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "sdl_GetQueuedAudioSize");
	return Value::Null;
}

// sdl2.sdl_LoadWAV
Gura_DeclareFunction(sdl_LoadWAV)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LoadWAV)
{
	Stream &file = Object_stream::GetObject(args, 0)->GetStream();
	std::auto_ptr<SDL_RWops> _file(CreateRWopsStream(&file, &sig));
	SDL_AudioSpec spec;
	Uint8 *audio_buf = NULL;
	Uint32 audio_len = 0;
	SDL_AudioSpec *_rtn = SDL_LoadWAV_RW(_file.get(), 0, &spec, &audio_buf, &audio_len);
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Wav(spec, audio_buf, audio_len)));
}

// sdl2.sdl_LoadWAV_RW
Gura_DeclareFunction(sdl_LoadWAV_RW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LoadWAV_RW)
{
#if 0
	SDL_LoadWAV_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LoadWAV_RW");
	return Value::Null;
}

// sdl2.sdl_LockAudio
Gura_DeclareFunction(sdl_LockAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LockAudio)
{
	SDL_LockAudio();
	return Value::Null;
}

// sdl2.sdl_LockAudioDevice
Gura_DeclareFunction(sdl_LockAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LockAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_LockAudioDevice(dev);
	return Value::Null;
}

// sdl2.sdl_MixAudio
Gura_DeclareFunction(sdl_MixAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "volume", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_MixAudio)
{
#if 0
	int volume = args.GetInt(0);
	SDL_MixAudio(volume);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_MixAudio");
	return Value::Null;
}

// sdl2.sdl_MixAudioFormat
Gura_DeclareFunction(sdl_MixAudioFormat)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "volume", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_MixAudioFormat)
{
#if 0
	SDL_AudioFormat format = static_cast<SDL_AudioFormat>(args.GetInt(0));
	int volume = args.GetInt(1);
	SDL_MixAudioFormat(format, volume);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_MixAudioFormat");
	return Value::Null;
}

// sdl2.sdl_OpenAudio
Gura_DeclareFunction(sdl_OpenAudio)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "desired", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_OpenAudio)
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

// sdl2.sdl_OpenAudioDevice
Gura_DeclareFunction(sdl_OpenAudioDevice)
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

Gura_ImplementFunction(sdl_OpenAudioDevice)
{
#if 0
	const char *device = args.GetString(0);
	int iscapture = args.GetInt(1);
	const SDL_AudioSpec *desired = Object_AudioSpec::GetObject(args, 2)->GetEntity();
	int allowed_changes = args.GetInt(3);
	SDL_AudioDeviceID _rtn = SDL_OpenAudioDevice(device, iscapture, desired, allowed_changes);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "sdl_OpenAudioDevice");
	return Value::Null;
}

// sdl2.sdl_PauseAudio
Gura_DeclareFunction(sdl_PauseAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PauseAudio)
{
	int pause_on = args.GetInt(0);
	SDL_PauseAudio(pause_on);
	return Value::Null;
}

// sdl2.sdl_PauseAudioDevice
Gura_DeclareFunction(sdl_PauseAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_PauseAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	int pause_on = args.GetInt(1);
	SDL_PauseAudioDevice(dev, pause_on);
	return Value::Null;
}

// sdl2.sdl_QueueAudio
Gura_DeclareFunction(sdl_QueueAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_QueueAudio)
{
#if 0
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	int _rtn = SDL_QueueAudio(dev);
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_QueueAudio");
	return Value::Null;
}

// sdl2.sdl_UnlockAudio
Gura_DeclareFunction(sdl_UnlockAudio)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UnlockAudio)
{
	SDL_UnlockAudio();
	return Value::Null;
}

// sdl2.sdl_UnlockAudioDevice
Gura_DeclareFunction(sdl_UnlockAudioDevice)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UnlockAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_UnlockAudioDevice(dev);
	return Value::Null;
}

// sdl2.sdl_AUDIO_BITSIZE
Gura_DeclareFunction(sdl_AUDIO_BITSIZE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AUDIO_BITSIZE)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_BITSIZE(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_AUDIO_ISFLOAT
Gura_DeclareFunction(sdl_AUDIO_ISFLOAT)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AUDIO_ISFLOAT)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISFLOAT(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_AUDIO_ISBIGENDIAN
Gura_DeclareFunction(sdl_AUDIO_ISBIGENDIAN)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AUDIO_ISBIGENDIAN)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISBIGENDIAN(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_AUDIO_ISSIGNED
Gura_DeclareFunction(sdl_AUDIO_ISSIGNED)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AUDIO_ISSIGNED)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISSIGNED(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.sdl_AUDIO_ISINT
Gura_DeclareFunction(sdl_AUDIO_ISINT)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AUDIO_ISINT)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISINT(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_AUDIO_ISLITTLEENDIAN
Gura_DeclareFunction(sdl_AUDIO_ISLITTLEENDIAN)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AUDIO_ISLITTLEENDIAN)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISLITTLEENDIAN(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_AUDIO_ISUNSIGNED
Gura_DeclareFunction(sdl_AUDIO_ISUNSIGNED)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AUDIO_ISUNSIGNED)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISUNSIGNED(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_CreateThread
Gura_DeclareFunction(sdl_CreateThread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateThread)
{
#if 0
	SDL_CreateThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CreateThread");
	return Value::Null;
}

// sdl2.sdl_DetachThread
Gura_DeclareFunction(sdl_DetachThread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DetachThread)
{
#if 0
	SDL_DetachThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_DetachThread");
	return Value::Null;
}

// sdl2.sdl_GetThreadID
Gura_DeclareFunction(sdl_GetThreadID)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetThreadID)
{
#if 0
	SDL_GetThreadID();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetThreadID");
	return Value::Null;
}

// sdl2.sdl_GetThreadName
Gura_DeclareFunction(sdl_GetThreadName)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetThreadName)
{
#if 0
	SDL_GetThreadName();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetThreadName");
	return Value::Null;
}

// sdl2.sdl_GetThreadPriority
Gura_DeclareFunction(sdl_GetThreadPriority)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetThreadPriority)
{
#if 0
	SDL_GetThreadPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_GetThreadPriority");
	return Value::Null;
}

// sdl2.sdl_TLSCreate
Gura_DeclareFunction(sdl_TLSCreate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_TLSCreate)
{
#if 0
	SDL_TLSCreate();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_TLSCreate");
	return Value::Null;
}

// sdl2.sdl_TLSGet
Gura_DeclareFunction(sdl_TLSGet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_TLSGet)
{
#if 0
	SDL_TLSGet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_TLSGet");
	return Value::Null;
}

// sdl2.sdl_TLSSet
Gura_DeclareFunction(sdl_TLSSet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_TLSSet)
{
#if 0
	SDL_TLSSet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_TLSSet");
	return Value::Null;
}

// sdl2.sdl_ThreadID
Gura_DeclareFunction(sdl_ThreadID)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ThreadID)
{
#if 0
	SDL_ThreadID();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ThreadID");
	return Value::Null;
}

// sdl2.sdl_WaitThread
Gura_DeclareFunction(sdl_WaitThread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WaitThread)
{
#if 0
	SDL_WaitThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WaitThread");
	return Value::Null;
}

// sdl2.sdl_CondBroadcast
Gura_DeclareFunction(sdl_CondBroadcast)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CondBroadcast)
{
#if 0
	SDL_CondBroadcast();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CondBroadcast");
	return Value::Null;
}

// sdl2.sdl_CondSignal
Gura_DeclareFunction(sdl_CondSignal)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CondSignal)
{
#if 0
	SDL_CondSignal();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CondSignal");
	return Value::Null;
}

// sdl2.sdl_CondWait
Gura_DeclareFunction(sdl_CondWait)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CondWait)
{
#if 0
	SDL_CondWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CondWait");
	return Value::Null;
}

// sdl2.sdl_CondWaitTimeout
Gura_DeclareFunction(sdl_CondWaitTimeout)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CondWaitTimeout)
{
#if 0
	SDL_CondWaitTimeout();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CondWaitTimeout");
	return Value::Null;
}

// sdl2.sdl_CreateCond
Gura_DeclareFunction(sdl_CreateCond)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateCond)
{
#if 0
	SDL_CreateCond();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CreateCond");
	return Value::Null;
}

// sdl2.sdl_CreateMutex
Gura_DeclareFunction(sdl_CreateMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateMutex)
{
#if 0
	SDL_CreateMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CreateMutex");
	return Value::Null;
}

// sdl2.sdl_CreateSemaphore
Gura_DeclareFunction(sdl_CreateSemaphore)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CreateSemaphore)
{
#if 0
	SDL_CreateSemaphore();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CreateSemaphore");
	return Value::Null;
}

// sdl2.sdl_DestroyCond
Gura_DeclareFunction(sdl_DestroyCond)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DestroyCond)
{
#if 0
	SDL_DestroyCond();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_DestroyCond");
	return Value::Null;
}

// sdl2.sdl_DestroyMutex
Gura_DeclareFunction(sdl_DestroyMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DestroyMutex)
{
#if 0
	SDL_DestroyMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_DestroyMutex");
	return Value::Null;
}

// sdl2.sdl_DestroySemaphore
Gura_DeclareFunction(sdl_DestroySemaphore)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_DestroySemaphore)
{
#if 0
	SDL_DestroySemaphore();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_DestroySemaphore");
	return Value::Null;
}

// sdl2.sdl_LockMutex
Gura_DeclareFunction(sdl_LockMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_LockMutex)
{
#if 0
	SDL_LockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_LockMutex");
	return Value::Null;
}

// sdl2.sdl_SemPost
Gura_DeclareFunction(sdl_SemPost)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SemPost)
{
#if 0
	SDL_SemPost();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SemPost");
	return Value::Null;
}

// sdl2.sdl_SemTryWait
Gura_DeclareFunction(sdl_SemTryWait)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SemTryWait)
{
#if 0
	SDL_SemTryWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SemTryWait");
	return Value::Null;
}

// sdl2.sdl_SemValue
Gura_DeclareFunction(sdl_SemValue)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SemValue)
{
#if 0
	SDL_SemValue();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SemValue");
	return Value::Null;
}

// sdl2.sdl_SemWait
Gura_DeclareFunction(sdl_SemWait)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SemWait)
{
#if 0
	SDL_SemWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SemWait");
	return Value::Null;
}

// sdl2.sdl_SemWaitTimeout
Gura_DeclareFunction(sdl_SemWaitTimeout)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SemWaitTimeout)
{
#if 0
	SDL_SemWaitTimeout();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SemWaitTimeout");
	return Value::Null;
}

// sdl2.sdl_TryLockMutex
Gura_DeclareFunction(sdl_TryLockMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_TryLockMutex)
{
#if 0
	SDL_TryLockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_TryLockMutex");
	return Value::Null;
}

// sdl2.sdl_UnlockMutex
Gura_DeclareFunction(sdl_UnlockMutex)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_UnlockMutex)
{
#if 0
	SDL_UnlockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_UnlockMutex");
	return Value::Null;
}

// sdl2.sdl_AtomicAdd
Gura_DeclareFunction(sdl_AtomicAdd)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicAdd)
{
#if 0
	SDL_AtomicAdd();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicAdd");
	return Value::Null;
}

// sdl2.sdl_AtomicCAS
Gura_DeclareFunction(sdl_AtomicCAS)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicCAS)
{
#if 0
	SDL_AtomicCAS();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicCAS");
	return Value::Null;
}

// sdl2.sdl_AtomicCASPtr
Gura_DeclareFunction(sdl_AtomicCASPtr)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicCASPtr)
{
#if 0
	SDL_AtomicCASPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicCASPtr");
	return Value::Null;
}

// sdl2.sdl_AtomicDecRef
Gura_DeclareFunction(sdl_AtomicDecRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicDecRef)
{
#if 0
	SDL_AtomicDecRef();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicDecRef");
	return Value::Null;
}

// sdl2.sdl_AtomicGet
Gura_DeclareFunction(sdl_AtomicGet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicGet)
{
#if 0
	SDL_AtomicGet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicGet");
	return Value::Null;
}

// sdl2.sdl_AtomicGetPtr
Gura_DeclareFunction(sdl_AtomicGetPtr)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicGetPtr)
{
#if 0
	SDL_AtomicGetPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicGetPtr");
	return Value::Null;
}

// sdl2.sdl_AtomicIncRef
Gura_DeclareFunction(sdl_AtomicIncRef)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicIncRef)
{
#if 0
	SDL_AtomicIncRef();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicIncRef");
	return Value::Null;
}

// sdl2.sdl_AtomicLock
Gura_DeclareFunction(sdl_AtomicLock)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicLock)
{
#if 0
	SDL_AtomicLock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicLock");
	return Value::Null;
}

// sdl2.sdl_AtomicSet
Gura_DeclareFunction(sdl_AtomicSet)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicSet)
{
#if 0
	SDL_AtomicSet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicSet");
	return Value::Null;
}

// sdl2.sdl_AtomicSetPtr
Gura_DeclareFunction(sdl_AtomicSetPtr)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicSetPtr)
{
#if 0
	SDL_AtomicSetPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicSetPtr");
	return Value::Null;
}

// sdl2.sdl_AtomicTryLock
Gura_DeclareFunction(sdl_AtomicTryLock)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicTryLock)
{
#if 0
	SDL_AtomicTryLock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicTryLock");
	return Value::Null;
}

// sdl2.sdl_AtomicUnlock
Gura_DeclareFunction(sdl_AtomicUnlock)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AtomicUnlock)
{
#if 0
	SDL_AtomicUnlock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AtomicUnlock");
	return Value::Null;
}

// sdl2.sdl_CompilerBarrier
Gura_DeclareFunction(sdl_CompilerBarrier)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_CompilerBarrier)
{
#if 0
	SDL_CompilerBarrier();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_CompilerBarrier");
	return Value::Null;
}

// sdl2.sdl_AddTimer
Gura_DeclareFunction(sdl_AddTimer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "interval", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AddTimer)
{
#if 0
	Uint32 interval = args.GetULong(0);
	SDL_TimerID _rtn = SDL_AddTimer(interval);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "sdl_AddTimer");
	return Value::Null;
}

// sdl2.sdl_Delay
Gura_DeclareFunction(sdl_Delay)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "ms", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Delay)
{
	Uint32 ms = args.GetULong(0);
	SDL_Delay(ms);
	return Value::Null;
}

// sdl2.sdl_GetPerformanceCounter
Gura_DeclareFunction(sdl_GetPerformanceCounter)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetPerformanceCounter)
{
	Uint64 _rtn = SDL_GetPerformanceCounter();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetPerformanceFrequency
Gura_DeclareFunction(sdl_GetPerformanceFrequency)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetPerformanceFrequency)
{
	Uint64 _rtn = SDL_GetPerformanceFrequency();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetTicks
Gura_DeclareFunction(sdl_GetTicks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetTicks)
{
	Uint32 _rtn = SDL_GetTicks();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_RemoveTimer
Gura_DeclareFunction(sdl_RemoveTimer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RemoveTimer)
{
	SDL_TimerID id = static_cast<SDL_TimerID>(args.GetInt(0));
	SDL_bool _rtn = SDL_RemoveTimer(id);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_TICKS_PASSED
Gura_DeclareFunction(sdl_TICKS_PASSED)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_TICKS_PASSED)
{
	Uint32 A = args.GetULong(0);
	Uint32 B = args.GetULong(1);
	bool _rtn = SDL_TICKS_PASSED(A, B);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetBasePath
Gura_DeclareFunction(sdl_GetBasePath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetBasePath)
{
#if 0
	char *_rtn = SDL_GetBasePath();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "sdl_GetBasePath");
	return Value::Null;
}

// sdl2.sdl_GetPrefPath
Gura_DeclareFunction(sdl_GetPrefPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "org", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "app", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetPrefPath)
{
#if 0
	const char *org = args.GetString(0);
	const char *app = args.GetString(1);
	char *_rtn = SDL_GetPrefPath(org, app);
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "sdl_GetPrefPath");
	return Value::Null;
}

// sdl2.sdl_AllocRW
Gura_DeclareFunction(sdl_AllocRW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AllocRW)
{
#if 0
	SDL_AllocRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AllocRW");
	return Value::Null;
}

// sdl2.sdl_FreeRW
Gura_DeclareFunction(sdl_FreeRW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_FreeRW)
{
#if 0
	SDL_FreeRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_FreeRW");
	return Value::Null;
}

// sdl2.sdl_RWFromConstMem
Gura_DeclareFunction(sdl_RWFromConstMem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWFromConstMem)
{
#if 0
	SDL_RWFromConstMem();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWFromConstMem");
	return Value::Null;
}

// sdl2.sdl_RWFromFP
Gura_DeclareFunction(sdl_RWFromFP)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWFromFP)
{
#if 0
	SDL_RWFromFP();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWFromFP");
	return Value::Null;
}

// sdl2.sdl_RWFromFile
Gura_DeclareFunction(sdl_RWFromFile)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWFromFile)
{
#if 0
	SDL_RWFromFile();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWFromFile");
	return Value::Null;
}

// sdl2.sdl_RWFromMem
Gura_DeclareFunction(sdl_RWFromMem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWFromMem)
{
#if 0
	SDL_RWFromMem();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWFromMem");
	return Value::Null;
}

// sdl2.sdl_RWclose
Gura_DeclareFunction(sdl_RWclose)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWclose)
{
#if 0
	SDL_RWclose();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWclose");
	return Value::Null;
}

// sdl2.sdl_RWread
Gura_DeclareFunction(sdl_RWread)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWread)
{
#if 0
	SDL_RWread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWread");
	return Value::Null;
}

// sdl2.sdl_RWseek
Gura_DeclareFunction(sdl_RWseek)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWseek)
{
#if 0
	SDL_RWseek();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWseek");
	return Value::Null;
}

// sdl2.sdl_RWtell
Gura_DeclareFunction(sdl_RWtell)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWtell)
{
#if 0
	SDL_RWtell();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWtell");
	return Value::Null;
}

// sdl2.sdl_RWwrite
Gura_DeclareFunction(sdl_RWwrite)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_RWwrite)
{
#if 0
	SDL_RWwrite();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_RWwrite");
	return Value::Null;
}

// sdl2.sdl_ReadBE16
Gura_DeclareFunction(sdl_ReadBE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ReadBE16)
{
#if 0
	SDL_ReadBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ReadBE16");
	return Value::Null;
}

// sdl2.sdl_ReadBE32
Gura_DeclareFunction(sdl_ReadBE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ReadBE32)
{
#if 0
	SDL_ReadBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ReadBE32");
	return Value::Null;
}

// sdl2.sdl_ReadBE64
Gura_DeclareFunction(sdl_ReadBE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ReadBE64)
{
#if 0
	SDL_ReadBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ReadBE64");
	return Value::Null;
}

// sdl2.sdl_ReadLE16
Gura_DeclareFunction(sdl_ReadLE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ReadLE16)
{
#if 0
	SDL_ReadLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ReadLE16");
	return Value::Null;
}

// sdl2.sdl_ReadLE32
Gura_DeclareFunction(sdl_ReadLE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ReadLE32)
{
#if 0
	SDL_ReadLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ReadLE32");
	return Value::Null;
}

// sdl2.sdl_ReadLE64
Gura_DeclareFunction(sdl_ReadLE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_ReadLE64)
{
#if 0
	SDL_ReadLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_ReadLE64");
	return Value::Null;
}

// sdl2.sdl_WriteBE16
Gura_DeclareFunction(sdl_WriteBE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WriteBE16)
{
#if 0
	SDL_WriteBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WriteBE16");
	return Value::Null;
}

// sdl2.sdl_WriteBE32
Gura_DeclareFunction(sdl_WriteBE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WriteBE32)
{
#if 0
	SDL_WriteBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WriteBE32");
	return Value::Null;
}

// sdl2.sdl_WriteBE64
Gura_DeclareFunction(sdl_WriteBE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WriteBE64)
{
#if 0
	SDL_WriteBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WriteBE64");
	return Value::Null;
}

// sdl2.sdl_WriteLE16
Gura_DeclareFunction(sdl_WriteLE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WriteLE16)
{
#if 0
	SDL_WriteLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WriteLE16");
	return Value::Null;
}

// sdl2.sdl_WriteLE32
Gura_DeclareFunction(sdl_WriteLE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WriteLE32)
{
#if 0
	SDL_WriteLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WriteLE32");
	return Value::Null;
}

// sdl2.sdl_WriteLE64
Gura_DeclareFunction(sdl_WriteLE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_WriteLE64)
{
#if 0
	SDL_WriteLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_WriteLE64");
	return Value::Null;
}

// sdl2.sdl_GetPlatform
Gura_DeclareFunction(sdl_GetPlatform)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetPlatform)
{
	const char *_rtn = SDL_GetPlatform();
	if (_rtn == NULL) {
		if (*SDL_GetError() != '\0') {
			SetError_SDL(sig);
			return Value::Null;
		}
		return ReturnValue(env, sig, args, Value::Null);
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetCPUCacheLineSize
Gura_DeclareFunction(sdl_GetCPUCacheLineSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetCPUCacheLineSize)
{
	int _rtn = SDL_GetCPUCacheLineSize();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetCPUCount
Gura_DeclareFunction(sdl_GetCPUCount)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetCPUCount)
{
	int _rtn = SDL_GetCPUCount();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_GetSystemRAM
Gura_DeclareFunction(sdl_GetSystemRAM)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetSystemRAM)
{
	int _rtn = SDL_GetSystemRAM();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.sdl_Has3DNow
Gura_DeclareFunction(sdl_Has3DNow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Has3DNow)
{
	SDL_bool _rtn = SDL_Has3DNow();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasAVX
Gura_DeclareFunction(sdl_HasAVX)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasAVX)
{
	SDL_bool _rtn = SDL_HasAVX();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasAVX2
Gura_DeclareFunction(sdl_HasAVX2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasAVX2)
{
#if 0
	SDL_bool _rtn = SDL_HasAVX2();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "sdl_HasAVX2");
	return Value::Null;
}

// sdl2.sdl_HasAltiVec
Gura_DeclareFunction(sdl_HasAltiVec)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasAltiVec)
{
	SDL_bool _rtn = SDL_HasAltiVec();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasMMX
Gura_DeclareFunction(sdl_HasMMX)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasMMX)
{
	SDL_bool _rtn = SDL_HasMMX();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasRDTSC
Gura_DeclareFunction(sdl_HasRDTSC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasRDTSC)
{
	SDL_bool _rtn = SDL_HasRDTSC();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasSSE
Gura_DeclareFunction(sdl_HasSSE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasSSE)
{
	SDL_bool _rtn = SDL_HasSSE();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasSSE2
Gura_DeclareFunction(sdl_HasSSE2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasSSE2)
{
	SDL_bool _rtn = SDL_HasSSE2();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasSSE3
Gura_DeclareFunction(sdl_HasSSE3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasSSE3)
{
	SDL_bool _rtn = SDL_HasSSE3();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasSSE41
Gura_DeclareFunction(sdl_HasSSE41)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasSSE41)
{
	SDL_bool _rtn = SDL_HasSSE41();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_HasSSE42
Gura_DeclareFunction(sdl_HasSSE42)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_HasSSE42)
{
	SDL_bool _rtn = SDL_HasSSE42();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.sdl_Swap16
Gura_DeclareFunction(sdl_Swap16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Swap16)
{
#if 0
	SDL_Swap16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_Swap16");
	return Value::Null;
}

// sdl2.sdl_Swap32
Gura_DeclareFunction(sdl_Swap32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Swap32)
{
#if 0
	SDL_Swap32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_Swap32");
	return Value::Null;
}

// sdl2.sdl_Swap64
Gura_DeclareFunction(sdl_Swap64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_Swap64)
{
#if 0
	SDL_Swap64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_Swap64");
	return Value::Null;
}

// sdl2.sdl_SwapBE16
Gura_DeclareFunction(sdl_SwapBE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapBE16)
{
#if 0
	SDL_SwapBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapBE16");
	return Value::Null;
}

// sdl2.sdl_SwapBE32
Gura_DeclareFunction(sdl_SwapBE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapBE32)
{
#if 0
	SDL_SwapBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapBE32");
	return Value::Null;
}

// sdl2.sdl_SwapBE64
Gura_DeclareFunction(sdl_SwapBE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapBE64)
{
#if 0
	SDL_SwapBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapBE64");
	return Value::Null;
}

// sdl2.sdl_SwapFloat
Gura_DeclareFunction(sdl_SwapFloat)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapFloat)
{
#if 0
	SDL_SwapFloat();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapFloat");
	return Value::Null;
}

// sdl2.sdl_SwapFloatBE
Gura_DeclareFunction(sdl_SwapFloatBE)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapFloatBE)
{
#if 0
	SDL_SwapFloatBE();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapFloatBE");
	return Value::Null;
}

// sdl2.sdl_SwapFloatLE
Gura_DeclareFunction(sdl_SwapFloatLE)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapFloatLE)
{
#if 0
	SDL_SwapFloatLE();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapFloatLE");
	return Value::Null;
}

// sdl2.sdl_SwapLE16
Gura_DeclareFunction(sdl_SwapLE16)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapLE16)
{
#if 0
	SDL_SwapLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapLE16");
	return Value::Null;
}

// sdl2.sdl_SwapLE32
Gura_DeclareFunction(sdl_SwapLE32)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapLE32)
{
#if 0
	SDL_SwapLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapLE32");
	return Value::Null;
}

// sdl2.sdl_SwapLE64
Gura_DeclareFunction(sdl_SwapLE64)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_SwapLE64)
{
#if 0
	SDL_SwapLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_SwapLE64");
	return Value::Null;
}

// sdl2.sdl_MostSignificantBitIndex32
Gura_DeclareFunction(sdl_MostSignificantBitIndex32)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_MostSignificantBitIndex32)
{
#if 0
	Uint32 x = args.GetULong(0);
	int _rtn = SDL_MostSignificantBitIndex32(x);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "sdl_MostSignificantBitIndex32");
	return Value::Null;
}

// sdl2.sdl_GetPowerInfo
Gura_DeclareFunction(sdl_GetPowerInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_GetPowerInfo)
{
	int secs = 0;
	int pct = 0;
	SDL_PowerState _rtn = SDL_GetPowerInfo(&secs, &pct);
	return ReturnValue(env, sig, args, Value::CreateList(env,
									Value(_rtn), Value(secs), Value(pct)));
}

// sdl2.sdl_AndroidGetActivity
Gura_DeclareFunction(sdl_AndroidGetActivity)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AndroidGetActivity)
{
#if 0
	SDL_AndroidGetActivity();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AndroidGetActivity");
	return Value::Null;
}

// sdl2.sdl_AndroidGetExternalStoragePath
Gura_DeclareFunction(sdl_AndroidGetExternalStoragePath)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AndroidGetExternalStoragePath)
{
#if 0
	SDL_AndroidGetExternalStoragePath();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AndroidGetExternalStoragePath");
	return Value::Null;
}

// sdl2.sdl_AndroidGetExternalStorageState
Gura_DeclareFunction(sdl_AndroidGetExternalStorageState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AndroidGetExternalStorageState)
{
#if 0
	SDL_AndroidGetExternalStorageState();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AndroidGetExternalStorageState");
	return Value::Null;
}

// sdl2.sdl_AndroidGetInternalStoragePath
Gura_DeclareFunction(sdl_AndroidGetInternalStoragePath)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AndroidGetInternalStoragePath)
{
#if 0
	SDL_AndroidGetInternalStoragePath();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AndroidGetInternalStoragePath");
	return Value::Null;
}

// sdl2.sdl_AndroidGetJNIEnv
Gura_DeclareFunction(sdl_AndroidGetJNIEnv)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_AndroidGetJNIEnv)
{
#if 0
	SDL_AndroidGetJNIEnv();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "sdl_AndroidGetJNIEnv");
	return Value::Null;
}

// sdl2.sdl_acos
Gura_DeclareFunction(sdl_acos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(sdl_acos)
{
	double x = args.GetDouble(0);
	double _rtn = SDL_acos(x);
	return ReturnValue(env, sig, args, Value(_rtn));
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
		Gura_AssignFunction(sdl_Init);
		Gura_AssignFunction(sdl_InitSubSystem);
		Gura_AssignFunction(sdl_Quit);
		Gura_AssignFunction(sdl_QuitSubSystem);
		Gura_AssignFunction(sdl_SetMainReady);
		Gura_AssignFunction(sdl_WasInit);
		Gura_AssignFunction(sdl_AddHintCallback);
		Gura_AssignFunction(sdl_ClearHints);
		Gura_AssignFunction(sdl_DelhintCallback);
		Gura_AssignFunction(sdl_GetHint);
		Gura_AssignFunction(sdl_SetHint);
		Gura_AssignFunction(sdl_SetHintWithPriority);
		Gura_AssignFunction(sdl_ClearError);
		Gura_AssignFunction(sdl_GetError);
		Gura_AssignFunction(sdl_SetError);
		Gura_AssignFunction(sdl_Log);
		Gura_AssignFunction(sdl_LogCritical);
		Gura_AssignFunction(sdl_LogDebug);
		Gura_AssignFunction(sdl_LogError);
		Gura_AssignFunction(sdl_LogGetOutputFunction);
		Gura_AssignFunction(sdl_LogGetPriority);
		Gura_AssignFunction(sdl_LogInfo);
		Gura_AssignFunction(sdl_LogMessage);
		Gura_AssignFunction(sdl_LogMessageV);
		Gura_AssignFunction(sdl_LogResetPriorities);
		Gura_AssignFunction(sdl_LogSetAllPriority);
		Gura_AssignFunction(sdl_LogSetOutputFunction);
		Gura_AssignFunction(sdl_LogSetPriority);
		Gura_AssignFunction(sdl_LogVerbose);
		Gura_AssignFunction(sdl_LogWarn);
		Gura_AssignFunction(sdl_GetAssertionHandler);
		Gura_AssignFunction(sdl_GetAssertionReport);
		Gura_AssignFunction(sdl_GetDefaultAssertionHandler);
		Gura_AssignFunction(sdl_ResetAssertionReport);
		Gura_AssignFunction(sdl_SetAssertionHandler);
		Gura_AssignFunction(sdl_TriggerBreakpoint);
		Gura_AssignFunction(sdl_assert);
		Gura_AssignFunction(sdl_assert_paranoid);
		Gura_AssignFunction(sdl_assert_release);
		Gura_AssignFunction(sdl_GetRevision);
		Gura_AssignFunction(sdl_GetRevisionNumber);
		Gura_AssignFunction(sdl_GetVersion);
		Gura_AssignFunction(sdl_VERSION);
		Gura_AssignFunction(sdl_VERSION_ATLEAST);
		Gura_AssignFunction(sdl_CreateWindow);
		Gura_AssignFunction(sdl_CreateWindowAndRenderer);
		Gura_AssignFunction(sdl_CreateWindowFrom);
		Gura_AssignFunction(sdl_DestroyWindow);
		Gura_AssignFunction(sdl_DisableScreenSaver);
		Gura_AssignFunction(sdl_EnableScreenSaver);
		Gura_AssignFunction(sdl_GL_CreateContext);
		Gura_AssignFunction(sdl_GL_DeleteContext);
		Gura_AssignFunction(sdl_GL_ExtensionSupported);
		Gura_AssignFunction(sdl_GL_GetAttribute);
		Gura_AssignFunction(sdl_GL_GetCurrentContext);
		Gura_AssignFunction(sdl_GL_GetCurrentWindow);
		Gura_AssignFunction(sdl_GL_GetDrawableSize);
		Gura_AssignFunction(sdl_GL_GetProcAddress);
		Gura_AssignFunction(sdl_GL_GetSwapInterval);
		Gura_AssignFunction(sdl_GL_LoadLibrary);
		Gura_AssignFunction(sdl_GL_MakeCurrent);
		Gura_AssignFunction(sdl_GL_ResetAttributes);
		Gura_AssignFunction(sdl_GL_SetAttribute);
		Gura_AssignFunction(sdl_GL_SetSwapInterval);
		Gura_AssignFunction(sdl_GL_SwapWindow);
		Gura_AssignFunction(sdl_GL_UnloadLibrary);
		Gura_AssignFunction(sdl_GetClosestDisplayMode);
		Gura_AssignFunction(sdl_GetCurrentDisplayMode);
		Gura_AssignFunction(sdl_GetCurrentVideoDriver);
		Gura_AssignFunction(sdl_GetDesktopDisplayMode);
		Gura_AssignFunction(sdl_GetDisplayBounds);
		Gura_AssignFunction(sdl_GetDisplayMode);
		Gura_AssignFunction(sdl_GetDisplayName);
		Gura_AssignFunction(sdl_GetNumDisplayModes);
		Gura_AssignFunction(sdl_GetNumVideoDisplays);
		Gura_AssignFunction(sdl_GetNumVideoDrivers);
		Gura_AssignFunction(sdl_GetVideoDriver);
		Gura_AssignFunction(sdl_GetWindowBrightness);
		Gura_AssignFunction(sdl_GetWindowData);
		Gura_AssignFunction(sdl_GetWindowDisplayIndex);
		Gura_AssignFunction(sdl_GetWindowDisplayMode);
		Gura_AssignFunction(sdl_GetWindowFlags);
		Gura_AssignFunction(sdl_GetWindowFromID);
		Gura_AssignFunction(sdl_GetWindowGammaRamp);
		Gura_AssignFunction(sdl_GetWindowGrab);
		Gura_AssignFunction(sdl_GetWindowID);
		Gura_AssignFunction(sdl_GetWindowMaximumSize);
		Gura_AssignFunction(sdl_GetWindowMinimumSize);
		Gura_AssignFunction(sdl_GetWindowPixelFormat);
		Gura_AssignFunction(sdl_GetWindowPosition);
		Gura_AssignFunction(sdl_GetWindowSize);
		Gura_AssignFunction(sdl_GetWindowSurface);
		Gura_AssignFunction(sdl_GetWindowTitle);
		Gura_AssignFunction(sdl_GetWindowWMInfo);
		Gura_AssignFunction(sdl_HideWindow);
		Gura_AssignFunction(sdl_IsScreenSaverEnabled);
		Gura_AssignFunction(sdl_MaximizeWindow);
		Gura_AssignFunction(sdl_MinimizeWindow);
		Gura_AssignFunction(sdl_RaiseWindow);
		Gura_AssignFunction(sdl_RestoreWindow);
		Gura_AssignFunction(sdl_SetWindowBordered);
		Gura_AssignFunction(sdl_SetWindowBrightness);
		Gura_AssignFunction(sdl_SetWindowData);
		Gura_AssignFunction(sdl_SetWindowDisplayMode);
		Gura_AssignFunction(sdl_SetWindowFullscreen);
		Gura_AssignFunction(sdl_SetWindowGammaRamp);
		Gura_AssignFunction(sdl_SetWindowGrab);
		Gura_AssignFunction(sdl_SetWindowHitTest);
		Gura_AssignFunction(sdl_SetWindowIcon);
		Gura_AssignFunction(sdl_SetWindowMaximumSize);
		Gura_AssignFunction(sdl_SetWindowMinimumSize);
		Gura_AssignFunction(sdl_SetWindowPosition);
		Gura_AssignFunction(sdl_SetWindowSize);
		Gura_AssignFunction(sdl_SetWindowTitle);
		Gura_AssignFunction(sdl_ShowMessageBox);
		Gura_AssignFunction(sdl_ShowSimpleMessageBox);
		Gura_AssignFunction(sdl_ShowWindow);
		Gura_AssignFunction(sdl_UpdateWindowSurface);
		Gura_AssignFunction(sdl_UpdateWindowSurfaceRects);
		Gura_AssignFunction(sdl_VideoInit);
		Gura_AssignFunction(sdl_VideoQuit);
		Gura_AssignFunction(sdl_CreateRenderer);
		Gura_AssignFunction(sdl_CreateSoftwareRenderer);
		Gura_AssignFunction(sdl_CreateTexture);
		Gura_AssignFunction(sdl_CreateTextureFromSurface);
		Gura_AssignFunction(sdl_DestroyRenderer);
		Gura_AssignFunction(sdl_DestroyTexture);
		Gura_AssignFunction(sdl_GL_BindTexture);
		Gura_AssignFunction(sdl_GL_UnbindTexture);
		Gura_AssignFunction(sdl_GetNumRenderDrivers);
		Gura_AssignFunction(sdl_GetRenderDrawBlendMode);
		Gura_AssignFunction(sdl_GetRenderDrawColor);
		Gura_AssignFunction(sdl_GetRenderDriverInfo);
		Gura_AssignFunction(sdl_GetRenderTarget);
		Gura_AssignFunction(sdl_GetRenderer);
		Gura_AssignFunction(sdl_GetRendererInfo);
		Gura_AssignFunction(sdl_GetRenderOutputSize);
		Gura_AssignFunction(sdl_GetTextureAlphaMod);
		Gura_AssignFunction(sdl_GetTextureBlendMode);
		Gura_AssignFunction(sdl_GetTextureColorMod);
		Gura_AssignFunction(sdl_LockTexture);
		Gura_AssignFunction(sdl_QueryTexture);
		Gura_AssignFunction(sdl_RenderClear);
		Gura_AssignFunction(sdl_RenderCopy);
		Gura_AssignFunction(sdl_RenderCopyEx);
		Gura_AssignFunction(sdl_RenderDrawLine);
		Gura_AssignFunction(sdl_RenderDrawLines);
		Gura_AssignFunction(sdl_RenderDrawPoint);
		Gura_AssignFunction(sdl_RenderDrawPoints);
		Gura_AssignFunction(sdl_RenderDrawRect);
		Gura_AssignFunction(sdl_RenderDrawRects);
		Gura_AssignFunction(sdl_RenderFillRect);
		Gura_AssignFunction(sdl_RenderFillRects);
		Gura_AssignFunction(sdl_RenderGetClipRect);
		Gura_AssignFunction(sdl_RenderGetLogicalSize);
		Gura_AssignFunction(sdl_RenderGetScale);
		Gura_AssignFunction(sdl_RenderGetViewport);
		Gura_AssignFunction(sdl_RenderIsClipEnabled);
		Gura_AssignFunction(sdl_RenderPresent);
		Gura_AssignFunction(sdl_RenderReadPixels);
		Gura_AssignFunction(sdl_RenderSetClipRect);
		Gura_AssignFunction(sdl_RenderSetLogicalSize);
		Gura_AssignFunction(sdl_RenderSetScale);
		Gura_AssignFunction(sdl_RenderSetViewport);
		Gura_AssignFunction(sdl_RenderTargetSupported);
		Gura_AssignFunction(sdl_SetRenderDrawBlendMode);
		Gura_AssignFunction(sdl_SetRenderDrawColor);
		Gura_AssignFunction(sdl_SetRenderTarget);
		Gura_AssignFunction(sdl_SetTextureAlphaMod);
		Gura_AssignFunction(sdl_SetTextureBlendMode);
		Gura_AssignFunction(sdl_SetTextureColorMod);
		Gura_AssignFunction(sdl_UnlockTexture);
		Gura_AssignFunction(sdl_UpdateTexture);
		Gura_AssignFunction(sdl_UpdateYUVTexture);
		Gura_AssignFunction(sdl_AllocFormat);
		Gura_AssignFunction(sdl_AllocPalette);
		Gura_AssignFunction(sdl_CalculateGammaRamp);
		Gura_AssignFunction(sdl_FreeFormat);
		Gura_AssignFunction(sdl_FreePalette);
		Gura_AssignFunction(sdl_GetPixelFormatName);
		Gura_AssignFunction(sdl_GetRGB);
		Gura_AssignFunction(sdl_GetRGBA);
		Gura_AssignFunction(sdl_MapRGB);
		Gura_AssignFunction(sdl_MapRGBA);
		Gura_AssignFunction(sdl_MasksToPixelFormatEnum);
		Gura_AssignFunction(sdl_PixelFormatEnumToMasks);
		Gura_AssignFunction(sdl_SetPaletteColors);
		Gura_AssignFunction(sdl_SetPixelFormatPalette);
		Gura_AssignFunction(sdl_EnclosePoints);
		Gura_AssignFunction(sdl_HasIntersection);
		Gura_AssignFunction(sdl_IntersectRect);
		Gura_AssignFunction(sdl_IntersectRectAndLine);
		Gura_AssignFunction(sdl_PointInRect);
		Gura_AssignFunction(sdl_RectEmpty);
		Gura_AssignFunction(sdl_RectEquals);
		Gura_AssignFunction(sdl_UnionRect);
		Gura_AssignFunction(sdl_BlitScaled);
		Gura_AssignFunction(sdl_BlitSurface);
		Gura_AssignFunction(sdl_ConvertPixels);
		Gura_AssignFunction(sdl_ConvertSurface);
		Gura_AssignFunction(sdl_ConvertSurfaceFormat);
		Gura_AssignFunction(sdl_CreateRGBSurface);
		Gura_AssignFunction(sdl_CreateRGBSurfaceFrom);
		Gura_AssignFunction(sdl_CreateRGBSurfaceFromImage);
		Gura_AssignFunction(sdl_FillRect);
		Gura_AssignFunction(sdl_FillRects);
		Gura_AssignFunction(sdl_FreeSurface);
		Gura_AssignFunction(sdl_GetClipRect);
		Gura_AssignFunction(sdl_GetColorKey);
		Gura_AssignFunction(sdl_GetSurfaceAlphaMod);
		Gura_AssignFunction(sdl_GetSurfaceBlendMode);
		Gura_AssignFunction(sdl_GetSurfaceColorMod);
		Gura_AssignFunction(sdl_LoadBMP);
		Gura_AssignFunction(sdl_LoadBMP_RW);
		Gura_AssignFunction(sdl_LockSurface);
		Gura_AssignFunction(sdl_LowerBlit);
		Gura_AssignFunction(sdl_LowerBlitScaled);
		Gura_AssignFunction(sdl_MUSTLOCK);
		Gura_AssignFunction(sdl_SaveBMP);
		Gura_AssignFunction(sdl_SaveBMP_RW);
		Gura_AssignFunction(sdl_SetClipRect);
		Gura_AssignFunction(sdl_SetColorKey);
		Gura_AssignFunction(sdl_SetSurfaceAlphaMod);
		Gura_AssignFunction(sdl_SetSurfaceBlendMode);
		Gura_AssignFunction(sdl_SetSurfaceColorMod);
		Gura_AssignFunction(sdl_SetSurfacePalette);
		Gura_AssignFunction(sdl_SetSurfaceRLE);
		Gura_AssignFunction(sdl_UnlockSurface);
		Gura_AssignFunction(sdl_GetClipboardText);
		Gura_AssignFunction(sdl_HasClipboardText);
		Gura_AssignFunction(sdl_SetClipboardText);
		Gura_AssignFunction(sdl_AddEventWatch);
		Gura_AssignFunction(sdl_DelEventWatch);
		Gura_AssignFunction(sdl_EventState);
		Gura_AssignFunction(sdl_FilterEvents);
		Gura_AssignFunction(sdl_FlushEvent);
		Gura_AssignFunction(sdl_FlushEvents);
		Gura_AssignFunction(sdl_GetEventFilter);
		Gura_AssignFunction(sdl_GetNumTouchDevices);
		Gura_AssignFunction(sdl_GetNumTouchFingers);
		Gura_AssignFunction(sdl_GetTouchDevice);
		Gura_AssignFunction(sdl_GetTouchFinger);
		Gura_AssignFunction(sdl_HasEvent);
		Gura_AssignFunction(sdl_HasEvents);
		Gura_AssignFunction(sdl_LoadDollarTemplates);
		Gura_AssignFunction(sdl_AddEvents);
		Gura_AssignFunction(sdl_PeekEvents);
		Gura_AssignFunction(sdl_GetEvents);
		Gura_AssignFunction(sdl_PollEvent);
		Gura_AssignFunction(sdl_PumpEvents);
		Gura_AssignFunction(sdl_PushEvent);
		Gura_AssignFunction(sdl_QuitRequested);
		Gura_AssignFunction(sdl_RecordGesture);
		Gura_AssignFunction(sdl_RegisterEvents);
		Gura_AssignFunction(sdl_SaveAllDollarTemplates);
		Gura_AssignFunction(sdl_SaveDollarTemplate);
		Gura_AssignFunction(sdl_SetEventFilter);
		Gura_AssignFunction(sdl_WaitEvent);
		Gura_AssignFunction(sdl_WaitEventTimeout);
		Gura_AssignFunction(sdl_CheckKeyboardState);
		Gura_AssignFunction(sdl_GetKeyFromName);
		Gura_AssignFunction(sdl_GetKeyFromScancode);
		Gura_AssignFunction(sdl_GetKeyName);
		Gura_AssignFunction(sdl_GetKeyboardFocus);
		Gura_AssignFunction(sdl_GetKeyboardState);
		Gura_AssignFunction(sdl_GetModState);
		Gura_AssignFunction(sdl_GetScancodeFromKey);
		Gura_AssignFunction(sdl_GetScancodeFromName);
		Gura_AssignFunction(sdl_GetScancodeName);
		Gura_AssignFunction(sdl_HasScreenKeyboardSupport);
		Gura_AssignFunction(sdl_IsScreenKeyboardShown);
		Gura_AssignFunction(sdl_IsTextInputActive);
		Gura_AssignFunction(sdl_SetModState);
		Gura_AssignFunction(sdl_SetTextInputRect);
		Gura_AssignFunction(sdl_StartTextInput);
		Gura_AssignFunction(sdl_StopTextInput);
		Gura_AssignFunction(sdl_CaptureMouse);
		Gura_AssignFunction(sdl_CreateColorCursor);
		Gura_AssignFunction(sdl_CreateCursor);
		Gura_AssignFunction(sdl_CreateSystemCursor);
		Gura_AssignFunction(sdl_FreeCursor);
		Gura_AssignFunction(sdl_GetCursor);
		Gura_AssignFunction(sdl_GetDefaultCursor);
		Gura_AssignFunction(sdl_GetGlobalMouseState);
		Gura_AssignFunction(sdl_GetMouseFocus);
		Gura_AssignFunction(sdl_GetMouseState);
		Gura_AssignFunction(sdl_GetRelativeMouseMode);
		Gura_AssignFunction(sdl_GetRelativeMouseState);
		Gura_AssignFunction(sdl_SetCursor);
		Gura_AssignFunction(sdl_SetRelativeMouseMode);
		Gura_AssignFunction(sdl_ShowCursor);
		Gura_AssignFunction(sdl_WarpMouseGlobal);
		Gura_AssignFunction(sdl_WarpMouseInWindow);
		Gura_AssignFunction(sdl_JoystickClose);
		Gura_AssignFunction(sdl_JoystickEventState);
		Gura_AssignFunction(sdl_JoystickGetAttached);
		Gura_AssignFunction(sdl_JoystickGetAxis);
		Gura_AssignFunction(sdl_JoystickGetBall);
		Gura_AssignFunction(sdl_JoystickGetButton);
		Gura_AssignFunction(sdl_JoystickGetDeviceGUID);
		Gura_AssignFunction(sdl_JoystickGetGUID);
		Gura_AssignFunction(sdl_JoystickGetGUIDFromString);
		Gura_AssignFunction(sdl_JoystickGetGUIDString);
		Gura_AssignFunction(sdl_JoystickGetHat);
		Gura_AssignFunction(sdl_JoystickInstanceID);
		Gura_AssignFunction(sdl_JoystickName);
		Gura_AssignFunction(sdl_JoystickNameForIndex);
		Gura_AssignFunction(sdl_JoystickNumAxes);
		Gura_AssignFunction(sdl_JoystickNumBalls);
		Gura_AssignFunction(sdl_JoystickNumButtons);
		Gura_AssignFunction(sdl_JoystickNumHats);
		Gura_AssignFunction(sdl_JoystickOpen);
		Gura_AssignFunction(sdl_JoystickUpdate);
		Gura_AssignFunction(sdl_NumJoysticks);
		Gura_AssignFunction(sdl_GameControllerAddMapping);
		Gura_AssignFunction(sdl_GameControllerAddMappingsFromFile);
		Gura_AssignFunction(sdl_GameControllerAddMappingsFromRW);
		Gura_AssignFunction(sdl_GameControllerClose);
		Gura_AssignFunction(sdl_GameControllerEventState);
		Gura_AssignFunction(sdl_GameControllerGetAttached);
		Gura_AssignFunction(sdl_GameControllerGetAxis);
		Gura_AssignFunction(sdl_GameControllerGetAxisFromString);
		Gura_AssignFunction(sdl_GameControllerGetBindForAxis);
		Gura_AssignFunction(sdl_GameControllerGetBindForButton);
		Gura_AssignFunction(sdl_GameControllerGetButton);
		Gura_AssignFunction(sdl_GameControllerGetButtonFromString);
		Gura_AssignFunction(sdl_GameControllerGetJoystick);
		Gura_AssignFunction(sdl_GameControllerGetStringForAxis);
		Gura_AssignFunction(sdl_GameControllerGetStringForButton);
		Gura_AssignFunction(sdl_GameControllerMapping);
		Gura_AssignFunction(sdl_GameControllerMappingForGUID);
		Gura_AssignFunction(sdl_GameControllerName);
		Gura_AssignFunction(sdl_GameControllerNameForIndex);
		Gura_AssignFunction(sdl_GameControllerOpen);
		Gura_AssignFunction(sdl_GameControllerUpdate);
		Gura_AssignFunction(sdl_IsGameController);
		Gura_AssignFunction(sdl_HapticClose);
		Gura_AssignFunction(sdl_HapticDestroyEffect);
		Gura_AssignFunction(sdl_HapticEffectSupported);
		Gura_AssignFunction(sdl_HapticGetEffectStatus);
		Gura_AssignFunction(sdl_HapticIndex);
		Gura_AssignFunction(sdl_HapticName);
		Gura_AssignFunction(sdl_HapticNewEffect);
		Gura_AssignFunction(sdl_HapticNumAxes);
		Gura_AssignFunction(sdl_HapticNumEffects);
		Gura_AssignFunction(sdl_HapticNumEffectsPlaying);
		Gura_AssignFunction(sdl_HapticOpen);
		Gura_AssignFunction(sdl_HapticOpenFromJoystick);
		Gura_AssignFunction(sdl_HapticOpenFromMouse);
		Gura_AssignFunction(sdl_HapticOpened);
		Gura_AssignFunction(sdl_HapticPause);
		Gura_AssignFunction(sdl_HapticQuery);
		Gura_AssignFunction(sdl_HapticRumbleInit);
		Gura_AssignFunction(sdl_HapticRumblePlay);
		Gura_AssignFunction(sdl_HapticRumbleStop);
		Gura_AssignFunction(sdl_HapticRumbleSupported);
		Gura_AssignFunction(sdl_HapticRunEffect);
		Gura_AssignFunction(sdl_HapticSetAutocenter);
		Gura_AssignFunction(sdl_HapticSetGain);
		Gura_AssignFunction(sdl_HapticStopAll);
		Gura_AssignFunction(sdl_HapticStopEffect);
		Gura_AssignFunction(sdl_HapticUnpause);
		Gura_AssignFunction(sdl_HapticUpdateEffect);
		Gura_AssignFunction(sdl_JoystickIsHaptic);
		Gura_AssignFunction(sdl_MouseIsHaptic);
		Gura_AssignFunction(sdl_NumHaptics);
		Gura_AssignFunction(sdl_AudioInit);
		Gura_AssignFunction(sdl_AudioQuit);
		Gura_AssignFunction(sdl_BuildAudioCVT);
		Gura_AssignFunction(sdl_ClearQueuedAudio);
		Gura_AssignFunction(sdl_CloseAudio);
		Gura_AssignFunction(sdl_CloseAudioDevice);
		Gura_AssignFunction(sdl_ConvertAudio);
		Gura_AssignFunction(sdl_FreeWAV);
		Gura_AssignFunction(sdl_GetAudioDeviceName);
		Gura_AssignFunction(sdl_GetAudioDeviceStatus);
		Gura_AssignFunction(sdl_GetAudioDriver);
		Gura_AssignFunction(sdl_GetAudioStatus);
		Gura_AssignFunction(sdl_GetCurrentAudioDriver);
		Gura_AssignFunction(sdl_GetNumAudioDevices);
		Gura_AssignFunction(sdl_GetNumAudioDrivers);
		Gura_AssignFunction(sdl_GetQueuedAudioSize);
		Gura_AssignFunction(sdl_LoadWAV);
		Gura_AssignFunction(sdl_LoadWAV_RW);
		Gura_AssignFunction(sdl_LockAudio);
		Gura_AssignFunction(sdl_LockAudioDevice);
		Gura_AssignFunction(sdl_MixAudio);
		Gura_AssignFunction(sdl_MixAudioFormat);
		Gura_AssignFunction(sdl_OpenAudio);
		Gura_AssignFunction(sdl_OpenAudioDevice);
		Gura_AssignFunction(sdl_PauseAudio);
		Gura_AssignFunction(sdl_PauseAudioDevice);
		Gura_AssignFunction(sdl_QueueAudio);
		Gura_AssignFunction(sdl_UnlockAudio);
		Gura_AssignFunction(sdl_UnlockAudioDevice);
		Gura_AssignFunction(sdl_AUDIO_BITSIZE);
		Gura_AssignFunction(sdl_AUDIO_ISFLOAT);
		Gura_AssignFunction(sdl_AUDIO_ISBIGENDIAN);
		Gura_AssignFunction(sdl_AUDIO_ISSIGNED);
		Gura_AssignFunction(sdl_AUDIO_ISINT);
		Gura_AssignFunction(sdl_AUDIO_ISLITTLEENDIAN);
		Gura_AssignFunction(sdl_AUDIO_ISUNSIGNED);
		Gura_AssignFunction(sdl_CreateThread);
		Gura_AssignFunction(sdl_DetachThread);
		Gura_AssignFunction(sdl_GetThreadID);
		Gura_AssignFunction(sdl_GetThreadName);
		Gura_AssignFunction(sdl_GetThreadPriority);
		Gura_AssignFunction(sdl_TLSCreate);
		Gura_AssignFunction(sdl_TLSGet);
		Gura_AssignFunction(sdl_TLSSet);
		Gura_AssignFunction(sdl_ThreadID);
		Gura_AssignFunction(sdl_WaitThread);
		Gura_AssignFunction(sdl_CondBroadcast);
		Gura_AssignFunction(sdl_CondSignal);
		Gura_AssignFunction(sdl_CondWait);
		Gura_AssignFunction(sdl_CondWaitTimeout);
		Gura_AssignFunction(sdl_CreateCond);
		Gura_AssignFunction(sdl_CreateMutex);
		Gura_AssignFunction(sdl_CreateSemaphore);
		Gura_AssignFunction(sdl_DestroyCond);
		Gura_AssignFunction(sdl_DestroyMutex);
		Gura_AssignFunction(sdl_DestroySemaphore);
		Gura_AssignFunction(sdl_LockMutex);
		Gura_AssignFunction(sdl_SemPost);
		Gura_AssignFunction(sdl_SemTryWait);
		Gura_AssignFunction(sdl_SemValue);
		Gura_AssignFunction(sdl_SemWait);
		Gura_AssignFunction(sdl_SemWaitTimeout);
		Gura_AssignFunction(sdl_TryLockMutex);
		Gura_AssignFunction(sdl_UnlockMutex);
		Gura_AssignFunction(sdl_AtomicAdd);
		Gura_AssignFunction(sdl_AtomicCAS);
		Gura_AssignFunction(sdl_AtomicCASPtr);
		Gura_AssignFunction(sdl_AtomicDecRef);
		Gura_AssignFunction(sdl_AtomicGet);
		Gura_AssignFunction(sdl_AtomicGetPtr);
		Gura_AssignFunction(sdl_AtomicIncRef);
		Gura_AssignFunction(sdl_AtomicLock);
		Gura_AssignFunction(sdl_AtomicSet);
		Gura_AssignFunction(sdl_AtomicSetPtr);
		Gura_AssignFunction(sdl_AtomicTryLock);
		Gura_AssignFunction(sdl_AtomicUnlock);
		Gura_AssignFunction(sdl_CompilerBarrier);
		Gura_AssignFunction(sdl_AddTimer);
		Gura_AssignFunction(sdl_Delay);
		Gura_AssignFunction(sdl_GetPerformanceCounter);
		Gura_AssignFunction(sdl_GetPerformanceFrequency);
		Gura_AssignFunction(sdl_GetTicks);
		Gura_AssignFunction(sdl_RemoveTimer);
		Gura_AssignFunction(sdl_TICKS_PASSED);
		Gura_AssignFunction(sdl_GetBasePath);
		Gura_AssignFunction(sdl_GetPrefPath);
		Gura_AssignFunction(sdl_AllocRW);
		Gura_AssignFunction(sdl_FreeRW);
		Gura_AssignFunction(sdl_RWFromConstMem);
		Gura_AssignFunction(sdl_RWFromFP);
		Gura_AssignFunction(sdl_RWFromFile);
		Gura_AssignFunction(sdl_RWFromMem);
		Gura_AssignFunction(sdl_RWclose);
		Gura_AssignFunction(sdl_RWread);
		Gura_AssignFunction(sdl_RWseek);
		Gura_AssignFunction(sdl_RWtell);
		Gura_AssignFunction(sdl_RWwrite);
		Gura_AssignFunction(sdl_ReadBE16);
		Gura_AssignFunction(sdl_ReadBE32);
		Gura_AssignFunction(sdl_ReadBE64);
		Gura_AssignFunction(sdl_ReadLE16);
		Gura_AssignFunction(sdl_ReadLE32);
		Gura_AssignFunction(sdl_ReadLE64);
		Gura_AssignFunction(sdl_WriteBE16);
		Gura_AssignFunction(sdl_WriteBE32);
		Gura_AssignFunction(sdl_WriteBE64);
		Gura_AssignFunction(sdl_WriteLE16);
		Gura_AssignFunction(sdl_WriteLE32);
		Gura_AssignFunction(sdl_WriteLE64);
		Gura_AssignFunction(sdl_GetPlatform);
		Gura_AssignFunction(sdl_GetCPUCacheLineSize);
		Gura_AssignFunction(sdl_GetCPUCount);
		Gura_AssignFunction(sdl_GetSystemRAM);
		Gura_AssignFunction(sdl_Has3DNow);
		Gura_AssignFunction(sdl_HasAVX);
		Gura_AssignFunction(sdl_HasAVX2);
		Gura_AssignFunction(sdl_HasAltiVec);
		Gura_AssignFunction(sdl_HasMMX);
		Gura_AssignFunction(sdl_HasRDTSC);
		Gura_AssignFunction(sdl_HasSSE);
		Gura_AssignFunction(sdl_HasSSE2);
		Gura_AssignFunction(sdl_HasSSE3);
		Gura_AssignFunction(sdl_HasSSE41);
		Gura_AssignFunction(sdl_HasSSE42);
		Gura_AssignFunction(sdl_Swap16);
		Gura_AssignFunction(sdl_Swap32);
		Gura_AssignFunction(sdl_Swap64);
		Gura_AssignFunction(sdl_SwapBE16);
		Gura_AssignFunction(sdl_SwapBE32);
		Gura_AssignFunction(sdl_SwapBE64);
		Gura_AssignFunction(sdl_SwapFloat);
		Gura_AssignFunction(sdl_SwapFloatBE);
		Gura_AssignFunction(sdl_SwapFloatLE);
		Gura_AssignFunction(sdl_SwapLE16);
		Gura_AssignFunction(sdl_SwapLE32);
		Gura_AssignFunction(sdl_SwapLE64);
		Gura_AssignFunction(sdl_MostSignificantBitIndex32);
		Gura_AssignFunction(sdl_GetPowerInfo);
		Gura_AssignFunction(sdl_AndroidGetActivity);
		Gura_AssignFunction(sdl_AndroidGetExternalStoragePath);
		Gura_AssignFunction(sdl_AndroidGetExternalStorageState);
		Gura_AssignFunction(sdl_AndroidGetInternalStoragePath);
		Gura_AssignFunction(sdl_AndroidGetJNIEnv);
		Gura_AssignFunction(sdl_acos);
	Gura_AssignFunction(test);
}

Gura_EndModuleScope(sdl2)
