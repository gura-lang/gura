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

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
void AssignValues(Environment &env);
void AssignFunctions(Environment &env);

Gura_ModuleEntry()
{
	// sumbols
	Gura_RealizeUserSymbol(Aloss);
	Gura_RealizeUserSymbol(Amask);
	Gura_RealizeUserSymbol(Ashift);
	Gura_RealizeUserSymbol(BitsPerPixel);
	Gura_RealizeUserSymbol(Bloss);
	Gura_RealizeUserSymbol(Bmask);
	Gura_RealizeUserSymbol(Bshift);
	Gura_RealizeUserSymbol(BytesPerPixel);
	Gura_RealizeUserSymbol(Gloss);
	Gura_RealizeUserSymbol(Gmask);
	Gura_RealizeUserSymbol(Gshift);
	Gura_RealizeUserSymbol(Rloss);
	Gura_RealizeUserSymbol(Rmask);
	Gura_RealizeUserSymbol(Rshift);
	Gura_RealizeUserSymbol(alpha);
	Gura_RealizeUserSymbol(axis);
	Gura_RealizeUserSymbol(b);
	Gura_RealizeUserSymbol(ball);
	Gura_RealizeUserSymbol(blit_fill);
	Gura_RealizeUserSymbol(blit_hw);
	Gura_RealizeUserSymbol(blit_hw_A);
	Gura_RealizeUserSymbol(blit_hw_CC);
	Gura_RealizeUserSymbol(blit_sw);
	Gura_RealizeUserSymbol(blit_sw_A);
	Gura_RealizeUserSymbol(blit_sw_CC);
	Gura_RealizeUserSymbol(button);
	Gura_RealizeUserSymbol(clicks);
	Gura_RealizeUserSymbol(clip_rect);
	Gura_RealizeUserSymbol(code);
	Gura_RealizeUserSymbol(colorkey);
	Gura_RealizeUserSymbol(cur_frame);
	Gura_RealizeUserSymbol(cur_track);
	Gura_RealizeUserSymbol(dDist);
	Gura_RealizeUserSymbol(dTheta);
	Gura_RealizeUserSymbol(data1);
	Gura_RealizeUserSymbol(data2);
	Gura_RealizeUserSymbol(dx);
	Gura_RealizeUserSymbol(dy);
	Gura_RealizeUserSymbol(error);
	Gura_RealizeUserSymbol(event);
	Gura_RealizeUserSymbol(file);
	Gura_RealizeUserSymbol(fingerId);
	Gura_RealizeUserSymbol(flags);
	Gura_RealizeUserSymbol(format);
	Gura_RealizeUserSymbol(g);
	Gura_RealizeUserSymbol(gain);
	Gura_RealizeUserSymbol(gestureId);
	Gura_RealizeUserSymbol(h);
	Gura_RealizeUserSymbol(hat);
	Gura_RealizeUserSymbol(hw_available);
	Gura_RealizeUserSymbol(id);
	Gura_RealizeUserSymbol(length);
	Gura_RealizeUserSymbol(mod);
	Gura_RealizeUserSymbol(numFingers);
	Gura_RealizeUserSymbol(numtracks);
	Gura_RealizeUserSymbol(offset);
	Gura_RealizeUserSymbol(palette);
	Gura_RealizeUserSymbol(pitch);
	Gura_RealizeUserSymbol(pixels);
	Gura_RealizeUserSymbol(pressure);
	Gura_RealizeUserSymbol(r);
	Gura_RealizeUserSymbol(refcount);
	Gura_RealizeUserSymbol(refresh_rate);
	Gura_RealizeUserSymbol(repeat);
	Gura_RealizeUserSymbol(scancode);
	Gura_RealizeUserSymbol(start);
	Gura_RealizeUserSymbol(state);
	Gura_RealizeUserSymbol(status);
	Gura_RealizeUserSymbol(sym);
	Gura_RealizeUserSymbol(text);
	Gura_RealizeUserSymbolAlias(thread_, "thread");
	Gura_RealizeUserSymbol(timestamp);
	Gura_RealizeUserSymbol(touchId);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(value);
	Gura_RealizeUserSymbol(vfmt);
	Gura_RealizeUserSymbol(video_mem);
	Gura_RealizeUserSymbol(w);
	Gura_RealizeUserSymbol(which);
	Gura_RealizeUserSymbol(windowID);
	Gura_RealizeUserSymbol(wm_available);
	Gura_RealizeUserSymbol(x);
	Gura_RealizeUserSymbol(xrel);
	Gura_RealizeUserSymbol(y);
	Gura_RealizeUserSymbol(yrel);
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
	RealizeClass(JoystickGUID);
	RealizeClass(GameController);
	RealizeClass(GameControllerButtonBind);
	RealizeClass(AudioCVT);
	RealizeClass(AudioSpec);
	RealizeClass(Wav);
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
	PrepareClass(JoystickGUID);
	PrepareClass(GameController);
	PrepareClass(GameControllerButtonBind);
	PrepareClass(AudioCVT);
	PrepareClass(AudioSpec);
	PrepareClass(Wav);
	PrepareClass(RendererInfo);
	PrepareClass(DisplayMode);
	PrepareClass(GLContext);
	PrepareClass(HapticEffect);
	PrepareClass(Surface);
	PrepareClass(Finger);
	AssignValues(env);
	AssignFunctions(env);
	return true;
}

void AssignValues(Environment &env)
{
	Gura_AssignValueSDL(QUERY);
	Gura_AssignValueSDL(IGNORE);
	Gura_AssignValueSDL(ENABLE);
	Gura_AssignValueSDL(DISABLE);
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
	Gura_AssignValueSDL(HAT_CENTERED);
	Gura_AssignValueSDL(HAT_UP);
	Gura_AssignValueSDL(HAT_RIGHT);
	Gura_AssignValueSDL(HAT_DOWN);
	Gura_AssignValueSDL(HAT_LEFT);
	Gura_AssignValueSDL(HAT_RIGHTUP);
	Gura_AssignValueSDL(HAT_RIGHTDOWN);
	Gura_AssignValueSDL(HAT_LEFTUP);
	Gura_AssignValueSDL(HAT_LEFTDOWN);
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
