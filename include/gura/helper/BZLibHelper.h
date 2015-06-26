#ifndef __GURA_BZLIBHELPER_H__
#define __GURA_BZLIBHELPER_H__

#include <gura.h>
#include <bzlib.h>

namespace Gura {
namespace BZLib {

//-----------------------------------------------------------------------------
// Stream_Decompressor
//-----------------------------------------------------------------------------
class Stream_Decompressor : public Stream {
private:
	AutoPtr<Stream> _pStream;
	AutoPtr<Memory> _pMemory;
	size_t _bytesSrc;
	size_t _bytesBuff;
	size_t _bytesOut;
	size_t _offsetOut;
	bz_stream _bzstrm;
	char *_buffOut;
	char *_buffIn;
	bool _doneFlag;
public:
	Stream_Decompressor(Environment &env, Signal sig, Stream *pStream, size_t bytesSrc, size_t bytesBuff = 32768) :
			Stream(env, sig, ATTR_Readable), _pStream(pStream), _bytesSrc(bytesSrc),
			_bytesBuff(bytesBuff), _bytesOut(0),
			_offsetOut(0), _buffOut(nullptr), _buffIn(nullptr), _doneFlag(false) {
		CopyCodec(pStream);
	}
	~Stream_Decompressor() {
		::BZ2_bzDecompressEnd(&_bzstrm);
	}
	bool Initialize(Signal sig, int verbosity, int small) {
		::memset(&_bzstrm, 0x00, sizeof(_bzstrm));
		_bzstrm.bzalloc = nullptr;
		_bzstrm.bzfree = nullptr;
		_bzstrm.opaque = nullptr;
		_bzstrm.avail_in = 0;
		if (::BZ2_bzDecompressInit(&_bzstrm, verbosity, small) != BZ_OK) {
			sig.SetError(ERR_IOError, "bzlib error");
			return false;
		}
		_pMemory.reset(new MemoryHeap(_bytesBuff * 2));
		_buffOut = reinterpret_cast<char *>(_pMemory->GetPointer(0));
		_buffIn = reinterpret_cast<char *>(_pMemory->GetPointer(_bytesBuff));
		return true;
	}
	virtual const char *GetName() const {
		return (_pStream.IsNull())? "(invalid)" : _pStream->GetName();
	}
	virtual const char *GetIdentifier() const {
		return (_pStream.IsNull())? nullptr : _pStream->GetIdentifier();
	}
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len) {
		return 0;
	}
	virtual size_t DoRead(Signal sig, void *buff, size_t bytes) {
		size_t bytesRead = 0;
		char *buffp = reinterpret_cast<char *>(buff);
		bool continueFlag = true;
		for (size_t bytesRest = bytes; bytesRest > 0 && continueFlag; ) {
			if (_offsetOut >= _bytesOut) {
				_offsetOut = 0;
				_bytesOut = 0;
				if (_doneFlag) break;
				while (_bytesOut == 0) {
					if (_bzstrm.avail_in == 0) {
						size_t bytesRead = _pStream->Read(sig,
										_buffIn, ChooseMin(_bytesBuff, _bytesSrc));
						if (sig.IsSignalled()) {
							::BZ2_bzDecompressEnd(&_bzstrm);
							return 0;
						}
						if (bytesRead == 0) {
							sig.SetError(ERR_IOError, "unexpected end of bzip stream");
							return 0;
						}
						if (_bytesSrc != InvalidSize) {
							_bytesSrc -= bytesRead;
						}
						_bzstrm.avail_in = static_cast<unsigned int>(bytesRead);
						_bzstrm.next_in = _buffIn;
					}
					_bzstrm.avail_out = static_cast<unsigned int>(_bytesBuff);
					_bzstrm.next_out = _buffOut;
					int ret = ::BZ2_bzDecompress(&_bzstrm);
					_bytesOut = _bytesBuff - _bzstrm.avail_out;
					if (ret == BZ_OK) {
						// nothing to do
					} else if (ret == BZ_STREAM_END) {
						_doneFlag = true;
						continueFlag = false;
						break;
					} else {
						sig.SetError(ERR_IOError, "bzlib error");
						::BZ2_bzDecompressEnd(&_bzstrm);
						return 0;
					}
				}
			}
			size_t bytesToCopy = _bytesOut - _offsetOut;
			if (bytesToCopy > bytesRest) bytesToCopy = bytesRest;
			if (buffp != nullptr) {
				::memcpy(buffp + bytesRead, _buffOut + _offsetOut, bytesToCopy);
			}
			_offsetOut += bytesToCopy;
			bytesRest -= bytesToCopy;
			bytesRead += bytesToCopy;
		}
		return bytesRead;
	}
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode) {
		if (seekMode == SeekSet) {
			if (static_cast<size_t>(offset) >= offsetPrev) {
				size_t bytesToRead = static_cast<size_t>(offset) - offsetPrev;
				if (bytesToRead == 0) return true;
				return DoRead(sig, nullptr, bytesToRead) == static_cast<size_t>(bytesToRead);
			}
		} else if (seekMode == SeekCur) {
			if (offset == 0) {
				return true;
			} else if (offset > 0) {
				return DoRead(sig, nullptr, offset) == static_cast<size_t>(offset);
			}
		}
		sig.SetError(ERR_SystemError, "backward seeking is not supported");
		return false;
	}
	virtual bool DoFlush(Signal sig) {
		return false;
	}
	virtual bool DoClose(Signal sig) {
		return true;
	}
};

//-----------------------------------------------------------------------------
// Stream_Compressor
//-----------------------------------------------------------------------------
class Stream_Compressor : public Stream {
private:
	AutoPtr<Stream> _pStream;
	AutoPtr<Memory> _pMemory;
	size_t _bytesBuff;
	size_t _offsetOut;
	bz_stream _bzstrm;
	char *_buffOut;
	char *_buffIn;
public:
	Stream_Compressor(Environment &env, Signal sig, Stream *pStream, size_t bytesBuff = 32768) :
			Stream(env, sig, ATTR_Writable), _pStream(pStream),
			_bytesBuff(bytesBuff), _offsetOut(0), _buffOut(nullptr), _buffIn(nullptr) {
		CopyCodec(pStream);
	}
	~Stream_Compressor() {
		DoClose(_sig);
	}
	bool Initialize(Signal sig, int blockSize100k, int verbosity, int workFactor) {
		::memset(&_bzstrm, 0x00, sizeof(_bzstrm));
		_bzstrm.bzalloc = nullptr;
		_bzstrm.bzfree = nullptr;
		_bzstrm.opaque = nullptr;
		if (::BZ2_bzCompressInit(&_bzstrm, blockSize100k, verbosity, workFactor) != BZ_OK) {
			sig.SetError(ERR_IOError, "bzlib error");
			return false;
		}
		_pMemory.reset(new MemoryHeap(_bytesBuff * 2));
		_buffOut = reinterpret_cast<char *>(_pMemory->GetPointer(0));
		_buffIn = reinterpret_cast<char *>(_pMemory->GetPointer(_bytesBuff));
		_bzstrm.next_out = _buffOut;
		_bzstrm.avail_out = static_cast<unsigned int>(_bytesBuff);
		return true;
	}
	virtual const char *GetName() const {
		return (_pStream.IsNull())? "(invalid)" : _pStream->GetName();
	}
	virtual const char *GetIdentifier() const {
		return (_pStream.IsNull())? nullptr : _pStream->GetIdentifier();
	}
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len) {
		if (_pStream.IsNull()) return 0;
		_bzstrm.next_in = reinterpret_cast<char *>(const_cast<void *>(buff));
		_bzstrm.avail_in = static_cast<unsigned int>(len);
		while (_bzstrm.avail_in > 0) {
			if (_bzstrm.avail_out == 0) {
				_pStream->Write(sig, _buffOut, _bytesBuff);
				if (sig.IsSignalled()) return 0;
				_bzstrm.next_out = _buffOut;
				_bzstrm.avail_out = static_cast<unsigned int>(_bytesBuff);
			}
			int rtn = ::BZ2_bzCompress(&_bzstrm, BZ_RUN);
			if (rtn != BZ_RUN_OK) {
				sig.SetError(ERR_IOError, "bzlib error");
				return 0;
			}
		}
		return len;
	}
	virtual bool DoFlush(Signal sig) {
		return DoClose(sig);
	}
	virtual bool DoClose(Signal sig) {
		if (_pStream.IsNull()) return true;
		for (;;) {
			if (_bzstrm.avail_out == 0) {
				_pStream->Write(sig, _buffOut, _bytesBuff);
				if (sig.IsSignalled()) return 0;
				_bzstrm.next_out = _buffOut;
				_bzstrm.avail_out = static_cast<unsigned int>(_bytesBuff);
			}
			int rtn = ::BZ2_bzCompress(&_bzstrm, BZ_FINISH);
			if (rtn == BZ_STREAM_END) break;
			if (rtn != BZ_FINISH_OK) {
				sig.SetError(ERR_IOError, "bzlib error");
				return false;
			}
		}
		size_t bytesOut = _bytesBuff - _bzstrm.avail_out;
		if (bytesOut > 0) {
			_pStream->Write(sig, _buffOut, bytesOut);
		}
		::BZ2_bzCompressEnd(&_bzstrm);
		if (sig.IsSignalled()) return false;
		bool rtn = _pStream->Flush(sig);
		_pStream.reset(nullptr);
		return rtn;
	}
	virtual size_t DoRead(Signal sig, void *buff, size_t bytes) {
		return 0;
	}
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode) {
		return false;
	}
};

}
}

#endif
