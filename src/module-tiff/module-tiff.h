//-----------------------------------------------------------------------------
// Gura tiff module
// http://www.libtiff.org/
// Following site is useful with many samples.
// http://www.ibm.com/developerworks/jp/linux/library/l-libtiff/
// http://www.ibm.com/developerworks/jp/linux/library/l-libtiff2/
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_TIFF_H__
#define __GURA_MODULE_TIFF_H__
#include <gura.h>
#include <tiffio.h>

Gura_BeginModuleHeader(tiff)

//-----------------------------------------------------------------------------
// ImageStreamer_TIFF
//-----------------------------------------------------------------------------
class ImageStreamer_TIFF : public ImageStreamer {
public:
	inline ImageStreamer_TIFF() : ImageStreamer("tiff") {}
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
	inline size_t Read(void *buff, size_t bytes) {
		return _stream.Read(_sig, buff, bytes);
	}
	inline size_t Write(void *buff, size_t bytes) {
		return _stream.Write(_sig, buff, bytes);
	}
	inline bool Seek(size_t offset, Stream::SeekMode seekMode) {
		_stream.Seek(_sig, offset, seekMode);
		return !_sig.IsSignalled();
	}
	inline bool Flush() {
		_stream.Flush(_sig);
		return !_sig.IsSignalled();
	}
	inline size_t GetSize() {
		return _stream.GetSize();
	}
public:
	static tsize_t TiffRead(thandle_t fd, tdata_t buf, tsize_t size);
	static toff_t TiffSeek(thandle_t fd, toff_t offset, int origin);
	static tsize_t TiffWrite(thandle_t fd, tdata_t buf, tsize_t size);
	static int TiffClose(thandle_t fd);
	static toff_t TiffSize(thandle_t fd);
};

Gura_EndModuleHeader(tiff)

#endif
