//-----------------------------------------------------------------------------
// Gura xpm module
// As fot the XPM format, see http://www.fileformat.info/format/xpm/egff.htm
//-----------------------------------------------------------------------------
#ifndef __MODULE_XPM_H__
#define __MODULE_XPM_H__

#include <gura.h>

Gura_BeginModule(xpm)

//-----------------------------------------------------------------------------
// ImageStreamer_xpm
//-----------------------------------------------------------------------------
class ImageStreamer_xpm : public ImageStreamer {
public:
	inline ImageStreamer_xpm() : ImageStreamer("xpm") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
public:
	static bool ReadStream(Signal sig, Object_image *pObjImage, Stream &stream);
	static bool WriteStream(Signal sig, Object_image *pObjImage, Stream &stream);
	static void SetError_InvalidFormat(Signal sig);
};

}}

#endif
