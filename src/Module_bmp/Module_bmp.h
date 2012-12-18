//-----------------------------------------------------------------------------
// Gura bmp module
//-----------------------------------------------------------------------------
#ifndef __MODULE_BMP_H__
#define __MODULE_BMP_H__
#include <gura.h>

Gura_BeginModule(bmp)

//-----------------------------------------------------------------------------
// ImageStreamer_BMP
//-----------------------------------------------------------------------------
class ImageStreamer_BMP : public ImageStreamer {
public:
	inline ImageStreamer_BMP() : ImageStreamer("bmp") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
public:
	static bool ReadStream(Signal sig, Object_image *pObjImage, Stream &stream);
	static bool WriteStream(Signal sig, Object_image *pObjImage, Stream &stream);
	static void SetError_InvalidBMPFormat(Signal sig);
};

}}

#endif
