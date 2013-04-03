//-----------------------------------------------------------------------------
// Gura zip module
// specification: http://www.pkware.com/documents/casestudies/APPNOTE.TXT
//-----------------------------------------------------------------------------
#ifndef __MODULE_ZIP_H__
#define __MODULE_ZIP_H__
#include <gura.h>

Gura_BeginModule(zip)

Gura_DeclareUserSymbol(filename);
Gura_DeclareUserSymbol(comment);
Gura_DeclareUserSymbol(compression_method);
Gura_DeclareUserSymbol(mtime);
Gura_DeclareUserSymbol(crc32);
Gura_DeclareUserSymbol(size);
Gura_DeclareUserSymbol(compressed_size);
Gura_DeclareUserSymbol(attributes);

Gura_DeclareUserSymbol(store);
Gura_DeclareUserSymbol(shrink);
Gura_DeclareUserSymbol(factor1);
Gura_DeclareUserSymbol(factor2);
Gura_DeclareUserSymbol(factor3);
Gura_DeclareUserSymbol(factor4);
Gura_DeclareUserSymbol(implode);
Gura_DeclareUserSymbol(deflate);
Gura_DeclareUserSymbol(deflate64);
Gura_DeclareUserSymbol(pkware);
Gura_DeclareUserSymbol(bzip2);
Gura_DeclareUserSymbol(lzma);
Gura_DeclareUserSymbol(tersa);
Gura_DeclareUserSymbol(lz77);
Gura_DeclareUserSymbol(wavpack);
Gura_DeclareUserSymbol(ppmd);

class CentralFileHeader;

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
unsigned short SymbolToCompressionMethod(const Symbol *pSymbol);
unsigned short GetDosTime(const DateTime &dt);
unsigned short GetDosDate(const DateTime &dt);
DateTime MakeDateTimeFromDos(unsigned short dosDate, unsigned short dosTime);
bool IsMatchedName(const char *name1, const char *name2);

unsigned long SeekCentralDirectory(Signal sig, Stream *pStream);
Directory *CreateDirectory(Environment &env, Signal sig, Stream *pStreamSrc,
	Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode);
Stream *CreateStream(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader *pHdr);

bool SkipStream(Signal sig, Stream &stream, size_t bytes);
bool ReadStream(Signal sig, Stream &stream, void *buff, size_t bytes, size_t offset = 0);
bool ReadStream(Signal sig, Stream &stream, unsigned long *pSignature);
bool ReadStream(Signal sig, Stream &stream, Binary &binary, size_t bytes);
bool WriteStream(Signal sig, Stream &stream, void *buff, size_t bytes);
bool WriteStream(Signal sig, Stream &stream, Binary &binary);

//-----------------------------------------------------------------------------
// structures
//-----------------------------------------------------------------------------
enum {
	METHOD_Invalid		= -1,
	METHOD_Store		= 0,	// The file is stored (no compression)
	METHOD_Shrink		= 1,	// The file is Shrunk
	METHOD_Factor1		= 2,	// The file is Reduced with compression factor 1
	METHOD_Factor2		= 3,	// The file is Reduced with compression factor 2
	METHOD_Factor3		= 4,	// The file is Reduced with compression factor 3
	METHOD_Factor4		= 5,	// The file is Reduced with compression factor 4
	METHOD_Implode		= 6,	// The file is Imploded
	METHOD_Deflate		= 8,	// The file is Deflated
	METHOD_Deflate64	= 9,	// Enhanced Deflating using Deflate64(tm)
	METHOD_PKWARE		= 10,	// PKWARE Data Compression Library Imploding (old IBM TERSE)
	METHOD_BZIP2		= 12,	// File is compressed using BZIP2 algorithm
	METHOD_LZMA			= 14,	// LZMA (EFS)
	METHOD_TERSA		= 18,	// File is compressed using IBM TERSE (new)
	METHOD_LZ77			= 19,	// IBM LZ77 z Architecture (PFS)
	METHOD_WavPack		= 97,	// WavPack compressed data
	METHOD_PPMd			= 99,	// PPMd version I, Rev 1
};

enum {
	DOSATTR_ReadOnly		= (1 << 0),
	DOSATTR_Hidden			= (1 << 1),
	DOSATTR_System			= (1 << 2),
	DOSATTR_VolumeLabel		= (1 << 3),
	DOSATTR_Subdirectory	= (1 << 4),
	DOSATTR_Archive			= (1 << 5),
	DOSATTR_Device			= (1 << 6),
	DOSATTR_Unused			= (1 << 7),
};

// A. Local file header
class LocalFileHeader {
public:
	enum { Signature = 0x04034b50 };
	struct Fields {
		Gura_PackedULong_LE(Signature);
		Gura_PackedUShort_LE(VersionNeededToExtract);
		Gura_PackedUShort_LE(GeneralPurposeBitFlag);
		Gura_PackedUShort_LE(CompressionMethod);
		Gura_PackedUShort_LE(LastModFileTime);
		Gura_PackedUShort_LE(LastModFileDate);
		Gura_PackedULong_LE(Crc32);				// zero if Data Descriptor exists
		Gura_PackedULong_LE(CompressedSize);	// zero if Data Descriptor exists
		Gura_PackedULong_LE(UncompressedSize);	// zero if Data Descriptor exists
		Gura_PackedUShort_LE(FileNameLength);
		Gura_PackedUShort_LE(ExtraFieldLength);
		// FileName (FileNameLength bytes)
		// ExtraField (ExtraFieldLength bytes)
	};
private:
	Fields _fields;
	Binary _fileName;
	Binary _extraField;
public:
	inline LocalFileHeader() { Gura_PackULong(_fields.Signature, Signature); }
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 30 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _fileName,
						Gura_UnpackUShort(_fields.FileNameLength))) return false;
		if (!ReadStream(sig, stream, _extraField,
						Gura_UnpackUShort(_fields.ExtraFieldLength))) return false;
		return true;
	}
	bool SkipOver(Signal sig, Stream &stream);
	inline bool Write(Signal sig, Stream &stream) {
		Gura_PackUShort(_fields.FileNameLength, _fileName.size());
		Gura_PackUShort(_fields.FileNameLength, _extraField.size());
		if (!WriteStream(sig, stream, &_fields, 30)) return false;
		if (!WriteStream(sig, stream, _fileName)) return false;
		if (!WriteStream(sig, stream, _extraField)) return false;
		return true;
	}
	inline bool SkipFileData(Signal sig, Stream &stream) {
		return SkipStream(sig, stream, Gura_UnpackULong(_fields.CompressedSize));
	}
	inline void SetFileName(const char *fileName) { _fileName = fileName; }
	inline const char *GetFileName() const { return _fileName.c_str(); }
	inline bool IsEncrypted() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 0)) != 0;
	}
	inline bool IsExistDataDescriptor() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 3)) != 0;
	}
	inline bool IsStrongEncrypted() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 6)) != 0;
	}
	inline bool IsUtf8() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 11)) != 0;
	}
	inline DateTime GetLastModDateTime() const {
		unsigned short dosTime = Gura_UnpackUShort(_fields.LastModFileTime);
		unsigned short dosDate = Gura_UnpackUShort(_fields.LastModFileDate);
		return MakeDateTimeFromDos(dosDate, dosTime);
	}
	inline void Print() const {
		::printf("Signature              %08x\n", Gura_UnpackULong(_fields.Signature));
		::printf("VersionNeededToExtract %04x\n", Gura_UnpackUShort(_fields.VersionNeededToExtract));
		::printf("GeneralPurposeBitFlag  %04x\n", Gura_UnpackUShort(_fields.GeneralPurposeBitFlag));
		::printf("CompressionMethod      %04x\n", Gura_UnpackUShort(_fields.CompressionMethod));
		::printf("LastModFileTime        %04x\n", Gura_UnpackUShort(_fields.LastModFileTime));
		::printf("LastModFileDate        %04x\n", Gura_UnpackUShort(_fields.LastModFileDate));
		::printf("Crc32                  %08x\n", Gura_UnpackULong(_fields.Crc32));
		::printf("CompressedSize         %08x\n", Gura_UnpackULong(_fields.CompressedSize));
		::printf("UncompressedSize       %08x\n", Gura_UnpackULong(_fields.UncompressedSize));
		::printf("FileNameLength         %04x\n", Gura_UnpackUShort(_fields.FileNameLength));
		::printf("ExtraFieldLength       %04x\n", Gura_UnpackUShort(_fields.ExtraFieldLength));
	}
};

// B. File data

// C. Data descriptor
class DataDescriptor {
public:
	struct Fields {
		Gura_PackedULong_LE(Crc32);
		Gura_PackedULong_LE(CompressedSize);
		Gura_PackedULong_LE(UncompressedSize);
	};
private:
	Fields _fields;
public:
	inline DataDescriptor() {}
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		return ReadStream(sig, stream, &_fields, 12);
	}
	inline bool Write(Signal sig, Stream &stream) {
		return WriteStream(sig, stream, &_fields, 12);
	}
};

// D. Archive decryption header

// E. Archive extra data record
class ArchiveExtraDataRecord {
public:
	enum { Signature = 0x08064b50 };
	struct Fields {
		Gura_PackedULong_LE(Signature);
		Gura_PackedULong_LE(ExtraFieldLength);
		// ExtraField (ExtraFieldLength bytes)
	};
private:
	Fields _fields;
	Binary _extraField;
public:
	inline ArchiveExtraDataRecord() { Gura_PackULong(_fields.Signature, Signature); }
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 8 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _extraField,
						Gura_UnpackULong(_fields.ExtraFieldLength))) return false;
		return true;
	}
	inline bool Write(Signal sig, Stream &stream) {
		Gura_PackULong(_fields.ExtraFieldLength, _extraField.size());
		if (!WriteStream(sig, stream, &_fields, 8)) return false;
		if (!WriteStream(sig, stream, _extraField)) return false;
		return true;
	}
};

// F. Central directory structure
class CentralFileHeader {
public:
	enum { Signature = 0x02014b50 };
	struct Fields {
		Gura_PackedULong_LE(Signature);
		Gura_PackedUShort_LE(VersionMadeBy);				// only in CentralFileHeader
		Gura_PackedUShort_LE(VersionNeededToExtract);
		Gura_PackedUShort_LE(GeneralPurposeBitFlag);
		Gura_PackedUShort_LE(CompressionMethod);
		Gura_PackedUShort_LE(LastModFileTime);
		Gura_PackedUShort_LE(LastModFileDate);
		Gura_PackedULong_LE(Crc32);
		Gura_PackedULong_LE(CompressedSize);
		Gura_PackedULong_LE(UncompressedSize);
		Gura_PackedUShort_LE(FileNameLength);
		Gura_PackedUShort_LE(ExtraFieldLength);
		Gura_PackedUShort_LE(FileCommentLength);			// only in CentralFileHeader
		Gura_PackedUShort_LE(DiskNumberStart);				// only in CentralFileHeader
		Gura_PackedUShort_LE(InternalFileAttributes);		// only in CentralFileHeader
		Gura_PackedULong_LE(ExternalFileAttributes);		// only in CentralFileHeader
		Gura_PackedULong_LE(RelativeOffsetOfLocalHeader);	// only in CentralFileHeader
		// FileName (FileNameLength bytes)
		// ExtraField (ExtraFieldLength bytes)
		// FileComment (FileCommentLength bytes)
	};
private:
	Fields _fields;
	Binary _fileName;
	Binary _extraField;
	Binary _fileComment;
public:
	inline CentralFileHeader() { Gura_PackULong(_fields.Signature, Signature); }
	inline CentralFileHeader(const CentralFileHeader &hdr) :
		_fields(hdr._fields), _fileName(hdr._fileName),
		_extraField(hdr._extraField), _fileComment(hdr._fileComment) {}
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 46 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _fileName,
						Gura_UnpackUShort(_fields.FileNameLength))) return false;
		if (!ReadStream(sig, stream, _extraField,
						Gura_UnpackUShort(_fields.ExtraFieldLength))) return false;
		if (!ReadStream(sig, stream, _fileComment,
						Gura_UnpackUShort(_fields.FileCommentLength))) return false;
		return true;
	}
	inline bool Write(Signal sig, Stream &stream) {
		Gura_PackUShort(_fields.FileNameLength, _fileName.size());
		Gura_PackUShort(_fields.ExtraFieldLength, _extraField.size());
		Gura_PackUShort(_fields.FileCommentLength, _fileComment.size());
		if (!WriteStream(sig, stream, &_fields, 46)) return false;
		if (!WriteStream(sig, stream, _fileName)) return false;
		if (!WriteStream(sig, stream, _extraField)) return false;
		if (!WriteStream(sig, stream, _fileComment)) return false;
		return true;
	}
	inline bool WriteAsLocalFileHeader(Signal sig, Stream &stream) {
		LocalFileHeader hdr;
		LocalFileHeader::Fields &fields = hdr.GetFields();
		Gura_PackUShort(fields.VersionNeededToExtract,
						Gura_UnpackUShort(_fields.VersionNeededToExtract));
		Gura_PackUShort(fields.GeneralPurposeBitFlag,
						Gura_UnpackUShort(_fields.GeneralPurposeBitFlag));
		Gura_PackUShort(fields.CompressionMethod,
						Gura_UnpackUShort(_fields.CompressionMethod));
		Gura_PackUShort(fields.LastModFileTime,
						Gura_UnpackUShort(_fields.LastModFileTime));
		Gura_PackUShort(fields.LastModFileDate,
						Gura_UnpackUShort(_fields.LastModFileDate));
		Gura_PackULong(fields.Crc32,
						Gura_UnpackULong(_fields.Crc32));
		Gura_PackULong(fields.CompressedSize,
						Gura_UnpackULong(_fields.CompressedSize));
		Gura_PackULong(fields.UncompressedSize,
						Gura_UnpackULong(_fields.UncompressedSize));
		unsigned short fileNameLength = static_cast<unsigned short>(_fileName.size());
		Gura_PackUShort(fields.FileNameLength, fileNameLength);
		unsigned short extraFieldLength = static_cast<unsigned short>(_extraField.size());
		Gura_PackUShort(fields.ExtraFieldLength, extraFieldLength);
		if (!WriteStream(sig, stream, &fields, 30)) return false;
		if (!WriteStream(sig, stream, _fileName)) return false;
		if (!WriteStream(sig, stream, _extraField)) return false;
		return true;
	}
	inline void SetFileName(const char *fileName) { _fileName = fileName; }
	inline const char *GetFileName() const { return _fileName.c_str(); }
	inline const char *GetFileComment() const { return _fileComment.c_str(); }
	inline bool IsEncrypted() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 0)) != 0;
	}
	inline bool IsExistDataDescriptor() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 3)) != 0;
	}
	inline bool IsStrongEncrypted() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 6)) != 0;
	}
	inline bool IsUtf8() const {
		return (Gura_UnpackUShort(_fields.GeneralPurposeBitFlag) & (1 << 11)) != 0;
	}
	inline unsigned long GetRelativeOffsetOfLocalHeader() const {
		return Gura_UnpackULong(_fields.RelativeOffsetOfLocalHeader);
	}
	inline unsigned short GetCompressionMethod() const {
		return Gura_UnpackUShort(_fields.CompressionMethod);
	}
	inline DateTime GetLastModDateTime() const {
		unsigned short dosTime = Gura_UnpackUShort(_fields.LastModFileTime);
		unsigned short dosDate = Gura_UnpackUShort(_fields.LastModFileDate);
		return MakeDateTimeFromDos(dosDate, dosTime);
	}
	inline unsigned long GetCrc32() const {
		return Gura_UnpackULong(_fields.Crc32);
	}
	inline unsigned long GetCompressedSize() const {
		return Gura_UnpackULong(_fields.CompressedSize);
	}
	inline unsigned long GetUncompressedSize() const {
		return Gura_UnpackULong(_fields.UncompressedSize);
	}
	inline unsigned long GetExternalFileAttributes() const {
		return Gura_UnpackULong(_fields.ExternalFileAttributes);
	}
	inline void Print() const {
		::printf("Signature              %08x\n", Gura_UnpackULong(_fields.Signature));
		::printf("VersionMadeBy          %04x\n", Gura_UnpackUShort(_fields.VersionMadeBy));
		::printf("VersionNeededToExtract %04x\n", Gura_UnpackUShort(_fields.VersionNeededToExtract));
		::printf("GeneralPurposeBitFlag  %04x\n", Gura_UnpackUShort(_fields.GeneralPurposeBitFlag));
		::printf("CompressionMethod      %04x\n", Gura_UnpackUShort(_fields.CompressionMethod));
		::printf("LastModFileTime        %04x\n", Gura_UnpackUShort(_fields.LastModFileTime));
		::printf("LastModFileDate        %04x\n", Gura_UnpackUShort(_fields.LastModFileDate));
		::printf("Crc32                  %08x\n", Gura_UnpackULong(_fields.Crc32));
		::printf("CompressedSize         %08x\n", Gura_UnpackULong(_fields.CompressedSize));
		::printf("UncompressedSize       %08x\n", Gura_UnpackULong(_fields.UncompressedSize));
		::printf("FileNameLength         %04x\n", Gura_UnpackUShort(_fields.FileNameLength));
		::printf("ExtraFieldLength       %04x\n", Gura_UnpackUShort(_fields.ExtraFieldLength));
		::printf("FileCommentLength      %04x\n", Gura_UnpackUShort(_fields.FileCommentLength));
		::printf("DiskNumberStart        %04x\n", Gura_UnpackUShort(_fields.DiskNumberStart));
		::printf("InternalFileAttributes %04x\n", Gura_UnpackUShort(_fields.InternalFileAttributes));
		::printf("ExternalFileAttributes %08x\n", Gura_UnpackULong(_fields.ExternalFileAttributes));
		::printf("RelativeOffsetOfLocalHeader %08x\n", Gura_UnpackULong(_fields.RelativeOffsetOfLocalHeader));
	}
};

class DigitalSignature {
public:
	enum { Signature = 0x05054b50 };
	struct Fields {
		Gura_PackedULong_LE(Signature);
		Gura_PackedUShort_LE(SizeOfData);
		// Data (SizeOfData bytes)
	};
private:
	Fields _fields;
	Binary _data;
public:
	inline DigitalSignature() { Gura_PackULong(_fields.Signature, Signature); }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 8 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _data,
						Gura_UnpackUShort(_fields.SizeOfData))) return false;
		return true;
	}
	inline bool Write(Signal sig, Stream &stream) {
		Gura_PackUShort(_fields.SizeOfData, _data.size());
		if (!WriteStream(sig, stream, &_fields, 8)) return false;
		if (!WriteStream(sig, stream, _data)) return false;
		return true;
	}
};

// G. Zip64 end of central directory record
class Zip64EndOfCentralDirectory {
public:
	enum { Signature = 0x06064b50 };
	struct Fields {
		Gura_PackedULong_LE(Signature);
		Gura_PackedUInt64_LE(SizeOfZip64EndOfCentralDirectoryRecord);
		Gura_PackedUShort_LE(VersionMadeBy);
		Gura_PackedUShort_LE(VersionNeededToExtract);
		Gura_PackedULong_LE(NumberOfThisDisk);
		Gura_PackedULong_LE(NumberOfTheDiskWithTheStartOfTheCentralDirectory);
		Gura_PackedUInt64_LE(TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk);
		Gura_PackedUInt64_LE(TotalNumberOfEntriesInTheCentralDirectory);
		Gura_PackedUInt64_LE(SizeOfTheCentralDirectory);
		Gura_PackedUInt64_LE(OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber);
		// Zip64ExtensibleDataSector (... bytes)
	};
private:
	Fields _fields;
public:
	inline Zip64EndOfCentralDirectory() { Gura_PackULong(_fields.Signature, Signature); }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 56 - 4, 4)) return false;
		return true;
	}
	inline bool Write(Signal sig, Stream &stream) {
		if (!WriteStream(sig, stream, &_fields, 56)) return false;
		return true;
	}
};

// H. Zip64 end of central directory locator
class Zip64EndOfCentralDirectoryLocator {
public:
	enum { Signature = 0x07064b50 };
	struct Fields {
		Gura_PackedULong_LE(Signature);
		Gura_PackedULong_LE(NumberOfTheDiskWithTheStartOfTheZip64EndOfCentralDirectory);
		Gura_PackedUInt64_LE(RelativeOffsetOfTheZip64EndOfCentralDirectoryRecord);
		Gura_PackedULong_LE(TotalNumberOfDisks);
	};
private:
	Fields _fields;
public:
	inline Zip64EndOfCentralDirectoryLocator() { Gura_PackULong(_fields.Signature, Signature); }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		return ReadStream(sig, stream, &_fields, 20 - 4, 4);
	}
	inline bool Write(Signal sig, Stream &stream) {
		return WriteStream(sig, stream, &_fields, 20);
	}
};

// I. End of central directory record
class EndOfCentralDirectoryRecord {
public:
	enum { Signature = 0x06054b50 };
	enum { MinSize = 22, MaxSize = 22 + 65536 };
	struct Fields {
		Gura_PackedULong_LE(Signature);
		Gura_PackedUShort_LE(NumberOfThisDisk);
		Gura_PackedUShort_LE(NumberOfTheDiskWithTheStartOfTheCentralDirectory);
		Gura_PackedUShort_LE(TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk);
		Gura_PackedUShort_LE(TotalNumberOfEntriesInTheCentralDirectory);
		Gura_PackedULong_LE(SizeOfTheCentralDirectory);
		Gura_PackedULong_LE(OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber);
		Gura_PackedUShort_LE(ZIPFileCommentLength);
		// ZIPFileComment (ZIPFileCommentLength bytes)
	};
private:
	Fields _fields;
	Binary _zipFileComment;
public:
	inline EndOfCentralDirectoryRecord() { Gura_PackULong(_fields.Signature, Signature); }
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 22 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _zipFileComment,
						Gura_UnpackUShort(_fields.ZIPFileCommentLength))) return false;
		return true;
	}
	inline bool Write(Signal sig, Stream &stream) {
		Gura_PackUShort(_fields.ZIPFileCommentLength, _zipFileComment.size());
		if (!WriteStream(sig, stream, &_fields, 22)) return false;
		if (!WriteStream(sig, stream, _zipFileComment)) return false;
		return true;
	}
	void Print() const {
		::printf("Signature                                                         %08x\n", Gura_UnpackULong(_fields.Signature));
		::printf("NumberOfThisDisk                                                  %04x\n", Gura_UnpackUShort(_fields.NumberOfThisDisk));
		::printf("NumberOfTheDiskWithTheStartOfTheCentralDirectory                  %04x\n", Gura_UnpackUShort(_fields.NumberOfTheDiskWithTheStartOfTheCentralDirectory));
		::printf("TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk               %04x\n", Gura_UnpackUShort(_fields.TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk));
		::printf("TotalNumberOfEntriesInTheCentralDirectory                         %04x\n", Gura_UnpackUShort(_fields.TotalNumberOfEntriesInTheCentralDirectory));
		::printf("SizeOfTheCentralDirectory                                         %08x\n", Gura_UnpackULong(_fields.SizeOfTheCentralDirectory));
		::printf("OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber %08x\n", Gura_UnpackULong(_fields.OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber));
		::printf("ZIPFileCommentLength                                              %04x\n", Gura_UnpackUShort(_fields.ZIPFileCommentLength));
	}
};

// Zip64 Extended Information Extra Field (0x0001)
class Extra_ZIP64 {
public:
	enum { Tag = 0x0001 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(Size);
		Gura_PackedUInt64_LE(OriginalSize);
		Gura_PackedUInt64_LE(CompressedSize);
		Gura_PackedUInt64_LE(RelativeHeaderOffset);
		Gura_PackedULong_LE(DiskStartNumber);
	};
};

// OS/2 Extra Field (0x0009)
class Extra_OS2 {
public:
	enum { Tag = 0x0009 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedULong_LE(BSize);
		Gura_PackedUShort_LE(CType);
		Gura_PackedULong_LE(EACRC);
		// CompressedBlock
	};
};

// NTFS Extra Field (0x000a)
class Extra_NTFS {
public:
	enum { Tag = 0x000a };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		// Tag1, Size1, ...
	};
};

// OpenVMS Extra Field (0x000c)
class Extra_VMS {
public:
	enum { Tag = 0x000c };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedULong_LE(CRC);
		// Tag1, Size1, ...
	};
};

// UNIX Extra Field (0x000d)
class Extra_UNIX {
public:
	enum { Tag = 0x000d };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedULong_LE(Atime);
		Gura_PackedULong_LE(Mtime);
		Gura_PackedUShort_LE(Uid);
		Gura_PackedUShort_LE(Gid);
		// VariableLengthDataField
	};
};

// PATCH Descriptor Extra Field (0x000f)
class Extra_Patch {
public:
	enum { Tag = 0x000f };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedUShort_LE(Version);
		Gura_PackedULong_LE(Flags);
		Gura_PackedULong_LE(OldSize);
		Gura_PackedULong_LE(OldCRC);
		Gura_PackedULong_LE(NewSize);
		Gura_PackedULong_LE(NewCRC);
	};
};

// PKCS#7 Store for X.509 Certificates (0x0014)
class Extra_Store {
public:
	enum { Tag = 0x0014 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		// TData (TSize bytes)
	};
};

// X.509 Certificate ID and Signature for individual file (0x0015)
class Extra_CID {
public:
	enum { Tag = 0x0015 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		// TData (TSize bytes)
	};
};

// X.509 Certificate ID and Signature for central directory (0x0016)
class Extra_CDID {
public:
	enum { Tag = 0x0016 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		// TData (TSize bytes)
	};
};

// Record Management Controls (0x0018)
class Extra_RecCTL {
public:
	enum { Tag = 0x0018 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(CSize);
		// Tag1, Size1, Data1, ..
	};
};

// PKCS#7 Encryption Recipient Certificate List (0x0019)
class Extra_CStore {
public:
	enum { Tag = 0x0019 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		// TData (TSize bytes)
	};
};

// MVS Extra Field (0x0065)
class Extra_MVS {
public:
	enum { Tag = 0x0065 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedUInt64_LE(ID);
		// AttributeData ((TSize - 4) bytes)
	};
};

// OS/400 Extra Field (0x0065)
class Extra_OS400 {
public:
	enum { Tag = 0x0065 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(Size);
		Gura_PackedUInt64_LE(ID);
		// AttributeData ((TSize - 4) bytes)
	};
};

// ZipIt Macintosh Extra Field (long) (0x2605)
class Extra_Mac2 {
public:
	enum { Tag = 0x2605 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedULong_BE(Signature);	// "ZPIT"
		unsigned char FnLen;
		// FileName, FileType, Creator
	};
};

// ZipIt Macintosh Extra Field (short, for files) (0x2705)
class Extra_Mac2b {
public:
	enum { Tag = 0x2705 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedULong_BE(Signature);	// "ZPIT"
		// FileType, Creator, fdFlags, reserved
	};
};

// ZipIt Macintosh Extra Field (short, for directories) (0x2805)
class Extra_Mac2c {
public:
	enum { Tag = 0x2805 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedULong_BE(Signature);	// "ZPIT"
		// frFlags, View
	};
};

// Info-ZIP Unicode Comment Extra Field (0x6375)
class Extra_UCom {
public:
	enum { Tag = 0x6375 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		unsigned char Version;
		Gura_PackedULong_LE(ComCRC32);
		// UnicodeCom
	};
};

// Info-ZIP Unicode Path Extra Field (0x7075)
class Extra_UPath {
public:
	enum { Tag = 0x7075 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		unsigned char Version;
		Gura_PackedULong_LE(NameCRC32);
		// UnicodeName
	};
};

// Microsoft Open Packaging Growth Hint (0xa220)
class Extra_MSOpen {
public:
	enum { Tag = 0xa220 };
	struct Fields {
		Gura_PackedUShort_LE(Tag);
		Gura_PackedUShort_LE(TSize);
		Gura_PackedUShort_LE(Signature);
		Gura_PackedUShort_LE(PadVal);
		// Padding
	};
};

typedef std::vector<CentralFileHeader *> CentralFileHeaderList;

//-----------------------------------------------------------------------------
// Object_stat declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(stat);

class Object_stat : public Object {
private:
	CentralFileHeader _hdr;
public:
	Gura_DeclareObjectAccessor(stat)
public:
	inline Object_stat(const CentralFileHeader &hdr) :
						Object(Gura_UserClass(stat)), _hdr(hdr) {}
	inline Object_stat(const Object_stat &obj) :
						Object(obj), _hdr(obj._hdr) {}
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
	CentralFileHeaderList _hdrList;
public:
	Gura_DeclareObjectAccessor(reader)
public:
	Object_reader(Signal sig, Stream *pStreamSrc);
	inline CentralFileHeaderList &GetHeaderList() { return _hdrList; }
	virtual ~Object_reader();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline Stream *GetStreamSrc() { return _pStreamSrc.get(); }
	bool ReadDirectory(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_writer declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(writer);

class Object_writer : public Object {
private:
	Signal _sig;
	AutoPtr<Stream> _pStreamDst;
	unsigned short _compressionMethod;
	CentralFileHeaderList _hdrList;
public:
	Gura_DeclareObjectAccessor(writer)
public:
	Object_writer(Signal sig, Stream *pStreamDst, unsigned short compressionMethod);
	inline CentralFileHeaderList &GetHeaderList() { return _hdrList; }
	virtual ~Object_writer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline Stream *GetStreamDst() { return _pStreamDst.get(); }
	bool Add(Environment &env, Signal sig, Stream &streamSrc,
					const char *fileName, unsigned short compressionMethod);
	bool Finish();
	inline unsigned short GetCompressionMethod() const { return _compressionMethod; }
};

//-----------------------------------------------------------------------------
// Iterator_Entry declaration
//-----------------------------------------------------------------------------
class Iterator_Entry : public Iterator {
private:
	AutoPtr<Object_reader> _pObjZipR;
	CentralFileHeaderList::iterator _ppHdr;
public:
	inline Iterator_Entry(Object_reader *pObjZipR);
	virtual ~Iterator_Entry();
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Directory_ZIP declaration
//-----------------------------------------------------------------------------
class Record_ZIP;

class Directory_ZIP : public Directory {
private:
	AutoPtr<DirBuilder::Structure> _pStructure;
	Record_ZIP *_pRecord;
public:
	Directory_ZIP(Directory *pParent, const char *name,
		Type type, DirBuilder::Structure *pStructure, Record_ZIP *pRecord);
	virtual ~Directory_ZIP();
	virtual Directory *DoNext(Environment &env, Signal sig);
	virtual Stream *DoOpenStream(Environment &env, Signal sig, unsigned long attr);
	virtual Object *DoGetStatObj(Signal sig);
	inline Record_ZIP &GetRecord() { return *_pRecord; }
};

//-----------------------------------------------------------------------------
// DirectoryFactory_ZIP declaration
//-----------------------------------------------------------------------------
class DirectoryFactory_ZIP : public DirectoryFactory {
public:
	virtual bool IsResponsible(Environment &env, Signal sig,
					const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env, Signal sig,
		Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode);
};

//-----------------------------------------------------------------------------
// Record_ZIP declaration
//-----------------------------------------------------------------------------
class Record_ZIP : public DirBuilder::Record {
private:
	CentralFileHeader *_pHdr;
public:
	Record_ZIP(DirBuilder::Structure *pStructure, Record_ZIP *pParent,
									const char *name, bool containerFlag);
	virtual ~Record_ZIP();
	virtual DirBuilder::Record *DoGenerateChild(const char *name, bool containerFlag);
	virtual Directory *DoGenerateDirectory(Directory *pParent, Directory::Type type);
	inline void SetCentralFileHeader(CentralFileHeader *pHdr) { _pHdr = pHdr; }
	inline const CentralFileHeader *GetCentralFileHeader() const { return _pHdr; }
};

//-----------------------------------------------------------------------------
// Stream_reader declaration
//-----------------------------------------------------------------------------
class Stream_reader : public Stream {
protected:
	AutoPtr<Stream> _pStreamSrc;
	CentralFileHeader _hdr;
	String _name;
	size_t _bytesUncompressed;
	size_t _bytesCompressed;
	unsigned long _crc32Expected;
	bool _seekedFlag;
	CRC32 _crc32;
public:
	Stream_reader(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader();
	virtual bool Initialize(Environment &env, Signal sig) = 0;
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoWrite(Signal sig, const void *buff, size_t len);
	virtual bool DoFlush(Signal sig);
	virtual bool DoClose(Signal sig);
	virtual size_t DoGetSize();
	virtual Object *DoGetStatObj(Signal sig);
	size_t CheckCRC32(Signal sig, const void *buff, size_t bytesRead);
};

//-----------------------------------------------------------------------------
// Stream_reader_Store declaration
// Compression method #0: stored (no compression)
//-----------------------------------------------------------------------------
class Stream_reader_Store : public Stream_reader {
private:
	size_t _offsetTop;
public:
	Stream_reader_Store(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_Store();
	virtual bool Initialize(Environment &env, Signal sig);
	virtual size_t DoRead(Signal sig, void *buff, size_t bytes);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

//-----------------------------------------------------------------------------
// Stream_reader_Deflate declaration
// Compression method #8: Deflated
//-----------------------------------------------------------------------------
class Stream_reader_Deflate : public Stream_reader {
private:
	AutoPtr<ZLib::Stream_Inflater> _pStreamInflater;
public:
	Stream_reader_Deflate(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_Deflate();
	virtual bool Initialize(Environment &env, Signal sig);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

//-----------------------------------------------------------------------------
// Stream_reader_BZIP2 declaration
// Compression method #12: BZIP2
//-----------------------------------------------------------------------------
class Stream_reader_BZIP2 : public Stream_reader {
private:
	AutoPtr<BZLib::Stream_Decompressor> _pStreamDecompressor;
public:
	Stream_reader_BZIP2(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_BZIP2();
	virtual bool Initialize(Environment &env, Signal sig);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

//-----------------------------------------------------------------------------
// Stream_reader_Deflate64 declaration
// Compression method #9: Enhanced Deflating using Deflate64(tm)
//-----------------------------------------------------------------------------
class Stream_reader_Deflate64 : public Stream_reader {
public:
	Stream_reader_Deflate64(Environment &env, Signal sig, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_Deflate64();
	virtual bool Initialize(Environment &env, Signal sig);
	virtual size_t DoRead(Signal sig, void *buff, size_t len);
	virtual bool DoSeek(Signal sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

}}

#endif
