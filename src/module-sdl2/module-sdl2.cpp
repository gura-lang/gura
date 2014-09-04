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

// sdl2.DisableScreenSaver():void
Gura_DeclareFunction(DisableScreenSaver)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(DisableScreenSaver)
{
	::SDL_DisableScreenSaver();
	return Value::Null;
}

// sdl2.EnableScreenSaver():void
Gura_DeclareFunction(EnableScreenSaver)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(EnableScreenSaver)
{
	::SDL_EnableScreenSaver();
	return Value::Null;
}

// sdl2.GL_ExtensionSupported(extension:string):map
Gura_DeclareFunction(GL_ExtensionSupported)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_ExtensionSupported)
{
	const char *extension = args.GetString(0);
	SDL_bool rtn = ::SDL_GL_ExtensionSupported(extension);
	return Value(rtn == SDL_TRUE);
}

// sdl2.GL_GetAttribute(attr:number):map
Gura_DeclareFunction(GL_GetAttribute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(GL_GetAttribute)
{
	SDL_GLattr attr = static_cast<SDL_GLattr>(args.GetInt(0));
	int value = 0;
	int rtn = ::SDL_GL_GetAttribute(attr, &value);
	if (rtn < 0) {
		SetError_SDL(sig);
		return Value::Null;
	}
	return Value(value);
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
	// Basics - Initialization and Shutdown
	Gura_AssignFunction(Init);
	Gura_AssignFunction(InitSubSystem);
	Gura_AssignFunction(Quit);
	Gura_AssignFunction(QuitSubSystem);
	Gura_AssignFunction(SetMainReady);
	Gura_AssignFunction(test);
	// Basics - Configuration Variables
	// Basics - Error Handling
	// Basics - Log Handling
	// Basics - Assertions
	// Basics - Querying SDL Version
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
	Gura_AssignFunction(CreateWindow);
	Gura_AssignFunction(CreateWindowAndRenderer);
	Gura_AssignFunction(DisableScreenSaver);
	Gura_AssignFunction(EnableScreenSaver);
	Gura_AssignFunction(GL_ExtensionSupported);
	Gura_AssignFunction(GL_GetAttribute);
	
	
	
	
	
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
