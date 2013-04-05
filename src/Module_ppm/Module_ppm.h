//-----------------------------------------------------------------------------
// Gura ppm module
// PPM specification:
// http://local.wasp.uwa.edu.au/~pbourke/dataformats/ppm/
//-----------------------------------------------------------------------------
#ifndef __MODULE_PPM_H__
#define __MODULE_PPM_H__
#include <gura.h>

Gura_BeginModule(ppm)

//-----------------------------------------------------------------------------
// ImageStreamer_PPM
//-----------------------------------------------------------------------------
class ImageStreamer_PPM : public ImageStreamer {
public:
	inline ImageStreamer_PPM() : ImageStreamer("ppm") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Image *pImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Image *pImage, Stream &stream);
public:
	static bool ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream);
	static bool WriteStream(Environment &env, Signal sig, Image *pImage,
										Stream &stream, bool grayFlag);
	static void SetError_InvalidPPMFormat(Signal sig);
};

}}

#endif
