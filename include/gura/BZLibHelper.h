// This header file contains bodies of functions.

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
	Stream *_pStream;
	AutoPtr<OAL::Memory> _pMemory;
	size_t _bytesSrc;
	size_t _bytesBuff;
	size_t _bytesOut;
	size_t _offsetOut;
	bz_stream _bzstrm;
	char *_buffOut;
	char *_buffIn;
public:
	Stream_Decompressor(Environment &env, Signal sig, Stream *pStream, size_t bytesSrc, size_t bytesBuff = 32768);
	~Stream_Decompressor();
	bool Initialize(Signal sig, int verbosity, int small);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual size_t DoRead(Signal sig, void *buff, size_t bytes);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
};

Stream_Decompressor::Stream_Decompressor(Environment &env, Signal sig, Stream *pStream, size_t bytesSrc, size_t bytesBuff) :
		Stream(env, sig, ATTR_Readable), _pStream(pStream), _bytesSrc(bytesSrc),
		_bytesBuff(bytesBuff), _bytesOut(0),
		_offsetOut(0), _buffOut(NULL), _buffIn(NULL)
{
	CopyCodec(pStream);
}

Stream_Decompressor::~Stream_Decompressor()
{
	Stream::Delete(_pStream);
	::BZ2_bzDecompressEnd(&_bzstrm);
}

bool Stream_Decompressor::Initialize(Signal sig, int verbosity, int small)
{
	::memset(&_bzstrm, 0x00, sizeof(_bzstrm));
	_bzstrm.bzalloc = NULL;
	_bzstrm.bzfree = NULL;
	_bzstrm.opaque = NULL;
	_bzstrm.avail_in = 0;
	if (::BZ2_bzDecompressInit(&_bzstrm, verbosity, small) != BZ_OK) {
		sig.SetError(ERR_IOError, "bzlib error");
		return false;
	}
	_pMemory.reset(new OAL::MemoryHeap(_bytesBuff * 2));
	_buffOut = reinterpret_cast<char *>(_pMemory->GetPointer(0));
	_buffIn = reinterpret_cast<char *>(_pMemory->GetPointer(_bytesBuff));
	return true;
}

const char *Stream_Decompressor::GetName() const
{
	return (_pStream == NULL)? "(invalid)" : _pStream->GetName();
}

const char *Stream_Decompressor::GetIdentifier() const
{
	return (_pStream == NULL)? NULL : _pStream->GetIdentifier();
}

size_t Stream_Decompressor::DoWrite(Signal sig, const void *buff, size_t len)
{
	return 0;
}

size_t Stream_Decompressor::DoRead(Signal sig, void *buff, size_t bytes)
{
	size_t bytesRead = 0;
	char *buffp = reinterpret_cast<char *>(buff);
	bool continueFlag = true;
	for (size_t bytesRest = bytes; bytesRest > 0 && continueFlag; ) {
		if (_offsetOut >= _bytesOut) {
			if (_bzstrm.avail_in == 0) {
				size_t bytesRead = _pStream->Read(sig,
								_buffIn, ChooseMin(_bytesBuff, _bytesSrc));
				if (sig.IsSignalled()) {
					::BZ2_bzDecompressEnd(&_bzstrm);
					return 0;
				}
				if (bytesRead == 0) break;
				if (_bytesSrc != InvalidSize) {
					_bytesSrc -= bytesRead;
				}
				_bzstrm.avail_in = static_cast<unsigned int>(bytesRead);
				_bzstrm.next_in = _buffIn;
			}
			_bzstrm.avail_out = static_cast<unsigned int>(_bytesBuff);
			_bzstrm.next_out = _buffOut;
			int ret = ::BZ2_bzDecompress(&_bzstrm);
			if (ret == BZ_OK) {
				// nothing to do
			} else if (ret == BZ_STREAM_END) {
				continueFlag = false;
			} else {
				sig.SetError(ERR_IOError, "bzlib error");
				::BZ2_bzDecompressEnd(&_bzstrm);
				return 0;
			}
			_bytesOut = _bytesBuff - _bzstrm.avail_out;
			_offsetOut = 0;
			if (_bytesOut == 0) break;
		}
		size_t bytesToCopy = _bytesOut - _offsetOut;
		if (bytesToCopy > bytesRest) bytesToCopy = bytesRest;
		if (buffp != NULL) {
			::memcpy(buffp + bytesRead, _buffOut + _offsetOut, bytesToCopy);
		}
		_offsetOut += bytesToCopy;
		bytesRest -= bytesToCopy;
		bytesRead += bytesToCopy;
	}
	return bytesRead;
}

bool Stream_Decompressor::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (seekMode == SeekSet) {
		if (static_cast<size_t>(offset) >= offsetPrev) {
			size_t bytesToRead = static_cast<size_t>(offset) - offsetPrev;
			if (bytesToRead == 0) return true;
			return DoRead(sig, NULL, bytesToRead) == static_cast<size_t>(bytesToRead);
		}
	} else if (seekMode == SeekCur) {
		if (offset == 0) {
			return true;
		} else if (offset > 0) {
			return DoRead(sig, NULL, offset) == static_cast<size_t>(offset);
		}
	}
	sig.SetError(ERR_SystemError, "backward seeking is not supported");
	return false;
}

bool Stream_Decompressor::DoFlush(Signal sig)
{
	return false;
}

bool Stream_Decompressor::DoClose(Signal sig)
{
	return true;
}

//-----------------------------------------------------------------------------
// Stream_Compressor
//-----------------------------------------------------------------------------
class Stream_Compressor : public Stream {
private:
	Stream *_pStream;
	AutoPtr<OAL::Memory> _pMemory;
	size_t _bytesBuff;
	size_t _offsetOut;
	bz_stream _bzstrm;
	char *_buffOut;
	char *_buffIn;
public:
	Stream_Compressor(Environment &env, Signal sig, Stream *pStream, size_t bytesBuff = 32768);
	~Stream_Compressor();
	bool Initialize(Signal sig, int blockSize100k, int verbosity, int workFactor);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoRead(Signal sig, void *buff, size_t bytes);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

Stream_Compressor::Stream_Compressor(Environment &env, Signal sig, Stream *pStream, size_t bytesBuff) :
		Stream(env, sig, ATTR_Writable), _pStream(pStream),
		_bytesBuff(bytesBuff), _offsetOut(0), _buffOut(NULL), _buffIn(NULL)
{
	CopyCodec(pStream);
}

Stream_Compressor::~Stream_Compressor()
{
	DoClose(_sig);
}

bool Stream_Compressor::Initialize(Signal sig,
							int blockSize100k, int verbosity, int workFactor)
{
	::memset(&_bzstrm, 0x00, sizeof(_bzstrm));
	_bzstrm.bzalloc = NULL;
	_bzstrm.bzfree = NULL;
	_bzstrm.opaque = NULL;
	if (::BZ2_bzCompressInit(&_bzstrm, blockSize100k, verbosity, workFactor) != BZ_OK) {
		sig.SetError(ERR_IOError, "bzlib error");
		return false;
	}
	_pMemory.reset(new OAL::MemoryHeap(_bytesBuff * 2));
	_buffOut = reinterpret_cast<char *>(_pMemory->GetPointer(0));
	_buffIn = reinterpret_cast<char *>(_pMemory->GetPointer(_bytesBuff));
	_bzstrm.next_out = _buffOut;
	_bzstrm.avail_out = static_cast<unsigned int>(_bytesBuff);
	return true;
}

const char *Stream_Compressor::GetName() const
{
	return (_pStream == NULL)? "(invalid)" : _pStream->GetName();
}

const char *Stream_Compressor::GetIdentifier() const
{
	return (_pStream == NULL)? NULL : _pStream->GetIdentifier();
}

size_t Stream_Compressor::DoWrite(Signal sig, const void *buff, size_t len)
{
	if (_pStream == NULL) return 0;
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

bool Stream_Compressor::DoFlush(Signal sig)
{
	return DoClose(sig);
}

bool Stream_Compressor::DoClose(Signal sig)
{
	if (_pStream == NULL) return true;
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
	Stream::Delete(_pStream);
	_pStream = NULL;
	return rtn;
}

size_t Stream_Compressor::DoRead(Signal sig, void *buff, size_t bytes)
{
	return 0;
}

bool Stream_Compressor::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	return false;
}

}
}

#endif
