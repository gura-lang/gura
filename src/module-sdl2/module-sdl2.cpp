//=============================================================================
// Gura module: sdl2
//=============================================================================
#include "stdafx.h"

#undef CreateWindow

#define RealizeClass(className) \
Gura_RealizeUserClassExWithoutPrepare(##className, #className, env.LookupClass(VTYPE_object))

#define PrepareClass(className) \
Gura_UserClass(className)->Prepare(env)

Gura_BeginModuleBody(sdl2)

//-----------------------------------------------------------------------------
// Basics - Initialization and Shutdown
//-----------------------------------------------------------------------------
// sdl2.Init(flags:number):void
Gura_DeclareFunction(Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Init)
{
	Uint32 flags = args.GetULong(0);
	int rtn = ::SDL_Init(flags);
	if (rtn < 0) {
		SetError_SDL(sig);
	}
	return Value::Null;
}

// sdl2.InitSubSystem(flags:number):void
Gura_DeclareFunction(InitSubSystem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(InitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	int rtn = ::SDL_InitSubSystem(flags);
	if (rtn < 0) {
		SetError_SDL(sig);
	}
	return Value::Null;
}

// sdl2.Quit():void
Gura_DeclareFunction(Quit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Quit)
{
	::SDL_Quit();
	return Value::Null;
}

// sdl2.QuitSubSystem(flags:number):void
Gura_DeclareFunction(QuitSubSystem)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(QuitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	::SDL_QuitSubSystem(flags);
	return Value::Null;
}

// sdl2.SetMainReady():void
Gura_DeclareFunction(SetMainReady)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(SetMainReady)
{
	::SDL_SetMainReady();
	return Value::Null;
}

// sdl2.WasInit(flags:number)
Gura_DeclareFunction(WasInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(WasInit)
{
	Uint32 flags = args.GetULong(0);
	Uint32 rtn = ::SDL_WasInit(flags);
	return Value(rtn);
}

//-----------------------------------------------------------------------------
// Basics - Configuration Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Basics - Error Handling
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Basics - Log Handling
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Basics - Assertions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Basics - Querying SDL Version
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Video - Display and Window Management
//-----------------------------------------------------------------------------
// sdl2.CreateWindow(title:string, x:number, y:number, w:number, h:number, flags:number)
Gura_DeclareFunction(CreateWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "title", VTYPE_string);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "w", VTYPE_number);
	DeclareArg(env, "h", VTYPE_number);
	DeclareArg(env, "flags", VTYPE_number);
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
	SDL_Window *rtn = ::SDL_CreateWindow(title, x, y, w, h, flags);
	return Value(new Object_Window(rtn));
}

// sdl2.CreateWindowAndRenderer(w:number, h:number, window_flags:number)
Gura_DeclareFunction(CreateWindowAndRenderer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "w", VTYPE_number);
	DeclareArg(env, "h", VTYPE_number);
	DeclareArg(env, "window_flags", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(CreateWindowAndRenderer)
{
	int w = args.GetInt(0);
	int h = args.GetInt(1);
	Uint32 window_flags = args.GetULong(2);
	SDL_Window *pWindow = NULL;
	SDL_Renderer *pRenderer = NULL;
	int rtn = ::SDL_CreateWindowAndRenderer(w, h, window_flags, &pWindow, &pRenderer);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value::CreateAsList(env,
		Value(new Object_Window(pWindow)), Value(new Object_Renderer(pRenderer)));
}

//-----------------------------------------------------------------------------
// Video - 2D Accelerated Rendering
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Video - Pixel Formats and Conversion Routines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Video - Rectangle Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Video - Surface Creation and Simple Drawing
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Video - Platform-specific Window Management
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Video - Clipboard Handling
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Input Events - Event Handling
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Input Events - Keyboard Support
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Input Events - Mouse Support
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Input Events - Joystick Support
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Input Events - Game Controller Support
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Force Feedback - Force Feedback Support
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Audio - Audio Device Management, Playing and Recording
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Threads - Thread Management
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Threads - Thread Synchronization Primitives
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Threads - Atomic Operations
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Timers - Timer Support
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// File Abstraction - Filesystem Paths
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// File Abstraction - File I/O Abstraction
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Shared Object Support - Shared Object Loading and Function Lookup
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Platform and CPU Information - Platform Detection
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Platform and CPU Information - CPU Feature Detection
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Platform and CPU Information - Byte Order and Byte Swapping
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Platform and CPU Information - Bit Manipulation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Power Management - Power Management Status
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Additional - Platform-specific functionality
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Additional - Other
//-----------------------------------------------------------------------------

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
Gura_ModuleEntry()
{
	// class realization
	RealizeClass(Window);
	RealizeClass(Renderer);
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
	RealizeClass(DisplayMode);
	// class preparation
	PrepareClass(Window);
	PrepareClass(Renderer);
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
	PrepareClass(DisplayMode);
	// function assignment
	// Basics - Initialization and Shutdown
	Gura_AssignFunction(Init);
	Gura_AssignFunction(InitSubSystem);
	Gura_AssignFunction(Quit);
	Gura_AssignFunction(QuitSubSystem);
	Gura_AssignFunction(SetMainReady);
	Gura_AssignFunction(test);
	return true;
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

Gura_EndModuleBody(sdl2, sdl2)

Gura_RegisterModule(sdl2)
