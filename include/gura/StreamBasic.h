//=============================================================================
// StreamBasic
//=============================================================================
#ifndef __GURA_STREAMBASIC_H__
#define __GURA_STREAMBASIC_H__

#include "Stream.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SimpleStream_CStringReader
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SimpleStream_CStringReader : public SimpleStream {
private:
	const char *_pStr;
	const char *_pEnd;
public:
	inline SimpleStream_CStringReader(const char *pStr, const char *pEnd = nullptr) :
													_pStr(pStr), _pEnd(pEnd) {}
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual int GetChar(Signal &sig);
	virtual void PutChar(Signal &sig, char ch);
	virtual size_t Read(Signal &sig, void *buff, size_t len);
	virtual size_t Write(Signal &sig, const void *buff, size_t len);
};

//-----------------------------------------------------------------------------
// SimpleStream_StringReader
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SimpleStream_StringReader : public SimpleStream {
private:
	String::const_iterator _pStr;
	String::const_iterator _pEnd;
public:
	inline SimpleStream_StringReader(String::const_iterator pStr,
				String::const_iterator pEnd) : _pStr(pStr), _pEnd(pEnd) {}
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual int GetChar(Signal &sig);
	virtual void PutChar(Signal &sig, char ch);
	virtual size_t Read(Signal &sig, void *buff, size_t len);
	virtual size_t Write(Signal &sig, const void *buff, size_t len);
};

//-----------------------------------------------------------------------------
// SimpleStream_StringWriter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SimpleStream_StringWriter : public SimpleStream {
private:
	String &_str;
public:
	inline SimpleStream_StringWriter(String &str) : _str(str) {}
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual int GetChar(Signal &sig);
	virtual void PutChar(Signal &sig, char ch);
	virtual size_t Read(Signal &sig, void *buff, size_t len);
	virtual size_t Write(Signal &sig, const void *buff, size_t len);
};

//-----------------------------------------------------------------------------
// StreamDumb
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StreamDumb : public Stream {
public:
	StreamDumb(Environment &env);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
};

//-----------------------------------------------------------------------------
// StreamFIFO
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StreamFIFO : public Stream {
private:
	class Entity {
	private:
		int _cntRef;
		AutoPtr<Memory> _pMemory;
		size_t _offsetWrite;
		size_t _offsetRead;
		size_t _bytesAvail;
		bool _brokenFlag;
		std::unique_ptr<OAL::Semaphore> _pSemaphore;
	public:
		Gura_DeclareReferenceAccessor(Entity);
	public:
		Entity(size_t bytesBuff);
	protected:
		inline ~Entity() {}
	public:
		size_t DoRead(Signal &sig, void *buff, size_t len);
		size_t DoWrite(Signal &sig, const void *buff, size_t len);
		inline void SetBrokenFlag() { _brokenFlag = true; }
	};
private:
	AutoPtr<Entity> _pEntity;
public:
	StreamFIFO(Environment &env, size_t bytesBuff);
	StreamFIFO(Environment &env, Entity *pEntity);
	virtual ~StreamFIFO();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
	inline Entity *GetEntity() { return _pEntity.get(); }
};

//-----------------------------------------------------------------------------
// StreamMemory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StreamMemory : public Stream {
private:
	std::unique_ptr<Binary> _pBinary;
public:
	StreamMemory(Environment &env);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
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
	StreamMemReader(Environment &env, const void *buff, size_t bytes);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
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
	Stream_Prefetch(Environment &env, Stream *pStreamSrc, size_t bytesUnit);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
	bool DoPrefetch(Signal &sig);
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
	Stream_Base64Reader(Environment &env, Stream *pStreamSrc);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
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
	Stream_Base64Writer(Environment &env, Stream *pStreamDst, int nCharsPerLine);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
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
	Stream_CRC32(Environment &env, Stream *pStreamDst);
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
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
	Stream_StringReader(Environment &env, const String &str);
	virtual ~Stream_StringReader();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
};

}

#endif
