//=============================================================================
// Gura module: sdl2
//=============================================================================
#include "stdafx.h"

#undef CreateWindow

#define RealizeClass(className) \
Gura_RealizeUserClassExWithoutPrepare(className, #className, env.LookupClass(VTYPE_object))

#define PrepareClass(className) \
Gura_UserClass(className)->Prepare(env)

#define Gura_AssignValueConst(name) Gura_AssignValue(name, Value(name))

#define Gura_AssignValueSDL(name) Gura_AssignValue(name, Value(SDL_##name))

#define Gura_AssignValueScancodeKeycode(name) \
Gura_AssignValue(SCANCODE_##name, Value(SDL_SCANCODE_##name));	\
Gura_AssignValue(K_##name, Value(SDLK_##name))

#define Gura_AssignValueScancodeKeycodeEx(nameScancode, nameKeycode) \
Gura_AssignValue(SCANCODE_##nameScancode, Value(SDL_SCANCODE_##nameScancode));	\
Gura_AssignValue(K_##nameKeycode, Value(SDLK_##nameKeycode))

#define Gura_AssignValueScancode(name) \
Gura_AssignValue(SCANCODE_##name, Value(SDL_SCANCODE_##name))

#define Gura_AssignValueKeycode(name) \
Gura_AssignValue(K_##name, Value(SDLK_##name))

Gura_BeginModuleBody(sdl2)

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
	int rtn = SDL_Init(flags);
	if (rtn < 0) {
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
	int rtn = SDL_InitSubSystem(flags);
	if (rtn < 0) {
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
	Uint32 rtn = SDL_WasInit(flags);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetError();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetRevision();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetRevisionNumber();
	return ReturnValue(env, sig, args, Value(rtn));
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
	bool rtn = SDL_VERSION_ATLEAST(X, Y, Z);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *title = args.IsValid(0)? args.GetString(0) : NULL;
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int w = args.GetInt(3);
	int h = args.GetInt(4);
	Uint32 flags = args.GetULong(5);
	SDL_Window *rtn = SDL_CreateWindow(title, x, y, w, h, flags);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(rtn)));
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
	int rtn = SDL_CreateWindowAndRenderer(width, height, window_flags, &window, &renderer);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_GLContext rtn = SDL_GL_CreateContext(window);
	return ReturnValue(env, sig, args, Value(new Object_GLContext(rtn)));
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
	const char *extension = args.IsValid(0)? args.GetString(0) : NULL;
	SDL_bool rtn = SDL_GL_ExtensionSupported(extension);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	int rtn = SDL_GL_GetAttribute(attr, &value);
	if (rtn < 0) {
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
	SDL_GLContext rtn = SDL_GL_GetCurrentContext();
	return ReturnValue(env, sig, args, Value(new Object_GLContext(rtn)));
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
	SDL_Window *rtn = SDL_GL_GetCurrentWindow();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(rtn)));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	int rtn = SDL_GL_GetSwapInterval();
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *path = args.IsValid(0)? args.GetString(0) : NULL;
	int rtn = SDL_GL_LoadLibrary(path);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_GLContext context = Object_GLContext::GetObject(args, 1)->GetEntity();
	int rtn = SDL_GL_MakeCurrent(window, context);
	if (rtn < 0) {
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
	int rtn = SDL_GL_SetAttribute(attr, value);
	if (rtn < 0) {
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
	int rtn = SDL_GL_SetSwapInterval(interval);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	const SDL_DisplayMode *mode = args.IsValid(1)? Object_DisplayMode::GetObject(args, 1)->GetEntity() : NULL;
	SDL_DisplayMode closest;
	SDL_DisplayMode* rtn = SDL_GetClosestDisplayMode(displayIndex, mode, &closest);
	if (rtn == NULL) {
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
	int rtn = SDL_GetCurrentDisplayMode(displayIndex, &mode);
	if (rtn < 0) {
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
	const char *rtn = SDL_GetCurrentVideoDriver();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetDesktopDisplayMode(displayIndex, &mode);
	if (rtn < 0) {
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
	int rtn = SDL_GetDisplayBounds(displayIndex, &rect);
	if (rtn < 0) {
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
	int rtn = SDL_GetDisplayMode(displayIndex, modeIndex, &mode);
	if (rtn < 0) {
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
	const char *rtn = SDL_GetDisplayName(dipslayIndex);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetNumDisplayModes(displayIndex);
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetNumVideoDisplays();
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetNumVideoDrivers();
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetVideoDriver(index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	float rtn = SDL_GetWindowBrightness(window);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	const char *name = args.IsValid(1)? args.GetString(1) : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_GetWindowDisplayIndex(window);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_DisplayMode *mode = args.IsValid(1)? Object_DisplayMode::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_GetWindowDisplayMode(window, mode);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 rtn = SDL_GetWindowFlags(window);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *rtn = SDL_GetWindowFromID(id);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(rtn)));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	Uint16 red = 0;
	Uint16 green = 0;
	Uint16 blue = 0;
	int rtn = SDL_GetWindowGammaRamp(window, &red, &green, &blue);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_bool rtn = SDL_GetWindowGrab(window);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 rtn = SDL_GetWindowID(window);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 rtn = SDL_GetWindowPixelFormat(window);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Surface *rtn = SDL_GetWindowSurface(window);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(rtn)));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	const char *rtn = SDL_GetWindowTitle(window);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_SysWMinfo info;
	SDL_bool rtn = SDL_GetWindowWMInfo(window, &info);
	if (rtn != SDL_TRUE) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_bool rtn = SDL_IsScreenSaverEnabled();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	float brightness = args.GetFloat(1);
	int rtn = SDL_SetWindowBrightness(window, brightness);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	const char *name = args.IsValid(1)? args.GetString(1) : NULL;
	void *userdata = args.IsValid(2)? NULL : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_DisplayMode *mode = args.IsValid(1)? Object_DisplayMode::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_SetWindowDisplayMode(window, mode);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 flags = args.GetULong(1);
	int rtn = SDL_SetWindowFullscreen(window, flags);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	CArray<Uint16> red(args.GetList(1));
	CArray<Uint16> green(args.GetList(2));
	CArray<Uint16> blue(args.GetList(3));
	if (red.GetSize() != 256 || green.GetSize() != 256 || blue.GetSize() != 256) {
		sig.SetError(ERR_ValueError, "red, green and blue must have 256 elements");
		return Value::Null;
	}
	int rtn = SDL_SetWindowGammaRamp(window, red, green, blue);
	if (rtn != SDL_TRUE) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_HitTest callback = NULL;
	void *callback_data = args.IsValid(2)? NULL : NULL;
	int rtn = SDL_SetWindowHitTest(window, callback, callback_data);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Surface *icon = args.IsValid(1)? Object_Surface::GetObject(args, 1)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	const char *title = args.IsValid(1)? args.GetString(1) : NULL;
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
	const SDL_MessageBoxData *messageboxdata = args.IsValid(0)? NULL : NULL;
	int *buttonid = args.IsValid(1)? NULL : NULL;
	int rtn = SDL_ShowMessageBox(messageboxdata, buttonid);
	if (rtn < 0) {
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
	const char *title = args.IsValid(1)? args.GetString(1) : NULL;
	const char *message = args.IsValid(2)? args.GetString(2) : NULL;
	SDL_Window *window = args.IsValid(3)? Object_Window::GetObject(args, 3)->GetEntity() : NULL;
	int rtn = SDL_ShowSimpleMessageBox(flags, title, message, window);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_UpdateWindowSurface(window);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int numrects = static_cast<int>(rects.GetSize());
	int rtn = SDL_UpdateWindowSurfaceRects(window, rects, numrects);
	if (rtn < 0) {
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
	const char *driver_name = args.IsValid(0)? args.GetString(0) : NULL;
	int rtn = SDL_VideoInit(driver_name);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	int index = args.GetInt(1);
	Uint32 flags = args.GetULong(2);
	SDL_Renderer *rtn = SDL_CreateRenderer(window, index, flags);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Renderer(rtn)));
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Renderer *rtn = SDL_CreateSoftwareRenderer(surface);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Renderer(rtn)));
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 format = args.GetULong(1);
	int access = args.GetInt(2);
	int w = args.GetInt(3);
	int h = args.GetInt(4);
	SDL_Texture *rtn = SDL_CreateTexture(renderer, format, access, w, h);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Texture(rtn)));
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Surface *surface = args.IsValid(1)? Object_Surface::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Texture *rtn = SDL_CreateTextureFromSurface(renderer, surface);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Texture(rtn)));
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_GL_UnbindTexture(texture);
	if (rtn < 0) {
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
	int rtn = SDL_GetNumRenderDrivers();
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
	int rtn = SDL_GetRenderDrawBlendMode(renderer, &blendMode);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	Uint8 a = 0;
	int rtn = SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
	if (rtn < 0) {
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
	int rtn = SDL_GetRenderDriverInfo(index, &info);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_RendererInfo(info)));
}

// sdl2.GetRenderTarget
Gura_DeclareFunction(GetRenderTarget)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetRenderTarget)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_GetRenderTarget(renderer);
	return Value::Null;
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Renderer *rtn = SDL_GetRenderer(window);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Renderer(rtn)));
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_RendererInfo info;
	int rtn = SDL_GetRendererInfo(renderer, &info);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	int w = 0;
	int h = 0;
	int rtn = SDL_GetRendererOutputSize(renderer, &w, &h);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 alpha = 0;
	int rtn = SDL_GetTextureAlphaMod(texture, &alpha);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
	int rtn = SDL_GetTextureBlendMode(texture, &blendMode);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	int rtn = SDL_GetTextureColorMod(texture, &r, &g, &b);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	void **pixels = args.IsValid(2)? NULL : NULL;
	int *pitch = args.IsValid(3)? NULL : NULL;
	int rtn = SDL_LockTexture(texture, rect, pixels, pitch);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 format = 0;
	int access = 0;
	int w = 0;
	int h = 0;
	int rtn = SDL_QueryTexture(texture, &format, &access, &w, &h);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_RenderClear(renderer);
	if (rtn < 0) {
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
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderCopy)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Texture *texture = args.IsValid(1)? Object_Texture::GetObject(args, 1)->GetEntity() : NULL;
	const SDL_Rect *srcrect = args.IsValid(2)? Object_Rect::GetObject(args, 2)->GetEntity() : NULL;
	const SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int rtn = SDL_RenderCopy(renderer, texture, srcrect, dstrect);
	if (rtn < 0) {
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
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "center", VTYPE_Point, OCCUR_Once, FLAG_None);
	DeclareArg(env, "flip", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderCopyEx)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Texture *texture = args.IsValid(1)? Object_Texture::GetObject(args, 1)->GetEntity() : NULL;
	const SDL_Rect *srcrect = args.IsValid(2)? Object_Rect::GetObject(args, 2)->GetEntity() : NULL;
	const SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	double angle = args.GetDouble(4);
	const SDL_Point *center = args.IsValid(5)? Object_Point::GetObject(args, 5)->GetEntity() : NULL;
	SDL_RendererFlip flip = static_cast<SDL_RendererFlip>(args.GetInt(6));
	int rtn = SDL_RenderCopyEx(renderer, texture, srcrect, dstrect, angle, center, flip);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	int x1 = args.GetInt(1);
	int y1 = args.GetInt(2);
	int x2 = args.GetInt(3);
	int y2 = args.GetInt(4);
	int rtn = SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	CArray<SDL_Point> points(CreateCArray<SDL_Point, Object_Point>(args.GetList(1)));
	int count = static_cast<int>(points.GetSize());
	int rtn = SDL_RenderDrawLines(renderer, points, count);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int rtn = SDL_RenderDrawPoint(renderer, x, y);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	CArray<SDL_Point> points(CreateCArray<SDL_Point, Object_Point>(args.GetList(1)));
	int count = static_cast<int>(points.GetSize());
	int rtn = SDL_RenderDrawPoints(renderer, points, count);
	if (rtn < 0) {
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderDrawRect)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_RenderDrawRect(renderer, rect);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int count = static_cast<int>(rects.GetSize());
	int rtn = SDL_RenderDrawRects(renderer, rects, count);
	if (rtn < 0) {
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderFillRect)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_RenderFillRect(renderer, rect);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int count = static_cast<int>(rects.GetSize());
	int rtn = SDL_RenderFillRects(renderer, rects, count);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_bool rtn = SDL_RenderIsClipEnabled(renderer);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_RenderPresent(renderer);
	return Value::Null;
}

// sdl2.RenderReadPixels
Gura_DeclareFunction(RenderReadPixels)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "renderer", VTYPE_Renderer, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderReadPixels)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
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
	int rtn = SDL_RenderReadPixels(renderer, rect, format, pixels, pitch);
	if (rtn < 0) {
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderSetClipRect)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_RenderSetClipRect(renderer, rect);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	int w = args.GetInt(1);
	int h = args.GetInt(2);
	int rtn = SDL_RenderSetLogicalSize(renderer, w, h);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	float scaleX = args.GetFloat(1);
	float scaleY = args.GetFloat(2);
	int rtn = SDL_RenderSetScale(renderer, scaleX, scaleY);
	if (rtn < 0) {
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RenderSetViewport)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_RenderSetViewport(renderer, rect);
	if (rtn < 0) {
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_bool rtn = SDL_RenderTargetSupported(renderer);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint8 a = args.GetUChar(4);
	int rtn = SDL_SetRenderDrawColor(renderer, r, g, b, a);
	if (rtn < 0) {
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
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetRenderTarget)
{
	SDL_Renderer *renderer = args.IsValid(0)? Object_Renderer::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Texture *texture = args.IsValid(1)? Object_Texture::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_SetRenderTarget(renderer, texture);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 alpha = args.GetUChar(1);
	int rtn = SDL_SetTextureAlphaMod(texture, alpha);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	SDL_BlendMode blendMode = static_cast<SDL_BlendMode>(args.GetInt(1));
	int rtn = SDL_SetTextureBlendMode(texture, blendMode);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	int rtn = SDL_SetTextureColorMod(texture, r, g, b);
	if (rtn < 0) {
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
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	SDL_UnlockTexture(texture);
	return Value::Null;
}

// sdl2.UpdateTexture
Gura_DeclareFunction(UpdateTexture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "texture", VTYPE_Texture, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "pitch", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UpdateTexture)
{
#if 0
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	const void *pixels = args.IsValid(2)? NULL : NULL;
	int pitch = args.GetInt(3);
	int rtn = SDL_UpdateTexture(texture, rect, pixels, pitch);
	if (rtn < 0) {
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(UpdateYUVTexture)
{
#if 0
	SDL_Texture *texture = args.IsValid(0)? Object_Texture::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	const Uint8 *Yplane = args.IsValid(2)? NULL : NULL;
	int Ypitch = NULL;
	const Uint8 *Uplane = args.IsValid(4)? NULL : NULL;
	int Upitch = NULL;
	const Uint8 *Vplane = args.IsValid(6)? NULL : NULL;
	int Vpitch = NULL;
	int rtn = SDL_UpdateYUVTexture(texture, rect, Yplane, Ypitch, Uplane, Upitch, Vplane, Vpitch);
	if (rtn < 0) {
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
	SDL_PixelFormat *rtn = SDL_AllocFormat(pixel_format);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_PixelFormat(rtn)));
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
	SDL_Palette *rtn = SDL_AllocPalette(ncolors);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Palette(rtn)));
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
	SDL_PixelFormat *format = args.IsValid(0)? Object_PixelFormat::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Palette *palette = args.IsValid(0)? Object_Palette::GetObject(args, 0)->GetEntity() : NULL;
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
	const char *rtn = SDL_GetPixelFormatName(format);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const SDL_PixelFormat *format = args.IsValid(1)? Object_PixelFormat::GetObject(args, 1)->GetEntity() : NULL;
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
	const SDL_PixelFormat *format = args.IsValid(1)? Object_PixelFormat::GetObject(args, 1)->GetEntity() : NULL;
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
	const SDL_PixelFormat *format = args.IsValid(0)? Object_PixelFormat::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint32 rtn = SDL_MapRGB(format, r, g, b);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const SDL_PixelFormat *format = args.IsValid(0)? Object_PixelFormat::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	Uint8 a = args.GetUChar(4);
	Uint32 rtn = SDL_MapRGBA(format, r, g, b, a);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Uint32 rtn = SDL_MasksToPixelFormatEnum(bpp, Rmask, Gmask, Bmask, Amask);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_bool rtn = SDL_PixelFormatEnumToMasks(format, &bpp, &Rmask, &Gmask, &Bmask, &Amask);
	if (rtn != SDL_TRUE) {
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
	SDL_Palette *palette = args.IsValid(0)? Object_Palette::GetObject(args, 0)->GetEntity() : NULL;
	int firstcolor = args.GetInt(2);
	int ncolors = args.GetInt(3);
	CArray<SDL_Color> colors(CreateCArray<SDL_Color, Object_Color>(args.GetList(1)));
	int nmax = static_cast<int>(colors.GetSize());
	if (firstcolor + ncolors > nmax) {
		sig.SetError(ERR_IndexError, "out of range");
		return Value::Null;
	}
	int rtn = SDL_SetPaletteColors(palette, colors, firstcolor, ncolors);
	if (rtn < 0) {
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
	SDL_PixelFormat *format = args.IsValid(0)? Object_PixelFormat::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Palette *palette = args.IsValid(1)? Object_Palette::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_SetPixelFormatPalette(format, palette);
	if (rtn < 0) {
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
	DeclareArg(env, "clip", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(EnclosePoints)
{
#if 0
	const SDL_Point *points = args.IsValid(0)? NULL : NULL;
	int count = NULL;
	const SDL_Rect *clip = args.IsValid(2)? Object_Rect::GetObject(args, 2)->GetEntity() : NULL;
	SDL_Rect *result = args.IsValid(3)? NULL : NULL;
	SDL_bool rtn = SDL_EnclosePoints(points, count, clip, result);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
#endif
	SetError_NotImpFunction(sig, "EnclosePoints");
	return Value::Null;
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
	const SDL_Rect *A = args.IsValid(0)? Object_Rect::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *B = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_bool rtn = SDL_HasIntersection(A, B);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	const SDL_Rect *A = args.IsValid(0)? Object_Rect::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *B = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Rect result;
	SDL_bool rtn = SDL_IntersectRect(A, B, &result);
	Value value;
	if (rtn == SDL_TRUE) {
		value = Value(new Object_Rect(result));
	}
	return ReturnValue(env, sig, args, value);
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
	const SDL_Rect *rect = args.IsValid(0)? Object_Rect::GetObject(args, 0)->GetEntity() : NULL;
	int X1 = args.GetInt(1);
	int Y1 = args.GetInt(2);
	int X2 = args.GetInt(3);
	int Y2 = args.GetInt(4);
	SDL_bool rtn = SDL_IntersectRectAndLine(rect, X1, Y1, X2, Y2);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	const SDL_Point *p = args.IsValid(0)? Object_Point::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *r = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_bool rtn = SDL_PointInRect(p, r);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	const SDL_Rect *r = args.IsValid(0)? Object_Rect::GetObject(args, 0)->GetEntity() : NULL;
	SDL_bool rtn = SDL_RectEmpty(r);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	const SDL_Rect *a = args.IsValid(0)? Object_Rect::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *b = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_bool rtn = SDL_RectEquals(a, b);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	const SDL_Rect *A = args.IsValid(0)? Object_Rect::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *B = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Rect result;
	SDL_UnionRect(A, B, &result);
	Value value = Value(new Object_Rect(result));
	return ReturnValue(env, sig, args, value);
}

// sdl2.BlitScaled
Gura_DeclareFunction(BlitScaled)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(BlitScaled)
{
	SDL_Surface *src = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = args.IsValid(2)? Object_Surface::GetObject(args, 2)->GetEntity() : NULL;
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int rtn = SDL_BlitScaled(src, srcrect, dst, dstrect);
	if (rtn < 0) {
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
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(BlitSurface)
{
	SDL_Surface *src = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = args.IsValid(2)? Object_Surface::GetObject(args, 2)->GetEntity() : NULL;
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int rtn = SDL_BlitSurface(src, srcrect, dst, dstrect);
	if (rtn < 0) {
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
	const void *src = args.IsValid(3)? NULL : NULL;
	int src_pitch = NULL;
	Uint32 dst_format = args.GetULong(5);
	void *dst = args.IsValid(6)? NULL : NULL;
	int dst_pitch = NULL;
	int rtn = SDL_ConvertPixels(width, height, src_format, src, src_pitch, dst_format, dst, dst_pitch);
	if (rtn < 0) {
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
	SDL_Surface *src = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_PixelFormat *fmt = args.IsValid(1)? Object_PixelFormat::GetObject(args, 1)->GetEntity() : NULL;
	Uint32 flags = args.GetULong(2);
	SDL_Surface *rtn = SDL_ConvertSurface(src, fmt, flags);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(rtn)));
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
	SDL_Surface *src = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 pixel_format = args.GetULong(1);
	Uint32 flags = args.GetULong(2);
	SDL_Surface *rtn = SDL_ConvertSurfaceFormat(src, pixel_format, flags);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(rtn)));
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
	SDL_Surface *rtn = SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask, Bmask, Amask);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(rtn)));
}

// sdl2.CreateRGBSurfaceFrom
Gura_DeclareFunction(CreateRGBSurfaceFrom)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "image", VTYPE_image, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateRGBSurfaceFrom)
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "color", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FillRect)
{
	SDL_Surface *dst = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	Uint32 color = args.GetULong(2);
	int rtn = SDL_FillRect(dst, rect, color);
	if (rtn < 0) {
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
	SDL_Surface *dst = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 color = args.GetULong(2);
	CArray<SDL_Rect> rects(CreateCArray<SDL_Rect, Object_Rect>(args.GetList(1)));
	int count = static_cast<int>(rects.GetSize());
	int rtn = SDL_FillRects(dst, rects, count, color);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_FreeSurface(surface);
	return Value::Null;
}

// sdl2.GetClipRect
Gura_DeclareFunction(GetClipRect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GetClipRect)
{
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_GetClipRect(surface, rect);
	return Value::Null;
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	Uint32 key = 0;
	int rtn = SDL_GetColorKey(surface, &key);
	if (rtn < 0) {
		SetError_SDL(sig);	// there may be no error even if rtn is -1.
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(key));
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 alpha = 0;
	int rtn = SDL_GetSurfaceAlphaMod(surface, &alpha);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
	int rtn = SDL_GetSurfaceBlendMode(surface, &blendMode);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	int rtn = SDL_GetSurfaceColorMod(surface, &r, &g, &b);
	return ReturnValue(env, sig, args,
			Value::CreateList(env, Value(r), Value(g), Value(b)));
}

// sdl2.LoadBMP
Gura_DeclareFunction(LoadBMP)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadBMP)
{
	const char *file = args.IsValid(0)? args.GetString(0) : NULL;
	SDL_Surface *rtn = SDL_LoadBMP(file);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(rtn)));
}

// sdl2.LoadBMP_RW
Gura_DeclareFunction(LoadBMP_RW)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_nil, OCCUR_Once, FLAG_None);
	DeclareArg(env, "freesrc", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadBMP_RW)
{
#if 0
	SDL_RWops *src = args.IsValid(0)? NULL : NULL;
	int freesrc = args.GetInt(1);
	SDL_Surface *rtn = SDL_LoadBMP_RW(src, freesrc);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Surface(rtn)));
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_LockSurface(surface);
	if (rtn < 0) {
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
	DeclareArg(env, "srcrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dstrect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LowerBlit)
{
	SDL_Surface *src = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = args.IsValid(2)? Object_Surface::GetObject(args, 2)->GetEntity() : NULL;
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int rtn = SDL_LowerBlit(src, srcrect, dst, dstrect);
	if (rtn < 0) {
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
	SDL_Surface *src = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Rect *srcrect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_Surface *dst = args.IsValid(2)? Object_Surface::GetObject(args, 2)->GetEntity() : NULL;
	SDL_Rect *dstrect = args.IsValid(3)? Object_Rect::GetObject(args, 3)->GetEntity() : NULL;
	int rtn = SDL_LowerBlitScaled(src, srcrect, dst, dstrect);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	bool rtn = SDL_MUSTLOCK(surface);
	return ReturnValue(env, sig, args, Value(rtn));
}

// sdl2.SaveBMP
Gura_DeclareFunction(SaveBMP)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveBMP)
{
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	const char *file = args.IsValid(1)? args.GetString(1) : NULL;
	int rtn = SDL_SaveBMP(surface, file);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.SaveBMP_RW
Gura_DeclareFunction(SaveBMP_RW)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "surface", VTYPE_Surface, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_nil, OCCUR_Once, FLAG_None);
	DeclareArg(env, "freedst", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveBMP_RW)
{
#if 0
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_RWops *dst = args.IsValid(1)? NULL : NULL;
	int freedst = args.GetInt(2);
	int rtn = SDL_SaveBMP_RW(surface, dst, freedst);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetClipRect)
{
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	const SDL_Rect *rect = args.IsValid(1)? Object_Rect::GetObject(args, 1)->GetEntity() : NULL;
	SDL_bool rtn = SDL_SetClipRect(surface, rect);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	int flag = args.GetInt(1);
	Uint32 key = args.GetULong(2);
	int rtn = SDL_SetColorKey(surface, flag, key);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 alpha = args.GetUChar(1);
	int rtn = SDL_SetSurfaceAlphaMod(surface, alpha);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_BlendMode blendMode = static_cast<SDL_BlendMode>(args.GetInt(1));
	int rtn = SDL_SetSurfaceBlendMode(surface, blendMode);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	Uint8 r = args.GetUChar(1);
	Uint8 g = args.GetUChar(2);
	Uint8 b = args.GetUChar(3);
	int rtn = SDL_SetSurfaceColorMod(surface, r, g, b);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Palette *palette = args.IsValid(1)? Object_Palette::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_SetSurfacePalette(surface, palette);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	int flag = args.GetInt(1);
	int rtn = SDL_SetSurfaceRLE(surface, flag);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
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
	char *rtn = SDL_GetClipboardText();
	Value value(rtn);
	SDL_free(rtn);
	return ReturnValue(env, sig, args, value);
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
	SDL_bool rtn = SDL_HasClipboardText();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	const char *text = args.IsValid(0)? args.GetString(0) : NULL;
	int rtn = SDL_SetClipboardText(text);
	if (rtn < 0) {
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
	Uint8 rtn = SDL_EventState(type, state);
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetNumTouchDevices();
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetNumTouchFingers(touchId);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_TouchID rtn = SDL_GetTouchDevice(index);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Finger *rtn = SDL_GetTouchFinger(touchId, index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Finger(rtn)));
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
	SDL_bool rtn = SDL_HasEvent(type);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasEvents(minType, maxType);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
}

// sdl2.LoadDollarTemplates
Gura_DeclareFunction(LoadDollarTemplates)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "src", VTYPE_nil, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadDollarTemplates)
{
#if 0
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	SDL_RWops *src = args.IsValid(1)? NULL : NULL;
	int rtn = SDL_LoadDollarTemplates(touchId, src);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImpFunction(sig, "LoadDollarTemplates");
	return Value::Null;
}

// sdl2.PeepEvents
Gura_DeclareFunction(PeepEvents)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "action", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "minType", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "maxType", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(PeepEvents)
{
#if 0
	SDL_Event *events = args.IsValid(0)? NULL : NULL;
	int numevents = NULL;
	SDL_eventaction action = static_cast<SDL_eventaction>(args.GetInt(2));
	Uint32 minType = args.GetULong(3);
	Uint32 maxType = args.GetULong(4);
	int rtn = SDL_PeepEvents(events, numevents, action, minType, maxType);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "PeepEvents");
	return Value::Null;
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
	int rtn = SDL_PollEvent(&event);
	if (rtn == 0) return Value::Null;
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
	SDL_Event *event = args.IsValid(0)? Object_Event::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_PushEvent(event);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	bool rtn = SDL_QuitRequested();
	return ReturnValue(env, sig, args, Value(rtn));
}

// sdl2.RecordGesture
Gura_DeclareFunction(RecordGesture)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "touchId", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(RecordGesture)
{
	SDL_TouchID touchId = static_cast<SDL_TouchID>(args.GetInt(0));
	int rtn = SDL_RecordGesture(touchId);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
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
	Uint32 rtn = SDL_RegisterEvents(numevents);
	return ReturnValue(env, sig, args, Value(rtn));
}

// sdl2.SaveAllDollarTemplates
Gura_DeclareFunction(SaveAllDollarTemplates)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "dst", VTYPE_nil, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveAllDollarTemplates)
{
#if 0
	SDL_RWops *dst = args.IsValid(0)? NULL : NULL;
	int rtn = SDL_SaveAllDollarTemplates(dst);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SaveAllDollarTemplates");
	return Value::Null;
}

// sdl2.SaveDollarTemplate
Gura_DeclareFunction(SaveDollarTemplate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "gestureId", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "dst", VTYPE_nil, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SaveDollarTemplate)
{
#if 0
	SDL_GestureID gestureId = static_cast<SDL_GestureID>(args.GetInt(0));
	SDL_RWops *dst = args.IsValid(1)? NULL : NULL;
	int rtn = SDL_SaveDollarTemplate(gestureId, dst);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "SaveDollarTemplate");
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
	int rtn = SDL_WaitEvent(&event);
	if (rtn == 0) {
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
	int rtn = SDL_WaitEventTimeout(&event, timeout);
	if (rtn == 0) {
		SetError_SDL(sig); // no signal if timeout
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Event(event)));
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
	const char *name = args.IsValid(0)? args.GetString(0) : NULL;
	SDL_Keycode rtn = SDL_GetKeyFromName(name);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Keycode rtn = SDL_GetKeyFromScancode(scancode);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetKeyName(key);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Window *rtn = SDL_GetKeyboardFocus();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(rtn)));
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
	const Uint8 *rtn = SDL_GetKeyboardState(&numkeys);
	return ReturnValue(env, sig, args, Value::CreateList(env, rtn, numkeys));
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
	SDL_Keymod rtn = SDL_GetModState();
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Scancode rtn = SDL_GetScancodeFromKey(key);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *name = args.IsValid(0)? args.GetString(0) : NULL;
	SDL_Scancode rtn = SDL_GetScancodeFromName(name);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetScancodeName(scancode);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_bool rtn = SDL_HasScreenKeyboardSupport();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
	SDL_bool rtn = SDL_IsScreenKeyboardShown(window);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_IsTextInputActive();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	DeclareArg(env, "rect", VTYPE_Rect, OCCUR_Once, FLAG_None);
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
	int rtn = SDL_CaptureMouse(enalbed);
	if (rtn < 0) {
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
	SDL_Surface *surface = args.IsValid(0)? Object_Surface::GetObject(args, 0)->GetEntity() : NULL;
	int hot_x = args.GetInt(1);
	int hot_y = args.GetInt(2);
	SDL_Cursor *rtn = SDL_CreateColorCursor(surface, hot_x, hot_y);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(rtn, false)));
}

// sdl2.CreateCursor
Gura_DeclareFunction(CreateCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_x", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hot_y", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateCursor)
{
#if 0
	const Uint8 *data = args.IsValid(0)? NULL : NULL;
	const Uint8 *mask = args.IsValid(1)? args.GetList(1) : NULL;
	int w = args.GetInt(2);
	int h = args.GetInt(3);
	int hot_x = args.GetInt(4);
	int hot_y = args.GetInt(5);
	SDL_Cursor *rtn = SDL_CreateCursor(data, mask, w, h, hot_x, hot_y);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(rtn, false)));
#endif
	SetError_NotImpFunction(sig, "CreateCursor");
	return Value::Null;
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
	SDL_Cursor *rtn = SDL_CreateSystemCursor(id);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(rtn, false)));
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
	SDL_Cursor *cursor = args.IsValid(0)? Object_Cursor::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Cursor *rtn = SDL_GetCursor();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(rtn, false)));
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
	SDL_Cursor *rtn = SDL_GetDefaultCursor();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Cursor(rtn, false)));
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
	Uint32 rtn = SDL_GetGlobalMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(rtn), Value(x), Value(y)));
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
	SDL_Window *rtn = SDL_GetMouseFocus();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Window(rtn)));
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
	Uint32 rtn = SDL_GetMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(rtn), Value(x), Value(y)));
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
	SDL_bool rtn = SDL_GetRelativeMouseMode();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	Uint32 rtn = SDL_GetRelativeMouseState(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateList(env,
										Value(rtn), Value(x), Value(y)));
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
	SDL_Cursor *cursor = args.IsValid(0)? Object_Cursor::GetObject(args, 0)->GetEntity() : NULL;
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
	int rtn = SDL_SetRelativeMouseMode(enabled);
	if (rtn < 0) {
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
	int rtn = SDL_ShowCursor(toggle);
	if (rtn < 0) {
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
	SDL_Window *window = args.IsValid(0)? Object_Window::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
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
	int rtn = SDL_JoystickEventState(state);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	SDL_bool rtn = SDL_JoystickGetAttached(joystick);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int axis = args.GetInt(1);
	Sint16 rtn = SDL_JoystickGetAxis(joystick, axis);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int ball = args.GetInt(1);
	int dx = 0;
	int dy = 0;
	int rtn = SDL_JoystickGetBall(joystick, ball, &dx, &dy);
	if (rtn < 0) {
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int button = args.GetInt(1);
	Uint8 rtn = SDL_JoystickGetButton(joystick, button);
	return ReturnValue(env, sig, args, Value(rtn));
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
#if 0
	int device_index = args.GetInt(0);
	int rtn = SDL_JoystickGetDeviceGUID(device_index);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImpFunction(sig, "JoystickGetDeviceGUID");
	return Value::Null;
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
#if 0
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_JoystickGetGUID(joystick);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImpFunction(sig, "JoystickGetGUID");
	return Value::Null;
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
#if 0
	const char *pchGUID = args.IsValid(0)? args.GetString(0) : NULL;
	int rtn = SDL_JoystickGetGUIDFromString(pchGUID);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImpFunction(sig, "JoystickGetGUIDFromString");
	return Value::Null;
}

// sdl2.JoystickGetGUIDString
Gura_DeclareFunction(JoystickGetGUIDString)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(JoystickGetGUIDString)
{
#if 0
	SDL_JoystickGetGUIDString();
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "JoystickGetGUIDString");
	return Value::Null;
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int hat = args.GetInt(1);
	Uint8 rtn = SDL_JoystickGetHat(joystick, hat);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	SDL_JoystickID rtn = SDL_JoystickInstanceID(joystick);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	const char *rtn = SDL_JoystickName(joystick);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_JoystickNameForIndex(device_index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_JoystickNumAxes(joystick);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_JoystickNumBalls(joystick);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_JoystickNumButtons(joystick);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_JoystickNumHats(joystick);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Joystick *rtn = SDL_JoystickOpen(device_index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Joystick(rtn)));
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
	int rtn = SDL_NumJoysticks();
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *mappingString = args.IsValid(0)? args.GetString(0) : NULL;
	int rtn = SDL_GameControllerAddMapping(mappingString);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

// sdl2.GameControllerAddMappingsFromFile
Gura_DeclareFunction(GameControllerAddMappingsFromFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerAddMappingsFromFile)
{
	const char *filename = args.IsValid(0)? args.GetString(0) : NULL;
	int rtn = SDL_GameControllerAddMappingsFromFile(filename);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_RWops *rw = args.IsValid(0)? NULL : NULL;
	int freerw = args.GetInt(1);
	int rtn = SDL_GameControllerAddMappingsFromRW(rw, freerw);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
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
	int rtn = SDL_GameControllerEventState(state);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	SDL_bool rtn = SDL_GameControllerGetAttached(gamecontroller);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	Sint16 rtn = SDL_GameControllerGetAxis(gamecontroller, axis);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *pchString = args.IsValid(0)? args.GetString(0) : NULL;
	SDL_GameControllerAxis rtn = SDL_GameControllerGetAxisFromString(pchString);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	SDL_GameControllerAxis axis = static_cast<SDL_GameControllerAxis>(args.GetInt(1));
	SDL_GameControllerButtonBind rtn = SDL_GameControllerGetBindForAxis(gamecontroller, axis);
	return ReturnValue(env, sig, args, Value(new Object_GameControllerButtonBind(rtn)));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(1));
	SDL_GameControllerButtonBind rtn = SDL_GameControllerGetBindForButton(gamecontroller, button);
	return ReturnValue(env, sig, args, Value(new Object_GameControllerButtonBind(rtn)));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	SDL_GameControllerButton button = static_cast<SDL_GameControllerButton>(args.GetInt(1));
	Uint8 rtn = SDL_GameControllerGetButton(gamecontroller, button);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *pchString = args.IsValid(0)? args.GetString(0) : NULL;
	SDL_GameControllerButton rtn = SDL_GameControllerGetButtonFromString(pchString);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Joystick *rtn = SDL_GameControllerGetJoystick(gamecontroller);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Joystick(rtn)));
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
	const char *rtn = SDL_GameControllerGetStringForAxis(axis);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GameControllerGetStringForButton(button);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	const char *rtn = SDL_GameControllerMapping(gamecontroller);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
}

// sdl2.GameControllerMappingForGUID
Gura_DeclareFunction(GameControllerMappingForGUID)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "guid", VTYPE_number, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GameControllerMappingForGUID)
{
#if 0
	int guid = args.GetInt(0);
	const char *rtn = SDL_GameControllerMappingForGUID(guid);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImpFunction(sig, "GameControllerMappingForGUID");
	return Value::Null;
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
	SDL_GameController *gamecontroller = args.IsValid(0)? Object_GameController::GetObject(args, 0)->GetEntity() : NULL;
	const char *rtn = SDL_GameControllerName(gamecontroller);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GameControllerNameForIndex(joystick_index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_GameController *rtn = SDL_GameControllerOpen(joystick_index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_GameController(rtn)));
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
	SDL_bool rtn = SDL_IsGameController(joystick_index);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	SDL_HapticEffect *effect = args.IsValid(1)? Object_HapticEffect::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_HapticEffectSupported(haptic, effect);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int effect = args.GetInt(1);
	int rtn = SDL_HapticGetEffectStatus(haptic, effect);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticIndex(haptic);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_HapticName(device_index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	SDL_HapticEffect *effect = args.IsValid(1)? Object_HapticEffect::GetObject(args, 1)->GetEntity() : NULL;
	int rtn = SDL_HapticNewEffect(haptic, effect);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticNumAxes(haptic);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticNumEffects(haptic);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticNumEffectsPlaying(haptic);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Haptic *rtn = SDL_HapticOpen(device_index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Haptic(rtn)));
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	SDL_Haptic *rtn = SDL_HapticOpenFromJoystick(joystick);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Haptic(rtn)));
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
	SDL_Haptic *rtn = SDL_HapticOpenFromMouse();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_Haptic(rtn)));
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
	int rtn = SDL_HapticOpened(device_index);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticPause(haptic);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	unsigned int rtn = SDL_HapticQuery(haptic);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticRumbleInit(haptic);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	float strength = args.GetFloat(1);
	Uint32 length = args.GetULong(2);
	int rtn = SDL_HapticRumblePlay(haptic, strength, length);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticRumbleStop(haptic);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticRumbleSupported(haptic);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int effect = args.GetInt(1);
	Uint32 iterations = args.GetULong(2);
	int rtn = SDL_HapticRunEffect(haptic, effect, iterations);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int autocenter = args.GetInt(1);
	int rtn = SDL_HapticSetAutocenter(haptic, autocenter);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int gain = args.GetInt(1);
	int rtn = SDL_HapticSetGain(haptic, gain);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticStopAll(haptic);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int effect = args.GetInt(1);
	int rtn = SDL_HapticStopEffect(haptic, effect);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_HapticUnpause(haptic);
	if (rtn < 0) {
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
	SDL_Haptic *haptic = args.IsValid(0)? Object_Haptic::GetObject(args, 0)->GetEntity() : NULL;
	int effect = args.GetInt(1);
	SDL_HapticEffect *data = args.IsValid(2)? Object_HapticEffect::GetObject(args, 2)->GetEntity() : NULL;
	int rtn = SDL_HapticUpdateEffect(haptic, effect, data);
	if (rtn < 0) {
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
	SDL_Joystick *joystick = args.IsValid(0)? Object_Joystick::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_JoystickIsHaptic(joystick);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	int rtn = SDL_MouseIsHaptic();
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	int rtn = SDL_NumHaptics();
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *driver_name = args.IsValid(0)? args.GetString(0) : NULL;
	int rtn = SDL_AudioInit(driver_name);
	if (rtn < 0) {
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
	SDL_AudioCVT *cvt = args.IsValid(0)? Object_AudioCVT::GetObject(args, 0)->GetEntity() : NULL;
	SDL_AudioFormat src_format = static_cast<SDL_AudioFormat>(args.GetInt(1));
	Uint8 src_channels = args.GetUChar(2);
	int src_rate = args.GetInt(3);
	SDL_AudioFormat dst_format = static_cast<SDL_AudioFormat>(args.GetInt(4));
	Uint8 dst_channels = args.GetUChar(5);
	int dst_rate = args.GetInt(6);
	int rtn = SDL_BuildAudioCVT(cvt, src_format, src_channels, src_rate, dst_format, dst_channels, dst_rate);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	SDL_AudioCVT *cvt = args.IsValid(0)? Object_AudioCVT::GetObject(args, 0)->GetEntity() : NULL;
	int rtn = SDL_ConvertAudio(cvt);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
}

// sdl2.FreeWAV
Gura_DeclareFunction(FreeWAV)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(FreeWAV)
{
#if 0
	Uint8 *audio_buf = args.IsValid(0)? NULL : NULL;
	SDL_FreeWAV(audio_buf);
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "FreeWAV");
	return Value::Null;
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
	const char *rtn = SDL_GetAudioDeviceName(index, iscapture);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_AudioStatus rtn = SDL_GetAudioDeviceStatus(dev);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetAudioDriver(index);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_AudioStatus rtn = SDL_GetAudioStatus();
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetCurrentAudioDriver();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetNumAudioDevices(iscapture);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetNumAudioDrivers();
	return ReturnValue(env, sig, args, Value(rtn));
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
	Uint32 rtn = SDL_GetQueuedAudioSize(dev);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImpFunction(sig, "GetQueuedAudioSize");
	return Value::Null;
}

// sdl2.LoadWAV
Gura_DeclareFunction(LoadWAV)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once, FLAG_None);
	DeclareArg(env, "spec", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadWAV)
{
#if 0
	const char *file = args.IsValid(0)? args.GetString(0) : NULL;
	SDL_AudioSpec *spec = args.IsValid(1)? Object_AudioSpec::GetObject(args, 1)->GetEntity() : NULL;
	Uint8 **audio_buf = args.IsValid(2)? NULL : NULL;
	Uint32 *audio_len = args.IsValid(3)? NULL : NULL;
	SDL_AudioSpec *rtn = SDL_LoadWAV(file, spec, audio_buf, audio_len);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_AudioSpec(rtn)));
#endif
	SetError_NotImpFunction(sig, "LoadWAV");
	return Value::Null;
}

// sdl2.LoadWAV_RW
Gura_DeclareFunction(LoadWAV_RW)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareArg(env, "src", VTYPE_nil, OCCUR_Once, FLAG_None);
	DeclareArg(env, "freesrc", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "spec", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(LoadWAV_RW)
{
#if 0
	SDL_RWops *src = args.IsValid(0)? NULL : NULL;
	int freesrc = args.GetInt(1);
	SDL_AudioSpec *spec = args.IsValid(2)? Object_AudioSpec::GetObject(args, 2)->GetEntity() : NULL;
	Uint8 **audio_buf = args.IsValid(3)? NULL : NULL;
	Uint32 *audio_len = args.IsValid(4)? NULL : NULL;
	SDL_AudioSpec *rtn = SDL_LoadWAV_RW(src, freesrc, spec, audio_buf, audio_len);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_AudioSpec(rtn)));
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
	Uint8 *dst = args.IsValid(0)? NULL : NULL;
	const Uint8 *src = args.IsValid(1)? NULL : NULL;
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
	Uint8 *dst = args.IsValid(0)? NULL : NULL;
	const Uint8 *src = args.IsValid(1)? NULL : NULL;
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
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "desired", VTYPE_AudioSpec, OCCUR_Once, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(OpenAudio)
{
#if 0
	SDL_AudioSpec *desired = args.IsValid(0)? Object_AudioSpec::GetObject(args, 0)->GetEntity() : NULL;
	SDL_AudioSpec *obtained = args.IsValid(1)? NULL : NULL;
	int rtn = SDL_OpenAudio(desired, obtained);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::Null;
#endif
	SetError_NotImpFunction(sig, "OpenAudio");
	return Value::Null;
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
	const char *device = args.IsValid(0)? args.GetString(0) : NULL;
	int iscapture = args.GetInt(1);
	const SDL_AudioSpec *desired = args.IsValid(2)? Object_AudioSpec::GetObject(args, 2)->GetEntity() : NULL;
	SDL_AudioSpec *obtained = args.IsValid(3)? NULL : NULL;
	int allowed_changes = args.GetInt(4);
	SDL_AudioDeviceID rtn = SDL_OpenAudioDevice(device, iscapture, desired, obtained, allowed_changes);
	return ReturnValue(env, sig, args, Value(rtn));
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
	const void *data = args.IsValid(1)? NULL : NULL;
	Uint32 len = NULL;
	int rtn = SDL_QueueAudio(dev, data, len);
	if (rtn < 0) {
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
	Uint16 rtn = SDL_AUDIO_BITSIZE(x);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Uint16 rtn = SDL_AUDIO_ISFLOAT(x);
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	Uint16 rtn = SDL_AUDIO_ISBIGENDIAN(x);
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	Uint16 rtn = SDL_AUDIO_ISSIGNED(x);
	return ReturnValue(env, sig, args, Value(rtn != 0));
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
	bool rtn = SDL_AUDIO_ISINT(x);
	return ReturnValue(env, sig, args, Value(rtn));
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
	bool rtn = SDL_AUDIO_ISLITTLEENDIAN(x);
	return ReturnValue(env, sig, args, Value(rtn));
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
	bool rtn = SDL_AUDIO_ISUNSIGNED(x);
	return ReturnValue(env, sig, args, Value(rtn));
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
	void *param = args.IsValid(2)? NULL : NULL;
	SDL_TimerID rtn = SDL_AddTimer(interval, callback, param);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Uint64 rtn = SDL_GetPerformanceCounter();
	return ReturnValue(env, sig, args, Value(rtn));
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
	Uint64 rtn = SDL_GetPerformanceFrequency();
	return ReturnValue(env, sig, args, Value(rtn));
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
	Uint32 rtn = SDL_GetTicks();
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_bool rtn = SDL_RemoveTimer(id);
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	bool rtn = SDL_TICKS_PASSED(A, B);
	return ReturnValue(env, sig, args, Value(rtn));
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
	char *rtn = SDL_GetBasePath();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *org = args.IsValid(0)? args.GetString(0) : NULL;
	const char *app = args.IsValid(1)? args.GetString(1) : NULL;
	char *rtn = SDL_GetPrefPath(org, app);
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	const char *rtn = SDL_GetPlatform();
	if (rtn == NULL) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetCPUCacheLineSize();
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetCPUCount();
	return ReturnValue(env, sig, args, Value(rtn));
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
	int rtn = SDL_GetSystemRAM();
	return ReturnValue(env, sig, args, Value(rtn));
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
	SDL_bool rtn = SDL_Has3DNow();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasAVX();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasAVX2();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasAltiVec();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasMMX();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasRDTSC();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasSSE();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasSSE2();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasSSE3();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasSSE41();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	SDL_bool rtn = SDL_HasSSE42();
	return ReturnValue(env, sig, args, Value(rtn != SDL_FALSE));
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
	int rtn = SDL_MostSignificantBitIndex32(x);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImpFunction(sig, "MostSignificantBitIndex32");
	return Value::Null;
}

// sdl2.SDL_GetPowerInfo
Gura_DeclareFunction(SDL_GetPowerInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SDL_GetPowerInfo)
{
	int secs = 0;
	int pct = 0;
	SDL_PowerState rtn = SDL_GetPowerInfo(&secs, &pct);
	return ReturnValue(env, sig, args, Value::CreateList(env,
									Value(rtn), Value(secs), Value(pct)));
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
	double rtn = SDL_acos(x);
	return ReturnValue(env, sig, args, Value(rtn));
}


// sdl2.test()
Gura_DeclareFunction(test)
{
}

Gura_ImplementFunction(test)
{
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

Gura_ModuleEntry()
{
	// symbols in SDL_Event
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(gain);
	Gura_RealizeUserSymbol(state);
	Gura_RealizeUserSymbol(scancode);
	Gura_RealizeUserSymbol(sym);
	Gura_RealizeUserSymbol(mod);
	Gura_RealizeUserSymbol(x);
	Gura_RealizeUserSymbol(y);
	Gura_RealizeUserSymbol(xrel);
	Gura_RealizeUserSymbol(yrel);
	Gura_RealizeUserSymbol(axis);
	Gura_RealizeUserSymbol(value);
	Gura_RealizeUserSymbol(button);
	Gura_RealizeUserSymbol(which);
	Gura_RealizeUserSymbol(hat);
	Gura_RealizeUserSymbol(ball);
	Gura_RealizeUserSymbol(w);
	Gura_RealizeUserSymbol(h);
	Gura_RealizeUserSymbol(timestamp);
	Gura_RealizeUserSymbol(windowID);
	Gura_RealizeUserSymbol(event);
	Gura_RealizeUserSymbol(data1);
	Gura_RealizeUserSymbol(text);
	Gura_RealizeUserSymbol(start);
	Gura_RealizeUserSymbol(repeat);
	Gura_RealizeUserSymbol(clicks);
	Gura_RealizeUserSymbol(code);
	Gura_RealizeUserSymbol(touchId);
	Gura_RealizeUserSymbol(fingerId);
	Gura_RealizeUserSymbol(gestureId);
	Gura_RealizeUserSymbol(dx);
	Gura_RealizeUserSymbol(dy);
	Gura_RealizeUserSymbol(pressure);
	Gura_RealizeUserSymbol(dTheta);
	Gura_RealizeUserSymbol(dDist);
	Gura_RealizeUserSymbol(numFingers);
	Gura_RealizeUserSymbol(error);
	Gura_RealizeUserSymbol(file);
	// symbols in SDL_Color
	Gura_RealizeUserSymbol(r)
	Gura_RealizeUserSymbol(g)
	Gura_RealizeUserSymbol(b)
	// symbols in SDL_PixelFormat
	Gura_RealizeUserSymbol(palette);
	Gura_RealizeUserSymbol(BitsPerPixel);
	Gura_RealizeUserSymbol(BytesPerPixel);
	Gura_RealizeUserSymbol(Rloss);
	Gura_RealizeUserSymbol(Gloss);
	Gura_RealizeUserSymbol(Bloss);
	Gura_RealizeUserSymbol(Aloss);
	Gura_RealizeUserSymbol(Rshift);
	Gura_RealizeUserSymbol(Gshift);
	Gura_RealizeUserSymbol(Bshift);
	Gura_RealizeUserSymbol(Ashift);
	Gura_RealizeUserSymbol(Rmask);
	Gura_RealizeUserSymbol(Gmask);
	Gura_RealizeUserSymbol(Bmask);
	Gura_RealizeUserSymbol(Amask);
	Gura_RealizeUserSymbol(colorkey);
	Gura_RealizeUserSymbol(alpha);
	// symbols in SDL_Surface
	Gura_RealizeUserSymbol(flags)
	Gura_RealizeUserSymbol(format)
	Gura_RealizeUserSymbol(pitch)
	Gura_RealizeUserSymbol(pixels)
	Gura_RealizeUserSymbol(clip_rect)
	Gura_RealizeUserSymbol(refcount)
	// symbols in SDL_VideoInfo
	Gura_RealizeUserSymbol(hw_available);
	Gura_RealizeUserSymbol(wm_available);
	Gura_RealizeUserSymbol(blit_hw);
	Gura_RealizeUserSymbol(blit_hw_CC);
	Gura_RealizeUserSymbol(blit_hw_A);
	Gura_RealizeUserSymbol(blit_sw);
	Gura_RealizeUserSymbol(blit_sw_CC);
	Gura_RealizeUserSymbol(blit_sw_A);
	Gura_RealizeUserSymbol(blit_fill);
	Gura_RealizeUserSymbol(video_mem);
	Gura_RealizeUserSymbol(vfmt);
	// symbols in SDL_CDtrack
	Gura_RealizeUserSymbol(id)
	Gura_RealizeUserSymbol(length)
	Gura_RealizeUserSymbol(offset)
	// symbols in SDL_CD
	Gura_RealizeUserSymbol(status)
	Gura_RealizeUserSymbol(numtracks)
	Gura_RealizeUserSymbol(cur_track)
	Gura_RealizeUserSymbol(cur_frame)
	// symbols for other purposes
	Gura_RealizeUserSymbolAlias(thread_, "thread")
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
	RealizeClass(GameControllerButtonBind);
	RealizeClass(AudioCVT);
	RealizeClass(AudioSpec);
	RealizeClass(RendererInfo);
	RealizeClass(DisplayMode);
	RealizeClass(GLContext);
	RealizeClass(Haptic);
	RealizeClass(HapticEffect);
	RealizeClass(Surface);
	RealizeClass(Finger);
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
	PrepareClass(GameControllerButtonBind);
	PrepareClass(AudioCVT);
	PrepareClass(AudioSpec);
	PrepareClass(RendererInfo);
	PrepareClass(DisplayMode);
	PrepareClass(GLContext);
	PrepareClass(HapticEffect);
	PrepareClass(Surface);
	PrepareClass(Finger);
	AssignValues(env);
	AssignFunctions(env);
	Gura_AssignFunction(test);
	return true;
}

void AssignValues(Environment &env)
{
	// Basics - Initialization and Shutdown
	Gura_AssignValueSDL(INIT_TIMER);
	Gura_AssignValueSDL(INIT_AUDIO);
	Gura_AssignValueSDL(INIT_VIDEO);
	Gura_AssignValueSDL(INIT_JOYSTICK);
	Gura_AssignValueSDL(INIT_HAPTIC);
	Gura_AssignValueSDL(INIT_GAMECONTROLLER);
	Gura_AssignValueSDL(INIT_EVENTS);
	Gura_AssignValueSDL(INIT_EVERYTHING);
	Gura_AssignValueSDL(INIT_NOPARACHUTE);
	// Basics - Configuration Variables
	// Basics - Error Handling
	// Basics - Log Handling
	// Basics - Assertions
	// Basics - Querying SDL Version
	Gura_AssignValueSDL(COMPILEDVERSION);
	//Gura_AssignValueSDL(REVISION);
	//Gura_AssignValueSDL(VERSIONNUM);
	// Video - Display and Window Management
	Gura_AssignValueSDL(WINDOWPOS_CENTERED);
	Gura_AssignValueSDL(WINDOWPOS_UNDEFINED);
	Gura_AssignValueSDL(WINDOW_FULLSCREEN);
	Gura_AssignValueSDL(WINDOW_FULLSCREEN_DESKTOP);
	Gura_AssignValueSDL(WINDOW_OPENGL);
	Gura_AssignValueSDL(WINDOW_HIDDEN);
	Gura_AssignValueSDL(WINDOW_BORDERLESS);
	Gura_AssignValueSDL(WINDOW_RESIZABLE);
	Gura_AssignValueSDL(WINDOW_MINIMIZED);
	Gura_AssignValueSDL(WINDOW_MAXIMIZED);
	Gura_AssignValueSDL(WINDOW_INPUT_GRABBED);
	Gura_AssignValueSDL(WINDOW_ALLOW_HIGHDPI);
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
	Gura_AssignValueSDL(BLENDMODE_NONE);
	Gura_AssignValueSDL(BLENDMODE_BLEND);
	Gura_AssignValueSDL(BLENDMODE_ADD);
	Gura_AssignValueSDL(BLENDMODE_MOD);
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
	Gura_AssignValueScancodeKeycode(0);
	Gura_AssignValueScancodeKeycode(1);
	Gura_AssignValueScancodeKeycode(2);
	Gura_AssignValueScancodeKeycode(3);
	Gura_AssignValueScancodeKeycode(4);
	Gura_AssignValueScancodeKeycode(5);
	Gura_AssignValueScancodeKeycode(6);
	Gura_AssignValueScancodeKeycode(7);
	Gura_AssignValueScancodeKeycode(8);
	Gura_AssignValueScancodeKeycode(9);
	Gura_AssignValueScancodeKeycodeEx(A, a);
	Gura_AssignValueScancodeKeycode(AC_BACK);
	Gura_AssignValueScancodeKeycode(AC_BOOKMARKS);
	Gura_AssignValueScancodeKeycode(AC_FORWARD);
	Gura_AssignValueScancodeKeycode(AC_HOME);
	Gura_AssignValueScancodeKeycode(AC_REFRESH);
	Gura_AssignValueScancodeKeycode(AC_SEARCH);
	Gura_AssignValueScancodeKeycode(AC_STOP);
	Gura_AssignValueScancodeKeycode(AGAIN);
	Gura_AssignValueScancodeKeycode(ALTERASE);
	Gura_AssignValueScancodeKeycodeEx(APOSTROPHE, QUOTE);
	Gura_AssignValueScancodeKeycode(APPLICATION);
	Gura_AssignValueScancodeKeycode(AUDIOMUTE);
	Gura_AssignValueScancodeKeycode(AUDIONEXT);
	Gura_AssignValueScancodeKeycode(AUDIOPLAY);
	Gura_AssignValueScancodeKeycode(AUDIOPREV);
	Gura_AssignValueScancodeKeycode(AUDIOSTOP);
	Gura_AssignValueScancodeKeycodeEx(B, b);
	Gura_AssignValueScancodeKeycode(BACKSLASH);
	Gura_AssignValueScancodeKeycode(BACKSPACE);
	Gura_AssignValueScancodeKeycode(BRIGHTNESSDOWN);
	Gura_AssignValueScancodeKeycode(BRIGHTNESSUP);
	Gura_AssignValueScancodeKeycodeEx(C, c);
	Gura_AssignValueScancodeKeycode(CALCULATOR);
	Gura_AssignValueScancodeKeycode(CANCEL);
	Gura_AssignValueScancodeKeycode(CAPSLOCK);
	Gura_AssignValueScancodeKeycode(CLEAR);
	Gura_AssignValueScancodeKeycode(CLEARAGAIN);
	Gura_AssignValueScancodeKeycode(COMMA);
	Gura_AssignValueScancodeKeycode(COMPUTER);
	Gura_AssignValueScancodeKeycode(COPY);
	Gura_AssignValueScancodeKeycode(CRSEL);
	Gura_AssignValueScancodeKeycode(CURRENCYSUBUNIT);
	Gura_AssignValueScancodeKeycode(CURRENCYUNIT);
	Gura_AssignValueScancodeKeycode(CUT);
	Gura_AssignValueScancodeKeycodeEx(D, d);
	Gura_AssignValueScancodeKeycode(DECIMALSEPARATOR);
	Gura_AssignValueScancodeKeycode(DELETE);
	Gura_AssignValueScancodeKeycode(DISPLAYSWITCH);
	Gura_AssignValueScancodeKeycode(DOWN);
	Gura_AssignValueScancodeKeycodeEx(E, e);
	Gura_AssignValueScancodeKeycode(EJECT);
	Gura_AssignValueScancodeKeycode(END);
	Gura_AssignValueScancodeKeycode(EQUALS);
	Gura_AssignValueScancodeKeycode(ESCAPE);
	Gura_AssignValueScancodeKeycode(EXECUTE);
	Gura_AssignValueScancodeKeycode(EXSEL);
	Gura_AssignValueScancodeKeycodeEx(F, f);
	Gura_AssignValueScancodeKeycode(F1);
	Gura_AssignValueScancodeKeycode(F10);
	Gura_AssignValueScancodeKeycode(F11);
	Gura_AssignValueScancodeKeycode(F12);
	Gura_AssignValueScancodeKeycode(F13);
	Gura_AssignValueScancodeKeycode(F14);
	Gura_AssignValueScancodeKeycode(F15);
	Gura_AssignValueScancodeKeycode(F16);
	Gura_AssignValueScancodeKeycode(F17);
	Gura_AssignValueScancodeKeycode(F18);
	Gura_AssignValueScancodeKeycode(F19);
	Gura_AssignValueScancodeKeycode(F2);
	Gura_AssignValueScancodeKeycode(F20);
	Gura_AssignValueScancodeKeycode(F21);
	Gura_AssignValueScancodeKeycode(F22);
	Gura_AssignValueScancodeKeycode(F23);
	Gura_AssignValueScancodeKeycode(F24);
	Gura_AssignValueScancodeKeycode(F3);
	Gura_AssignValueScancodeKeycode(F4);
	Gura_AssignValueScancodeKeycode(F5);
	Gura_AssignValueScancodeKeycode(F6);
	Gura_AssignValueScancodeKeycode(F7);
	Gura_AssignValueScancodeKeycode(F8);
	Gura_AssignValueScancodeKeycode(F9);
	Gura_AssignValueScancodeKeycode(FIND);
	Gura_AssignValueScancodeKeycodeEx(G, g);
	Gura_AssignValueScancodeKeycodeEx(GRAVE, BACKQUOTE);
	Gura_AssignValueScancodeKeycodeEx(H, h);
	Gura_AssignValueScancodeKeycode(HELP);
	Gura_AssignValueScancodeKeycode(HOME);
	Gura_AssignValueScancodeKeycodeEx(I, i);
	Gura_AssignValueScancodeKeycode(INSERT);
	Gura_AssignValueScancodeKeycodeEx(J, j);
	Gura_AssignValueScancodeKeycodeEx(K, k);
	Gura_AssignValueScancodeKeycode(KBDILLUMDOWN);
	Gura_AssignValueScancodeKeycode(KBDILLUMTOGGLE);
	Gura_AssignValueScancodeKeycode(KBDILLUMUP);
	Gura_AssignValueScancodeKeycode(KP_0);
	Gura_AssignValueScancodeKeycode(KP_00);
	Gura_AssignValueScancodeKeycode(KP_000);
	Gura_AssignValueScancodeKeycode(KP_1);
	Gura_AssignValueScancodeKeycode(KP_2);
	Gura_AssignValueScancodeKeycode(KP_3);
	Gura_AssignValueScancodeKeycode(KP_4);
	Gura_AssignValueScancodeKeycode(KP_5);
	Gura_AssignValueScancodeKeycode(KP_6);
	Gura_AssignValueScancodeKeycode(KP_7);
	Gura_AssignValueScancodeKeycode(KP_8);
	Gura_AssignValueScancodeKeycode(KP_9);
	Gura_AssignValueScancodeKeycode(KP_A);
	Gura_AssignValueScancodeKeycode(KP_AMPERSAND);
	Gura_AssignValueScancodeKeycode(KP_AT);
	Gura_AssignValueScancodeKeycode(KP_B);
	Gura_AssignValueScancodeKeycode(KP_BACKSPACE);
	Gura_AssignValueScancodeKeycode(KP_BINARY);
	Gura_AssignValueScancodeKeycode(KP_C);
	Gura_AssignValueScancodeKeycode(KP_CLEAR);
	Gura_AssignValueScancodeKeycode(KP_CLEARENTRY);
	Gura_AssignValueScancodeKeycode(KP_COLON);
	Gura_AssignValueScancodeKeycode(KP_COMMA);
	Gura_AssignValueScancodeKeycode(KP_D);
	Gura_AssignValueScancodeKeycode(KP_DBLAMPERSAND);
	Gura_AssignValueScancodeKeycode(KP_DBLVERTICALBAR);
	Gura_AssignValueScancodeKeycode(KP_DECIMAL);
	Gura_AssignValueScancodeKeycode(KP_DIVIDE);
	Gura_AssignValueScancodeKeycode(KP_E);
	Gura_AssignValueScancodeKeycode(KP_ENTER);
	Gura_AssignValueScancodeKeycode(KP_EQUALS);
	Gura_AssignValueScancodeKeycode(KP_EQUALSAS400);
	Gura_AssignValueScancodeKeycode(KP_EXCLAM);
	Gura_AssignValueScancodeKeycode(KP_F);
	Gura_AssignValueScancodeKeycode(KP_GREATER);
	Gura_AssignValueScancodeKeycode(KP_HASH);
	Gura_AssignValueScancodeKeycode(KP_HEXADECIMAL);
	Gura_AssignValueScancodeKeycode(KP_LEFTBRACE);
	Gura_AssignValueScancodeKeycode(KP_LEFTPAREN);
	Gura_AssignValueScancodeKeycode(KP_LESS);
	Gura_AssignValueScancodeKeycode(KP_MEMADD);
	Gura_AssignValueScancodeKeycode(KP_MEMCLEAR);
	Gura_AssignValueScancodeKeycode(KP_MEMDIVIDE);
	Gura_AssignValueScancodeKeycode(KP_MEMMULTIPLY);
	Gura_AssignValueScancodeKeycode(KP_MEMRECALL);
	Gura_AssignValueScancodeKeycode(KP_MEMSTORE);
	Gura_AssignValueScancodeKeycode(KP_MEMSUBTRACT);
	Gura_AssignValueScancodeKeycode(KP_MINUS);
	Gura_AssignValueScancodeKeycode(KP_MULTIPLY);
	Gura_AssignValueScancodeKeycode(KP_OCTAL);
	Gura_AssignValueScancodeKeycode(KP_PERCENT);
	Gura_AssignValueScancodeKeycode(KP_PERIOD);
	Gura_AssignValueScancodeKeycode(KP_PLUS);
	Gura_AssignValueScancodeKeycode(KP_PLUSMINUS);
	Gura_AssignValueScancodeKeycode(KP_POWER);
	Gura_AssignValueScancodeKeycode(KP_RIGHTBRACE);
	Gura_AssignValueScancodeKeycode(KP_RIGHTPAREN);
	Gura_AssignValueScancodeKeycode(KP_SPACE);
	Gura_AssignValueScancodeKeycode(KP_TAB);
	Gura_AssignValueScancodeKeycode(KP_VERTICALBAR);
	Gura_AssignValueScancodeKeycode(KP_XOR);
	Gura_AssignValueScancodeKeycodeEx(L, l);
	Gura_AssignValueScancodeKeycode(LALT);
	Gura_AssignValueScancodeKeycode(LCTRL);
	Gura_AssignValueScancodeKeycode(LEFT);
	Gura_AssignValueScancodeKeycode(LEFTBRACKET);
	Gura_AssignValueScancodeKeycode(LGUI);
	Gura_AssignValueScancodeKeycode(LSHIFT);
	Gura_AssignValueScancodeKeycodeEx(M, m);
	Gura_AssignValueScancodeKeycode(MAIL);
	Gura_AssignValueScancodeKeycode(MEDIASELECT);
	Gura_AssignValueScancodeKeycode(MENU);
	Gura_AssignValueScancodeKeycode(MINUS);
	Gura_AssignValueScancodeKeycode(MODE);
	Gura_AssignValueScancodeKeycode(MUTE);
	Gura_AssignValueScancodeKeycodeEx(N, n);
	Gura_AssignValueScancodeKeycode(NUMLOCKCLEAR);
	Gura_AssignValueScancodeKeycodeEx(O, o);
	Gura_AssignValueScancodeKeycode(OPER);
	Gura_AssignValueScancodeKeycode(OUT);
	Gura_AssignValueScancodeKeycodeEx(P, p);
	Gura_AssignValueScancodeKeycode(PAGEDOWN);
	Gura_AssignValueScancodeKeycode(PAGEUP);
	Gura_AssignValueScancodeKeycode(PASTE);
	Gura_AssignValueScancodeKeycode(PAUSE);
	Gura_AssignValueScancodeKeycode(PERIOD);
	Gura_AssignValueScancodeKeycode(POWER);
	Gura_AssignValueScancodeKeycode(PRINTSCREEN);
	Gura_AssignValueScancodeKeycode(PRIOR);
	Gura_AssignValueScancodeKeycodeEx(Q, q);
	Gura_AssignValueScancodeKeycodeEx(R, r);
	Gura_AssignValueScancodeKeycode(RALT);
	Gura_AssignValueScancodeKeycode(RCTRL);
	Gura_AssignValueScancodeKeycode(RETURN);
	Gura_AssignValueScancodeKeycode(RETURN2);
	Gura_AssignValueScancodeKeycode(RGUI);
	Gura_AssignValueScancodeKeycode(RIGHT);
	Gura_AssignValueScancodeKeycode(RIGHTBRACKET);
	Gura_AssignValueScancodeKeycode(RSHIFT);
	Gura_AssignValueScancodeKeycodeEx(S, s);
	Gura_AssignValueScancodeKeycode(SCROLLLOCK);
	Gura_AssignValueScancodeKeycode(SELECT);
	Gura_AssignValueScancodeKeycode(SEMICOLON);
	Gura_AssignValueScancodeKeycode(SEPARATOR);
	Gura_AssignValueScancodeKeycode(SLASH);
	Gura_AssignValueScancodeKeycode(SLEEP);
	Gura_AssignValueScancodeKeycode(SPACE);
	Gura_AssignValueScancodeKeycode(STOP);
	Gura_AssignValueScancodeKeycode(SYSREQ);
	Gura_AssignValueScancodeKeycodeEx(T, t);
	Gura_AssignValueScancodeKeycode(TAB);
	Gura_AssignValueScancodeKeycode(THOUSANDSSEPARATOR);
	Gura_AssignValueScancodeKeycodeEx(U, u);
	Gura_AssignValueScancodeKeycode(UNDO);
	Gura_AssignValueScancodeKeycode(UNKNOWN);
	Gura_AssignValueScancodeKeycode(UP);
	Gura_AssignValueScancodeKeycodeEx(V, v);
	Gura_AssignValueScancodeKeycode(VOLUMEDOWN);
	Gura_AssignValueScancodeKeycode(VOLUMEUP);
	Gura_AssignValueScancodeKeycodeEx(W, w);
	Gura_AssignValueScancodeKeycode(WWW);
	Gura_AssignValueScancodeKeycodeEx(X, x);
	Gura_AssignValueScancodeKeycodeEx(Y, y);
	Gura_AssignValueScancodeKeycodeEx(Z, z);
	Gura_AssignValueScancode(INTERNATIONAL1);
	Gura_AssignValueScancode(INTERNATIONAL2);
	Gura_AssignValueScancode(INTERNATIONAL3);
	Gura_AssignValueScancode(INTERNATIONAL4);
	Gura_AssignValueScancode(INTERNATIONAL5);
	Gura_AssignValueScancode(INTERNATIONAL6);
	Gura_AssignValueScancode(INTERNATIONAL7);
	Gura_AssignValueScancode(INTERNATIONAL8);
	Gura_AssignValueScancode(INTERNATIONAL9);
	Gura_AssignValueScancode(LANG1);
	Gura_AssignValueScancode(LANG2);
	Gura_AssignValueScancode(LANG3);
	Gura_AssignValueScancode(LANG4);
	Gura_AssignValueScancode(LANG5);
	Gura_AssignValueScancode(LANG6);
	Gura_AssignValueScancode(LANG7);
	Gura_AssignValueScancode(LANG8);
	Gura_AssignValueScancode(LANG9);
	//Gura_AssignValueScancode(LOCKINGCAPSLOCK);
	//Gura_AssignValueScancode(LOCKINGNUMLOCK);
	//Gura_AssignValueScancode(LOCKINGSCROLLLOCK);
	Gura_AssignValueScancode(NONUSBACKSLASH);
	Gura_AssignValueScancode(NONUSHASH);
	Gura_AssignValueKeycode(AMPERSAND);
	Gura_AssignValueKeycode(ASTERISK);
	Gura_AssignValueKeycode(AT);
	Gura_AssignValueKeycode(CARET);
	Gura_AssignValueKeycode(COLON);
	Gura_AssignValueKeycode(DOLLAR);
	Gura_AssignValueKeycode(EXCLAIM);
	Gura_AssignValueKeycode(GREATER);
	Gura_AssignValueKeycode(HASH);
	Gura_AssignValueKeycode(LEFTPAREN);
	Gura_AssignValueKeycode(LESS);
	Gura_AssignValueKeycode(PERCENT);
	Gura_AssignValueKeycode(PLUS);
	Gura_AssignValueKeycode(QUESTION);
	Gura_AssignValueKeycode(QUOTEDBL);
	Gura_AssignValueKeycode(RIGHTPAREN);
	Gura_AssignValueKeycode(UNDERSCORE);
	Gura_AssignValueConst(KMOD_NONE);
	Gura_AssignValueConst(KMOD_LSHIFT);
	Gura_AssignValueConst(KMOD_RSHIFT);
	Gura_AssignValueConst(KMOD_LCTRL);
	Gura_AssignValueConst(KMOD_RCTRL);
	Gura_AssignValueConst(KMOD_LALT);
	Gura_AssignValueConst(KMOD_RALT);
	Gura_AssignValueConst(KMOD_LGUI);
	Gura_AssignValueConst(KMOD_RGUI);
	Gura_AssignValueConst(KMOD_NUM);
	Gura_AssignValueConst(KMOD_CAPS);
	Gura_AssignValueConst(KMOD_MODE);
	Gura_AssignValueConst(KMOD_CTRL);
	Gura_AssignValueConst(KMOD_SHIFT);
	Gura_AssignValueConst(KMOD_ALT);
	Gura_AssignValueConst(KMOD_GUI);
	Gura_AssignValueConst(KMOD_RESERVED);
	// Input Events - Mouse Support
	// Input Events - Joystick Support
	// Input Events - Game Controller Support
	Gura_AssignValueSDL(CONTROLLER_AXIS_INVALID);
	Gura_AssignValueSDL(CONTROLLER_AXIS_LEFTX);
	Gura_AssignValueSDL(CONTROLLER_AXIS_LEFTY);
	Gura_AssignValueSDL(CONTROLLER_AXIS_RIGHTX);
	Gura_AssignValueSDL(CONTROLLER_AXIS_RIGHTY);
	Gura_AssignValueSDL(CONTROLLER_AXIS_TRIGGERLEFT);
	Gura_AssignValueSDL(CONTROLLER_AXIS_TRIGGERRIGHT);
	Gura_AssignValueSDL(CONTROLLER_AXIS_MAX);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_INVALID);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_A);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_B);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_X);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_Y);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_BACK);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_GUIDE);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_START);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_LEFTSTICK);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_RIGHTSTICK);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_LEFTSHOULDER);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_RIGHTSHOULDER);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_DPAD_UP);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_DPAD_DOWN);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_DPAD_LEFT);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_DPAD_RIGHT);
	Gura_AssignValueSDL(CONTROLLER_BUTTON_MAX);
	// Force Feedback - Force Feedback Support
	Gura_AssignValueSDL(HAPTIC_SPRING);			// type of SDL_HapticCondition
	Gura_AssignValueSDL(HAPTIC_DAMPER);
	Gura_AssignValueSDL(HAPTIC_INERTIA);
	Gura_AssignValueSDL(HAPTIC_FRICTION);
	Gura_AssignValueSDL(HAPTIC_CONSTANT);		// type of SDL_HapticConstant
	Gura_AssignValueSDL(HAPTIC_CUSTOM);			// type of SDL_HapticCustom
	Gura_AssignValueSDL(HAPTIC_POLAR);			// type of SDL_HapticDirection
	Gura_AssignValueSDL(HAPTIC_CARTESIAN);
	Gura_AssignValueSDL(HAPTIC_SPHERICAL);
	Gura_AssignValueSDL(HAPTIC_LEFTRIGHT);		// type of SDL_HapticLeftRight
	Gura_AssignValueSDL(HAPTIC_SINE);			// type of SDL_HapticPeriodic
	//Gura_AssignValueSDL(HAPTIC_SQUARE);
	Gura_AssignValueSDL(HAPTIC_TRIANGLE);
	Gura_AssignValueSDL(HAPTIC_SAWTOOTHUP);
	Gura_AssignValueSDL(HAPTIC_SAWTOOTHDOWN);
	Gura_AssignValueSDL(HAPTIC_RAMP);			// type of SDL_HapticRamp
	// Audio - Audio Device Management, Playing and Recording
	Gura_AssignValueSDL(AUDIO_MASK_BITSIZE);	// Audio Format Macros
	Gura_AssignValueSDL(AUDIO_MASK_DATATYPE);
	Gura_AssignValueSDL(AUDIO_MASK_ENDIAN);
	Gura_AssignValueSDL(AUDIO_MASK_SIGNED);
	Gura_AssignValueConst(AUDIO_S8);			// Audio Format Values
	Gura_AssignValueConst(AUDIO_U8);
	Gura_AssignValueConst(AUDIO_S16LSB);
	Gura_AssignValueConst(AUDIO_S16MSB);
	Gura_AssignValueConst(AUDIO_S16SYS);
	Gura_AssignValueConst(AUDIO_S16);
	Gura_AssignValueConst(AUDIO_U16LSB);
	Gura_AssignValueConst(AUDIO_U16MSB);
	Gura_AssignValueConst(AUDIO_U16SYS);
	Gura_AssignValueConst(AUDIO_U16);
	Gura_AssignValueConst(AUDIO_S32LSB);
	Gura_AssignValueConst(AUDIO_S32MSB);
	Gura_AssignValueConst(AUDIO_S32SYS);
	Gura_AssignValueConst(AUDIO_S32);
	Gura_AssignValueConst(AUDIO_F32LSB);
	Gura_AssignValueConst(AUDIO_F32MSB);
	Gura_AssignValueConst(AUDIO_F32SYS);
	Gura_AssignValueConst(AUDIO_F32);
	Gura_AssignValueSDL(AUDIO_STOPPED);			// Audio Status
	Gura_AssignValueSDL(AUDIO_PLAYING);
	Gura_AssignValueSDL(AUDIO_PAUSED);
	Gura_AssignValueSDL(AUDIO_ALLOW_FREQUENCY_CHANGE);	// allowd_changes
	Gura_AssignValueSDL(AUDIO_ALLOW_FORMAT_CHANGE);
	Gura_AssignValueSDL(AUDIO_ALLOW_CHANNELS_CHANGE);
	Gura_AssignValueSDL(AUDIO_ALLOW_ANY_CHANGE);
	// Threads - Thread Management
	Gura_AssignValueSDL(THREAD_PRIORITY_LOW);
	Gura_AssignValueSDL(THREAD_PRIORITY_NORMAL);
	Gura_AssignValueSDL(THREAD_PRIORITY_HIGH);
	// Threads - Thread Synchronization Primitives
	// Threads - Atomic Operations
	// Timers - Timer Support
	// File Abstraction - Filesystem Paths
	// File Abstraction - File I/O Abstraction
	Gura_AssignValueSDL(RWOPS_UNKNOWN);
	Gura_AssignValueSDL(RWOPS_WINFILE);
	Gura_AssignValueSDL(RWOPS_STDFILE);
	Gura_AssignValueSDL(RWOPS_JNIFILE);
	Gura_AssignValueSDL(RWOPS_MEMORY);
	Gura_AssignValueSDL(RWOPS_MEMORY_RO);
	// Shared Object Support - Shared Object Loading and Function Lookup
	// Platform and CPU Information - Platform Detection
	// Platform and CPU Information - CPU Feature Detection
	// Platform and CPU Information - Byte Order and Byte Swapping
	Gura_AssignValueSDL(BYTEORDER);
	Gura_AssignValueSDL(LIL_ENDIAN);
	Gura_AssignValueSDL(BIG_ENDIAN);
	// Platform and CPU Information - Bit Manipulation
	// Power Management - Power Management Status
	Gura_AssignValueSDL(POWERSTATE_UNKNOWN);
	Gura_AssignValueSDL(POWERSTATE_ON_BATTERY);
	Gura_AssignValueSDL(POWERSTATE_NO_BATTERY);
	Gura_AssignValueSDL(POWERSTATE_CHARGING);
	Gura_AssignValueSDL(POWERSTATE_CHARGED);
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
		Gura_AssignFunction(PeepEvents);
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
		Gura_AssignFunction(SDL_GetPowerInfo);
		Gura_AssignFunction(AndroidGetActivity);
		Gura_AssignFunction(AndroidGetExternalStoragePath);
		Gura_AssignFunction(AndroidGetExternalStorageState);
		Gura_AssignFunction(AndroidGetInternalStoragePath);
		Gura_AssignFunction(AndroidGetJNIEnv);
		Gura_AssignFunction(acos);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_SDL(Signal &sig)
{
	const char *msg = ::SDL_GetError();
	if (*msg == '\0') {
		sig.SetError(ERR_RuntimeError, "%s", msg);
	}
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
