#ifndef __GURA_STREAM_H__
#define __GURA_STREAM_H__

#include "Signal.h"
#include "OAL.h"
#include "Codec.h"
#include "Algorithm.h"

namespace Gura {

class Object;
class ValueList;
class Function;
class Object_codec;

//-----------------------------------------------------------------------------
// SimpleStream
//-----------------------------------------------------------------------------
class DLLDECLARE SimpleStream {
public:
	void Print(Signal sig, const char *str);
	void Printf(Signal sig, const char *format, const ValueList &valList);
	void Println(Signal sig, const char *str);
	void PrintSignal(Signal sig, const Signal &sigToPrint);
	void Dump(Signal sig, const void *buff, size_t bytes, bool upperFlag = false);
	virtual int GetChar(Signal sig) = 0;
	virtual void PutChar(Signal sig, char ch) = 0;
};

//-----------------------------------------------------------------------------
// SimpleStream_StringRead
//-----------------------------------------------------------------------------
class DLLDECLARE SimpleStream_StringRead : public SimpleStream {
private:
	String::const_iterator _pStr;
	String::const_iterator _pEnd;
public:
	inline SimpleStream_StringRead(String::const_iterator pStr,
				String::const_iterator pEnd) : _pStr(pStr), _pEnd(pEnd) {}
	virtual int GetChar(Signal sig);
	virtual void PutChar(Signal sig, char ch);
};

//-----------------------------------------------------------------------------
// SimpleStream_StringWrite
//-----------------------------------------------------------------------------
class DLLDECLARE SimpleStream_StringWrite : public SimpleStream {
private:
	String &_str;
public:
	inline SimpleStream_StringWrite(String &str) : _str(str) {}
	virtual int GetChar(Signal sig);
	virtual void PutChar(Signal sig, char ch);
};

//-----------------------------------------------------------------------------
// Stream
//-----------------------------------------------------------------------------
class DLLDECLARE Stream : public SimpleStream {
public:
	enum SeekMode { SeekSet, SeekCur };
	enum Error {
		ERROR_None,
		ERROR_Codec,
	};
	enum {
		ATTR_None			= 0,
		ATTR_Infinite		= (1 << 0),
		ATTR_BwdSeekable	= (1 << 1),
		ATTR_Readable		= (1 << 2),
		ATTR_Writable		= (1 << 3),
		ATTR_Append			= (1 << 4),
	};
	struct Attribute {
	public:
		DateTime atime;
		DateTime mtime;
		DateTime ctime;
		unsigned long attr;
		unsigned long attrMask;
	public:
		inline Attribute() : attr(0), attrMask(0) {}
	};
protected:
	int _cntRef;
	Signal _sig;
	unsigned long _attr;
	size_t _offsetCur;
	String _encoding;
	std::auto_ptr<Codec_Decoder> _pDecoder;
	std::auto_ptr<Codec_Encoder> _pEncoder;
	struct {
		char *buff;
		size_t bytes;
		size_t offsetRead;
	} _peek;
public:
	inline static Stream *Reference(const Stream *pStream) {
		if (pStream == NULL) return NULL;
		Stream *pStreamCasted = const_cast<Stream *>(pStream);
		pStreamCasted->_cntRef++;
		return pStreamCasted;
	}
	inline static void Delete(Stream *pStream) {
		if (pStream == NULL) return;
		pStream->_cntRef--;
		if (pStream->_cntRef <= 0) delete pStream;
	}
protected:
	virtual ~Stream();
public:
	Stream(Signal sig, unsigned long attr);
	void Close();
	bool InstallCodec(const char *encoding, bool processEOLFlag);
	void CopyCodec(Stream *pStream);
	void CopyCodec(Object_codec *pObjCodec);
	void ReleaseCodec();
	inline bool IsCodecInstalled() const { return !_encoding.empty(); }
	inline const char *GetEncoding() const { return _encoding.c_str(); }
	inline Codec_Decoder *GetDecoder() { return _pDecoder.get(); }
	inline Codec_Encoder *GetEncoder() { return _pEncoder.get(); }
	virtual int GetChar(Signal sig);
	virtual void PutChar(Signal sig, char ch);
	virtual void FlushConsole();
	virtual const char *GetName() const = 0;
	virtual const char *GetIdentifier() const = 0;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	virtual int DoGetChar(Signal sig);
	virtual void DoPutChar(Signal sig, char ch);
	virtual Object *DoGetStatObj(Signal sig);
	inline int GetRefCount() const { return _cntRef; }
	inline unsigned long GetAttr() const { return _attr; }
	inline bool IsInfinite() const { return (_attr & ATTR_Infinite)? true : false; }
	inline bool IsReadable() const { return (_attr & ATTR_Readable)? true : false; }
	inline bool IsWritable() const { return (_attr & ATTR_Writable)? true : false; }
	inline bool IsAppend() const { return (_attr & ATTR_Append)? true : false; }
	inline bool IsBwdSeekable() const { return (_attr & ATTR_BwdSeekable)? true : false; }
	inline void SetReadable(bool flag) {
		_attr = (_attr & ~ATTR_Readable) | (flag? ATTR_Readable : 0);
	}
	inline void SetWritable(bool flag) {
		_attr = (_attr & ~ATTR_Writable) | (flag? ATTR_Writable : 0);
	}
	inline void SetAppend(bool flag) {
		_attr = (_attr & ~ATTR_Append) | (flag? ATTR_Append : 0);
	}
	size_t Read(Signal sig, void *buff, size_t len);
	size_t Write(Signal sig, const void *buff, size_t len);
	size_t Peek(Signal sig, void *buff, size_t len);
	bool Seek(Signal sig, long offset, SeekMode seekMode);
	inline size_t Tell() { return _offsetCur; }
	inline size_t GetSize() { return DoGetSize(); }
	inline Object *GetStatObj(Signal sig) { return DoGetStatObj(sig); }
	bool Flush(Signal sig);
	bool HasNameSuffix(const char *suffix, bool ignoreCase = true) const;
	bool CheckReadable(Signal sig) const;
	bool CheckWritable(Signal sig) const;
	bool CheckBwdSeekable(Signal sig) const;
	bool Compare(Signal sig, Stream &stream);
	bool ReadToStream(Environment &env, Signal sig, Stream &streamDst,
					size_t bytesUnit = 0x10000, bool finalizeFlag = true,
					const Function *pFuncFilter = NULL);
	bool SerializeBoolean(Signal sig, bool num);
	bool DeserializeBoolean(Signal sig, bool &num);
	bool SerializeUChar(Signal sig, unsigned char num);
	bool DeserializeUChar(Signal sig, unsigned char &num);
	bool SerializeUShort(Signal sig, unsigned short num);
	bool DeserializeUShort(Signal sig, unsigned short &num);
	bool SerializeULong(Signal sig, unsigned long num);
	bool DeserializeULong(Signal sig, unsigned long &num);
	bool SerializeUInt64(Signal sig, uint64 num);
	bool DeserializeUInt64(Signal sig, uint64 &num);
	bool SerializeDouble(Signal sig, double num);
	bool DeserializeDouble(Signal sig, double &num);
	bool SerializeString(Signal sig, const char *str);
	bool DeserializeString(Signal sig, String &str);
	bool SerializeBinary(Signal sig, const Binary &binary);
	bool DeserializeBinary(Signal sig, Binary &binary);
	bool SerializeSymbol(Signal sig, const Symbol *pSymbol);
	bool DeserializeSymbol(Signal sig, const Symbol **ppSymbol);
	bool SerializeSymbolSet(Signal sig, const SymbolSet &symbolSet);
	bool DeserializeSymbolSet(Signal sig, SymbolSet &symbolSet);
	bool SerializeSymbolList(Signal sig, const SymbolList &symbolList);
	bool DeserializeSymbolList(Signal sig, SymbolList &symbolList);
	bool SerializePackedULong(Signal sig, unsigned long num);
	bool DeserializePackedULong(Signal sig, unsigned long &num);
public:
	static Stream *Prefetch(Signal sig, Stream *pStreamSrc,
							bool deleteSrcFlag, size_t bytesUnit = 0x10000);
};

//-----------------------------------------------------------------------------
// StreamDumb
//-----------------------------------------------------------------------------
class DLLDECLARE StreamDumb : public Stream {
private:
	Signal _sig;
public:
	StreamDumb();
	virtual ~StreamDumb();
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
class DLLDECLARE Stream_Prefetch : public Stream {
public:
	typedef std::vector<OAL::Memory *> MemoryList;
private:
	AutoPtr<Stream> _pStreamSrc;
	size_t _offset;
	size_t _bytesAll;
	size_t _bytesUnit;
	MemoryList _memoryList;
public:
	Stream_Prefetch(Signal sig, Stream *pStreamSrc, size_t bytesUnit);
	virtual ~Stream_Prefetch();
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
class DLLDECLARE Stream_Base64Reader : public Stream {
private:
	AutoPtr<Stream> _pStreamSrc;
	int _nChars;
	int _nInvalid;
	unsigned long _accum;
	size_t _iBuffWork;
	unsigned char _buffWork[8];
public:
	Stream_Base64Reader(Signal sig, Stream *pStreamSrc);
	virtual ~Stream_Base64Reader();
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
class DLLDECLARE Stream_Base64Writer : public Stream {
private:
	AutoPtr<Stream> _pStreamDst;
	int _nCharsPerLine;
	int _nChars;
	size_t _iBuffWork;
	unsigned char _buffWork[8];
	static const char _chars[];
public:
	Stream_Base64Writer(Signal sig, Stream *pStreamDst, int nCharsPerLine);
	virtual ~Stream_Base64Writer();
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
class DLLDECLARE Stream_CRC32 : public Stream {
private:
	AutoPtr<Stream> _pStreamDst;
	CRC32 _crc32;
public:
	Stream_CRC32(Signal sig, Stream *pStreamDst);
	virtual ~Stream_CRC32();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	inline void Initialize() { _crc32.Initialize(); }
	inline unsigned long GetCRC32() const { return _crc32.GetResult(); }
	inline size_t GetBytes() const { return _crc32.GetBytes(); }
};

}

#endif
