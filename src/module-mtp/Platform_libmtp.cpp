//=============================================================================
// PLATFORM_libmtp.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// InitPlatform
//-----------------------------------------------------------------------------
bool InitPlatform()
{
	::LIBMTP_Init();
	return true;
}

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
Device::Device(LIBMTP_mtpdevice_t *mtpDevice) : _cntRef(1), _mtpDevice(mtpDevice)
{
}

Device::~Device()
{
	::LIBMTP_Release_Device(_mtpDevice);
}

Directory_MTP *Device::GeneratePartialDirectory(
	Signal &sig, uint32_t storageId, const char *pathName, const char **pPathNamePartial) const
{
	const char *p = pathName;
	if (IsFileSeparator(*p)) p++;
	*pPathNamePartial = p;
	Directory_MTP *pDirectory = new Directory_MTP(
		nullptr, "/", Directory::TYPE_Container, Reference(), storageId, LIBMTP_FILES_AND_FOLDERS_ROOT,
		new Stat("", "/", 0, DateTime(), LIBMTP_FILETYPE_FOLDER));
	while (*p != '\0') {
		if (!pDirectory->IsContainer()) {
			sig.SetError(ERR_FileError, "can't browse inside an item");
			return nullptr;
		}
		String field;
		for ( ; ; p++) {
			if (*p == '\0') {
				break;
			} else if (IsFileSeparator(*p)) {
				p++;
				break;
			}
			field += *p;
		}
		if (field.empty()) {
			sig.SetError(ERR_FormatError, "wrong format of path name");
			return nullptr;
		}
		//::printf("[%s]\n", field.c_str());
		LIBMTP_file_t *mtpfileHead = ::LIBMTP_Get_Files_And_Folders(_mtpDevice, storageId, pDirectory->GetItemId());
		if (mtpfileHead == nullptr) {
			::LIBMTP_Dump_Errorstack(_mtpDevice);
			::LIBMTP_Clear_Errorstack(_mtpDevice);
			sig.SetError(ERR_LibraryError, "failed to get file information from MTP");
			return nullptr;
		}
		LIBMTP_file_t *mtpfileFound = nullptr;
		for (LIBMTP_file_t *mtpfile = mtpfileHead; mtpfile != nullptr; mtpfile = mtpfile->next) {
			if (field == mtpfile->filename) {
				mtpfileFound = mtpfile;
				break;
			}
		}
		if (mtpfileFound == nullptr) {
			DestroyMtpfileList(mtpfileHead);
			break;
		}
		*pPathNamePartial = p;
		pDirectory = new Directory_MTP(
			pDirectory, mtpfileFound->filename,
			(mtpfileFound->filetype == LIBMTP_FILETYPE_FOLDER)?
								Directory::TYPE_Container : Directory::TYPE_Item,
			Reference(), storageId, mtpfileFound->item_id,
			new Stat(pDirectory->MakePathName(false).c_str(), mtpfileFound));
		DestroyMtpfileList(mtpfileHead);
	}
	return pDirectory;
}

Directory_MTP *Device::GenerateDirectory(Signal &sig, uint32_t storageId, const char *pathName) const
{
	const char *pathNamePartial = nullptr;
	AutoPtr<Directory_MTP> pDirectory(GeneratePartialDirectory(sig, storageId, pathName, &pathNamePartial));
	if (*pathNamePartial != '\0') {
		sig.SetError(ERR_FileError, "specified path doesn't exist");
		return nullptr;
	}
	return pDirectory.release();
}

//-----------------------------------------------------------------------------
// Device::Reader
//-----------------------------------------------------------------------------
Device::Reader::Reader(Signal &sig, Device *pDevice, uint32_t itemId, Stream *pStream) :
	_sig(sig), _pDevice(pDevice), _itemId(itemId), _pStream(pStream)
{
}

uint16_t Device::Reader::OnDataPut(void *params, uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	//::printf("OnWrite()\n");
	*putlen = static_cast<uint32_t>(_pStream->Write(_sig, data, sendlen));
	return _sig.IsSignalled()? LIBMTP_HANDLER_RETURN_ERROR : LIBMTP_HANDLER_RETURN_OK;
}

uint16_t Device::Reader::OnDataPutStub(void *params, void *priv,
								 uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	Reader *pReader = reinterpret_cast<Reader *>(priv);
	return pReader->OnDataPut(params, sendlen, data, putlen);
}

void Device::Reader::Run()
{
	if (::LIBMTP_Get_File_To_Handler(
			_pDevice->GetMtpDevice(), _itemId, OnDataPutStub, this, nullptr, nullptr) != 0) {
		_sig.SetError(ERR_LibraryError, "error while communicating in MTP protocol");
	}
}

//-----------------------------------------------------------------------------
// DeviceOwner
//-----------------------------------------------------------------------------
DeviceOwner::~DeviceOwner()
{
	Clear();
}

void DeviceOwner::Clear()
{
	foreach (DeviceOwner, ppDevice, *this) {
		Device *pDevice = *ppDevice;
		Device::Delete(pDevice);
	}
	clear();
}

bool DeviceOwner::EnumerateDevices(Signal &sig)
{
	LIBMTP_raw_device_t *rawDevices = nullptr;
	int nRawDevices = 0;
	LIBMTP_error_number_t err = ::LIBMTP_Detect_Raw_Devices(&rawDevices, &nRawDevices);
	if (err == LIBMTP_ERROR_NONE) {
		// nothing to do
	} else if (err == LIBMTP_ERROR_NO_DEVICE_ATTACHED) {
		// nothing to do
	} else { // LIBMTP_ERROR_CONNECTING, LIBMTP_ERROR_MEMORY_ALLOCATION, LIBMTP_ERROR_GENERAL
		sig.SetError(ERR_LibraryError, "error occured while detecting devices");
		return false;
	}
	for (int i = 0; i < nRawDevices; i++) {
		LIBMTP_mtpdevice_t *mtpDevice = ::LIBMTP_Open_Raw_Device_Uncached(&rawDevices[i]);
		if (mtpDevice == nullptr) {
			sig.SetError(ERR_IOError, "failed to detect MTP devices");
			return false;
		}
		push_back(new Device(mtpDevice));
	}	
	::free(rawDevices);
	return true;
}

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
Storage::Storage(Device *pDevice, LIBMTP_devicestorage_t *deviceStorage) : _cntRef(1),
	_pDevice(pDevice),
	_id(deviceStorage->id),
	_maxCapacity(deviceStorage->MaxCapacity),
	_freeSpaceInBytes(deviceStorage->FreeSpaceInBytes),
	_freeSpaceInObjects(deviceStorage->FreeSpaceInObjects)
{
	_pStorageType =
		(deviceStorage->StorageType == PTP_ST_Undefined)? Gura_UserSymbol(Undefined) :
		(deviceStorage->StorageType == PTP_ST_FixedROM)? Gura_UserSymbol(FixedROM) :
		(deviceStorage->StorageType == PTP_ST_RemovableROM)? Gura_UserSymbol(RemovableROM) :
		(deviceStorage->StorageType == PTP_ST_FixedRAM)? Gura_UserSymbol(FixedRAM) :
		(deviceStorage->StorageType == PTP_ST_RemovableRAM)? Gura_UserSymbol(RemovableRAM) :
		Gura_UserSymbol(Undefined);
	_pFilesystemType =
		(deviceStorage->FilesystemType == PTP_FST_Undefined)? Gura_UserSymbol(Undefined) :
		(deviceStorage->FilesystemType == PTP_FST_GenericFlat)? Gura_UserSymbol(GenericFlat) :
		(deviceStorage->FilesystemType == PTP_FST_GenericHierarchical)? Gura_UserSymbol(GenericHierarchical) :
		(deviceStorage->FilesystemType == PTP_FST_DCF)? Gura_UserSymbol(DCF) :
		Gura_UserSymbol(Undefined);
	_pAccessCapability =
		(deviceStorage->AccessCapability == PTP_AC_ReadWrite)? Gura_UserSymbol(ReadWrite) :
		(deviceStorage->AccessCapability == PTP_AC_ReadOnly)? Gura_UserSymbol(ReadOnly) :
		(deviceStorage->AccessCapability == PTP_AC_ReadOnly_with_Object_Deletion)?
													Gura_UserSymbol(ReadOnlyWithObjectDeletion) :
		Gura_UserSymbol(Undefined);
	if (deviceStorage->StorageDescription != nullptr) {
		_storageDescription = deviceStorage->StorageDescription;
	}
	if (deviceStorage->VolumeIdentifier != nullptr) {
		_volumeIdentifier = deviceStorage->VolumeIdentifier;
	}
}

Stream *Storage::GenerateReaderStream(Environment &env, const char *pathName) const
{
	AutoPtr<Directory_MTP> pDirectory(GenerateDirectory(env, pathName));
	if (pDirectory.IsNull()) return nullptr;
	AutoPtr<StreamFIFO> pStreamFIFO(new StreamFIFO(env, 65536));
	AutoPtr<StreamFIFO> pStreamFIFORtn(new StreamFIFO(env, pStreamFIFO->GetEntity()->Reference()));
	OAL::Thread *pThread = new Device::Reader(
		env, _pDevice->Reference(), pDirectory->GetItemId(), pStreamFIFO.release());
	pThread->Start();
	return pStreamFIFORtn.release();
}

bool Storage::RecvFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const
{
	bool rtn = true;
	AutoPtr<Directory_MTP> pDirectory(GenerateDirectory(sig, pathName));
	if (pDirectory.IsNull()) return false;
	if (::LIBMTP_Get_File_To_Handler(
			_pDevice->GetMtpDevice(), pDirectory->GetItemId(),
			Callback_RecvFile, pStream, Callback_Progress, pFuncBlock) != 0) {
		sig.SetError(ERR_LibraryError, "error while communicating in MTP protocol");
		rtn = false;
	}
	return rtn;
}

bool Storage::SendFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const
{
	if (pStream->IsInfinite()) {
		sig.SetError(ERR_ValueError, "infinite stream can not be specified");
		return false;
	}
	String dirName, fileName;
	PathMgr::SplitFileName(pathName, &dirName, &fileName);
	AutoPtr<Directory_MTP> pDirectoryParent(GenerateDirectory(sig, dirName.c_str()));
	if (pDirectoryParent.IsNull()) return false;
	LIBMTP_file_t *mtpfile = ::LIBMTP_new_file_t();
	mtpfile->filesize = static_cast<uint32_t>(pStream->GetSize());
	mtpfile->filename = ::strdup(fileName.c_str());
	mtpfile->filetype = GetMtpfiletype(fileName.c_str());
	mtpfile->parent_id = pDirectoryParent->GetItemId();
	mtpfile->storage_id = 0;
	bool rtn = true;
	if (::LIBMTP_Send_File_From_Handler(
			_pDevice->GetMtpDevice(), Callback_SendFile, pStream, mtpfile, Callback_Progress, pFuncBlock) != 0) {
		sig.SetError(ERR_LibraryError, "error while communicating in MTP protocol");
		rtn = false;
	}
	::LIBMTP_destroy_file_t(mtpfile);
	return rtn;
}

bool Storage::DeleteFile(Signal &sig, const char *pathName) const
{
	bool rtn = true;
	AutoPtr<Directory_MTP> pDirectory(GenerateDirectory(sig, pathName));
	if (pDirectory.IsNull()) return false;
	if (::LIBMTP_Delete_Object(
			_pDevice->GetMtpDevice(), pDirectory->GetItemId()) != 0) {
		sig.SetError(ERR_LibraryError, "error while communicating in MTP protocol");
		rtn = false;
	}
	return rtn;
}

bool Storage::MoveFile(Signal &sig, const char *pathNameOld, const char *pathNameNew, bool overwriteFlag) const
{
	const char *pathNamePartialNew;
	AutoPtr<Directory_MTP> pDirectoryOld(GenerateDirectory(sig, pathNameOld));
	if (pDirectoryOld.IsNull()) return false;
	AutoPtr<Directory_MTP> pDirectoryNew(GeneratePartialDirectory(sig, pathNameNew, &pathNamePartialNew));
	if (pDirectoryNew.IsNull()) return false;
	if (PathMgr::HasFileSeparator(pathNamePartialNew)) {
		goto error_done;
	}
	if (*pathNamePartialNew == '\0') {
		if (pDirectoryNew->IsContainer()) {
			//int ::LIBMTP_Move_Object(LIBMTP_mtpdevice_t *, uint32_t, uint32_t, uint32_t);
		} else if (overwriteFlag) {
			
		} else {
			goto error_done;
		}
	} else {
		if (pDirectoryNew->IsContainer()) {
			
		} else {
			goto error_done;
		}
	}
	return true;
error_done:
	sig.SetError(ERR_FileError, "failed to move the %s", pDirectoryOld->IsContainer()? "folder" : "file");
	return false;
}

bool Storage::CopyFile(Signal &sig, const char *pathNameSrc, const char *pathNameDst, bool overwriteFlag) const
{
	return false;
}

uint16_t Storage::Callback_RecvFile(
	void *params, void *priv, uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	Stream *pStream = reinterpret_cast<Stream *>(priv);
	Signal &sig = pStream->GetSignal();
	*putlen = static_cast<uint32_t>(pStream->Write(sig, data, sendlen));
	return sig.IsSignalled()? LIBMTP_HANDLER_RETURN_ERROR : LIBMTP_HANDLER_RETURN_OK;
}

uint16_t Storage::Callback_SendFile(
	void *params, void *priv, uint32_t wantlen, unsigned char *data, uint32_t *gotlen)
{
	Stream *pStream = reinterpret_cast<Stream *>(priv);
	Signal &sig = pStream->GetSignal();
	*gotlen = static_cast<uint32_t>(pStream->Read(sig, data, wantlen));
	return sig.IsSignalled()? LIBMTP_HANDLER_RETURN_ERROR :
		(*gotlen == 0)? LIBMTP_HANDLER_RETURN_CANCEL : LIBMTP_HANDLER_RETURN_OK;
}

int Storage::Callback_Progress(
		uint64_t const sent, uint64_t const total, void const * const data)
{
	const Function *pFuncBlock = reinterpret_cast<const Function *>(data);
	Environment &env = pFuncBlock->GetEnvScope();
	AutoPtr<Argument> pArg(new Argument(pFuncBlock));
	pArg->StoreValue(env, Value(sent), Value(total));
	pFuncBlock->Eval(env, *pArg);
	return env.IsSignalled()? -1 : 0;
}

//-----------------------------------------------------------------------------
// StorageOwner
//-----------------------------------------------------------------------------
StorageOwner::~StorageOwner()
{
	Clear();
}

void StorageOwner::Clear()
{
	foreach (StorageOwner, ppStorage, *this) {
		Storage *pStorage = *ppStorage;
		Storage::Delete(pStorage);
	}
	clear();
}

bool StorageOwner::EnumerateStorages(Signal &sig, Device *pDevice)
{
	LIBMTP_devicestorage_t *deviceStorage = pDevice->GetMtpDevice()->storage;
	for ( ; deviceStorage != nullptr; deviceStorage = deviceStorage->next) {
		push_back(new Storage(pDevice->Reference(), deviceStorage));
	}
	return true;
}

//-----------------------------------------------------------------------------
// Stat
//-----------------------------------------------------------------------------
Stat::Stat(const char *dirName, const LIBMTP_file_t *mtpfile) :
	_cntRef(1), _dirName(dirName), _fileName(mtpfile->filename), _fileSize(mtpfile->filesize),
	_dtModification(OAL::ToDateTime(mtpfile->modificationdate)), _fileType(mtpfile->filetype)
{
}

Stat::Stat(const char *dirName, const char *fileName, size_t fileSize,
		   const DateTime &dtModification, LIBMTP_filetype_t fileType) :
	_cntRef(1), _dirName(dirName), _fileName(fileName), _fileSize(fileSize),
	_dtModification(dtModification), _fileType(fileType)
{
}

String Stat::MakePathName() const
{
	return OAL::JoinPathName(OAL::FileSeparatorUnix, GetDirName(), GetFileName());
}

//-----------------------------------------------------------------------------
// Directory_MTP implementation
//-----------------------------------------------------------------------------
Directory_MTP::Directory_MTP(Directory *pParent, const char *name, Type type,
							 Device *pDevice, uint32_t storageId, uint32_t itemId, Stat *pStat) :
	Directory(pParent, name, type, OAL::FileSeparatorUnix),
	_pDevice(pDevice), _storageId(storageId), _itemId(itemId), _pStat(pStat)
{
	_browsePack.mtpfileHead = nullptr;
	_browsePack.mtpfile = nullptr;
}

Directory_MTP::~Directory_MTP()
{
	DestroyMtpfileList(_browsePack.mtpfileHead);
}

Directory *Directory_MTP::DoNext(Environment &env)
{
	if (_browsePack.mtpfileHead == nullptr) {
		_browsePack.mtpfileHead = ::LIBMTP_Get_Files_And_Folders(_pDevice->GetMtpDevice(), _storageId, _itemId);
		_browsePack.mtpfile = _browsePack.mtpfileHead;
	} else {
		_browsePack.mtpfile = _browsePack.mtpfile->next;
	}
	if (_browsePack.mtpfile == nullptr) return nullptr;
	Type type = (_browsePack.mtpfile->filetype == LIBMTP_FILETYPE_FOLDER)? TYPE_Container : TYPE_Item;
	return new Directory_MTP(
		Reference(), _browsePack.mtpfile->filename, type,
		_pDevice->Reference(), _storageId, _browsePack.mtpfile->item_id,
		new Stat(MakePathName(false).c_str(), _browsePack.mtpfile));
}

Stream *Directory_MTP::DoOpenStream(Environment &env, UInt32 attr)
{
	return nullptr;
}

Object *Directory_MTP::DoGetStatObj(Signal &sig)
{
	return new Object_stat(_pStat->Reference());
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void DestroyMtpfileList(LIBMTP_file_t *mtpfile)
{
	while (mtpfile != nullptr) {
		LIBMTP_file_t *mtpfileNext = mtpfile->next;
		::LIBMTP_destroy_file_t(mtpfile);
		mtpfile = mtpfileNext;
	}
}

LIBMTP_filetype_t GetMtpfiletype(const char *fileName)
{
	struct Table {
		const char *extName;
		LIBMTP_filetype_t mtpfiletype;
	};
	static const Table tbl[] = {
		{ "wav",	LIBMTP_FILETYPE_WAV					},
		{ "mp3",	LIBMTP_FILETYPE_MP3					},
		{ "wma",	LIBMTP_FILETYPE_WMA					},
		{ "ogg",	LIBMTP_FILETYPE_OGG					},
		{ "mp4",	LIBMTP_FILETYPE_MP4					},
		{ "wmv",	LIBMTP_FILETYPE_WMV					},
		{ "avi",	LIBMTP_FILETYPE_AVI					},
		{ "mpeg",	LIBMTP_FILETYPE_MPEG				},
		{ "mpg",	LIBMTP_FILETYPE_MPEG				},
		{ "asf",	LIBMTP_FILETYPE_ASF					},
		{ "qt",		LIBMTP_FILETYPE_QT					},
		{ "mov",	LIBMTP_FILETYPE_QT					},
		{ "wma",	LIBMTP_FILETYPE_WMA					},
		{ "jpg",	LIBMTP_FILETYPE_JPEG				},
		{ "jpeg",	LIBMTP_FILETYPE_JPEG				},
		{ "jfif",	LIBMTP_FILETYPE_JFIF				},
		{ "tif",	LIBMTP_FILETYPE_TIFF				},
		{ "tiff",	LIBMTP_FILETYPE_TIFF				},
		{ "bmp",	LIBMTP_FILETYPE_BMP					},
		{ "gif",	LIBMTP_FILETYPE_GIF					},
		{ "pic",	LIBMTP_FILETYPE_PICT				},
		{ "pict",	LIBMTP_FILETYPE_PICT				},
		{ "png",	LIBMTP_FILETYPE_PNG					},
		{ "wmf",	LIBMTP_FILETYPE_WINDOWSIMAGEFORMAT	},
		{ "ics",	LIBMTP_FILETYPE_VCALENDAR2			},
		{ "exe",	LIBMTP_FILETYPE_WINEXEC				},
		{ "com",	LIBMTP_FILETYPE_WINEXEC				},
		{ "bat",	LIBMTP_FILETYPE_WINEXEC				},
		{ "dll",	LIBMTP_FILETYPE_WINEXEC				},
		{ "sys",	LIBMTP_FILETYPE_WINEXEC				},
		{ "aac",	LIBMTP_FILETYPE_AAC					},
		{ "mp2",	LIBMTP_FILETYPE_MP2					},
		{ "flac",	LIBMTP_FILETYPE_FLAC				},
		{ "m4a",	LIBMTP_FILETYPE_M4A					},
		{ "doc",	LIBMTP_FILETYPE_DOC					},
		{ "xml",	LIBMTP_FILETYPE_XML					},
		{ "xls",	LIBMTP_FILETYPE_XLS					},
		{ "ppt",	LIBMTP_FILETYPE_PPT					},
		{ "mht",	LIBMTP_FILETYPE_MHT					},
		{ "jp2",	LIBMTP_FILETYPE_JP2					},
		{ "jpx",	LIBMTP_FILETYPE_JPX					},
		{ "bin",	LIBMTP_FILETYPE_FIRMWARE			},
		{ "vcf",	LIBMTP_FILETYPE_VCARD3				},
	};
	const char *extName = ::strrchr(fileName, '.');
	if (extName == nullptr) return LIBMTP_FILETYPE_UNKNOWN;
	extName++;
	for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
		if (::strcasecmp(extName, tbl[i].extName) == 0) return tbl[i].mtpfiletype;
	}
	return LIBMTP_FILETYPE_UNKNOWN;
}

Gura_EndModuleScope(mtp)
