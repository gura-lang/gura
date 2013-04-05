//-----------------------------------------------------------------------------
// Gura png module
//-----------------------------------------------------------------------------
#ifndef __MODULE_PNG_H__
#define __MODULE_PNG_H__

#include <gura.h>
#include <png.h>
#include <setjmp.h>

Gura_BeginModule(png)

//-----------------------------------------------------------------------------
// ImageStreamer_PNG
//-----------------------------------------------------------------------------
class ImageStreamer_PNG : public ImageStreamer {
public:
	inline ImageStreamer_PNG() : ImageStreamer("png") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Image *pImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Image *pImage, Stream &stream);
public:
	static bool ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream);
	static bool WriteStream(Environment &env, Signal sig, Image *pImage, Stream &stream);
};

//-----------------------------------------------------------------------------
// Handler
//-----------------------------------------------------------------------------
class Handler {
private:
	Signal _sig;
	Stream &_stream;
public:
	inline Handler(Signal sig, Stream &stream) : _sig(sig), _stream(stream) {}
	inline Signal &GetSignal() { return _sig; }
	inline Stream &GetStream() { return _stream; }
public:
	static void Error(png_structp png_ptr, png_const_charp error_msg);
	static void Warning(png_structp png_ptr, png_const_charp warning_msg);
	static void ReadData(png_structp png_ptr, png_bytep data, png_size_t length);
	static void WriteData(png_structp png_ptr, png_bytep data, png_size_t length);
	static void FlushData(png_structp png_ptr);
};

}}

#endif
