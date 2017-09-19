//-----------------------------------------------------------------------------
// Gura module: zip
// specification: http://www.pkware.com/documents/casestudies/APPNOTE.TXT
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_ZIP_H__
#define __GURA_MODULE_ZIP_H__
#include <gura.h>
#include <gura/helper/ZLibHelper.h>
#include <gura/helper/BZLibHelper.h>

Gura_BeginModuleHeader(zip)

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
UInt16 SymbolToCompressionMethod(const Symbol *pSymbol);
UInt16 GetDosTime(const DateTime &dt);
UInt16 GetDosDate(const DateTime &dt);
DateTime MakeDateTimeFromDos(UInt16 dosDate, UInt16 dosTime);
bool IsMatchedName(const char *name1, const char *name2);

UInt32 SeekCentralDirectory(Signal &sig, Stream *pStream);
Directory *CreateDirectory(Environment &env, Stream *pStreamSrc,
	Directory *pParent, const char **pPathName, PathMgr::NotFoundMode notFoundMode);
Stream *CreateStream(Environment &env, Stream *pStreamSrc, const CentralFileHeader *pHdr);

bool SkipStream(Signal &sig, Stream &stream, size_t bytes);
bool ReadStream(Signal &sig, Stream &stream, void *buff, size_t bytes, size_t offset = 0);
bool ReadStream(Signal &sig, Stream &stream, UInt32 *pSignature);
bool ReadStream(Signal &sig, Stream &stream, Binary &binary, size_t bytes);
bool WriteStream(Signal &sig, Stream &stream, void *buff, size_t bytes);
bool WriteStream(Signal &sig, Stream &stream, Binary &binary);

//-----------------------------------------------------------------------------
// structures
//-----------------------------------------------------------------------------
enum {
	METHOD_Invalid		= 0xffff,
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
		Gura_PackedUInt32_LE(Signature);
		Gura_PackedUInt16_LE(VersionNeededToExtract);
		Gura_PackedUInt16_LE(GeneralPurposeBitFlag);
		Gura_PackedUInt16_LE(CompressionMethod);
		Gura_PackedUInt16_LE(LastModFileTime);
		Gura_PackedUInt16_LE(LastModFileDate);
		Gura_PackedUInt32_LE(Crc32);				// zero if Data Descriptor exists
		Gura_PackedUInt32_LE(CompressedSize);	// zero if Data Descriptor exists
		Gura_PackedUInt32_LE(UncompressedSize);	// zero if Data Descriptor exists
		Gura_PackedUInt16_LE(FileNameLength);
		Gura_PackedUInt16_LE(ExtraFieldLength);
		// FileName (FileNameLength bytes)
		// ExtraField (ExtraFieldLength bytes)
	};
private:
	Fields _fields;
	Binary _fileName;
	Binary _extraField;
public:
	inline LocalFileHeader() { Gura_PackUInt32(_fields.Signature, Signature); }
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 30 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _fileName,
						Gura_UnpackUInt16(_fields.FileNameLength))) return false;
		if (!ReadStream(sig, stream, _extraField,
						Gura_UnpackUInt16(_fields.ExtraFieldLength))) return false;
		return true;
	}
	bool SkipOver(Signal &sig, Stream &stream);
	inline bool Write(Signal &sig, Stream &stream) {
		Gura_PackUInt16(_fields.FileNameLength, _fileName.size());
		Gura_PackUInt16(_fields.FileNameLength, _extraField.size());
		if (!WriteStream(sig, stream, &_fields, 30)) return false;
		if (!WriteStream(sig, stream, _fileName)) return false;
		if (!WriteStream(sig, stream, _extraField)) return false;
		return true;
	}
	inline bool SkipFileData(Signal &sig, Stream &stream) {
		return SkipStream(sig, stream, Gura_UnpackUInt32(_fields.CompressedSize));
	}
	inline void SetFileName(const char *fileName) { _fileName = fileName; }
	inline const char *GetFileName() const { return _fileName.c_str(); }
	inline bool IsEncrypted() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 0)) != 0;
	}
	inline bool IsExistDataDescriptor() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 3)) != 0;
	}
	inline bool IsStrongEncrypted() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 6)) != 0;
	}
	inline bool IsUtf8() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 11)) != 0;
	}
	inline DateTime GetLastModDateTime() const {
		UInt16 dosTime = Gura_UnpackUInt16(_fields.LastModFileTime);
		UInt16 dosDate = Gura_UnpackUInt16(_fields.LastModFileDate);
		return MakeDateTimeFromDos(dosDate, dosTime);
	}
	inline void Print() const {
		::printf("Signature              %08x\n", Gura_UnpackUInt32(_fields.Signature));
		::printf("VersionNeededToExtract %04x\n", Gura_UnpackUInt16(_fields.VersionNeededToExtract));
		::printf("GeneralPurposeBitFlag  %04x\n", Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag));
		::printf("CompressionMethod      %04x\n", Gura_UnpackUInt16(_fields.CompressionMethod));
		::printf("LastModFileTime        %04x\n", Gura_UnpackUInt16(_fields.LastModFileTime));
		::printf("LastModFileDate        %04x\n", Gura_UnpackUInt16(_fields.LastModFileDate));
		::printf("Crc32                  %08x\n", Gura_UnpackUInt32(_fields.Crc32));
		::printf("CompressedSize         %08x\n", Gura_UnpackUInt32(_fields.CompressedSize));
		::printf("UncompressedSize       %08x\n", Gura_UnpackUInt32(_fields.UncompressedSize));
		::printf("FileNameLength         %04x\n", Gura_UnpackUInt16(_fields.FileNameLength));
		::printf("ExtraFieldLength       %04x\n", Gura_UnpackUInt16(_fields.ExtraFieldLength));
	}
};

// B. File data

// C. Data descriptor
class DataDescriptor {
public:
	struct Fields {
		Gura_PackedUInt32_LE(Crc32);
		Gura_PackedUInt32_LE(CompressedSize);
		Gura_PackedUInt32_LE(UncompressedSize);
	};
private:
	Fields _fields;
public:
	inline DataDescriptor() {}
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		return ReadStream(sig, stream, &_fields, 12);
	}
	inline bool Write(Signal &sig, Stream &stream) {
		return WriteStream(sig, stream, &_fields, 12);
	}
};

// D. Archive decryption header

// E. Archive extra data record
class ArchiveExtraDataRecord {
public:
	enum { Signature = 0x08064b50 };
	struct Fields {
		Gura_PackedUInt32_LE(Signature);
		Gura_PackedUInt32_LE(ExtraFieldLength);
		// ExtraField (ExtraFieldLength bytes)
	};
private:
	Fields _fields;
	Binary _extraField;
public:
	inline ArchiveExtraDataRecord() { Gura_PackUInt32(_fields.Signature, Signature); }
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 8 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _extraField,
						Gura_UnpackUInt32(_fields.ExtraFieldLength))) return false;
		return true;
	}
	inline bool Write(Signal &sig, Stream &stream) {
		Gura_PackUInt32(_fields.ExtraFieldLength, _extraField.size());
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
		Gura_PackedUInt32_LE(Signature);
		Gura_PackedUInt16_LE(VersionMadeBy);				// only in CentralFileHeader
		Gura_PackedUInt16_LE(VersionNeededToExtract);
		Gura_PackedUInt16_LE(GeneralPurposeBitFlag);
		Gura_PackedUInt16_LE(CompressionMethod);
		Gura_PackedUInt16_LE(LastModFileTime);
		Gura_PackedUInt16_LE(LastModFileDate);
		Gura_PackedUInt32_LE(Crc32);
		Gura_PackedUInt32_LE(CompressedSize);
		Gura_PackedUInt32_LE(UncompressedSize);
		Gura_PackedUInt16_LE(FileNameLength);
		Gura_PackedUInt16_LE(ExtraFieldLength);
		Gura_PackedUInt16_LE(FileCommentLength);			// only in CentralFileHeader
		Gura_PackedUInt16_LE(DiskNumberStart);				// only in CentralFileHeader
		Gura_PackedUInt16_LE(InternalFileAttributes);		// only in CentralFileHeader
		Gura_PackedUInt32_LE(ExternalFileAttributes);		// only in CentralFileHeader
		Gura_PackedUInt32_LE(RelativeOffsetOfLocalHeader);	// only in CentralFileHeader
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
	inline CentralFileHeader() { Gura_PackUInt32(_fields.Signature, Signature); }
	inline CentralFileHeader(const CentralFileHeader &hdr) :
		_fields(hdr._fields), _fileName(hdr._fileName),
		_extraField(hdr._extraField), _fileComment(hdr._fileComment) {}
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 46 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _fileName,
						Gura_UnpackUInt16(_fields.FileNameLength))) return false;
		if (!ReadStream(sig, stream, _extraField,
						Gura_UnpackUInt16(_fields.ExtraFieldLength))) return false;
		if (!ReadStream(sig, stream, _fileComment,
						Gura_UnpackUInt16(_fields.FileCommentLength))) return false;
		return true;
	}
	inline bool Write(Signal &sig, Stream &stream) {
		Gura_PackUInt16(_fields.FileNameLength, _fileName.size());
		Gura_PackUInt16(_fields.ExtraFieldLength, _extraField.size());
		Gura_PackUInt16(_fields.FileCommentLength, _fileComment.size());
		if (!WriteStream(sig, stream, &_fields, 46)) return false;
		if (!WriteStream(sig, stream, _fileName)) return false;
		if (!WriteStream(sig, stream, _extraField)) return false;
		if (!WriteStream(sig, stream, _fileComment)) return false;
		return true;
	}
	inline bool WriteAsLocalFileHeader(Signal &sig, Stream &stream) {
		LocalFileHeader hdr;
		LocalFileHeader::Fields &fields = hdr.GetFields();
		Gura_PackUInt16(fields.VersionNeededToExtract,
						Gura_UnpackUInt16(_fields.VersionNeededToExtract));
		Gura_PackUInt16(fields.GeneralPurposeBitFlag,
						Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag));
		Gura_PackUInt16(fields.CompressionMethod,
						Gura_UnpackUInt16(_fields.CompressionMethod));
		Gura_PackUInt16(fields.LastModFileTime,
						Gura_UnpackUInt16(_fields.LastModFileTime));
		Gura_PackUInt16(fields.LastModFileDate,
						Gura_UnpackUInt16(_fields.LastModFileDate));
		Gura_PackUInt32(fields.Crc32,
						Gura_UnpackUInt32(_fields.Crc32));
		Gura_PackUInt32(fields.CompressedSize,
						Gura_UnpackUInt32(_fields.CompressedSize));
		Gura_PackUInt32(fields.UncompressedSize,
						Gura_UnpackUInt32(_fields.UncompressedSize));
		UInt16 fileNameLength = static_cast<UInt16>(_fileName.size());
		Gura_PackUInt16(fields.FileNameLength, fileNameLength);
		UInt16 extraFieldLength = static_cast<UInt16>(_extraField.size());
		Gura_PackUInt16(fields.ExtraFieldLength, extraFieldLength);
		if (!WriteStream(sig, stream, &fields, 30)) return false;
		if (!WriteStream(sig, stream, _fileName)) return false;
		if (!WriteStream(sig, stream, _extraField)) return false;
		return true;
	}
	inline void SetFileName(const char *fileName) { _fileName = fileName; }
	inline const char *GetFileName() const { return _fileName.c_str(); }
	inline const char *GetFileComment() const { return _fileComment.c_str(); }
	inline bool IsEncrypted() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 0)) != 0;
	}
	inline bool IsExistDataDescriptor() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 3)) != 0;
	}
	inline bool IsStrongEncrypted() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 6)) != 0;
	}
	inline bool IsUtf8() const {
		return (Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag) & (1 << 11)) != 0;
	}
	inline UInt32 GetRelativeOffsetOfLocalHeader() const {
		return Gura_UnpackUInt32(_fields.RelativeOffsetOfLocalHeader);
	}
	inline UInt16 GetCompressionMethod() const {
		return Gura_UnpackUInt16(_fields.CompressionMethod);
	}
	inline DateTime GetLastModDateTime() const {
		UInt16 dosTime = Gura_UnpackUInt16(_fields.LastModFileTime);
		UInt16 dosDate = Gura_UnpackUInt16(_fields.LastModFileDate);
		return MakeDateTimeFromDos(dosDate, dosTime);
	}
	inline UInt32 GetCrc32() const {
		return Gura_UnpackUInt32(_fields.Crc32);
	}
	inline UInt32 GetCompressedSize() const {
		return Gura_UnpackUInt32(_fields.CompressedSize);
	}
	inline UInt32 GetUncompressedSize() const {
		return Gura_UnpackUInt32(_fields.UncompressedSize);
	}
	inline UInt32 GetExternalFileAttributes() const {
		return Gura_UnpackUInt32(_fields.ExternalFileAttributes);
	}
	inline void Print() const {
		::printf("Signature              %08x\n", Gura_UnpackUInt32(_fields.Signature));
		::printf("VersionMadeBy          %04x\n", Gura_UnpackUInt16(_fields.VersionMadeBy));
		::printf("VersionNeededToExtract %04x\n", Gura_UnpackUInt16(_fields.VersionNeededToExtract));
		::printf("GeneralPurposeBitFlag  %04x\n", Gura_UnpackUInt16(_fields.GeneralPurposeBitFlag));
		::printf("CompressionMethod      %04x\n", Gura_UnpackUInt16(_fields.CompressionMethod));
		::printf("LastModFileTime        %04x\n", Gura_UnpackUInt16(_fields.LastModFileTime));
		::printf("LastModFileDate        %04x\n", Gura_UnpackUInt16(_fields.LastModFileDate));
		::printf("Crc32                  %08x\n", Gura_UnpackUInt32(_fields.Crc32));
		::printf("CompressedSize         %08x\n", Gura_UnpackUInt32(_fields.CompressedSize));
		::printf("UncompressedSize       %08x\n", Gura_UnpackUInt32(_fields.UncompressedSize));
		::printf("FileNameLength         %04x\n", Gura_UnpackUInt16(_fields.FileNameLength));
		::printf("ExtraFieldLength       %04x\n", Gura_UnpackUInt16(_fields.ExtraFieldLength));
		::printf("FileCommentLength      %04x\n", Gura_UnpackUInt16(_fields.FileCommentLength));
		::printf("DiskNumberStart        %04x\n", Gura_UnpackUInt16(_fields.DiskNumberStart));
		::printf("InternalFileAttributes %04x\n", Gura_UnpackUInt16(_fields.InternalFileAttributes));
		::printf("ExternalFileAttributes %08x\n", Gura_UnpackUInt32(_fields.ExternalFileAttributes));
		::printf("RelativeOffsetOfLocalHeader %08x\n", Gura_UnpackUInt32(_fields.RelativeOffsetOfLocalHeader));
	}
};

class DigitalSignature {
public:
	enum { Signature = 0x05054b50 };
	struct Fields {
		Gura_PackedUInt32_LE(Signature);
		Gura_PackedUInt16_LE(SizeOfData);
		// Data (SizeOfData bytes)
	};
private:
	Fields _fields;
	Binary _data;
public:
	inline DigitalSignature() { Gura_PackUInt32(_fields.Signature, Signature); }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 8 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _data,
						Gura_UnpackUInt16(_fields.SizeOfData))) return false;
		return true;
	}
	inline bool Write(Signal &sig, Stream &stream) {
		Gura_PackUInt16(_fields.SizeOfData, _data.size());
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
		Gura_PackedUInt32_LE(Signature);
		Gura_PackedUInt64_LE(SizeOfZip64EndOfCentralDirectoryRecord);
		Gura_PackedUInt16_LE(VersionMadeBy);
		Gura_PackedUInt16_LE(VersionNeededToExtract);
		Gura_PackedUInt32_LE(NumberOfThisDisk);
		Gura_PackedUInt32_LE(NumberOfTheDiskWithTheStartOfTheCentralDirectory);
		Gura_PackedUInt64_LE(TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk);
		Gura_PackedUInt64_LE(TotalNumberOfEntriesInTheCentralDirectory);
		Gura_PackedUInt64_LE(SizeOfTheCentralDirectory);
		Gura_PackedUInt64_LE(OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber);
		// Zip64ExtensibleDataSector (... bytes)
	};
private:
	Fields _fields;
public:
	inline Zip64EndOfCentralDirectory() { Gura_PackUInt32(_fields.Signature, Signature); }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 56 - 4, 4)) return false;
		return true;
	}
	inline bool Write(Signal &sig, Stream &stream) {
		if (!WriteStream(sig, stream, &_fields, 56)) return false;
		return true;
	}
};

// H. Zip64 end of central directory locator
class Zip64EndOfCentralDirectoryLocator {
public:
	enum { Signature = 0x07064b50 };
	struct Fields {
		Gura_PackedUInt32_LE(Signature);
		Gura_PackedUInt32_LE(NumberOfTheDiskWithTheStartOfTheZip64EndOfCentralDirectory);
		Gura_PackedUInt64_LE(RelativeOffsetOfTheZip64EndOfCentralDirectoryRecord);
		Gura_PackedUInt32_LE(TotalNumberOfDisks);
	};
private:
	Fields _fields;
public:
	inline Zip64EndOfCentralDirectoryLocator() { Gura_PackUInt32(_fields.Signature, Signature); }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		return ReadStream(sig, stream, &_fields, 20 - 4, 4);
	}
	inline bool Write(Signal &sig, Stream &stream) {
		return WriteStream(sig, stream, &_fields, 20);
	}
};

// I. End of central directory record
class EndOfCentralDirectoryRecord {
public:
	enum { Signature = 0x06054b50 };
	enum { MinSize = 22, MaxSize = 22 + 65536 };
	struct Fields {
		Gura_PackedUInt32_LE(Signature);
		Gura_PackedUInt16_LE(NumberOfThisDisk);
		Gura_PackedUInt16_LE(NumberOfTheDiskWithTheStartOfTheCentralDirectory);
		Gura_PackedUInt16_LE(TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk);
		Gura_PackedUInt16_LE(TotalNumberOfEntriesInTheCentralDirectory);
		Gura_PackedUInt32_LE(SizeOfTheCentralDirectory);
		Gura_PackedUInt32_LE(OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber);
		Gura_PackedUInt16_LE(ZIPFileCommentLength);
		// ZIPFileComment (ZIPFileCommentLength bytes)
	};
private:
	Fields _fields;
	Binary _zipFileComment;
public:
	inline EndOfCentralDirectoryRecord() { Gura_PackUInt32(_fields.Signature, Signature); }
	inline Fields &GetFields() { return _fields; }
	inline const Fields &GetFields() const { return _fields; }
	inline bool Read(Signal &sig, Stream &stream) {
		if (!ReadStream(sig, stream, &_fields, 22 - 4, 4)) return false;
		if (!ReadStream(sig, stream, _zipFileComment,
						Gura_UnpackUInt16(_fields.ZIPFileCommentLength))) return false;
		return true;
	}
	inline bool Write(Signal &sig, Stream &stream) {
		Gura_PackUInt16(_fields.ZIPFileCommentLength, _zipFileComment.size());
		if (!WriteStream(sig, stream, &_fields, 22)) return false;
		if (!WriteStream(sig, stream, _zipFileComment)) return false;
		return true;
	}
	void Print() const {
		::printf("Signature                                                         %08x\n", Gura_UnpackUInt32(_fields.Signature));
		::printf("NumberOfThisDisk                                                  %04x\n", Gura_UnpackUInt16(_fields.NumberOfThisDisk));
		::printf("NumberOfTheDiskWithTheStartOfTheCentralDirectory                  %04x\n", Gura_UnpackUInt16(_fields.NumberOfTheDiskWithTheStartOfTheCentralDirectory));
		::printf("TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk               %04x\n", Gura_UnpackUInt16(_fields.TotalNumberOfEntriesInTheCentralDirectoryOnThisDisk));
		::printf("TotalNumberOfEntriesInTheCentralDirectory                         %04x\n", Gura_UnpackUInt16(_fields.TotalNumberOfEntriesInTheCentralDirectory));
		::printf("SizeOfTheCentralDirectory                                         %08x\n", Gura_UnpackUInt32(_fields.SizeOfTheCentralDirectory));
		::printf("OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber %08x\n", Gura_UnpackUInt32(_fields.OffsetOfStartOfCentralDirectoryWithRespectToTheStartingDiskNumber));
		::printf("ZIPFileCommentLength                                              %04x\n", Gura_UnpackUInt16(_fields.ZIPFileCommentLength));
	}
};

// Zip64 Extended Information Extra Field (0x0001)
class Extra_ZIP64 {
public:
	enum { Tag = 0x0001 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(Size);
		Gura_PackedUInt64_LE(OriginalSize);
		Gura_PackedUInt64_LE(CompressedSize);
		Gura_PackedUInt64_LE(RelativeHeaderOffset);
		Gura_PackedUInt32_LE(DiskStartNumber);
	};
};

// OS/2 Extra Field (0x0009)
class Extra_OS2 {
public:
	enum { Tag = 0x0009 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt32_LE(BSize);
		Gura_PackedUInt16_LE(CType);
		Gura_PackedUInt32_LE(EACRC);
		// CompressedBlock
	};
};

// NTFS Extra Field (0x000a)
class Extra_NTFS {
public:
	enum { Tag = 0x000a };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		// Tag1, Size1, ...
	};
};

// OpenVMS Extra Field (0x000c)
class Extra_VMS {
public:
	enum { Tag = 0x000c };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt32_LE(CRC);
		// Tag1, Size1, ...
	};
};

// UNIX Extra Field (0x000d)
class Extra_UNIX {
public:
	enum { Tag = 0x000d };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt32_LE(Atime);
		Gura_PackedUInt32_LE(Mtime);
		Gura_PackedUInt16_LE(Uid);
		Gura_PackedUInt16_LE(Gid);
		// VariableLengthDataField
	};
};

// PATCH Descriptor Extra Field (0x000f)
class Extra_Patch {
public:
	enum { Tag = 0x000f };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt16_LE(Version);
		Gura_PackedUInt32_LE(Flags);
		Gura_PackedUInt32_LE(OldSize);
		Gura_PackedUInt32_LE(OldCRC);
		Gura_PackedUInt32_LE(NewSize);
		Gura_PackedUInt32_LE(NewCRC);
	};
};

// PKCS#7 Store for X.509 Certificates (0x0014)
class Extra_Store {
public:
	enum { Tag = 0x0014 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		// TData (TSize bytes)
	};
};

// X.509 Certificate ID and Signature for individual file (0x0015)
class Extra_CID {
public:
	enum { Tag = 0x0015 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		// TData (TSize bytes)
	};
};

// X.509 Certificate ID and Signature for central directory (0x0016)
class Extra_CDID {
public:
	enum { Tag = 0x0016 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		// TData (TSize bytes)
	};
};

// Record Management Controls (0x0018)
class Extra_RecCTL {
public:
	enum { Tag = 0x0018 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(CSize);
		// Tag1, Size1, Data1, ..
	};
};

// PKCS#7 Encryption Recipient Certificate List (0x0019)
class Extra_CStore {
public:
	enum { Tag = 0x0019 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		// TData (TSize bytes)
	};
};

// MVS Extra Field (0x0065)
class Extra_MVS {
public:
	enum { Tag = 0x0065 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt64_LE(ID);
		// AttributeData ((TSize - 4) bytes)
	};
};

// OS/400 Extra Field (0x0065)
class Extra_OS400 {
public:
	enum { Tag = 0x0065 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(Size);
		Gura_PackedUInt64_LE(ID);
		// AttributeData ((TSize - 4) bytes)
	};
};

// ZipIt Macintosh Extra Field (long) (0x2605)
class Extra_Mac2 {
public:
	enum { Tag = 0x2605 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt32_BE(Signature);	// "ZPIT"
		UChar FnLen;
		// FileName, FileType, Creator
	};
};

// ZipIt Macintosh Extra Field (short, for files) (0x2705)
class Extra_Mac2b {
public:
	enum { Tag = 0x2705 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt32_BE(Signature);	// "ZPIT"
		// FileType, Creator, fdFlags, reserved
	};
};

// ZipIt Macintosh Extra Field (short, for directories) (0x2805)
class Extra_Mac2c {
public:
	enum { Tag = 0x2805 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt32_BE(Signature);	// "ZPIT"
		// frFlags, View
	};
};

// Info-ZIP Unicode Comment Extra Field (0x6375)
class Extra_UCom {
public:
	enum { Tag = 0x6375 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		UChar Version;
		Gura_PackedUInt32_LE(ComCRC32);
		// UnicodeCom
	};
};

// Info-ZIP Unicode Path Extra Field (0x7075)
class Extra_UPath {
public:
	enum { Tag = 0x7075 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		UChar Version;
		Gura_PackedUInt32_LE(NameCRC32);
		// UnicodeName
	};
};

// Microsoft Open Packaging Growth Hint (0xa220)
class Extra_MSOpen {
public:
	enum { Tag = 0xa220 };
	struct Fields {
		Gura_PackedUInt16_LE(Tag);
		Gura_PackedUInt16_LE(TSize);
		Gura_PackedUInt16_LE(Signature);
		Gura_PackedUInt16_LE(PadVal);
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
	virtual String ToString(bool exprFlag);
	const inline CentralFileHeader &GetCentralFileHeader() const { return _hdr; }
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
	Object_reader(Signal &sig, Stream *pStreamSrc);
	inline CentralFileHeaderList &GetHeaderList() { return _hdrList; }
	virtual ~Object_reader();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Stream *GetStreamSrc() { return _pStreamSrc.get(); }
	bool ReadDirectory(Environment &env);
};

//-----------------------------------------------------------------------------
// Object_writer declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(writer);

class Object_writer : public Object {
private:
	Signal &_sig;
	AutoPtr<Stream> _pStreamDst;
	UInt16 _compressionMethod;
	CentralFileHeaderList _hdrList;
public:
	Gura_DeclareObjectAccessor(writer)
public:
	Object_writer(Signal &sig, Stream *pStreamDst, UInt16 compressionMethod);
	inline CentralFileHeaderList &GetHeaderList() { return _hdrList; }
	virtual ~Object_writer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Stream *GetStreamDst() { return _pStreamDst.get(); }
	bool Add(Environment &env, Stream &streamSrc,
					const char *fileName, UInt16 compressionMethod);
	bool Finish();
	inline UInt16 GetCompressionMethod() const { return _compressionMethod; }
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
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
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
	virtual Directory *DoNext(Environment &env);
	virtual Stream *DoOpenStream(Environment &env, UInt32 attr);
	virtual Object *DoGetStatObj(Signal &sig);
	inline Record_ZIP &GetRecord() { return *_pRecord; }
};

//-----------------------------------------------------------------------------
// PathMgr_ZIP declaration
//-----------------------------------------------------------------------------
class PathMgr_ZIP : public PathMgr {
public:
	virtual bool IsResponsible(Environment &env,
					const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode);
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
	UInt32 _crc32Expected;
	bool _seekedFlag;
	CRC32 _crc32;
public:
	Stream_reader(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader();
	virtual bool Initialize(Environment &env) = 0;
	virtual const char *GetName() const;
	virtual const char *GetIdentifier() const;
	virtual bool GetAttribute(Attribute &attr);
	virtual bool SetAttribute(const Attribute &attr);
	virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
	virtual bool DoFlush(Signal &sig);
	virtual bool DoClose(Signal &sig);
	virtual size_t DoGetSize();
	virtual Object *DoGetStatObj(Signal &sig);
	size_t CheckCRC32(Signal &sig, const void *buff, size_t bytesRead);
};

//-----------------------------------------------------------------------------
// Stream_reader_Store declaration
// Compression method #0: stored (no compression)
//-----------------------------------------------------------------------------
class Stream_reader_Store : public Stream_reader {
private:
	size_t _offsetTop;
public:
	Stream_reader_Store(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_Store();
	virtual bool Initialize(Environment &env);
	virtual size_t DoRead(Signal &sig, void *buff, size_t bytes);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

//-----------------------------------------------------------------------------
// Stream_reader_Deflate declaration
// Compression method #8: Deflated
//-----------------------------------------------------------------------------
class Stream_reader_Deflate : public Stream_reader {
private:
	AutoPtr<ZLib::Stream_Inflater> _pStreamInflater;
public:
	Stream_reader_Deflate(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_Deflate();
	virtual bool Initialize(Environment &env);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

//-----------------------------------------------------------------------------
// Stream_reader_BZIP2 declaration
// Compression method #12: BZIP2
//-----------------------------------------------------------------------------
class Stream_reader_BZIP2 : public Stream_reader {
private:
	AutoPtr<BZLib::Stream_Decompressor> _pStreamDecompressor;
public:
	Stream_reader_BZIP2(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_BZIP2();
	virtual bool Initialize(Environment &env);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

//-----------------------------------------------------------------------------
// Stream_reader_Deflate64 declaration
// Compression method #9: Enhanced Deflating using Deflate64(tm)
//-----------------------------------------------------------------------------
class Stream_reader_Deflate64 : public Stream_reader {
public:
	Stream_reader_Deflate64(Environment &env, Stream *pStreamSrc, const CentralFileHeader &hdr);
	virtual ~Stream_reader_Deflate64();
	virtual bool Initialize(Environment &env);
	virtual size_t DoRead(Signal &sig, void *buff, size_t len);
	virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
};

Gura_EndModuleHeader(zip)

#endif
