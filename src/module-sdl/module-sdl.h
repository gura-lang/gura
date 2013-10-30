//-----------------------------------------------------------------------------
// Gura sdl module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_SDL_H__
#define __GURA_MODULE_SDL_H__
#include <gura.h>
#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_mixer.h>
//#include <SDL_ttf.h>

#undef LoadImage

#define SDL_USEREVENT_Timer (SDL_NUMEVENTS - 1)

Gura_BeginModuleHeader(sdl, sdl)

// symbols in SDL_Event
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(gain);
Gura_DeclareUserSymbol(state);
Gura_DeclareUserSymbol(scancode);
Gura_DeclareUserSymbol(sym);
Gura_DeclareUserSymbol(mod);
Gura_DeclareUserSymbol(unicode);
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

const char *GetEventTypeName(Uint8 type);

//-----------------------------------------------------------------------------
// Object_Cursor declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Cursor);

class Object_Cursor : public Object {
public:
	Gura_DeclareObjectAccessor(Cursor)
private:
	SDL_Cursor *_pCursor;
public:
	inline Object_Cursor(SDL_Cursor *pCursor) :
			Object(Gura_UserClass(Cursor)), _pCursor(pCursor) {}
	inline Object_Cursor(const Object_Cursor &obj) : Object(obj) {}
	virtual ~Object_Cursor();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	void FreeCursor();
	inline SDL_Cursor *GetCursor() { return _pCursor; }
	inline static Value CreateValue(SDL_Cursor *pCursor) {
		return Value(new Object_Cursor(pCursor));
	}
};

//-----------------------------------------------------------------------------
// Object_Timer declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Timer);

class Object_Timer : public Object {
public:
	Gura_DeclareObjectAccessor(Timer)
private:
	SDL_TimerID _timerID;
	Signal _sig;
	Object_function *_pObjFunc;
	bool _threadFlag;
	bool _contFlag;
public:
	inline Object_Timer(Signal sig, Object_function *pObjFunc, bool threadFlag) :
		Object(Gura_UserClass(Timer)), _timerID(NULL),
		_sig(sig), _pObjFunc(pObjFunc), _threadFlag(threadFlag), _contFlag(false) {}
	virtual ~Object_Timer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline bool IsThread() const { return _threadFlag; }
	bool AddTimer(Uint32 interval);
	bool RemoveTimer();
	bool DoHandle();
	static Uint32 CallbackStub(Uint32 interval, void *param);
};

//-----------------------------------------------------------------------------
// Object_Event declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Event);

class Object_Event : public Object {
public:
	Gura_DeclareObjectAccessor(Event)
private:
	SDL_Event _event;
public:
	inline Object_Event(SDL_Event event) :
					Object(Gura_UserClass(Event)), _event(event) {}
	inline Object_Event(const Object_Event &obj) : Object(obj) {}
	virtual ~Object_Event();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline SDL_Event &GetEvent() { return _event; }
	inline const SDL_Event &GetEvent() const { return _event; }
	inline static Value CreateValue(const SDL_Event &event) {
		return Value(new Object_Event(event));
	}
};

//-----------------------------------------------------------------------------
// Object_Rect declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Rect);

class Object_Rect : public Object {
public:
	Gura_DeclareObjectAccessor(Rect)
private:
	SDL_Rect _rect;
public:
	inline Object_Rect(const SDL_Rect &rect) :
			Object(Gura_UserClass(Rect)), _rect(rect) {}
	inline Object_Rect(const Object_Rect &obj) : Object(obj) {}
	virtual ~Object_Rect();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Rect &GetRect() { return _rect; }
	inline const SDL_Rect &GetRect() const { return _rect; }
	inline static Value CreateValue(const SDL_Rect &rect) {
		return Value(new Object_Rect(rect));
	}
};

//-----------------------------------------------------------------------------
// Object_Color declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Color);

class Object_Color : public Object {
public:
	Gura_DeclareObjectAccessor(Color)
private:
	SDL_Color _color;
public:
	inline Object_Color(const SDL_Color &color) :
			Object(Gura_UserClass(Color)), _color(color) {}
	inline Object_Color(const Object_Color &obj) : Object(obj) {}
	virtual ~Object_Color();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Color &GetColor() { return _color; }
	inline const SDL_Color &GetColor() const { return _color; }
	inline static Value CreateValue(const SDL_Color &color) {
		return Value(new Object_Color(color));
	}
};

//-----------------------------------------------------------------------------
// Object_Palette declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Palette);

class Object_Palette : public Object {
public:
	Gura_DeclareObjectAccessor(Palette)
private:
	const SDL_Palette *_pPalette;
public:
	inline Object_Palette(const SDL_Palette *pPalette) :
			Object(Gura_UserClass(Palette)), _pPalette(pPalette) {}
	inline Object_Palette(const Object_Palette &obj) : Object(obj) {}
	virtual ~Object_Palette();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline static Value CreateValue(const SDL_Palette *pPalette) {
		return Value(new Object_Palette(pPalette));
	}
};

//-----------------------------------------------------------------------------
// Object_PixelFormat declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(PixelFormat);

class Object_PixelFormat : public Object {
public:
	Gura_DeclareObjectAccessor(PixelFormat)
private:
	SDL_PixelFormat _pixelFormat;
public:
	Object_PixelFormat(const SDL_PixelFormat &pixelFormat);
	inline Object_PixelFormat(const Object_PixelFormat &obj) : Object(obj) {}
	virtual ~Object_PixelFormat();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_PixelFormat *GetPixelFormat() { return &_pixelFormat; }
	inline const SDL_PixelFormat *GetPixelFormat() const { return &_pixelFormat; }
	inline static Value CreateValue(const SDL_PixelFormat &pixelFormat) {
		return Value(new Object_PixelFormat(pixelFormat));
	}
};

//-----------------------------------------------------------------------------
// Object_PixelFormat declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Surface);

class Object_Surface : public Object {
public:
	Gura_DeclareObjectAccessor(Surface)
private:
	SDL_Surface *_pSurface;
	AutoPtr<Image> _pImage;
public:
	inline Object_Surface(SDL_Surface *pSurface, Image *pImage) :
				Object(Gura_UserClass(Surface)), _pSurface(pSurface), _pImage(pImage) {}
	inline Object_Surface(const Object_Surface &obj) : Object(obj),
				_pImage(Image::Reference(obj._pImage.get())) {}
	inline SDL_Surface *GetSurface() { return _pSurface; }
	virtual ~Object_Surface();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline static Value CreateValue(SDL_Surface *pSurface, Image *pImage) {
		return Value(new Object_Surface(pSurface, pImage));
	}
	static Object_Surface *CreateSurfaceFromImage(Signal sig, Image *pImage);
};

//-----------------------------------------------------------------------------
// Object_Overlay declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Overlay);

class Object_Overlay : public Object {
public:
	Gura_DeclareObjectAccessor(Overlay)
private:
	SDL_Overlay *_pOverlay;
public:
	inline Object_Overlay(SDL_Overlay *pOverlay) :
				Object(Gura_UserClass(Overlay)), _pOverlay(pOverlay) {}
	inline Object_Overlay(const Object_Overlay &obj) : Object(obj) {}
	inline SDL_Overlay *GetOverlay() { return _pOverlay; }
	virtual ~Object_Overlay();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline static Value CreateValue(SDL_Overlay *pOverlay) {
		return Value(new Object_Overlay(pOverlay));
	}
};

//-----------------------------------------------------------------------------
// Object_VideoInfo declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(VideoInfo);

class Object_VideoInfo : public Object {
public:
	Gura_DeclareObjectAccessor(VideoInfo)
private:
	const SDL_VideoInfo *_pVideoInfo;
public:
	inline Object_VideoInfo(const SDL_VideoInfo *pVideoInfo) :
			Object(Gura_UserClass(VideoInfo)), _pVideoInfo(pVideoInfo) {}
	inline Object_VideoInfo(const Object_VideoInfo &obj) : Object(obj) {}
	virtual ~Object_VideoInfo();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline static Value CreateValue(const SDL_VideoInfo *pVideoInfo) {
		return Value(new Object_VideoInfo(pVideoInfo));
	}
};

#if 0
//-----------------------------------------------------------------------------
// Object_Font declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Font);

class Object_Font : public Object {
public:
	Gura_DeclareObjectAccessor(Font)
private:
	TTF_Font *_pFont;
public:
	inline Object_Font(TTF_Font *pFont) :
			Object(Gura_UserClass(Font)), _pFont(pFont) {}
	inline Object_Font(const Object_Font &obj) : Object(obj) {}
	virtual ~Object_Font();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline TTF_Font *GetFont() { return _pFont; }
	inline static Value CreateValue(TTF_Font *pFont) {
		return Value(new Object_Font(pFont));
	}
};
#endif

//-----------------------------------------------------------------------------
// Object_Joystick declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Joystick);

class Object_Joystick : public Object {
public:
	Gura_DeclareObjectAccessor(Joystick)
private:
	SDL_Joystick *_pJoystick;
public:
	inline Object_Joystick(SDL_Joystick *pJoystick) :
			Object(Gura_UserClass(Joystick)), _pJoystick(pJoystick) {}
	inline Object_Joystick(const Object_Joystick &obj) : Object(obj) {}
	virtual ~Object_Joystick();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline SDL_Joystick *GetJoystick() { return _pJoystick; }
	inline static Value CreateValue(SDL_Joystick *pJoystick) {
		return Value(new Object_Joystick(pJoystick));
	}
};

//-----------------------------------------------------------------------------
// Object_AudioSpec declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(AudioSpec);

class Object_AudioSpec : public Object {
public:
	Gura_DeclareObjectAccessor(AudioSpec)
private:
	SDL_AudioSpec *_pAudioSpec;
	Signal _sig;
	Function *_pFuncCallback;
	Uint8 *_audio_buf;
	Uint32 _audio_len;
public:
	inline Object_AudioSpec(SDL_AudioSpec *pAudioSpec,
		Signal sig, Function *pFuncCallback, Uint8 *audio_buf, Uint32 audio_len) :
			Object(Gura_UserClass(AudioSpec)),
			_pAudioSpec(pAudioSpec), _sig(sig), _pFuncCallback(pFuncCallback),
			_audio_buf(audio_buf), _audio_len(audio_len) {}
	inline Object_AudioSpec(const Object_AudioSpec &obj) : Object(obj) {}
	virtual ~Object_AudioSpec();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline SDL_AudioSpec *GetAudioSpec() { return _pAudioSpec; }
	inline Uint8 *GetAudioBuf() { return _audio_buf; }
	inline Uint32 GetAudioLen() { return _audio_len; }
	inline static Value CreateValue(SDL_AudioSpec *pAudioSpec,
			Signal sig,  Function *pFuncCallback, Uint8 *audio_buf, Uint32 audio_len) {
		return Value(new Object_AudioSpec(pAudioSpec, sig, pFuncCallback, audio_buf, audio_len));
	}
	void Callback(Uint8 *stream, int len);
	static void CallbackStub(void *userdata, Uint8 *stream, int len);
};

//-----------------------------------------------------------------------------
// Object_AudioCVT declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(AudioCVT);

class Object_AudioCVT : public Object {
public:
	Gura_DeclareObjectAccessor(AudioCVT)
private:
	SDL_AudioCVT *_pAudioCVT;
public:
	inline Object_AudioCVT(SDL_AudioCVT *pAudioCVT) :
			Object(Gura_UserClass(AudioCVT)), _pAudioCVT(pAudioCVT) {}
	inline Object_AudioCVT(const Object_AudioCVT &obj) : Object(obj) {}
	virtual ~Object_AudioCVT();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline SDL_AudioCVT *GetAudioCVT() { return _pAudioCVT; }
	inline static Value CreateValue(SDL_AudioCVT *pAudioCVT) {
		return Value(new Object_AudioCVT(pAudioCVT));
	}
};

//-----------------------------------------------------------------------------
// Object_CDtrack declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CDtrack);

class Object_CDtrack : public Object {
public:
	Gura_DeclareObjectAccessor(CDtrack)
private:
	SDL_CDtrack _CDtrack;
public:
	inline Object_CDtrack(const SDL_CDtrack &CDtrack) : Object(Gura_UserClass(CDtrack)), _CDtrack(CDtrack) {}
	inline Object_CDtrack(const Object_CDtrack &obj) : Object(obj) {}
	virtual ~Object_CDtrack();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline SDL_CDtrack &GetCDtrack() { return _CDtrack; }
	inline static Value CreateValue(const SDL_CDtrack &CDtrack) {
		return Value(new Object_CDtrack(CDtrack));
	}
};

//-----------------------------------------------------------------------------
// Object_CD declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CD);

class Object_CD : public Object {
public:
	Gura_DeclareObjectAccessor(CD)
private:
	SDL_CD *_pCD;
public:
	inline Object_CD(SDL_CD *pCD) : Object(Gura_UserClass(CD)), _pCD(pCD) {}
	inline Object_CD(const Object_CD &obj) : Object(obj) {}
	virtual ~Object_CD();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline SDL_CD *GetCD() { return _pCD; }
	inline static Value CreateValue(SDL_CD *pCD) {
		return Value(new Object_CD(pCD));
	}
};

Gura_EndModuleHeader(sdl, sdl)

#endif
