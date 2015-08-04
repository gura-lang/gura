//-----------------------------------------------------------------------------
// Gura module: bmp
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_BMP_H__
#define __GURA_MODULE_BMP_H__
#include <gura.h>

Gura_BeginModuleHeader(bmp)

//-----------------------------------------------------------------------------
// ImageStreamer_BMP
//-----------------------------------------------------------------------------
class ImageStreamer_BMP : public ImageStreamer {
public:
	inline ImageStreamer_BMP() : ImageStreamer("bmp") {}
	virtual bool IsResponsible(Signal &sig, Stream &stream);
	virtual bool Read(Environment &env, Image *pImage, Stream &stream);
	virtual bool Write(Environment &env, Image *pImage, Stream &stream);
public:
	static bool ReadStream(Environment &env, Image *pImage, Stream &stream);
	static bool WriteStream(Environment &env, Image *pImage, Stream &stream);
	static void SetError_InvalidBMPFormat(Signal &sig);
};

Gura_EndModuleHeader(bmp)

#endif
