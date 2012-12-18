//-----------------------------------------------------------------------------
// Gura jpeg module
//-----------------------------------------------------------------------------
#ifndef __MODULE_JPEG_H__
#define __MODULE_JPEG_H__
#include <gura.h>
extern "C" {
#include <jpeglib.h>
#include <jerror.h>
#include <setjmp.h>
}

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// ImageStreamer_JPEG
//-----------------------------------------------------------------------------
class ImageStreamer_JPEG : public ImageStreamer {
public:
	inline ImageStreamer_JPEG() : ImageStreamer("jpeg") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
public:
	static bool ReadStream(Signal sig, Object_image *pObjImage, Stream &stream);
	static bool WriteStream(Signal sig,
						Object_image *pObjImage, Stream &stream, int quality);
};

//-----------------------------------------------------------------------------
// ErrorMgr
//-----------------------------------------------------------------------------
struct ErrorMgr {
	jpeg_error_mgr pub;
	jmp_buf jmpenv;
	Signal &_sig;
	inline ErrorMgr(Signal &sig) : _sig(sig) {}
	static void error_exit(j_common_ptr cinfo);
};

//-----------------------------------------------------------------------------
// SourceMgr
//-----------------------------------------------------------------------------
struct SourceMgr {
	jpeg_source_mgr pub;
	Signal *pSig;
	Stream *pStream;
	JOCTET *buff;
	bool firstFlag;
	enum { BuffSize = 4096 };
	static void Setup(j_decompress_ptr cinfo, Signal *pSig, Stream *pStream);
	static void init_source(j_decompress_ptr cinfo);
	static boolean fill_input_buffer(j_decompress_ptr cinfo);
	static void skip_input_data(j_decompress_ptr cinfo, long num_bytes);
	static void term_source(j_decompress_ptr cinfo);
};

//-----------------------------------------------------------------------------
// DestinationMgr
//-----------------------------------------------------------------------------
struct DestinationMgr {
	jpeg_destination_mgr pub;
	Signal *pSig;
	Stream *pStream;
	JOCTET *buffer;
	enum { BuffSize = 4096 };
	static void Setup(j_compress_ptr cinfo, Signal *pSig, Stream *pStream);
	static void init_destination(j_compress_ptr cinfo);
	static boolean empty_output_buffer(j_compress_ptr cinfo);
	static void term_destination(j_compress_ptr cinfo);
};

}}

#endif
