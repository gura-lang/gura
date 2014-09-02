//=============================================================================
// Gura module: sdl2
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(sdl2)

//-----------------------------------------------------------------------------
// SDL functions: Initialization and Shutdown
//-----------------------------------------------------------------------------
// sdl2.Init(flags:number)
Gura_DeclareFunction(Init)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(Init)
{
	Uint32 flags = args.GetULong(0);
	int rtn = ::SDL_Init(flags);
	return Value(rtn);
}

// sdl2.InitSubSystem(flags:number)
Gura_DeclareFunction(InitSubSystem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "flags", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(InitSubSystem)
{
	Uint32 flags = args.GetULong(0);
	int rtn = ::SDL_InitSubSystem(flags);
	return Value(rtn);
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
	// function assignment
	// Initialization and Shutdown
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

Gura_EndModuleBody(sdl2, sdl2)

Gura_RegisterModule(sdl2)
