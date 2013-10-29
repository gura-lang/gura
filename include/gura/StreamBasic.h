#ifndef __GURA_STREAMBASIC_H__
#define __GURA_STREAMBASIC_H__

#include "Stream.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SimpleStream_CString
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SimpleStream_CString : public SimpleStream {
private:
	const char *_pStr;
	const char *_pEnd;
public:
	inline SimpleStream_CString(const char *pStr, const char *pEnd = NULL) :
													_pStr(pStr), _pEnd(pEnd) {}
	virtual int GetChar(Signal sig);
	virtual void PutChar(Signal sig, char ch);
};

//-----------------------------------------------------------------------------
// SimpleStream_String
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SimpleStream_String : public SimpleStream {
private:
	String::const_iterator _pStr;
	String::const_iterator _pEnd;
public:
	inline SimpleStream_String(String::const_iterator pStr,
				String::const_iterator pEnd) : _pStr(pStr), _pEnd(pEnd) {}
	virtual int GetChar(Signal sig);
	virtual void PutChar(Signal sig, char ch);
};

//-----------------------------------------------------------------------------
// SimpleStream_StringWrite
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SimpleStream_StringWrite : public SimpleStream {
private:
	String &_str;
public:
	inline SimpleStream_StringWrite(String &str) : _str(str) {}
	virtual int GetChar(Signal sig);
	virtual void PutChar(Signal sig, char ch);
};

//-----------------------------------------------------------------------------
// StreamDumb
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StreamDumb : public Stream {
public:
	StreamDumb(Environment &env, Signal sig);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
};

//-----------------------------------------------------------------------------
// StreamFIFO
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StreamFIFO : public Stream {
private:
	AutoPtr<Memory> _pMemory;
	size_t _offsetWrite;
	size_t _offsetRead;
	size_t _bytesAvail;
	bool _readReqFlag;
	bool _writeReqFlag;
	bool _writeDoneFlag;
	std::auto_ptr<OAL::Semaphore> _pSemaphore;
	std::auto_ptr<OAL::Event> _pEventReadReq;
	std::auto_ptr<OAL::Event> _pEventWriteReq;
public:
	StreamFIFO(Environment &env, Signal sig, size_t bytesBuff);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	void SetWriteDoneFlag();
public:
	size_t GetOffsetWrite() const { return _offsetWrite; }
	size_t GetOffsetRead() const { return _offsetRead; }
	size_t GetBytesAvail() const { return _bytesAvail; }
};

//-----------------------------------------------------------------------------
// StreamMemory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StreamMemory : public Stream {
private:
	std::auto_ptr<Binary> _pBinary;
public:
	StreamMemory(Environment &env, Signal sig);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	const char *GetPointer() const;
};

//-----------------------------------------------------------------------------
// StreamMemReader
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StreamMemReader : public Stream {
private:
	const char *_buff;
	size_t _bytes;
public:
	StreamMemReader(Environment &env, Signal sig, const void *buff, size_t bytes);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
};

//-----------------------------------------------------------------------------
// Stream_Prefetch
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_Prefetch : public Stream {
private:
	AutoPtr<Stream> _pStreamSrc;
	size_t _offset;
	size_t _bytesAll;
	size_t _bytesUnit;
	MemoryOwner _memoryOwner;
public:
	Stream_Prefetch(Environment &env, Signal sig, Stream *pStreamSrc, size_t bytesUnit);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	bool DoPrefetch(Signal sig);
};

//-----------------------------------------------------------------------------
// Stream_Base64Reader
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_Base64Reader : public Stream {
private:
	AutoPtr<Stream> _pStreamSrc;
	int _nChars;
	int _nInvalid;
	ULong _accum;
	size_t _iBuffWork;
	UChar _buffWork[8];
public:
	Stream_Base64Reader(Environment &env, Signal sig, Stream *pStreamSrc);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
};

//-----------------------------------------------------------------------------
// Stream_Base64Writer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_Base64Writer : public Stream {
private:
	AutoPtr<Stream> _pStreamDst;
	int _nCharsPerLine;
	int _nChars;
	size_t _iBuffWork;
	UChar _buffWork[8];
	static const char _chars[];
public:
	Stream_Base64Writer(Environment &env, Signal sig, Stream *pStreamDst, int nCharsPerLine);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
};

//-----------------------------------------------------------------------------
// Stream_CRC32
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_CRC32 : public Stream {
private:
	AutoPtr<Stream> _pStreamDst;
	CRC32 _crc32;
public:
	Stream_CRC32(Environment &env, Signal sig, Stream *pStreamDst);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	inline void Initialize() { _crc32.Initialize(); }
	inline ULong GetCRC32() const { return _crc32.GetResult(); }
	inline size_t GetBytes() const { return _crc32.GetBytes(); }
};

//-----------------------------------------------------------------------------
// Stream_StringReader
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream_StringReader : public Stream {
private:
	String _str;
	size_t _offset;
public:
	Stream_StringReader(Environment &env, Signal sig, const String &str);
	virtual ~Stream_StringReader();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
};

}

#endif
