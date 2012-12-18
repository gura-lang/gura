//-----------------------------------------------------------------------------
// Gura zip module
// specification: http://www.pkware.com/documents/casestudies/APPNOTE.TXT
//-----------------------------------------------------------------------------
#include "gura/ZLibHelper.h"
#include "gura/BZLibHelper.h"
#include "Module_zip.h"

Gura_BeginModule(zip)

//-----------------------------------------------------------------------------
// Implementation of Object_reader
//-----------------------------------------------------------------------------
Object_reader::Object_reader(Signal sig, Stream *pStreamSrc) :
				Object(Gura_UserClass(reader)), _pStreamSrc(pStreamSrc)
{
}

Object_reader::~Object_reader()
{
	foreach (CentralFileHeaderList, ppHdr, _hdrList) {
		delete *ppHdr;
	}
}

Object *Object_reader::Clone() const
{
	return NULL;
}

String Object_reader::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<zip.reader";
	if (_pStreamSrc.IsNull()) {
		str += ":invalid";
	} else {
		str += ":";
		str += _pStreamSrc->GetName();
		do {
			str += ":";
			str += NumberToString(_hdrList.size());
			str += "files";
		} while (0);
	}
	str += ">";
	return str;
}

bool Object_reader::ReadDirectory(Environment &env, Signal sig)
{
	if (!_pStreamSrc->IsBwdSeekable()) {
		Stream *pStreamPrefetch = Stream::Prefetch(sig, _pStreamSrc.release(), true);
		if (sig.IsSignalled()) return false;
		_pStreamSrc.reset(pStreamPrefetch);
	}
	unsigned long offsetCentralDirectory = SeekCentralDirectory(sig, _pStreamSrc.get());
	if (sig.IsSignalled()) return false;
	if (!_pStreamSrc->Seek(sig, offsetCentralDirectory, Stream::SeekSet)) return false;
	unsigned long signature;
	while (ReadStream(sig, *_pStreamSrc, &signature)) {
		//::printf("%08x\n", signature);
		if (signature == LocalFileHeader::Signature) {
			LocalFileHeader hdr;
			if (!hdr.Read(sig, *_pStreamSrc)) return false;
			if (!hdr.SkipFileData(sig, *_pStreamSrc)) return false;
		} else if (signature == ArchiveExtraDataRecord::Signature) {
			ArchiveExtraDataRecord record;
			if (!record.Read(sig, *_pStreamSrc)) return false;
		} else if (signature == CentralFileHeader::Signature) {
			CentralFileHeader *pHdr = new CentralFileHeader();
			if (!pHdr->Read(sig, *_pStreamSrc)) {
				delete pHdr;
				return false;
			}
			_hdrList.push_back(pHdr);
		} else if (signature == DigitalSignature::Signature) {
			DigitalSignature signature;
			if (!signature.Read(sig, *_pStreamSrc)) return false;
		} else if (signature == Zip64EndOfCentralDirectory::Signature) {
			Zip64EndOfCentralDirectory dir;
			if (!dir.Read(sig, *_pStreamSrc)) return false;
		} else if (signature == Zip64EndOfCentralDirectoryLocator::Signature) {
			Zip64EndOfCentralDirectoryLocator loc;
			if (!loc.Read(sig, *_pStreamSrc)) return false;
		} else if (signature == EndOfCentralDirectoryRecord::Signature) {
			EndOfCentralDirectoryRecord record;
			if (!record.Read(sig, *_pStreamSrc)) return false;
			break;
		} else {
			sig.SetError(ERR_FormatError, "unknown signature %08x", signature);
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
// Gura interfaces of zip.reader
//-----------------------------------------------------------------------------
// zip.reader#entries() {block?}
Gura_DeclareMethod(reader, entries)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(reader, entries)
{
	Object_reader *pSelf = Object_reader::GetSelfObj(args);
	if (pSelf->GetStreamSrc() == NULL) {
		sig.SetError(ERR_ValueError, "zip object is not readable");
		return Value::Null;
	}
	Iterator *pIterator = new Iterator_Entry(Object_reader::Reference(pSelf));
	return ReturnIterator(env, sig, args, pIterator);
}

// implementation of class zip.reader
Gura_ImplementUserClass(reader)
{
	Gura_AssignMethod(reader, entries);
}

//-----------------------------------------------------------------------------
// Implementation of Object_writer
//-----------------------------------------------------------------------------
Object_writer::Object_writer(Signal sig, Stream *pStreamDst,
											unsigned short compressionMethod) :
		Object(Gura_UserClass(writer)), _sig(sig),
		_pStreamDst(pStreamDst), _compressionMethod(compressionMethod)
{
}

Object_writer::~Object_writer()
{
	Finish();
	foreach (CentralFileHeaderList, ppHdr, _hdrList) {
		delete *ppHdr;
	}
}

Object *Object_writer::Clone() const
{
	return NULL;
}

String Object_writer::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<zip.writer";
	if (_pStreamDst.IsNull()) {
		str += ":invalid";
	} else {
		str += ":";
		str += _pStreamDst->GetName();
		do {
			str += ":";
			str += NumberToString(_hdrList.size());
			str += "files";
		} while (0);
	}
	str += ">";
	return str;
}

bool Object_writer::Add(Signal sig, Stream &streamSrc,
					const char *fileName, unsigned short compressionMethod)
{
	if (_pStreamDst.IsNull()) {
		sig.SetError(ERR_IOError, "invalid accesss to writer");
		return false;
	}
	const int memLevel = 8;
	CentralFileHeader *pHdr = new CentralFileHeader();
	_hdrList.push_back(pHdr);
	unsigned short version = (0 << 8) | (2 * 10 + 0);	// MS-DOS, 2.0
	unsigned short generalPurposeBitFlag = (1 << 3);	// ExistDataDescriptor
	DateTime dt;
	Stream::Attribute attr;
	if (streamSrc.GetAttribute(attr)) {
		dt = attr.mtime;
	} else {
		dt = OAL::GetCurDateTime(false);
	}
	unsigned short lastModFileTime = GetDosTime(dt);
	unsigned short lastModFileDate = GetDosDate(dt);
	unsigned long compressedSize = 0;
	unsigned long uncompressedSize = 0;
	unsigned long externalFileAttributes = (1 << 5);
	unsigned long relativeOffsetOfLocalHeader =
							static_cast<unsigned long>(_pStreamDst->Tell());
	do {
		CentralFileHeader::Fields &fields = pHdr->GetFields();
		XPackUShort(fields.VersionMadeBy,				version);
		XPackUShort(fields.VersionNeededToExtract,		version);
		XPackUShort(fields.GeneralPurposeBitFlag,		generalPurposeBitFlag);
		XPackUShort(fields.CompressionMethod,			compressionMethod);
		XPackUShort(fields.LastModFileTime,				lastModFileTime);
		XPackUShort(fields.LastModFileDate,				lastModFileDate);
		XPackULong(fields.Crc32,						0x00000000);
		XPackULong(fields.CompressedSize,				compressedSize);
		XPackULong(fields.UncompressedSize,				uncompressedSize);
		XPackUShort(fields.FileNameLength,				0x0000);
		XPackUShort(fields.ExtraFieldLength,			0x0000);
		XPackUShort(fields.FileCommentLength,			0x0000);
		XPackUShort(fields.DiskNumberStart,				0x0000);
		XPackUShort(fields.InternalFileAttributes,		0x0000);
		XPackULong(fields.ExternalFileAttributes,		externalFileAttributes);
		XPackULong(fields.RelativeOffsetOfLocalHeader,	relativeOffsetOfLocalHeader);
		pHdr->SetFileName(fileName);
		if (!pHdr->WriteAsLocalFileHeader(sig, *_pStreamDst)) return false;
	} while (0);
	AutoPtr<Stream> pStreamOut;
	size_t offsetDst = _pStreamDst->Tell();
	size_t offsetSrc = streamSrc.Tell();
	if (compressionMethod == METHOD_Store) {
		pStreamOut.reset(Stream::Reference(_pStreamDst.get()));
	} else if (compressionMethod == METHOD_Shrink) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor1) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor2) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor3) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor4) {
		// unsupported
	} else if (compressionMethod == METHOD_Implode) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor1) {
		// unsupported
	} else if (compressionMethod == METHOD_Deflate) {
		AutoPtr<ZLib::Stream_Deflater> pStreamDeflater(
			new ZLib::Stream_Deflater(sig, Stream::Reference(_pStreamDst.get())));
		if (!pStreamDeflater->Initialize(sig, Z_DEFAULT_COMPRESSION,
					-MAX_WBITS, memLevel, Z_DEFAULT_STRATEGY)) return false;
		pStreamOut.reset(pStreamDeflater.release());
	} else if (compressionMethod == METHOD_Deflate64) {
		// unsupported
	} else if (compressionMethod == METHOD_PKWARE) {
		// unsupported
	} else if (compressionMethod == METHOD_BZIP2) {
		AutoPtr<BZLib::Stream_Compressor> pStreamCompressor(
			new BZLib::Stream_Compressor(sig, Stream::Reference(_pStreamDst.get())));
		int blockSize100k = 9, verbosity = 0, workFactor = 0;
		if (!pStreamCompressor->Initialize(sig,
							blockSize100k, verbosity, workFactor)) return false;
		pStreamOut.reset(pStreamCompressor.release());
	} else if (compressionMethod == METHOD_LZMA) {
		// unsupported
	} else if (compressionMethod == METHOD_TERSA) {
		// unsupported
	} else if (compressionMethod == METHOD_LZ77) {
		// unsupported
	} else if (compressionMethod == METHOD_WavPack) {
		// unsupported
	} else if (compressionMethod == METHOD_PPMd) {
		// unsupported
	}
	if (pStreamOut.IsNull()) {
		sig.SetError(ERR_IOError,
				"unsupported compression method %d", compressionMethod);
		return false;
	}
	CRC32 crc32;
	OAL::Memory memory;
	void *buff = memory.Allocate(32768);
	for (;;) {
		size_t bytesRead = streamSrc.Read(sig, buff, memory.GetSize());
		if (sig.IsSignalled()) break;
		if (bytesRead == 0) break;
		crc32.Update(buff, bytesRead);
		pStreamOut->Write(sig, buff, bytesRead);
		if (sig.IsSignalled()) break;
	}
	pStreamOut->Flush(sig);
	if (sig.IsSignalled()) return false;
	unsigned long crc32num = crc32.GetResult();
	compressedSize = static_cast<unsigned long>(_pStreamDst->Tell() - offsetDst);
	uncompressedSize = static_cast<unsigned long>(streamSrc.Tell() - offsetSrc);
	do {
		DataDescriptor desc;
		DataDescriptor::Fields &fields = desc.GetFields();
		XPackULong(fields.Crc32,			crc32num);
		XPackULong(fields.CompressedSize,	compressedSize);
		XPackULong(fields.UncompressedSize,	uncompressedSize);
		if (!desc.Write(sig, *_pStreamDst)) return false;
	} while (0);
	do {
		CentralFileHeader::Fields &fields = pHdr->GetFields();
		XPackULong(fields.Crc32,			crc32num);
		XPackULong(fields.CompressedSize,	compressedSize);
		XPackULong(fields.UncompressedSize,	uncompressedSize);
	} while (0);
	return true;
}

bool Object_writer::Finish()
{
	if (_pStreamDst.IsNull()) return true;
	size_t offset = _pStreamDst->Tell();
	foreach (CentralFileHeaderList, ppHdr, _hdrList) {
		CentralFileHeader *pHdr = *ppHdr;
		if (!pHdr->Write(_sig, *_pStreamDst)) return false;
		//pHdr->Print();
	}
	unsigned long offsetOfCentralDirectory = static_cast<unsigned long>(offset);
	unsigned long sizeOfTheCentralDirectory =
							static_cast<unsigned long>(_pStreamDst->Tell() - offset);
	unsigned short nCentralFileHeaders = static_cast<unsigned short>(_hdrList.size());
	do {
		EndOfCentralDirectoryRecord rec;
		EndOfCentralDirectoryRecord::Fields &fields = rec.GetFields();
		XPackUShort(fields.NumberOfThisDisk,									0x0000);
		XPackUShort(fields.NumberOfTheDiskWithTheStartOfTheCentralDirectory,	0x0000);
		XPackUShort(fields.TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk,	nCentralFileHeaders);
		XPackUShort(fields.TotalNumberOfEntriesInTheCentralDirectory,			nCentralFileHeaders);
		XPackULong(fields.SizeOfTheCentralDirectory,							sizeOfTheCentralDirectory);
		XPackULong(fields.OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber,
															offsetOfCentralDirectory);
		XPackUShort(fields.ZIPFileCommentLength,								0x0000);
		if (!rec.Write(_sig, *_pStreamDst)) return false;
	} while (0);
	_pStreamDst->Close();
	_pStreamDst.reset(NULL);
	return !_sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// Gura interfaces of zip.writer
//-----------------------------------------------------------------------------
// zip.writer#add(stream:stream:r, filename?:string, compression?:symbol):map:reduce
Gura_DeclareMethod(writer, add)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "compression", VTYPE_symbol, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(writer, add)
{
	Object_writer *pSelf = Object_writer::GetSelfObj(args);
	String fileName;
	if (args.IsString(1)) {
		fileName = args.GetString(1);
	} else {
		const char *identifier = args.GetStream(0).GetIdentifier();
		if (identifier == NULL) {
			sig.SetError(ERR_ValueError, "stream doesn't have an identifier");
			return Value::Null;
		}
		Directory::SplitFileName(identifier, NULL, &fileName);
	}
	unsigned short compressionMethod = args.IsSymbol(2)?
						SymbolToCompressionMethod(args.GetSymbol(2)) :
						pSelf->GetCompressionMethod();
	if (compressionMethod == METHOD_Invalid) {
		sig.SetError(ERR_IOError, "invalid compression method");
		return Value::Null;
	}
	if (!pSelf->Add(sig, args.GetStream(0),
					fileName.c_str(), compressionMethod)) return Value::Null;
	return args.GetSelf();
}

// zip.writer#close():void
Gura_DeclareMethod(writer, close)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(writer, close)
{
	Object_writer *pSelf = Object_writer::GetSelfObj(args);
	if (!pSelf->Finish()) return Value::Null;
	return Value::Null;
}

// implementation of class zip.writer
Gura_ImplementUserClass(writer)
{
	Gura_AssignMethod(writer, add);
	Gura_AssignMethod(writer, close);
}

//-----------------------------------------------------------------------------
// Iterator_Entry implementation
//-----------------------------------------------------------------------------
Iterator_Entry::Iterator_Entry(Object_reader *pObjZipR) :
								Iterator(false), _pObjZipR(pObjZipR)
{
	_ppHdr = pObjZipR->GetHeaderList().begin();
}

Iterator_Entry::~Iterator_Entry()
{
}

bool Iterator_Entry::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_ppHdr == _pObjZipR->GetHeaderList().end()) return false;
	const CentralFileHeader *pHdr = *_ppHdr;
	const CentralFileHeader::Fields &fields = pHdr->GetFields();
	Stream *pStreamSrc = _pObjZipR->GetStreamSrc();
	if (pStreamSrc == NULL) return false;
	long offset = XUnpackLong(fields.RelativeOffsetOfLocalHeader);
	Stream *pStream = CreateStream(sig, pStreamSrc, pHdr);
	if (sig.IsSignalled()) return false;
	Object_stream *pObjStream = new Object_stream(env, pStream);
	value = Value(pObjStream);
	_ppHdr++;
	return true;
}

String Iterator_Entry::ToString(Signal sig) const
{
	String rtn;
	rtn += "<iterator:zip.entry>";
	return rtn;
}

void Iterator_Entry::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Gura module functions: zip
//-----------------------------------------------------------------------------
// zip.reader(stream:stream:r) {block?}
Gura_DeclareFunction(reader)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(reader));
}

Gura_ImplementFunction(reader)
{
	Stream &streamSrc = args.GetStream(0);
	AutoPtr<Object_reader> pObjZipR(
					new Object_reader(sig, Stream::Reference(&streamSrc)));
	if (!pObjZipR->ReadDirectory(env, sig)) return Value::Null;
	Value result(pObjZipR.release());
	return ReturnValue(env, sig, args, result);
}

// zip.writer(stream:stream:w, compression?:symbol) {block?}
Gura_DeclareFunction(writer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "compression", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(writer));
}

Gura_ImplementFunction(writer)
{
	Stream &streamDst = args.GetStream(0);
	unsigned short compressionMethod = args.IsSymbol(1)?
			SymbolToCompressionMethod(args.GetSymbol(1)) : METHOD_Deflate;
	if (compressionMethod == METHOD_Invalid) {
		sig.SetError(ERR_IOError, "invalid compression method");
		return Value::Null;
	}
	Object_writer *pObjZipW = new Object_writer(sig,
						Stream::Reference(&streamDst), compressionMethod);
	Value result(pObjZipW);
	return ReturnValue(env, sig, args, result);
}

// zip.test(stream:stream:r)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(test)
{
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(filename);
	Gura_RealizeUserSymbol(comment);
	Gura_RealizeUserSymbol(compression_method);
	Gura_RealizeUserSymbol(mtime);
	Gura_RealizeUserSymbol(crc32);
	Gura_RealizeUserSymbol(size);
	Gura_RealizeUserSymbol(compressed_size);
	Gura_RealizeUserSymbol(attributes);
	Gura_RealizeUserSymbol(store);
	Gura_RealizeUserSymbol(shrink);
	Gura_RealizeUserSymbol(factor1);
	Gura_RealizeUserSymbol(factor2);
	Gura_RealizeUserSymbol(factor3);
	Gura_RealizeUserSymbol(factor4);
	Gura_RealizeUserSymbol(implode);
	Gura_RealizeUserSymbol(deflate);
	Gura_RealizeUserSymbol(deflate64);
	Gura_RealizeUserSymbol(pkware);
	Gura_RealizeUserSymbol(bzip2);
	Gura_RealizeUserSymbol(lzma);
	Gura_RealizeUserSymbol(tersa);
	Gura_RealizeUserSymbol(lz77);
	Gura_RealizeUserSymbol(wavpack);
	Gura_RealizeUserSymbol(ppmd);
	// class realization
	Gura_RealizeUserClass(reader, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(writer, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(stat, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	Gura_AssignFunction(test);
	// registration of stream/directory factory
	DirectoryFactory::Register(new DirectoryFactory_ZIP());
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Object_stat implementation
//-----------------------------------------------------------------------------
Object_stat::~Object_stat()
{
}

Object *Object_stat::Clone() const
{
	return new Object_stat(*this);
}

bool Object_stat::DoPropDir(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoPropDir(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(filename));
	symbols.insert(Gura_UserSymbol(comment));
	symbols.insert(Gura_UserSymbol(mtime));
	symbols.insert(Gura_UserSymbol(crc32));
	symbols.insert(Gura_UserSymbol(compression_method));
	symbols.insert(Gura_UserSymbol(size));
	symbols.insert(Gura_UserSymbol(compressed_size));
	symbols.insert(Gura_UserSymbol(attributes));
	return true;
}

Value Object_stat::DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(filename))) {
		return Value(env, _hdr.GetFileName());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(comment))) {
		return Value(env, _hdr.GetFileComment());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mtime))) {
		return Value(env, _hdr.GetLastModDateTime());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(crc32))) {
		return Value(env, _hdr.GetCrc32());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(compression_method))) {
		return Value(static_cast<unsigned long>(_hdr.GetCompressionMethod()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(size))) {
		return Value(static_cast<unsigned long>(_hdr.GetUncompressedSize()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(compressed_size))) {
		return Value(static_cast<unsigned long>(_hdr.GetCompressedSize()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(attributes))) {
		return Value(static_cast<unsigned long>(_hdr.GetExternalFileAttributes()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_stat::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<zip.stat:";
	str += _hdr.GetFileName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stat
//-----------------------------------------------------------------------------
// implementation of class stat
Gura_ImplementUserClass(stat)
{
}

//-----------------------------------------------------------------------------
// Stream_reader implementation
//-----------------------------------------------------------------------------
Stream_reader::Stream_reader(Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream(sig, ATTR_Readable), _pStreamSrc(pStreamSrc), _hdr(hdr),
	_name(hdr.GetFileName()), _bytesUncompressed(hdr.GetUncompressedSize()),
	_bytesCompressed(hdr.GetCompressedSize()), _crc32Expected(hdr.GetCrc32()),
	_seekedFlag(false)
{
}

Stream_reader::~Stream_reader()
{
}

const char *Stream_reader::GetName() const
{
	return _name.c_str();
}

const char *Stream_reader::GetIdentifier() const
{
	return _name.c_str();
}

bool Stream_reader::GetAttribute(Attribute &attr)
{
	attr.atime = attr.ctime = attr.mtime = _hdr.GetLastModDateTime();
	attr.attr = 0, attr.attrMask = 0;
	return true;
}

bool Stream_reader::SetAttribute(const Attribute &attr)
{
	return false;
}

size_t Stream_reader::CheckCRC32(Signal sig, const void *buff, size_t bytesRead)
{
	if (_seekedFlag) return bytesRead;
	_crc32.Update(buff, bytesRead);
	if (bytesRead == 0 && _crc32Expected != _crc32.GetResult()) {
		sig.SetError(ERR_FormatError, "CRC error");
		return 0;
	}
	return bytesRead;
}

size_t Stream_reader::DoWrite(Signal sig, const void *buff, size_t len)
{
	return 0;
}

bool Stream_reader::DoFlush(Signal sig)
{
	return false;
}

bool Stream_reader::DoClose(Signal sig)
{
	_pStreamSrc.reset(NULL);
	return true;
}

size_t Stream_reader::DoGetSize()
{
	return _bytesUncompressed;
}

Object *Stream_reader::DoGetStatObj(Signal sig)
{
	return new Object_stat(_hdr);
}

//-----------------------------------------------------------------------------
// Stream_reader_Store implementation
// Compression method #0: stored (no compression)
//-----------------------------------------------------------------------------
Stream_reader_Store::Stream_reader_Store(Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream_reader(sig, pStreamSrc, hdr), _offsetTop(pStreamSrc->Tell())
{
}

Stream_reader_Store::~Stream_reader_Store()
{
}

bool Stream_reader_Store::Initialize(Signal sig)
{
	return true;
}

size_t Stream_reader_Store::DoRead(Signal sig, void *buff, size_t bytes)
{
	size_t bytesRest = _bytesUncompressed - (_pStreamSrc->Tell() - _offsetTop);
	if (bytes > bytesRest) bytes = bytesRest;
	size_t bytesRead = _pStreamSrc->Read(sig, buff, bytes);
	return CheckCRC32(sig, buff, bytesRead);
}

bool Stream_reader_Store::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	if (seekMode == SeekSet) {
		_seekedFlag = true;
		return _pStreamSrc->Seek(sig, static_cast<long>(_offsetTop + offset), seekMode);
	} else if (seekMode == SeekCur) {
		_seekedFlag = true;
		return _pStreamSrc->Seek(sig, offset, seekMode);
	}
	return false;
}

//-----------------------------------------------------------------------------
// Stream_reader_Deflate implementation
// Compression method #8: Deflated
//-----------------------------------------------------------------------------
Stream_reader_Deflate::Stream_reader_Deflate(Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
											Stream_reader(sig, pStreamSrc, hdr)
{
}

Stream_reader_Deflate::~Stream_reader_Deflate()
{
}

bool Stream_reader_Deflate::Initialize(Signal sig)
{
	_pStreamInflater.reset(new ZLib::Stream_Inflater(sig,
						Stream::Reference(_pStreamSrc.get()), _bytesCompressed));
	return _pStreamInflater->Initialize(sig, -MAX_WBITS);
}

size_t Stream_reader_Deflate::DoRead(Signal sig, void *buff, size_t bytes)
{
	size_t bytesRead = _pStreamInflater->Read(sig, buff, bytes);
	return CheckCRC32(sig, buff, bytesRead);
}

bool Stream_reader_Deflate::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	_seekedFlag = true;
	return _pStreamInflater->Seek(sig, offset, seekMode);
}

//-----------------------------------------------------------------------------
// Stream_reader_BZIP2 implementation
// Compression method #12: BZIP2
//-----------------------------------------------------------------------------
Stream_reader_BZIP2::Stream_reader_BZIP2(Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
											Stream_reader(sig, pStreamSrc, hdr)
{
}

Stream_reader_BZIP2::~Stream_reader_BZIP2()
{
}

bool Stream_reader_BZIP2::Initialize(Signal sig)
{
	_pStreamDecompressor.reset(new BZLib::Stream_Decompressor(sig,
						Stream::Reference(_pStreamSrc.get()), _bytesCompressed));
	int verbosity = 0, small = 0;
	return _pStreamDecompressor->Initialize(sig, verbosity, small);
}

size_t Stream_reader_BZIP2::DoRead(Signal sig, void *buff, size_t bytes)
{
	size_t bytesRead = _pStreamDecompressor->Read(sig, buff, bytes);
	return CheckCRC32(sig, buff, bytesRead);
}

bool Stream_reader_BZIP2::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	_seekedFlag = true;
	return _pStreamDecompressor->Seek(sig, offset, seekMode);
}

//-----------------------------------------------------------------------------
// Stream_reader_Deflate64 implementation
// Compression method #9: Enhanced Deflating using Deflate64(tm)
//-----------------------------------------------------------------------------
Stream_reader_Deflate64::Stream_reader_Deflate64(Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream_reader(sig, pStreamSrc, hdr)
{
}

Stream_reader_Deflate64::~Stream_reader_Deflate64()
{
}

bool Stream_reader_Deflate64::Initialize(Signal sig)
{
	sig.SetError(ERR_SystemError, "this compression method is not implemented yet");
	return false;
}

size_t Stream_reader_Deflate64::DoRead(Signal sig, void *buff, size_t bytes)
{
	return 0;
}

bool Stream_reader_Deflate64::DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	return false;
}

//-----------------------------------------------------------------------------
// Record_ZIP implementation
//-----------------------------------------------------------------------------
Record_ZIP::Record_ZIP(DirBuilder::Structure *pStructure, Record_ZIP *pParent,
								const char *name, bool containerFlag) :
	DirBuilder::Record(pStructure, pParent, name, containerFlag), _pHdr(NULL)
{
}

Record_ZIP::~Record_ZIP()
{
}

DirBuilder::Record *Record_ZIP::DoGenerateChild(const char *name, bool containerFlag)
{
	Record_ZIP *pRecord = new Record_ZIP(_pStructure, this, name, containerFlag);
	AddChild(pRecord);
	return pRecord;
}

Directory *Record_ZIP::DoGenerateDirectory(Directory *pParent, Directory::Type type)
{
	return new Directory_ZIP(Directory::Reference(pParent),
		GetName(), type, DirBuilder::Structure::Reference(_pStructure), this);
}

//-----------------------------------------------------------------------------
// Directory_ZIP implementation
//-----------------------------------------------------------------------------
Directory_ZIP::Directory_ZIP(Directory *pParent, const char *name, Type type,
						DirBuilder::Structure *pStructure, Record_ZIP *pRecord) :
	Directory(pParent, name, type, OAL::FileSeparator),
	_pStructure(pStructure), _pRecord(pRecord)
{
}

Directory_ZIP::~Directory_ZIP()
{
}

Directory *Directory_ZIP::DoNext(Environment &env, Signal sig)
{
	return _pRecord->Next(this);
}

Stream *Directory_ZIP::DoOpenStream(Environment &env, Signal sig,
								unsigned long attr, const char *encoding)
{
	AutoPtr<Stream> pStreamSrc;
	for (Directory *pDirectory = this; pDirectory != NULL;
											pDirectory = pDirectory->GetParent()) {
		if (pDirectory->IsBoundaryContainer()) {
			pStreamSrc.reset(pDirectory->GetParent()->
							OpenStream(env, sig, Stream::ATTR_Readable, NULL));
			if (sig.IsSignalled()) return NULL;
			break;
		}
	}
	const CentralFileHeader *pHdr = _pRecord->GetCentralFileHeader();
	ASSUME(env, pHdr != NULL);
	return CreateStream(sig, pStreamSrc.get(), pHdr);
}

Object *Directory_ZIP::DoGetStatObj(Signal sig)
{
	return new Object_stat(*_pRecord->GetCentralFileHeader());
}

//-----------------------------------------------------------------------------
// DirectoryFactory_ZIP implementation
//-----------------------------------------------------------------------------
bool DirectoryFactory_ZIP::IsResponsible(Environment &env, Signal sig,
						const Directory *pParent, const char *pathName)
{
	return pParent != NULL && !pParent->IsContainer() &&
			(EndsWith(pParent->GetName(), ".zip", true) ||
			 EndsWith(pParent->GetName(), ".gurc", true) ||
			 EndsWith(pParent->GetName(), ".gurcw", true));
}

Directory *DirectoryFactory_ZIP::DoOpenDirectory(Environment &env, Signal sig,
	Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode)
{
	Stream *pStream = pParent->OpenStream(env, sig, Stream::ATTR_Readable, NULL);
	if (sig.IsSignalled()) return NULL;
	if (!pStream->IsBwdSeekable()) {
		Stream *pStreamPrefetch = Stream::Prefetch(sig, pStream, true);
		if (sig.IsSignalled()) return NULL;
		pStream = pStreamPrefetch;
	}
	Value valStream(env, pStream);	// this works like std::auto_ptr
	AutoPtr<DirBuilder::Structure> pStructure(new DirBuilder::Structure());
	pStructure->SetRoot(new Record_ZIP(pStructure.get(), NULL, "", true));
	unsigned long offsetCentralDirectory = SeekCentralDirectory(sig, pStream);
	if (sig.IsSignalled()) return NULL;
	if (!pStream->Seek(sig, offsetCentralDirectory, Stream::SeekSet)) return NULL;
	unsigned long signature;
	while (ReadStream(sig, *pStream, &signature)) {
		//::printf("%08x\n", signature);
		if (signature == LocalFileHeader::Signature) {
			LocalFileHeader hdr;
			if (!hdr.Read(sig, *pStream)) return NULL;
			if (!hdr.SkipFileData(sig, *pStream)) return NULL;
		} else if (signature == ArchiveExtraDataRecord::Signature) {
			ArchiveExtraDataRecord record;
			if (!record.Read(sig, *pStream)) return NULL;
		} else if (signature == CentralFileHeader::Signature) {
			CentralFileHeader *pHdr = new CentralFileHeader();
			if (!pHdr->Read(sig, *pStream)) {
				delete pHdr;
				return NULL;
			}
			Record_ZIP *pRecord = dynamic_cast<Record_ZIP *>(
									pStructure->AddRecord(pHdr->GetFileName()));
			pRecord->SetCentralFileHeader(pHdr);
		} else if (signature == DigitalSignature::Signature) {
			DigitalSignature signature;
			if (!signature.Read(sig, *pStream)) return NULL;
		} else if (signature == Zip64EndOfCentralDirectory::Signature) {
			Zip64EndOfCentralDirectory dir;
			if (!dir.Read(sig, *pStream)) return NULL;
		} else if (signature == Zip64EndOfCentralDirectoryLocator::Signature) {
			Zip64EndOfCentralDirectoryLocator loc;
			if (!loc.Read(sig, *pStream)) return NULL;
		} else if (signature == EndOfCentralDirectoryRecord::Signature) {
			EndOfCentralDirectoryRecord record;
			if (!record.Read(sig, *pStream)) return NULL;
			break;
		} else {
			sig.SetError(ERR_FormatError, "unknown signature %08x", signature);
			return NULL;
		}
	}
	if (sig.IsSignalled()) return NULL;
	//pStream->Close();
	return pStructure->GenerateDirectory(sig, pParent, pPathName, notFoundMode);
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
unsigned short SymbolToCompressionMethod(const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_UserSymbol(store))) {
		return METHOD_Store;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(shrink))) {
		return METHOD_Shrink;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(factor1))) {
		return METHOD_Factor1;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(factor2))) {
		return METHOD_Factor2;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(factor3))) {
		return METHOD_Factor3;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(factor4))) {
		return METHOD_Factor4;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(implode))) {
		return METHOD_Implode;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(deflate))) {
		return METHOD_Deflate;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(deflate64))) {
		return METHOD_Deflate64;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(pkware))) {
		return METHOD_PKWARE;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(bzip2))) {
		return METHOD_BZIP2;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lzma))) {
		return METHOD_LZMA;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(tersa))) {
		return METHOD_TERSA;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lz77))) {
		return METHOD_LZ77;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(wavpack))) {
		return METHOD_WavPack;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ppmd))) {
		return METHOD_PPMd;
	} else {
		return METHOD_Invalid;
	}
}

unsigned short GetDosTime(const DateTime &dt)
{
	return (static_cast<unsigned short>(dt.GetHour()) << 11) |
			(static_cast<unsigned short>(dt.GetMin()) << 5) |
			(static_cast<unsigned short>(dt.GetSec() / 2) << 0);
}

unsigned short GetDosDate(const DateTime &dt)
{
	return (static_cast<unsigned short>(dt.GetYear() - 1980) << 9) |
			(static_cast<unsigned short>(dt.GetMonth()) << 5) |
			(static_cast<unsigned short>(dt.GetDay()) << 0);
}

DateTime MakeDateTimeFromDos(unsigned short dosDate, unsigned short dosTime)
{
	short year = static_cast<short>((dosDate >> 9) + 1980);
	char month = static_cast<char>((dosDate >> 5) & 0xf);
	char day = static_cast<char>((dosDate >> 0) & 0x1f);
	long sec = static_cast<long>((dosTime >> 11) * 3600 +
				((dosTime >> 5) & 0x3f) * 60 + ((dosTime >> 0) & 0x1f) * 2);
	return DateTime(year, month, day, sec, 0);
}

unsigned long SeekCentralDirectory(Signal sig, Stream *pStream)
{
	size_t bytesZIPFile = pStream->GetSize();
	if (bytesZIPFile == InvalidSize) {
		sig.SetError(ERR_IOError, "can't seek end of file");
		return 0;
	}
	unsigned long offsetCentralDirectory = 0;
	if (bytesZIPFile < EndOfCentralDirectoryRecord::MinSize) {
		sig.SetError(ERR_FormatError, "can't find central directory record");
		return 0;
	}
	size_t bytesBuff = 0;
	if (bytesZIPFile <= EndOfCentralDirectoryRecord::MaxSize) {
		bytesBuff = bytesZIPFile;
	} else {
		long offsetStart = static_cast<long>(bytesZIPFile -
									EndOfCentralDirectoryRecord::MaxSize);
		if (!pStream->Seek(sig, offsetStart, Stream::SeekSet)) {
			return 0;
		}
		bytesBuff = EndOfCentralDirectoryRecord::MaxSize;
	}
	OAL::Memory memory;
	char *buff = reinterpret_cast<char *>(memory.Allocate(bytesBuff));
	pStream->Read(sig, buff, bytesBuff);
	if (sig.IsSignalled()) return NULL;
	char *buffAnchor = NULL;
	for (size_t i = 0; i <= bytesBuff - EndOfCentralDirectoryRecord::MinSize; i++) {
		if (::memcmp(buff + i, "\x50\x4b\x05\x06", 4) == 0) {
			buffAnchor = buff + i;
		}
	}
	if (buffAnchor == NULL) {
		sig.SetError(ERR_FormatError, "can't find central directory record");
		return 0;
	}
	EndOfCentralDirectoryRecord record;
	::memcpy(&record, buffAnchor, EndOfCentralDirectoryRecord::MinSize);
	return XUnpackULong(record.GetFields().
			OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber);
}

Stream *CreateStream(Signal sig, Stream *pStreamSrc, const CentralFileHeader *pHdr)
{
	AutoPtr<Stream_reader> pStream;
	long offset = static_cast<long>(pHdr->GetRelativeOffsetOfLocalHeader());
	pStreamSrc->Seek(sig, offset, Stream::SeekSet);
	if (sig.IsSignalled()) return NULL;
	do {
		unsigned long signature;
		if (!ReadStream(sig, *pStreamSrc, &signature)) return NULL;
		if (signature != LocalFileHeader::Signature) {
			sig.SetError(ERR_FormatError, "invalid ZIP format");
			return NULL;
		}
		LocalFileHeader hdr;
		if (!hdr.Read(sig, *pStreamSrc)) return NULL;
	} while (0);
	//const char *name = pHdr->GetFileName();
	unsigned short compressionMethod = pHdr->GetCompressionMethod();
	//size_t bytesUncompressed = pHdr->GetUncompressedSize();
	//size_t bytesCompressed = pHdr->GetCompressedSize();
	//unsigned long crc32Expected = pHdr->GetCrc32();
	if (compressionMethod == METHOD_Store) {
		pStream.reset(new Stream_reader_Store(sig, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_Shrink) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor1) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor2) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor3) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor4) {
		// unsupported
	} else if (compressionMethod == METHOD_Implode) {
		// unsupported
	} else if (compressionMethod == METHOD_Factor1) {
		// unsupported
	} else if (compressionMethod == METHOD_Deflate) {
		pStream.reset(new Stream_reader_Deflate(sig, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_Deflate64) {
		pStream.reset(new Stream_reader_Deflate64(sig, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_PKWARE) {
		// unsupported
	} else if (compressionMethod == METHOD_BZIP2) {
		pStream.reset(new Stream_reader_BZIP2(sig, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_LZMA) {
		// unsupported
	} else if (compressionMethod == METHOD_TERSA) {
		// unsupported
	} else if (compressionMethod == METHOD_LZ77) {
		// unsupported
	} else if (compressionMethod == METHOD_WavPack) {
		// unsupported
	} else if (compressionMethod == METHOD_PPMd) {
		// unsupported
	}
	if (pStream.IsNull()) {
		sig.SetError(ERR_FormatError,
				"unsupported compression method %d", compressionMethod);
		return NULL;
	}
	if (!pStream->Initialize(sig)) return NULL;
	return pStream.release();
}

bool SkipStream(Signal sig, Stream &stream, size_t bytes)
{
	return stream.Seek(sig, static_cast<long>(bytes), Stream::SeekCur);
}

bool ReadStream(Signal sig, Stream &stream, void *buff, size_t bytes, size_t offset)
{
	if (bytes == 0) return true;
	size_t bytesRead = stream.Read(sig,
						reinterpret_cast<char *>(buff) + offset, bytes);
	if (sig.IsSignalled()) return false;
	if (bytesRead < bytes) {
		sig.SetError(ERR_FormatError, "invalid ZIP format");
		return false;
	}
	return true;
}

bool ReadStream(Signal sig, Stream &stream, unsigned long *pSignature)
{
	struct {
		XPackedULong_LE(Signature);
	} buff;
	if (!ReadStream(sig, stream, &buff, 4)) return false;
	*pSignature = XUnpackULong(buff.Signature);
	return true;
}

bool ReadStream(Signal sig, Stream &stream, Binary &binary, size_t bytes)
{
	if (bytes == 0) {
		binary = Binary();
		return true;
	}
	char *buff = new char[bytes];
	if (!ReadStream(sig, stream, buff, bytes)) {
		delete[] buff;
		return false;
	}
	binary = Binary(buff, bytes);
	delete[] buff;
	return true;
}

bool WriteStream(Signal sig, Stream &stream, void *buff, size_t bytes)
{
	stream.Write(sig, buff, bytes);
	return !sig.IsSignalled();
}

bool WriteStream(Signal sig, Stream &stream, Binary &binary)
{
	stream.Write(sig, binary.data(), binary.size());
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// structures
//-----------------------------------------------------------------------------
bool LocalFileHeader::SkipOver(Signal sig, Stream &stream)
{
	if (!ReadStream(sig, stream, &_fields, 30 - 4, 4)) return false;
	if (IsExistDataDescriptor()) {
		sig.SetError(ERR_FormatError,
			"failed to skip local file header because it has data descriptor");
		return false;
	}
	size_t bytesToSkip = 0;
	bytesToSkip += XUnpackUShort(_fields.FileNameLength);
	bytesToSkip += XUnpackUShort(_fields.ExtraFieldLength);
	bytesToSkip += XUnpackULong(_fields.CompressedSize);
	if (!SkipStream(sig, stream, bytesToSkip)) return false;
	return true;
}

Gura_EndModule(zip, zip)

Gura_RegisterModule(zip)
