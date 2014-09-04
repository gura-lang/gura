//=============================================================================
// Gura module: sdl2
//=============================================================================
#ifndef __GURA_MODULE_SDL2_H__
#define __GURA_MODULE_SDL2_H__
#include <SDL.h>
#include <gura.h>
#include "Class_Window.h"
#include "Class_Renderer.h"
#include "Class_Texture.h"
#include "Class_Event.h"
#include "Class_Point.h"
#include "Class_Rect.h"
#include "Class_Color.h"
#include "Class_Palette.h"
#include "Class_PixelFormat.h"
#include "Class_Keysym.h"
#include "Class_Cursor.h"
#include "Class_Joystick.h"
#include "Class_GameController.h"
#include "Class_AudioCVT.h"
#include "Class_AudioSpec.h"
#include "Class_RendererInfo.h"
#include "Class_DisplayMode.h"
#include "Class_GLContext.h"

Gura_BeginModuleHeader(sdl2)

void SetError_SDL(Signal &sig);

Gura_EndModuleHeader(sdl2)

#endif
