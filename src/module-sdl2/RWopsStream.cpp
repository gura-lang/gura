#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// RWopsStream
//-----------------------------------------------------------------------------
static Sint64 RWops_size(SDL_RWops *context)
{
	RWopsStream *contextEx = reinterpret_cast<RWopsStream *>(context);
	Stream *pStream = contextEx->pStream;
	Signal &sig = *contextEx->pSig;
	return static_cast<Sint64>(pStream->GetSize());
}

static Sint64 RWops_seek(SDL_RWops *context, Sint64 offset, int whence)
{
	RWopsStream *contextEx = reinterpret_cast<RWopsStream *>(context);
	Stream *pStream = contextEx->pStream;
	Signal &sig = *contextEx->pSig;
	Stream::SeekMode seekMode = Stream::SeekSet;
	if (whence == RW_SEEK_SET) {
		seekMode = Stream::SeekSet;
	} else if (whence == RW_SEEK_CUR) {
		seekMode = Stream::SeekCur;
	} else if (whence == RW_SEEK_END) {
		seekMode = Stream::SeekEnd;
	} else {
		sig.SetError(ERR_ValueError, "invalid value for whence");
		return -1;
	}
	if (!pStream->Seek(sig, static_cast<long>(offset), seekMode)) return -1;
	return static_cast<Sint64>(pStream->Tell());
}

static size_t RWops_read(SDL_RWops *context, void *ptr, size_t size, size_t maxnum)
{
	RWopsStream *contextEx = reinterpret_cast<RWopsStream *>(context);
	Stream *pStream = contextEx->pStream;
	Signal &sig = *contextEx->pSig;
	size_t rtn = pStream->Read(sig, ptr, size * maxnum);
	return rtn / size;
}

static size_t RWops_write(SDL_RWops *context, const void *ptr, size_t size, size_t num)
{
	RWopsStream *contextEx = reinterpret_cast<RWopsStream *>(context);
	Stream *pStream = contextEx->pStream;
	Signal &sig = *contextEx->pSig;
	size_t rtn = pStream->Write(sig, ptr, size * num);
	return rtn / size;
}

static int RWops_close(SDL_RWops *context)
{
	RWopsStream *contextEx = reinterpret_cast<RWopsStream *>(context);
	Stream *pStream = contextEx->pStream;
	Signal &sig = *contextEx->pSig;
	return pStream->Close()? 0 : -1;
}

SDL_RWops *CreateRWopsStream(Stream *pStream, Signal *pSig)
{
	RWopsStream *contextEx = new RWopsStream();
	contextEx->context.size = RWops_size;
	contextEx->context.seek = RWops_seek;
	contextEx->context.read = RWops_read;
	contextEx->context.write = RWops_write;
	contextEx->context.close = RWops_close;
	contextEx->context.type = SDL_RWOPS_UNKNOWN;
	contextEx->pStream = pStream;
	contextEx->pSig = pSig;
	return reinterpret_cast<SDL_RWops *>(contextEx);
}

Gura_EndModuleScope(sdl2)
