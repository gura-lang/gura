#ifndef __SDL2_RWOPSSTREAM_H__
#define __SDL2_RWOPSSTREAM_H__

Gura_BeginModuleScope(sdl2)

struct RWopsStream {
	SDL_RWops context;
	Stream *pStream;
	Signal *pSig;
};

SDL_RWops *CreateRWFromStream(Stream *pStream, Signal *pSig);

Gura_EndModuleScope(sdl2)

#endif
