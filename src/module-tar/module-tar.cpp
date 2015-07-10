//-----------------------------------------------------------------------------
// Gura module: tar
// http://www.gnu.org/software/tar/manual/html_node/Standard.html
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(tar)

//-----------------------------------------------------------------------------
// TAR format data types
//-----------------------------------------------------------------------------
const int BLOCKSIZE			= 512;

const char *TMAGIC			= "ustar";	// ustar and a null
const int TMAGLEN			= 6;
const char *TVERSION		= "00";		// 00 and no null
const int TVERSLEN			= 2;

// Values used in typeflag field.
const char REGTYPE			= '0';		// regular file
const char AREGTYPE			= '\0';		// regular file
const char LNKTYPE			= '1';		// link
const char SYMTYPE			= '2';		// reserved
const char CHRTYPE			= '3';		// character special
const char BLKTYPE			= '4';		// block special
const char DIRTYPE			= '5';		// directory
const char FIFOTYPE			= '6';		// FIFO special
const char CONTTYPE			= '7';		// reserved
const char XHDTYPE			= 'x';		// Extended header referring to the next file in the archive
const char XGLTYPE			= 'g';		// Global extended header

// Bits used in the mode field, values in octal. 
const ULong TSUID	= 04000;	// set UID on execution
const ULong TSGID	= 02000;	// set GID on execution
const ULong TSVTX	= 01000;	// reserved
								// file permissions
const ULong TUREAD	= 00400;	// read by owner
const ULong TUWRITE	= 00200;	// write by owner
const ULong TUEXEC	= 00100;	// execute/search by owner
const ULong TGREAD	= 00040;	// read by group
const ULong TGWRITE	= 00020;	// write by group
const ULong TGEXEC	= 00010;	// execute/search by group
const ULong TOREAD	= 00004;	// read by other
const ULong TOWRITE	= 00002;	// write by other
const ULong TOEXEC	= 00001;	// execute/search by other

//-----------------------------------------------------------------------------
// Header implementation
//-----------------------------------------------------------------------------
Header::Header()
{
}

Header::Header(const Header &hdr) :
	_offset(hdr._offset), _mode(hdr._mode), _uid(hdr._uid), _gid(hdr._gid),
	_size(hdr._size), _mtime(hdr._mtime), _atime(hdr._atime), _ctime(hdr._ctime),
	_chksum(hdr._chksum), _typeflag(hdr._typeflag),
	_devmajor(hdr._devmajor), _devminor(hdr._devminor)
{
	::memcpy(_name, hdr._name, sizeof(_name));
	::memcpy(_linkname, hdr._linkname, sizeof(_linkname));
	::memcpy(_uname, hdr._uname, sizeof(_uname));
	::memcpy(_gname, hdr._gname, sizeof(_gname));
}

void Header::Initialize()
{
	SetName("");
	SetLinkName("");
	SetUName("");
	SetGName("");
	SetMode(0);
	SetUid(0);
	SetGid(0);
	SetSize(0);
	//SetMTime();
	//SetATime();
	//SetCTime();
	SetChksum(0);
	SetTypeFlag('0');
	SetDevMajor(0);
	SetDevMinor(0);
}

bool Header::SetRawHeader(Signal &sig, const star_header &rawHdr)
{
	_name[sizeof(_name) - 1] = '\0';
	_linkname[sizeof(_linkname) - 1] = '\0';
	_uname[sizeof(_uname) - 1] = '\0';
	_gname[sizeof(_gname) - 1] = '\0';
	::memcpy(_name, rawHdr.name, sizeof(rawHdr.name));
	::memcpy(_linkname, rawHdr.linkname, sizeof(rawHdr.linkname));
	::memcpy(_uname, rawHdr.uname, sizeof(rawHdr.uname));
	::memcpy(_gname, rawHdr.gname, sizeof(rawHdr.gname));
	_mode = OctetToULong(sig, rawHdr.mode, sizeof(rawHdr.mode));
	if (sig.IsSignalled()) return false;
	_uid = OctetToULong(sig, rawHdr.uid, sizeof(rawHdr.uid));
	if (sig.IsSignalled()) return false;
	_gid = OctetToULong(sig, rawHdr.gid, sizeof(rawHdr.gid));
	if (sig.IsSignalled()) return false;
	_size = OctetToULong(sig, rawHdr.size, sizeof(rawHdr.size));
	if (sig.IsSignalled()) return false;
	do {
		ULong num = OctetToULong(sig, rawHdr.mtime, sizeof(rawHdr.mtime));
		if (sig.IsSignalled()) return false;
		_mtime.SetUnixTime(num);
	} while (0);
	do {
		ULong num = OctetToULong(sig, rawHdr.atime, sizeof(rawHdr.atime));
		if (sig.IsSignalled()) return false;
		_atime.SetUnixTime(num);
	} while (0);
	do {
		ULong num = OctetToULong(sig, rawHdr.ctime, sizeof(rawHdr.ctime));
		if (sig.IsSignalled()) return false;
		_ctime.SetUnixTime(num);
	} while (0);
	_chksum = OctetToULong(sig, rawHdr.chksum, sizeof(rawHdr.chksum));
	if (sig.IsSignalled()) return false;
	_typeflag = rawHdr.typeflag;
	_devmajor = OctetToULong(sig, rawHdr.devmajor, sizeof(rawHdr.devmajor));
	if (sig.IsSignalled()) return false;
	_devminor = OctetToULong(sig, rawHdr.devminor, sizeof(rawHdr.devminor));
	if (sig.IsSignalled()) return false;
	return true;
}

void Header::ComposeHeaderBlock(void *memBlock)
{
	star_header &rawHdr = *reinterpret_cast<star_header *>(memBlock);
	::memset(memBlock, 0x00, BLOCKSIZE);
	::memcpy(rawHdr.name,		_name, sizeof(rawHdr.name));
	::sprintf(rawHdr.mode,		"%06lo ", _mode);
	::sprintf(rawHdr.uid,		"%06lo ", _uid);
	::sprintf(rawHdr.gid,		"%06lo ", _gid);
	::sprintf(rawHdr.size,		"%11lo", _size);
	rawHdr.size[11] = ' ';
	::sprintf(rawHdr.mtime,		"%11lo", _mtime.GetUnixTime());
	rawHdr.mtime[11] = ' ';
	::memset(rawHdr.chksum,		' ', 8);
	rawHdr.typeflag = _typeflag;
	::memcpy(rawHdr.linkname,	_linkname, sizeof(rawHdr.linkname));
	::memcpy(rawHdr.magic,		"ustar ", 6);
	::memcpy(rawHdr.version,	" \x00", 2);
	::memcpy(rawHdr.uname,		_uname, sizeof(rawHdr.uname));
	::memcpy(rawHdr.gname,		_gname, sizeof(rawHdr.gname));
	//::sprintf(rawHdr.devmajor,	"%06o ", _devmajor);
	//::sprintf(rawHdr.devminor,	"%06o ", _devminor);
	//::memset(rawHdr.prefix,	0x00, sizeof(rawHdr.prefix));
	//::sprintf(rawHdr.atime,		"%11o", _atime.GetUnixTime());
	//rawHdr.atime[11] = ' ';
	//::sprintf(rawHdr.ctime,		"%11o", _ctime.GetUnixTime());
	//rawHdr.ctime[11] = ' ';
	ULong chksum = 0;
	UChar *p = reinterpret_cast<UChar *>(&rawHdr);
	for (int i = 0; i < BLOCKSIZE; i++, p++) chksum += *p;
	::sprintf(rawHdr.chksum,	"%6lo ", chksum);
}

//-----------------------------------------------------------------------------
// Implementation of Object_reader
//-----------------------------------------------------------------------------
Object_reader::Object_reader() : Object(Gura_UserClass(reader)),
							_pMemoryBlock(new MemoryHeap(BLOCKSIZE))
{
}

Object_reader::~Object_reader()
{
}

Object *Object_reader::Clone() const
{
	return nullptr;
}

String Object_reader::ToString(bool exprFlag)
{
	String str;
	str = "<tar.reader:";
	if (_pStreamSrc.IsNull()) {
		str += "invalid";
	} else {
		str += _pStreamSrc->GetName();
	}
	str += ">";
	return str;
}

bool Object_reader::Open(Environment &env, Signal &sig,
						Stream *pStreamSrc, CompressionType compressionType)
{
	_pStreamSrc.reset(DecorateReaderStream(env, sig,
				pStreamSrc, pStreamSrc->GetIdentifier(), compressionType));
	return !sig.IsSignalled();
}

Header *Object_reader::NextHeader(Signal &sig)
{
	return ReadHeader(sig, _pStreamSrc.get(), _pMemoryBlock->GetPointer());
}

//-----------------------------------------------------------------------------
// Interfaces of tar.reader
//-----------------------------------------------------------------------------
// tar.reader#entries() {block?}
Gura_DeclareMethod(reader, entries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"");
}

Gura_ImplementMethod(reader, entries)
{
	Object_reader *pThis = Object_reader::GetThisObj(args);
	Iterator *pIterator = new Iterator_Entry(Object_reader::Reference(pThis));
	return ReturnIterator(env, sig, args, pIterator);
}

// implementation of class reader
Gura_ImplementUserClass(reader)
{
	Gura_AssignMethod(reader, entries);
}

//-----------------------------------------------------------------------------
// Implementation of Object_writer
//-----------------------------------------------------------------------------
Object_writer::Object_writer(Signal &sig) : Object(Gura_UserClass(writer)),
					_sig(sig), _pMemoryBlock(new MemoryHeap(BLOCKSIZE))
{
}

Object_writer::~Object_writer()
{
	Close();
}

bool Object_writer::Open(Environment &env,
						Stream *pStreamDst, CompressionType compressionType)
{
	_pStreamDst.reset(DecorateWriterStream(env, _sig,
				pStreamDst, pStreamDst->GetIdentifier(), compressionType));
	return !_sig.IsSignalled();
}

Object *Object_writer::Clone() const
{
	return nullptr;
}

String Object_writer::ToString(bool exprFlag)
{
	String str;
	str = "<tar.writer:";
	if (_pStreamDst.IsNull()) {
		str += "invalid";
	} else {
		str += _pStreamDst->GetName();
	}
	str += ">";
	return str;
}

bool Object_writer::Add(Stream &streamSrc, const char *fileName)
{
	if (_pStreamDst.IsNull()) {
		_sig.SetError(ERR_IOError, "invalid tar writer");
		return false;
	}
	size_t bytesBody = streamSrc.GetSize();
	size_t bytesPadding = (bytesBody + BLOCKSIZE - 1) /
										BLOCKSIZE * BLOCKSIZE - bytesBody;
	AutoPtr<Memory> pMemory(new MemoryHeap(32768));
	void *buff = pMemory->GetPointer();
	Header hdr;
	hdr.SetName(fileName);
	hdr.SetLinkName("");
	hdr.SetUName("root");
	hdr.SetGName("");
	hdr.SetUid(0);
	hdr.SetGid(0);
	hdr.SetSize(streamSrc.GetSize());
	Stream::Attribute attr;
	if (streamSrc.GetAttribute(attr)) {
		hdr.SetMode(0100000 | (attr.attr & 0777));
		hdr.SetMTime(attr.mtime);
		hdr.SetATime(attr.atime);
		hdr.SetCTime(attr.ctime);
	} else {
		hdr.SetMode(0100666);
		DateTime dt = OAL::GetCurDateTime(false);
		hdr.SetMTime(dt);
		hdr.SetATime(dt);
		hdr.SetCTime(dt);
	}
	hdr.SetChksum(0);
	hdr.SetTypeFlag(0x00);
	hdr.SetDevMajor(0);
	hdr.SetDevMinor(0);
	hdr.ComposeHeaderBlock(buff);
	_pStreamDst->Write(_sig, buff, BLOCKSIZE);
	if (_sig.IsSignalled()) return false;
	for (;;) {
		size_t bytesRead = streamSrc.Read(_sig, buff, pMemory->GetSize());
		if (_sig.IsSignalled()) break;
		if (bytesRead == 0) break;
		_pStreamDst->Write(_sig, buff, bytesRead);
		if (_sig.IsSignalled()) break;
	}
	::memset(buff, 0x00, bytesPadding);
	_pStreamDst->Write(_sig, buff, bytesPadding);
	if (_sig.IsSignalled()) return false;
	return true;
}

bool Object_writer::Close()
{
	if (_pStreamDst.IsNull()) return true;
	const size_t bytesTerminator = BLOCKSIZE * 2;
	AutoPtr<Memory> pMemory(new MemoryHeap(bytesTerminator));
	void *buff = pMemory->GetPointer();
	::memset(buff, 0x00, bytesTerminator);
	_pStreamDst->Write(_sig, buff, bytesTerminator);
	if (_sig.IsSignalled()) return false;
	_pStreamDst.reset(nullptr);
	return true;
}

//-----------------------------------------------------------------------------
// Interfaces of tar.writer
//-----------------------------------------------------------------------------
// tar.writer#add(stream:stream:r, filename?:string):map:reduce
Gura_DeclareMethod(writer, add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"");
}

Gura_ImplementMethod(writer, add)
{
	Object_writer *pThis = Object_writer::GetThisObj(args);
	String fileName;
	if (args.Is_string(1)) {
		fileName = args.GetString(1);
	} else {
		const char *identifier = args.GetStream(0).GetIdentifier();
		if (identifier == nullptr) {
			sig.SetError(ERR_ValueError, "stream doesn't have an identifier");
			return Value::Null;
		}
		PathMgr::SplitFileName(identifier, nullptr, &fileName);
	}
	if (!pThis->Add(args.GetStream(0), fileName.c_str())) return Value::Null;
	return args.GetThis();
}

// tar.writer#close():reduce
Gura_DeclareMethod(writer, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"");
}

Gura_ImplementMethod(writer, close)
{
	Object_writer *pThis = Object_writer::GetThisObj(args);
	if (!pThis->Close()) return Value::Null;
	return args.GetThis();
}

// implementation of class writer
Gura_ImplementUserClass(writer)
{
	Gura_AssignMethod(writer, add);
	Gura_AssignMethod(writer, close);
}

//-----------------------------------------------------------------------------
// Iterator_Entry implementation
//-----------------------------------------------------------------------------
Iterator_Entry::Iterator_Entry(Object_reader *pObjReader) :
			Iterator(false), _pObjReader(pObjReader), _offsetNext(InvalidSize)
{
}

Iterator *Iterator_Entry::GetSource()
{
	return nullptr;
}

bool Iterator_Entry::DoNext(Environment &env, Signal &sig, Value &value)
{
	Stream *pStreamSrc = _pObjReader->GetStreamSrc();
	if (_offsetNext != InvalidSize) {
		pStreamSrc->Seek(sig, _offsetNext, Stream::SeekSet);
	}
	std::unique_ptr<Header> pHdr(_pObjReader->NextHeader(sig));
	if (pHdr.get() == nullptr) return false;
	_offsetNext = pStreamSrc->Tell() + pHdr->CalcBlocks() * BLOCKSIZE;
	Stream *pStreamEntry = new Stream_Entry(env, sig,
								Stream::Reference(pStreamSrc), *pHdr);
	value = Value(new Object_stream(env, pStreamEntry));
	return true;
}

String Iterator_Entry::ToString() const
{
	String rtn;
	rtn += "<iterator:tar.entry>";
	return rtn;
}

void Iterator_Entry::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Implementation of Object_stat
//-----------------------------------------------------------------------------
Object_stat::~Object_stat()
{
}

Object *Object_stat::Clone() const
{
	return new Object_stat(*this);
}

bool Object_stat::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(name));
	symbols.insert(Gura_UserSymbol(filename));
	symbols.insert(Gura_UserSymbol(linkname));
	symbols.insert(Gura_UserSymbol(uname));
	symbols.insert(Gura_UserSymbol(gname));
	symbols.insert(Gura_UserSymbol(mode));
	symbols.insert(Gura_UserSymbol(uid));
	symbols.insert(Gura_UserSymbol(gid));
	symbols.insert(Gura_UserSymbol(size));
	symbols.insert(Gura_UserSymbol(mtime));
	symbols.insert(Gura_UserSymbol(atime));
	symbols.insert(Gura_UserSymbol(ctime));
	symbols.insert(Gura_UserSymbol(chksum));
	symbols.insert(Gura_UserSymbol(typeflag));
	symbols.insert(Gura_UserSymbol(devmajor));
	symbols.insert(Gura_UserSymbol(devminor));
	return true;
}

Value Object_stat::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(name))) {
		return Value(_hdr.GetName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(filename))) {
		return Value(_hdr.GetName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(linkname))) {
		return Value(_hdr.GetLinkName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(uname))) {
		return Value(_hdr.GetUName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(gname))) {
		return Value(_hdr.GetGName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mode))) {
		return Value(_hdr.GetMode());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(uid))) {
		return Value(_hdr.GetUid());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(gid))) {
		return Value(_hdr.GetGid());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(size))) {
		return Value(_hdr.GetSize());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mtime))) {
		return Value(new Object_datetime(env, _hdr.GetMTime()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(atime))) {
		return Value(new Object_datetime(env, _hdr.GetATime()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ctime))) {
		return Value(new Object_datetime(env, _hdr.GetCTime()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(chksum))) {
		return Value(_hdr.GetChksum());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(typeflag))) {
		return Value(_hdr.GetTypeFlag());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(devmajor))) {
		return Value(_hdr.GetDevMajor());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(devminor))) {
		return Value(_hdr.GetDevMinor());
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_stat::ToString(bool exprFlag)
{
	String str;
	str = "<tar.stat:";
	str += _hdr.GetName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Interfaces of tar.stat
//-----------------------------------------------------------------------------
// implementation of class stat
Gura_ImplementUserClass(stat)
{
}

//-----------------------------------------------------------------------------
// Stream_Entry implementation
//-----------------------------------------------------------------------------
Stream_Entry::Stream_Entry(Environment &env, Signal &sig, Stream *pStreamSrc, const Header &hdr) :
		Stream(env, sig, ATTR_Readable), _pStreamSrc(pStreamSrc),
		_hdr(hdr), _name(hdr.GetName()), _offsetTop(pStreamSrc->Tell())
{
}

Stream_Entry::~Stream_Entry()
{
	Close();
}

const char *Stream_Entry::GetName() const
{
	return _name.c_str();
}

const char *Stream_Entry::GetIdentifier() const
{
	return _name.c_str();
}

bool Stream_Entry::GetAttribute(Attribute &attr)
{
	attr.atime = attr.ctime = attr.mtime = _hdr.GetMTime();
	attr.attr = _hdr.GetMode(), attr.attrMask = 0777;
	return true;
}

bool Stream_Entry::SetAttribute(const Attribute &attr)
{
	return false;
}

bool Stream_Entry::FlushRead(Signal &sig)
{
	Stream &streamSrc = GetSource();
	size_t offset = _offsetTop + _hdr.CalcBlocks() * BLOCKSIZE;
	return streamSrc.Seek(sig, offset, Stream::SeekSet);
}

size_t Stream_Entry::DoRead(Signal &sig, void *buff, size_t bytes)
{
	Stream &streamSrc = GetSource();
	size_t bytesRest = _hdr.GetSize() - (streamSrc.Tell() - _offsetTop);
	if (bytes > bytesRest) bytes = bytesRest;
	return streamSrc.Read(sig, buff, bytes);
}

bool Stream_Entry::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	Stream &streamSrc = GetSource();
	if (seekMode == SeekSet) {
		return streamSrc.Seek(sig, static_cast<long>(_offsetTop + offset), seekMode);
	} else if (seekMode == SeekCur) {
		return streamSrc.Seek(sig, offset, seekMode);
	}
	return false;
}

size_t Stream_Entry::DoWrite(Signal &sig, const void *buff, size_t len)
{
	return 0;
}

bool Stream_Entry::DoFlush(Signal &sig)
{
	return false;
}

bool Stream_Entry::DoClose(Signal &sig)
{
	_pStreamSrc.reset(nullptr);
	return Stream::DoClose(sig);
}

size_t Stream_Entry::DoGetSize()
{
	return _hdr.GetSize();
}

Object *Stream_Entry::DoGetStatObj(Signal &sig)
{
	return new Object_stat(_hdr);
}

//-----------------------------------------------------------------------------
// Directory_TAR implementation
//-----------------------------------------------------------------------------
Directory_TAR::Directory_TAR(Directory *pParent, const char *name, Type type,
		DirBuilder::Structure *pStructure, Record_TAR *pRecord) :
	Directory(pParent, name, type, OAL::FileSeparator),
	_pStructure(pStructure), _pRecord(pRecord)
{
}

Directory_TAR::~Directory_TAR()
{
}

Directory *Directory_TAR::DoNext(Environment &env, Signal &sig)
{
	return _pRecord->Next(this);
}

Stream *Directory_TAR::DoOpenStream(Environment &env, Signal &sig, ULong attr)
{
	Directory *pDirectory = this;
	for ( ; pDirectory != nullptr && !pDirectory->IsBoundaryContainer();
										pDirectory = pDirectory->GetParent()) ;
	if (pDirectory != nullptr) pDirectory = pDirectory->GetParent();
	if (pDirectory == nullptr) {
		sig.SetError(ERR_IOError, "failed to open a stream");
		return nullptr;
	}
	AutoPtr<Stream> pStreamSrc(pDirectory->DoOpenStream(env, sig, attr));
	if (IsGZippedTar(pDirectory->GetName())) {
		ZLib::GZHeader hdr;
		if (!hdr.Read(sig, *pStreamSrc)) return nullptr;
		AutoPtr<ZLib::Stream_Inflater> pStreamInflater(
				new ZLib::Stream_Inflater(env, sig, pStreamSrc.release(), InvalidSize));
		if (!pStreamInflater->Initialize(sig, -MAX_WBITS)) return nullptr;
		pStreamSrc.reset(pStreamInflater.release());
	} else if (IsBZippedTar(pDirectory->GetName())) {
		AutoPtr<BZLib::Stream_Decompressor> pStreamDecompressor(
				new BZLib::Stream_Decompressor(env, sig, pStreamSrc.release(), InvalidSize));
		if (!pStreamDecompressor->Initialize(sig, 0, 0)) return nullptr;
		pStreamSrc.reset(pStreamDecompressor.release());
	}
	//::printf("%s: %08x\n", pDirectory->GetName(), _pRecord->GetOffset());
	//::printf("offset: %d\n", _pRecord->GetOffset());
	const Header *pHdr = _pRecord->GetHeader();
	if (!pStreamSrc->Seek(sig,
				static_cast<long>(pHdr->GetOffset()), Stream::SeekSet)) {
		return nullptr;
	}
	return new Stream_Entry(env, sig, pStreamSrc.release(), *pHdr);
}

Object *Directory_TAR::DoGetStatObj(Signal &sig)
{
	return new Object_stat(*_pRecord->GetHeader());
}

//-----------------------------------------------------------------------------
// Record_TAR implementation
//-----------------------------------------------------------------------------
DirBuilder::Record *Record_TAR::DoGenerateChild(const char *name, bool containerFlag)
{
	Record_TAR *pRecord = new Record_TAR(_pStructure, this, name, containerFlag);
	AddChild(pRecord);
	return pRecord;
}

Directory *Record_TAR::DoGenerateDirectory(Directory *pParent, Directory::Type type)
{
	return new Directory_TAR(Directory::Reference(pParent),
		GetName(), type, DirBuilder::Structure::Reference(_pStructure), this);
}

//-----------------------------------------------------------------------------
// PathMgr_TAR implementation
//-----------------------------------------------------------------------------
bool PathMgr_TAR::IsResponsible(Environment &env, Signal &sig,
						const Directory *pParent, const char *pathName)
{
	return pParent != nullptr && !pParent->IsContainer() &&
			(EndsWith(pParent->GetName(), ".tar", true) ||
										IsGZippedTar(pParent->GetName()));
}

Directory *PathMgr_TAR::DoOpenDirectory(Environment &env, Signal &sig,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	AutoPtr<Stream> pStream(pParent->DoOpenStream(env, sig, Stream::ATTR_Readable));
	if (sig.IsSignalled()) return nullptr;
	pStream.reset(DecorateReaderStream(env, sig,
					pStream.release(), pParent->GetName(), COMPRESS_Auto));
	if (sig.IsSignalled()) return nullptr;
	AutoPtr<Memory> pMemory(new MemoryHeap(BLOCKSIZE));
	void *buffBlock = pMemory->GetPointer();
	AutoPtr<DirBuilder::Structure> pStructure(new DirBuilder::Structure());
	pStructure->SetRoot(new Record_TAR(pStructure.get(), nullptr, "", true));
	for (;;) {
		std::unique_ptr<Header> pHdr(ReadHeader(sig, pStream.get(), buffBlock));
		if (sig.IsSignalled()) return nullptr;
		if (pHdr.get() == nullptr) break;
		Record_TAR *pRecord =
				dynamic_cast<Record_TAR *>(pStructure->AddRecord(pHdr->GetName()));
		size_t offset = pHdr->CalcBlocks() * BLOCKSIZE;
		pRecord->SetHeader(pHdr.release());
		if (!pStream->Seek(sig, offset, Stream::SeekCur)) return nullptr;
	}
	Directory *pDirectory = pStructure->GenerateDirectory(sig,
											pParent, pPathName, notFoundMode);
	pStructure.release();
	return pDirectory;
}

//-----------------------------------------------------------------------------
// Gura module functions: tar
//-----------------------------------------------------------------------------
// tar.reader(stream:stream:r, compression?:symbol) {block?}
Gura_DeclareFunction(reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "compression", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(reader));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"");
}

Gura_ImplementFunction(reader)
{
	Stream &streamSrc = args.GetStream(0);
	CompressionType compressionType = args.Is_symbol(1)?
				SymbolToCompressionType(args.GetSymbol(1)) : COMPRESS_Auto;
	if (compressionType == COMPRESS_Invalid) {
		sig.SetError(ERR_ValueError, "invalid compression symbol");
		return Value::Null;
	}
	AutoPtr<Object_reader> pObj(new Object_reader());
	if (!pObj->Open(env, sig, streamSrc.Reference(), compressionType)) {
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// tar.writer(stream:stream:w, compression?:symbol) {block?}
Gura_DeclareFunction(writer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "compression", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(writer));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"");
}

Gura_ImplementFunction(writer)
{
	Stream &streamDst = args.GetStream(0);
	CompressionType compressionType = args.Is_symbol(1)?
				SymbolToCompressionType(args.GetSymbol(1)) : COMPRESS_Auto;
	if (compressionType == COMPRESS_Invalid) {
		sig.SetError(ERR_ValueError, "invalid compression symbol");
		return Value::Null;
	}
	AutoPtr<Object_writer> pObj(new Object_writer(sig));
	if (!pObj->Open(env, streamDst.Reference(), compressionType)) {
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObj.release()));
}

// tar.test(stream:stream:r)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"");
}

Gura_ImplementFunction(test)
{
	Stream &stream = args.GetStream(0);
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(filename);
	Gura_RealizeUserSymbol(linkname);
	Gura_RealizeUserSymbol(uname);
	Gura_RealizeUserSymbol(gname);
	Gura_RealizeUserSymbol(mode);
	Gura_RealizeUserSymbol(uid);
	Gura_RealizeUserSymbol(gid);
	Gura_RealizeUserSymbol(size);
	Gura_RealizeUserSymbol(mtime);
	Gura_RealizeUserSymbol(atime);
	Gura_RealizeUserSymbol(ctime);
	Gura_RealizeUserSymbol(chksum);
	Gura_RealizeUserSymbol(typeflag);
	Gura_RealizeUserSymbol(devmajor);
	Gura_RealizeUserSymbol(devminor);
	Gura_RealizeUserSymbol(none);
	Gura_RealizeUserSymbol(gzip);
	Gura_RealizeUserSymbol(bzip2);
	Gura_RealizeUserSymbol(auto);
	// class realization
	Gura_RealizeAndPrepareUserClass(reader, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(writer, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(stat, env.LookupClass(VTYPE_object));
#if 0
const char REGTYPE			= '0';		// regular file
const char AREGTYPE			= '\0';		// regular file
const char LNKTYPE			= '1';		// link
const char SYMTYPE			= '2';		// reserved
const char CHRTYPE			= '3';		// character special
const char BLKTYPE			= '4';		// block special
const char DIRTYPE			= '5';		// directory
const char FIFOTYPE			= '6';		// FIFO special
const char CONTTYPE			= '7';		// reserved
const char XHDTYPE			= 'x';		// Extended header referring to the next file in the archive
const char XGLTYPE			= 'g';		// Global extended header
#endif
	// value assignment
	Gura_AssignValue(REGTYPE,	Value(REGTYPE));
	Gura_AssignValue(AREGTYPE,	Value(AREGTYPE));
	Gura_AssignValue(LNKTYPE,	Value(LNKTYPE));
	Gura_AssignValue(SYMTYPE,	Value(SYMTYPE));
	Gura_AssignValue(CHRTYPE,	Value(CHRTYPE));
	Gura_AssignValue(BLKTYPE,	Value(BLKTYPE));
	Gura_AssignValue(DIRTYPE,	Value(DIRTYPE));
	Gura_AssignValue(FIFOTYPE,	Value(FIFOTYPE));
	Gura_AssignValue(CONTTYPE,	Value(CONTTYPE));
	Gura_AssignValue(XHDTYPE,	Value(XHDTYPE));
	Gura_AssignValue(XGLTYPE,	Value(XGLTYPE));
	// function assignment
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	// registration of directory factory
	PathMgr::Register(env, new PathMgr_TAR());
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
CompressionType SymbolToCompressionType(const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_UserSymbol(none))) {
		return COMPRESS_None;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(auto))) {
		return COMPRESS_Auto;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(gzip))) {
		return COMPRESS_GZip;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bzip2))) {
		return COMPRESS_BZip2;
	} else {
		return COMPRESS_Invalid;
	}
}

Header *ReadHeader(Signal &sig, Stream *pStream, void *buffBlock)
{
	int nTerminator = 0;
	for (;;) {
		size_t bytesRead = pStream->Read(sig, buffBlock, BLOCKSIZE);
		if (sig.IsSignalled()) return nullptr;
		if (bytesRead < BLOCKSIZE) {
			sig.SetError(ERR_FormatError, "failed to read a block");
			return nullptr;
		}
		bool zeroBlockFlag = true;
		ULong *p = reinterpret_cast<ULong *>(buffBlock);
		for (int i = 0; i < BLOCKSIZE / 4; i++, p++) {
			if (*p != 0x00000000) {
				zeroBlockFlag = false;
				break;
			}
		}
		if (!zeroBlockFlag) break;
		nTerminator++;
		if (nTerminator == 2) return nullptr;
	}
	star_header &hdr = *reinterpret_cast<star_header *>(buffBlock);
	std::unique_ptr<Header> pHdr(new Header());
	pHdr->SetOffset(pStream->Tell());
	if (!pHdr->SetRawHeader(sig, hdr)) return nullptr;
	return pHdr.release();
}

Stream *DecorateReaderStream(Environment &env, Signal &sig, Stream *pStreamSrc,
							const char *name, CompressionType compressionType)
{
	if (compressionType != COMPRESS_Auto) {
		// nothing to do
	} else if (name == nullptr) {
		compressionType = COMPRESS_None;
	} else if (IsGZippedTar(name)) {
		compressionType = COMPRESS_GZip;
	} else if (IsBZippedTar(name)) {
		compressionType = COMPRESS_BZip2;
	} else {
		compressionType = COMPRESS_None;
	}
	if (compressionType == COMPRESS_GZip) {
		ZLib::GZHeader hdr;
		if (!hdr.Read(sig, *pStreamSrc)) return nullptr;
		AutoPtr<ZLib::Stream_Inflater> pStreamInflater(
					new ZLib::Stream_Inflater(env, sig, pStreamSrc, InvalidSize));
		if (!pStreamInflater->Initialize(sig, -MAX_WBITS)) return nullptr;
		pStreamSrc = pStreamInflater.release();
	} else if (compressionType == COMPRESS_BZip2) {
		AutoPtr<BZLib::Stream_Decompressor> pStreamDecompressor(
					new BZLib::Stream_Decompressor(env, sig, pStreamSrc, InvalidSize));
		int verbosity = 0, small = 0;
		if (!pStreamDecompressor->Initialize(sig, verbosity, small)) return nullptr;
		pStreamSrc = pStreamDecompressor.release();
	}
	return pStreamSrc;
}

Stream *DecorateWriterStream(Environment &env, Signal &sig, Stream *pStreamDst,
							const char *name, CompressionType compressionType)
{
	if (compressionType != COMPRESS_Auto) {
		// nothing to do
	} else if (name == nullptr) {
		compressionType = COMPRESS_None;
	} else if (IsGZippedTar(name)) {
		compressionType = COMPRESS_GZip;
	} else if (IsBZippedTar(name)) {
		compressionType = COMPRESS_BZip2;
	} else {
		compressionType = COMPRESS_None;
	}
	if (compressionType == COMPRESS_GZip) {
		int windowBits = 31;
		AutoPtr<ZLib::Stream_Deflater> pStreamDeflater(
					new ZLib::Stream_Deflater(env, sig, pStreamDst));
		if (!pStreamDeflater->Initialize(sig, Z_DEFAULT_COMPRESSION,
							windowBits, 8, Z_DEFAULT_STRATEGY)) return nullptr;
		pStreamDst = pStreamDeflater.release();
	} else if (compressionType == COMPRESS_BZip2) {
		AutoPtr<BZLib::Stream_Compressor> pStreamCompressor(
					new BZLib::Stream_Compressor(env, sig, pStreamDst));
		int blockSize100k = 9, verbosity = 0, workFactor = 0;
		if (!pStreamCompressor->Initialize(sig,
							blockSize100k, verbosity, workFactor)) return nullptr;
		pStreamDst = pStreamCompressor.release();
	}
	return pStreamDst;
}

ULong OctetToULong(Signal &sig, const char *octet, size_t len)
{
	ULong num = 0;
	for (const char *p = octet; len > 0; len--, p++) {
		char ch = *p;
		if (ch == '\0') break;
		if (ch == ' ') {
			continue;
		} else if (!IsOctDigit(ch)) {
			sig.SetError(ERR_FormatError, "invalid octet format");
			return 0;
		}
		num = (num << 3) | (ch - '0');
	}
	return num;
}

Gura_EndModuleBody(tar, tar)

Gura_RegisterModule(tar)
