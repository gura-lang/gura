//-----------------------------------------------------------------------------
// Gura tar module
// http://www.gnu.org/software/tar/manual/html_node/Standard.html
//-----------------------------------------------------------------------------
#ifndef __MODULE_TAR_H__
#define __MODULE_TAR_H__

#include <gura.h>

Gura_BeginModule(tar)

Gura_DeclareUserSymbol(name);
Gura_DeclareUserSymbol(filename);
Gura_DeclareUserSymbol(linkname);
Gura_DeclareUserSymbol(uname);
Gura_DeclareUserSymbol(gname);
Gura_DeclareUserSymbol(mode);
Gura_DeclareUserSymbol(uid);
Gura_DeclareUserSymbol(gid);
Gura_DeclareUserSymbol(size);
Gura_DeclareUserSymbol(mtime);
Gura_DeclareUserSymbol(atime);
Gura_DeclareUserSymbol(ctime);
Gura_DeclareUserSymbol(chksum);
Gura_DeclareUserSymbol(typeflag);
Gura_DeclareUserSymbol(devmajor);
Gura_DeclareUserSymbol(devminor);

Gura_DeclareUserSymbol(none);
Gura_DeclareUserSymbol(gzip);
Gura_DeclareUserSymbol(bzip2);
Gura_DeclareUserSymbol(auto);

class Header;

enum CompressionType {
	COMPRESS_Invalid,
	COMPRESS_None,
	COMPRESS_Auto,
	COMPRESS_GZip,
	COMPRESS_BZip2,
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Header *ReadHeader(Signal sig, Stream *pStream, void *buffBlock);
Stream *DecorateReaderStream(Environment &env, Signal sig, Stream *pStreamSrc,
						const char *name, CompressionType compressionType);
Stream *DecorateWriterStream(Environment &env, Signal sig, Stream *pStreamDst,
						const char *name, CompressionType compressionType);
unsigned long OctetToULong(Signal sig, const char *octet, size_t len);

CompressionType SymbolToCompressionType(const Symbol *pSymbol);

inline bool IsGZippedTar(const char *name) {
	return (EndsWith(name, ".tar.gz", true) || EndsWith(name, ".tgz", true));
}

inline bool IsBZippedTar(const char *name) {
	return (EndsWith(name, ".tar.bz2", true));
}

//-----------------------------------------------------------------------------
// TAR format data types
//-----------------------------------------------------------------------------
extern const int BLOCKSIZE;

struct posix_header
{						// byte offset
	char name[100];		//   0
	char mode[8];		// 100
	char uid[8];		// 108
	char gid[8];		// 116
	char size[12];		// 124
	char mtime[12];		// 136
	char chksum[8];		// 148
	char typeflag;		// 156
	char linkname[100];	// 157
	char magic[6];		// 257
	char version[2];	// 263
	char uname[32];		// 265
	char gname[32];		// 297
	char devmajor[8];	// 329
	char devminor[8];	// 337
	char prefix[155];	// 345
						// 500
};

struct star_header
{						// byte offset
	char name[100];		//   0
	char mode[8];		// 100
	char uid[8];		// 108
	char gid[8];		// 116
	char size[12];		// 124
	char mtime[12];		// 136
	char chksum[8];		// 148
	char typeflag;		// 156
	char linkname[100];	// 157
	char magic[6];		// 257
	char version[2];	// 263
	char uname[32];		// 265
	char gname[32];		// 297
	char devmajor[8];	// 329
	char devminor[8];	// 337
	char prefix[131];	// 345
	char atime[12];		// 476
	char ctime[12];		// 488
						// 500
};

//-----------------------------------------------------------------------------
// Header declaration
//-----------------------------------------------------------------------------
class Header {
private:
	size_t _offset;
	char _name[100 + 1];
	char _linkname[100 + 1];
	char _uname[32 + 1];
	char _gname[32 + 1];
	unsigned long _mode;
	unsigned long _uid;
	unsigned long _gid;
	size_t _size;
	DateTime _mtime;
	DateTime _atime;
	DateTime _ctime;
	unsigned long _chksum;
	char _typeflag;
	unsigned long _devmajor;
	unsigned long _devminor;
public:
	Header();
	Header(const Header &hdr);
	void Initialize();
	bool SetRawHeader(Signal sig, const star_header &rawHdr);
	void ComposeHeaderBlock(void *memBlock);
	inline void SetOffset(size_t offset) { _offset = offset; }
	inline size_t GetOffset() const { return _offset; }
	inline void SetName(const char *name) {
		::memset(_name, 0x00, sizeof(_name)), ::strcpy(_name, name);
	}
	inline const char *GetName() const { return _name; }
	inline void SetLinkName(const char *linkname) {
		::memset(_linkname, 0x00, sizeof(_linkname)), ::strcpy(_linkname, linkname);
	}
	inline const char *GetLinkName() const { return _linkname; }
	inline void SetUName(const char *uname) {
		::memset(_uname, 0x00, sizeof(_uname)), ::strcpy(_uname, uname);
	}
	inline const char *GetUName() const { return _uname; }
	inline void SetGName(const char *gname) {
		::memset(_gname, 0x00, sizeof(_gname)), ::strcpy(_gname, gname);
	}
	inline const char *GetGName() const { return _gname; }
	inline void SetMode(unsigned long mode) { _mode = mode; }
	inline unsigned long GetMode() const { return _mode; }
	inline void SetUid(unsigned long uid) { _uid = uid; }
	inline unsigned long GetUid() const { return _uid; }
	inline void SetGid(unsigned long gid) { _gid = gid; }
	inline unsigned long GetGid() const { return _gid; }
	inline void SetSize(size_t size) { _size = size; }
	inline size_t GetSize() const { return _size; }
	inline void SetMTime(const DateTime &mtime) { _mtime = mtime; }
	inline DateTime GetMTime() const { return _mtime; }
	inline void SetATime(const DateTime &atime) { _atime = atime; }
	inline DateTime GetATime() const { return _atime; }
	inline void SetCTime(const DateTime &ctime) { _ctime = ctime; }
	inline DateTime GetCTime() const { return _ctime; }
	inline void SetChksum(unsigned long chksum) { _chksum = chksum; }
	inline unsigned long GetChksum() const { return _chksum; }
	inline void SetTypeFlag(char typeflag) { _typeflag = typeflag; }
	inline char GetTypeFlag() const { return _typeflag; }
	inline void SetDevMajor(unsigned long devmajor) { _devmajor = devmajor; }
	inline unsigned long GetDevMajor() const { return _devmajor; }
	inline void SetDevMinor(unsigned long devminor) { _devminor = devminor; }
	inline unsigned long GetDevMinor() const { return _devminor; }
	inline unsigned long CalcBlocks() const {
		return (_size + BLOCKSIZE - 1) / BLOCKSIZE;
	}
};

//-----------------------------------------------------------------------------
// Stream_Entry declaration
//-----------------------------------------------------------------------------
class Stream_Entry : public Stream {
protected:
	AutoPtr<Stream> _pStreamSrc;
	Header _hdr;
	String _name;
	size_t _offsetTop;
public:
	Stream_Entry(Environment &env, Signal sig, Stream *pStreamSrc, const Header &hdr);
	virtual ~Stream_Entry();
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoRead(Signal sig, void *buff, size_t bytes);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	virtual Object *DoGetStatObj(Signal sig);
	bool FlushRead(Signal sig);
	inline Stream &GetSource() { return *_pStreamSrc; }
	inline const Stream &GetSource() const { return *_pStreamSrc; }
};

//-----------------------------------------------------------------------------
// Directory_TAR declaration
//-----------------------------------------------------------------------------
class Record_TAR;

class Directory_TAR : public Directory {
private:
	AutoPtr<DirBuilder::Structure> _pStructure;
	Record_TAR *_pRecord;
public:
	Directory_TAR(Directory *pParent, const char *name,
		Type type, DirBuilder::Structure *pStructure, Record_TAR *pRecord);
	virtual ~Directory_TAR();
	virtual Directory *DoNext(Environment &env, Signal sig);
	virtual Stream *DoOpenStream(Environment &env, Signal sig, unsigned long attr);
	virtual Object *DoGetStatObj(Signal sig);
};

//-----------------------------------------------------------------------------
// DirectoryFactory_TAR declaration
//-----------------------------------------------------------------------------
class DirectoryFactory_TAR : public DirectoryFactory {
public:
	virtual bool IsResponsible(Environment &env, Signal sig,
					const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env, Signal sig,
		Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode);
};

//-----------------------------------------------------------------------------
// Record_TAR declaration
//-----------------------------------------------------------------------------
class Record_TAR : public DirBuilder::Record {
private:
	std::auto_ptr<Header> _pHdr;
public:
	inline Record_TAR(DirBuilder::Structure *pStructure, Record_TAR *pParent,
									const char *name, bool containerFlag) :
		DirBuilder::Record(pStructure, pParent, name, containerFlag), _pHdr(NULL) {}
	virtual DirBuilder::Record *DoGenerateChild(const char *name, bool containerFlag);
	virtual Directory *DoGenerateDirectory(Directory *pParent, Directory::Type type);
	inline void SetHeader(Header *pHdr) { _pHdr.reset(pHdr); }
	inline const Header *GetHeader() const { return _pHdr.get(); }
};

//-----------------------------------------------------------------------------
// Object_stat declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(stat);

class Object_stat : public Object {
private:
	Header _hdr;
public:
	Gura_DeclareObjectAccessor(stat)
public:
	inline Object_stat(const Header &hdr) : Object(Gura_UserClass(stat)), _hdr(hdr) {}
	inline Object_stat(const Object_stat &obj) : Object(obj), _hdr(obj._hdr) {}
	virtual ~Object_stat();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// Object_reader declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(reader);

class Object_reader : public Object {
private:
	AutoPtr<Stream> _pStreamSrc;
	AutoPtr<OAL::Memory> _pMemoryBlock;
public:
	Gura_DeclareObjectAccessor(reader)
public:
	Object_reader();
	virtual ~Object_reader();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	bool Open(Environment &env, Signal sig, Stream *pStreamSrc, CompressionType compressionType);
	inline Stream *GetStreamSrc() { return _pStreamSrc.get(); }
	Header *NextHeader(Signal sig);
};

//-----------------------------------------------------------------------------
// Object_writer declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(writer);

class Object_writer : public Object {
private:
	Signal _sig;
	AutoPtr<Stream> _pStreamDst;
	AutoPtr<OAL::Memory> _pMemoryBlock;
public:
	Gura_DeclareObjectAccessor(writer)
public:
	Object_writer(Signal sig);
	virtual ~Object_writer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	bool Open(Environment &env, Stream *pStreamSrc, CompressionType compressionType);
	bool Add(Stream &streamSrc, const char *fileName);
	bool Close();
	inline Stream *GetStreamDst() { return _pStreamDst.get(); }
};

//-----------------------------------------------------------------------------
// Iterator_Entry declaration
//-----------------------------------------------------------------------------
class Iterator_Entry : public Iterator {
private:
	AutoPtr<Object_reader> _pObjReader;
	size_t _offsetNext;
public:
	inline Iterator_Entry(Object_reader *pObjReader);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}}

#endif
