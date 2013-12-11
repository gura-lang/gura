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

//-----------------------------------------------------------------------------
// SimpleStream
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SimpleStream {
public:
	void Print(Signal sig, const char *str);
	void Printf(Signal sig, const char *format, const ValueList &valList);
	void Println(Signal sig, const char *str);
	void Dump(Signal sig, const void *buff, size_t bytes, bool upperFlag = false);
	virtual const char *GetName() const = 0;
	virtual int GetChar(Signal sig) = 0;
	virtual void PutChar(Signal sig, char ch) = 0;
	virtual size_t Read(Signal sig, void *buff, size_t len) = 0;
	virtual size_t Write(Signal sig, const void *buff, size_t len) = 0;
};

//-----------------------------------------------------------------------------
// Stream
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Stream : public SimpleStream {
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
		ULong attr;
		ULong attrMask;
	public:
		inline Attribute() : attr(0), attrMask(0) {}
	};
protected:
	int _cntRef;
	Signal _sig;
	ULong _attr;
	size_t _offsetCur;
	AutoPtr<Codec> _pCodec;
	struct {
		char *buff;
		size_t bytes;
		size_t offsetRead;
	} _peek;
public:
	Gura_DeclareReferenceAccessor(Stream);
protected:
	virtual ~Stream();
public:
	Stream(Environment &env, Signal sig, ULong attr);
	void Close();
	void SetCodec(Codec *pCodec);
	void CopyCodec(Stream *pStream);
	void CopyCodec(const Codec *pCodec);
	inline Codec *GetCodec() { return _pCodec.get(); }
	String ReadChar(Signal sig);
	virtual int GetChar(Signal sig);
	virtual void PutChar(Signal sig, char ch);
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
	inline ULong GetAttr() const { return _attr; }
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
	virtual size_t Read(Signal sig, void *buff, size_t len);
	virtual size_t Write(Signal sig, const void *buff, size_t len);
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
	bool SerializeUChar(Signal sig, UChar num);
	bool DeserializeUChar(Signal sig, UChar &num);
	bool SerializeUShort(Signal sig, UShort num);
	bool DeserializeUShort(Signal sig, UShort &num);
	bool SerializeULong(Signal sig, ULong num);
	bool DeserializeULong(Signal sig, ULong &num);
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
	bool SerializePackedULong(Signal sig, ULong num);
	bool DeserializePackedULong(Signal sig, ULong &num);
public:
	static Stream *Open(Environment &env, Signal sig, const char *pathName, ULong attr);
	static Stream *Prefetch(Environment &env, Signal sig, Stream *pStreamSrc,
							bool deleteSrcFlag, size_t bytesUnit = 0x10000);
	static ULong ParseOpenMode(Signal sig, const char *mode);
};

}

#endif
