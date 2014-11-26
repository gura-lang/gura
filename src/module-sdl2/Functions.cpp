#include "stdafx.h"

#undef CreateWindow
#undef CreateMutex
#undef CreateSemaphore

Gura_BeginModuleScope(sdl2)

// sdl2.Init
Gura_DeclareFunctionAlias(__Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(ja), Help::FMT_markdown,
		"この関数で SDL ライブラリを初期化します。\n"
		"他の SDL 関数を使う前に呼び出す必要があります。\n"
		"\n"
		"イベントハンドリング, ファイル I/O　およびスレッドのサブシステムはデフォルトで初期化されます。\n"
		"他のサブシステムをアプリケーションで使用する場合は個別に初期化する必要があります。\n"
		"\n"
		"`flags` は以下の値を OR したものです。\n"
		"\n"
		"- `sdl2.INIT_TIMER` .. タイマーサブシステム\n"
		"- `sdl2.INIT_AUDIO` .. オーディオサブシステム\n"
		"- `sdl2.INIT_VIDEO` .. ビデオサブシステム\n"
		"- `sdl2.INIT_JOYSTICK` .. ジョイスティックサブシステム\n"
		"- `sdl2.INIT_HAPTIC` .. haptic (force feedback) サブシステム\n"
		"- `sdl2.INIT_GAMECONTROLLER` .. コントローラサブシステム\n"
		"- `sdl2.INIT_EVENTS` .. イベントサブシステム\n"
		"- `sdl2.INIT_EVERYTHING` .. all of the above subsystems\n"
		"- `sdl2.INIT_NOPARACHUTE` .. compatibility; this flag is ignored\n"
		"\n");
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to initialize the SDL library.\n"
		"This must be called before using any other SDL function.\n"
		"\n"
		"The Event Handling, File I/O, and Threading subsystems are initialized by default.\n"
		"You must specifically initialize other subsystems if you use them in your application.\n"
		"\n"
		"`flags` may be any of the following OR\'d together:\n"
		"\n"
		"- `sdl2.INIT_TIMER` .. timer subsystem\n"
		"- `sdl2.INIT_AUDIO` .. audio subsystem\n"
		"- `sdl2.INIT_VIDEO` .. video subsystem\n"
		"- `sdl2.INIT_JOYSTICK` .. joystick subsystem\n"
		"- `sdl2.INIT_HAPTIC` .. haptic (force feedback) subsystem\n"
		"- `sdl2.INIT_GAMECONTROLLER` .. controller subsystem\n"
		"- `sdl2.INIT_EVENTS` .. events subsystem\n"
		"- `sdl2.INIT_EVERYTHING` .. all of the above subsystems\n"
		"- `sdl2.INIT_NOPARACHUTE` .. compatibility; this flag is ignored\n"
		"\n"
		"If you want to initialize subsystems separately you would call `SDL_Init(0)` followed\n"
		"by `SDL_InitSubSystem()` with the desired subsystem flag.\n");
}

Gura_ImplementFunction(__Init)
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
Gura_DeclareFunctionAlias(__InitSubSystem, "InitSubSystem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to initialize specific SDL subsystems.\n"
		"\n"
		"After SDL has been initialized with `SDL_Init()`\n"
		"you may initialize uninitialized subsystems with `SDL_InitSubSystem()`.\n"
		"\n"
		"These are the flags which may be passed to `SDL_InitSubSystem()`\n"
		"and may be OR\'d together to initialize multiple subsystems simultaneously.\n"
		"\n"
		"- `sdl2.INIT_TIMER` .. timer subsystem\n"
		"- `sdl2.INIT_AUDIO` .. audio subsystem\n"
		"- `sdl2.INIT_VIDEO` .. video subsystem\n"
		"- `sdl2.INIT_JOYSTICK` .. joystick subsystem\n"
		"- `sdl2.INIT_HAPTIC` .. haptic (force feedback) subsystem\n"
		"- `sdl2.INIT_GAMECONTROLLER` .. controller subsystem\n"
		"- `sdl2.INIT_EVENTS` .. events subsystem\n"
		"- `sdl2.INIT_EVERYTHING` .. all of the above subsystems\n"
		"- `sdl2.INIT_NOPARACHUTE` .. compatibility; this flag is ignored\n"
		"\n"
		"If you want to initialize subsystems separately you would call `SDL_Init(0)` followed\n"
		"by `SDL_InitSubSystem()` with the desired subsystem flag.\n");
}

Gura_ImplementFunction(__InitSubSystem)
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
Gura_DeclareFunctionAlias(__Quit, "Quit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to clean up all initialized subsystems.\n"
		"You should call it upon all exit conditions.\n"
		"\n"
		"You should call this function even if you have already shutdown\n"
		"each initialized subsystem with `SDL_QuitSubSystem()`.\n"
		"\n"
		"If you start a subsystem using a call to that subsystem\'s init function\n"
		"(for example `SDL_VideoInit()`) instead of `SDL_Init()` or `SDL_InitSubSystem()`,\n"
		"then you must use that subsystem\'s quit function (`SDL_VideoQuit()`)\n"
		"to shut it down before calling `SDL_Quit()`.\n"
		"\n"
		"You can use this function with `atexit()` to ensure that it is run\n"
		"when your application is shutdown,\n"
		"but it is not wise to do this from a library or other dynamically loaded code.\n");
}

Gura_ImplementFunction(__Quit)
{
	SDL_Quit();
	return Value::Null;
}

// sdl2.QuitSubSystem
Gura_DeclareFunctionAlias(__QuitSubSystem, "QuitSubSystem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to shut down specific SDL subsystems.\n"
		"\n"
		"These are the flags which may be passed to `SDL_QuitSubSystem()`\n"
		"and may be OR\'d together to quit multiple subsystems simultaneously.\n"
		"\n"
		"- `sdl2.INIT_TIMER` .. timer subsystem\n"
		"- `sdl2.INIT_AUDIO` .. audio subsystem\n"
		"- `sdl2.INIT_VIDEO` .. video subsystem\n"
		"- `sdl2.INIT_JOYSTICK` .. joystick subsystem\n"
		"- `sdl2.INIT_HAPTIC` .. haptic (force feedback) subsystem\n"
		"- `sdl2.INIT_GAMECONTROLLER` .. controller subsystem\n"
		"- `sdl2.INIT_EVENTS` .. events subsystem\n"
		"- `sdl2.INIT_EVERYTHING` .. all of the above subsystems\n"
		"- `sdl2.INIT_NOPARACHUTE` .. compatibility; this flag is ignored\n"
		"\n"
		"If you want to initialize subsystems separately you would call `SDL_Init(0)` followed\n"
		"by `SDL_InitSubSystem()` with the desired subsystem flag.\n");
}

Gura_ImplementFunction(__QuitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	SDL_QuitSubSystem(flags);
	return Value::Null;
}

// sdl2.SetMainReady
Gura_DeclareFunctionAlias(__SetMainReady, "SetMainReady")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to circumvent failure of `SDL_Init()`\n"
		"when not using `SDL_main()` as an entry point.\n"
		"\n"
		"This function is defined in SDL_main.h, along with the preprocessor\n"
		"rule to redefine `main()` as `SDL_main()`.\n"
		"Thus to ensure that your `main()` function will not be changed\n"
		"it is necessary to define `SDL_MAIN_HANDLED` before including SDL.h.\n");
}

Gura_ImplementFunction(__SetMainReady)
{
	SDL_SetMainReady();
	return Value::Null;
}

// sdl2.WasInit
Gura_DeclareFunctionAlias(__WasInit, "WasInit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to return a mask of the specified subsystems\n"
		"which have previously been initialized.\n"
		"\n"
		"These are the flags which may be passed to `SDL_WasInit()`\n"
		"and may be OR\'d together to query multiple subsystems simultaneously.\n"
		"\n"
		"- `sdl2.INIT_TIMER` .. timer subsystem\n"
		"- `sdl2.INIT_AUDIO` .. audio subsystem\n"
		"- `sdl2.INIT_VIDEO` .. video subsystem\n"
		"- `sdl2.INIT_JOYSTICK` .. joystick subsystem\n"
		"- `sdl2.INIT_HAPTIC` .. haptic (force feedback) subsystem\n"
		"- `sdl2.INIT_GAMECONTROLLER` .. controller subsystem\n"
		"- `sdl2.INIT_EVENTS` .. events subsystem\n"
		"- `sdl2.INIT_EVERYTHING` .. all of the above subsystems\n"
		"- `sdl2.INIT_NOPARACHUTE` .. compatibility; this flag is ignored\n"
		"\n"
		"If you want to initialize subsystems separately you would call `SDL_Init(0)` followed\n"
		"by `SDL_InitSubSystem()` with the desired subsystem flag.\n");
}

Gura_ImplementFunction(__WasInit)
{
	Uint32 flags = args.GetULong(0);
	Uint32 _rtn = SDL_WasInit(flags);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.AddHintCallback
Gura_DeclareFunctionAlias(__AddHintCallback, "AddHintCallback")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AddHintCallback)
{
#if 0
	SDL_AddHintCallback();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AddHintCallback");
	return Value::Null;
}

// sdl2.ClearHints
Gura_DeclareFunctionAlias(__ClearHints, "ClearHints")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ClearHints)
{
#if 0
	SDL_ClearHints();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ClearHints");
	return Value::Null;
}

// sdl2.DelhintCallback
Gura_DeclareFunctionAlias(__DelhintCallback, "DelhintCallback")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DelhintCallback)
{
#if 0
	SDL_DelhintCallback();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DelhintCallback");
	return Value::Null;
}

// sdl2.GetHint
Gura_DeclareFunctionAlias(__GetHint, "GetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetHint)
{
#if 0
	SDL_GetHint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetHint");
	return Value::Null;
}

// sdl2.SetHint
Gura_DeclareFunctionAlias(__SetHint, "SetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetHint)
{
#if 0
	SDL_SetHint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetHint");
	return Value::Null;
}

// sdl2.SetHintWithPriority
Gura_DeclareFunctionAlias(__SetHintWithPriority, "SetHintWithPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetHintWithPriority)
{
#if 0
	SDL_SetHintWithPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetHintWithPriority");
	return Value::Null;
}

// sdl2.ClearError
Gura_DeclareFunctionAlias(__ClearError, "ClearError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to clear any previous error message.\n");
}

Gura_ImplementFunction(__ClearError)
{
	SDL_ClearError();
	return Value::Null;
}

// sdl2.GetError
Gura_DeclareFunctionAlias(__GetError, "GetError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Use this function to retrieve a message about the last error that occurred.\n"
		"\n"
		"Returns a message with information about the specific error that occurred, or an empty string if there hasn\'t been an error since the last call to `SDL_ClearError()`. Without calling `SDL_ClearError()`, the message is only applicable when an SDL function has signaled an error. You must check the return values of SDL function calls to determine when to appropriately call `SDL_GetError()`.\n"
		"\n"
		"This string is statically allocated and must not be freed by the application.\n"
		"\n"
		"It is possible for multiple errors to occur before calling `SDL_GetError()`. Only the last error is returned.\n");
}

Gura_ImplementFunction(__GetError)
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
Gura_DeclareFunctionAlias(__SetError, "SetError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetError)
{
#if 0
	SDL_SetError();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetError");
	return Value::Null;
}

// sdl2.Log
Gura_DeclareFunctionAlias(__Log, "Log")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__Log)
{
#if 0
	SDL_Log();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Log");
	return Value::Null;
}

// sdl2.LogCritical
Gura_DeclareFunctionAlias(__LogCritical, "LogCritical")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogCritical)
{
#if 0
	SDL_LogCritical();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogCritical");
	return Value::Null;
}

// sdl2.LogDebug
Gura_DeclareFunctionAlias(__LogDebug, "LogDebug")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogDebug)
{
#if 0
	SDL_LogDebug();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogDebug");
	return Value::Null;
}

// sdl2.LogError
Gura_DeclareFunctionAlias(__LogError, "LogError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogError)
{
#if 0
	SDL_LogError();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogError");
	return Value::Null;
}

// sdl2.LogGetOutputFunction
Gura_DeclareFunctionAlias(__LogGetOutputFunction, "LogGetOutputFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogGetOutputFunction)
{
#if 0
	SDL_LogGetOutputFunction();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogGetOutputFunction");
	return Value::Null;
}

// sdl2.LogGetPriority
Gura_DeclareFunctionAlias(__LogGetPriority, "LogGetPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogGetPriority)
{
#if 0
	SDL_LogGetPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogGetPriority");
	return Value::Null;
}

// sdl2.LogInfo
Gura_DeclareFunctionAlias(__LogInfo, "LogInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogInfo)
{
#if 0
	SDL_LogInfo();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogInfo");
	return Value::Null;
}

// sdl2.LogMessage
Gura_DeclareFunctionAlias(__LogMessage, "LogMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogMessage)
{
#if 0
	SDL_LogMessage();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogMessage");
	return Value::Null;
}

// sdl2.LogMessageV
Gura_DeclareFunctionAlias(__LogMessageV, "LogMessageV")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogMessageV)
{
#if 0
	SDL_LogMessageV();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogMessageV");
	return Value::Null;
}

// sdl2.LogResetPriorities
Gura_DeclareFunctionAlias(__LogResetPriorities, "LogResetPriorities")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogResetPriorities)
{
#if 0
	SDL_LogResetPriorities();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogResetPriorities");
	return Value::Null;
}

// sdl2.LogSetAllPriority
Gura_DeclareFunctionAlias(__LogSetAllPriority, "LogSetAllPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogSetAllPriority)
{
#if 0
	SDL_LogSetAllPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogSetAllPriority");
	return Value::Null;
}

// sdl2.LogSetOutputFunction
Gura_DeclareFunctionAlias(__LogSetOutputFunction, "LogSetOutputFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogSetOutputFunction)
{
#if 0
	SDL_LogSetOutputFunction();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogSetOutputFunction");
	return Value::Null;
}

// sdl2.LogSetPriority
Gura_DeclareFunctionAlias(__LogSetPriority, "LogSetPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogSetPriority)
{
#if 0
	SDL_LogSetPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogSetPriority");
	return Value::Null;
}

// sdl2.LogVerbose
Gura_DeclareFunctionAlias(__LogVerbose, "LogVerbose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogVerbose)
{
#if 0
	SDL_LogVerbose();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogVerbose");
	return Value::Null;
}

// sdl2.LogWarn
Gura_DeclareFunctionAlias(__LogWarn, "LogWarn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LogWarn)
{
#if 0
	SDL_LogWarn();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LogWarn");
	return Value::Null;
}

// sdl2.GetAssertionHandler
Gura_DeclareFunctionAlias(__GetAssertionHandler, "GetAssertionHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetAssertionHandler)
{
#if 0
	SDL_GetAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetAssertionHandler");
	return Value::Null;
}

// sdl2.GetAssertionReport
Gura_DeclareFunctionAlias(__GetAssertionReport, "GetAssertionReport")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetAssertionReport)
{
#if 0
	SDL_GetAssertionReport();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetAssertionReport");
	return Value::Null;
}

// sdl2.GetDefaultAssertionHandler
Gura_DeclareFunctionAlias(__GetDefaultAssertionHandler, "GetDefaultAssertionHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetDefaultAssertionHandler)
{
#if 0
	SDL_GetDefaultAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetDefaultAssertionHandler");
	return Value::Null;
}

// sdl2.ResetAssertionReport
Gura_DeclareFunctionAlias(__ResetAssertionReport, "ResetAssertionReport")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ResetAssertionReport)
{
#if 0
	SDL_ResetAssertionReport();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ResetAssertionReport");
	return Value::Null;
}

// sdl2.SetAssertionHandler
Gura_DeclareFunctionAlias(__SetAssertionHandler, "SetAssertionHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetAssertionHandler)
{
#if 0
	SDL_SetAssertionHandler();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetAssertionHandler");
	return Value::Null;
}

// sdl2.TriggerBreakpoint
Gura_DeclareFunctionAlias(__TriggerBreakpoint, "TriggerBreakpoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__TriggerBreakpoint)
{
#if 0
	SDL_TriggerBreakpoint();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TriggerBreakpoint");
	return Value::Null;
}

// sdl2.assert
Gura_DeclareFunctionAlias(__assert, "assert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__assert)
{
#if 0
	SDL_assert();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "assert");
	return Value::Null;
}

// sdl2.assert_paranoid
Gura_DeclareFunctionAlias(__assert_paranoid, "assert_paranoid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__assert_paranoid)
{
#if 0
	SDL_assert_paranoid();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "assert_paranoid");
	return Value::Null;
}

// sdl2.assert_release
Gura_DeclareFunctionAlias(__assert_release, "assert_release")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__assert_release)
{
#if 0
	SDL_assert_release();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "assert_release");
	return Value::Null;
}

// sdl2.GetRevision
Gura_DeclareFunctionAlias(__GetRevision, "GetRevision")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRevision)
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
Gura_DeclareFunctionAlias(__GetRevisionNumber, "GetRevisionNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRevisionNumber)
{
	int _rtn = SDL_GetRevisionNumber();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetVersion
Gura_DeclareFunctionAlias(__GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetVersion)
{
	SDL_version ver;
	SDL_GetVersion(&ver);
	return ReturnValue(env, sig, args, Value::CreateList(env,
					Value(ver.major), Value(ver.minor), Value(ver.patch)));
}

// sdl2.VERSION
Gura_DeclareFunctionAlias(__VERSION, "VERSION")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__VERSION)
{
	SDL_version ver;
	SDL_VERSION(&ver);
	return ReturnValue(env, sig, args, Value::CreateList(env,
					Value(ver.major), Value(ver.minor), Value(ver.patch)));
}

// sdl2.VERSION_ATLEAST
Gura_DeclareFunctionAlias(__VERSION_ATLEAST, "VERSION_ATLEAST")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "X", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Z", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__VERSION_ATLEAST)
{
	int X = args.GetInt(0);
	int Y = args.GetInt(1);
	int Z = args.GetInt(2);
	bool _rtn = SDL_VERSION_ATLEAST(X, Y, Z);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.CreateWindow
Gura_DeclareFunctionAlias(__CreateWindow, "CreateWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateWindow)
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
Gura_DeclareFunctionAlias(__CreateWindowAndRenderer, "CreateWindowAndRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "window_flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateWindowAndRenderer)
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
Gura_DeclareFunctionAlias(__CreateWindowFrom, "CreateWindowFrom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateWindowFrom)
{
#if 0
	SDL_CreateWindowFrom();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateWindowFrom");
	return Value::Null;
}

// sdl2.DestroyWindow
Gura_DeclareFunctionAlias(__DestroyWindow, "DestroyWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DestroyWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_DestroyWindow(window);
	return Value::Null;
}

// sdl2.DisableScreenSaver
Gura_DeclareFunctionAlias(__DisableScreenSaver, "DisableScreenSaver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DisableScreenSaver)
{
	SDL_DisableScreenSaver();
	return Value::Null;
}

// sdl2.EnableScreenSaver
Gura_DeclareFunctionAlias(__EnableScreenSaver, "EnableScreenSaver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__EnableScreenSaver)
{
	SDL_EnableScreenSaver();
	return Value::Null;
}

// sdl2.GL_CreateContext
Gura_DeclareFunctionAlias(__GL_CreateContext, "GL_CreateContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_CreateContext)
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
Gura_DeclareFunctionAlias(__GL_DeleteContext, "GL_DeleteContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "context", VTYPE_GLContext, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_DeleteContext)
{
	SDL_GLContext context = Object_GLContext::GetObject(args, 0)->GetEntity();
	SDL_GL_DeleteContext(context);
	return Value::Null;
}

// sdl2.GL_ExtensionSupported
Gura_DeclareFunctionAlias(__GL_ExtensionSupported, "GL_ExtensionSupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_ExtensionSupported)
{
	const char *extension = args.GetString(0);
	SDL_bool _rtn = SDL_GL_ExtensionSupported(extension);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.GL_GetAttribute
Gura_DeclareFunctionAlias(__GL_GetAttribute, "GL_GetAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "attr", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_GetAttribute)
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
Gura_DeclareFunctionAlias(__GL_GetCurrentContext, "GL_GetCurrentContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_GetCurrentContext)
{
	SDL_GLContext _rtn = SDL_GL_GetCurrentContext();
	if (_rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_GLContext(_rtn)));
}

// sdl2.GL_GetCurrentWindow
Gura_DeclareFunctionAlias(__GL_GetCurrentWindow, "GL_GetCurrentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_GetCurrentWindow)
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
Gura_DeclareFunctionAlias(__GL_GetDrawableSize, "GL_GetDrawableSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_GetDrawableSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GL_GetDrawableSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GL_GetProcAddress
Gura_DeclareFunctionAlias(__GL_GetProcAddress, "GL_GetProcAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_GetProcAddress)
{
#if 0
	SDL_GL_GetProcAddress();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GL_GetProcAddress");
	return Value::Null;
}

// sdl2.GL_GetSwapInterval
Gura_DeclareFunctionAlias(__GL_GetSwapInterval, "GL_GetSwapInterval")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_GetSwapInterval)
{
	int _rtn = SDL_GL_GetSwapInterval();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.GL_LoadLibrary
Gura_DeclareFunctionAlias(__GL_LoadLibrary, "GL_LoadLibrary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_LoadLibrary)
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
Gura_DeclareFunctionAlias(__GL_MakeCurrent, "GL_MakeCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "context", VTYPE_GLContext, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_MakeCurrent)
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
Gura_DeclareFunctionAlias(__GL_ResetAttributes, "GL_ResetAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_ResetAttributes)
{
	SDL_GL_ResetAttributes();
	return Value::Null;
}

// sdl2.GL_SetAttribute
Gura_DeclareFunctionAlias(__GL_SetAttribute, "GL_SetAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "attr", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_SetAttribute)
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
Gura_DeclareFunctionAlias(__GL_SetSwapInterval, "GL_SetSwapInterval")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "interval", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_SetSwapInterval)
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
Gura_DeclareFunctionAlias(__GL_SwapWindow, "GL_SwapWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_SwapWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_GL_SwapWindow(window);
	return Value::Null;
}

// sdl2.GL_UnloadLibrary
Gura_DeclareFunctionAlias(__GL_UnloadLibrary, "GL_UnloadLibrary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_UnloadLibrary)
{
	SDL_GL_UnloadLibrary();
	return Value::Null;
}

// sdl2.GetClosestDisplayMode
Gura_DeclareFunctionAlias(__GetClosestDisplayMode, "GetClosestDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetClosestDisplayMode)
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

// sdl2.GetCurrentDisplayMode
Gura_DeclareFunctionAlias(__GetCurrentDisplayMode, "GetCurrentDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetCurrentDisplayMode)
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
Gura_DeclareFunctionAlias(__GetCurrentVideoDriver, "GetCurrentVideoDriver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetCurrentVideoDriver)
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
Gura_DeclareFunctionAlias(__GetDesktopDisplayMode, "GetDesktopDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetDesktopDisplayMode)
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
Gura_DeclareFunctionAlias(__GetDisplayBounds, "GetDisplayBounds")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetDisplayBounds)
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
Gura_DeclareFunctionAlias(__GetDisplayMode, "GetDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "modeIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetDisplayMode)
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
Gura_DeclareFunctionAlias(__GetDisplayName, "GetDisplayName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dipslayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetDisplayName)
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
Gura_DeclareFunctionAlias(__GetNumDisplayModes, "GetNumDisplayModes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "displayIndex", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumDisplayModes)
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
Gura_DeclareFunctionAlias(__GetNumVideoDisplays, "GetNumVideoDisplays")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumVideoDisplays)
{
	int _rtn = SDL_GetNumVideoDisplays();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetNumVideoDrivers
Gura_DeclareFunctionAlias(__GetNumVideoDrivers, "GetNumVideoDrivers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumVideoDrivers)
{
	int _rtn = SDL_GetNumVideoDrivers();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetVideoDriver
Gura_DeclareFunctionAlias(__GetVideoDriver, "GetVideoDriver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetVideoDriver)
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
Gura_DeclareFunctionAlias(__GetWindowBrightness, "GetWindowBrightness")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowBrightness)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	float _rtn = SDL_GetWindowBrightness(window);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetWindowData
Gura_DeclareFunctionAlias(__GetWindowData, "GetWindowData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowData)
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
Gura_DeclareFunctionAlias(__GetWindowDisplayIndex, "GetWindowDisplayIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowDisplayIndex)
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
Gura_DeclareFunctionAlias(__GetWindowDisplayMode, "GetWindowDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowDisplayMode)
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
Gura_DeclareFunctionAlias(__GetWindowFlags, "GetWindowFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowFlags)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowFlags(window);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetWindowFromID
Gura_DeclareFunctionAlias(__GetWindowFromID, "GetWindowFromID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowFromID)
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
Gura_DeclareFunctionAlias(__GetWindowGammaRamp, "GetWindowGammaRamp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowGammaRamp)
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
Gura_DeclareFunctionAlias(__GetWindowGrab, "GetWindowGrab")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowGrab)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_GetWindowGrab(window);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.GetWindowID
Gura_DeclareFunctionAlias(__GetWindowID, "GetWindowID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowID)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	Uint32 _rtn = SDL_GetWindowID(window);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetWindowMaximumSize
Gura_DeclareFunctionAlias(__GetWindowMaximumSize, "GetWindowMaximumSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowMaximumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowMaximumSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GetWindowMinimumSize
Gura_DeclareFunctionAlias(__GetWindowMinimumSize, "GetWindowMinimumSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowMinimumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowMinimumSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GetWindowPixelFormat
Gura_DeclareFunctionAlias(__GetWindowPixelFormat, "GetWindowPixelFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowPixelFormat)
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
Gura_DeclareFunctionAlias(__GetWindowPosition, "GetWindowPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowPosition)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = 0;
	int y = 0;
	SDL_GetWindowPosition(window, &x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(x), Value(y)));
}

// sdl2.GetWindowSize
Gura_DeclareFunctionAlias(__GetWindowSize, "GetWindowSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(window, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.GetWindowSurface
Gura_DeclareFunctionAlias(__GetWindowSurface, "GetWindowSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowSurface)
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
Gura_DeclareFunctionAlias(__GetWindowTitle, "GetWindowTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowTitle)
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
Gura_DeclareFunctionAlias(__GetWindowWMInfo, "GetWindowWMInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetWindowWMInfo)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_GetWindowWMInfo(window);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetWindowWMInfo");
	return Value::Null;
}

// sdl2.HideWindow
Gura_DeclareFunctionAlias(__HideWindow, "HideWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HideWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_HideWindow(window);
	return Value::Null;
}

// sdl2.IsScreenSaverEnabled
Gura_DeclareFunctionAlias(__IsScreenSaverEnabled, "IsScreenSaverEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__IsScreenSaverEnabled)
{
	SDL_bool _rtn = SDL_IsScreenSaverEnabled();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.MaximizeWindow
Gura_DeclareFunctionAlias(__MaximizeWindow, "MaximizeWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MaximizeWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_MaximizeWindow(window);
	return Value::Null;
}

// sdl2.MinimizeWindow
Gura_DeclareFunctionAlias(__MinimizeWindow, "MinimizeWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MinimizeWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_MinimizeWindow(window);
	return Value::Null;
}

// sdl2.RaiseWindow
Gura_DeclareFunctionAlias(__RaiseWindow, "RaiseWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RaiseWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_RaiseWindow(window);
	return Value::Null;
}

// sdl2.RestoreWindow
Gura_DeclareFunctionAlias(__RestoreWindow, "RestoreWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RestoreWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_RestoreWindow(window);
	return Value::Null;
}

// sdl2.SetWindowBordered
Gura_DeclareFunctionAlias(__SetWindowBordered, "SetWindowBordered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "bordered", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowBordered)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool bordered = (args.GetBoolean(1)? SDL_TRUE : SDL_FALSE);
	SDL_SetWindowBordered(window, bordered);
	return Value::Null;
}

// sdl2.SetWindowBrightness
Gura_DeclareFunctionAlias(__SetWindowBrightness, "SetWindowBrightness")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "brightness", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowBrightness)
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
Gura_DeclareFunctionAlias(__SetWindowData, "SetWindowData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowData)
{
#if 0
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *name = args.GetString(1);
	SDL_SetWindowData(window, name);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetWindowData");
	return Value::Null;
}

// sdl2.SetWindowDisplayMode
Gura_DeclareFunctionAlias(__SetWindowDisplayMode, "SetWindowDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mode", VTYPE_DisplayMode, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowDisplayMode)
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
Gura_DeclareFunctionAlias(__SetWindowFullscreen, "SetWindowFullscreen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowFullscreen)
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
Gura_DeclareFunctionAlias(__SetWindowGammaRamp, "SetWindowGammaRamp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "red", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "green", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareArg(env, "blue", VTYPE_number, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowGammaRamp)
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

// sdl2.SetWindowGrab
Gura_DeclareFunctionAlias(__SetWindowGrab, "SetWindowGrab")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "grabbed", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowGrab)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool grabbed = (args.GetBoolean(1)? SDL_TRUE : SDL_FALSE);
	SDL_SetWindowGrab(window, grabbed);
	return Value::Null;
}

// sdl2.SetWindowHitTest
Gura_DeclareFunctionAlias(__SetWindowHitTest, "SetWindowHitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowHitTest)
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
	SetError_NotImpFunction(sig, "SetWindowHitTest");
	return Value::Null;
}

// sdl2.SetWindowIcon
Gura_DeclareFunctionAlias(__SetWindowIcon, "SetWindowIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "icon", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowIcon)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_Surface *icon = Object_Surface::GetObject(args, 1)->GetEntity();
	SDL_SetWindowIcon(window, icon);
	return Value::Null;
}

// sdl2.SetWindowMaximumSize
Gura_DeclareFunctionAlias(__SetWindowMaximumSize, "SetWindowMaximumSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "max_w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "max_h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowMaximumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int max_w = args.GetInt(1);
	int max_h = args.GetInt(2);
	SDL_SetWindowMaximumSize(window, max_w, max_h);
	return Value::Null;
}

// sdl2.SetWindowMinimumSize
Gura_DeclareFunctionAlias(__SetWindowMinimumSize, "SetWindowMinimumSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "min_w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "min_h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowMinimumSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int min_w = args.GetInt(1);
	int min_h = args.GetInt(2);
	SDL_SetWindowMinimumSize(window, min_w, min_h);
	return Value::Null;
}

// sdl2.SetWindowPosition
Gura_DeclareFunctionAlias(__SetWindowPosition, "SetWindowPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowPosition)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	SDL_SetWindowPosition(window, x, y);
	return Value::Null;
}

// sdl2.SetWindowSize
Gura_DeclareFunctionAlias(__SetWindowSize, "SetWindowSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowSize)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int w = args.GetInt(1);
	int h = args.GetInt(2);
	SDL_SetWindowSize(window, w, h);
	return Value::Null;
}

// sdl2.SetWindowTitle
Gura_DeclareFunctionAlias(__SetWindowTitle, "SetWindowTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetWindowTitle)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	const char *title = args.GetString(1);
	SDL_SetWindowTitle(window, title);
	return Value::Null;
}

// sdl2.ShowMessageBox
Gura_DeclareFunctionAlias(__ShowMessageBox, "ShowMessageBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ShowMessageBox)
{
#if 0
	int _rtn = SDL_ShowMessageBox();
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
Gura_DeclareFunctionAlias(__ShowSimpleMessageBox, "ShowSimpleMessageBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ShowSimpleMessageBox)
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
Gura_DeclareFunctionAlias(__ShowWindow, "ShowWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ShowWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_ShowWindow(window);
	return Value::Null;
}

// sdl2.UpdateWindowSurface
Gura_DeclareFunctionAlias(__UpdateWindowSurface, "UpdateWindowSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UpdateWindowSurface)
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
Gura_DeclareFunctionAlias(__UpdateWindowSurfaceRects, "UpdateWindowSurfaceRects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UpdateWindowSurfaceRects)
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

// sdl2.VideoInit
Gura_DeclareFunctionAlias(__VideoInit, "VideoInit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "driver_name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__VideoInit)
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
Gura_DeclareFunctionAlias(__VideoQuit, "VideoQuit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__VideoQuit)
{
	SDL_VideoQuit();
	return Value::Null;
}

// sdl2.CreateRenderer
Gura_DeclareFunctionAlias(__CreateRenderer, "CreateRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateRenderer)
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
Gura_DeclareFunctionAlias(__CreateSoftwareRenderer, "CreateSoftwareRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateSoftwareRenderer)
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
Gura_DeclareFunctionAlias(__CreateTexture, "CreateTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "access", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateTexture)
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
Gura_DeclareFunctionAlias(__CreateTextureFromSurface, "CreateTextureFromSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateTextureFromSurface)
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
Gura_DeclareFunctionAlias(__DestroyRenderer, "DestroyRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DestroyRenderer)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_DestroyRenderer(renderer);
	return Value::Null;
}

// sdl2.DestroyTexture
Gura_DeclareFunctionAlias(__DestroyTexture, "DestroyTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DestroyTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_DestroyTexture(texture);
	return Value::Null;
}

// sdl2.GL_BindTexture
Gura_DeclareFunctionAlias(__GL_BindTexture, "GL_BindTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_BindTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	float texw = 0;
	float texh = 0;
	SDL_GL_BindTexture(texture, &texw, &texh);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(texw), Value(texh)));
}

// sdl2.GL_UnbindTexture
Gura_DeclareFunctionAlias(__GL_UnbindTexture, "GL_UnbindTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GL_UnbindTexture)
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
Gura_DeclareFunctionAlias(__GetNumRenderDrivers, "GetNumRenderDrivers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumRenderDrivers)
{
	int _rtn = SDL_GetNumRenderDrivers();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetRenderDrawBlendMode
Gura_DeclareFunctionAlias(__GetRenderDrawBlendMode, "GetRenderDrawBlendMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRenderDrawBlendMode)
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
Gura_DeclareFunctionAlias(__GetRenderDrawColor, "GetRenderDrawColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRenderDrawColor)
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
Gura_DeclareFunctionAlias(__GetRenderDriverInfo, "GetRenderDriverInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRenderDriverInfo)
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
Gura_DeclareFunctionAlias(__GetRenderTarget, "GetRenderTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRenderTarget)
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
Gura_DeclareFunctionAlias(__GetRenderer, "GetRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRenderer)
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
Gura_DeclareFunctionAlias(__GetRendererInfo, "GetRendererInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRendererInfo)
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
Gura_DeclareFunctionAlias(__GetRenderOutputSize, "GetRenderOutputSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRenderOutputSize)
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
Gura_DeclareFunctionAlias(__GetTextureAlphaMod, "GetTextureAlphaMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetTextureAlphaMod)
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
Gura_DeclareFunctionAlias(__GetTextureBlendMode, "GetTextureBlendMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetTextureBlendMode)
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
Gura_DeclareFunctionAlias(__GetTextureColorMod, "GetTextureColorMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetTextureColorMod)
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
Gura_DeclareFunctionAlias(__LockTexture, "LockTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LockTexture)
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
	SetError_NotImpFunction(sig, "LockTexture");
	return Value::Null;
}

// sdl2.QueryTexture
Gura_DeclareFunctionAlias(__QueryTexture, "QueryTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__QueryTexture)
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
Gura_DeclareFunctionAlias(__RenderClear, "RenderClear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderClear)
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
Gura_DeclareFunctionAlias(__RenderCopy, "RenderCopy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderCopy)
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
Gura_DeclareFunctionAlias(__RenderCopyEx, "RenderCopyEx")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "center", VTYPE_Point, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "flip", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderCopyEx)
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
Gura_DeclareFunctionAlias(__RenderDrawLine, "RenderDrawLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderDrawLine)
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
Gura_DeclareFunctionAlias(__RenderDrawLines, "RenderDrawLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderDrawLines)
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

// sdl2.RenderDrawPoint
Gura_DeclareFunctionAlias(__RenderDrawPoint, "RenderDrawPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderDrawPoint)
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
Gura_DeclareFunctionAlias(__RenderDrawPoints, "RenderDrawPoints")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderDrawPoints)
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

// sdl2.RenderDrawRect
Gura_DeclareFunctionAlias(__RenderDrawRect, "RenderDrawRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderDrawRect)
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
Gura_DeclareFunctionAlias(__RenderDrawRects, "RenderDrawRects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderDrawRects)
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

// sdl2.RenderFillRect
Gura_DeclareFunctionAlias(__RenderFillRect, "RenderFillRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderFillRect)
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
Gura_DeclareFunctionAlias(__RenderFillRects, "RenderFillRects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderFillRects)
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

// sdl2.RenderGetClipRect
Gura_DeclareFunctionAlias(__RenderGetClipRect, "RenderGetClipRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderGetClipRect)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_RenderGetClipRect(renderer, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.RenderGetLogicalSize
Gura_DeclareFunctionAlias(__RenderGetLogicalSize, "RenderGetLogicalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderGetLogicalSize)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	int w = 0;
	int h = 0;
	SDL_RenderGetLogicalSize(renderer, &w, &h);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(w), Value(h)));
}

// sdl2.RenderGetScale
Gura_DeclareFunctionAlias(__RenderGetScale, "RenderGetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderGetScale)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	float scaleX = 0;
	float scaleY = 0;
	SDL_RenderGetScale(renderer, &scaleX, &scaleY);
	return ReturnValue(env, sig, args, Value::CreateList(env, Value(scaleX), Value(scaleY)));
}

// sdl2.RenderGetViewport
Gura_DeclareFunctionAlias(__RenderGetViewport, "RenderGetViewport")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderGetViewport)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_RenderGetViewport(renderer, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.RenderIsClipEnabled
Gura_DeclareFunctionAlias(__RenderIsClipEnabled, "RenderIsClipEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderIsClipEnabled)
{
#if 0
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RenderIsClipEnabled(renderer);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "RenderIsClipEnabled");
	return Value::Null;
}

// sdl2.RenderPresent
Gura_DeclareFunctionAlias(__RenderPresent, "RenderPresent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderPresent)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_RenderPresent(renderer);
	return Value::Null;
}

// sdl2.RenderReadPixels
Gura_DeclareFunctionAlias(__RenderReadPixels, "RenderReadPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderReadPixels)
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

// sdl2.RenderSetClipRect
Gura_DeclareFunctionAlias(__RenderSetClipRect, "RenderSetClipRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderSetClipRect)
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
Gura_DeclareFunctionAlias(__RenderSetLogicalSize, "RenderSetLogicalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderSetLogicalSize)
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
Gura_DeclareFunctionAlias(__RenderSetScale, "RenderSetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "scaleX", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "scaleY", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderSetScale)
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
Gura_DeclareFunctionAlias(__RenderSetViewport, "RenderSetViewport")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderSetViewport)
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
Gura_DeclareFunctionAlias(__RenderTargetSupported, "RenderTargetSupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RenderTargetSupported)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RenderTargetSupported(renderer);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.SetRenderDrawBlendMode
Gura_DeclareFunctionAlias(__SetRenderDrawBlendMode, "SetRenderDrawBlendMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetRenderDrawBlendMode)
{
	SDL_Renderer *renderer = Object_Renderer::GetObject(args, 0)->GetEntity();
	SDL_BlendMode blendMode = static_cast<SDL_BlendMode>(args.GetInt(1));
	SDL_SetRenderDrawBlendMode(renderer, blendMode);
	return Value::Null;
}

// sdl2.SetRenderDrawColor
Gura_DeclareFunctionAlias(__SetRenderDrawColor, "SetRenderDrawColor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "a", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetRenderDrawColor)
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
Gura_DeclareFunctionAlias(__SetRenderTarget, "SetRenderTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetRenderTarget)
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
Gura_DeclareFunctionAlias(__SetTextureAlphaMod, "SetTextureAlphaMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetTextureAlphaMod)
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
Gura_DeclareFunctionAlias(__SetTextureBlendMode, "SetTextureBlendMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetTextureBlendMode)
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
Gura_DeclareFunctionAlias(__SetTextureColorMod, "SetTextureColorMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetTextureColorMod)
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
Gura_DeclareFunctionAlias(__UnlockTexture, "UnlockTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UnlockTexture)
{
	SDL_Texture *texture = Object_Texture::GetObject(args, 0)->GetEntity();
	SDL_UnlockTexture(texture);
	return Value::Null;
}

// sdl2.UpdateTexture
Gura_DeclareFunctionAlias(__UpdateTexture, "UpdateTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "pitch", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UpdateTexture)
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
	SetError_NotImpFunction(sig, "UpdateTexture");
	return Value::Null;
}

// sdl2.UpdateYUVTexture
Gura_DeclareFunctionAlias(__UpdateYUVTexture, "UpdateYUVTexture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UpdateYUVTexture)
{
#if 0
	SDL_UpdateYUVTexture();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "UpdateYUVTexture");
	return Value::Null;
}

// sdl2.AllocFormat
Gura_DeclareFunctionAlias(__AllocFormat, "AllocFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel_format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AllocFormat)
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
Gura_DeclareFunctionAlias(__AllocPalette, "AllocPalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "ncolors", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AllocPalette)
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
Gura_DeclareFunctionAlias(__CalculateGammaRamp, "CalculateGammaRamp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamma", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CalculateGammaRamp)
{
	float gamma = args.GetFloat(0);
	Uint16 ramp[256];
	SDL_CalculateGammaRamp(gamma, ramp);
	return ReturnValue(env, sig, args, Value::CreateList(env, ramp, ArraySizeOf(ramp)));
}

// sdl2.FreeFormat
Gura_DeclareFunctionAlias(__FreeFormat, "FreeFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FreeFormat)
{
	SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	SDL_FreeFormat(format);
	return Value::Null;
}

// sdl2.FreePalette
Gura_DeclareFunctionAlias(__FreePalette, "FreePalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FreePalette)
{
	SDL_Palette *palette = Object_Palette::GetObject(args, 0)->GetEntity();
	SDL_FreePalette(palette);
	return Value::Null;
}

// sdl2.GetPixelFormatName
Gura_DeclareFunctionAlias(__GetPixelFormatName, "GetPixelFormatName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetPixelFormatName)
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
Gura_DeclareFunctionAlias(__GetRGB, "GetRGB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRGB)
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
Gura_DeclareFunctionAlias(__GetRGBA, "GetRGBA")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pixel", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRGBA)
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
Gura_DeclareFunctionAlias(__MapRGB, "MapRGB")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MapRGB)
{
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint32 _rtn = SDL_MapRGB(format, r, g, b);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.MapRGBA
Gura_DeclareFunctionAlias(__MapRGBA, "MapRGBA")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "a", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MapRGBA)
{
	const SDL_PixelFormat *format = Object_PixelFormat::GetObject(args, 0)->GetEntity();
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint8 a = args.GetUChar(4);
	Uint32 _rtn = SDL_MapRGBA(format, r, g, b, a);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.MasksToPixelFormatEnum
Gura_DeclareFunctionAlias(__MasksToPixelFormatEnum, "MasksToPixelFormatEnum")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "bpp", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Rmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Gmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Bmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Amask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MasksToPixelFormatEnum)
{
	int bpp = args.GetInt(0);
	Uint32 Rmask = args.GetULong(1);
	Uint32 Gmask = args.GetULong(2);
	Uint32 Bmask = args.GetULong(3);
	Uint32 Amask = args.GetULong(4);
	Uint32 _rtn = SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.PixelFormatEnumToMasks
Gura_DeclareFunctionAlias(__PixelFormatEnumToMasks, "PixelFormatEnumToMasks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PixelFormatEnumToMasks)
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
Gura_DeclareFunctionAlias(__SetPaletteColors, "SetPaletteColors")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	DeclareArg(env, "colors", VTYPE_Color, OCCUR_Once, FLAG_List);
	DeclareArg(env, "firstcolor", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ncolors", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetPaletteColors)
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

// sdl2.SetPixelFormatPalette
Gura_DeclareFunctionAlias(__SetPixelFormatPalette, "SetPixelFormatPalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetPixelFormatPalette)
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
Gura_DeclareFunctionAlias(__EnclosePoints, "EnclosePoints")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "points", VTYPE_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "clip", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__EnclosePoints)
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

// sdl2.HasIntersection
Gura_DeclareFunctionAlias(__HasIntersection, "HasIntersection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasIntersection)
{
	const SDL_Rect *A = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *B = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_HasIntersection(A, B);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.IntersectRect
Gura_DeclareFunctionAlias(__IntersectRect, "IntersectRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__IntersectRect)
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
Gura_DeclareFunctionAlias(__IntersectRectAndLine, "IntersectRectAndLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "X1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Y1", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "X2", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Y2", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__IntersectRectAndLine)
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
	SetError_NotImpFunction(sig, "IntersectRectAndLine");
	return Value::Null;
}

// sdl2.PointInRect
Gura_DeclareFunctionAlias(__PointInRect, "PointInRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "p", VTYPE_Point, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PointInRect)
{
#if 0
	const SDL_Point *p = Object_Point::GetObject(args, 0)->GetEntity();
	const SDL_Rect *r = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_PointInRect(p, r);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "PointInRect");
	return Value::Null;
}

// sdl2.RectEmpty
Gura_DeclareFunctionAlias(__RectEmpty, "RectEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "r", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RectEmpty)
{
	const SDL_Rect *r = Object_Rect::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_RectEmpty(r);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.RectEquals
Gura_DeclareFunctionAlias(__RectEquals, "RectEquals")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "a", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RectEquals)
{
	const SDL_Rect *a = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *b = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_RectEquals(a, b);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.UnionRect
Gura_DeclareFunctionAlias(__UnionRect, "UnionRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UnionRect)
{
	const SDL_Rect *A = Object_Rect::GetObject(args, 0)->GetEntity();
	const SDL_Rect *B = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_Rect result;
	SDL_UnionRect(A, B, &result);
	Value _rtnVal = Value(new Object_Rect(result));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.BlitScaled
Gura_DeclareFunctionAlias(__BlitScaled, "BlitScaled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__BlitScaled)
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
Gura_DeclareFunctionAlias(__BlitSurface, "BlitSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__BlitSurface)
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
Gura_DeclareFunctionAlias(__ConvertPixels, "ConvertPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_format", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ConvertPixels)
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
	SetError_NotImpFunction(sig, "ConvertPixels");
	return Value::Null;
}

// sdl2.ConvertSurface
Gura_DeclareFunctionAlias(__ConvertSurface, "ConvertSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "fmt", VTYPE_PixelFormat, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ConvertSurface)
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
Gura_DeclareFunctionAlias(__ConvertSurfaceFormat, "ConvertSurfaceFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pixel_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ConvertSurfaceFormat)
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
Gura_DeclareFunctionAlias(__CreateRGBSurface, "CreateRGBSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "depth", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Rmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Gmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Bmask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "Amask", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateRGBSurface)
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
Gura_DeclareFunctionAlias(__CreateRGBSurfaceFrom, "CreateRGBSurfaceFrom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateRGBSurfaceFrom)
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

// sdl2.CreateRGBSurfaceFromImage
Gura_DeclareFunctionAlias(__CreateRGBSurfaceFromImage, "CreateRGBSurfaceFromImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "image", VTYPE_image, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateRGBSurfaceFromImage)
{
	Image *image = Object_image::GetObject(args, 0)->GetImage();
	Object_Surface *pObjSurface = Object_Surface::CreateSurfaceFromImage(sig, image);
	if (pObjSurface == NULL) return Value::Null;
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

// sdl2.FillRect
Gura_DeclareFunctionAlias(__FillRect, "FillRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "color", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FillRect)
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
Gura_DeclareFunctionAlias(__FillRects, "FillRects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rects", VTYPE_Rect, OCCUR_Once, FLAG_List);
	DeclareArg(env, "color", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FillRects)
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

// sdl2.FreeSurface
Gura_DeclareFunctionAlias(__FreeSurface, "FreeSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FreeSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_FreeSurface(surface);
	return Value::Null;
}

// sdl2.GetClipRect
Gura_DeclareFunctionAlias(__GetClipRect, "GetClipRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetClipRect)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_Rect rect;
	SDL_GetClipRect(surface, &rect);
	return ReturnValue(env, sig, args, Value(new Object_Rect(rect)));
}

// sdl2.GetColorKey
Gura_DeclareFunctionAlias(__GetColorKey, "GetColorKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetColorKey)
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
Gura_DeclareFunctionAlias(__GetSurfaceAlphaMod, "GetSurfaceAlphaMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetSurfaceAlphaMod)
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
Gura_DeclareFunctionAlias(__GetSurfaceBlendMode, "GetSurfaceBlendMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetSurfaceBlendMode)
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
Gura_DeclareFunctionAlias(__GetSurfaceColorMod, "GetSurfaceColorMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetSurfaceColorMod)
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
Gura_DeclareFunctionAlias(__LoadBMP, "LoadBMP")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LoadBMP)
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

// sdl2.LoadBMP_RW
Gura_DeclareFunctionAlias(__LoadBMP_RW, "LoadBMP_RW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LoadBMP_RW)
{
#if 0
	SDL_LoadBMP_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LoadBMP_RW");
	return Value::Null;
}

// sdl2.LockSurface
Gura_DeclareFunctionAlias(__LockSurface, "LockSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LockSurface)
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
Gura_DeclareFunctionAlias(__LowerBlit, "LowerBlit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LowerBlit)
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

// sdl2.LowerBlitScaled
Gura_DeclareFunctionAlias(__LowerBlitScaled, "LowerBlitScaled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LowerBlitScaled)
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

// sdl2.MUSTLOCK
Gura_DeclareFunctionAlias(__MUSTLOCK, "MUSTLOCK")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MUSTLOCK)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	bool _rtn = SDL_MUSTLOCK(surface);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.SaveBMP
Gura_DeclareFunctionAlias(__SaveBMP, "SaveBMP")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SaveBMP)
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

// sdl2.SaveBMP_RW
Gura_DeclareFunctionAlias(__SaveBMP_RW, "SaveBMP_RW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SaveBMP_RW)
{
#if 0
	SDL_SaveBMP_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SaveBMP_RW");
	return Value::Null;
}

// sdl2.SetClipRect
Gura_DeclareFunctionAlias(__SetClipRect, "SetClipRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetClipRect)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	const SDL_Rect *rect = Object_Rect::GetObject(args, 1)->GetEntity();
	SDL_bool _rtn = SDL_SetClipRect(surface, rect);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.SetColorKey
Gura_DeclareFunctionAlias(__SetColorKey, "SetColorKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetColorKey)
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
Gura_DeclareFunctionAlias(__SetSurfaceAlphaMod, "SetSurfaceAlphaMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetSurfaceAlphaMod)
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
Gura_DeclareFunctionAlias(__SetSurfaceBlendMode, "SetSurfaceBlendMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "blendMode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetSurfaceBlendMode)
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
Gura_DeclareFunctionAlias(__SetSurfaceColorMod, "SetSurfaceColorMod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetSurfaceColorMod)
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
Gura_DeclareFunctionAlias(__SetSurfacePalette, "SetSurfacePalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "palette", VTYPE_Palette, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetSurfacePalette)
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
Gura_DeclareFunctionAlias(__SetSurfaceRLE, "SetSurfaceRLE")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetSurfaceRLE)
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
Gura_DeclareFunctionAlias(__UnlockSurface, "UnlockSurface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UnlockSurface)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	SDL_UnlockSurface(surface);
	return Value::Null;
}

// sdl2.GetClipboardText
Gura_DeclareFunctionAlias(__GetClipboardText, "GetClipboardText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetClipboardText)
{
	char *_rtn = SDL_GetClipboardText();
	Value _rtnVal(_rtn);
	SDL_free(_rtn);
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.HasClipboardText
Gura_DeclareFunctionAlias(__HasClipboardText, "HasClipboardText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasClipboardText)
{
	SDL_bool _rtn = SDL_HasClipboardText();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.SetClipboardText
Gura_DeclareFunctionAlias(__SetClipboardText, "SetClipboardText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetClipboardText)
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
Gura_DeclareFunctionAlias(__AddEventWatch, "AddEventWatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AddEventWatch)
{
#if 0
	SDL_AddEventWatch();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AddEventWatch");
	return Value::Null;
}

// sdl2.DelEventWatch
Gura_DeclareFunctionAlias(__DelEventWatch, "DelEventWatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DelEventWatch)
{
#if 0
	SDL_DelEventWatch();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DelEventWatch");
	return Value::Null;
}

// sdl2.EventState
Gura_DeclareFunctionAlias(__EventState, "EventState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__EventState)
{
	Uint32 type = args.GetULong(0);
	int state = args.GetInt(1);
	Uint8 _rtn = SDL_EventState(type, state);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.FilterEvents
Gura_DeclareFunctionAlias(__FilterEvents, "FilterEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FilterEvents)
{
#if 0
	SDL_FilterEvents();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "FilterEvents");
	return Value::Null;
}

// sdl2.FlushEvent
Gura_DeclareFunctionAlias(__FlushEvent, "FlushEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FlushEvent)
{
	Uint32 type = args.GetULong(0);
	SDL_FlushEvent(type);
	return Value::Null;
}

// sdl2.FlushEvents
Gura_DeclareFunctionAlias(__FlushEvents, "FlushEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FlushEvents)
{
	Uint32 minType = args.GetULong(0);
	Uint32 maxType = args.GetULong(1);
	SDL_FlushEvents(minType, maxType);
	return Value::Null;
}

// sdl2.GetEventFilter
Gura_DeclareFunctionAlias(__GetEventFilter, "GetEventFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetEventFilter)
{
#if 0
	SDL_GetEventFilter();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetEventFilter");
	return Value::Null;
}

// sdl2.GetNumTouchDevices
Gura_DeclareFunctionAlias(__GetNumTouchDevices, "GetNumTouchDevices")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumTouchDevices)
{
	int _rtn = SDL_GetNumTouchDevices();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetNumTouchFingers
Gura_DeclareFunctionAlias(__GetNumTouchFingers, "GetNumTouchFingers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumTouchFingers)
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
Gura_DeclareFunctionAlias(__GetTouchDevice, "GetTouchDevice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetTouchDevice)
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
Gura_DeclareFunctionAlias(__GetTouchFinger, "GetTouchFinger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetTouchFinger)
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
Gura_DeclareFunctionAlias(__HasEvent, "HasEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasEvent)
{
	Uint32 type = args.GetULong(0);
	SDL_bool _rtn = SDL_HasEvent(type);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasEvents
Gura_DeclareFunctionAlias(__HasEvents, "HasEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasEvents)
{
	Uint32 minType = args.GetULong(0);
	Uint32 maxType = args.GetULong(1);
	SDL_bool _rtn = SDL_HasEvents(minType, maxType);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.LoadDollarTemplates
Gura_DeclareFunctionAlias(__LoadDollarTemplates, "LoadDollarTemplates")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LoadDollarTemplates)
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

// sdl2.AddEvents
Gura_DeclareFunctionAlias(__AddEvents, "AddEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "events", VTYPE_Event, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AddEvents)
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

// sdl2.PeekEvents
Gura_DeclareFunctionAlias(__PeekEvents, "PeekEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PeekEvents)
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
Gura_DeclareFunctionAlias(__GetEvents, "GetEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetEvents)
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
Gura_DeclareFunctionAlias(__PollEvent, "PollEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PollEvent)
{
	SDL_Event event;
	int _rtn = SDL_PollEvent(&event);
	if (_rtn == 0) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_Event(event)));
}

// sdl2.PumpEvents
Gura_DeclareFunctionAlias(__PumpEvents, "PumpEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PumpEvents)
{
	SDL_PumpEvents();
	return Value::Null;
}

// sdl2.PushEvent
Gura_DeclareFunctionAlias(__PushEvent, "PushEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "event", VTYPE_Event, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PushEvent)
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
Gura_DeclareFunctionAlias(__QuitRequested, "QuitRequested")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__QuitRequested)
{
	bool _rtn = SDL_QuitRequested();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.RecordGesture
Gura_DeclareFunctionAlias(__RecordGesture, "RecordGesture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RecordGesture)
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
Gura_DeclareFunctionAlias(__RegisterEvents, "RegisterEvents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "numevents", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RegisterEvents)
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
Gura_DeclareFunctionAlias(__SaveAllDollarTemplates, "SaveAllDollarTemplates")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SaveAllDollarTemplates)
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

// sdl2.SaveDollarTemplate
Gura_DeclareFunctionAlias(__SaveDollarTemplate, "SaveDollarTemplate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "gestureId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SaveDollarTemplate)
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

// sdl2.SetEventFilter
Gura_DeclareFunctionAlias(__SetEventFilter, "SetEventFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetEventFilter)
{
#if 0
	SDL_SetEventFilter();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SetEventFilter");
	return Value::Null;
}

// sdl2.WaitEvent
Gura_DeclareFunctionAlias(__WaitEvent, "WaitEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WaitEvent)
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
Gura_DeclareFunctionAlias(__WaitEventTimeout, "WaitEventTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WaitEventTimeout)
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

// sdl2.CheckKeyboardState
Gura_DeclareFunctionAlias(__CheckKeyboardState, "CheckKeyboardState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CheckKeyboardState)
{
	SDL_Scancode scancode = static_cast<SDL_Scancode>(args.GetInt(0));
	int numkeys = 0;
	const Uint8 *_keystate = SDL_GetKeyboardState(&numkeys);
	bool _rtn = (0 <= scancode && scancode < numkeys && _keystate[scancode] != 0);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetKeyFromName
Gura_DeclareFunctionAlias(__GetKeyFromName, "GetKeyFromName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetKeyFromName)
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
Gura_DeclareFunctionAlias(__GetKeyFromScancode, "GetKeyFromScancode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetKeyFromScancode)
{
	SDL_Scancode scancode = static_cast<SDL_Scancode>(args.GetInt(0));
	SDL_Keycode _rtn = SDL_GetKeyFromScancode(scancode);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetKeyName
Gura_DeclareFunctionAlias(__GetKeyName, "GetKeyName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetKeyName)
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
Gura_DeclareFunctionAlias(__GetKeyboardFocus, "GetKeyboardFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetKeyboardFocus)
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
Gura_DeclareFunctionAlias(__GetKeyboardState, "GetKeyboardState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetKeyboardState)
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

// sdl2.GetModState
Gura_DeclareFunctionAlias(__GetModState, "GetModState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetModState)
{
	SDL_Keymod _rtn = SDL_GetModState();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetScancodeFromKey
Gura_DeclareFunctionAlias(__GetScancodeFromKey, "GetScancodeFromKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetScancodeFromKey)
{
	SDL_Keycode key = static_cast<SDL_Keycode>(args.GetInt(0));
	SDL_Scancode _rtn = SDL_GetScancodeFromKey(key);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetScancodeFromName
Gura_DeclareFunctionAlias(__GetScancodeFromName, "GetScancodeFromName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetScancodeFromName)
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
Gura_DeclareFunctionAlias(__GetScancodeName, "GetScancodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "scancode", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetScancodeName)
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
Gura_DeclareFunctionAlias(__HasScreenKeyboardSupport, "HasScreenKeyboardSupport")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasScreenKeyboardSupport)
{
	SDL_bool _rtn = SDL_HasScreenKeyboardSupport();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.IsScreenKeyboardShown
Gura_DeclareFunctionAlias(__IsScreenKeyboardShown, "IsScreenKeyboardShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__IsScreenKeyboardShown)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_IsScreenKeyboardShown(window);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.IsTextInputActive
Gura_DeclareFunctionAlias(__IsTextInputActive, "IsTextInputActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__IsTextInputActive)
{
	SDL_bool _rtn = SDL_IsTextInputActive();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.SetModState
Gura_DeclareFunctionAlias(__SetModState, "SetModState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "modstate", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetModState)
{
	SDL_Keymod modstate = static_cast<SDL_Keymod>(args.GetInt(0));
	SDL_SetModState(modstate);
	return Value::Null;
}

// sdl2.SetTextInputRect
Gura_DeclareFunctionAlias(__SetTextInputRect, "SetTextInputRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetTextInputRect)
{
	SDL_Rect *rect = Object_Rect::GetObject(args, 0)->GetEntity();
	SDL_SetTextInputRect(rect);
	return Value::Null;
}

// sdl2.StartTextInput
Gura_DeclareFunctionAlias(__StartTextInput, "StartTextInput")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__StartTextInput)
{
	SDL_StartTextInput();
	return Value::Null;
}

// sdl2.StopTextInput
Gura_DeclareFunctionAlias(__StopTextInput, "StopTextInput")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__StopTextInput)
{
	SDL_StopTextInput();
	return Value::Null;
}

// sdl2.CaptureMouse
Gura_DeclareFunctionAlias(__CaptureMouse, "CaptureMouse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "enalbed", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CaptureMouse)
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
Gura_DeclareFunctionAlias(__CreateColorCursor, "CreateColorCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateColorCursor)
{
	SDL_Surface *surface = Object_Surface::GetObject(args, 0)->GetEntity();
	int hot_x = args.GetInt(1);
	int hot_y = args.GetInt(2);
	SDL_Cursor *_rtn = SDL_CreateColorCursor(surface, hot_x, hot_y);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, true));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.CreateCursor
Gura_DeclareFunctionAlias(__CreateCursor, "CreateCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_binary, OCCUR_Once, FLAG_None);
	DeclareArg(env, "mask", VTYPE_binary, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateCursor)
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

// sdl2.CreateSystemCursor
Gura_DeclareFunctionAlias(__CreateSystemCursor, "CreateSystemCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateSystemCursor)
{
	SDL_SystemCursor id = static_cast<SDL_SystemCursor>(args.GetInt(0));
	SDL_Cursor *_rtn = SDL_CreateSystemCursor(id);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, true));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.FreeCursor
Gura_DeclareFunctionAlias(__FreeCursor, "FreeCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FreeCursor)
{
	SDL_Cursor *cursor = Object_Cursor::GetObject(args, 0)->GetEntity();
	SDL_FreeCursor(cursor);
	return Value::Null;
}

// sdl2.GetCursor
Gura_DeclareFunctionAlias(__GetCursor, "GetCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetCursor)
{
	SDL_Cursor *_rtn = SDL_GetCursor();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, false));
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetDefaultCursor
Gura_DeclareFunctionAlias(__GetDefaultCursor, "GetDefaultCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetDefaultCursor)
{
	SDL_Cursor *_rtn = SDL_GetDefaultCursor();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(new Object_Cursor(_rtn, true));
	} else if (*SDL_GetError() != '\0') {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GetGlobalMouseState
Gura_DeclareFunctionAlias(__GetGlobalMouseState, "GetGlobalMouseState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetGlobalMouseState)
{
#if 0
	SDL_GetGlobalMouseState();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetGlobalMouseState");
	return Value::Null;
}

// sdl2.GetMouseFocus
Gura_DeclareFunctionAlias(__GetMouseFocus, "GetMouseFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetMouseFocus)
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
Gura_DeclareFunctionAlias(__GetMouseState, "GetMouseState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetMouseState)
{
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
}

// sdl2.GetRelativeMouseMode
Gura_DeclareFunctionAlias(__GetRelativeMouseMode, "GetRelativeMouseMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRelativeMouseMode)
{
	SDL_bool _rtn = SDL_GetRelativeMouseMode();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.GetRelativeMouseState
Gura_DeclareFunctionAlias(__GetRelativeMouseState, "GetRelativeMouseState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetRelativeMouseState)
{
	int x = 0;
	int y = 0;
	Uint32 _rtn = SDL_GetRelativeMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(_rtn), Value(x), Value(y)));
}

// sdl2.SetCursor
Gura_DeclareFunctionAlias(__SetCursor, "SetCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cursor", VTYPE_Cursor, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetCursor)
{
	SDL_Cursor *cursor = Object_Cursor::GetObject(args, 0)->GetEntity();
	SDL_SetCursor(cursor);
	return Value::Null;
}

// sdl2.SetRelativeMouseMode
Gura_DeclareFunctionAlias(__SetRelativeMouseMode, "SetRelativeMouseMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "enabled", VTYPE_boolean, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SetRelativeMouseMode)
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
Gura_DeclareFunctionAlias(__ShowCursor, "ShowCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "toggle", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ShowCursor)
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
Gura_DeclareFunctionAlias(__WarpMouseGlobal, "WarpMouseGlobal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WarpMouseGlobal)
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
Gura_DeclareFunctionAlias(__WarpMouseInWindow, "WarpMouseInWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "window", VTYPE_Window, OCCUR_Once, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WarpMouseInWindow)
{
	SDL_Window *window = Object_Window::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	SDL_WarpMouseInWindow(window, x, y);
	return Value::Null;
}

// sdl2.JoystickClose
Gura_DeclareFunctionAlias(__JoystickClose, "JoystickClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickClose)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickClose(joystick);
	return Value::Null;
}

// sdl2.JoystickEventState
Gura_DeclareFunctionAlias(__JoystickEventState, "JoystickEventState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickEventState)
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
Gura_DeclareFunctionAlias(__JoystickGetAttached, "JoystickGetAttached")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetAttached)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_JoystickGetAttached(joystick);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.JoystickGetAxis
Gura_DeclareFunctionAlias(__JoystickGetAxis, "JoystickGetAxis")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetAxis)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int axis = args.GetInt(1);
	Sint16 _rtn = SDL_JoystickGetAxis(joystick, axis);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.JoystickGetBall
Gura_DeclareFunctionAlias(__JoystickGetBall, "JoystickGetBall")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "ball", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetBall)
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
Gura_DeclareFunctionAlias(__JoystickGetButton, "JoystickGetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetButton)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int button = args.GetInt(1);
	Uint8 _rtn = SDL_JoystickGetButton(joystick, button);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.JoystickGetDeviceGUID
Gura_DeclareFunctionAlias(__JoystickGetDeviceGUID, "JoystickGetDeviceGUID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetDeviceGUID)
{
	int device_index = args.GetInt(0);
	SDL_JoystickGUID _rtn = SDL_JoystickGetDeviceGUID(device_index);
	Value _rtnVal(new Object_JoystickGUID(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetGUID
Gura_DeclareFunctionAlias(__JoystickGetGUID, "JoystickGetGUID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetGUID)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	SDL_JoystickGUID _rtn = SDL_JoystickGetGUID(joystick);
	Value _rtnVal(new Object_JoystickGUID(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetGUIDFromString
Gura_DeclareFunctionAlias(__JoystickGetGUIDFromString, "JoystickGetGUIDFromString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchGUID", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetGUIDFromString)
{
	const char *pchGUID = args.GetString(0);
	SDL_JoystickGUID _rtn = SDL_JoystickGetGUIDFromString(pchGUID);
	Value _rtnVal(new Object_JoystickGUID(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.JoystickGetGUIDString
Gura_DeclareFunctionAlias(__JoystickGetGUIDString, "JoystickGetGUIDString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "guid", VTYPE_JoystickGUID, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetGUIDString)
{
	SDL_JoystickGUID guid = Object_JoystickGUID::GetObject(args, 0)->GetEntity();
	char szGUID[64];
	int cbGUID = sizeof(szGUID);
	SDL_JoystickGetGUIDString(guid, szGUID, cbGUID);
	return ReturnValue(env, sig, args, Value(szGUID));
}

// sdl2.JoystickGetHat
Gura_DeclareFunctionAlias(__JoystickGetHat, "JoystickGetHat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hat", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickGetHat)
{
	SDL_Joystick *joystick = Object_Joystick::GetObject(args, 0)->GetEntity();
	int hat = args.GetInt(1);
	Uint8 _rtn = SDL_JoystickGetHat(joystick, hat);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.JoystickInstanceID
Gura_DeclareFunctionAlias(__JoystickInstanceID, "JoystickInstanceID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickInstanceID)
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
Gura_DeclareFunctionAlias(__JoystickName, "JoystickName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickName)
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
Gura_DeclareFunctionAlias(__JoystickNameForIndex, "JoystickNameForIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickNameForIndex)
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
Gura_DeclareFunctionAlias(__JoystickNumAxes, "JoystickNumAxes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickNumAxes)
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
Gura_DeclareFunctionAlias(__JoystickNumBalls, "JoystickNumBalls")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickNumBalls)
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
Gura_DeclareFunctionAlias(__JoystickNumButtons, "JoystickNumButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickNumButtons)
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
Gura_DeclareFunctionAlias(__JoystickNumHats, "JoystickNumHats")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickNumHats)
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
Gura_DeclareFunctionAlias(__JoystickOpen, "JoystickOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickOpen)
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
Gura_DeclareFunctionAlias(__JoystickUpdate, "JoystickUpdate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickUpdate)
{
	SDL_JoystickUpdate();
	return Value::Null;
}

// sdl2.NumJoysticks
Gura_DeclareFunctionAlias(__NumJoysticks, "NumJoysticks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__NumJoysticks)
{
	int _rtn = SDL_NumJoysticks();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GameControllerAddMapping
Gura_DeclareFunctionAlias(__GameControllerAddMapping, "GameControllerAddMapping")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "mappingString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerAddMapping)
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
Gura_DeclareFunctionAlias(__GameControllerAddMappingsFromFile, "GameControllerAddMappingsFromFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerAddMappingsFromFile)
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

// sdl2.GameControllerAddMappingsFromRW
Gura_DeclareFunctionAlias(__GameControllerAddMappingsFromRW, "GameControllerAddMappingsFromRW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerAddMappingsFromRW)
{
#if 0
	SDL_GameControllerAddMappingsFromRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GameControllerAddMappingsFromRW");
	return Value::Null;
}

// sdl2.GameControllerClose
Gura_DeclareFunctionAlias(__GameControllerClose, "GameControllerClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerClose)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerClose(gamecontroller);
	return Value::Null;
}

// sdl2.GameControllerEventState
Gura_DeclareFunctionAlias(__GameControllerEventState, "GameControllerEventState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerEventState)
{
	int state = args.GetInt(0);
	int _rtn = SDL_GameControllerEventState(state);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GameControllerGetAttached
Gura_DeclareFunctionAlias(__GameControllerGetAttached, "GameControllerGetAttached")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetAttached)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_bool _rtn = SDL_GameControllerGetAttached(gamecontroller);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.GameControllerGetAxis
Gura_DeclareFunctionAlias(__GameControllerGetAxis, "GameControllerGetAxis")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetAxis)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	Sint16 _rtn = SDL_GameControllerGetAxis(gamecontroller, axis);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GameControllerGetAxisFromString
Gura_DeclareFunctionAlias(__GameControllerGetAxisFromString, "GameControllerGetAxisFromString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetAxisFromString)
{
	const char *pchString = args.GetString(0);
	SDL_GameControllerAxis _rtn = SDL_GameControllerGetAxisFromString(pchString);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GameControllerGetBindForAxis
Gura_DeclareFunctionAlias(__GameControllerGetBindForAxis, "GameControllerGetBindForAxis")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetBindForAxis)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	SDL_GameControllerButtonBind _rtn = SDL_GameControllerGetBindForAxis(gamecontroller, axis);
	Value _rtnVal(new Object_GameControllerButtonBind(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetBindForButton
Gura_DeclareFunctionAlias(__GameControllerGetBindForButton, "GameControllerGetBindForButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetBindForButton)
{
	SDL_GameController *gamecontroller = Object_GameController::GetObject(args, 0)->GetEntity();
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(1));
	SDL_GameControllerButtonBind _rtn = SDL_GameControllerGetBindForButton(gamecontroller, button);
	Value _rtnVal(new Object_GameControllerButtonBind(_rtn));
	return ReturnValue(env, sig, args, _rtnVal);
}

// sdl2.GameControllerGetButton
Gura_DeclareFunctionAlias(__GameControllerGetButton, "GameControllerGetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetButton)
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
Gura_DeclareFunctionAlias(__GameControllerGetButtonFromString, "GameControllerGetButtonFromString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "pchString", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetButtonFromString)
{
	const char *pchString = args.GetString(0);
	SDL_GameControllerButton _rtn = SDL_GameControllerGetButtonFromString(pchString);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GameControllerGetJoystick
Gura_DeclareFunctionAlias(__GameControllerGetJoystick, "GameControllerGetJoystick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetJoystick)
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
Gura_DeclareFunctionAlias(__GameControllerGetStringForAxis, "GameControllerGetStringForAxis")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetStringForAxis)
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
Gura_DeclareFunctionAlias(__GameControllerGetStringForButton, "GameControllerGetStringForButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerGetStringForButton)
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
Gura_DeclareFunctionAlias(__GameControllerMapping, "GameControllerMapping")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerMapping)
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
Gura_DeclareFunctionAlias(__GameControllerMappingForGUID, "GameControllerMappingForGUID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "guid", VTYPE_JoystickGUID, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerMappingForGUID)
{
	SDL_JoystickGUID guid = Object_JoystickGUID::GetObject(args, 0)->GetEntity();
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
Gura_DeclareFunctionAlias(__GameControllerName, "GameControllerName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "gamecontroller", VTYPE_GameController, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerName)
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
Gura_DeclareFunctionAlias(__GameControllerNameForIndex, "GameControllerNameForIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerNameForIndex)
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
Gura_DeclareFunctionAlias(__GameControllerOpen, "GameControllerOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerOpen)
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
Gura_DeclareFunctionAlias(__GameControllerUpdate, "GameControllerUpdate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GameControllerUpdate)
{
	SDL_GameControllerUpdate();
	return Value::Null;
}

// sdl2.IsGameController
Gura_DeclareFunctionAlias(__IsGameController, "IsGameController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__IsGameController)
{
	int joystick_index = args.GetInt(0);
	SDL_bool _rtn = SDL_IsGameController(joystick_index);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HapticClose
Gura_DeclareFunctionAlias(__HapticClose, "HapticClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticClose)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	SDL_HapticClose(haptic);
	return Value::Null;
}

// sdl2.HapticDestroyEffect
Gura_DeclareFunctionAlias(__HapticDestroyEffect, "HapticDestroyEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticDestroyEffect)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	int effect = args.GetInt(1);
	SDL_HapticDestroyEffect(haptic, effect);
	return Value::Null;
}

// sdl2.HapticEffectSupported
Gura_DeclareFunctionAlias(__HapticEffectSupported, "HapticEffectSupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticEffectSupported)
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
Gura_DeclareFunctionAlias(__HapticGetEffectStatus, "HapticGetEffectStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticGetEffectStatus)
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
Gura_DeclareFunctionAlias(__HapticIndex, "HapticIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticIndex)
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
Gura_DeclareFunctionAlias(__HapticName, "HapticName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticName)
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
Gura_DeclareFunctionAlias(__HapticNewEffect, "HapticNewEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticNewEffect)
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
Gura_DeclareFunctionAlias(__HapticNumAxes, "HapticNumAxes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticNumAxes)
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
Gura_DeclareFunctionAlias(__HapticNumEffects, "HapticNumEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticNumEffects)
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
Gura_DeclareFunctionAlias(__HapticNumEffectsPlaying, "HapticNumEffectsPlaying")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticNumEffectsPlaying)
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
Gura_DeclareFunctionAlias(__HapticOpen, "HapticOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticOpen)
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
Gura_DeclareFunctionAlias(__HapticOpenFromJoystick, "HapticOpenFromJoystick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticOpenFromJoystick)
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
Gura_DeclareFunctionAlias(__HapticOpenFromMouse, "HapticOpenFromMouse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticOpenFromMouse)
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
Gura_DeclareFunctionAlias(__HapticOpened, "HapticOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "device_index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticOpened)
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
Gura_DeclareFunctionAlias(__HapticPause, "HapticPause")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticPause)
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
Gura_DeclareFunctionAlias(__HapticQuery, "HapticQuery")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticQuery)
{
	SDL_Haptic *haptic = Object_Haptic::GetObject(args, 0)->GetEntity();
	unsigned int _rtn = SDL_HapticQuery(haptic);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.HapticRumbleInit
Gura_DeclareFunctionAlias(__HapticRumbleInit, "HapticRumbleInit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticRumbleInit)
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
Gura_DeclareFunctionAlias(__HapticRumblePlay, "HapticRumblePlay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "strength", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "length", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticRumblePlay)
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
Gura_DeclareFunctionAlias(__HapticRumbleStop, "HapticRumbleStop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticRumbleStop)
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
Gura_DeclareFunctionAlias(__HapticRumbleSupported, "HapticRumbleSupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticRumbleSupported)
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
Gura_DeclareFunctionAlias(__HapticRunEffect, "HapticRunEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iterations", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticRunEffect)
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
Gura_DeclareFunctionAlias(__HapticSetAutocenter, "HapticSetAutocenter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "autocenter", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticSetAutocenter)
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
Gura_DeclareFunctionAlias(__HapticSetGain, "HapticSetGain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "gain", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticSetGain)
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
Gura_DeclareFunctionAlias(__HapticStopAll, "HapticStopAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticStopAll)
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
Gura_DeclareFunctionAlias(__HapticStopEffect, "HapticStopEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticStopEffect)
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
Gura_DeclareFunctionAlias(__HapticUnpause, "HapticUnpause")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticUnpause)
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
Gura_DeclareFunctionAlias(__HapticUpdateEffect, "HapticUpdateEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "haptic", VTYPE_Haptic, OCCUR_Once, FLAG_None);
	DeclareArg(env, "effect", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "data", VTYPE_HapticEffect, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HapticUpdateEffect)
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
Gura_DeclareFunctionAlias(__JoystickIsHaptic, "JoystickIsHaptic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_Joystick, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__JoystickIsHaptic)
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
Gura_DeclareFunctionAlias(__MouseIsHaptic, "MouseIsHaptic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MouseIsHaptic)
{
	int _rtn = SDL_MouseIsHaptic();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.NumHaptics
Gura_DeclareFunctionAlias(__NumHaptics, "NumHaptics")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__NumHaptics)
{
	int _rtn = SDL_NumHaptics();
	if (_rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.AudioInit
Gura_DeclareFunctionAlias(__AudioInit, "AudioInit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "driver_name", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AudioInit)
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
Gura_DeclareFunctionAlias(__AudioQuit, "AudioQuit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AudioQuit)
{
	SDL_AudioQuit();
	return Value::Null;
}

// sdl2.BuildAudioCVT
Gura_DeclareFunctionAlias(__BuildAudioCVT, "BuildAudioCVT")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "cvt", VTYPE_AudioCVT, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_channels", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src_rate", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_channels", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst_rate", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__BuildAudioCVT)
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
Gura_DeclareFunctionAlias(__ClearQueuedAudio, "ClearQueuedAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ClearQueuedAudio)
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
Gura_DeclareFunctionAlias(__CloseAudio, "CloseAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CloseAudio)
{
	SDL_CloseAudio();
	return Value::Null;
}

// sdl2.CloseAudioDevice
Gura_DeclareFunctionAlias(__CloseAudioDevice, "CloseAudioDevice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CloseAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_CloseAudioDevice(dev);
	return Value::Null;
}

// sdl2.ConvertAudio
Gura_DeclareFunctionAlias(__ConvertAudio, "ConvertAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "cvt", VTYPE_AudioCVT, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ConvertAudio)
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
Gura_DeclareFunctionAlias(__FreeWAV, "FreeWAV")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "wav", VTYPE_Wav, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FreeWAV)
{
	Object_Wav *wav = Object_Wav::GetObject(args, 0);
	Object_Wav *pObj = Object_Wav::GetObject(args, 0);
	Uint8 *buffer = pObj->GetBuffer();
	SDL_FreeWAV(buffer);
	return Value::Null;
}

// sdl2.GetAudioDeviceName
Gura_DeclareFunctionAlias(__GetAudioDeviceName, "GetAudioDeviceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetAudioDeviceName)
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
Gura_DeclareFunctionAlias(__GetAudioDeviceStatus, "GetAudioDeviceStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetAudioDeviceStatus)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_AudioStatus _rtn = SDL_GetAudioDeviceStatus(dev);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetAudioDriver
Gura_DeclareFunctionAlias(__GetAudioDriver, "GetAudioDriver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetAudioDriver)
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
Gura_DeclareFunctionAlias(__GetAudioStatus, "GetAudioStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetAudioStatus)
{
	SDL_AudioStatus _rtn = SDL_GetAudioStatus();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetCurrentAudioDriver
Gura_DeclareFunctionAlias(__GetCurrentAudioDriver, "GetCurrentAudioDriver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetCurrentAudioDriver)
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
Gura_DeclareFunctionAlias(__GetNumAudioDevices, "GetNumAudioDevices")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumAudioDevices)
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
Gura_DeclareFunctionAlias(__GetNumAudioDrivers, "GetNumAudioDrivers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetNumAudioDrivers)
{
	int _rtn = SDL_GetNumAudioDrivers();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetQueuedAudioSize
Gura_DeclareFunctionAlias(__GetQueuedAudioSize, "GetQueuedAudioSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetQueuedAudioSize)
{
#if 0
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	Uint32 _rtn = SDL_GetQueuedAudioSize(dev);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "GetQueuedAudioSize");
	return Value::Null;
}

// sdl2.LoadWAV
Gura_DeclareFunctionAlias(__LoadWAV, "LoadWAV")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_stream, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LoadWAV)
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

// sdl2.LoadWAV_RW
Gura_DeclareFunctionAlias(__LoadWAV_RW, "LoadWAV_RW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LoadWAV_RW)
{
#if 0
	SDL_LoadWAV_RW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LoadWAV_RW");
	return Value::Null;
}

// sdl2.LockAudio
Gura_DeclareFunctionAlias(__LockAudio, "LockAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LockAudio)
{
	SDL_LockAudio();
	return Value::Null;
}

// sdl2.LockAudioDevice
Gura_DeclareFunctionAlias(__LockAudioDevice, "LockAudioDevice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LockAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_LockAudioDevice(dev);
	return Value::Null;
}

// sdl2.MixAudio
Gura_DeclareFunctionAlias(__MixAudio, "MixAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "volume", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MixAudio)
{
#if 0
	int volume = args.GetInt(0);
	SDL_MixAudio(volume);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "MixAudio");
	return Value::Null;
}

// sdl2.MixAudioFormat
Gura_DeclareFunctionAlias(__MixAudioFormat, "MixAudioFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "volume", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MixAudioFormat)
{
#if 0
	SDL_AudioFormat format = static_cast<SDL_AudioFormat>(args.GetInt(0));
	int volume = args.GetInt(1);
	SDL_MixAudioFormat(format, volume);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "MixAudioFormat");
	return Value::Null;
}

// sdl2.OpenAudio
Gura_DeclareFunctionAlias(__OpenAudio, "OpenAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "desired", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__OpenAudio)
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
Gura_DeclareFunctionAlias(__OpenAudioDevice, "OpenAudioDevice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "device", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "iscapture", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "desired", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	DeclareArg(env, "allowed_changes", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__OpenAudioDevice)
{
#if 0
	const char *device = args.GetString(0);
	int iscapture = args.GetInt(1);
	const SDL_AudioSpec *desired = Object_AudioSpec::GetObject(args, 2)->GetEntity();
	int allowed_changes = args.GetInt(3);
	SDL_AudioDeviceID _rtn = SDL_OpenAudioDevice(device, iscapture, desired, allowed_changes);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "OpenAudioDevice");
	return Value::Null;
}

// sdl2.PauseAudio
Gura_DeclareFunctionAlias(__PauseAudio, "PauseAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PauseAudio)
{
	int pause_on = args.GetInt(0);
	SDL_PauseAudio(pause_on);
	return Value::Null;
}

// sdl2.PauseAudioDevice
Gura_DeclareFunctionAlias(__PauseAudioDevice, "PauseAudioDevice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pause_on", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__PauseAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	int pause_on = args.GetInt(1);
	SDL_PauseAudioDevice(dev, pause_on);
	return Value::Null;
}

// sdl2.QueueAudio
Gura_DeclareFunctionAlias(__QueueAudio, "QueueAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__QueueAudio)
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
	SetError_NotImpFunction(sig, "QueueAudio");
	return Value::Null;
}

// sdl2.UnlockAudio
Gura_DeclareFunctionAlias(__UnlockAudio, "UnlockAudio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UnlockAudio)
{
	SDL_UnlockAudio();
	return Value::Null;
}

// sdl2.UnlockAudioDevice
Gura_DeclareFunctionAlias(__UnlockAudioDevice, "UnlockAudioDevice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UnlockAudioDevice)
{
	SDL_AudioDeviceID dev = static_cast<SDL_AudioDeviceID>(args.GetInt(0));
	SDL_UnlockAudioDevice(dev);
	return Value::Null;
}

// sdl2.AUDIO_BITSIZE
Gura_DeclareFunctionAlias(__AUDIO_BITSIZE, "AUDIO_BITSIZE")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AUDIO_BITSIZE)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_BITSIZE(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.AUDIO_ISFLOAT
Gura_DeclareFunctionAlias(__AUDIO_ISFLOAT, "AUDIO_ISFLOAT")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AUDIO_ISFLOAT)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISFLOAT(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.AUDIO_ISBIGENDIAN
Gura_DeclareFunctionAlias(__AUDIO_ISBIGENDIAN, "AUDIO_ISBIGENDIAN")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AUDIO_ISBIGENDIAN)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISBIGENDIAN(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.AUDIO_ISSIGNED
Gura_DeclareFunctionAlias(__AUDIO_ISSIGNED, "AUDIO_ISSIGNED")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AUDIO_ISSIGNED)
{
	Uint16 x = args.GetUShort(0);
	Uint16 _rtn = SDL_AUDIO_ISSIGNED(x);
	return ReturnValue(env, sig, args, Value(_rtn != 0));
}

// sdl2.AUDIO_ISINT
Gura_DeclareFunctionAlias(__AUDIO_ISINT, "AUDIO_ISINT")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AUDIO_ISINT)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISINT(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.AUDIO_ISLITTLEENDIAN
Gura_DeclareFunctionAlias(__AUDIO_ISLITTLEENDIAN, "AUDIO_ISLITTLEENDIAN")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AUDIO_ISLITTLEENDIAN)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISLITTLEENDIAN(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.AUDIO_ISUNSIGNED
Gura_DeclareFunctionAlias(__AUDIO_ISUNSIGNED, "AUDIO_ISUNSIGNED")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AUDIO_ISUNSIGNED)
{
	Uint16 x = args.GetUShort(0);
	bool _rtn = SDL_AUDIO_ISUNSIGNED(x);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.CreateThread
Gura_DeclareFunctionAlias(__CreateThread, "CreateThread")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateThread)
{
#if 0
	SDL_CreateThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateThread");
	return Value::Null;
}

// sdl2.DetachThread
Gura_DeclareFunctionAlias(__DetachThread, "DetachThread")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DetachThread)
{
#if 0
	SDL_DetachThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DetachThread");
	return Value::Null;
}

// sdl2.GetThreadID
Gura_DeclareFunctionAlias(__GetThreadID, "GetThreadID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetThreadID)
{
#if 0
	SDL_GetThreadID();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetThreadID");
	return Value::Null;
}

// sdl2.GetThreadName
Gura_DeclareFunctionAlias(__GetThreadName, "GetThreadName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetThreadName)
{
#if 0
	SDL_GetThreadName();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetThreadName");
	return Value::Null;
}

// sdl2.GetThreadPriority
Gura_DeclareFunctionAlias(__GetThreadPriority, "GetThreadPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetThreadPriority)
{
#if 0
	SDL_GetThreadPriority();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "GetThreadPriority");
	return Value::Null;
}

// sdl2.TLSCreate
Gura_DeclareFunctionAlias(__TLSCreate, "TLSCreate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__TLSCreate)
{
#if 0
	SDL_TLSCreate();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TLSCreate");
	return Value::Null;
}

// sdl2.TLSGet
Gura_DeclareFunctionAlias(__TLSGet, "TLSGet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__TLSGet)
{
#if 0
	SDL_TLSGet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TLSGet");
	return Value::Null;
}

// sdl2.TLSSet
Gura_DeclareFunctionAlias(__TLSSet, "TLSSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__TLSSet)
{
#if 0
	SDL_TLSSet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TLSSet");
	return Value::Null;
}

// sdl2.ThreadID
Gura_DeclareFunctionAlias(__ThreadID, "ThreadID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ThreadID)
{
#if 0
	SDL_ThreadID();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ThreadID");
	return Value::Null;
}

// sdl2.WaitThread
Gura_DeclareFunctionAlias(__WaitThread, "WaitThread")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WaitThread)
{
#if 0
	SDL_WaitThread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WaitThread");
	return Value::Null;
}

// sdl2.CondBroadcast
Gura_DeclareFunctionAlias(__CondBroadcast, "CondBroadcast")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CondBroadcast)
{
#if 0
	SDL_CondBroadcast();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondBroadcast");
	return Value::Null;
}

// sdl2.CondSignal
Gura_DeclareFunctionAlias(__CondSignal, "CondSignal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CondSignal)
{
#if 0
	SDL_CondSignal();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondSignal");
	return Value::Null;
}

// sdl2.CondWait
Gura_DeclareFunctionAlias(__CondWait, "CondWait")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CondWait)
{
#if 0
	SDL_CondWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondWait");
	return Value::Null;
}

// sdl2.CondWaitTimeout
Gura_DeclareFunctionAlias(__CondWaitTimeout, "CondWaitTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CondWaitTimeout)
{
#if 0
	SDL_CondWaitTimeout();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CondWaitTimeout");
	return Value::Null;
}

// sdl2.CreateCond
Gura_DeclareFunctionAlias(__CreateCond, "CreateCond")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateCond)
{
#if 0
	SDL_CreateCond();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateCond");
	return Value::Null;
}

// sdl2.CreateMutex
Gura_DeclareFunctionAlias(__CreateMutex, "CreateMutex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateMutex)
{
#if 0
	SDL_CreateMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateMutex");
	return Value::Null;
}

// sdl2.CreateSemaphore
Gura_DeclareFunctionAlias(__CreateSemaphore, "CreateSemaphore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CreateSemaphore)
{
#if 0
	SDL_CreateSemaphore();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CreateSemaphore");
	return Value::Null;
}

// sdl2.DestroyCond
Gura_DeclareFunctionAlias(__DestroyCond, "DestroyCond")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DestroyCond)
{
#if 0
	SDL_DestroyCond();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DestroyCond");
	return Value::Null;
}

// sdl2.DestroyMutex
Gura_DeclareFunctionAlias(__DestroyMutex, "DestroyMutex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DestroyMutex)
{
#if 0
	SDL_DestroyMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DestroyMutex");
	return Value::Null;
}

// sdl2.DestroySemaphore
Gura_DeclareFunctionAlias(__DestroySemaphore, "DestroySemaphore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__DestroySemaphore)
{
#if 0
	SDL_DestroySemaphore();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "DestroySemaphore");
	return Value::Null;
}

// sdl2.LockMutex
Gura_DeclareFunctionAlias(__LockMutex, "LockMutex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__LockMutex)
{
#if 0
	SDL_LockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "LockMutex");
	return Value::Null;
}

// sdl2.SemPost
Gura_DeclareFunctionAlias(__SemPost, "SemPost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SemPost)
{
#if 0
	SDL_SemPost();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemPost");
	return Value::Null;
}

// sdl2.SemTryWait
Gura_DeclareFunctionAlias(__SemTryWait, "SemTryWait")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SemTryWait)
{
#if 0
	SDL_SemTryWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemTryWait");
	return Value::Null;
}

// sdl2.SemValue
Gura_DeclareFunctionAlias(__SemValue, "SemValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SemValue)
{
#if 0
	SDL_SemValue();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemValue");
	return Value::Null;
}

// sdl2.SemWait
Gura_DeclareFunctionAlias(__SemWait, "SemWait")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SemWait)
{
#if 0
	SDL_SemWait();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemWait");
	return Value::Null;
}

// sdl2.SemWaitTimeout
Gura_DeclareFunctionAlias(__SemWaitTimeout, "SemWaitTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SemWaitTimeout)
{
#if 0
	SDL_SemWaitTimeout();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SemWaitTimeout");
	return Value::Null;
}

// sdl2.TryLockMutex
Gura_DeclareFunctionAlias(__TryLockMutex, "TryLockMutex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__TryLockMutex)
{
#if 0
	SDL_TryLockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "TryLockMutex");
	return Value::Null;
}

// sdl2.UnlockMutex
Gura_DeclareFunctionAlias(__UnlockMutex, "UnlockMutex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__UnlockMutex)
{
#if 0
	SDL_UnlockMutex();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "UnlockMutex");
	return Value::Null;
}

// sdl2.AtomicAdd
Gura_DeclareFunctionAlias(__AtomicAdd, "AtomicAdd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicAdd)
{
#if 0
	SDL_AtomicAdd();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicAdd");
	return Value::Null;
}

// sdl2.AtomicCAS
Gura_DeclareFunctionAlias(__AtomicCAS, "AtomicCAS")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicCAS)
{
#if 0
	SDL_AtomicCAS();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicCAS");
	return Value::Null;
}

// sdl2.AtomicCASPtr
Gura_DeclareFunctionAlias(__AtomicCASPtr, "AtomicCASPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicCASPtr)
{
#if 0
	SDL_AtomicCASPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicCASPtr");
	return Value::Null;
}

// sdl2.AtomicDecRef
Gura_DeclareFunctionAlias(__AtomicDecRef, "AtomicDecRef")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicDecRef)
{
#if 0
	SDL_AtomicDecRef();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicDecRef");
	return Value::Null;
}

// sdl2.AtomicGet
Gura_DeclareFunctionAlias(__AtomicGet, "AtomicGet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicGet)
{
#if 0
	SDL_AtomicGet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicGet");
	return Value::Null;
}

// sdl2.AtomicGetPtr
Gura_DeclareFunctionAlias(__AtomicGetPtr, "AtomicGetPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicGetPtr)
{
#if 0
	SDL_AtomicGetPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicGetPtr");
	return Value::Null;
}

// sdl2.AtomicIncRef
Gura_DeclareFunctionAlias(__AtomicIncRef, "AtomicIncRef")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicIncRef)
{
#if 0
	SDL_AtomicIncRef();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicIncRef");
	return Value::Null;
}

// sdl2.AtomicLock
Gura_DeclareFunctionAlias(__AtomicLock, "AtomicLock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicLock)
{
#if 0
	SDL_AtomicLock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicLock");
	return Value::Null;
}

// sdl2.AtomicSet
Gura_DeclareFunctionAlias(__AtomicSet, "AtomicSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicSet)
{
#if 0
	SDL_AtomicSet();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicSet");
	return Value::Null;
}

// sdl2.AtomicSetPtr
Gura_DeclareFunctionAlias(__AtomicSetPtr, "AtomicSetPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicSetPtr)
{
#if 0
	SDL_AtomicSetPtr();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicSetPtr");
	return Value::Null;
}

// sdl2.AtomicTryLock
Gura_DeclareFunctionAlias(__AtomicTryLock, "AtomicTryLock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicTryLock)
{
#if 0
	SDL_AtomicTryLock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicTryLock");
	return Value::Null;
}

// sdl2.AtomicUnlock
Gura_DeclareFunctionAlias(__AtomicUnlock, "AtomicUnlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AtomicUnlock)
{
#if 0
	SDL_AtomicUnlock();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AtomicUnlock");
	return Value::Null;
}

// sdl2.CompilerBarrier
Gura_DeclareFunctionAlias(__CompilerBarrier, "CompilerBarrier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__CompilerBarrier)
{
#if 0
	SDL_CompilerBarrier();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "CompilerBarrier");
	return Value::Null;
}

// sdl2.AddTimer
Gura_DeclareFunctionAlias(__AddTimer, "AddTimer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "interval", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AddTimer)
{
#if 0
	Uint32 interval = args.GetULong(0);
	SDL_TimerID _rtn = SDL_AddTimer(interval);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "AddTimer");
	return Value::Null;
}

// sdl2.Delay
Gura_DeclareFunctionAlias(__Delay, "Delay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "ms", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__Delay)
{
	Uint32 ms = args.GetULong(0);
	SDL_Delay(ms);
	return Value::Null;
}

// sdl2.GetPerformanceCounter
Gura_DeclareFunctionAlias(__GetPerformanceCounter, "GetPerformanceCounter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetPerformanceCounter)
{
	Uint64 _rtn = SDL_GetPerformanceCounter();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetPerformanceFrequency
Gura_DeclareFunctionAlias(__GetPerformanceFrequency, "GetPerformanceFrequency")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetPerformanceFrequency)
{
	Uint64 _rtn = SDL_GetPerformanceFrequency();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetTicks
Gura_DeclareFunctionAlias(__GetTicks, "GetTicks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetTicks)
{
	Uint32 _rtn = SDL_GetTicks();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.RemoveTimer
Gura_DeclareFunctionAlias(__RemoveTimer, "RemoveTimer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RemoveTimer)
{
	SDL_TimerID id = static_cast<SDL_TimerID>(args.GetInt(0));
	SDL_bool _rtn = SDL_RemoveTimer(id);
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.TICKS_PASSED
Gura_DeclareFunctionAlias(__TICKS_PASSED, "TICKS_PASSED")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "A", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "B", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__TICKS_PASSED)
{
	Uint32 A = args.GetULong(0);
	Uint32 B = args.GetULong(1);
	bool _rtn = SDL_TICKS_PASSED(A, B);
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetBasePath
Gura_DeclareFunctionAlias(__GetBasePath, "GetBasePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetBasePath)
{
#if 0
	char *_rtn = SDL_GetBasePath();
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
		// free buffer of _rtn
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
Gura_DeclareFunctionAlias(__GetPrefPath, "GetPrefPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "org", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "app", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetPrefPath)
{
#if 0
	const char *org = args.GetString(0);
	const char *app = args.GetString(1);
	char *_rtn = SDL_GetPrefPath(org, app);
	Value _rtnVal;
	if (_rtn != NULL) {
		_rtnVal = Value(_rtn);
		// free buffer of _rtn
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
Gura_DeclareFunctionAlias(__AllocRW, "AllocRW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AllocRW)
{
#if 0
	SDL_AllocRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AllocRW");
	return Value::Null;
}

// sdl2.FreeRW
Gura_DeclareFunctionAlias(__FreeRW, "FreeRW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__FreeRW)
{
#if 0
	SDL_FreeRW();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "FreeRW");
	return Value::Null;
}

// sdl2.RWFromConstMem
Gura_DeclareFunctionAlias(__RWFromConstMem, "RWFromConstMem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWFromConstMem)
{
#if 0
	SDL_RWFromConstMem();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromConstMem");
	return Value::Null;
}

// sdl2.RWFromFP
Gura_DeclareFunctionAlias(__RWFromFP, "RWFromFP")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWFromFP)
{
#if 0
	SDL_RWFromFP();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromFP");
	return Value::Null;
}

// sdl2.RWFromFile
Gura_DeclareFunctionAlias(__RWFromFile, "RWFromFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWFromFile)
{
#if 0
	SDL_RWFromFile();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromFile");
	return Value::Null;
}

// sdl2.RWFromMem
Gura_DeclareFunctionAlias(__RWFromMem, "RWFromMem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWFromMem)
{
#if 0
	SDL_RWFromMem();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWFromMem");
	return Value::Null;
}

// sdl2.RWclose
Gura_DeclareFunctionAlias(__RWclose, "RWclose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWclose)
{
#if 0
	SDL_RWclose();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWclose");
	return Value::Null;
}

// sdl2.RWread
Gura_DeclareFunctionAlias(__RWread, "RWread")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWread)
{
#if 0
	SDL_RWread();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWread");
	return Value::Null;
}

// sdl2.RWseek
Gura_DeclareFunctionAlias(__RWseek, "RWseek")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWseek)
{
#if 0
	SDL_RWseek();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWseek");
	return Value::Null;
}

// sdl2.RWtell
Gura_DeclareFunctionAlias(__RWtell, "RWtell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWtell)
{
#if 0
	SDL_RWtell();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWtell");
	return Value::Null;
}

// sdl2.RWwrite
Gura_DeclareFunctionAlias(__RWwrite, "RWwrite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__RWwrite)
{
#if 0
	SDL_RWwrite();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "RWwrite");
	return Value::Null;
}

// sdl2.ReadBE16
Gura_DeclareFunctionAlias(__ReadBE16, "ReadBE16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ReadBE16)
{
#if 0
	SDL_ReadBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadBE16");
	return Value::Null;
}

// sdl2.ReadBE32
Gura_DeclareFunctionAlias(__ReadBE32, "ReadBE32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ReadBE32)
{
#if 0
	SDL_ReadBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadBE32");
	return Value::Null;
}

// sdl2.ReadBE64
Gura_DeclareFunctionAlias(__ReadBE64, "ReadBE64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ReadBE64)
{
#if 0
	SDL_ReadBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadBE64");
	return Value::Null;
}

// sdl2.ReadLE16
Gura_DeclareFunctionAlias(__ReadLE16, "ReadLE16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ReadLE16)
{
#if 0
	SDL_ReadLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadLE16");
	return Value::Null;
}

// sdl2.ReadLE32
Gura_DeclareFunctionAlias(__ReadLE32, "ReadLE32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ReadLE32)
{
#if 0
	SDL_ReadLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadLE32");
	return Value::Null;
}

// sdl2.ReadLE64
Gura_DeclareFunctionAlias(__ReadLE64, "ReadLE64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__ReadLE64)
{
#if 0
	SDL_ReadLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "ReadLE64");
	return Value::Null;
}

// sdl2.WriteBE16
Gura_DeclareFunctionAlias(__WriteBE16, "WriteBE16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WriteBE16)
{
#if 0
	SDL_WriteBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteBE16");
	return Value::Null;
}

// sdl2.WriteBE32
Gura_DeclareFunctionAlias(__WriteBE32, "WriteBE32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WriteBE32)
{
#if 0
	SDL_WriteBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteBE32");
	return Value::Null;
}

// sdl2.WriteBE64
Gura_DeclareFunctionAlias(__WriteBE64, "WriteBE64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WriteBE64)
{
#if 0
	SDL_WriteBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteBE64");
	return Value::Null;
}

// sdl2.WriteLE16
Gura_DeclareFunctionAlias(__WriteLE16, "WriteLE16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WriteLE16)
{
#if 0
	SDL_WriteLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteLE16");
	return Value::Null;
}

// sdl2.WriteLE32
Gura_DeclareFunctionAlias(__WriteLE32, "WriteLE32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WriteLE32)
{
#if 0
	SDL_WriteLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteLE32");
	return Value::Null;
}

// sdl2.WriteLE64
Gura_DeclareFunctionAlias(__WriteLE64, "WriteLE64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__WriteLE64)
{
#if 0
	SDL_WriteLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "WriteLE64");
	return Value::Null;
}

// sdl2.GetPlatform
Gura_DeclareFunctionAlias(__GetPlatform, "GetPlatform")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetPlatform)
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
Gura_DeclareFunctionAlias(__GetCPUCacheLineSize, "GetCPUCacheLineSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetCPUCacheLineSize)
{
	int _rtn = SDL_GetCPUCacheLineSize();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetCPUCount
Gura_DeclareFunctionAlias(__GetCPUCount, "GetCPUCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetCPUCount)
{
	int _rtn = SDL_GetCPUCount();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.GetSystemRAM
Gura_DeclareFunctionAlias(__GetSystemRAM, "GetSystemRAM")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetSystemRAM)
{
	int _rtn = SDL_GetSystemRAM();
	return ReturnValue(env, sig, args, Value(_rtn));
}

// sdl2.Has3DNow
Gura_DeclareFunctionAlias(__Has3DNow, "Has3DNow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__Has3DNow)
{
	SDL_bool _rtn = SDL_Has3DNow();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasAVX
Gura_DeclareFunctionAlias(__HasAVX, "HasAVX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasAVX)
{
	SDL_bool _rtn = SDL_HasAVX();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasAVX2
Gura_DeclareFunctionAlias(__HasAVX2, "HasAVX2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasAVX2)
{
#if 0
	SDL_bool _rtn = SDL_HasAVX2();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "HasAVX2");
	return Value::Null;
}

// sdl2.HasAltiVec
Gura_DeclareFunctionAlias(__HasAltiVec, "HasAltiVec")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasAltiVec)
{
	SDL_bool _rtn = SDL_HasAltiVec();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasMMX
Gura_DeclareFunctionAlias(__HasMMX, "HasMMX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasMMX)
{
	SDL_bool _rtn = SDL_HasMMX();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasRDTSC
Gura_DeclareFunctionAlias(__HasRDTSC, "HasRDTSC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasRDTSC)
{
	SDL_bool _rtn = SDL_HasRDTSC();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasSSE
Gura_DeclareFunctionAlias(__HasSSE, "HasSSE")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasSSE)
{
	SDL_bool _rtn = SDL_HasSSE();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasSSE2
Gura_DeclareFunctionAlias(__HasSSE2, "HasSSE2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasSSE2)
{
	SDL_bool _rtn = SDL_HasSSE2();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasSSE3
Gura_DeclareFunctionAlias(__HasSSE3, "HasSSE3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasSSE3)
{
	SDL_bool _rtn = SDL_HasSSE3();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasSSE41
Gura_DeclareFunctionAlias(__HasSSE41, "HasSSE41")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasSSE41)
{
	SDL_bool _rtn = SDL_HasSSE41();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.HasSSE42
Gura_DeclareFunctionAlias(__HasSSE42, "HasSSE42")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__HasSSE42)
{
	SDL_bool _rtn = SDL_HasSSE42();
	return ReturnValue(env, sig, args, Value(_rtn != SDL_FALSE));
}

// sdl2.Swap16
Gura_DeclareFunctionAlias(__Swap16, "Swap16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__Swap16)
{
#if 0
	SDL_Swap16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Swap16");
	return Value::Null;
}

// sdl2.Swap32
Gura_DeclareFunctionAlias(__Swap32, "Swap32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__Swap32)
{
#if 0
	SDL_Swap32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Swap32");
	return Value::Null;
}

// sdl2.Swap64
Gura_DeclareFunctionAlias(__Swap64, "Swap64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__Swap64)
{
#if 0
	SDL_Swap64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "Swap64");
	return Value::Null;
}

// sdl2.SwapBE16
Gura_DeclareFunctionAlias(__SwapBE16, "SwapBE16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapBE16)
{
#if 0
	SDL_SwapBE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapBE16");
	return Value::Null;
}

// sdl2.SwapBE32
Gura_DeclareFunctionAlias(__SwapBE32, "SwapBE32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapBE32)
{
#if 0
	SDL_SwapBE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapBE32");
	return Value::Null;
}

// sdl2.SwapBE64
Gura_DeclareFunctionAlias(__SwapBE64, "SwapBE64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapBE64)
{
#if 0
	SDL_SwapBE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapBE64");
	return Value::Null;
}

// sdl2.SwapFloat
Gura_DeclareFunctionAlias(__SwapFloat, "SwapFloat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapFloat)
{
#if 0
	SDL_SwapFloat();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapFloat");
	return Value::Null;
}

// sdl2.SwapFloatBE
Gura_DeclareFunctionAlias(__SwapFloatBE, "SwapFloatBE")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapFloatBE)
{
#if 0
	SDL_SwapFloatBE();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapFloatBE");
	return Value::Null;
}

// sdl2.SwapFloatLE
Gura_DeclareFunctionAlias(__SwapFloatLE, "SwapFloatLE")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapFloatLE)
{
#if 0
	SDL_SwapFloatLE();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapFloatLE");
	return Value::Null;
}

// sdl2.SwapLE16
Gura_DeclareFunctionAlias(__SwapLE16, "SwapLE16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapLE16)
{
#if 0
	SDL_SwapLE16();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapLE16");
	return Value::Null;
}

// sdl2.SwapLE32
Gura_DeclareFunctionAlias(__SwapLE32, "SwapLE32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapLE32)
{
#if 0
	SDL_SwapLE32();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapLE32");
	return Value::Null;
}

// sdl2.SwapLE64
Gura_DeclareFunctionAlias(__SwapLE64, "SwapLE64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__SwapLE64)
{
#if 0
	SDL_SwapLE64();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SwapLE64");
	return Value::Null;
}

// sdl2.MostSignificantBitIndex32
Gura_DeclareFunctionAlias(__MostSignificantBitIndex32, "MostSignificantBitIndex32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__MostSignificantBitIndex32)
{
#if 0
	Uint32 x = args.GetULong(0);
	int _rtn = SDL_MostSignificantBitIndex32(x);
	return ReturnValue(env, sig, args, Value(_rtn));
#endif
	SetError_NotImpFunction(sig, "MostSignificantBitIndex32");
	return Value::Null;
}

// sdl2.GetPowerInfo
Gura_DeclareFunctionAlias(__GetPowerInfo, "GetPowerInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__GetPowerInfo)
{
	int secs = 0;
	int pct = 0;
	SDL_PowerState _rtn = SDL_GetPowerInfo(&secs, &pct);
	return ReturnValue(env, sig, args, Value::CreateList(env,
									Value(_rtn), Value(secs), Value(pct)));
}

// sdl2.AndroidGetActivity
Gura_DeclareFunctionAlias(__AndroidGetActivity, "AndroidGetActivity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AndroidGetActivity)
{
#if 0
	SDL_AndroidGetActivity();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetActivity");
	return Value::Null;
}

// sdl2.AndroidGetExternalStoragePath
Gura_DeclareFunctionAlias(__AndroidGetExternalStoragePath, "AndroidGetExternalStoragePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AndroidGetExternalStoragePath)
{
#if 0
	SDL_AndroidGetExternalStoragePath();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetExternalStoragePath");
	return Value::Null;
}

// sdl2.AndroidGetExternalStorageState
Gura_DeclareFunctionAlias(__AndroidGetExternalStorageState, "AndroidGetExternalStorageState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AndroidGetExternalStorageState)
{
#if 0
	SDL_AndroidGetExternalStorageState();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetExternalStorageState");
	return Value::Null;
}

// sdl2.AndroidGetInternalStoragePath
Gura_DeclareFunctionAlias(__AndroidGetInternalStoragePath, "AndroidGetInternalStoragePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AndroidGetInternalStoragePath)
{
#if 0
	SDL_AndroidGetInternalStoragePath();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetInternalStoragePath");
	return Value::Null;
}

// sdl2.AndroidGetJNIEnv
Gura_DeclareFunctionAlias(__AndroidGetJNIEnv, "AndroidGetJNIEnv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__AndroidGetJNIEnv)
{
#if 0
	SDL_AndroidGetJNIEnv();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "AndroidGetJNIEnv");
	return Value::Null;
}

// sdl2.acos
Gura_DeclareFunctionAlias(__acos, "acos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(__acos)
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
	Gura_AssignFunction(__Init);
	Gura_AssignFunction(__InitSubSystem);
	Gura_AssignFunction(__Quit);
	Gura_AssignFunction(__QuitSubSystem);
	Gura_AssignFunction(__SetMainReady);
	Gura_AssignFunction(__WasInit);
	Gura_AssignFunction(__AddHintCallback);
	Gura_AssignFunction(__ClearHints);
	Gura_AssignFunction(__DelhintCallback);
	Gura_AssignFunction(__GetHint);
	Gura_AssignFunction(__SetHint);
	Gura_AssignFunction(__SetHintWithPriority);
	Gura_AssignFunction(__ClearError);
	Gura_AssignFunction(__GetError);
	Gura_AssignFunction(__SetError);
	Gura_AssignFunction(__Log);
	Gura_AssignFunction(__LogCritical);
	Gura_AssignFunction(__LogDebug);
	Gura_AssignFunction(__LogError);
	Gura_AssignFunction(__LogGetOutputFunction);
	Gura_AssignFunction(__LogGetPriority);
	Gura_AssignFunction(__LogInfo);
	Gura_AssignFunction(__LogMessage);
	Gura_AssignFunction(__LogMessageV);
	Gura_AssignFunction(__LogResetPriorities);
	Gura_AssignFunction(__LogSetAllPriority);
	Gura_AssignFunction(__LogSetOutputFunction);
	Gura_AssignFunction(__LogSetPriority);
	Gura_AssignFunction(__LogVerbose);
	Gura_AssignFunction(__LogWarn);
	Gura_AssignFunction(__GetAssertionHandler);
	Gura_AssignFunction(__GetAssertionReport);
	Gura_AssignFunction(__GetDefaultAssertionHandler);
	Gura_AssignFunction(__ResetAssertionReport);
	Gura_AssignFunction(__SetAssertionHandler);
	Gura_AssignFunction(__TriggerBreakpoint);
	Gura_AssignFunction(__assert);
	Gura_AssignFunction(__assert_paranoid);
	Gura_AssignFunction(__assert_release);
	Gura_AssignFunction(__GetRevision);
	Gura_AssignFunction(__GetRevisionNumber);
	Gura_AssignFunction(__GetVersion);
	Gura_AssignFunction(__VERSION);
	Gura_AssignFunction(__VERSION_ATLEAST);
	Gura_AssignFunction(__CreateWindow);
	Gura_AssignFunction(__CreateWindowAndRenderer);
	Gura_AssignFunction(__CreateWindowFrom);
	Gura_AssignFunction(__DestroyWindow);
	Gura_AssignFunction(__DisableScreenSaver);
	Gura_AssignFunction(__EnableScreenSaver);
	Gura_AssignFunction(__GL_CreateContext);
	Gura_AssignFunction(__GL_DeleteContext);
	Gura_AssignFunction(__GL_ExtensionSupported);
	Gura_AssignFunction(__GL_GetAttribute);
	Gura_AssignFunction(__GL_GetCurrentContext);
	Gura_AssignFunction(__GL_GetCurrentWindow);
	Gura_AssignFunction(__GL_GetDrawableSize);
	Gura_AssignFunction(__GL_GetProcAddress);
	Gura_AssignFunction(__GL_GetSwapInterval);
	Gura_AssignFunction(__GL_LoadLibrary);
	Gura_AssignFunction(__GL_MakeCurrent);
	Gura_AssignFunction(__GL_ResetAttributes);
	Gura_AssignFunction(__GL_SetAttribute);
	Gura_AssignFunction(__GL_SetSwapInterval);
	Gura_AssignFunction(__GL_SwapWindow);
	Gura_AssignFunction(__GL_UnloadLibrary);
	Gura_AssignFunction(__GetClosestDisplayMode);
	Gura_AssignFunction(__GetCurrentDisplayMode);
	Gura_AssignFunction(__GetCurrentVideoDriver);
	Gura_AssignFunction(__GetDesktopDisplayMode);
	Gura_AssignFunction(__GetDisplayBounds);
	Gura_AssignFunction(__GetDisplayMode);
	Gura_AssignFunction(__GetDisplayName);
	Gura_AssignFunction(__GetNumDisplayModes);
	Gura_AssignFunction(__GetNumVideoDisplays);
	Gura_AssignFunction(__GetNumVideoDrivers);
	Gura_AssignFunction(__GetVideoDriver);
	Gura_AssignFunction(__GetWindowBrightness);
	Gura_AssignFunction(__GetWindowData);
	Gura_AssignFunction(__GetWindowDisplayIndex);
	Gura_AssignFunction(__GetWindowDisplayMode);
	Gura_AssignFunction(__GetWindowFlags);
	Gura_AssignFunction(__GetWindowFromID);
	Gura_AssignFunction(__GetWindowGammaRamp);
	Gura_AssignFunction(__GetWindowGrab);
	Gura_AssignFunction(__GetWindowID);
	Gura_AssignFunction(__GetWindowMaximumSize);
	Gura_AssignFunction(__GetWindowMinimumSize);
	Gura_AssignFunction(__GetWindowPixelFormat);
	Gura_AssignFunction(__GetWindowPosition);
	Gura_AssignFunction(__GetWindowSize);
	Gura_AssignFunction(__GetWindowSurface);
	Gura_AssignFunction(__GetWindowTitle);
	Gura_AssignFunction(__GetWindowWMInfo);
	Gura_AssignFunction(__HideWindow);
	Gura_AssignFunction(__IsScreenSaverEnabled);
	Gura_AssignFunction(__MaximizeWindow);
	Gura_AssignFunction(__MinimizeWindow);
	Gura_AssignFunction(__RaiseWindow);
	Gura_AssignFunction(__RestoreWindow);
	Gura_AssignFunction(__SetWindowBordered);
	Gura_AssignFunction(__SetWindowBrightness);
	Gura_AssignFunction(__SetWindowData);
	Gura_AssignFunction(__SetWindowDisplayMode);
	Gura_AssignFunction(__SetWindowFullscreen);
	Gura_AssignFunction(__SetWindowGammaRamp);
	Gura_AssignFunction(__SetWindowGrab);
	Gura_AssignFunction(__SetWindowHitTest);
	Gura_AssignFunction(__SetWindowIcon);
	Gura_AssignFunction(__SetWindowMaximumSize);
	Gura_AssignFunction(__SetWindowMinimumSize);
	Gura_AssignFunction(__SetWindowPosition);
	Gura_AssignFunction(__SetWindowSize);
	Gura_AssignFunction(__SetWindowTitle);
	Gura_AssignFunction(__ShowMessageBox);
	Gura_AssignFunction(__ShowSimpleMessageBox);
	Gura_AssignFunction(__ShowWindow);
	Gura_AssignFunction(__UpdateWindowSurface);
	Gura_AssignFunction(__UpdateWindowSurfaceRects);
	Gura_AssignFunction(__VideoInit);
	Gura_AssignFunction(__VideoQuit);
	Gura_AssignFunction(__CreateRenderer);
	Gura_AssignFunction(__CreateSoftwareRenderer);
	Gura_AssignFunction(__CreateTexture);
	Gura_AssignFunction(__CreateTextureFromSurface);
	Gura_AssignFunction(__DestroyRenderer);
	Gura_AssignFunction(__DestroyTexture);
	Gura_AssignFunction(__GL_BindTexture);
	Gura_AssignFunction(__GL_UnbindTexture);
	Gura_AssignFunction(__GetNumRenderDrivers);
	Gura_AssignFunction(__GetRenderDrawBlendMode);
	Gura_AssignFunction(__GetRenderDrawColor);
	Gura_AssignFunction(__GetRenderDriverInfo);
	Gura_AssignFunction(__GetRenderTarget);
	Gura_AssignFunction(__GetRenderer);
	Gura_AssignFunction(__GetRendererInfo);
	Gura_AssignFunction(__GetRenderOutputSize);
	Gura_AssignFunction(__GetTextureAlphaMod);
	Gura_AssignFunction(__GetTextureBlendMode);
	Gura_AssignFunction(__GetTextureColorMod);
	Gura_AssignFunction(__LockTexture);
	Gura_AssignFunction(__QueryTexture);
	Gura_AssignFunction(__RenderClear);
	Gura_AssignFunction(__RenderCopy);
	Gura_AssignFunction(__RenderCopyEx);
	Gura_AssignFunction(__RenderDrawLine);
	Gura_AssignFunction(__RenderDrawLines);
	Gura_AssignFunction(__RenderDrawPoint);
	Gura_AssignFunction(__RenderDrawPoints);
	Gura_AssignFunction(__RenderDrawRect);
	Gura_AssignFunction(__RenderDrawRects);
	Gura_AssignFunction(__RenderFillRect);
	Gura_AssignFunction(__RenderFillRects);
	Gura_AssignFunction(__RenderGetClipRect);
	Gura_AssignFunction(__RenderGetLogicalSize);
	Gura_AssignFunction(__RenderGetScale);
	Gura_AssignFunction(__RenderGetViewport);
	Gura_AssignFunction(__RenderIsClipEnabled);
	Gura_AssignFunction(__RenderPresent);
	Gura_AssignFunction(__RenderReadPixels);
	Gura_AssignFunction(__RenderSetClipRect);
	Gura_AssignFunction(__RenderSetLogicalSize);
	Gura_AssignFunction(__RenderSetScale);
	Gura_AssignFunction(__RenderSetViewport);
	Gura_AssignFunction(__RenderTargetSupported);
	Gura_AssignFunction(__SetRenderDrawBlendMode);
	Gura_AssignFunction(__SetRenderDrawColor);
	Gura_AssignFunction(__SetRenderTarget);
	Gura_AssignFunction(__SetTextureAlphaMod);
	Gura_AssignFunction(__SetTextureBlendMode);
	Gura_AssignFunction(__SetTextureColorMod);
	Gura_AssignFunction(__UnlockTexture);
	Gura_AssignFunction(__UpdateTexture);
	Gura_AssignFunction(__UpdateYUVTexture);
	Gura_AssignFunction(__AllocFormat);
	Gura_AssignFunction(__AllocPalette);
	Gura_AssignFunction(__CalculateGammaRamp);
	Gura_AssignFunction(__FreeFormat);
	Gura_AssignFunction(__FreePalette);
	Gura_AssignFunction(__GetPixelFormatName);
	Gura_AssignFunction(__GetRGB);
	Gura_AssignFunction(__GetRGBA);
	Gura_AssignFunction(__MapRGB);
	Gura_AssignFunction(__MapRGBA);
	Gura_AssignFunction(__MasksToPixelFormatEnum);
	Gura_AssignFunction(__PixelFormatEnumToMasks);
	Gura_AssignFunction(__SetPaletteColors);
	Gura_AssignFunction(__SetPixelFormatPalette);
	Gura_AssignFunction(__EnclosePoints);
	Gura_AssignFunction(__HasIntersection);
	Gura_AssignFunction(__IntersectRect);
	Gura_AssignFunction(__IntersectRectAndLine);
	Gura_AssignFunction(__PointInRect);
	Gura_AssignFunction(__RectEmpty);
	Gura_AssignFunction(__RectEquals);
	Gura_AssignFunction(__UnionRect);
	Gura_AssignFunction(__BlitScaled);
	Gura_AssignFunction(__BlitSurface);
	Gura_AssignFunction(__ConvertPixels);
	Gura_AssignFunction(__ConvertSurface);
	Gura_AssignFunction(__ConvertSurfaceFormat);
	Gura_AssignFunction(__CreateRGBSurface);
	Gura_AssignFunction(__CreateRGBSurfaceFrom);
	Gura_AssignFunction(__CreateRGBSurfaceFromImage);
	Gura_AssignFunction(__FillRect);
	Gura_AssignFunction(__FillRects);
	Gura_AssignFunction(__FreeSurface);
	Gura_AssignFunction(__GetClipRect);
	Gura_AssignFunction(__GetColorKey);
	Gura_AssignFunction(__GetSurfaceAlphaMod);
	Gura_AssignFunction(__GetSurfaceBlendMode);
	Gura_AssignFunction(__GetSurfaceColorMod);
	Gura_AssignFunction(__LoadBMP);
	Gura_AssignFunction(__LoadBMP_RW);
	Gura_AssignFunction(__LockSurface);
	Gura_AssignFunction(__LowerBlit);
	Gura_AssignFunction(__LowerBlitScaled);
	Gura_AssignFunction(__MUSTLOCK);
	Gura_AssignFunction(__SaveBMP);
	Gura_AssignFunction(__SaveBMP_RW);
	Gura_AssignFunction(__SetClipRect);
	Gura_AssignFunction(__SetColorKey);
	Gura_AssignFunction(__SetSurfaceAlphaMod);
	Gura_AssignFunction(__SetSurfaceBlendMode);
	Gura_AssignFunction(__SetSurfaceColorMod);
	Gura_AssignFunction(__SetSurfacePalette);
	Gura_AssignFunction(__SetSurfaceRLE);
	Gura_AssignFunction(__UnlockSurface);
	Gura_AssignFunction(__GetClipboardText);
	Gura_AssignFunction(__HasClipboardText);
	Gura_AssignFunction(__SetClipboardText);
	Gura_AssignFunction(__AddEventWatch);
	Gura_AssignFunction(__DelEventWatch);
	Gura_AssignFunction(__EventState);
	Gura_AssignFunction(__FilterEvents);
	Gura_AssignFunction(__FlushEvent);
	Gura_AssignFunction(__FlushEvents);
	Gura_AssignFunction(__GetEventFilter);
	Gura_AssignFunction(__GetNumTouchDevices);
	Gura_AssignFunction(__GetNumTouchFingers);
	Gura_AssignFunction(__GetTouchDevice);
	Gura_AssignFunction(__GetTouchFinger);
	Gura_AssignFunction(__HasEvent);
	Gura_AssignFunction(__HasEvents);
	Gura_AssignFunction(__LoadDollarTemplates);
	Gura_AssignFunction(__AddEvents);
	Gura_AssignFunction(__PeekEvents);
	Gura_AssignFunction(__GetEvents);
	Gura_AssignFunction(__PollEvent);
	Gura_AssignFunction(__PumpEvents);
	Gura_AssignFunction(__PushEvent);
	Gura_AssignFunction(__QuitRequested);
	Gura_AssignFunction(__RecordGesture);
	Gura_AssignFunction(__RegisterEvents);
	Gura_AssignFunction(__SaveAllDollarTemplates);
	Gura_AssignFunction(__SaveDollarTemplate);
	Gura_AssignFunction(__SetEventFilter);
	Gura_AssignFunction(__WaitEvent);
	Gura_AssignFunction(__WaitEventTimeout);
	Gura_AssignFunction(__CheckKeyboardState);
	Gura_AssignFunction(__GetKeyFromName);
	Gura_AssignFunction(__GetKeyFromScancode);
	Gura_AssignFunction(__GetKeyName);
	Gura_AssignFunction(__GetKeyboardFocus);
	Gura_AssignFunction(__GetKeyboardState);
	Gura_AssignFunction(__GetModState);
	Gura_AssignFunction(__GetScancodeFromKey);
	Gura_AssignFunction(__GetScancodeFromName);
	Gura_AssignFunction(__GetScancodeName);
	Gura_AssignFunction(__HasScreenKeyboardSupport);
	Gura_AssignFunction(__IsScreenKeyboardShown);
	Gura_AssignFunction(__IsTextInputActive);
	Gura_AssignFunction(__SetModState);
	Gura_AssignFunction(__SetTextInputRect);
	Gura_AssignFunction(__StartTextInput);
	Gura_AssignFunction(__StopTextInput);
	Gura_AssignFunction(__CaptureMouse);
	Gura_AssignFunction(__CreateColorCursor);
	Gura_AssignFunction(__CreateCursor);
	Gura_AssignFunction(__CreateSystemCursor);
	Gura_AssignFunction(__FreeCursor);
	Gura_AssignFunction(__GetCursor);
	Gura_AssignFunction(__GetDefaultCursor);
	Gura_AssignFunction(__GetGlobalMouseState);
	Gura_AssignFunction(__GetMouseFocus);
	Gura_AssignFunction(__GetMouseState);
	Gura_AssignFunction(__GetRelativeMouseMode);
	Gura_AssignFunction(__GetRelativeMouseState);
	Gura_AssignFunction(__SetCursor);
	Gura_AssignFunction(__SetRelativeMouseMode);
	Gura_AssignFunction(__ShowCursor);
	Gura_AssignFunction(__WarpMouseGlobal);
	Gura_AssignFunction(__WarpMouseInWindow);
	Gura_AssignFunction(__JoystickClose);
	Gura_AssignFunction(__JoystickEventState);
	Gura_AssignFunction(__JoystickGetAttached);
	Gura_AssignFunction(__JoystickGetAxis);
	Gura_AssignFunction(__JoystickGetBall);
	Gura_AssignFunction(__JoystickGetButton);
	Gura_AssignFunction(__JoystickGetDeviceGUID);
	Gura_AssignFunction(__JoystickGetGUID);
	Gura_AssignFunction(__JoystickGetGUIDFromString);
	Gura_AssignFunction(__JoystickGetGUIDString);
	Gura_AssignFunction(__JoystickGetHat);
	Gura_AssignFunction(__JoystickInstanceID);
	Gura_AssignFunction(__JoystickName);
	Gura_AssignFunction(__JoystickNameForIndex);
	Gura_AssignFunction(__JoystickNumAxes);
	Gura_AssignFunction(__JoystickNumBalls);
	Gura_AssignFunction(__JoystickNumButtons);
	Gura_AssignFunction(__JoystickNumHats);
	Gura_AssignFunction(__JoystickOpen);
	Gura_AssignFunction(__JoystickUpdate);
	Gura_AssignFunction(__NumJoysticks);
	Gura_AssignFunction(__GameControllerAddMapping);
	Gura_AssignFunction(__GameControllerAddMappingsFromFile);
	Gura_AssignFunction(__GameControllerAddMappingsFromRW);
	Gura_AssignFunction(__GameControllerClose);
	Gura_AssignFunction(__GameControllerEventState);
	Gura_AssignFunction(__GameControllerGetAttached);
	Gura_AssignFunction(__GameControllerGetAxis);
	Gura_AssignFunction(__GameControllerGetAxisFromString);
	Gura_AssignFunction(__GameControllerGetBindForAxis);
	Gura_AssignFunction(__GameControllerGetBindForButton);
	Gura_AssignFunction(__GameControllerGetButton);
	Gura_AssignFunction(__GameControllerGetButtonFromString);
	Gura_AssignFunction(__GameControllerGetJoystick);
	Gura_AssignFunction(__GameControllerGetStringForAxis);
	Gura_AssignFunction(__GameControllerGetStringForButton);
	Gura_AssignFunction(__GameControllerMapping);
	Gura_AssignFunction(__GameControllerMappingForGUID);
	Gura_AssignFunction(__GameControllerName);
	Gura_AssignFunction(__GameControllerNameForIndex);
	Gura_AssignFunction(__GameControllerOpen);
	Gura_AssignFunction(__GameControllerUpdate);
	Gura_AssignFunction(__IsGameController);
	Gura_AssignFunction(__HapticClose);
	Gura_AssignFunction(__HapticDestroyEffect);
	Gura_AssignFunction(__HapticEffectSupported);
	Gura_AssignFunction(__HapticGetEffectStatus);
	Gura_AssignFunction(__HapticIndex);
	Gura_AssignFunction(__HapticName);
	Gura_AssignFunction(__HapticNewEffect);
	Gura_AssignFunction(__HapticNumAxes);
	Gura_AssignFunction(__HapticNumEffects);
	Gura_AssignFunction(__HapticNumEffectsPlaying);
	Gura_AssignFunction(__HapticOpen);
	Gura_AssignFunction(__HapticOpenFromJoystick);
	Gura_AssignFunction(__HapticOpenFromMouse);
	Gura_AssignFunction(__HapticOpened);
	Gura_AssignFunction(__HapticPause);
	Gura_AssignFunction(__HapticQuery);
	Gura_AssignFunction(__HapticRumbleInit);
	Gura_AssignFunction(__HapticRumblePlay);
	Gura_AssignFunction(__HapticRumbleStop);
	Gura_AssignFunction(__HapticRumbleSupported);
	Gura_AssignFunction(__HapticRunEffect);
	Gura_AssignFunction(__HapticSetAutocenter);
	Gura_AssignFunction(__HapticSetGain);
	Gura_AssignFunction(__HapticStopAll);
	Gura_AssignFunction(__HapticStopEffect);
	Gura_AssignFunction(__HapticUnpause);
	Gura_AssignFunction(__HapticUpdateEffect);
	Gura_AssignFunction(__JoystickIsHaptic);
	Gura_AssignFunction(__MouseIsHaptic);
	Gura_AssignFunction(__NumHaptics);
	Gura_AssignFunction(__AudioInit);
	Gura_AssignFunction(__AudioQuit);
	Gura_AssignFunction(__BuildAudioCVT);
	Gura_AssignFunction(__ClearQueuedAudio);
	Gura_AssignFunction(__CloseAudio);
	Gura_AssignFunction(__CloseAudioDevice);
	Gura_AssignFunction(__ConvertAudio);
	Gura_AssignFunction(__FreeWAV);
	Gura_AssignFunction(__GetAudioDeviceName);
	Gura_AssignFunction(__GetAudioDeviceStatus);
	Gura_AssignFunction(__GetAudioDriver);
	Gura_AssignFunction(__GetAudioStatus);
	Gura_AssignFunction(__GetCurrentAudioDriver);
	Gura_AssignFunction(__GetNumAudioDevices);
	Gura_AssignFunction(__GetNumAudioDrivers);
	Gura_AssignFunction(__GetQueuedAudioSize);
	Gura_AssignFunction(__LoadWAV);
	Gura_AssignFunction(__LoadWAV_RW);
	Gura_AssignFunction(__LockAudio);
	Gura_AssignFunction(__LockAudioDevice);
	Gura_AssignFunction(__MixAudio);
	Gura_AssignFunction(__MixAudioFormat);
	Gura_AssignFunction(__OpenAudio);
	Gura_AssignFunction(__OpenAudioDevice);
	Gura_AssignFunction(__PauseAudio);
	Gura_AssignFunction(__PauseAudioDevice);
	Gura_AssignFunction(__QueueAudio);
	Gura_AssignFunction(__UnlockAudio);
	Gura_AssignFunction(__UnlockAudioDevice);
	Gura_AssignFunction(__AUDIO_BITSIZE);
	Gura_AssignFunction(__AUDIO_ISFLOAT);
	Gura_AssignFunction(__AUDIO_ISBIGENDIAN);
	Gura_AssignFunction(__AUDIO_ISSIGNED);
	Gura_AssignFunction(__AUDIO_ISINT);
	Gura_AssignFunction(__AUDIO_ISLITTLEENDIAN);
	Gura_AssignFunction(__AUDIO_ISUNSIGNED);
	Gura_AssignFunction(__CreateThread);
	Gura_AssignFunction(__DetachThread);
	Gura_AssignFunction(__GetThreadID);
	Gura_AssignFunction(__GetThreadName);
	Gura_AssignFunction(__GetThreadPriority);
	Gura_AssignFunction(__TLSCreate);
	Gura_AssignFunction(__TLSGet);
	Gura_AssignFunction(__TLSSet);
	Gura_AssignFunction(__ThreadID);
	Gura_AssignFunction(__WaitThread);
	Gura_AssignFunction(__CondBroadcast);
	Gura_AssignFunction(__CondSignal);
	Gura_AssignFunction(__CondWait);
	Gura_AssignFunction(__CondWaitTimeout);
	Gura_AssignFunction(__CreateCond);
	Gura_AssignFunction(__CreateMutex);
	Gura_AssignFunction(__CreateSemaphore);
	Gura_AssignFunction(__DestroyCond);
	Gura_AssignFunction(__DestroyMutex);
	Gura_AssignFunction(__DestroySemaphore);
	Gura_AssignFunction(__LockMutex);
	Gura_AssignFunction(__SemPost);
	Gura_AssignFunction(__SemTryWait);
	Gura_AssignFunction(__SemValue);
	Gura_AssignFunction(__SemWait);
	Gura_AssignFunction(__SemWaitTimeout);
	Gura_AssignFunction(__TryLockMutex);
	Gura_AssignFunction(__UnlockMutex);
	Gura_AssignFunction(__AtomicAdd);
	Gura_AssignFunction(__AtomicCAS);
	Gura_AssignFunction(__AtomicCASPtr);
	Gura_AssignFunction(__AtomicDecRef);
	Gura_AssignFunction(__AtomicGet);
	Gura_AssignFunction(__AtomicGetPtr);
	Gura_AssignFunction(__AtomicIncRef);
	Gura_AssignFunction(__AtomicLock);
	Gura_AssignFunction(__AtomicSet);
	Gura_AssignFunction(__AtomicSetPtr);
	Gura_AssignFunction(__AtomicTryLock);
	Gura_AssignFunction(__AtomicUnlock);
	Gura_AssignFunction(__CompilerBarrier);
	Gura_AssignFunction(__AddTimer);
	Gura_AssignFunction(__Delay);
	Gura_AssignFunction(__GetPerformanceCounter);
	Gura_AssignFunction(__GetPerformanceFrequency);
	Gura_AssignFunction(__GetTicks);
	Gura_AssignFunction(__RemoveTimer);
	Gura_AssignFunction(__TICKS_PASSED);
	Gura_AssignFunction(__GetBasePath);
	Gura_AssignFunction(__GetPrefPath);
	Gura_AssignFunction(__AllocRW);
	Gura_AssignFunction(__FreeRW);
	Gura_AssignFunction(__RWFromConstMem);
	Gura_AssignFunction(__RWFromFP);
	Gura_AssignFunction(__RWFromFile);
	Gura_AssignFunction(__RWFromMem);
	Gura_AssignFunction(__RWclose);
	Gura_AssignFunction(__RWread);
	Gura_AssignFunction(__RWseek);
	Gura_AssignFunction(__RWtell);
	Gura_AssignFunction(__RWwrite);
	Gura_AssignFunction(__ReadBE16);
	Gura_AssignFunction(__ReadBE32);
	Gura_AssignFunction(__ReadBE64);
	Gura_AssignFunction(__ReadLE16);
	Gura_AssignFunction(__ReadLE32);
	Gura_AssignFunction(__ReadLE64);
	Gura_AssignFunction(__WriteBE16);
	Gura_AssignFunction(__WriteBE32);
	Gura_AssignFunction(__WriteBE64);
	Gura_AssignFunction(__WriteLE16);
	Gura_AssignFunction(__WriteLE32);
	Gura_AssignFunction(__WriteLE64);
	Gura_AssignFunction(__GetPlatform);
	Gura_AssignFunction(__GetCPUCacheLineSize);
	Gura_AssignFunction(__GetCPUCount);
	Gura_AssignFunction(__GetSystemRAM);
	Gura_AssignFunction(__Has3DNow);
	Gura_AssignFunction(__HasAVX);
	Gura_AssignFunction(__HasAVX2);
	Gura_AssignFunction(__HasAltiVec);
	Gura_AssignFunction(__HasMMX);
	Gura_AssignFunction(__HasRDTSC);
	Gura_AssignFunction(__HasSSE);
	Gura_AssignFunction(__HasSSE2);
	Gura_AssignFunction(__HasSSE3);
	Gura_AssignFunction(__HasSSE41);
	Gura_AssignFunction(__HasSSE42);
	Gura_AssignFunction(__Swap16);
	Gura_AssignFunction(__Swap32);
	Gura_AssignFunction(__Swap64);
	Gura_AssignFunction(__SwapBE16);
	Gura_AssignFunction(__SwapBE32);
	Gura_AssignFunction(__SwapBE64);
	Gura_AssignFunction(__SwapFloat);
	Gura_AssignFunction(__SwapFloatBE);
	Gura_AssignFunction(__SwapFloatLE);
	Gura_AssignFunction(__SwapLE16);
	Gura_AssignFunction(__SwapLE32);
	Gura_AssignFunction(__SwapLE64);
	Gura_AssignFunction(__MostSignificantBitIndex32);
	Gura_AssignFunction(__GetPowerInfo);
	Gura_AssignFunction(__AndroidGetActivity);
	Gura_AssignFunction(__AndroidGetExternalStoragePath);
	Gura_AssignFunction(__AndroidGetExternalStorageState);
	Gura_AssignFunction(__AndroidGetInternalStoragePath);
	Gura_AssignFunction(__AndroidGetJNIEnv);
	Gura_AssignFunction(__acos);
	Gura_AssignFunction(test);
}

Gura_EndModuleScope(sdl2)
