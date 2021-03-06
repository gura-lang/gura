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
const UInt32 TSUID			= 04000;	// set UID on execution
const UInt32 TSGID			= 02000;	// set GID on execution
const UInt32 TSVTX			= 01000;	// reserved
										// file permissions
const UInt32 TUREAD			= 00400;	// read by owner
const UInt32 TUWRITE		= 00200;	// write by owner
const UInt32 TUEXEC			= 00100;	// execute/search by owner
const UInt32 TGREAD			= 00040;	// read by group
const UInt32 TGWRITE		= 00020;	// write by group
const UInt32 TGEXEC			= 00010;	// execute/search by group
const UInt32 TOREAD			= 00004;	// read by other
const UInt32 TOWRITE		= 00002;	// write by other
const UInt32 TOEXEC			= 00001;	// execute/search by other

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
	_mode = OctetToUInt32(sig, rawHdr.mode, sizeof(rawHdr.mode));
	if (sig.IsSignalled()) return false;
	_uid = OctetToUInt32(sig, rawHdr.uid, sizeof(rawHdr.uid));
	if (sig.IsSignalled()) return false;
	_gid = OctetToUInt32(sig, rawHdr.gid, sizeof(rawHdr.gid));
	if (sig.IsSignalled()) return false;
	_size = OctetToUInt32(sig, rawHdr.size, sizeof(rawHdr.size));
	if (sig.IsSignalled()) return false;
	do {
		time_t time = static_cast<time_t>(OctetToUInt64(sig, rawHdr.mtime, sizeof(rawHdr.mtime)));
		if (sig.IsSignalled()) return false;
		_mtime = DateTime(&time);
	} while (0);
	do {
		time_t time = static_cast<time_t>(OctetToUInt64(sig, rawHdr.atime, sizeof(rawHdr.atime)));
		if (sig.IsSignalled()) return false;
		_atime = DateTime(&time);
	} while (0);
	do {
		time_t time = static_cast<time_t>(OctetToUInt64(sig, rawHdr.ctime, sizeof(rawHdr.ctime)));
		if (sig.IsSignalled()) return false;
		_ctime = DateTime(&time);
	} while (0);
	_chksum = OctetToUInt32(sig, rawHdr.chksum, sizeof(rawHdr.chksum));
	if (sig.IsSignalled()) return false;
	_typeflag = rawHdr.typeflag;
	_devmajor = OctetToUInt32(sig, rawHdr.devmajor, sizeof(rawHdr.devmajor));
	if (sig.IsSignalled()) return false;
	_devminor = OctetToUInt32(sig, rawHdr.devminor, sizeof(rawHdr.devminor));
	if (sig.IsSignalled()) return false;
	return true;
}

void Header::ComposeHeaderBlock(void *memBlock) const
{
	star_header &rawHdr = *reinterpret_cast<star_header *>(memBlock);
	::memset(memBlock, 0x00, BLOCKSIZE);
	::memcpy(rawHdr.name,			_name, sizeof(rawHdr.name));
	::sprintf(rawHdr.mode,			"%06o ", _mode);
	::sprintf(rawHdr.uid,			"%06o ", _uid);
	::sprintf(rawHdr.gid,			"%06o ", _gid);
	::sprintf(rawHdr.size,			"%11o", static_cast<UInt32>(_size));
	rawHdr.size[11] = ' ';
	::sprintf(rawHdr.mtime,			"%11llo", static_cast<UInt64>(_mtime.GetUnixTime()));
	rawHdr.mtime[11] = ' ';
	::memset(rawHdr.chksum,			' ', 8);
	rawHdr.typeflag = _typeflag;
	::memcpy(rawHdr.linkname,		_linkname, sizeof(rawHdr.linkname));
	::memcpy(rawHdr.magic,			"ustar ", 6);
	::memcpy(rawHdr.version,		" \x00", 2);
	::memcpy(rawHdr.uname,			_uname, sizeof(rawHdr.uname));
	::memcpy(rawHdr.gname,			_gname, sizeof(rawHdr.gname));
	//::sprintf(rawHdr.devmajor,	"%06o ", _devmajor);
	//::sprintf(rawHdr.devminor,	"%06o ", _devminor);
	//::memset(rawHdr.prefix,		0x00, sizeof(rawHdr.prefix));
	//::sprintf(rawHdr.atime,		"%11o", _atime.GetUnixTime());
	//rawHdr.atime[11] = ' ';
	//::sprintf(rawHdr.ctime,		"%11o", _ctime.GetUnixTime());
	//rawHdr.ctime[11] = ' ';
	UInt32 chksum = 0;
	UChar *p = reinterpret_cast<UChar *>(&rawHdr);
	for (int i = 0; i < BLOCKSIZE; i++, p++) chksum += *p;
	::sprintf(rawHdr.chksum,		"%6o ", chksum);
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

bool Object_reader::Open(Environment &env,
						Stream *pStreamSrc, CompressionType compressionType)
{
	Signal &sig = env.GetSignal();
	_pStreamSrc.reset(DecorateReaderStream(env,
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
		Gura_Symbol(en), 
		"Creates an iterator that returns stream instances for each entry in the tar file.");
}

Gura_ImplementMethod(reader, entries)
{
	Object_reader *pThis = Object_reader::GetObjectThis(arg);
	Iterator *pIterator = new Iterator_Entry(Object_reader::Reference(pThis));
	return ReturnIterator(env, arg, pIterator);
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
	_pStreamDst.reset(DecorateWriterStream(env,
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

bool Object_writer::Add(Stream &streamSrc, const Header &hdr)
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
		Gura_Symbol(en), 
		"Adds an entry to the tar archive with a content from `stream` and a name of `filename`.\n"
		"\n"
		"If the argument `filename` is omitted, an identifier associated with the `stream`\n"
		"would be used as the entry name.\n");
}

Gura_ImplementMethod(writer, add)
{
	Signal &sig = env.GetSignal();
	Object_writer *pThis = Object_writer::GetObjectThis(arg);
	Stream &streamSrc = arg.GetStream(0);
	String fileName;
	if (arg.Is_string(1)) {
		fileName = arg.GetString(1);
	} else {
		const char *identifier = arg.GetStream(0).GetIdentifier();
		if (identifier == nullptr) {
			sig.SetError(ERR_ValueError, "stream doesn't have an identifier");
			return Value::Nil;
		}
		PathMgr::SplitFileName(identifier, nullptr, &fileName);
	}
	Header hdr;
	hdr.SetName(fileName.c_str());
	hdr.SetLinkName("");
	hdr.SetSize(streamSrc.GetSize());
	Stream::Attribute attr;
	if (streamSrc.GetAttribute(attr)) {
		char buff[80];
		hdr.SetMode(0100000 | (attr.attr & 0777));
		hdr.SetMTime(attr.mtime);
		hdr.SetATime(attr.atime);
		hdr.SetCTime(attr.ctime);
		hdr.SetUid(attr.uid);
		hdr.SetGid(attr.gid);
		::sprintf(buff, "%d", attr.uid);
		hdr.SetUName(buff);
		::sprintf(buff, "%d", attr.gid);
		hdr.SetGName(buff);
	} else {
		hdr.SetMode(0100666);
		DateTime dt = OAL::GetCurDateTime(false);
		hdr.SetMTime(dt);
		hdr.SetATime(dt);
		hdr.SetCTime(dt);
		hdr.SetUid(0);
		hdr.SetGid(0);
		hdr.SetUName("0");
		hdr.SetGName("0");
	}
	hdr.SetChksum(0);
	hdr.SetTypeFlag(0x00);
	hdr.SetDevMajor(0);
	hdr.SetDevMinor(0);
	if (!pThis->Add(streamSrc, hdr)) return Value::Nil;
	return arg.GetValueThis();
}

// tar.writer#close():reduce
Gura_DeclareMethod(writer, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), 
		"Flushes all the unfinished writing processes and invalidates the `tar.writer` instance.");
}

Gura_ImplementMethod(writer, close)
{
	Object_writer *pThis = Object_writer::GetObjectThis(arg);
	if (!pThis->Close()) return Value::Nil;
	return arg.GetValueThis();
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
			Iterator(Finite), _pObjReader(pObjReader), _offsetNext(InvalidSize)
{
}

Iterator *Iterator_Entry::GetSource()
{
	return nullptr;
}

bool Iterator_Entry::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	Stream *pStreamSrc = _pObjReader->GetStreamSrc();
	if (_offsetNext != InvalidSize) {
		pStreamSrc->Seek(sig, _offsetNext, Stream::SeekSet);
	}
	std::unique_ptr<Header> pHdr(_pObjReader->NextHeader(sig));
	if (pHdr.get() == nullptr) return false;
	_offsetNext = pStreamSrc->Tell() + pHdr->CalcBlocks() * BLOCKSIZE;
	Stream *pStreamEntry = new Stream_Entry(env, Stream::Reference(pStreamSrc), *pHdr);
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

String Object_stat::ToString(bool exprFlag)
{
	String str;
	str = "<tar.stat:";
	str += _hdr.GetName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// tar.stat#atime
Gura_DeclareProperty_R(stat, atime)
{
	SetPropAttr(VTYPE_datetime);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, atime)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(new Object_datetime(env, hdr.GetATime()));
}

// tar.stat#chksum
Gura_DeclareProperty_R(stat, chksum)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, chksum)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetChksum());
}

// tar.stat#ctime
Gura_DeclareProperty_R(stat, ctime)
{
	SetPropAttr(VTYPE_datetime);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, ctime)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(new Object_datetime(env, hdr.GetCTime()));
}

// tar.stat#devmajor
Gura_DeclareProperty_R(stat, devmajor)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, devmajor)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetDevMajor());
}

// tar.stat#devminor
Gura_DeclareProperty_R(stat, devminor)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, devminor)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetDevMinor());
}

// tar.stat#filename
Gura_DeclareProperty_R(stat, filename)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, filename)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetName());
}

// tar.stat#gid
Gura_DeclareProperty_R(stat, gid)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, gid)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetGid());
}

// tar.stat#gname
Gura_DeclareProperty_R(stat, gname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, gname)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetGName());
}

// tar.stat#linkname
Gura_DeclareProperty_R(stat, linkname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, linkname)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetLinkName());
}

// tar.stat#mode
Gura_DeclareProperty_R(stat, mode)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, mode)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetMode());
}

// tar.stat#mtime
Gura_DeclareProperty_R(stat, mtime)
{
	SetPropAttr(VTYPE_datetime);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, mtime)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(new Object_datetime(env, hdr.GetMTime()));
}

// tar.stat#name
Gura_DeclareProperty_R(stat, name)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, name)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetName());
}

// tar.stat#size
Gura_DeclareProperty_R(stat, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, size)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetSize());
}

// tar.stat#typeflag
Gura_DeclareProperty_R(stat, typeflag)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, typeflag)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetTypeFlag());
}

// tar.stat#uid
Gura_DeclareProperty_R(stat, uid)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, uid)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetUid());
}

// tar.stat#uname
Gura_DeclareProperty_R(stat, uname)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, uname)
{
	const Header &hdr = Object_stat::GetObject(valueThis)->GetHeader();
	return Value(hdr.GetUName());
}

//-----------------------------------------------------------------------------
// Interfaces of tar.stat
//-----------------------------------------------------------------------------
// implementation of class stat
Gura_ImplementUserClass(stat)
{
	// Assignment of properties
	Gura_AssignProperty(stat, atime);
	Gura_AssignProperty(stat, chksum);
	Gura_AssignProperty(stat, ctime);
	Gura_AssignProperty(stat, devmajor);
	Gura_AssignProperty(stat, devminor);
	Gura_AssignProperty(stat, filename);
	Gura_AssignProperty(stat, gid);
	Gura_AssignProperty(stat, gname);
	Gura_AssignProperty(stat, linkname);
	Gura_AssignProperty(stat, mode);
	Gura_AssignProperty(stat, mtime);
	Gura_AssignProperty(stat, name);
	Gura_AssignProperty(stat, size);
	Gura_AssignProperty(stat, typeflag);
	Gura_AssignProperty(stat, uid);
	Gura_AssignProperty(stat, uname);
}

//-----------------------------------------------------------------------------
// Stream_Entry implementation
//-----------------------------------------------------------------------------
Stream_Entry::Stream_Entry(Environment &env, Stream *pStreamSrc, const Header &hdr) :
		Stream(env, ATTR_Readable), _pStreamSrc(pStreamSrc),
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
	Directory(pParent, name, type, OAL::FileSeparator, OAL::IgnoreCaseInPathNameFlag),
	_pStructure(pStructure), _pRecord(pRecord)
{
}

Directory_TAR::~Directory_TAR()
{
}

Directory *Directory_TAR::DoNext(Environment &env)
{
	return _pRecord->Next(this);
}

Stream *Directory_TAR::DoOpenStream(Environment &env, UInt32 attr)
{
	Signal &sig = env.GetSignal();
	Directory *pDirectory = this;
	for ( ; pDirectory != nullptr && !pDirectory->IsBoundaryContainer();
										pDirectory = pDirectory->GetParent()) ;
	if (pDirectory != nullptr) pDirectory = pDirectory->GetParent();
	if (pDirectory == nullptr) {
		sig.SetError(ERR_IOError, "failed to open a stream");
		return nullptr;
	}
	AutoPtr<Stream> pStreamSrc(pDirectory->DoOpenStream(env, attr));
	if (IsGZippedTar(pDirectory->GetName())) {
		ZLib::GZHeader hdr;
		if (!hdr.Read(sig, *pStreamSrc)) return nullptr;
		AutoPtr<ZLib::Stream_Inflater> pStreamInflater(
			new ZLib::Stream_Inflater(env, pStreamSrc.release(), InvalidSize));
		if (!pStreamInflater->Initialize(sig, -MAX_WBITS)) return nullptr;
		pStreamSrc.reset(pStreamInflater.release());
	} else if (IsBZippedTar(pDirectory->GetName())) {
		AutoPtr<BZLib::Stream_Decompressor> pStreamDecompressor(
			new BZLib::Stream_Decompressor(env, pStreamSrc.release(), InvalidSize));
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
	return new Stream_Entry(env, pStreamSrc.release(), *pHdr);
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
bool PathMgr_TAR::IsResponsible(Environment &env,
						const Directory *pParent, const char *pathName)
{
	return pParent != nullptr && !pParent->IsContainer() &&
			(EndsWith(pParent->GetName(), ".tar", true) ||
			 IsGZippedTar(pParent->GetName()) || IsBZippedTar(pParent->GetName()));
}

Directory *PathMgr_TAR::DoOpenDirectory(Environment &env,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	AutoPtr<Stream> pStreamSrc(pParent->DoOpenStream(env, Stream::ATTR_Readable));
	if (env.IsSignalled()) return nullptr;
	return CreateDirectory(env, pStreamSrc.get(), pParent, pPathName, notFoundMode);
}

//-----------------------------------------------------------------------------
// Gura module functions: tar
//-----------------------------------------------------------------------------
// tar.opendir(stream:stream:r) {block?}
Gura_DeclareFunction(opendir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `directory` instance that browses the contents in a TAR stream.");
}

Gura_ImplementFunction(opendir)
{
	Stream &stream = arg.GetStream(0);
	AutoPtr<Directory> pDirectory(CreateDirectory(env, &stream, nullptr, nullptr, PathMgr::NF_Signal));
	if (env.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_directory(env, pDirectory.release())));
}

// tar.reader(stream:stream:r, compression?:symbol) {block?}
Gura_DeclareFunction(reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "compression", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(reader));
	AddHelp(
		Gura_Symbol(en), 
		"Reads a tar file from `stream` and returns a `tar.reader` instance\n"
		"that is to be used to read contents from the archive.\n"
		"\n"
		"The argument `compression` specifies the compression format of the tar file\n"
		"and takes one of the following symbols:\n"
		"\n"
		"- `` `auto`` .. determins the format from a suffix name of the stream.\n"
		"- `` `gzip`` .. gzip format\n"
		"- `` `bzip2`` .. bzip2 format\n");
}

Gura_ImplementFunction(reader)
{
	Signal &sig = env.GetSignal();
	Stream &streamSrc = arg.GetStream(0);
	CompressionType compressionType = arg.Is_symbol(1)?
				SymbolToCompressionType(arg.GetSymbol(1)) : COMPRESS_Auto;
	if (compressionType == COMPRESS_Invalid) {
		sig.SetError(ERR_ValueError, "invalid compression symbol");
		return Value::Nil;
	}
	AutoPtr<Object_reader> pObj(new Object_reader());
	if (!pObj->Open(env, streamSrc.Reference(), compressionType)) {
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(pObj.release()));
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
		Gura_Symbol(en), 
		"Creates a tar file on `stream` and returns a `tar.writer` instance\n"
		"that is to be used to write contents to the archive.\n"
		"\n"
		"The argument `compression` specifies the compression format of the tar file\n"
		"and takes one of the following symbols:\n"
		"\n"
		"- `` `auto`` .. determins the format from a suffix name of the stream.\n"
		"- `` `gzip`` .. gzip format\n"
		"- `` `bzip2`` .. bzip2 format\n");
}

Gura_ImplementFunction(writer)
{
	Signal &sig = env.GetSignal();
	Stream &streamDst = arg.GetStream(0);
	CompressionType compressionType = arg.Is_symbol(1)?
				SymbolToCompressionType(arg.GetSymbol(1)) : COMPRESS_Auto;
	if (compressionType == COMPRESS_Invalid) {
		sig.SetError(ERR_ValueError, "invalid compression symbol");
		return Value::Nil;
	}
	AutoPtr<Object_writer> pObj(new Object_writer(sig));
	if (!pObj->Open(env, streamDst.Reference(), compressionType)) {
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(pObj.release()));
}

// tar.test(stream:stream:r)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), 
		"");
}

Gura_ImplementFunction(test)
{
	Stream &stream = arg.GetStream(0);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(none);
	Gura_RealizeUserSymbol(gzip);
	Gura_RealizeUserSymbol(bzip2);
	Gura_RealizeUserSymbol(auto);
	// class realization
	Gura_RealizeAndPrepareUserClass(reader, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(writer, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(stat, env.LookupClass(VTYPE_object));
	// value assignment
	Gura_AssignValue(REGTYPE,	Value(REGTYPE));	// regular file
	Gura_AssignValue(AREGTYPE,	Value(AREGTYPE));	// regular file
	Gura_AssignValue(LNKTYPE,	Value(LNKTYPE));	// link
	Gura_AssignValue(SYMTYPE,	Value(SYMTYPE));	// reserved
	Gura_AssignValue(CHRTYPE,	Value(CHRTYPE));	// character special
	Gura_AssignValue(BLKTYPE,	Value(BLKTYPE));	// block special
	Gura_AssignValue(DIRTYPE,	Value(DIRTYPE));	// directory
	Gura_AssignValue(FIFOTYPE,	Value(FIFOTYPE));	// FIFO special
	Gura_AssignValue(CONTTYPE,	Value(CONTTYPE));	// reserved
	Gura_AssignValue(XHDTYPE,	Value(XHDTYPE));	// Extended header referring to the next file in the archive
	Gura_AssignValue(XGLTYPE,	Value(XGLTYPE));	// Global extended header
	// function assignment
	Gura_AssignFunction(opendir);
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
		UInt32 *p = reinterpret_cast<UInt32 *>(buffBlock);
		for (int i = 0; i < BLOCKSIZE / sizeof(UInt32); i++, p++) {
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

Stream *DecorateReaderStream(Environment &env, Stream *pStreamSrc,
							const char *name, CompressionType compressionType)
{
	Signal &sig = env.GetSignal();
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
			new ZLib::Stream_Inflater(env, pStreamSrc, InvalidSize));
		if (!pStreamInflater->Initialize(sig, -MAX_WBITS)) return nullptr;
		pStreamSrc = pStreamInflater.release();
	} else if (compressionType == COMPRESS_BZip2) {
		AutoPtr<BZLib::Stream_Decompressor> pStreamDecompressor(
			new BZLib::Stream_Decompressor(env, pStreamSrc, InvalidSize));
		int verbosity = 0, small = 0;
		if (!pStreamDecompressor->Initialize(sig, verbosity, small)) return nullptr;
		pStreamSrc = pStreamDecompressor.release();
	}
	return pStreamSrc;
}

Stream *DecorateWriterStream(Environment &env, Stream *pStreamDst,
							const char *name, CompressionType compressionType)
{
	Signal &sig = env.GetSignal();
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
			new ZLib::Stream_Deflater(env, pStreamDst));
		if (!pStreamDeflater->Initialize(sig, Z_DEFAULT_COMPRESSION,
							windowBits, 8, Z_DEFAULT_STRATEGY)) return nullptr;
		pStreamDst = pStreamDeflater.release();
	} else if (compressionType == COMPRESS_BZip2) {
		AutoPtr<BZLib::Stream_Compressor> pStreamCompressor(
			new BZLib::Stream_Compressor(env, pStreamDst));
		int blockSize100k = 9, verbosity = 0, workFactor = 0;
		if (!pStreamCompressor->Initialize(sig,
							blockSize100k, verbosity, workFactor)) return nullptr;
		pStreamDst = pStreamCompressor.release();
	}
	return pStreamDst;
}

Directory *CreateDirectory(Environment &env, Stream *pStreamSrc,
	Directory *pParent, const char **pPathName, PathMgr::NotFoundMode notFoundMode)
{
	AutoPtr<Stream> pStream(DecorateReaderStream(
								env, pStreamSrc->Reference(), pStreamSrc->GetIdentifier(), COMPRESS_Auto));
	if (env.IsSignalled()) return nullptr;
	AutoPtr<Memory> pMemory(new MemoryHeap(BLOCKSIZE));
	void *buffBlock = pMemory->GetPointer();
	AutoPtr<DirBuilder::Structure> pStructure(new DirBuilder::Structure());
	pStructure->SetRoot(new Record_TAR(pStructure.get(), nullptr, "", true));
	for (;;) {
		std::unique_ptr<Header> pHdr(ReadHeader(env, pStream.get(), buffBlock));
		if (env.IsSignalled()) return nullptr;
		if (pHdr.get() == nullptr) break;
		Record_TAR *pRecord = dynamic_cast<Record_TAR *>(pStructure->AddRecord(pHdr->GetName()));
		size_t offset = pHdr->CalcBlocks() * BLOCKSIZE;
		pRecord->SetHeader(pHdr.release());
		if (!pStream->Seek(env, offset, Stream::SeekCur)) return nullptr;
	}
	return pStructure->GenerateDirectory(env, pParent, pPathName, notFoundMode);
}

UInt64 OctetToUInt64(Signal &sig, const char *octet, size_t len)
{
	UInt64 num = 0;
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
