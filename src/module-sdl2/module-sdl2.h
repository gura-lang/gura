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
#include "Class_GameControllerButtonBind.h"
#include "Class_AudioCVT.h"
#include "Class_AudioSpec.h"
#include "Class_RendererInfo.h"
#include "Class_DisplayMode.h"
#include "Class_GLContext.h"
#include "Class_Haptic.h"
#include "Class_HapticEffect.h"
#include "Class_Surface.h"
#include "Class_Finger.h"

Gura_BeginModuleHeader(sdl2)

template<typename T>
class CArray {
private:
	AutoPtr<Memory> _pMemory;
public:
	CArray(size_t n) {
		_pMemory.reset(new MemoryHeap(sizeof(T) * n));
	}
	CArray(const ValueList &valList) {
		size_t n = valList.size();
		_pMemory.reset(new MemoryHeap(sizeof(T) * n));
		T *p = reinterpret_cast<T *>(_pMemory->GetPointer());
		foreach_const (ValueList, pValue, valList) {
			*p++ = static_cast<T>(pValue->GetNumber());
		}
	}
	CArray(const CArray &src) {
		_pMemory.reset(src._pMemory->Reference());
	}
	inline size_t GetSize() const { return _pMemory->GetSize() / sizeof(T); }
	inline operator T *() {
		return reinterpret_cast<T *>(_pMemory->GetPointer());
	}
	inline const operator T *() const  {
		return reinterpret_cast<T *>(_pMemory->GetPointer());
	}
};

// symbols in SDL_Event
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(gain);
Gura_DeclareUserSymbol(state);
Gura_DeclareUserSymbol(scancode);
Gura_DeclareUserSymbol(sym);
Gura_DeclareUserSymbol(mod);
Gura_DeclareUserSymbol(x);
Gura_DeclareUserSymbol(y);
Gura_DeclareUserSymbol(xrel);
Gura_DeclareUserSymbol(yrel);
Gura_DeclareUserSymbol(axis);
Gura_DeclareUserSymbol(value);
Gura_DeclareUserSymbol(button);
Gura_DeclareUserSymbol(which);
Gura_DeclareUserSymbol(hat);
Gura_DeclareUserSymbol(ball);
Gura_DeclareUserSymbol(w);
Gura_DeclareUserSymbol(h);

Gura_DeclareUserSymbol(timestamp);
Gura_DeclareUserSymbol(windowID);
Gura_DeclareUserSymbol(event);
Gura_DeclareUserSymbol(data1);
Gura_DeclareUserSymbol(data2);
Gura_DeclareUserSymbol(text);
Gura_DeclareUserSymbol(start);
Gura_DeclareUserSymbol(repeat);

Gura_DeclareUserSymbol(clicks);
Gura_DeclareUserSymbol(code);
Gura_DeclareUserSymbol(touchId);
Gura_DeclareUserSymbol(fingerId);
Gura_DeclareUserSymbol(gestureId);
Gura_DeclareUserSymbol(dx);
Gura_DeclareUserSymbol(dy);
Gura_DeclareUserSymbol(pressure);
Gura_DeclareUserSymbol(dTheta);
Gura_DeclareUserSymbol(dDist);
Gura_DeclareUserSymbol(numFingers);
Gura_DeclareUserSymbol(error);
Gura_DeclareUserSymbol(file);

// symbols in SDL_Color
Gura_DeclareUserSymbol(r)
Gura_DeclareUserSymbol(g)
Gura_DeclareUserSymbol(b)
// symbols in SDL_PixelFormat
Gura_DeclareUserSymbol(palette);
Gura_DeclareUserSymbol(BitsPerPixel);
Gura_DeclareUserSymbol(BytesPerPixel);
Gura_DeclareUserSymbol(Rloss);
Gura_DeclareUserSymbol(Gloss);
Gura_DeclareUserSymbol(Bloss);
Gura_DeclareUserSymbol(Aloss);
Gura_DeclareUserSymbol(Rshift);
Gura_DeclareUserSymbol(Gshift);
Gura_DeclareUserSymbol(Bshift);
Gura_DeclareUserSymbol(Ashift);
Gura_DeclareUserSymbol(Rmask);
Gura_DeclareUserSymbol(Gmask);
Gura_DeclareUserSymbol(Bmask);
Gura_DeclareUserSymbol(Amask);
Gura_DeclareUserSymbol(colorkey);
Gura_DeclareUserSymbol(alpha);
// symbols in SDL_Surface
Gura_DeclareUserSymbol(flags)
Gura_DeclareUserSymbol(format)
Gura_DeclareUserSymbol(pitch)
Gura_DeclareUserSymbol(pixels)
Gura_DeclareUserSymbol(clip_rect)
Gura_DeclareUserSymbol(refcount)
// symbols in SDL_VideoInfo
Gura_DeclareUserSymbol(hw_available);
Gura_DeclareUserSymbol(wm_available);
Gura_DeclareUserSymbol(blit_hw);
Gura_DeclareUserSymbol(blit_hw_CC);
Gura_DeclareUserSymbol(blit_hw_A);
Gura_DeclareUserSymbol(blit_sw);
Gura_DeclareUserSymbol(blit_sw_CC);
Gura_DeclareUserSymbol(blit_sw_A);
Gura_DeclareUserSymbol(blit_fill);
Gura_DeclareUserSymbol(video_mem);
Gura_DeclareUserSymbol(vfmt);
// symbols in SDL_CDtrack
Gura_DeclareUserSymbol(id)
Gura_DeclareUserSymbol(length)
Gura_DeclareUserSymbol(offset)
// symbols in SDL_CD
Gura_DeclareUserSymbol(status)
Gura_DeclareUserSymbol(numtracks)
Gura_DeclareUserSymbol(cur_track)
Gura_DeclareUserSymbol(cur_frame)
// symbols for other purposes
Gura_DeclareUserSymbol(thread_);

CArray<SDL_Point> CreateCArrayOfPoint(const ValueList &valList);
CArray<SDL_Rect> CreateCArrayOfRect(const ValueList &valList);

void SetError_SDL(Signal &sig);
void SetError_NotImpFunction(Signal &sig, const char *funcName);
void SetError_NotImpMethod(Signal &sig, const char *className, const char *methodName);

Gura_EndModuleHeader(sdl2)

#endif
