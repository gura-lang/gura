//-----------------------------------------------------------------------------
// Gura zip module
// specification: http://www.pkware.com/documents/casestudies/APPNOTE.TXT
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(zip)

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

String Object_reader::ToString(bool exprFlag)
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
		Stream *pStreamPrefetch = Stream::Prefetch(env, sig, _pStreamSrc.release(), true);
		if (sig.IsSignalled()) return false;
		_pStreamSrc.reset(pStreamPrefetch);
	}
	ULong offsetCentralDirectory = SeekCentralDirectory(sig, _pStreamSrc.get());
	if (sig.IsSignalled()) return false;
	if (!_pStreamSrc->Seek(sig, offsetCentralDirectory, Stream::SeekSet)) return false;
	ULong signature;
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
// zip.reader#entry(name:string) {block?}
Gura_DeclareMethod(reader, entry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "name", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(reader, entry)
{
	Object_reader *pThis = Object_reader::GetThisObj(args);
	Stream *pStreamSrc = pThis->GetStreamSrc();
	if (pStreamSrc == NULL) {
		sig.SetError(ERR_ValueError, "zip object is not readable");
		return Value::Null;
	}
	AutoPtr<Object_stream> pObjStream;
	const char *name = args.GetString(0);
	foreach (CentralFileHeaderList, ppHdr, pThis->GetHeaderList()) {
		const CentralFileHeader *pHdr = *ppHdr;
		const CentralFileHeader::Fields &fields = pHdr->GetFields();
		if (IsMatchedName(pHdr->GetFileName(), name)) {
			long offset = Gura_UnpackLong(fields.RelativeOffsetOfLocalHeader);
			Stream *pStream = CreateStream(env, sig, pStreamSrc, pHdr);
			if (sig.IsSignalled()) return Value::Null;
			pObjStream.reset(new Object_stream(env, pStream));
			break;
		}
	}
	if (pObjStream.IsNull()) {
		sig.SetError(ERR_NameError, "entry not found");
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(pObjStream.release()));
}

// zip.reader#entries() {block?}
Gura_DeclareMethod(reader, entries)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(reader, entries)
{
	Object_reader *pThis = Object_reader::GetThisObj(args);
	if (pThis->GetStreamSrc() == NULL) {
		sig.SetError(ERR_ValueError, "zip object is not readable");
		return Value::Null;
	}
	Iterator *pIterator = new Iterator_Entry(Object_reader::Reference(pThis));
	return ReturnIterator(env, sig, args, pIterator);
}

// implementation of class zip.reader
Gura_ImplementUserClass(reader)
{
	Gura_AssignMethod(reader, entry);
	Gura_AssignMethod(reader, entries);
}

//-----------------------------------------------------------------------------
// Implementation of Object_writer
//-----------------------------------------------------------------------------
Object_writer::Object_writer(Signal sig, Stream *pStreamDst,
											UShort compressionMethod) :
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

String Object_writer::ToString(bool exprFlag)
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

bool Object_writer::Add(Environment &env, Signal sig, Stream &streamSrc,
					const char *fileName, UShort compressionMethod)
{
	if (_pStreamDst.IsNull()) {
		sig.SetError(ERR_IOError, "invalid accesss to writer");
		return false;
	}
	const int memLevel = 8;
	CentralFileHeader *pHdr = new CentralFileHeader();
	_hdrList.push_back(pHdr);
	UShort version = (0 << 8) | (2 * 10 + 0);	// MS-DOS, 2.0
	UShort generalPurposeBitFlag = (1 << 3);	// ExistDataDescriptor
	DateTime dt;
	Stream::Attribute attr;
	if (streamSrc.GetAttribute(attr)) {
		dt = attr.mtime;
	} else {
		dt = OAL::GetCurDateTime(false);
	}
	UShort lastModFileTime = GetDosTime(dt);
	UShort lastModFileDate = GetDosDate(dt);
	ULong compressedSize = 0;
	ULong uncompressedSize = 0;
	ULong externalFileAttributes = (1 << 5);
	ULong relativeOffsetOfLocalHeader =
							static_cast<ULong>(_pStreamDst->Tell());
	do {
		CentralFileHeader::Fields &fields = pHdr->GetFields();
		Gura_PackUShort(fields.VersionMadeBy,				version);
		Gura_PackUShort(fields.VersionNeededToExtract,		version);
		Gura_PackUShort(fields.GeneralPurposeBitFlag,		generalPurposeBitFlag);
		Gura_PackUShort(fields.CompressionMethod,			compressionMethod);
		Gura_PackUShort(fields.LastModFileTime,				lastModFileTime);
		Gura_PackUShort(fields.LastModFileDate,				lastModFileDate);
		Gura_PackULong(fields.Crc32,						0x00000000);
		Gura_PackULong(fields.CompressedSize,				compressedSize);
		Gura_PackULong(fields.UncompressedSize,				uncompressedSize);
		Gura_PackUShort(fields.FileNameLength,				0x0000);
		Gura_PackUShort(fields.ExtraFieldLength,			0x0000);
		Gura_PackUShort(fields.FileCommentLength,			0x0000);
		Gura_PackUShort(fields.DiskNumberStart,				0x0000);
		Gura_PackUShort(fields.InternalFileAttributes,		0x0000);
		Gura_PackULong(fields.ExternalFileAttributes,		externalFileAttributes);
		Gura_PackULong(fields.RelativeOffsetOfLocalHeader,	relativeOffsetOfLocalHeader);
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
			new ZLib::Stream_Deflater(env, sig, Stream::Reference(_pStreamDst.get())));
		if (!pStreamDeflater->Initialize(sig, Z_DEFAULT_COMPRESSION,
					-MAX_WBITS, memLevel, Z_DEFAULT_STRATEGY)) return false;
		pStreamOut.reset(pStreamDeflater.release());
	} else if (compressionMethod == METHOD_Deflate64) {
		// unsupported
	} else if (compressionMethod == METHOD_PKWARE) {
		// unsupported
	} else if (compressionMethod == METHOD_BZIP2) {
		AutoPtr<BZLib::Stream_Compressor> pStreamCompressor(
			new BZLib::Stream_Compressor(env, sig, Stream::Reference(_pStreamDst.get())));
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
	AutoPtr<Memory> pMemory(new MemoryHeap(32768));
	void *buff = pMemory->GetPointer();
	for (;;) {
		size_t bytesRead = streamSrc.Read(sig, buff, pMemory->GetSize());
		if (sig.IsSignalled()) break;
		if (bytesRead == 0) break;
		crc32.Update(buff, bytesRead);
		pStreamOut->Write(sig, buff, bytesRead);
		if (sig.IsSignalled()) break;
	}
	pStreamOut->Flush(sig);
	if (sig.IsSignalled()) return false;
	ULong crc32num = crc32.GetResult();
	compressedSize = static_cast<ULong>(_pStreamDst->Tell() - offsetDst);
	uncompressedSize = static_cast<ULong>(streamSrc.Tell() - offsetSrc);
	do {
		DataDescriptor desc;
		DataDescriptor::Fields &fields = desc.GetFields();
		Gura_PackULong(fields.Crc32,			crc32num);
		Gura_PackULong(fields.CompressedSize,	compressedSize);
		Gura_PackULong(fields.UncompressedSize,	uncompressedSize);
		if (!desc.Write(sig, *_pStreamDst)) return false;
	} while (0);
	do {
		CentralFileHeader::Fields &fields = pHdr->GetFields();
		Gura_PackULong(fields.Crc32,			crc32num);
		Gura_PackULong(fields.CompressedSize,	compressedSize);
		Gura_PackULong(fields.UncompressedSize,	uncompressedSize);
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
	ULong offsetOfCentralDirectory = static_cast<ULong>(offset);
	ULong sizeOfTheCentralDirectory =
							static_cast<ULong>(_pStreamDst->Tell() - offset);
	UShort nCentralFileHeaders = static_cast<UShort>(_hdrList.size());
	do {
		EndOfCentralDirectoryRecord rec;
		EndOfCentralDirectoryRecord::Fields &fields = rec.GetFields();
		Gura_PackUShort(fields.NumberOfThisDisk,									0x0000);
		Gura_PackUShort(fields.NumberOfTheDiskWithTheStartOfTheCentralDirectory,	0x0000);
		Gura_PackUShort(fields.TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk,	nCentralFileHeaders);
		Gura_PackUShort(fields.TotalNumberOfEntriesInTheCentralDirectory,			nCentralFileHeaders);
		Gura_PackULong(fields.SizeOfTheCentralDirectory,							sizeOfTheCentralDirectory);
		Gura_PackULong(fields.OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber,
															offsetOfCentralDirectory);
		Gura_PackUShort(fields.ZIPFileCommentLength,								0x0000);
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
	Object_writer *pThis = Object_writer::GetThisObj(args);
	String fileName;
	if (args.Is_string(1)) {
		fileName = args.GetString(1);
	} else {
		const char *identifier = args.GetStream(0).GetIdentifier();
		if (identifier == NULL) {
			sig.SetError(ERR_ValueError, "stream doesn't have an identifier");
			return Value::Null;
		}
		PathManager::SplitFileName(identifier, NULL, &fileName);
	}
	UShort compressionMethod = args.Is_symbol(2)?
						SymbolToCompressionMethod(args.GetSymbol(2)) :
						pThis->GetCompressionMethod();
	if (compressionMethod == METHOD_Invalid) {
		sig.SetError(ERR_IOError, "invalid compression method");
		return Value::Null;
	}
	if (!pThis->Add(env, sig, args.GetStream(0),
					fileName.c_str(), compressionMethod)) return Value::Null;
	return args.GetThis();
}

// zip.writer#close():void
Gura_DeclareMethod(writer, close)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(writer, close)
{
	Object_writer *pThis = Object_writer::GetThisObj(args);
	if (!pThis->Finish()) return Value::Null;
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

Iterator *Iterator_Entry::GetSource()
{
	return NULL;
}

bool Iterator_Entry::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_ppHdr == _pObjZipR->GetHeaderList().end()) return false;
	const CentralFileHeader *pHdr = *_ppHdr;
	const CentralFileHeader::Fields &fields = pHdr->GetFields();
	Stream *pStreamSrc = _pObjZipR->GetStreamSrc();
	if (pStreamSrc == NULL) return false;
	long offset = Gura_UnpackLong(fields.RelativeOffsetOfLocalHeader);
	Stream *pStream = CreateStream(env, sig, pStreamSrc, pHdr);
	if (sig.IsSignalled()) return false;
	Object_stream *pObjStream = new Object_stream(env, pStream);
	value = Value(pObjStream);
	_ppHdr++;
	return true;
}

String Iterator_Entry::ToString() const
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
	AutoPtr<Object_reader> pObjZipR(new Object_reader(sig, streamSrc.Reference()));
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
	UShort compressionMethod = args.Is_symbol(1)?
			SymbolToCompressionMethod(args.GetSymbol(1)) : METHOD_Deflate;
	if (compressionMethod == METHOD_Invalid) {
		sig.SetError(ERR_IOError, "invalid compression method");
		return Value::Null;
	}
	Object_writer *pObjZipW = new Object_writer(sig, streamDst.Reference(), compressionMethod);
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
	PathManager::Register(env, new PathManager_ZIP());
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

bool Object_stat::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
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

Value Object_stat::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
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
		return Value(static_cast<ULong>(_hdr.GetCompressionMethod()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(size))) {
		return Value(static_cast<ULong>(_hdr.GetUncompressedSize()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(compressed_size))) {
		return Value(static_cast<ULong>(_hdr.GetCompressedSize()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(attributes))) {
		return Value(static_cast<ULong>(_hdr.GetExternalFileAttributes()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_stat::ToString(bool exprFlag)
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
Stream_reader::Stream_reader(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream(env, sig, ATTR_Readable), _pStreamSrc(pStreamSrc), _hdr(hdr),
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
	return Stream::DoClose(sig);
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
Stream_reader_Store::Stream_reader_Store(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream_reader(env, sig, pStreamSrc, hdr), _offsetTop(pStreamSrc->Tell())
{
}

Stream_reader_Store::~Stream_reader_Store()
{
}

bool Stream_reader_Store::Initialize(Environment &env, Signal sig)
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
Stream_reader_Deflate::Stream_reader_Deflate(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
											Stream_reader(env, sig, pStreamSrc, hdr)
{
}

Stream_reader_Deflate::~Stream_reader_Deflate()
{
}

bool Stream_reader_Deflate::Initialize(Environment &env, Signal sig)
{
	_pStreamInflater.reset(new ZLib::Stream_Inflater(env, sig,
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
Stream_reader_BZIP2::Stream_reader_BZIP2(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
											Stream_reader(env, sig, pStreamSrc, hdr)
{
}

Stream_reader_BZIP2::~Stream_reader_BZIP2()
{
}

bool Stream_reader_BZIP2::Initialize(Environment &env, Signal sig)
{
	_pStreamDecompressor.reset(new BZLib::Stream_Decompressor(env, sig,
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
Stream_reader_Deflate64::Stream_reader_Deflate64(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream_reader(env, sig, pStreamSrc, hdr)
{
}

Stream_reader_Deflate64::~Stream_reader_Deflate64()
{
}

bool Stream_reader_Deflate64::Initialize(Environment &env, Signal sig)
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

Stream *Directory_ZIP::DoOpenStream(Environment &env, Signal sig, ULong attr)
{
	AutoPtr<Stream> pStreamSrc;
	for (Directory *pDirectory = this; pDirectory != NULL;
											pDirectory = pDirectory->GetParent()) {
		if (pDirectory->IsBoundaryContainer()) {
			pStreamSrc.reset(pDirectory->GetParent()->
							DoOpenStream(env, sig, Stream::ATTR_Readable));
			if (sig.IsSignalled()) return NULL;
			break;
		}
	}
	const CentralFileHeader *pHdr = _pRecord->GetCentralFileHeader();
	GURA_ASSUME(env, pHdr != NULL);
	return CreateStream(env, sig, pStreamSrc.get(), pHdr);
}

Object *Directory_ZIP::DoGetStatObj(Signal sig)
{
	return new Object_stat(*_pRecord->GetCentralFileHeader());
}

//-----------------------------------------------------------------------------
// PathManager_ZIP implementation
//-----------------------------------------------------------------------------
bool PathManager_ZIP::IsResponsible(Environment &env, Signal sig,
						const Directory *pParent, const char *pathName)
{
	return pParent != NULL && !pParent->IsContainer() &&
			(EndsWith(pParent->GetName(), ".zip", true) ||
			 EndsWith(pParent->GetName(), ".gurc", true) ||
			 EndsWith(pParent->GetName(), ".gurcw", true));
}

Directory *PathManager_ZIP::DoOpenDirectory(Environment &env, Signal sig,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	AutoPtr<Stream> pStreamSrc(pParent->DoOpenStream(env, sig, Stream::ATTR_Readable));
	if (sig.IsSignalled()) return NULL;
	return CreateDirectory(env, sig,
					pStreamSrc.get(), pParent, pPathName, notFoundMode);
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
UShort SymbolToCompressionMethod(const Symbol *pSymbol)
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

UShort GetDosTime(const DateTime &dt)
{
	return (static_cast<UShort>(dt.GetHour()) << 11) |
			(static_cast<UShort>(dt.GetMin()) << 5) |
			(static_cast<UShort>(dt.GetSec() / 2) << 0);
}

UShort GetDosDate(const DateTime &dt)
{
	return (static_cast<UShort>(dt.GetYear() - 1980) << 9) |
			(static_cast<UShort>(dt.GetMonth()) << 5) |
			(static_cast<UShort>(dt.GetDay()) << 0);
}

DateTime MakeDateTimeFromDos(UShort dosDate, UShort dosTime)
{
	short year = static_cast<short>((dosDate >> 9) + 1980);
	char month = static_cast<char>((dosDate >> 5) & 0xf);
	char day = static_cast<char>((dosDate >> 0) & 0x1f);
	long sec = static_cast<long>((dosTime >> 11) * 3600 +
				((dosTime >> 5) & 0x3f) * 60 + ((dosTime >> 0) & 0x1f) * 2);
	return DateTime(year, month, day, sec, 0);
}

bool IsMatchedName(const char *name1, const char *name2)
{
	const char *p1 = name1, *p2 = name2;
	for ( ; ; p1++, p2++) {
		char ch1 = *p1, ch2 = *p2;
		if (IsFileSeparator(ch1) && IsFileSeparator(ch2)) {
			// nothing to do
		} else if (ch1 != ch2) {
			return false;
		} else if (ch1 == '\0') {
			break;
		}
	}
	return true;
}

ULong SeekCentralDirectory(Signal sig, Stream *pStream)
{
	size_t bytesZIPFile = pStream->GetSize();
	if (bytesZIPFile == InvalidSize) {
		sig.SetError(ERR_IOError, "can't seek end of file");
		return 0;
	}
	ULong offsetCentralDirectory = 0;
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
	AutoPtr<Memory> pMemory(new MemoryHeap(bytesBuff));
	char *buff = reinterpret_cast<char *>(pMemory->GetPointer());
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
	return Gura_UnpackULong(record.GetFields().
			OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber);
}

Directory *CreateDirectory(Environment &env, Signal sig, Stream *pStreamSrc,
	Directory *pParent, const char **pPathName, PathManager::NotFoundMode notFoundMode)
{
	if (!pStreamSrc->IsBwdSeekable()) {
		Stream *pStreamPrefetch = Stream::Prefetch(env, sig, pStreamSrc, true);
		if (sig.IsSignalled()) return NULL;
		pStreamSrc = pStreamPrefetch;
	}
	AutoPtr<DirBuilder::Structure> pStructure(new DirBuilder::Structure());
	pStructure->SetRoot(new Record_ZIP(pStructure.get(), NULL, "", true));
	ULong offsetCentralDirectory = SeekCentralDirectory(sig, pStreamSrc);
	if (sig.IsSignalled()) return NULL;
	if (!pStreamSrc->Seek(sig, offsetCentralDirectory, Stream::SeekSet)) return NULL;
	ULong signature;
	while (ReadStream(sig, *pStreamSrc, &signature)) {
		//::printf("%08x\n", signature);
		if (signature == LocalFileHeader::Signature) {
			LocalFileHeader hdr;
			if (!hdr.Read(sig, *pStreamSrc)) return NULL;
			if (!hdr.SkipFileData(sig, *pStreamSrc)) return NULL;
		} else if (signature == ArchiveExtraDataRecord::Signature) {
			ArchiveExtraDataRecord record;
			if (!record.Read(sig, *pStreamSrc)) return NULL;
		} else if (signature == CentralFileHeader::Signature) {
			CentralFileHeader *pHdr = new CentralFileHeader();
			if (!pHdr->Read(sig, *pStreamSrc)) {
				delete pHdr;
				return NULL;
			}
			Record_ZIP *pRecord = dynamic_cast<Record_ZIP *>(
									pStructure->AddRecord(pHdr->GetFileName()));
			pRecord->SetCentralFileHeader(pHdr);
		} else if (signature == DigitalSignature::Signature) {
			DigitalSignature signature;
			if (!signature.Read(sig, *pStreamSrc)) return NULL;
		} else if (signature == Zip64EndOfCentralDirectory::Signature) {
			Zip64EndOfCentralDirectory dir;
			if (!dir.Read(sig, *pStreamSrc)) return NULL;
		} else if (signature == Zip64EndOfCentralDirectoryLocator::Signature) {
			Zip64EndOfCentralDirectoryLocator loc;
			if (!loc.Read(sig, *pStreamSrc)) return NULL;
		} else if (signature == EndOfCentralDirectoryRecord::Signature) {
			EndOfCentralDirectoryRecord record;
			if (!record.Read(sig, *pStreamSrc)) return NULL;
			break;
		} else {
			sig.SetError(ERR_FormatError, "unknown signature %08x", signature);
			return NULL;
		}
	}
	if (sig.IsSignalled()) return NULL;
	//pStreamSrc->Close();
	return pStructure->GenerateDirectory(sig, pParent, pPathName, notFoundMode);
}

Stream *CreateStream(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader *pHdr)
{
	AutoPtr<Stream_reader> pStream;
	long offset = static_cast<long>(pHdr->GetRelativeOffsetOfLocalHeader());
	pStreamSrc->Seek(sig, offset, Stream::SeekSet);
	if (sig.IsSignalled()) return NULL;
	do {
		ULong signature;
		if (!ReadStream(sig, *pStreamSrc, &signature)) return NULL;
		if (signature != LocalFileHeader::Signature) {
			sig.SetError(ERR_FormatError, "invalid ZIP format");
			return NULL;
		}
		LocalFileHeader hdr;
		if (!hdr.Read(sig, *pStreamSrc)) return NULL;
	} while (0);
	//const char *name = pHdr->GetFileName();
	UShort compressionMethod = pHdr->GetCompressionMethod();
	//size_t bytesUncompressed = pHdr->GetUncompressedSize();
	//size_t bytesCompressed = pHdr->GetCompressedSize();
	//ULong crc32Expected = pHdr->GetCrc32();
	if (compressionMethod == METHOD_Store) {
		pStream.reset(new Stream_reader_Store(env, sig, Stream::Reference(pStreamSrc), *pHdr));
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
		pStream.reset(new Stream_reader_Deflate(env, sig, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_Deflate64) {
		pStream.reset(new Stream_reader_Deflate64(env, sig, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_PKWARE) {
		// unsupported
	} else if (compressionMethod == METHOD_BZIP2) {
		pStream.reset(new Stream_reader_BZIP2(env, sig, Stream::Reference(pStreamSrc), *pHdr));
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
	if (!pStream->Initialize(env, sig)) return NULL;
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

bool ReadStream(Signal sig, Stream &stream, ULong *pSignature)
{
	struct {
		Gura_PackedULong_LE(Signature);
	} buff;
	if (!ReadStream(sig, stream, &buff, 4)) return false;
	*pSignature = Gura_UnpackULong(buff.Signature);
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
	bytesToSkip += Gura_UnpackUShort(_fields.FileNameLength);
	bytesToSkip += Gura_UnpackUShort(_fields.ExtraFieldLength);
	bytesToSkip += Gura_UnpackULong(_fields.CompressedSize);
	if (!SkipStream(sig, stream, bytesToSkip)) return false;
	return true;
}

Gura_EndModuleBody(zip, zip)

Gura_RegisterModule(zip)
