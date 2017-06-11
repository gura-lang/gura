//-----------------------------------------------------------------------------
// Gura module: zip
// specification: http://www.pkware.com/documents/casestudies/APPNOTE.TXT
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(zip)

//-----------------------------------------------------------------------------
// Implementation of Object_reader
//-----------------------------------------------------------------------------
Object_reader::Object_reader(Signal &sig, Stream *pStreamSrc) :
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
	return nullptr;
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

bool Object_reader::ReadDirectory(Environment &env)
{
	Signal &sig = env.GetSignal();
	if (!_pStreamSrc->IsBwdSeekable()) {
		Stream *pStreamPrefetch = Stream::Prefetch(env, _pStreamSrc.release(), true);
		if (sig.IsSignalled()) return false;
		_pStreamSrc.reset(pStreamPrefetch);
	}
	UInt32 offsetCentralDirectory = SeekCentralDirectory(sig, _pStreamSrc.get());
	if (sig.IsSignalled()) return false;
	if (!_pStreamSrc->Seek(sig, offsetCentralDirectory, Stream::SeekSet)) return false;
	UInt32 signature;
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "name", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Seeks entry in the zip file that matches the specified name\n"
		"and returns a `stream` instance associated with the entry.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("s", "stream"));
}

Gura_ImplementMethod(reader, entry)
{
	Signal &sig = env.GetSignal();
	Object_reader *pThis = Object_reader::GetObjectThis(arg);
	Stream *pStreamSrc = pThis->GetStreamSrc();
	if (pStreamSrc == nullptr) {
		sig.SetError(ERR_ValueError, "zip object is not readable");
		return Value::Nil;
	}
	AutoPtr<Object_stream> pObjStream;
	const char *name = arg.GetString(0);
	foreach (CentralFileHeaderList, ppHdr, pThis->GetHeaderList()) {
		const CentralFileHeader *pHdr = *ppHdr;
		const CentralFileHeader::Fields &fields = pHdr->GetFields();
		if (IsMatchedName(pHdr->GetFileName(), name)) {
			long offset = Gura_UnpackInt32(fields.RelativeOffsetOfLocalHeader);
			Stream *pStream = CreateStream(env, pStreamSrc, pHdr);
			if (sig.IsSignalled()) return Value::Nil;
			pObjStream.reset(new Object_stream(env, pStream));
			break;
		}
	}
	if (pObjStream.IsNull()) {
		sig.SetError(ERR_NameError, "entry not found");
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(pObjStream.release()));
}

// zip.reader#entries() {block?}
Gura_DeclareMethod(reader, entries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `iterator` instance that returns `stream` instances\n"
		"associated with each entry in the ZIP file.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(reader, entries)
{
	Signal &sig = env.GetSignal();
	Object_reader *pThis = Object_reader::GetObjectThis(arg);
	if (pThis->GetStreamSrc() == nullptr) {
		sig.SetError(ERR_ValueError, "zip object is not readable");
		return Value::Nil;
	}
	Iterator *pIterator = new Iterator_Entry(Object_reader::Reference(pThis));
	return ReturnIterator(env, arg, pIterator);
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
Object_writer::Object_writer(Signal &sig, Stream *pStreamDst,
											UInt16 compressionMethod) :
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
	return nullptr;
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

bool Object_writer::Add(Environment &env, Stream &streamSrc,
					const char *fileName, UInt16 compressionMethod)
{
	Signal &sig = env.GetSignal();
	if (_pStreamDst.IsNull()) {
		sig.SetError(ERR_IOError, "invalid accesss to writer");
		return false;
	}
	const int memLevel = 8;
	CentralFileHeader *pHdr = new CentralFileHeader();
	_hdrList.push_back(pHdr);
	UInt16 version = (0 << 8) | (2 * 10 + 0);	// MS-DOS, 2.0
	UInt16 generalPurposeBitFlag = (1 << 3);	// ExistDataDescriptor
	DateTime dt;
	Stream::Attribute attr;
	if (streamSrc.GetAttribute(attr)) {
		dt = attr.mtime;
	} else {
		dt = OAL::GetCurDateTime(false);
	}
	UInt16 lastModFileTime = GetDosTime(dt);
	UInt16 lastModFileDate = GetDosDate(dt);
	UInt32 compressedSize = 0;
	UInt32 uncompressedSize = 0;
	UInt32 externalFileAttributes = (1 << 5);
	UInt32 relativeOffsetOfLocalHeader =
							static_cast<UInt32>(_pStreamDst->Tell());
	do {
		CentralFileHeader::Fields &fields = pHdr->GetFields();
		Gura_PackUInt16(fields.VersionMadeBy,				version);
		Gura_PackUInt16(fields.VersionNeededToExtract,		version);
		Gura_PackUInt16(fields.GeneralPurposeBitFlag,		generalPurposeBitFlag);
		Gura_PackUInt16(fields.CompressionMethod,			compressionMethod);
		Gura_PackUInt16(fields.LastModFileTime,				lastModFileTime);
		Gura_PackUInt16(fields.LastModFileDate,				lastModFileDate);
		Gura_PackUInt32(fields.Crc32,						0x00000000);
		Gura_PackUInt32(fields.CompressedSize,				compressedSize);
		Gura_PackUInt32(fields.UncompressedSize,			uncompressedSize);
		Gura_PackUInt16(fields.FileNameLength,				0x0000);
		Gura_PackUInt16(fields.ExtraFieldLength,			0x0000);
		Gura_PackUInt16(fields.FileCommentLength,			0x0000);
		Gura_PackUInt16(fields.DiskNumberStart,				0x0000);
		Gura_PackUInt16(fields.InternalFileAttributes,		0x0000);
		Gura_PackUInt32(fields.ExternalFileAttributes,		externalFileAttributes);
		Gura_PackUInt32(fields.RelativeOffsetOfLocalHeader,	relativeOffsetOfLocalHeader);
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
			new ZLib::Stream_Deflater(env, Stream::Reference(_pStreamDst.get())));
		if (!pStreamDeflater->Initialize(sig, Z_DEFAULT_COMPRESSION,
					-MAX_WBITS, memLevel, Z_DEFAULT_STRATEGY)) return false;
		pStreamOut.reset(pStreamDeflater.release());
	} else if (compressionMethod == METHOD_Deflate64) {
		// unsupported
	} else if (compressionMethod == METHOD_PKWARE) {
		// unsupported
	} else if (compressionMethod == METHOD_BZIP2) {
		AutoPtr<BZLib::Stream_Compressor> pStreamCompressor(
			new BZLib::Stream_Compressor(env, Stream::Reference(_pStreamDst.get())));
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
	UInt32 crc32num = crc32.GetResult();
	compressedSize = static_cast<UInt32>(_pStreamDst->Tell() - offsetDst);
	uncompressedSize = static_cast<UInt32>(streamSrc.Tell() - offsetSrc);
	do {
		DataDescriptor desc;
		DataDescriptor::Fields &fields = desc.GetFields();
		Gura_PackUInt32(fields.Crc32,			crc32num);
		Gura_PackUInt32(fields.CompressedSize,	compressedSize);
		Gura_PackUInt32(fields.UncompressedSize,	uncompressedSize);
		if (!desc.Write(sig, *_pStreamDst)) return false;
	} while (0);
	do {
		CentralFileHeader::Fields &fields = pHdr->GetFields();
		Gura_PackUInt32(fields.Crc32,			crc32num);
		Gura_PackUInt32(fields.CompressedSize,	compressedSize);
		Gura_PackUInt32(fields.UncompressedSize,	uncompressedSize);
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
	UInt32 offsetOfCentralDirectory = static_cast<UInt32>(offset);
	UInt32 sizeOfTheCentralDirectory =
							static_cast<UInt32>(_pStreamDst->Tell() - offset);
	UInt16 nCentralFileHeaders = static_cast<UInt16>(_hdrList.size());
	do {
		EndOfCentralDirectoryRecord rec;
		EndOfCentralDirectoryRecord::Fields &fields = rec.GetFields();
		Gura_PackUInt16(fields.NumberOfThisDisk,									0x0000);
		Gura_PackUInt16(fields.NumberOfTheDiskWithTheStartOfTheCentralDirectory,	0x0000);
		Gura_PackUInt16(fields.TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk,	nCentralFileHeaders);
		Gura_PackUInt16(fields.TotalNumberOfEntriesInTheCentralDirectory,			nCentralFileHeaders);
		Gura_PackUInt32(fields.SizeOfTheCentralDirectory,							sizeOfTheCentralDirectory);
		Gura_PackUInt32(fields.OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber,
															offsetOfCentralDirectory);
		Gura_PackUInt16(fields.ZIPFileCommentLength,								0x0000);
		if (!rec.Write(_sig, *_pStreamDst)) return false;
	} while (0);
	_pStreamDst->Close();
	_pStreamDst.reset(nullptr);
	return !_sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// Gura interfaces of zip.writer
//-----------------------------------------------------------------------------
// zip.writer#add(stream:stream:r, filename?:string, compression?:symbol):map:reduce
Gura_DeclareMethod(writer, add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "compression", VTYPE_symbol, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Reads data from `stream` and adds it to the zip file.\n"
		"Entry name is decided by the file name associated with the stream\n"
		"unless it's specified by argument `filename`.\n"
		"\n"
		"Argument `compression` specifies the compression method and takes one of the following symbol.\n"
		"\n"
		"- `` `store``\n"
		"- `` `deflate``\n"
		"- `` `bzip2``\n");
}

Gura_ImplementMethod(writer, add)
{
	Signal &sig = env.GetSignal();
	Object_writer *pThis = Object_writer::GetObjectThis(arg);
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
	UInt16 compressionMethod = arg.Is_symbol(2)?
						SymbolToCompressionMethod(arg.GetSymbol(2)) :
						pThis->GetCompressionMethod();
	if (compressionMethod == METHOD_Invalid) {
		sig.SetError(ERR_IOError, "invalid compression method");
		return Value::Nil;
	}
	if (!pThis->Add(env, arg.GetStream(0),
					fileName.c_str(), compressionMethod)) return Value::Nil;
	return arg.GetValueThis();
}

// zip.writer#close():void
Gura_DeclareMethod(writer, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Closes the zip file after flushing cached data.");
}

Gura_ImplementMethod(writer, close)
{
	Object_writer *pThis = Object_writer::GetObjectThis(arg);
	if (!pThis->Finish()) return Value::Nil;
	return Value::Nil;
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
								Iterator(Finite), _pObjZipR(pObjZipR)
{
	_ppHdr = pObjZipR->GetHeaderList().begin();
}

Iterator_Entry::~Iterator_Entry()
{
}

Iterator *Iterator_Entry::GetSource()
{
	return nullptr;
}

bool Iterator_Entry::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_ppHdr == _pObjZipR->GetHeaderList().end()) return false;
	const CentralFileHeader *pHdr = *_ppHdr;
	const CentralFileHeader::Fields &fields = pHdr->GetFields();
	Stream *pStreamSrc = _pObjZipR->GetStreamSrc();
	if (pStreamSrc == nullptr) return false;
	long offset = Gura_UnpackInt32(fields.RelativeOffsetOfLocalHeader);
	Stream *pStream = CreateStream(env, pStreamSrc, pHdr);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(reader));
	AddHelp(
		Gura_Symbol(en),
		"Creates `zip.reader` instance from the specified stream.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("reader", "zip.reader"));
}

Gura_ImplementFunction(reader)
{
	Signal &sig = env.GetSignal();
	Stream &streamSrc = arg.GetStream(0);
	AutoPtr<Object_reader> pObjZipR(new Object_reader(sig, streamSrc.Reference()));
	if (!pObjZipR->ReadDirectory(env)) return Value::Nil;
	Value result(pObjZipR.release());
	return ReturnValue(env, arg, result);
}

// zip.writer(stream:stream:w, compression?:symbol) {block?}
Gura_DeclareFunction(writer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "compression", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(writer));
	AddHelp(
		Gura_Symbol(en),
		"Creates `zip.writer` instance from the stream.\n"
		"\n"
		"Argument `compression` specifies the compression method and takes one of the following symbol.\n"
		"\n"
		"- `` `store``\n"
		"- `` `deflate``\n"
		"- `` `bzip2``\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("writer", "zip.writer"));
}

Gura_ImplementFunction(writer)
{
	Signal &sig = env.GetSignal();
	Stream &streamDst = arg.GetStream(0);
	UInt16 compressionMethod = arg.Is_symbol(1)?
			SymbolToCompressionMethod(arg.GetSymbol(1)) : METHOD_Deflate;
	if (compressionMethod == METHOD_Invalid) {
		sig.SetError(ERR_IOError, "invalid compression method");
		return Value::Nil;
	}
	Object_writer *pObjZipW = new Object_writer(sig, streamDst.Reference(), compressionMethod);
	Value result(pObjZipW);
	return ReturnValue(env, arg, result);
}

// zip.test(stream:stream:r)
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
	Gura_RealizeAndPrepareUserClass(reader, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(writer, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(stat, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(reader);
	Gura_AssignFunction(writer);
	Gura_AssignFunction(test);
	// registration of stream/directory factory
	PathMgr::Register(env, new PathMgr_ZIP());
	return true;
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

String Object_stat::ToString(bool exprFlag)
{
	String str;
	str = "<zip.stat:";
	str += _hdr.GetFileName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// zip.stat#attributes
Gura_DeclareProperty_R(stat, attributes)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, attributes)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(static_cast<UInt32>(hdr.GetExternalFileAttributes()));
}

// zip.stat#comment
Gura_DeclareProperty_R(stat, comment)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, comment)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(hdr.GetFileComment());
}

// zip.stat#compressed_size
Gura_DeclareProperty_R(stat, compressed_size)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, compressed_size)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(static_cast<UInt32>(hdr.GetCompressedSize()));
}

// zip.stat#compression_method
Gura_DeclareProperty_R(stat, compression_method)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, compression_method)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(static_cast<UInt32>(hdr.GetCompressionMethod()));
}

// zip.stat#crc32
Gura_DeclareProperty_R(stat, crc32)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, crc32)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(hdr.GetCrc32());
}

// zip.stat#filename
Gura_DeclareProperty_R(stat, filename)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, filename)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(hdr.GetFileName());
}

// zip.stat#mtime
Gura_DeclareProperty_R(stat, mtime)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, mtime)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(new Object_datetime(env, hdr.GetLastModDateTime()));
}

// zip.stat#size
Gura_DeclareProperty_R(stat, size)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(stat, size)
{
	const CentralFileHeader &hdr = Object_stat::GetObject(valueThis)->GetCentralFileHeader();
	return Value(static_cast<UInt32>(hdr.GetUncompressedSize()));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_stat
//-----------------------------------------------------------------------------
// implementation of class stat
Gura_ImplementUserClass(stat)
{
	// Assignment of properties
	Gura_AssignProperty(stat, attributes);
	Gura_AssignProperty(stat, comment);
	Gura_AssignProperty(stat, compressed_size);
	Gura_AssignProperty(stat, compression_method);
	Gura_AssignProperty(stat, crc32);
	Gura_AssignProperty(stat, filename);
	Gura_AssignProperty(stat, mtime);
	Gura_AssignProperty(stat, size);
}

//-----------------------------------------------------------------------------
// Stream_reader implementation
//-----------------------------------------------------------------------------
Stream_reader::Stream_reader(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream(env, ATTR_Readable), _pStreamSrc(pStreamSrc), _hdr(hdr),
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

size_t Stream_reader::CheckCRC32(Signal &sig, const void *buff, size_t bytesRead)
{
	if (_seekedFlag) return bytesRead;
	_crc32.Update(buff, bytesRead);
	if (bytesRead == 0 && _crc32Expected != _crc32.GetResult()) {
		sig.SetError(ERR_FormatError, "CRC error");
		return 0;
	}
	return bytesRead;
}

size_t Stream_reader::DoWrite(Signal &sig, const void *buff, size_t len)
{
	return 0;
}

bool Stream_reader::DoFlush(Signal &sig)
{
	return false;
}

bool Stream_reader::DoClose(Signal &sig)
{
	_pStreamSrc.reset(nullptr);
	return Stream::DoClose(sig);
}

size_t Stream_reader::DoGetSize()
{
	return _bytesUncompressed;
}

Object *Stream_reader::DoGetStatObj(Signal &sig)
{
	return new Object_stat(_hdr);
}

//-----------------------------------------------------------------------------
// Stream_reader_Store implementation
// Compression method #0: stored (no compression)
//-----------------------------------------------------------------------------
Stream_reader_Store::Stream_reader_Store(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream_reader(env, pStreamSrc, hdr), _offsetTop(pStreamSrc->Tell())
{
}

Stream_reader_Store::~Stream_reader_Store()
{
}

bool Stream_reader_Store::Initialize(Environment &env)
{
	return true;
}

size_t Stream_reader_Store::DoRead(Signal &sig, void *buff, size_t bytes)
{
	size_t bytesRest = _bytesUncompressed - (_pStreamSrc->Tell() - _offsetTop);
	if (bytes > bytesRest) bytes = bytesRest;
	size_t bytesRead = _pStreamSrc->Read(sig, buff, bytes);
	return CheckCRC32(sig, buff, bytesRead);
}

bool Stream_reader_Store::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
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
Stream_reader_Deflate::Stream_reader_Deflate(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr) :
											Stream_reader(env, pStreamSrc, hdr)
{
}

Stream_reader_Deflate::~Stream_reader_Deflate()
{
}

bool Stream_reader_Deflate::Initialize(Environment &env)
{
	Signal &sig = env.GetSignal();
	_pStreamInflater.reset(new ZLib::Stream_Inflater(env,
						Stream::Reference(_pStreamSrc.get()), _bytesCompressed));
	return _pStreamInflater->Initialize(sig, -MAX_WBITS);
}

size_t Stream_reader_Deflate::DoRead(Signal &sig, void *buff, size_t bytes)
{
	size_t bytesRead = _pStreamInflater->Read(sig, buff, bytes);
	return CheckCRC32(sig, buff, bytesRead);
}

bool Stream_reader_Deflate::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	_seekedFlag = true;
	return _pStreamInflater->Seek(sig, offset, seekMode);
}

//-----------------------------------------------------------------------------
// Stream_reader_BZIP2 implementation
// Compression method #12: BZIP2
//-----------------------------------------------------------------------------
Stream_reader_BZIP2::Stream_reader_BZIP2(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr) :
											Stream_reader(env, pStreamSrc, hdr)
{
}

Stream_reader_BZIP2::~Stream_reader_BZIP2()
{
}

bool Stream_reader_BZIP2::Initialize(Environment &env)
{
	Signal &sig = env.GetSignal();
	_pStreamDecompressor.reset(new BZLib::Stream_Decompressor(env,
						Stream::Reference(_pStreamSrc.get()), _bytesCompressed));
	int verbosity = 0, small = 0;
	return _pStreamDecompressor->Initialize(sig, verbosity, small);
}

size_t Stream_reader_BZIP2::DoRead(Signal &sig, void *buff, size_t bytes)
{
	size_t bytesRead = _pStreamDecompressor->Read(sig, buff, bytes);
	return CheckCRC32(sig, buff, bytesRead);
}

bool Stream_reader_BZIP2::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	_seekedFlag = true;
	return _pStreamDecompressor->Seek(sig, offset, seekMode);
}

//-----------------------------------------------------------------------------
// Stream_reader_Deflate64 implementation
// Compression method #9: Enhanced Deflating using Deflate64(tm)
//-----------------------------------------------------------------------------
Stream_reader_Deflate64::Stream_reader_Deflate64(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr) :
	Stream_reader(env, pStreamSrc, hdr)
{
}

Stream_reader_Deflate64::~Stream_reader_Deflate64()
{
}

bool Stream_reader_Deflate64::Initialize(Environment &env)
{
	Signal &sig = env.GetSignal();
	sig.SetError(ERR_SystemError, "this compression method is not implemented yet");
	return false;
}

size_t Stream_reader_Deflate64::DoRead(Signal &sig, void *buff, size_t bytes)
{
	return 0;
}

bool Stream_reader_Deflate64::DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode)
{
	return false;
}

//-----------------------------------------------------------------------------
// Record_ZIP implementation
//-----------------------------------------------------------------------------
Record_ZIP::Record_ZIP(DirBuilder::Structure *pStructure, Record_ZIP *pParent,
								const char *name, bool containerFlag) :
	DirBuilder::Record(pStructure, pParent, name, containerFlag), _pHdr(nullptr)
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

Directory *Directory_ZIP::DoNext(Environment &env)
{
	return _pRecord->Next(this);
}

Stream *Directory_ZIP::DoOpenStream(Environment &env, ULong attr)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Stream> pStreamSrc;
	for (Directory *pDirectory = this; pDirectory != nullptr;
											pDirectory = pDirectory->GetParent()) {
		if (pDirectory->IsBoundaryContainer()) {
			pStreamSrc.reset(pDirectory->GetParent()->
							DoOpenStream(env, Stream::ATTR_Readable));
			if (sig.IsSignalled()) return nullptr;
			break;
		}
	}
	const CentralFileHeader *pHdr = _pRecord->GetCentralFileHeader();
	GURA_ASSUME(env, pHdr != nullptr);
	return CreateStream(env, pStreamSrc.get(), pHdr);
}

Object *Directory_ZIP::DoGetStatObj(Signal &sig)
{
	return new Object_stat(*_pRecord->GetCentralFileHeader());
}

//-----------------------------------------------------------------------------
// PathMgr_ZIP implementation
//-----------------------------------------------------------------------------
bool PathMgr_ZIP::IsResponsible(Environment &env,
						const Directory *pParent, const char *pathName)
{
	return pParent != nullptr && !pParent->IsContainer() &&
			(EndsWith(pParent->GetName(), ".zip", true) ||
			 EndsWith(pParent->GetName(), ".gurc", true) ||
			 EndsWith(pParent->GetName(), ".gurcw", true));
}

Directory *PathMgr_ZIP::DoOpenDirectory(Environment &env,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Stream> pStreamSrc(pParent->DoOpenStream(env, Stream::ATTR_Readable));
	if (sig.IsSignalled()) return nullptr;
	return CreateDirectory(env, pStreamSrc.get(), pParent, pPathName, notFoundMode);
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
UInt16 SymbolToCompressionMethod(const Symbol *pSymbol)
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

UInt16 GetDosTime(const DateTime &dt)
{
	return (static_cast<UInt16>(dt.GetHour()) << 11) |
			(static_cast<UInt16>(dt.GetMin()) << 5) |
			(static_cast<UInt16>(dt.GetSec() / 2) << 0);
}

UInt16 GetDosDate(const DateTime &dt)
{
	return (static_cast<UInt16>(dt.GetYear() - 1980) << 9) |
			(static_cast<UInt16>(dt.GetMonth()) << 5) |
			(static_cast<UInt16>(dt.GetDay()) << 0);
}

DateTime MakeDateTimeFromDos(UInt16 dosDate, UInt16 dosTime)
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

UInt32 SeekCentralDirectory(Signal &sig, Stream *pStream)
{
	size_t bytesZIPFile = pStream->GetSize();
	if (bytesZIPFile == InvalidSize) {
		sig.SetError(ERR_IOError, "can't seek end of file");
		return 0;
	}
	UInt32 offsetCentralDirectory = 0;
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
	if (sig.IsSignalled()) return 0;
	char *buffAnchor = nullptr;
	for (size_t i = 0; i <= bytesBuff - EndOfCentralDirectoryRecord::MinSize; i++) {
		if (::memcmp(buff + i, "\x50\x4b\x05\x06", 4) == 0) {
			buffAnchor = buff + i;
		}
	}
	if (buffAnchor == nullptr) {
		sig.SetError(ERR_FormatError, "can't find central directory record");
		return 0;
	}
	EndOfCentralDirectoryRecord record;
	::memcpy(&record, buffAnchor, EndOfCentralDirectoryRecord::MinSize);
	return Gura_UnpackUInt32(record.GetFields().
			OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber);
}

Directory *CreateDirectory(Environment &env, Stream *pStreamSrc,
	Directory *pParent, const char **pPathName, PathMgr::NotFoundMode notFoundMode)
{
	Signal &sig = env.GetSignal();
	if (!pStreamSrc->IsBwdSeekable()) {
		Stream *pStreamPrefetch = Stream::Prefetch(env, pStreamSrc, true);
		if (sig.IsSignalled()) return nullptr;
		pStreamSrc = pStreamPrefetch;
	}
	AutoPtr<DirBuilder::Structure> pStructure(new DirBuilder::Structure());
	pStructure->SetRoot(new Record_ZIP(pStructure.get(), nullptr, "", true));
	UInt32 offsetCentralDirectory = SeekCentralDirectory(sig, pStreamSrc);
	if (sig.IsSignalled()) return nullptr;
	if (!pStreamSrc->Seek(sig, offsetCentralDirectory, Stream::SeekSet)) return nullptr;
	UInt32 signature;
	while (ReadStream(sig, *pStreamSrc, &signature)) {
		//::printf("%08x\n", signature);
		if (signature == LocalFileHeader::Signature) {
			LocalFileHeader hdr;
			if (!hdr.Read(sig, *pStreamSrc)) return nullptr;
			if (!hdr.SkipFileData(sig, *pStreamSrc)) return nullptr;
		} else if (signature == ArchiveExtraDataRecord::Signature) {
			ArchiveExtraDataRecord record;
			if (!record.Read(sig, *pStreamSrc)) return nullptr;
		} else if (signature == CentralFileHeader::Signature) {
			CentralFileHeader *pHdr = new CentralFileHeader();
			if (!pHdr->Read(sig, *pStreamSrc)) {
				delete pHdr;
				return nullptr;
			}
			Record_ZIP *pRecord = dynamic_cast<Record_ZIP *>(
									pStructure->AddRecord(pHdr->GetFileName()));
			pRecord->SetCentralFileHeader(pHdr);
		} else if (signature == DigitalSignature::Signature) {
			DigitalSignature signature;
			if (!signature.Read(sig, *pStreamSrc)) return nullptr;
		} else if (signature == Zip64EndOfCentralDirectory::Signature) {
			Zip64EndOfCentralDirectory dir;
			if (!dir.Read(sig, *pStreamSrc)) return nullptr;
		} else if (signature == Zip64EndOfCentralDirectoryLocator::Signature) {
			Zip64EndOfCentralDirectoryLocator loc;
			if (!loc.Read(sig, *pStreamSrc)) return nullptr;
		} else if (signature == EndOfCentralDirectoryRecord::Signature) {
			EndOfCentralDirectoryRecord record;
			if (!record.Read(sig, *pStreamSrc)) return nullptr;
			break;
		} else {
			sig.SetError(ERR_FormatError, "unknown signature %08x", signature);
			return nullptr;
		}
	}
	if (sig.IsSignalled()) return nullptr;
	//pStreamSrc->Close();
	return pStructure->GenerateDirectory(sig, pParent, pPathName, notFoundMode);
}

Stream *CreateStream(Environment &env, Stream *pStreamSrc, const CentralFileHeader *pHdr)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Stream_reader> pStream;
	long offset = static_cast<long>(pHdr->GetRelativeOffsetOfLocalHeader());
	pStreamSrc->Seek(sig, offset, Stream::SeekSet);
	if (sig.IsSignalled()) return nullptr;
	do {
		UInt32 signature;
		if (!ReadStream(sig, *pStreamSrc, &signature)) return nullptr;
		if (signature != LocalFileHeader::Signature) {
			sig.SetError(ERR_FormatError, "invalid ZIP format");
			return nullptr;
		}
		LocalFileHeader hdr;
		if (!hdr.Read(sig, *pStreamSrc)) return nullptr;
	} while (0);
	//const char *name = pHdr->GetFileName();
	UInt16 compressionMethod = pHdr->GetCompressionMethod();
	//size_t bytesUncompressed = pHdr->GetUncompressedSize();
	//size_t bytesCompressed = pHdr->GetCompressedSize();
	//UInt32 crc32Expected = pHdr->GetCrc32();
	if (compressionMethod == METHOD_Store) {
		pStream.reset(new Stream_reader_Store(env, Stream::Reference(pStreamSrc), *pHdr));
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
		pStream.reset(new Stream_reader_Deflate(env, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_Deflate64) {
		pStream.reset(new Stream_reader_Deflate64(env, Stream::Reference(pStreamSrc), *pHdr));
	} else if (compressionMethod == METHOD_PKWARE) {
		// unsupported
	} else if (compressionMethod == METHOD_BZIP2) {
		pStream.reset(new Stream_reader_BZIP2(env, Stream::Reference(pStreamSrc), *pHdr));
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
		return nullptr;
	}
	if (!pStream->Initialize(env)) return nullptr;
	return pStream.release();
}

bool SkipStream(Signal &sig, Stream &stream, size_t bytes)
{
	return stream.Seek(sig, static_cast<long>(bytes), Stream::SeekCur);
}

bool ReadStream(Signal &sig, Stream &stream, void *buff, size_t bytes, size_t offset)
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

bool ReadStream(Signal &sig, Stream &stream, UInt32 *pSignature)
{
	struct {
		Gura_PackedUInt32_LE(Signature);
	} buff;
	if (!ReadStream(sig, stream, &buff, 4)) return false;
	*pSignature = Gura_UnpackUInt32(buff.Signature);
	return true;
}

bool ReadStream(Signal &sig, Stream &stream, Binary &binary, size_t bytes)
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

bool WriteStream(Signal &sig, Stream &stream, void *buff, size_t bytes)
{
	stream.Write(sig, buff, bytes);
	return !sig.IsSignalled();
}

bool WriteStream(Signal &sig, Stream &stream, Binary &binary)
{
	stream.Write(sig, binary.data(), binary.size());
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// structures
//-----------------------------------------------------------------------------
bool LocalFileHeader::SkipOver(Signal &sig, Stream &stream)
{
	if (!ReadStream(sig, stream, &_fields, 30 - 4, 4)) return false;
	if (IsExistDataDescriptor()) {
		sig.SetError(ERR_FormatError,
			"failed to skip local file header because it has data descriptor");
		return false;
	}
	size_t bytesToSkip = 0;
	bytesToSkip += Gura_UnpackUInt16(_fields.FileNameLength);
	bytesToSkip += Gura_UnpackUInt16(_fields.ExtraFieldLength);
	bytesToSkip += Gura_UnpackUInt32(_fields.CompressedSize);
	if (!SkipStream(sig, stream, bytesToSkip)) return false;
	return true;
}

Gura_EndModuleBody(zip, zip)

Gura_RegisterModule(zip)
