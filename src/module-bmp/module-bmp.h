//-----------------------------------------------------------------------------
// Gura bmp module
//-----------------------------------------------------------------------------
#ifndef __MODULE_BMP_H__
#define __MODULE_BMP_H__
#include <gura.h>

Gura_BeginModuleHeader(bmp, bmp)

//-----------------------------------------------------------------------------
// ImageStreamer_BMP
//-----------------------------------------------------------------------------
class ImageStreamer_BMP : public ImageStreamer {
public:
	inline ImageStreamer_BMP() : ImageStreamer("bmp") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Image *pImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Image *pImage, Stream &stream);
public:
	static bool ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream);
	static bool WriteStream(Environment &env, Signal sig, Image *pImage, Stream &stream);
	static void SetError_InvalidBMPFormat(Signal sig);
};

Gura_EndModuleHeader(bmp, bmp)

#endif
